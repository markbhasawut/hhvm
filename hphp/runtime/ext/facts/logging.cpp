/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-present Facebook, Inc. (http://www.facebook.com)  |
   +----------------------------------------------------------------------+
   | This source path is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the path LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#include "hphp/runtime/ext/facts/logging.h"

#include <cstdio>
#include <memory>
#include <string>

#include <folly/Conv.h>
#include <folly/Range.h>
#include <folly/SynchronizedPtr.h>
#include <folly/logging/Init.h>
#include <folly/logging/LogConfig.h>
#include <folly/logging/LogFormatter.h>
#include <folly/logging/LogHandlerFactory.h>
#include <folly/logging/LogWriter.h>
#include <folly/logging/Logger.h>
#include <folly/logging/LoggerDB.h>
#include <folly/logging/StandardLogHandler.h>
#include <folly/logging/StandardLogHandlerFactory.h>

#include "hphp/util/cronolog.h"
#include "hphp/util/logger.h"

namespace HPHP {
namespace Facts {

namespace {

folly::SynchronizedPtr<std::unique_ptr<Cronolog>> make_synchronized_crono(
    const std::string& file_template,
    const std::string& link,
    const std::string& owner,
    int period_multiple) {

  if (file_template.empty() || link.empty()) {
    throw std::runtime_error("File template and link are required settings.");
  }

  auto crono = std::make_unique<Cronolog>();
  crono->m_template = file_template;
  crono->m_linkName = link;
  crono->setPeriodicity();
  crono->m_periodMultiple = period_multiple;

#if !defined(SKIP_USER_CHANGE)
  if (!owner.empty()) {
    Cronolog::changeOwner(owner, link);
  }
#endif

  return folly::SynchronizedPtr<std::unique_ptr<Cronolog>>(std::move(crono));
}

/*
 * HHVM has a Cronolog class which creates and maintains a FILE* point to
 * a log file which should be written to based on a template.  This offers
 * conveniences like automatically rolling the log file over on date boundaries.
 * The CronoLogWriter class wraps a Cronolog for writing Facts related log
 * information.
 */
struct CronoLogWriter final : public folly::LogWriter {
public:
  struct Options {
    std::string file_template;
    std::string link;
    std::string owner;
    int period_multiple = 1;
    bool flush_after_write = false;
  };

  explicit CronoLogWriter(const Options& options)
      : m_crono{make_synchronized_crono(
            options.file_template,
            options.link,
            options.owner,
            options.period_multiple)}
      , m_tty{isatty(fileno(m_crono.wlock()->getOutputFile())) == 1}
      , m_flush{options.flush_after_write} {
  }

  void writeMessage(folly::StringPiece buffer, uint32_t flags = 0) override {
    auto crono = m_crono.wlock();
    FILE* output = crono->getOutputFile();
    always_assert(::fwrite(buffer.data(), buffer.size(), 1, output) == 1);
    if (m_flush || (flags & folly::LogWriter::Flags::NEVER_DISCARD)) {
      always_assert(::fflush(output) == 0);
    }
  }

  void writeMessage(std::string&& buffer, uint32_t flags = 0) override {
    writeMessage(folly::StringPiece{buffer}, flags);
  }

  void flush() override {
    always_assert(::fflush(m_crono.wlock()->getOutputFile()) == 0);
  }

  bool ttyOutput() const override {
    return m_tty;
  }

private:
  folly::SynchronizedPtr<std::unique_ptr<Cronolog>> m_crono;
  const bool m_tty;
  const bool m_flush;
};

/*
 * The CronoLogHandlerFactory is a custom log handler for folly logging which
 * selects a destination file to write to using the Cronolog class.
 */
struct CronoLogHandlerFactory final : public folly::LogHandlerFactory {
public:
  explicit CronoLogHandlerFactory(const std::string& owner) : m_owner(owner) {
  }

  folly::StringPiece getType() const override {
    return "crono";
  }

  std::shared_ptr<folly::LogHandler>
  createHandler(const Options& options) override;

private:
  std::string m_owner;
  struct WriterFactory;
};

/*
 * Supported settings:
 *
 * See Cronolog code for further information on the file, link, and period
 * settings.
 *
 * flush_after_write - Perform a flush after each message to be sure the message
 * has been written.  This setting may have performance impacts.
 */
struct CronoLogHandlerFactory::WriterFactory final
    : public folly::StandardLogHandlerFactory::WriterFactory {

public:
  explicit WriterFactory(const std::string& owner) {
    m_options.owner = owner;
  }

  bool
  processOption(folly::StringPiece name, folly::StringPiece value) override {
    try {
      if (name == "file_template") {
        m_options.file_template = value.str();
        return true;
      } else if (name == "link") {
        m_options.link = value.str();
        return true;
      } else if (name == "owner") {
        m_options.owner = value.str();
        return true;
      } else if (name == "flush_after_write") {
        m_options.flush_after_write = folly::to<bool>(value);
        return true;
      } else if (name == "period_multiple") {
        m_options.period_multiple = folly::to<int>(value);
        return true;
      }
    } catch (...) {
      Logger::FError(
          "Caught exception while parsing arguments: {} = {}", name, value);
    }
    return false;
  }

  std::shared_ptr<folly::LogWriter> createWriter() override {
    return std::make_shared<CronoLogWriter>(m_options);
  }

private:
  CronoLogWriter::Options m_options;
};

std::shared_ptr<folly::LogHandler>
CronoLogHandlerFactory::createHandler(const Options& options) {
  WriterFactory writerFactory(m_owner);
  return folly::StandardLogHandlerFactory::createHandler(
      getType(), &writerFactory, options);
}

struct HhvmLogWriter final : public folly::LogWriter {

public:
  void
  writeMessage(folly::StringPiece buffer, uint32_t /* flags */ = 0) override {
    Logger::Error(buffer.str());
  }

  void writeMessage(std::string&& buffer, uint32_t /* flags */ = 0) override {
    Logger::Error(buffer);
  }

  void flush() override {
  }

  bool ttyOutput() const override {
    return false;
  }
};

struct HhvmLogFormatter final : public folly::LogFormatter {

public:
  std::string formatMessage(
      const folly::LogMessage& message,
      const folly::LogCategory* /* handlerCategory */) override {
    auto level = message.getLevel();
    folly::StringPiece level_string;
    if (level >= folly::LogLevel::FATAL) {
      level_string = "<level:fatal>";
    } else if (level >= folly::LogLevel::WARN) {
      level_string = "<level:warning>";
    } else if (level >= folly::LogLevel::INFO) {
      level_string = "<level:info>";
    } else {
      level_string = "<level:none>";
    }

    return folly::sformat(
        "{} {} {}:{} {}",
        level_string,
        message.getThreadID(),
        message.getFileBaseName(),
        message.getLineNumber(),
        message.getMessage());
  }
};

/*
 * The HhvmLogHandlerFactory is a custom log handler for folly logging which
 * writes to a log using the Logger::Error method.
 */
struct HhvmLogHandlerFactory final : public folly::LogHandlerFactory {
public:
  folly::StringPiece getType() const override {
    return "hhvm";
  }

  std::shared_ptr<folly::LogHandler>
  createHandler(const Options& options) override;

private:
  struct WriterFactory;
  struct FormatterFactory;
};

struct HhvmLogHandlerFactory::FormatterFactory final
    : public folly::StandardLogHandlerFactory::FormatterFactory {

  bool processOption(
      folly::StringPiece /* name */, folly::StringPiece /* value */) override {
    return false;
  }

  std::shared_ptr<folly::LogFormatter> createFormatter(
      const std::shared_ptr<folly::LogWriter>& /* logWriter */) override {
    return std::make_shared<HhvmLogFormatter>();
  }
};

struct HhvmLogHandlerFactory::WriterFactory final
    : public folly::StandardLogHandlerFactory::WriterFactory {

public:
  bool processOption(
      folly::StringPiece /* name */, folly::StringPiece /* value */) override {
    return false;
  }

  std::shared_ptr<folly::LogWriter> createWriter() override {
    return std::make_shared<HhvmLogWriter>();
  }
};

std::shared_ptr<folly::LogHandler>
HhvmLogHandlerFactory::createHandler(const Options& options) {
  WriterFactory writerFactory;
  FormatterFactory formatterFactory;
  return folly::StandardLogHandlerFactory::createHandler(
      getType(), &writerFactory, &formatterFactory, options);
}

} // namespace

void enableFactsLogging(const std::string& owner, const std::string& options) {
  folly::LoggerDB::get().registerHandlerFactory(
      std::make_unique<CronoLogHandlerFactory>(owner));

  folly::LoggerDB::get().registerHandlerFactory(
      std::make_unique<HhvmLogHandlerFactory>());

  // It appears that this should be safe to call twice and this will merge
  // in the new options, but it does seem like if elsewhere in HHVM begins
  // to use folly logging and overrides the base logging configuration, we
  // might end up overwriting the overridden settings with the base
  // configuration before applying our own settings.
  folly::initLogging(options);
}

} // namespace Facts
} // namespace HPHP
