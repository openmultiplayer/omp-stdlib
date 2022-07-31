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

#include "core"
#include "string"

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
	seek_end,
}
static stock seek_whence:_@seek_whence() { return seek_whence; }

/**
 * <library>file</library>
 */
const EOF = -1;

/**
 * <library>file</library>
 * <summary>Open a file (to read from or write to).</summary>
 * <param name="name">The path to the file to open (if just a filename is specified, it will open the
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
native File:fopen(const name[], filemode:mode = io_readwrite);

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
 * <param name="name">The <b>path</b> of the file to delete. (NOTE: NOT a file handle)</param>
 * <remarks>The file path must be valid.</remarks>
 * <remarks>Files that are currently open (<a href="#fopen">fopen</a>) must be closed first (<a href="#fclose">fclose</a>)
 * to be deleted.</remarks>
 * <returns>
 *   <b><c>true</c></b>: The function executed successfully.<p/>
 *   <b><c>false</c></b>: The function failed to execute.  The file doesn't exist, or you don't have
 * permission to delete it.
 * </returns>
 */
native bool:fremove(const name[]);

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
native __fgetcharthree(File:handle, value, bool:utf8 = true) = fgetchar;

/**
 * <library>file</library>
 * <summary>Reads a single character from a file.</summary>
 * <param name="handle">The file handle to use; returned by <a href="#fopen">fopen</a></param>
 * <param name="utf8">If true, read a character as UTF-8, otherwise as extended ASCII (optional=<b><c>true</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#fopen">fopen</a> or <a href="#ftemp">ftemp</a>.</remarks>
 * <returns>If succeed, it returns the extended ASCII or UTF-8 value of the character at the current
 * position in the file, otherwise EOF (end of file).</returns>
 */
stock __fgetchartwo(File:handle, bool:utf8 = true)
{
	return __fgetcharthree(handle, _:utf8, utf8);
}

// Backwards-compatibility trick.  Gives a warning about the number of parameters being wrong, but
// swaps the parameters around so the correct one is used.  Only happens when three parameters are
// given instead of two, and uses a pre-processor deferral trick to prevent recursion.
#define fgetchar(%0) (__fgetchartwo(%0)__fgetchar)
#define __fgetchartwo(%0,%1,%2)__fgetchar) __fgetchartwo(%0,%2,%1))
#define __fgetchar

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
stock ftell(File:handle)
{
	return fseek(handle, 0, seek_current);
}

#define ftell(%0) fseek((%0), 0, seek_current)

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
 * <summary>Checks if a specific file exists in the <b><c>/scriptfiles</c></b> directory.</summary>
 * <param name="name">The name of the file</param>
 * <returns>1 if the file exists, 0 otherwise.</returns>
 */
native fexist(const name[]);

/**
 * <library>file</library>
 * <summary>Return the size and the time stamp of a file.</summary>
 * <param name="name">The name of the file.</param>
 * <param name="size">If the function is successful, this param-eter holds the size of the file on return.</param>
 * <param name="timestamp">If the function is successful, this parameter holds the time of the last modification of the file on return.</param>
 * <param name="attrib">If the function is successful, this parameter holds the file attributes.</param>
 * <param name="inode">If the function is successful, this parameter holds inode number of the file.  An inode number is a number that uniquely identifies a file, and it usually indicates the physical position of (the start of) the file on the disk or memory card.</param>
 * <remarks>
 * In contrast to the function flength, this function does not need the file to be opened for querying its size.
 * <p/>
 * The time is in number of seconds since midnight at 1 January 1970: the start of the UNIX system epoch.
 * <p/>
 * The file attributes are a bit mask. The meaning of each bit depends on the underlying file system (e.g. FAT, NTFS, etx2 and others).
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
stock bool:fstat(const name[], &size = 0, &timestamp = 0, &attrib = 0, &inode = 0)
{
	// Not supported.
	timestamp = 0;
	attrib = 0;
	inode = 0;
	new File:fhnd = fopen(name);
	if (fhnd)
	{
		size = flength(fhnd);
		fclose(fhnd);
		return true;
	}
	return false;
}

#if !defined FCFG_MAX_LINE_LENGTH
	#define FCFG_MAX_LINE_LENGTH (256)
#endif

/**
 * <library>file</library>
 */
static stock __fbuf[FCFG_MAX_LINE_LENGTH];

/**
 * <library>file</library>
 */
