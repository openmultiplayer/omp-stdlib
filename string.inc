#if defined _string_included
	#endinput
#endif
#define _string_included

/**
 * <library name="string" summary="String functions.">
 *   <license>
 *     (c) Copyright 2005, ITB CompuPhase
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

#pragma library String

/**
 * <library>string</library>
 * <summary>Get the length of a string.</summary>
 * <param name="string">The string to get the length of</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <returns>The length of the string as an integer.</returns>
 */
native strlen(const string[]);

/**
 * <library>string</library>
 * <summary>Pack a string.  Packed strings use 75% less memory.</summary>
 * <param name="dest">The destination string to save the packed string in, passed by reference</param>
 * <param name="source">The source, original string</param>
 * <param name="maxlength">The maximum size to insert (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <returns>The number of characters packed.</returns>
 */
native strpack(dest[], const source[], maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>This function can be used to unpack a string.</summary>
 * <param name="dest">The destination string to save the unpacked string in, passed by reference</param>
 * <param name="source">The source, original packed string</param>
 * <param name="maxlength">The maximum size to insert (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <seealso name="ispacked"/>
 * <seealso name="strpack"/>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <returns>The number of characters packed.</returns>
 */
native strunpack(dest[], const source[], maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>This function concatenates (joins together) two strings into the destination string.</summary>
 * <param name="dest">The string to store the two concatenated strings in</param>
 * <param name="source">The source string</param>
 * <param name="maxlength">The maximum length of the destination (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <returns>The length of the new destination string.</returns>
 */
native strcat(dest[], const source[], maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>Copies a string into the destination string.</summary>
 * <param name="dest">The string to copy the source string into</param>
 * <param name="source">The source string</param>
 * <param name="maxlength">The maximum length of the destination (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <seealso name="strcat"/>
 * <returns>The length of the new destination string.</returns>
 */
/*
native strcopy(dest[], const source[], maxlength = sizeof (dest));
*/
stock strcopy(__dest[], const __source[], __maxlength = sizeof (__dest))
{
	return strcat((__dest[0] = EOS, __dest), __source, __maxlength);
}

/**
 * <library>string</library>
 * <summary>Extract a range of characters from a string.</summary>
 * <param name="dest">The string to store the extracted characters in</param>
 * <param name="source">The string from which to extract characters</param>
 * <param name="start">The position of the first character</param>
 * <param name="end">The position of the last character</param>
 * <param name="maxlength">The length of the destination. (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <returns>The number of characters stored in dest[].</returns>
 */
native strmid(dest[], const source[], start, end, maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>Insert a string into another string.</summary>
 * <param name="string">The string you want to insert substr in</param>
 * <param name="substr">The string you want to insert into string</param>
 * <param name="pos">The position to start inserting</param>
 * <param name="maxlength">The maximum size to insert (optional=<b><c>sizeof (string)</c></b>)</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 */
native bool:strins(string[], const substr[], pos, maxlength = sizeof (string));

/**
 * <library>string</library>
 * <summary>Delete part of a string.</summary>
 * <param name="string">The string to delete part of</param>
 * <param name="start">The position of the first character to delete</param>
 * <param name="end">The position of the last character to delete</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 */
native bool:strdel(string[], start, end);

/**
 * <library>string</library>
 * <summary>Compares two strings to see if they are the same.</summary>
 * <param name="string1">The first string to compare</param>
 * <param name="string2">The second string to compare</param>
 * <param name="ignorecase">When set to true, the case doesn't matter - HeLLo is the same as Hello.
 *  When false, they're not the same (optional=<b><c>0</c></b>)</param>
 * <param name="length">When this length is set, the first x chars will be compared - doing "Hello"
 * and "Hell No" with a length of 4 will say it's the same string (optional=<b><c>cellmax</c></b>)</param>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <seealso name="strequal"/>
 * <remarks>This function returns <b><c>0</c></b> if either string is empty.  Check for null strings
 * with <c>isnull()</c>.  If you do not, for example, people can login to anyone's account by simply
 * entering a blank password. </remarks>
 * <remarks>
 *   <code>
 *   #if !defined isnull<p/>
 *   &#9;#define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') &amp;&amp; (!(%1[1]))))<p/>
 *   #endif
 *   </code>
 * </remarks>
 * <remarks>If you compare strings from a text file, you should take in to account the 'carriage return'
 * and 'new line' special characters (\r \n), as they are included, when using fread.</remarks>
 * <returns>
 *   <b><c>0</c></b> if strings match each other on given length;.<p/>
 *   <b><c>1</c></b> or <b><c>-1</c></b> if some character do not match: <c>string1[i] - string2[i]</c>.<p/>
 *   <b>difference in number of characters</b> if one string matches only part of another string.
 * </returns>
 */
native strcmp(const string1[], const string2[], bool:ignorecase = false, length = cellmax);

/**
 * <library>string</library>
 * <summary>Search for a sub string in a string.</summary>
 * <param name="string">The string you want to search in (haystack)</param>
 * <param name="sub">The string you want to search for (needle)</param>
 * <param name="ignorecase">When set to true, the case doesn't matter - HeLLo is the same as Hello.
 *  When false, they're not the same (optional=<b><c>0</c></b>)</param>
 * <param name="pos">The offset to start searching from (optional=<b><c>0</c></b>)</param>
 * <seealso name="strcmp"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <returns>The number of characters before the sub string (the sub string's start position) or <b><c>-1</c></b>
 * if it's not found.</returns>
 */
native strfind(const string[], const sub[], bool:ignorecase = false, pos = 0);

/**
 * <library>string</library>
 * <summary>Convert a string to an integer.</summary>
 * <param name="string">The string you want to convert to an integer</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strcat"/>
 * <returns>The integer value of the string. <b><c>0</c></b> if the string is not numeric.</returns>
 */
native strval(const string[]);

/**
 * <library>string</library>
 * <summary>Convert an integer into a string.</summary>
 * <param name="dest">The destination of the string</param>
 * <param name="value">The value to convert to a string</param>
 * <param name="pack">Whether to pack the destination (optional=<b><c>0</c></b>)</param>
 * <seealso name="strval"/>
 * <seealso name="strcmp"/>
 * <remarks>Passing a high value to this function can cause the server to freeze/crash.  Fixes are available.
 *  Below is a fix that can be put straight in to your script.</remarks>
 * <remarks>
 *   <code>
 *     // valstr fix by Slice<p/>
 *     stock FIX_valstr(dest[], value, bool:pack = false)<p/>
 *     {<p/>
 *     &#9;// format can't handle cellmin properly<p/>
 *     &#9;static const cellmin_value[] = !"-2147483648";<p/>
 *     &#9;<p/>
 *     &#9;if (value == cellmin)<p/>
 *     &#9;&#9;pack &amp;&amp; strpack(dest, cellmin_value, 12) || strunpack(dest, cellmin_value, 12);<p/>
 *     &#9;else<p/>
 *     &#9;&#9;format(dest, 12, "%d", value), pack &amp;&amp; strpack(dest, dest, 12);<p/>
 *     }<p/>
 *     #define valstr FIX_valstr
 *   </code>
 * </remarks>
 */
native valstr(dest[], value, bool:pack = false);

/**
 * <library>string</library>
 * <summary>Checks if the given string is packed.</summary>
 * <param name="string">The string to check</param>
 * <returns><b><c>true</c></b> if the string is packed, <b><c>false</c></b> if it's unpacked.</returns>
 */
native bool:ispacked(const string[]);

/**
 * <library>string</library>
 * <summary>Convert values to text.</summary>
 * <param name="dest">The string that will contain the formatted result.</param>
 * <param name="size">The maximum number of <em>cells</em> that the dest parameter can hold. This value includes the zero terminator.</param>
 * <param name="pack">If <c>true</c>, the string in <c>dest</c> will become a packed string. Otherwise, the string in dest will be unpacked.
 * </param>
 * <param name="format">The string to store in <c>dest</c>, which may contain placeholders (see the notes below).</param>
 * <param name="...">The parameters for the placeholders.  These values may be untagged, weakly tagged, or tagged as rational values.</param>
 * <remarks>
 * The format parameter is a string that may contain embedded placeholder codes:
 * <ul>
 * <li><c>%b</c> - store a number at this position in binary radix</li>
 * <li><c>%c</c> - store a character at this position</li>
 * <li><c>%d</c> - store a number at this position in decimal radix (same as <c>%i</c>)</li>
 * <li><c>%i</c> - store a number at this position in decimal radix (same as <c>%d</c>)</li>
 * <li><c>%f</c> - store a floating point number at this position</li>
 * <li><c>%s</c> - store a character string at this position</li>
 * <li><c>%x</c> - store a number at this position in hexadecimal radix</li>
 * <li><c>%q</c> - store a string with special characters escaped for SQLite</li>
 * <li><c>%%</c> - store a literal <c>%</c></li>
 * The values for the placeholders follow as parameters in the call.
 * <p/>
 * You may optionally put a number between the <c>"%"</c> and the letter of the placeholder code.
 * This number indicates the field width; if the size of the parameter to print at the position of
 * the placeholder is smaller than the field width, the field is expanded with spaces.  A negative
 * number left-aligns the text (right-pads).
 * <p/>
 * You may optionally put a <c>.</c> followed by a number between the <c>"%"</c> and the letter of
 * the placeholder code, after the optional width.  This number indicates the field precision; it
 * will truncate the output in some way.  For <c>%f</c> this is the number of decimal points to
 * show, for <c>%s</c> it is the number of characters to show.
 * <p/>
 * The <c>strformat</c> function works similarly to the "C" function sprintf.
 * </remarks>
 * <returns>This function always returns 0.</returns>
 */
#pragma deprecated Use `format`.
native strformat(dest[], size = sizeof (dest), bool:pack = true, const format[], {Fixed, Float, _}:...);

/**
 * <library>string</library>
 * <summary>Decode an UU-encoded stream.</summary>
 * <param name="dest">The array that will hold the decoded byte array.</param>
 * <param name="source">The UU-encoded source string</param>
 * <param name="maxlength">If the length of dest would exceed maxlength cells, the result is truncated
 * to maxlength cells.  Note that several bytes fit in each cell. (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <remarks>Since the UU-encoding scheme is used for binary data, the decoded data is always "packed".
 *  The data is unlikely to be a string (the zero-terminator may not be present, or it may be in the
 * middle of the data).</remarks>
 * <remarks>A buffer may be decoded "in-place"; the destination size is always smaller than the source
 * size.  Endian issues (for multi-byte values in the data stream) are not handled.</remarks>
 * <remarks>Binary data is encoded in chunks of <b><c>45</c></b> bytes.  To assemble these chunks into
 * a complete stream, function <a href="#memcpy">memcpy</a> allows you to concatenate buffers at byte-aligned
 * boundaries.</remarks>
 * <seealso name="memcpy"/>
 * <seealso name="uuencode"/>
 * <returns>The number of bytes decoded and stored in dest.</returns>
 */
native uudecode(dest[], const source[], maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>Encode an UU-encoded stream.</summary>
 * <param name="dest">The array that will hold the encoded string.</param>
 * <param name="source">The UU-encoded byte array.</param>
 * <param name="numbytes">The number of bytes (in the source array) to encode.  This should not exceed
 * <b><c>45</c></b>.</param>
 * <param name="maxlength">If the length of dest would exceed maxlength cells, the result is truncated
 * to maxlength cells.  Note that several bytes fit in each cell. (optional=<b><c>sizeof (dest)</c></b>)</param>
 * <seealso name="memcpy"/>
 * <seealso name="uudecode"/>
 * <remarks>This function always creates a packed string.  The string has a newline character at the
 * end.</remarks>
 * <remarks>Binary data is encoded in chunks of <b><c>45</c></b> bytes.  To extract <b><c>45</c></b>
 * bytes from an array with data, possibly from a byte-aligned address, you can use the function <a
 * href="#memcpy">memcpy</a>.</remarks>
 * <remarks>A buffer may be encoded "in-place" if the destination buffer is large enough.  Endian issues
 * (for multi-byte values in the data stream) are not handled.</remarks>
 * <returns>The number of characters encoded, excluding the zero string terminator; if the dest buffer
 * is too small, not all bytes are stored.</returns>
 */
native uuencode(dest[], const source[], numbytes, maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>Copy bytes from one location to another.</summary>
 * <param name="dest">An array into which the bytes from source are copied in</param>
 * <param name="source">The source array</param>
 * <param name="index">The start index in bytes in the destination array where the data should be copied
 * to (optional=<b><c>0</c></b>)</param>
 * <param name="numbytes">The number of bytes (not cells) to copy</param>
 * <param name="maxlength">The maximum number of cells that fit in the destination buffer (optional=<b><c>sizeof
 * (dest)</c></b>)</param>
 * <seealso name="strcmp"/>
 * <seealso name="strfind"/>
 * <seealso name="strtok"/>
 * <seealso name="strdel"/>
 * <seealso name="strins"/>
 * <seealso name="strlen"/>
 * <seealso name="strmid"/>
 * <seealso name="strpack"/>
 * <seealso name="strval"/>
 * <seealso name="strcat"/>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure.</returns>
 */
native bool:memcpy(dest[], const source[], index = 0, numbytes, maxlength = sizeof (dest));

/**
 * <library>string</library>
 * <summary>Compares two strings to see if they are the same.</summary>
 * <param name="string1">The first string to compare</param>
 * <param name="string2">The second string to compare</param>
 * <param name="ignorecase">When set to true, the case doesn't matter - HeLLo is the same as Hello.
 *  When false, they're not the same (optional=<b><c>0</c></b>)</param>
 * <param name="length">When this length is set, the first x chars will be compared - doing "Hello"
 * and "Hell No" with a length of 4 will say it's the same string (optional=<b><c>cellmax</c></b>)</param>
 * <seealso name="strcmp"/>
 * <remarks>This is a conveniece function that depends on <a href="#strcmp">strcmp</a>.</remarks>
 * <returns><b><c>true</c></b> if the strings match each other on given length, <b><c>false</c></b>
 * otherwise.</returns>
 */
/*
native bool:strequal(const string1[], const string2[], bool:ignorecase = false, length = cellmax);
*/
stock bool:strequal(const __string1[], const __string2[], bool:__ignorecase = false, __length = cellmax)
{
	if (__string1[0] == '\0')
	{
		// Only need to check the first character.
		return __string2[0] == '\0';
	}
	if (__string2[0] == '\0')
	{
		// Because we already know that `string1` isn't the same.
		return false;
	}
	return strcmp(__string1, __string2, __ignorecase, __length) == 0;
}
