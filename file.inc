#if defined _file_included
	#endinput
#endif
#define _file_included

/**
 * <library name="file" summary="File input/output functions.">
 *   <license>
 *     (c) Copyright 2004-2005, ITB CompuPhase
 *     This file is provided as is (no warranties).
 *   </license>
 *   <summary pawndoc="true">
 *     This library uses the enhanced <em>pawndoc.xsl</em> from
 *     <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.
 *     This XSL has features such as library and markdown support, and will not
 *     render this message when used.
 *   </summary>
 * </library>
 */

/// <p/>

#pragma library File

/// <p/>
/**
 * <library>file</library>
 */
enum filemode
{
	io_read,            /* file must exist */
	io_write,           /* creates a new file */
	io_readwrite,       /* opens an existing file, or creates a new file */
	io_append,          /* appends to file (write-only) */
}
static stock filemode:_@filemode() { return filemode; }

/// <p/>
/**
 * <library>file</library>
 */
enum seek_whence
{
	seek_start,
	seek_current,
	seek_end
}
static stock seek_whence:_@seek_whence() { return seek_whence; }

/**
 * <library>file</library>
 */
const EOF = -1;

/**
 * <library>file</library>
 * <summary>Open a file (to read from or write to).</summary>
 * <param name="filename">The path to the file to open (if just a filename is specified, it will open the
 * file with the name specified in the 'scriptfiles' folder)</param>
 * <param name="mode">The mode to open the file with, see below (optional=<b><c>io_readwrite</c></b>)</param>
 * <remarks>This function can't access files outside the 'scriptfiles' folder!</remarks>
 * <remarks>If you use <a href="#io_read">io_read</a> and the file doesn't exist, it will return a <b><c>NULL</c></b>
 * reference.  Using <b>invalid references</b> on file functions will <b>crash</b> your server!</remarks>
 * <remarks>
 *   <b>Modes:</b><p/>
 *   <ul>
 *     <li><b><c>io_read</c></b> - reads from the file.</li>
 *     <li><b><c>io_write</c></b> - write in the file, or create the file if it does not exist.  Erases
 * all existing contents.</li>
 *     <li><b><c>io_readwrite</c></b> - reads the file or creates it if it doesn't already exist.</li>
 *     <li><b><c>io_append</c></b> - appends (adds) to file, write-only.  If the file does not exist,
 * it is created.</li>
 *   </ul>
 * </remarks>
 * <returns>Returns the file handle.  This handle is used for reading and writing. <b><c>0</c></b> if
 * failed to open file.</returns>
 */
native File:fopen(const filename[], filemode:mode = io_readwrite);

/**
 * <library>file</library>
 * <summary>Closes a file.  Files should always be closed when the script no longer needs them (after
 * reading/writing).</summary>
 * <param name="handle">The file handle to close.  Returned by <a href="#fopen">fopen</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <returns>
 *   <b><c>true</c></b>: The function executed successfully.<p/>
 *   <b><c>false</c></b>: The function failed to execute.  The file could not be closed.  It may already
 * be closed.
 * </returns>
 */
native bool:fclose(File:handle);

/**
 * <library>file</library>
 * <summary>Creates a file in the "tmp", "temp" or root directory with random name for reading and writing.
 *  The file is deleted after <a href="#fclose">fclose</a> is used on the file.</summary>
 * <remarks>This function can crash the server when the right directory isn't created.</remarks>
 * <returns>The temporary file handle. <b><c>0</c></b> if failed.</returns>
 */
native File:ftemp();

/**
 * <library>file</library>
 * <summary>Delete a file.</summary>
 * <param name="filename">The <b>path</b> of the file to delete. (NOTE: NOT a file handle)</param>
 * <remarks>The file path must be valid.</remarks>
 * <remarks>Files that are currently open (<a href="#fopen">fopen</a>) must be closed first (<a href="#fclose">fclose</a>)
 * to be deleted.</remarks>
 * <returns>
 *   <b><c>true</c></b>: The function executed successfully.<p/>
 *   <b><c>false</c></b>: The function failed to execute.  The file doesn't exist, or you don't have
 * permission to delete it.
 * </returns>
 */
native bool:fremove(const filename[]);

/**
 * <library>file</library>
 * <summary>Write text into a file.</summary>
 * <param name="handle">The handle of the file to write to (returned by <a href="#fopen">fopen</a>)</param>
 * <param name="string">The string of text to write in to the file</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <remarks>This functions writes to the file in UTF-8, which does not support some localized language
 * symbols.</remarks>
 * <remarks>This function doesn't support <a href="#strpack">packed strings</a>.</remarks>
 * <returns>The length of the written string as an integer.</returns>
 */
native fwrite(File:handle, const string[]);