static stock bool:__fpartialcopy(File:i, end, const newname[])
{
	// Try open the output file (the new name).
	new File:o = fopen(newname, io_write);
	if (!o)
	{
		return false;
	}
	// Clamp the read size to the number of cells in the file.
	new count = min(sizeof (__fbuf), end / (cellbits / 8));
	// The last few bytes.
	end &= (cellbits / 8) - 1;
	// Only loop as long as we read a full block.  Partials mean the end.  Might
	// do an extra read if `count` starts out as `0`, but that only happens on
	// files less than 4 bytes long and doesn't matter anyway.
	do
	{
		count = fblockread(i, __fbuf, count);
		fblockwrite(o, __fbuf, count);
	}
	while (count == sizeof (__fbuf));
	// Clean up any trailing bytes.
	while (end--)
	{
		fputchar(o, fgetchar(i, false), false);
	}
	return fclose(o);
}

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
stock bool:frename(const oldname[], const newname[])
{
	// Check the target doesn't exist.
	if (fexist(newname))
	{
		return false;
	}
	// Try open the input file (the old name).
	new File:i = fopen(oldname, io_read);
	if (!i)
	{
		return false;
	}
	new bool:ret = __fpartialcopy(i, flength(i), newname);
	fclose(i);
	if (ret && fremove(oldname))
	{
		return true;
	}
	// Couldn't delete the old version, so the rename failed.
	fremove(newname);
	return false;
}

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
stock bool:fcopy(const source[], const target[])
{
	// Try open the input file (the old name).
	new File:i = fopen(source, io_read);
	if (!i)
	{
		return false;
	}
	new bool:ret = __fpartialcopy(i, flength(i), target);
	fclose(i);
	return ret;
}

/**
 * <library>file</library>
 * <summary>Return the 32-bit CRC value of a file.</summary>
 * <param name="name">The name of the file.</param>
 * <remarks>
 * The CRC value is a useful measure to check whether the contents of a file has changed during
 * transmission or whether it has been edited (provided that the CRC value of the original file was
 * saved). The CRC value returned by this function is the same as the one used in ZIP archives
 * (PKZip, WinZip) and the "SFV" utilities and file formats.
 * </remarks>
 * <returns>The 32-bit CRC value of the file, or zero if the file cannot be opened.</returns>
 */
stock filecrc(const name[])
{
	static crctable[256] = {
		0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA, 0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
		0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988, 0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
		0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
		0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
		0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
		0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
		0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
		0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924, 0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
		0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
		0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
		0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
		0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
		0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
		0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
		0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
		0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
		0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
		0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
		0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
		0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
		0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
		0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
		0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236, 0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
		0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
		0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
		0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38, 0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
		0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
		0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
		0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
		0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
		0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
		0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
	};
	new File:i = fopen(name, io_read);
	if (!i)
	{
		return 0;
	}
	new crc = 0xFFFFFFFF;
	new ch;
	// This is the slowest way to write this function - reading a single byte
	// from a file at once.
	while ((ch = fgetchar(i, false)))
	{
		crc = (crc >>> 8) ^ crctable[(crc ^ ch) & 0xFF];
	}
	fclose(i);
	return crc ^ 0xFFFFFFFF;
}

/**
 * <library>file</library>
 * <summary>Returns the free disk space.</summary>
 * <param name="volume">The name of the volume on systems that support multiple disks or multiple memory cards.  On single-volume systems, it is optional.</param>
 * <remarks>
 * The maximum size that can be supported 2048 GiB (2 terabyte).
 * </remarks>
 * <returns>The amount of free space in KiB.</returns>
 */
forward diskfree(const volume[] = "");

/**
 * <library>file</library>
 * <summary>Set the file attributes.</summary>
 * <param name="name">The name of the file.</param>
 * <param name="timestamp">Time of the last modification of the file.  When this parameter is set to zero, the time stamp of the file is not changed.</param>
 * <param name="attrib">A bit mask with the new attributes of the file.  When set to 0x0F, the attributes of the file are not changed.</param>
 * <remarks>
 * The time is in number of seconds since midnight at 1 January 1970: the start of the UNIX system epoch.
 * <p/>
 * The file attributes are a bit mask. The meaning of each bit depends on the underlying file system (e.g. FAT, NTFS, etx2 and others).
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
forward bool:fattrib(const name[], timestamp = 0, attrib = 0x0F);

/**
 * <library>file</library>
 * <summary>Find a filename matching a pattern.</summary>
 * <param name="name">The string to hold the result in, returned as a packed string</param>
 * <param name="pattern">The pattern that should be matched.  May contain wildcards</param>
 * <param name="index">The number of the file, in case there are multiple matches (optional=<b><c>0</c></b>)</param>
 * <param name="size">The maximum size of parameter name (optional=<b><c>sizeof (name)</c></b>)</param>
 * <remarks>This function does not work in the current SA:MP version!</remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
forward bool:fmatch(name[], const pattern[], index = 0, size = sizeof (name));

/**
 * <library>file</library>
 * <summary>Create a directory.</summary>
 * <param name="name">The name of the directory to create, optionally including a full path.</param>
 * <remarks>
 * To delete the directory again, use <c>fremove</c>.  The directory must be empty before it can be removed.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
forward bool:fmkdir(const name[]);

/**
 * <library>file</library>
 */
