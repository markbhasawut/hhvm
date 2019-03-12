<?hh // partial

// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.splfileinfo.php )
 *
 * The SplFileInfo class offers a high-level object oriented interface to
 * information for an individual file.
 *
 */
class SplFileInfo {

  private $fileName;
  private $fileClass = "SplFileObject";
  private $infoClass = "SplFileInfo";

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.construct.php )
   *
   * Creates a new SplFileInfo object for the file_name specified. The file
   * does not need to exist, or be readable.
   *
   * @file_name  mixed   Path to the file.
   */
  public function __construct($file_name) {
    $this->setPathname($file_name);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getpath.php )
   *
   * Returns the path to the file, omitting the filename and any trailing
   * slash.
   *
   * @return     mixed   Returns the path to the file.
   */
  public function getPath() {
    $path = $this->getPathname();
    if ($path === false) {
      return '';
    }
    return dirname($path);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getfilename.php )
   *
   * Gets the filename without any path information.
   *
   * @return     mixed   The filename.
   */
  public function getFilename() {
    return $this->getBasename();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getfileinfo.php )
   *
   * This method gets an SplFileInfo object for the referenced file.
   *
   * @class_name mixed   Name of an SplFileInfo derived class to use.
   *
   * @return     mixed   An SplFileInfo object created for the file.
   */
  public function getFileInfo($class_name = null) {
    if (!$class_name) {
      $class_name = $this->infoClass;
    }
    return new $class_name($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getbasename.php )
   *
   * This method returns the base name of the file, directory, or link
   * without path info.
   *
   * @suffix     mixed   Optional suffix to omit from the base name returned.
   *
   * @return     mixed   Returns the base name without path information.
   */
  public function getBasename($suffix = "") {
    return basename($this->getPathname(), $suffix);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getpathname.php )
   *
   * Returns the path to the file.
   *
   * @return     mixed   The path to the file.
   */
  public function getPathname() {
    return $this->fileName;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getpathinfo.php )
   *
   * Gets an SplFileInfo object for the parent of the current file.
   *
   * @class_name mixed   Name of an SplFileInfo derived class to use.
   *
   * @return     mixed   Returns an SplFileInfo object for the parent path of
   *                     the file.
   */
  public function getPathInfo($class_name = null) {
    if (!$class_name) {
      $class_name = $this->infoClass;
    }
    return new $class_name($this->getPath());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getperms.php )
   *
   * Gets the file permissions for the file.
   *
   * @return     mixed   Returns the file permissions.
   */
  public function getPerms() {
    return fileperms($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getinode.php )
   *
   * Gets the inode number for the filesystem object.
   *
   * @return     mixed   Returns the inode number for the filesystem object.
   */
  public function getInode() {
    return fileinode($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getsize.php )
   *
   * Returns the filesize in bytes for the file referenced.
   *
   * @return     mixed   The filesize in bytes.
   */
  public function getSize() {
    return filesize($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getowner.php )
   *
   * Gets the file owner. The owner ID is returned in numerical format.
   *
   * @return     mixed   The owner id in numerical format.
   */
  public function getOwner() {
    return fileowner($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getgroup.php )
   *
   * Gets the file group. The group ID is returned in numerical format.
   *
   * @return     mixed   The group id in numerical format.
   */
  public function getGroup() {
    return filegroup($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getatime.php )
   *
   * Gets the last access time for the file.
   *
   * @return     mixed   Returns the time the file was last accessed.
   */
  public function getATime() {
    return fileatime($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getmtime.php )
   *
   * Returns the time when the contents of the file were changed. The time
   * returned is a Unix timestamp.
   *
   * @return     mixed   Returns the last modified time for the file, in a
   *                     Unix timestamp.
   */
  public function getMTime() {
    return filemtime($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getctime.php )
   *
   * Returns the inode change time for the file. The time returned is a Unix
   * timestamp.
   *
   * @return     mixed   The last change time, in a Unix timestamp.
   */
  public function getCTime() {
    return filectime($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.gettype.php )
   *
   * Returns the type of the file referenced.
   *
   * @return     mixed   A string representing the type of the entry. May be
   *                     one of file, link, or dir
   */
  public function getType() {
    return filetype($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getextension.php )
   *
   * Retrieves the file extension.
   *
   * @return     mixed   Returns a string containing the file extension, or
   *                     an empty string if the file has no extension.
   */
  public function getExtension() {
    return pathinfo($this->getPathname(), PATHINFO_EXTENSION);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.iswritable.php )
   *
   * Checks if the current entry is writable.
   *
   * @return     mixed   Returns TRUE if writable, FALSE otherwise;
   */
  public function isWritable() {
    return is_writable($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.isreadable.php )
   *
   * Check if the file is readable.
   *
   * @return     mixed   Returns TRUE if readable, FALSE otherwise.
   */
  public function isReadable() {
    return is_readable($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.isexecutable.php )
   *
   * Checks if the file is executable.
   *
   * @return     mixed   Returns TRUE if executable, FALSE otherwise.
   */
  public function isExecutable() {
    return is_executable($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.isfile.php )
   *
   * Checks if the file referenced by this SplFileInfo object exists and is
   * a regular file.
   *
   * @return     mixed   Returns TRUE if the file exists and is a regular
   *                     file (not a link), FALSE otherwise.
   */
  public function isFile() {
    return is_file($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.isdir.php )
   *
   * This method can be used to determine if the file is a directory.
   *
   * @return     mixed   Returns TRUE if a directory, FALSE otherwise.
   */
  public function isDir() {
    return is_dir($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.islink.php )
   *
   * Use this method to check if the file referenced by the SplFileInfo
   * object is a link.
   *
   * @return     mixed   Returns TRUE if the file is a link, FALSE otherwise.
   */
  public function isLink() {
    return is_link($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getlinktarget.php )
   *
   * Gets the target of a filesystem link.
   *
   * The target may not be the real path on the filesystem. Use
   * SplFileInfo::getRealPath() to determine the true path on the filesystem.
   *
   * @return     mixed   Returns the target of the filesystem link.
   */
  public function getLinkTarget() {
    $link = @readlink($this->getPathname());
    if ($link === false) {
      throw new Exception(
        'Unable to read link '.$this->getPathname()
      );
    }
    return $link;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.getrealpath.php )
   *
   * This method expands all symbolic links, resolves relative references
   * and returns the real path to the file.
   *
   * @return     mixed   Returns the path to the file.
   */
  public function getRealPath() {
    return realpath($this->getPathname());
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.tostring.php )
   *
   * This method will return the file name of the referenced file.
   *
   * @return     mixed   Returns the path to the file.
   */
  public function __toString() {
    return $this->getPathname();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.openfile.php )
   *
   * Creates an SplFileObject object of the file. This is useful because
   * SplFileObject contains additional methods for manipulating the file
   * whereas SplFileInfo is only useful for gaining information, like whether
   * the file is writable.
   *
   * @mode       mixed   The mode for opening the file. See the fopen()
   *                     documentation for descriptions of possible modes.
   *                     The default is read only.
   * @use_include_path
   *             mixed   When set to TRUE, the filename is also searched for
   *                     within the include_path
   * @context    mixed   Refer to the context section of the manual for a
   *                     description of contexts.
   *
   * @return     mixed   The opened file as an SplFileObject object.
   */
  public function openFile($mode = 'r', $use_include_path = false,
                           $context = null) {
    $class_name = $this->fileClass;
    return new $class_name(
      $this->getPathname(),
      $mode,
      $use_include_path,
      $context
    );
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.setfileclass.php )
   *
   * Set the class name which SplFileInfo will use to open files with when
   * openFile() is called. The class name passed to this method must be
   * derived from SplFileObject.
   *
   * @class_name mixed   The class name to use when openFile() is called.
   *
   * @return     mixed   No value is returned.
   */
  public function setFileClass($class_name = "SplFileObject") {
    if (!is_a($class_name, "SplFileObject", true)) {
      throw new UnexpectedValueException(
        "SplFileInfo::setFileClass() expects parameter 1 to be a class name ".
        "derived from SplFileObject, '$class_name' given"
      );
    }
    $this->fileClass = $class_name;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/splfileinfo.setinfoclass.php )
   *
   * Use this method to set a custom class which will be used when
   * getFileInfo and getPathInfo are called. The class name passed to this
   * method must be derived from SplFileInfo.
   *
   * @class_name mixed   The class name to use.
   *
   * @return     mixed   No value is returned.
   */
  public function setInfoClass($class_name = "SplFileInfo") {
    if (!is_a($class_name, "SplFileInfo", true)) {
      throw new UnexpectedValueException(
        "SplFileInfo::setInfoClass() expects parameter 1 to be a class name ".
        "derived from SplFileInfo, '$class_name' given"
      );
    }
    $this->infoClass = $class_name;
  }

  protected function setPathname($file_name) {
    if ($file_name !== false) {
      $file_name = rtrim($file_name, '/');
    }
    $this->fileName = $file_name;
  }
}