/**
 * <library>file</library>
 * <summary>Read a single line from a file.</summary>
 * <param name="handle">The handle of the file to read from (returned by <a href="#fopen">fopen</a>)</param>
 * <param name="string">A string array to store the read text in, passed by reference</param>
 * <param name="size">The number of bytes to read (optional=<b><c>sizeof (string)</c></b>)</param>
 * <param name="pack">Should the string be packed? (optional=<b><c>false</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <returns>The length of <b>string</b> (the read text) as an integer.</returns>
 */
native fread(File:handle, string[], size = sizeof (string), bool:pack = false);

/**
 * <library>file</library>
 * <summary>Write one character to a file.</summary>
 * <param name="handle">The File handle to use, earlier opened by <a href="#fopen">fopen</a></param>
 * <param name="value">The character to write into the file</param>
 * <param name="utf8">If true, write in UTF8 mode, otherwise in extended ASCII (optional=<b><c>true</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 */
native bool:fputchar(File:handle, value, bool:utf8 = true);

/**
 * <library>file</library>
 */
native fgetchar(File:handle, bool:utf8 = true);

/**
 * <library>file</library>
 * <summary>Write data to a file in binary format, while ignoring line brakes and encoding.</summary>
 * <param name="handle">The File handle to use, opened by fopen()</param>
 * <param name="buffer">The data to write to the file</param>
 * <param name="size">The number of cells to write (optional=<b><c>sizeof (buffer)</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 */
native fblockwrite(File:handle, const buffer[], size = sizeof (buffer));

/**
 * <library>file</library>
 * <summary>This function allows you to read data from a file, without encoding and line terminators.</summary>
 * <param name="handle">File handle to use, opened by <a href="#fopen">fopen</a></param>
 * <param name="buffer">The buffer to save the read data in</param>
 * <param name="size">The number of cells to read (optional=<b><c>sizeof (buffer)</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <returns>The number of cells read. <b><c>0</c></b> if the file end has been reached.</returns>
 */
native fblockread(File:handle, buffer[], size = sizeof (buffer));

/**
 * <library>file</library>
 * <summary>Change the current position in the file.  You can either seek forward or backward through
 * the file.</summary>
 * <param name="handle">The file handle to use.  Returned by <a href="#fopen">fopen</a></param>
 * <param name="position">The new position in the file, relative to the parameter whence (see below)
 * (optional=<b><c>0</c></b>)</param>
 * <param name="whence">The starting position to which parameter position relates (optional=<b><c>seek_start</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <remarks>
 *   <b>Whences:</b><p/>
 *   <ul>
 *     <li><b><c>seek_start</c></b> - set the file position relative to the start of the file (the position
 * parameter must be positive).</li>
 *     <li><b><c>seek_current</c></b> - set the file position relative to the current file position:
 * the position parameter is added to the current position.</li>
 *     <li><b><c>seek_end</c></b> - set the file position relative to the end of the file (parameter
 * position must be zero or negative).</li>
 *   </ul>
 * </remarks>
 * <returns>The new position, relative to the start of the file.</returns>
 */
native fseek(File:handle, position = 0, seek_whence:whence = seek_start);

/**
 * <library>file</library>
 * <summary>Get the current position in the file.</summary>
 * <param name="handle">The file handle to use.  Returned by <a href="#fopen">fopen</a></param>
 * <returns>The current position, relative to the start of the file.</returns>
 */
native ftell(File:handle);

/**
 * <library>file</library>
 * <summary>Returns the length of a file.</summary>
 * <param name="handle">The file handle returned by <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <returns>The length of a file, in bytes.</returns>
 */
native flength(File:handle);

/**
 * <library>file</library>
 * <summary>Flush a file to disk (ensure all writes are complete).</summary>
 * <param name="handle">The file handle returned by <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a></param>
 * <remarks>Actually just calls <c>flength</c> as that has to force a flush to be accurate.</remarks>
 */
/*
native bool:fflush(File:handle);
*/
stock bool:fflush(File:__handle)
{
	if (__handle)
	{
		flength(__handle);
		return true;
	}
	return false;
}

/**
 * <library>file</library>
 * <summary>Checks if a specific file exists in the <b><c>/scriptfiles</c></b> directory.</summary>
 * <param name="filename">The name of the file</param>
 * <returns>1 if the file exists, 0 otherwise.</returns>
 */
native fexist(const filename[]);