static stock const __cfgdefault[] = "config.ini";

/**
 * <library>file</library>
 * <summary>Deletes a key or a section from an INI file.</summary>
 * <param name="filename">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section from which to delete the key.  If this parameter is not set,
 * the function stores the key/value pair outside any section.</param>
 * <param name="key">The key to delete.  If this parameter is not set, the function deletes the entire section.</param>
 * <remarks>
 * If parameters <c>section</c> and <c>key</c> are both not set, the function deletes all keys that are outside any sections.
 * </remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
stock bool:deletecfg(const filename[] = "", const section[] = "", const key[] = "")
{
	// Open the cfg file, and a temp file for swap space.
	new File:i = fopen(filename[0] ? filename : __cfgdefault, io_read);
	if (!i)
	{
		return false;
	}
	new File:o = ftemp();
	if (!o)
	{
		fclose(i);
		return false;
	}
	// Max line length.
	new sectionlen = strlen(section);
	new keylen = strlen(key);
	new bool:insection = sectionlen == 0;
	while (fread(i, __fbuf))
	{
		if (insection)
		{
			if (__fbuf[0] == '[')
			{
				// New section, so the end of the old one.
				insection = false;
				fwrite(o, __fbuf);
			}
			else if (keylen && !(strcmp(__fbuf, key, false, keylen) == 0 && (__fbuf[keylen] == ':' || __fbuf[keylen] == '=')))
			{
				// This isn't the key we're deleting.  I could use DeMorgan on the line above, but
				// I think it is clearer this way.  It checks that the key isn't an exact match.
				fwrite(o, __fbuf);
			}
			// Else don't copy this line.
		}
		else
		{
			// Not in a section before, are we now?
			if (sectionlen && (__fbuf[0] == '[' && strcmp(__fbuf[1], section, false, sectionlen) == 0 && __fbuf[sectionlen + 1] == ']'))
			{
				// New correct section.
				insection = true;
				if (keylen)
				{
					// Not deleting the section, so keep the header.
					fwrite(o, __fbuf);
				}
			}
			else
			{
				// Not in the correct section, so keep the line.
				fwrite(o, __fbuf);
			}
		}
	}
	fclose(i);
	if (fremove(filename[0] ? filename : __cfgdefault))
	{
		fseek(o);
		insection = __fpartialcopy(o, flength(o), filename[0] ? filename : __cfgdefault);
		fclose(o);
		return insection;
	}
	fclose(o);
	return false;
}

/**
 * <library>file</library>
 * <summary>Reads a text field from an INI file.</summary>
 * <param name="filename">The name and path of the INI file.  If this parameter is not set, the
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
stock readcfg(const filename[] = "", const section[] = "", const key[], value[], size = sizeof (value), const defvalue[] = "", bool:pack = false)
{
	// Open the cfg file, and a temp file for swap space.
	new File:i = fopen(filename[0] ? filename : __cfgdefault, io_read);
	if (!i)
	{
		return false;
	}
	// Max line length.
	new sectionlen = strlen(section);
	new keylen = strlen(key);
	new bool:insection = sectionlen == 0;
	new len;
	while ((len = fread(i, __fbuf)))
	{
		if (insection)
		{
			if (__fbuf[0] == '[')
			{
				// The correction section ended, so we didn't find the value.
				break;
			}
			else if (strcmp(__fbuf, key, false, keylen) == 0 && (__fbuf[keylen] == ':' || __fbuf[keylen] == '='))
			{
				// Found the value.  Remove the newline characters.
				while (__fbuf[--len] <= ' ')
				{
					__fbuf[len] = '\0';
				}
				if (pack)
				{
					strpack(value, __fbuf[keylen + 1], size);
				}
				else
				{
					strunpack(value, __fbuf[keylen + 1], size);
				}
				fclose(i);
				return min(len - keylen - 1, size - 1);
			}
		}
		else
		{
			// Not in a section before, are we now?
			if (sectionlen && (__fbuf[0] == '[' && strcmp(__fbuf[1], section, false, sectionlen) == 0 && __fbuf[sectionlen + 1] == ']'))
			{
				// New correct section.
				insection = true;
			}
		}
	}
	fclose(i);
	if (pack)
	{
		strpack(value, defvalue, size);
	}
	else
	{
		strunpack(value, defvalue, size);
	}
	return min(strlen(defvalue), size - 1);
}

/**
 * <library>file</library>
 * <summary>Reads a numeric field from an INI file.</summary>
 * <param name="filename">The name and path of the INI file.  If this parameter is not set, the
 * function uses the default name <c>"config.ini"</c>.</param>
 * <param name="section">The section to look for the key.  If this parameter is not set, the
 * function reads the key outside any section.</param>
 * <param name="key">The key whose value must be looked up.</param>
 * <param name="defvalue">The string to copy into parameter value in the case that the function
 * cannot read the field from the INI file.</param>
 * <returns>The numeric value if the field, or the value of <c>defvalue</c> if the field was not
 * found in the section and/or at the key.</returns>
 */
