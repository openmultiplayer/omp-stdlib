#if defined _console_included
	#endinput
#endif
#define _console_included

/**
 * <library name="console" summary="Console output.">
 *   <license>
 *     (c) Copyright 1998-2011, ITB CompuPhase
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

#pragma library Console

/**
 * <library>console</library>
 */
/* */ native __print(const string[]) = print;

/**
 * <library>console</library>
 * <summary>Prints a string to the server console (not in-game chat) and logs (server_log.txt).</summary>
 * <param name="string">The string to print</param>
 * <param name="foreground">The string to print</param>
 * <param name="background">Colour codes for the foreground and the background of the text string;
 * see function <c>setattr</c> for a list of colours.  When left at <c>-1</c>, the default colours
 * are used.  Note that a terminal or a host application may not support colours.</param>
 * <seealso name="printf"/>
 * <return>This function always returns 0.</return>
 */
/*
native print(const string[], foreground = -1, background = -1);
*/
stock print(const __string[], __foreground = -1, __background = -1)
{
	// Quote:
	//
	// > Note that a [...] host application may not support colours
	//
	// So we can just ignore them.
	#pragma unused __foreground, __background
	return __print(__string);
}

/**
 * <library>console</library>
 * <summary>Outputs a formatted string on the console (the server window, not the in-game chat).</summary>
 * <param name="format">The format string</param>
 * <param name="">Indefinite number of arguments of any tag</param>
 * <seealso name="print"/>
 * <seealso name="format"/>
 * <remarks>The format string or its output should not exceed 1024 characters.  Anything beyond that
 * length can lead to a server to crash.</remarks>
 * <remarks>This function doesn't support <a href="#strpack">packed</a> strings.</remarks>
 * <remarks>
 *   <b>Format Specifiers:</b><p/>
 *   <ul>
 *     <li><b><c>%i</c></b> - integer (whole number)</li>
 *     <li><b><c>%d</c></b> - integer (whole number).</li>
 *     <li><b><c>%s</c></b> - string</li>
 *     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
 *     <li><b><c>%c</c></b> - ASCII character</li>
 *     <li><b><c>%x</c></b> - hexadecimal number</li>
 *     <li><b><c>%b</c></b> - binary number</li>
 *     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
 *     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
 *   </ul>
 * </remarks>
 * <remarks>The values for the placeholders follow in the exact same order as parameters in the call.
 *  For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer
 * variable, which is the person's age.</remarks>
 * <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder
 * code.  This number indicates the field width; if the size of the parameter to print at the position
 * of the placeholder is smaller than the field width, the field is expanded with spaces.  To cut the
 * number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between
 * the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
 * <return>This function always returns 0.</return>
 */
native printf(const format[], {Float, _}:...);

/**
 * <library>console</library>
 * <summary>Clear the rest of the line.</summary>
 * <seealso name="clrscr"/>
 * <return>This function always returns 0.</return>
 * <remarks>Clears the line at which the cursor is, from the position of the cursor to the right
 * margin of the console.  This function does not move the cursor.</remarks>
 */
forward clreol();

/**
 * <library>console</library>
 * <summary>Clear the screen.</summary>
 * <seealso name="clreol"/>
 * <return>This function always returns 0.</return>
 * <remarks>Clears the display and moves the cursor to the upper left corner.</remarks>
 */
forward clrscr();

/**
 * <library>console</library>
 * <summary>Read one character.</summary>
 * <param name="echo">If <c>true</c>, the character read from the keyboard is echoed on the display.</param>
 * <seealso name="getstring"/>
 * <return>The numeric code for the character that is read (this is usually the ASCII code).</return>
 */
forward getchar(bool:echo = true);

/**
 * <library>console</library>
 * <summary>Read a line.</summary>
 * <param name="string"></param>
 * <param name="size"></param>
 * <param name="pack"></param>
 * <seealso name="getchar"/>
 * <return>The number of characters read, excluding the terminating null character.</return>
 * <remarks>Function <c>getstring</c> stops reading when either the enter key is typed or the
 * maximum length is reached.  The maximum length is in cells (not characters) and it includes a
 * terminating null character.  The function can read both packed and unpacked strings; when reading
 * a packed string, the function may read more characters than the size parameter specifies, since
 * each cell holds multiple characters.</remarks>
 */
forward getstring(string[], size = sizeof (string), bool:pack = false);

/**
 * <library>console</library>
 * <summary>Read a number.</summary>
 * <param name="base">Must be between 2 and 36, use 10 for decimal or 16 for hexadecimal.</param>
 * <param name="end">The character code that terminates the input.  More than one character may be listed.</param>
 * <param name="..."></param>
 * <seealso name="getstring"/>
 * <return>The value that is read.</return>
 * <remarks>Read a value (a signed number) from the keyboard.  The <c>getvalue</c> function allows
 * you to read in a numeric radix from 2 to 36 (the base parameter) with decimal radix by default.
 * By default the input ends when the user types the enter key, but one or more different keys may
 * be selected (the end parameter and subsequent). In the list of terminating keys, a positive
 * number (like <c>'\r'</c>) displays the key and terminates input, and a negative number terminates
 * input without displaying the terminating key.</remarks>
 */
forward getvalue(base = 10, end = '\r', ...);

/**
 * <library>console</library>
 * <summary>Set cursor location.</summary>
 * <param name="x"></param>
 * <param name="y">The new cursor position.</param>
 * <seealso name="clrscr"/>
 * <return><c>true</c> if the cursor moved and <c>false</c> if the requested position is invalid.</return>
 * <remarks>Sets the cursor position on the console.  The upper left corner is at <c>(1,1)</c>.</remarks>
 */
forward bool:gotoxy(x = 1, y = 1);

/**
 * <library>console</library>
 * <summary>Set text colours.</summary>
 * <param name="foreground">The string to print</param>
 * <param name="background">Colour codes for the foreground and the background of the text string;
 * see function <c>setattr</c> for a list of colours.  When left at <c>-1</c>, the default colours
 * are used.  Note that a terminal or a host application may not support colours</param>
 * <seealso name="clrscr"/>
 * <return>This function always returns 0.</return>
 * <remarks>On most systems, the colour value must be a value between zero and seven, as per the
 * ANSI escape sequences, ISO 6429.  Predefined constants for the colours are <c>black (0)</c>,
 * <c>red (1)</c>, <c>green (2)</c>, <c>yellow (3)</c>, <c>blue (4)</c>, <c>magenta (5)</c>,
 * <c>cyan (6)</c>, and <c>white (7)</c>.</remarks>
 */
forward setattr(foreground = -1, background = -1);