/**
 * <library>file</library>
 * <summary>Return the size and the time stamp of a file.</summary>
 * <param name="filename">The name of the file.</param>
 * <param name="size">If the function is successful, this param-eter holds the size of the file on return.</param>
 * <param name="timestamp">If the function is successful, this parameter holds the time of the last modification of the file on
 * return.</param>
 * <param name="attrib">If the function is successful, this parameter holds the file attributes.</param>
 * <param name="inode">If the function is successful, this parameter holds inode number of the file.  An inode number is a number that
 * uniquely identifies a file, and it usually indicates the physical position of (the start of) the file on the disk or memory card.</param>
 * <remarks>
 * In contrast to the function flength, this function does not need the file to be opened for querying its size.
 * <p/>
 * The time is in number of seconds since midnight at 1 January 1970: the start of the UNIX system epoch.
 * <p/>
 * The file attributes are a bit mask. The meaning of each bit depends on the underlying file system (e.g. FAT, NTFS, etx2 and others).
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:fstat(const filename[], &size = 0, &timestamp = 0, &attrib = 0, &inode = 0);

/**
 * <library>file</library>
 * <summary>Rename a file.</summary>
 * <param name="oldname">The current name of the file, optionally including a full path.</param>
 * <param name="newname">The new name of the file, optionally including a full path.</param>
 * <remarks>
 * In addition to changing the name of the file, this function can also move the file to a different directory.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:frename(const oldname[], const newname[]);

/**
 * <library>file</library>
 * <summary>Copy a file.</summary>
 * <param name="source">The name of the (existing) file that must be copied, optionally including a path.</param>
 * <param name="target">The name of the new file, optionally including a full path.</param>
 * <remarks>
 * If the target file already exists, it is overwritten.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:fcopy(const source[], const target[]);

/**
 * <library>file</library>
 * <summary>Return the 32-bit CRC value of a file.</summary>
 * <param name="filename">The name of the file.</param>
 * <remarks>
 * The CRC value is a useful measure to check whether the contents of a file has changed during
 * transmission or whether it has been edited (provided that the CRC value of the original file was
 * saved). The CRC value returned by this function is the same as the one used in ZIP archives
 * (PKZip, WinZip) and the "SFV" utilities and file formats.
 * </remarks>
 * <returns>The 32-bit CRC value of the file, or zero if the file cannot be opened.</returns>
 */
native filecrc(const filename[]);

/**
 * <library>file</library>
 * <summary>Returns the free disk space.</summary>
 * <param name="volume">The name of the volume on systems that support multiple disks or multiple memory cards.  On single-volume systems, it
 * is optional.</param>
 * <remarks>
 * The maximum size that can be supported 2048 GiB (2 terabyte).
 * </remarks>
 * <returns>The amount of free space in KiB.</returns>
 */
forward diskfree(const volume[] = "");

/**
 * <library>file</library>
 * <summary>Set the file attributes.</summary>
 * <param name="filename">The name of the file.</param>
 * <param name="timestamp">Time of the last modification of the file.  When this parameter is set to zero, the time stamp of the file is not
 * changed.</param>
 * <param name="attrib">A bit mask with the new attributes of the file.  When set to 0x0F, the attributes of the file are not changed.</param>
 * <remarks>
 * The time is in number of seconds since midnight at 1 January 1970: the start of the UNIX system epoch.
 * <p/>
 * The file attributes are a bit mask. The meaning of each bit depends on the underlying file system (e.g. FAT, NTFS, etx2 and others).
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:fattrib(const filename[], timestamp = 0, attrib = 0x0F);

/**
 * <library>file</library>
 * <summary>Find a filename matching a pattern.</summary>
 * <param name="filename">The string to hold the result in, returned as a packed string</param>
 * <param name="pattern">The pattern that should be matched.  May contain wildcards</param>
 * <param name="index">The number of the file, in case there are multiple matches (optional=<b><c>0</c></b>)</param>
 * <param name="size">The maximum size of parameter name (optional=<b><c>sizeof (name)</c></b>)</param>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:fmatch(const filename[], const pattern[], index = 0, size = sizeof (filename));

/**
 * <library>file</library>
 * <summary>Create a directory.</summary>
 * <param name="dirname">The name of the directory to create, optionally including a full path.</param>
 * <remarks>
 * To delete the directory again, use <c>fremove</c>.  The directory must be empty before it can be removed.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
#pragma deprecated Use `fcreatedir`.
native bool:fmkdir(const dirname[]) = fcreatedir;

/**
 * <library>file</library>
 * <summary>Create a directory.</summary>
 * <param name="dirname">The name of the directory to create, optionally including a full path.</param>
 * <remarks>
 * To delete the directory again, use <c>fremove</c>.  The directory must be empty before it can be removed.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:fcreatedir(const dirname[]);

/**
 * <library>file</library>
 * <summary>Deletes a key or a section from an INI file.</summary>
 * <param name="cfgname">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section from which to delete the key.  If this parameter is not set,
 * the function stores the key/value pair outside any section.</param>
 * <param name="key">The key to delete.  If this parameter is not set, the function deletes the entire section.</param>
 * <remarks>
 * If parameters <c>section</c> and <c>key</c> are both not set, the function deletes all keys that are outside any sections.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:deletecfg(const cfgname[] = "", const section[] = "", const key[] = "");

/**
 * <library>file</library>
 * <summary>Reads a text field from an INI file.</summary>
 * <param name="cfgname">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section to look for the key.  If this parameter is not set, the
 * function reads the key outside any section.</param>
 * <param name="key">The key whose value must be looked up.</param>
 * <param name="value">The buffer into which to store the value.  If the key is not present in the
 * appropriate section of the INI file, the contents of parameter <c>defvalue</c> is copied into
 * this buffer.</param>
 * <param name="size">The (maximum) size of the value array in cells.  For a packed string, one cell
 * holds multiple characters.</param>
 * <param name="defvalue">The string to copy into parameter value in the case that the function
 * cannot read the field from the INI file.</param>
 * <param name="pack">If the pack parameter is false, the text is stored as an unpacked string and
 * the function parses UTF-8 encoding.  When reading text in a packed string, no UTF-8
 * interpretation occurs.</param>
 * <returns>The number of characters stored in parameter <c>value</c>.</returns>
 */