stock readcfgvalue(const filename[] = "", const section[] = "", const key[], defvalue = 0)
{
	new dest[16];
	if (readcfg(filename, section, key, dest))
	{
		// Got a number.
		return strval(dest);
	}
	return defvalue;
}

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
stock bool:writecfg(const filename[] = "", const section[] = "", const key[], const value[])
{
	// First time writing.
	if (!fexist(filename[0] ? filename : __cfgdefault))
	{
		new File:o = fopen(filename[0] ? filename : __cfgdefault, io_write);
		if (!o)
		{
			return false;
		}
		if (section[0])
		{
			fwrite(o, "[");
			fwrite(o, section);
			fwrite(o, "]");
			fwrite(o, "\r\n");
		}
		fwrite(o, key);
		fwrite(o, "=");
		fwrite(o, value);
		fwrite(o, "\r\n");
		return fclose(o);
	}
	// Open the cfg file, and a temp file for swap space.
	new File:i = fopen(filename[0] ? filename : __cfgdefault, io_read);
	if (!i)
	{
		return false;
	}
	new File:o = ftemp();
	if (!o)
	{
		fclose(i);
		return false;
	}
	// Max line length.
	new sectionlen = strlen(section);
	new keylen = strlen(key);
	new bool:insection = sectionlen == 0;
	new bool:written = false;
	while (fread(i, __fbuf))
	{
		if (insection)
		{
			if (__fbuf[0] == '[')
			{
				if (!written)
				{
					// Add the new key to the end of the current section.
					fwrite(o, key);
					fwrite(o, "=");
					fwrite(o, value);
					fwrite(o, "\r\n");
					written = true;
				}
				// New section, so the end of the old one.
				insection = false;
				fwrite(o, __fbuf);
			}
			else if (strcmp(__fbuf, key, false, keylen) == 0 && (__fbuf[keylen] == ':' || __fbuf[keylen] == '='))
			{
				if (!written)
				{
					// Found the key.  Replace it.
					fwrite(o, key);
					fwrite(o, "=");
					fwrite(o, value);
					fwrite(o, "\r\n");
					written = true;
				}
			}
			else
			{
				// Else copy this line.
				fwrite(o, __fbuf);
			}
		}
		else
		{
			// Not in a section before, are we now?
			if (sectionlen && (__fbuf[0] == '[' && strcmp(__fbuf[1], section, false, sectionlen) == 0 && __fbuf[sectionlen + 1] == ']'))
			{
				// New correct section.
				insection = true;
				if (keylen)
				{
					// Not deleting the section, so keep the header.
					fwrite(o, __fbuf);
				}
			}
			else
			{
				// Not in the correct section, so keep the line.
				fwrite(o, __fbuf);
			}
		}
	}
	fclose(i);
	if (!written)
	{
		// Didn't find the correct section, or the correct one ended.
		if (!insection && sectionlen)
		{
			fwrite(o, "[");
			fwrite(o, section);
			fwrite(o, "]");
			fwrite(o, "\r\n");
		}
		fwrite(o, key);
		fwrite(o, "=");
		fwrite(o, value);
		fwrite(o, "\r\n");
	}
	if (fremove(filename[0] ? filename : __cfgdefault))
	{
		fseek(o);
		insection = __fpartialcopy(o, flength(o), filename[0] ? filename : __cfgdefault);
		fclose(o);
		return insection;
	}
	fclose(o);
	return false;
}

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
stock bool:writecfgvalue(const filename[] = "", const section[] = "", const key[], value)
{
	if (value == cellmin)
	{
		// There's also a bug in `format` with `cellmin`.
		return writecfg(filename, section, key, "-2147483648");
	}
	// Don't use `valstr`, there's a bug with large numbers.
	new dest[16];
	__strformat(dest, sizeof (dest), "%d", value);
	return writecfg(filename, section, key, dest);
}