native readcfg(const cfgname[] = "", const section[] = "", const key[], value[], size = sizeof (value), const defvalue[] = "", bool:pack = false);

/**
 * <library>file</library>
 * <summary>Reads a numeric field from an INI file.</summary>
 * <param name="cfgname">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section to look for the key.  If this parameter is not set, the
 * function reads the key outside any section.</param>
 * <param name="key">The key whose value must be looked up.</param>
 * <param name="defvalue">The value to return in the case that the function
 * cannot read the field from the INI file.</param>
 * <returns>The numeric value if the field, or the value of <c>defvalue</c> if the field was not
 * found in the section and/or at the key.</returns>
 */
native readcfgvalue(const cfgname[] = "", const section[] = "", const key[], defvalue = 0);

/**
 * <library>file</library>
 * <summary>Writes a text field to an INI file.</summary>
 * <param name="filename">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section to store the key under. If this parameter is not set, the
 * function stores the key/value pair outside any section.</param>
 * <param name="key">The key for the field.</param>
 * <param name="value">The value for the field.</param>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:writecfg(const filename[] = "", const section[] = "", const key[], const value[]);

/**
 * <library>file</library>
 * <summary>Writes a numeric field to an INI file.</summary>
 * <param name="filename">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section to store the key under. If this parameter is not set, the
 * function stores the key/value pair outside any section.</param>
 * <param name="key">The key for the field.</param>
 * <param name="value">The value for the field, as a signed (decimal) number.</param>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:writecfgvalue(const filename[] = "", const section[] = "", const key[], value);

/**
 * <library>file</library>
 */
native bool:ffind(const pattern[], filename[], size = sizeof (filename), &idx);

/**
 * <library>file</library>
 */
native bool:dfind(const pattern[], filename[], size = sizeof (filename), &idx);

/**
 * <library>file</library>
 */
native bool:dcreate(const name[]) = fcreatedir;

/**
 * <library>file</library>
 */
native bool:drename(const oldname[], const newname[]) = frename;

/**
 * <library>file</library>
 */
native bool:ftouch(const filename[]);

/**
 * <library>file</library>
 */
forward File:operator++(File:a);
/**
 * <library>file</library>
 */
forward File:operator--(File:a);
/**
 * <library>file</library>
 */
forward File:operator-(File:a);
/**
 * <library>file</library>
 */
forward File:operator+(File:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator+(File:a, _:b);
/**
 * <library>file</library>
 */
forward File:operator-(File:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator-(_:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator-(File:a, _:b);
/**
 * <library>file</library>
 */
forward File:operator*(File:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator*(File:a, _:b);
/**
 * <library>file</library>
 */
forward File:operator/(File:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator/(_:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator/(File:a, _:b);
/**
 * <library>file</library>
 */
forward File:operator%(File:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator%(_:a, File:b);
/**
 * <library>file</library>
 */
forward File:operator%(File:a, _:b);
/**
 * <library>file</library>
 */
forward bool:operator<(File:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator<(_:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator<(File:a, _:b);
/**
 * <library>file</library>
 */
forward bool:operator<=(File:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator<=(_:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator<=(File:a, _:b);
/**
 * <library>file</library>
 */
forward bool:operator>(File:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator>(_:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator>(File:a, _:b);
/**
 * <library>file</library>
 */
forward bool:operator>=(File:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator>=(_:a, File:b);
/**
 * <library>file</library>
 */
forward bool:operator>=(File:a, _:b);
