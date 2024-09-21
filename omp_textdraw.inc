#if defined _INC_omp_textdraw
	#endinput
#endif
#define _INC_omp_textdraw

/**
 * <library name="omp_textdraw" summary="open.mp text draw functions.">
 *   <license>
 *     This Source Code Form is subject to the terms of the Mozilla Public License,
 *     v. 2.0. If a copy of the MPL was not distributed with this file, You can
 *     obtain one at http://mozilla.org/MPL/2.0/.
 *
 *     The original code is copyright (c) 2023, open.mp team and contributors.
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

#pragma tabsize 4

/**
 * <library>omp_textdraw</library>
 */
#if defined MAX_TEXT_DRAWS
	#if MAX_TEXT_DRAWS < Text:1 || MAX_TEXT_DRAWS > Text:2048
		#error MAX_TEXT_DRAWS must be >= 1 and <= 2048
	#endif

	const Text:__MAX_TEXT_DRAWS                = MAX_TEXT_DRAWS;
	#define __MAX_TEXT_DRAWS
#else
	const Text:MAX_TEXT_DRAWS                  = Text:2048;
	#define MAX_TEXT_DRAWS                     (Text:2048)
#endif

/**
 * <library>omp_textdraw</library>
 */
const Text:INVALID_TEXT_DRAW                   = Text:0xFFFF;
#define INVALID_TEXT_DRAW                      (Text:65535)

/**
 * <library>omp_textdraw</library>
 */
#if defined MAX_PLAYER_TEXT_DRAWS
	#if MAX_PLAYER_TEXT_DRAWS < PlayerText:1 || MAX_PLAYER_TEXT_DRAWS > PlayerText:256
		#error MAX_PLAYER_TEXT_DRAWS must be >= 1 and <= 256
	#endif

	const PlayerText:__MAX_PLAYER_TEXT_DRAWS   = MAX_PLAYER_TEXT_DRAWS;
	#define __MAX_PLAYER_TEXT_DRAWS
#else
	const PlayerText:MAX_PLAYER_TEXT_DRAWS     = PlayerText:256;
	#define MAX_PLAYER_TEXT_DRAWS              (PlayerText:256)
#endif

/**
 * <library>omp_textdraw</library>
 */
const PlayerText:INVALID_PLAYER_TEXT_DRAW      = PlayerText:0xFFFF;
#define INVALID_PLAYER_TEXT_DRAW               (PlayerText:65535)

/// <p/>
/**
 * <library>omp_textdraw</library>
 * <summary>Text draw font</summary>
 */
#define TEXT_DRAW_FONT: __TAG(TEXT_DRAW_FONT):
enum TEXT_DRAW_FONT:__TEXT_DRAW_FONT
{
	UNKNOWN_TEXT_DRAW_FONT                     = -1,
	// Numbers.
	TEXT_DRAW_FONT_0,
	TEXT_DRAW_FONT_1,
	TEXT_DRAW_FONT_2,
	TEXT_DRAW_FONT_3,
	TEXT_DRAW_FONT_SPRITE_DRAW,
	TEXT_DRAW_FONT_MODEL_PREVIEW,
	// From GTA.
	TEXT_DRAW_FONT_BANK = 0,
	TEXT_DRAW_FONT_STANDARD,
	TEXT_DRAW_FONT_SPACEAGE,
	TEXT_DRAW_FONT_HEADING,
	// From open.mp.
	TEXT_DRAW_FONT_BECKETT_REGULAR             = 0,
	TEXT_DRAW_FONT_AHARONI_BOLD,
	TEXT_DRAW_FONT_BANK_GOTHIC,
	TEXT_DRAW_FONT_PRICEDOWN,
	TEXT_DRAW_FONT_SPRITE,
	TEXT_DRAW_FONT_PREVIEW
}
static stock TEXT_DRAW_FONT:_@TEXT_DRAW_FONT() { return __TEXT_DRAW_FONT; }

#define UNKNOWN_TEXT_DRAW_FONT                 (TEXT_DRAW_FONT:-1)

// Numbers.
#define TEXT_DRAW_FONT_0                       (TEXT_DRAW_FONT:0)
#define TEXT_DRAW_FONT_1                       (TEXT_DRAW_FONT:1)
#define TEXT_DRAW_FONT_2                       (TEXT_DRAW_FONT:2)
#define TEXT_DRAW_FONT_3                       (TEXT_DRAW_FONT:3)
#define TEXT_DRAW_FONT_SPRITE_DRAW             (TEXT_DRAW_FONT:4)
#define TEXT_DRAW_FONT_MODEL_PREVIEW           (TEXT_DRAW_FONT:5)

// From GTA.
#define TEXT_DRAW_FONT_BANK                    (TEXT_DRAW_FONT:0)
#define TEXT_DRAW_FONT_STANDARD                (TEXT_DRAW_FONT:1)
#define TEXT_DRAW_FONT_SPACEAGE                (TEXT_DRAW_FONT:2)
#define TEXT_DRAW_FONT_HEADING                 (TEXT_DRAW_FONT:3)

// From open.mp.
#define TEXT_DRAW_FONT_BECKETT_REGULAR         (TEXT_DRAW_FONT:0)
#define TEXT_DRAW_FONT_AHARONI_BOLD            (TEXT_DRAW_FONT:1)
#define TEXT_DRAW_FONT_BANK_GOTHIC             (TEXT_DRAW_FONT:2)
#define TEXT_DRAW_FONT_PRICEDOWN               (TEXT_DRAW_FONT:3)
#define TEXT_DRAW_FONT_SPRITE                  (TEXT_DRAW_FONT:4)
#define TEXT_DRAW_FONT_PREVIEW                 (TEXT_DRAW_FONT:5)

/// <p/>
/**
 * <library>omp_textdraw</library>
 * <summary>Text draw alignment</summary>
 */
#define TEXT_DRAW_ALIGN: __TAG(TEXT_DRAW_ALIGN):
enum TEXT_DRAW_ALIGN:__TEXT_DRAW_ALIGN
{
	UNKNOWN_TEXT_DRAW_ALIGN                    = -1,
	TEXT_DRAW_ALIGN_LEFT                       = 1,
	TEXT_DRAW_ALIGN_CENTRE,
	TEXT_DRAW_ALIGN_CENTER = TEXT_DRAW_ALIGN_CENTRE,
	TEXT_DRAW_ALIGN_RIGHT
}
static stock TEXT_DRAW_ALIGN:_@TEXT_DRAW_ALIGN() { return __TEXT_DRAW_ALIGN; }

#define UNKNOWN_TEXT_DRAW_ALIGN                (TEXT_DRAW_ALIGN:-1)
#define TEXT_DRAW_ALIGN_LEFT                   (TEXT_DRAW_ALIGN:1)
#define TEXT_DRAW_ALIGN_CENTRE                 (TEXT_DRAW_ALIGN:2)
#define TEXT_DRAW_ALIGN_CENTER                 (TEXT_DRAW_ALIGN:2)
#define TEXT_DRAW_ALIGN_RIGHT                  (TEXT_DRAW_ALIGN:3)

/*
                                                                           
    888b      88                       88                                      
    8888b     88                ,d     ""                                      
    88 `8b    88                88                                             
    88  `8b   88  ,adPPYYba,  MM88MMM  88  8b       d8   ,adPPYba,  ,adPPYba,  
    88   `8b  88  ""     `Y8    88     88  `8b     d8'  a8P_____88  I8[    ""  
    88    `8b 88  ,adPPPPP88    88     88   `8b   d8'   8PP"""""""   `"Y8ba,   
    88     `8888  88,    ,88    88,    88    `8b,d8'    "8b,   ,aa  aa    ]8I  
    88      `888  `"8bbdP"Y8    "Y888  88      "8"       `"Ybbd8"'  `"YbbdP"'  
                                                                           
                                                                           

*/

/*
native # Global();
native              Global(
native      ====================(
native
*/

/**
 * <library>omp_textdraw</library>
 * <summary>Creates a textdraw.  Textdraws are, as the name implies, text (mainly - there can be boxes,
 * sprites and model previews (skins/vehicles/weapons/objects too) that is drawn on a player's screens.</summary>
 * <param name="x">The x (left/right) coordinate to create the textdraw at</param>
 * <param name="y">The y (up/down) coordinate to create the textdraw at</param>
 * <param name="format">The text that will appear in the textdraw.  May be optionally formatted.</param>
 * <remarks>
 *   If you choose values for y that are less than 1, the first text row will be invisible and only
 * the shadow is visible.<br />
 *   If part of the text is off-screen, the colour of the text will not show, only the shadow (if enabled)
 * will.
 * </remarks>
 * <remarks>
 *   Maximum length of textdraw is <b>800</b> characters.  Longer text will crash the legacy (SA:MP) client in older
 * versions.<br />
 *   If you use colour codes (such as <b><c>~R~ ~G~</c></b>) beyond 255th character the legacy (SA:MP) client will
 * crash trying to display the textdraw.
 * </remarks>
 * <remarks>
 *   The x, y coordinate is the top left coordinate for the text draw area based on a 640x480 "canvas"
 * (irrespective of screen resolution).  If you plan on using <a href="#TextDrawAlignment">TextDrawAlignment</a>
 * with alignment <b><c>3</c></b> (right), the x, y coordinate is the top right coordinate for the text
 * draw.<br />
 *   This function merely CREATES the textdraw, you must use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>
 * or <a href="#TextDrawShowForAll">TextDrawShowForAll</a> to show it.<br />
 *   It is recommended to use WHOLE numbers instead of decimal positions when creating textdraws to
 * ensure resolution friendly design.
 * </remarks>
 * <remarks>Keyboard key mapping codes (such as <b><c>~k~~VEHICLE_ENTER_EXIT~</c></b> don't work beyond
 * 255th character. </remarks>
 * <returns>The ID of the created textdraw.  Textdraw IDs start at <b><c>0</c></b>.</returns>
 */
native Text:TextDrawCreate(Float:x, Float:y, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_textdraw</library>
 * <summary>Destroys a previously-created textdraw.</summary>
 * <param name="textid">The ID of the textdraw to destroy.  Returned by <a href="#TextDrawCreate">TextDrawCreate</a></param>
 */
native bool:TextDrawDestroy(Text:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the width and height of the letters.</summary>
 * <param name="textid">The TextDraw to change</param>
 * <param name="width">Width of a char</param>
 * <param name="height">Height of a char</param>
 * <remarks>When using this function purely for the benefit of affecting the TextDraw box, multiply
 * 'y' by <b><c>0.135</c></b> to convert to <a href="#TextDrawTextSize">TextDrawTextSize</a>-like measurements.
 * <b>Hint</b>: it is easier and extremely precise to use <b><c>LD_SPAC:white</c></b> sprite for box-only
 * textdraws, <a href="#TextDrawTextSize">TextDrawTextSize</a> will have regular offsets.</remarks>
 * <remarks>If you want to change the letter size of a textdraw that is already shown, you don't have
 * to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible. </remarks>
 * <remarks>Fonts appear to look the best with an x to y ratio of <b><c>1</c></b> to <b><c>4</c></b>
 * (e.g.  if x is <b><c>0.5</c></b> then y should be <b><c>2</c></b>). </remarks>
 */
native bool:TextDrawLetterSize(Text:textid, Float:width, Float:height);

/**
 * <library>omp_textdraw</library>
 * <summary>Change the size of a textdraw (box if <a href="#TextDrawUseBox">TextDrawUseBox</a> is enabled
 * and/or clickable area for use with <a href="#TextDrawSetSelectable">TextDrawSetSelectable</a>).</summary>
 * <param name="textid">The TextDraw to set the size of</param>
 * <param name="width">The size on the x axis (left/right) following the same 640x480 grid as
 * <a href="#TextDrawCreate">TextDrawCreate</a></param>
 * <param name="height">The size on the y axis (up/down) following the same 640x480 grid as
 * <a href="#TextDrawCreate">TextDrawCreate</a></param>
 * <remarks>
 *   The x and y have different meanings with different TextDrawAlignment values:<br />
 *   <ul>
 *     <li><b><c>1</c></b> (left): they are the right-most corner of the box, absolute coordinates.</li>
 *     <li><b><c>2</c></b> (center): they need to inverted (switch the two) and the x value is the overall
 * width of the box.</li>
 *     <li><b><c>3</c></b> (right): the x and y are the coordinates of the left-most corner of the box
 * </li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   Using font type <b><c>4</c></b> (sprite) and <b><c>5</c></b> (model preview) converts x and y of
 * this function from corner coordinates to WIDTH and HEIGHT (offsets).<br />
 *   The TextDraw box starts <b><c>10.0</c></b> units up and <b><c>5.0</c></b> to the left as the origin
 * (<a href="#TextDrawCreate">TextDrawCreate</a> coordinate).<br />
 *   This function defines the clickable area for use with <a href="#TextDrawSetSelectable">TextDrawSetSelectable</a>,
 * whether a box is shown or not.
 * </remarks>
 * <remarks>If you want to change the text size of a textdraw that is already shown, you don't have
 * to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
native bool:TextDrawTextSize(Text:textid, Float:width, Float:height);

/**
 * <library>omp_textdraw</library>
 * <summary>Set the alignment of text in a text draw.</summary>
 * <param name="textid">The ID of the textdraw to set the alignment of</param>
 * <param name="alignment"><b><c>1</c></b>-left <b><c>2</c></b>-centered <b><c>3</c></b>-right</param>
 * <remarks>For alignment <b><c>2</c></b> (center) the x and y values of <a href="#TextSize">TextSize</a>
 * need to be swapped, see notes at <a href="#TextDrawTextSize">TextDrawTextSize</a>, also position
 * coordinate become position of center of textdraw and not left/top edges. </remarks>
 */
native bool:TextDrawAlignment(Text:textid, TEXT_DRAW_ALIGN:alignment);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the text colour of a textdraw.</summary>
 * <param name="textid">The ID of the textdraw to change the colour of.</param>
 * <param name="textColour">The colour to set the textdraw to</param>
 * <remarks>You can also use GameText colours in TextDraws.</remarks>
 * <remarks>If the TextDraw is already shown, it must be re-shown (<a href="#TextDrawShowForAll">TextDrawShowForAll</a>/<a
 * href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>) for the changes of this function to take
 * effect.</remarks>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `TextDrawColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:TextDrawColor(Text:textid, textColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the text colour of a textdraw.</summary>
 * <param name="textid">The ID of the textdraw to change the colour of.</param>
 * <param name="textColour">The colour to set the textdraw to</param>
 * <remarks>You can also use GameText colours in TextDraws.</remarks>
 * <remarks>If the TextDraw is already shown, it must be re-shown (<a href="#TextDrawShowForAll">TextDrawShowForAll</a>/<a
 * href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>) for the changes of this function to take
 * effect.</remarks>
 */
native bool:TextDrawColour(Text:textid, textColour) = TextDrawColor;

/**
 * <library>omp_textdraw</library>
 * <summary>Toggle whether a textdraw uses a box or not.</summary>
 * <param name="textid">The ID of the text textdraw to toggle the box of</param>
 * <param name="enableBox"><b><c>1</c></b> to show a box or <b><c>0</c></b> to not show a box</param>
 * <remarks>If the textdraw is already shown, it must be re-shown (<a href="#TextDrawShowForAll">TextDrawShowForAll</a>/<a
 * href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>) to show the changes of this function.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the textdraw specified does not exist.
 * </returns>
 */
native bool:TextDrawUseBox(Text:textid, bool:enableBox);

/**
 * <library>omp_textdraw</library>
 * <summary>Adjusts the text box colour (only used if <a href="#TextDrawUseBox">TextDrawUseBox</a> 'use'
 * parameter is <b><c>1</c></b>).</summary>
 * <param name="textid">The TextDraw to change</param>
 * <param name="boxColour">The colour (<b>RGBA</b>)</param>
 * <remarks>If you want to change the boxcolour of a textdraw that is already shown, you don't have
 * to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `TextDrawBoxColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:TextDrawBoxColor(Text:textid, boxColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Adjusts the text box colour (only used if <a href="#TextDrawUseBox">TextDrawUseBox</a> 'use'
 * parameter is <b><c>1</c></b>).</summary>
 * <param name="textid">The TextDraw to change</param>
 * <param name="boxColour">The colour (<b>RGBA</b>)</param>
 * <remarks>If you want to change the boxcolour of a textdraw that is already shown, you don't have
 * to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
native bool:TextDrawBoxColour(Text:textid, boxColour) = TextDrawBoxColor;

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the size of a textdraw's text's shadow.</summary>
 * <param name="textid">The ID of the textdraw to set the shadow size of</param>
 * <param name="shadowSize">The size of the shadow. <b><c>1</c></b> is generally used for a normal shadow
 * size. <b><c>0</c></b> disables the shadow completely</param>
 * <remarks>The shadow can be cut by the box area if the size is set too big for the area.</remarks>
 * <remarks>If you want to change the shadow of a textdraw that is already shown, you don't have to
 * recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/<a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The textdraw does not exist.
 * </returns>
 */
native bool:TextDrawSetShadow(Text:textid, shadowSize);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the thickness of a textdraw's text's outline. <a href="#TextDrawBackgroundColor">TextDrawBackgroundColor</a>
 * can be used to change the colour.</summary>
 * <param name="textid">The ID of the text draw to set the outline thickness of</param>
 * <param name="outlineSize">The thickness of the outline, as an integer. <b><c>0</c></b> for no outline</param>
 * <remarks>If you want to change the outline of a textdraw that is already shown, you don't have to
 * recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/<a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
native bool:TextDrawSetOutline(Text:textid, outlineSize);

/**
 * <library>omp_textdraw</library>
 * <summary>Adjusts the text draw area background colour (the outline/shadow - NOT the box.  For box
 * colour, see <a href="#TextDrawBoxColor">TextDrawBoxColor</a>).</summary>
 * <param name="textid">The ID of the textdraw to set the background colour of</param>
 * <param name="backgroundColour">The colour that the textdraw should be set to</param>
 * <remarks>If <a href="#TextDrawSetOutline">TextDrawSetOutline</a> is used with size &gt; <b><c>0</c></b>,
 * the outline colour will match the colour used in <a href="#TextDrawBackgroundColor">TextDrawBackgroundColor</a>.
 *  Changing the value of colour seems to alter the colour used in <a href="#TextDrawColor">TextDrawColor</a></remarks>
 * <remarks>If you want to change the background colour of a textdraw that is already shown, you don't
 * have to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `TextDrawBackgroundColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:TextDrawBackgroundColor(Text:textid, backgroundColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Adjusts the text draw area background colour (the outline/shadow - NOT the box.  For box
 * colour, see <a href="#TextDrawBoxColour">TextDrawBoxColour</a>).</summary>
 * <param name="textid">The ID of the textdraw to set the background colour of</param>
 * <param name="backgroundColour">The colour that the textdraw should be set to</param>
 * <remarks>If <a href="#TextDrawSetOutline">TextDrawSetOutline</a> is used with size &gt; <b><c>0</c></b>,
 * the outline colour will match the colour used in <a href="#TextDrawBackgroundColour">TextDrawBackgroundColour</a>.
 *  Changing the value of colour seems to alter the colour used in <a href="#TextDrawColour">TextDrawColour</a></remarks>
 * <remarks>If you want to change the background colour of a textdraw that is already shown, you don't
 * have to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
native bool:TextDrawBackgroundColour(Text:textid, backgroundColour) = TextDrawBackgroundColor;

/**
 * <library>omp_textdraw</library>
 * <summary>Changes the text font.</summary>
 * <param name="textid">The TextDraw to change</param>
 * <param name="font">There are four font styles, see
 * <a href="https://open.mp/docs/scripting/functions/TextDrawFont">https://open.mp/docs/scripting/functions/TextDrawFont</a>.
 *  Font value <b><c>4</c></b> specifies that this is a txd sprite; <b><c>5</c></b> specifies that this
 * textdraw can display preview models.  A font value greater than 5 does not display, and anything
 * greater than 16 crashes the client</param>
 * <remarks>If you want to change the font of a textdraw that is already shown, you don't have to recreate
 * it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/<a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible.</remarks>
 */
native bool:TextDrawFont(Text:textid, TEXT_DRAW_FONT:font);

/**
 * <library>omp_textdraw</library>
 * <summary>Appears to scale text spacing to a proportional ratio.  Useful when using <a href="#TextDrawLetterSize">TextDrawLetterSize</a>
 * to ensure the text has even character spacing.</summary>
 * <param name="textid">The ID of the textdraw to set the proportionality of</param>
 * <param name="proportional"><b><c>1</c></b> to enable proportionality, <b><c>0</c></b> to disable</param>
 * <remarks>Proportionality is set to <b><c>1</c></b> by default, you might skip this function if you
 * don't want to disable it. </remarks>
 * <remarks>If you want to change the proportionality of a textdraw that is already shown, you don't
 * have to recreate it.  Simply use <a href="#TextDrawShowForPlayer">TextDrawShowForPlayer</a>/
 * <a href="#TextDrawShowForAll">TextDrawShowForAll</a>
 * after modifying the textdraw and the change will be visible. </remarks>
 */
native bool:TextDrawSetProportional(Text:textid, bool:proportional);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets whether a textdraw can be selected (clicked on) or not.</summary>
 * <param name="textid">The ID of the textdraw to make selectable</param>
 * <param name="selectable"><b><c>1</c></b> to make it selectable, or <b><c>0</c></b> to make it not selectable</param>
 * <remarks><a href="#TextDrawSetSelectable">TextDrawSetSelectable</a> must be used BEFORE the textdraw
 * is shown to players for it to be selectable.</remarks>
 * <remarks>Use <a href="#TextDrawTextSize">TextDrawTextSize</a> to define the clickable area.</remarks>
 */
native bool:TextDrawSetSelectable(Text:textid, bool:selectable);

/**
 * <library>omp_textdraw</library>
 * <summary>Shows a textdraw for a specific player.</summary>
 * <param name="playerid">The ID of the player to show the textdraw for</param>
 * <param name="textid">The ID of the textdraw to show.  Returned by <a href="#TextDrawCreate">TextDrawCreate</a></param>
 * <remarks>If only a single player will see a textdraw, it might be wise to use player-textdraws instead.
 *  This is also useful for textdraws that need to show information specific for an individual player.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means either the player and/or textdraw
 * specified does not exist.
 * </returns>
 */
native bool:TextDrawShowForPlayer(playerid, Text:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Hides a textdraw for a specific player.</summary>
 * <param name="playerid">The ID of the player that the textdraw should be hidden for</param>
 * <param name="textid">The ID of the textdraw to hide</param>
 * <seealso name="TextDrawHideForAll" />
 * <seealso name="TextDrawShowForPlayer" />
 * <seealso name="TextDrawShowForAll" />
 */
native bool:TextDrawHideForPlayer(playerid, Text:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Shows a textdraw for all players.</summary>
 * <param name="textid">The ID of the textdraw to show.  Returned by <a href="#TextDrawCreate">TextDrawCreate</a></param>
 * <seealso name="TextDrawShowForPlayer" />
 * <seealso name="TextDrawHideForPlayer" />
 * <seealso name="TextDrawHideForAll" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the textdraw specified does not exist.
 * </returns>
 */
native bool:TextDrawShowForAll(Text:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Hides a text draw for all players.</summary>
 * <param name="textid">The ID of the textdraw to hide (returned by <a href="#TextDrawCreate">TextDrawCreate</a>)</param>
 * <seealso name="TextDrawShowForPlayer" />
 * <seealso name="TextDrawHideForPlayer" />
 * <seealso name="TextDrawShowForAll" />
 */
native bool:TextDrawHideForAll(Text:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Changes the text on a textdraw.</summary>
 * <param name="textid">The TextDraw to change</param>
 * <param name="format">The new string for the TextDraw.  May be optionally formatted.</param>
 * <remarks>There are limits to the length of textdraw strings - see <a href="https://open.mp/docs/scripting/resources/limits">here</a>
 * for more info.</remarks>
 */
native bool:TextDrawSetString(Text:textid, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_textdraw</library>
 * <summary>Set the model for a textdraw model preview.</summary>
 * <param name="textid">The textdraw ID that will display the 3D preview</param>
 * <param name="model">The GTA SA or SA:MP model ID to display</param>
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order
 * for this function to have effect.</remarks>
 * <remarks>Use <a href="#TextDrawBackgroundColor">TextDrawBackgroundColor</a> to set the background
 * colour behind the model.</remarks>
 */
native bool:TextDrawSetPreviewModel(Text:textid, model);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the rotation and zoom of a 3D model preview textdraw.</summary>
 * <param name="rotationX">The x rotation value</param>
 * <param name="rotationY">The y rotation value</param>
 * <param name="rotationZ">The z rotation value</param>
 * <param name="zoom">The zoom value, smaller values make the camera closer and larger values make the
 * camera further away (optional=<b><c>1.0</c></b>)</param>
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order
 * for this function to have effect.</remarks>
 */
native bool:TextDrawSetPreviewRot(Text:textid, Float:rotationX, Float:rotationY, Float:rotationZ, Float:zoom = 1.0);

/**
 * <library>omp_textdraw</library>
 * <summary>If a vehicle model is used in a 3D preview textdraw, this sets the two colour values for
 * that vehicle.</summary>
 * <param name="textid">The textdraw ID that is set to display a 3D vehicle model preview</param>
 * <param name="colour1">The primary colour ID to set the vehicle to</param>
 * <param name="colour2">The secondary colour ID to set the vehicle to</param>
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order
 * for this function to have effect.</remarks>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `TextDrawSetPreviewVehicleColours`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:TextDrawSetPreviewVehCol(Text:textid, colour1, colour2);

/**
 * <library>omp_textdraw</library>
 * <summary>If a vehicle model is used in a 3D preview textdraw, this sets the two colour values for
 * that vehicle.</summary>
 * <param name="textid">The textdraw ID that is set to display a 3D vehicle model preview</param>
 * <param name="colour1">The primary Colour ID to set the vehicle to</param>
 * <param name="colour2">The secondary Colour ID to set the vehicle to</param>
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order
 * for this function to have effect.</remarks>
 */
#if __namemax > 31
	native bool:TextDrawSetPreviewVehicleColours(Text:textid, colour1, colour2) = TextDrawSetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 * <summary>If a vehicle model is used in a 3D preview textdraw, this sets the two colour values for
 * that vehicle.</summary>
 * <param name="textid">The textdraw ID that is set to display a 3D vehicle model preview</param>
 * <param name="colour1">The primary Colour ID to set the vehicle to</param>
 * <param name="colour2">The secondary Colour ID to set the vehicle to</param>
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order
 * for this function to have effect.</remarks>
 */
#if __namemax > 31
	#if !defined MIXED_SPELLINGS
		#pragma deprecated Use `TextDrawSetPreviewVehicleColours`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
	native bool:TextDrawSetPreviewVehicleColors(Text:textid, colour1, colour2) = TextDrawSetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
native bool:IsValidTextDraw(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:IsTextDrawVisibleForPlayer(playerid, Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawGetString(Text:textid, string[], stringSize = sizeof (string));

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawSetPos(Text:textid, Float:x, Float:y);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawGetLetterSize(Text:textid, &Float:width, &Float:height);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawGetTextSize(Text:textid, &Float:width, &Float:height);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawGetPos(Text:textid, &Float:x, &Float:y);

/**
 * <library>omp_textdraw</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `TextDrawGetColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native TextDrawGetColor(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TextDrawGetColour(Text:textid) = TextDrawGetColor;

/**
 * <library>omp_textdraw</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `TextDrawGetBoxColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native TextDrawGetBoxColor(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TextDrawGetBoxColour(Text:textid) = TextDrawGetBoxColor;

/**
 * <library>omp_textdraw</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `TextDrawGetBackgroundColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native TextDrawGetBackgroundColor(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TextDrawGetBackgroundColour(Text:textid) = TextDrawGetBackgroundColor;

/**
 * <library>omp_textdraw</library>
 */
native TextDrawGetShadow(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TextDrawGetOutline(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TEXT_DRAW_FONT:TextDrawGetFont(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawIsBox(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawIsProportional(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawIsSelectable(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TEXT_DRAW_ALIGN:TextDrawGetAlignment(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native TextDrawGetPreviewModel(Text:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawGetPreviewRot(Text:textid, &Float:rotationX, &Float:rotationY, &Float:rotationZ, &Float:zoom);

/**
 * <library>omp_textdraw</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `TextDrawGetPreviewVehicleColours`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:TextDrawGetPreviewVehCol(Text:textid, &colour1, &colour2);

/**
 * <library>omp_textdraw</library>
 */
#if __namemax > 31
	native bool:TextDrawGetPreviewVehicleColours(Text:textid, &colour1, &colour2) = TextDrawGetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
#if __namemax > 31
	#if !defined MIXED_SPELLINGS
		#pragma deprecated Use `TextDrawGetPreviewVehicleColours`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
	native bool:TextDrawGetPreviewVehicleColors(Text:textid, &colour1, &colour2) = TextDrawGetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
native bool:TextDrawSetStringForPlayer(Text:textid, playerid, const format[], OPEN_MP_TAGS:...);

/*
native # Per-Player();
native           Per-Player(
native      ====================(
native
*/

/**
 * <library>omp_textdraw</library>
 * <summary>Creates a textdraw for a single player.  This can be used as a way around the <a href="#TextDrawCreate">global</a>
 * text-draw limit.</summary>
 * <param name="playerid">The ID of the player to create the textdraw for</param>
 * <param name="x">x-Coordinate</param>
 * <param name="y">y-Coordinate</param>
 * <param name="format">The text in the textdraw.  May be optionally formatted.</param>
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>
 *   If you choose values for y that are less than 1, the first text row will be invisible and only
 * the shadow is visible.<br />
 *   If part of the text is off-screen, the colour of the text will not show, only the shadow (if enabled)
 * will. <br />
 * </remarks>
 * <remarks>
 *   Maximum length of textdraw is <b><c>800</c></b> characters.<br />
 *   If you use colour codes (such as <b><c>~R~ ~G~</c></b>) beyond 255th character the legacy (SA:MP) client will
 * crash trying to display the textdraw. <br />
 * </remarks>
 * <remarks>Keyboard key mapping codes (such as <b><c>~k~~VEHICLE_ENTER_EXIT~</c></b> Doesn't work beyond
 * 255th character. </remarks>
 * <remarks>
 *   The x, y coordinate is the top left coordinate for the text draw area based on a <b><c>640x480</c></b>
 * "canvas" (irrespective of screen resolution).  If you plan on using <a href="#PlayerTextDrawAlignment">PlayerTextDrawAlignment</a>
 * with alignment <b><c>3</c></b> (right), the x, y coordinate is the top right coordinate for the text
 * draw.<br />
 *   This function merely CREATES the textdraw, you must use <a href="#PlayerTextDrawShow">PlayerTextDrawShow</a>
 * to show it to a player.<br />
 *   It is recommended to use WHOLE numbers instead of decimal positions when creating player textdraws
 * to ensure resolution friendly design. <br />
 * </remarks>
 * <remarks>Player-textdraws are automatically destroyed when a player disconnects.</remarks>
 * <returns>The ID of the created textdraw.</returns>
 */
native PlayerText:CreatePlayerTextDraw(playerid, Float:x, Float:y, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_textdraw</library>
 * <summary>Destroy a player-textdraw.</summary>
 * <param name="playerid">The ID of the player who's player-textdraw to destroy</param>
 * <param name="textid">The ID of the textdraw to destroy</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
native bool:PlayerTextDrawDestroy(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the width and height of the letters in a player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the letter size of</param>
 * <param name="textid">The ID of the player-textdraw to change the letter size of</param>
 * <param name="width">Width of a char</param>
 * <param name="height">Height of a char</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>When using this function purely for the benefit of affecting the textdraw box, multiply
 * 'y' by <b><c>0.135</c></b> to convert to <a href="#TextDrawTextSize">TextDrawTextSize</a>-like measurements</remarks>
 * <remarks>Fonts appear to look the best with an x to y ratio of <b><c>1</c></b> to <b><c>4</c></b>
 * (e.g.  if x is <b><c>0.5</c></b> then y should be <b><c>2</c></b>).</remarks>
 */
native bool:PlayerTextDrawLetterSize(playerid, PlayerText:textid, Float:width, Float:height);

/**
 * <library>omp_textdraw</library>
 * <summary>Change the size of a player-textdraw (box if <a href="#PlayerTextDrawUseBox">PlayerTextDrawUseBox</a>
 * is enabled and/or clickable area for use with <a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a>).</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the size of</param>
 * <param name="textid">The ID of the player-textdraw to set the size of</param>
 * <param name="width">The size on the x axis (left/right) following the same 640x480 grid as
 * <a href="#TextDrawCreate">TextDrawCreate</a></param>
 * <param name="height">The size on the y axis (up/down) following the same 640x480 grid as
 * <a href="#TextDrawCreate">TextDrawCreate</a></param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>
 *   The x and y have different meanings with different PlayerTextDrawAlignment values:<br />
 *   <ul>
 *     <li><b><c>1</c></b> (left): they are the right-most corner of the box, absolute coordinates.</li>
 *     <li><b><c>2</c></b> (center): they need to inverted (switch the two) and the x value is the overall
 * width of the box.</li>
 *     <li><b><c>3</c></b> (right): the x and y are the coordinates of the left-most corner of the box
 * </li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   Using font type <b><c>4</c></b> (sprite) and <b><c>5</c></b> (model preview) converts x and y of
 * this function from corner coordinates to WIDTH and HEIGHT (offsets).<br />
 *   The TextDraw box starts <b><c>10.0</c></b> units up and <b><c>5.0</c></b> to the left as the origin
 * (<a href="#TextDrawCreate">TextDrawCreate</a> coordinate).<br />
 *   This function defines the clickable area for use with <a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a>,
 * whether a box is shown or not.
 * </remarks>
 */
native bool:PlayerTextDrawTextSize(playerid, PlayerText:textid, Float:width, Float:height);

/**
 * <library>omp_textdraw</library>
 * <summary>Set the text alignment of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the alignment of</param>
 * <param name="textid">The ID of the player-textdraw to set the alignment of</param>
 * <param name="alignment"><b><c>1</c></b>-left <b><c>2</c></b>-centered <b><c>3</c></b>-right</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>For alignment <b><c>2</c></b> (center) the x and y values of TextSize need to be swapped,
 * see notes at <a href="#PlayerTextDrawTextSize">PlayerTextDrawTextSize</a>. </remarks>
 */
native bool:PlayerTextDrawAlignment(playerid, PlayerText:textid, TEXT_DRAW_ALIGN:alignment);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the text colour of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player who's textdraw to set the colour of</param>
 * <param name="textid">The TextDraw to change</param>
 * <param name="textColour">The colour in hexadecimal format</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>You can also use Gametext colours in textdraws.</remarks>
 * <remarks>The textdraw must be re-shown to the player in order to update the colour.</remarks>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerTextDrawColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:PlayerTextDrawColor(playerid, PlayerText:textid, textColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the text colour of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player who's textdraw to set the colour of</param>
 * <param name="textid">The TextDraw to change</param>
 * <param name="textColour">The colour in hexadecimal format</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>You can also use Gametext colours in textdraws.</remarks>
 * <remarks>The textdraw must be re-shown to the player in order to update the colour.</remarks>
 */
native bool:PlayerTextDrawColour(playerid, PlayerText:textid, textColour) = PlayerTextDrawColor;

/**
 * <library>omp_textdraw</library>
 * <summary>Toggle the box on a player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose textdraw to toggle the box of</param>
 * <param name="textid">The ID of the player-textdraw to toggle the box of</param>
 * <param name="boxEnabled"><b><c>1</c></b> to use a box or <b><c>0</c></b> to not use a box</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
native bool:PlayerTextDrawUseBox(playerid, PlayerText:textid, bool:boxEnabled);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the colour of a textdraw's box (<a href="#PlayerTextDrawUseBox">PlayerTextDrawUseBox</a>).</summary>
 * <param name="playerid">The ID of the player whose textdraw to set the box colour of</param>
 * <param name="textid">The ID of the player textdraw to set the box colour of</param>
 * <param name="boxColour">The colour to set.  Alpha (transparency) is supported</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerTextDrawBoxColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:PlayerTextDrawBoxColor(playerid, PlayerText:textid, boxColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the colour of a textdraw's box (<a href="#PlayerTextDrawUseBox">PlayerTextDrawUseBox</a>).</summary>
 * <param name="playerid">The ID of the player whose textdraw to set the box colour of</param>
 * <param name="textid">The ID of the player textdraw to set the box colour of</param>
 * <param name="boxColour">The colour to set.  Alpha (transparency) is supported</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
native bool:PlayerTextDrawBoxColour(playerid, PlayerText:textid, boxColour) = PlayerTextDrawBoxColor;

/**
 * <library>omp_textdraw</library>
 * <summary>Show a player-textdraw to the player it was created for.</summary>
 * <param name="playerid">The ID of the player to show the textdraw for</param>
 * <param name="textid">The ID of the textdraw to show</param>
 * <param name="shadowSize">The size of the shadow. <b><c>0</c></b> will hide the shadow</param>
 * <seealso name="PlayerTextDrawHide" />
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 */
native bool:PlayerTextDrawSetShadow(playerid, PlayerText:textid, shadowSize);

/**
 * <library>omp_textdraw</library>
 * <summary>Set the outline of a player-textdraw.  The outline colour cannot be changed unless
 * <a href="#PlayerTextDrawBackgroundColor">PlayerTextDrawBackgroundColor</a>
 * is used.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the outline of</param>
 * <param name="textid">The ID of the player-textdraw to set the outline of</param>
 * <param name="outlineSize">The thickness of the outline</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
native bool:PlayerTextDrawSetOutline(playerid, PlayerText:textid, outlineSize);

/**
 * <library>omp_textdraw</library>
 * <summary>Adjust the background colour of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the background colour of</param>
 * <param name="textid">The ID of the player-textdraw to set the background colour of</param>
 * <param name="backgroundColour">The colour that the textdraw should be set to</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>If <a href="#PlayerTextDrawSetOutline">PlayerTextDrawSetOutline</a> is used with size &gt;
 * 0, the outline colour will match the colour used in <a href="#PlayerTextDrawBackgroundColor">PlayerTextDrawBackgroundColor</a>.
 *  Changing the value of colour seems to alter the colour used in <a href="#PlayerTextDrawColor">PlayerTextDrawColor</a></remarks>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerTextDrawBackgroundColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:PlayerTextDrawBackgroundColor(playerid, PlayerText:textid, backgroundColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Adjust the background colour of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the background colour of</param>
 * <param name="textid">The ID of the player-textdraw to set the background colour of</param>
 * <param name="backgroundColour">The colour that the textdraw should be set to</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>If <a href="#PlayerTextDrawSetOutline">PlayerTextDrawSetOutline</a> is used with size &gt;
 * 0, the outline colour will match the colour used in <a href="#PlayerTextDrawBackgroundColour">PlayerTextDrawBackgroundColour</a>.
 *  Changing the value of colour seems to alter the colour used in <a href="#PlayerTextDrawColour">PlayerTextDrawColour</a></remarks>
 */
native bool:PlayerTextDrawBackgroundColour(playerid, PlayerText:textid, backgroundColour) = PlayerTextDrawBackgroundColor;

/**
 * <library>omp_textdraw</library>
 * <summary>Change the font of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to change the font of</param>
 * <param name="textid">The ID of the player-textdraw to change the font of</param>
 * <param name="font">There are four font styles.  A font value greater than <b><c>3</c></b> does not
 * display, and anything greater than <b><c>16</c></b> crashes the client.  See
 * <a href="https://open.mp/docs/scripting/functions/TextDrawFont">https://open.mp/docs/scripting/functions/TextDrawFont</a></param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
native bool:PlayerTextDrawFont(playerid, PlayerText:textid, TEXT_DRAW_FONT:font);

/**
 * <library>omp_textdraw</library>
 * <summary>Appears to scale text spacing to a proportional ratio.  Useful when using
 * <a href="#PlayerTextDrawLetterSize">PlayerTextDrawLetterSize</a>
 * to ensure the text has even character spacing.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the proportionality of</param>
 * <param name="textid">The ID of the player-textdraw to set the proportionality of</param>
 * <param name="proportional"><b><c>1</c></b> to enable proportionality, <b><c>0</c></b> to disable</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 */
native bool:PlayerTextDrawSetProportional(playerid, PlayerText:textid, bool:proportional);

/**
 * <library>omp_textdraw</library>
 * <summary>Toggles whether a player-textdraw can be selected or not.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to set the selectability of</param>
 * <param name="textid">The ID of the player-textdraw to set the selectability of</param>
 * <param name="selectable">Set the player-textdraw selectable (<b><c>1</c></b>) or non-selectable (<b><c>0</c></b>).
 *  By default this is <b><c>0</c></b></param>
 * <seealso name="SelectTextDraw" />
 * <seealso name="CancelSelectTextDraw" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks><a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a> MUST be used BEFORE
 * the textdraw is shown to the player.</remarks>
 * <remarks>Use <a href="#PlayerTextDrawTextSize">PlayerTextDrawTextSize</a> to define the clickable
 * area.</remarks>
 */
native bool:PlayerTextDrawSetSelectable(playerid, PlayerText:textid, bool:selectable);

/**
 * <library>omp_textdraw</library>
 * <summary>Show a player-textdraw to the player it was created for.</summary>
 * <param name="playerid">The ID of the player to show the textdraw for</param>
 * <param name="textid">The ID of the textdraw to show</param>
 * <seealso name="PlayerTextDrawHide" />
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 */
native bool:PlayerTextDrawShow(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Hide a player-textdraw from the player it was created for.</summary>
 * <param name="playerid">The ID of the player to hide the textdraw for</param>
 * <param name="textid">The ID of the textdraw to hide</param>
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawSetString" />
 */
native bool:PlayerTextDrawHide(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 * <summary>Change the text of a player-textdraw.</summary>
 * <param name="playerid">The ID of the player who's textdraw string to set</param>
 * <param name="textid">The ID of the textdraw to change</param>
 * <param name="format">The new string for the TextDraw.  May be optionally formatted.</param>
 * <seealso name="CreatePlayerTextDraw" />
 * <seealso name="PlayerTextDrawDestroy" />
 * <seealso name="PlayerTextDrawColour" />
 * <seealso name="PlayerTextDrawBoxColour" />
 * <seealso name="PlayerTextDrawBackgroundColour" />
 * <seealso name="PlayerTextDrawAlignment" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="PlayerTextDrawLetterSize" />
 * <seealso name="PlayerTextDrawTextSize" />
 * <seealso name="PlayerTextDrawSetOutline" />
 * <seealso name="PlayerTextDrawSetShadow" />
 * <seealso name="PlayerTextDrawSetProportional" />
 * <seealso name="PlayerTextDrawUseBox" />
 * <seealso name="PlayerTextDrawShow" />
 * <seealso name="PlayerTextDrawHide" />
 * <remarks>There are limits to the length of textdraw strings! See <a href="https://open.mp/docs/scripting/resources/limits">Limits</a>
 * for more info.</remarks>
 * <remarks>You don't have to show the TextDraw again in order to apply the changes.</remarks>
 */
native bool:PlayerTextDrawSetString(playerid, PlayerText:textid, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets a player textdraw 2D preview sprite of a specified model ID.</summary>
 * <param name="playerid">The PlayerTextDraw player ID</param>
 * <param name="textid">The textdraw ID that will display the 3D preview</param>
 * <param name="model">The GTA SA or SA:MP model ID to display</param>
 * <seealso name="PlayerTextDrawSetPreviewRot" />
 * <seealso name="PlayerTextDrawSetPreviewVehCol" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> in order
 * for this function to have effect.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  If an invalid model is passed 'success' is
 * reported, but the model will appear as a yellow/black question mark.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Player and/or textdraw do not exist.
 * </returns>
 */
native bool:PlayerTextDrawSetPreviewModel(playerid, PlayerText:textid, model);

/**
 * <library>omp_textdraw</library>
 * <summary>Sets the rotation and zoom of a 3D model preview player-textdraw.</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to change</param>
 * <param name="textid">The ID of the player-textdraw to change</param>
 * <param name="rotX">The x rotation value</param>
 * <param name="rotY">The y rotation value</param>
 * <param name="rotZ">The z rotation value</param>
 * <param name="zoom">The zoom value, smaller values make the camera closer and larger values make the
 * camera further away (optional=<b><c>1.0</c></b>)</param>
 * <seealso name="TextDrawSetPreviewRot" />
 * <seealso name="PlayerTextDrawSetPreviewModel" />
 * <seealso name="PlayerTextDrawSetPreviewVehCol" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks>The textdraw MUST use the font type <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> and already
 * have a model set in order for this function to have effect.</remarks>
 */
native bool:PlayerTextDrawSetPreviewRot(playerid, PlayerText:textid, Float:rotX, Float:rotY, Float:rotZ, Float:zoom = 1.0);

/**
 * <library>omp_textdraw</library>
 * <summary>Set the colour of a vehicle in a player-textdraw model preview (if a vehicle is shown).</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to change</param>
 * <param name="textid">The ID of the player's player-textdraw to change</param>
 * <param name="colour1">The <a href="https://open.mp/docs/scripting/resources/vehiclecolorid">colour</a> to set
 * the vehicle's primary colour to</param>
 * <param name="colour2">The <a href="https://open.mp/docs/scripting/resources/vehiclecolorid">colour</a> to set
 * the vehicle's secondary colour to</param>
 * <seealso name="PlayerTextDrawSetPreviewModel" />
 * <seealso name="PlayerTextDrawSetPreviewRot" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks>The textdraw MUST use the font <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> and be showing
 * a vehicle in order for this function to have effect.</remarks>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `PlayerTextDrawSetPreviewVehicleColours`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:PlayerTextDrawSetPreviewVehCol(playerid, PlayerText:textid, colour1, colour2);

/**
 * <library>omp_textdraw</library>
 * <summary>Set the colour of a vehicle in a player-textdraw model preview (if a vehicle is shown).</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to change</param>
 * <param name="textid">The ID of the player's player-textdraw to change</param>
 * <param name="colour1">The <a href="https://open.mp/docs/scripting/resources/vehicleColourid">colour</a> to set
 * the vehicle's primary colour to</param>
 * <param name="colour2">The <a href="https://open.mp/docs/scripting/resources/vehicleColourid">colour</a> to set
 * the vehicle's secondary colour to</param>
 * <seealso name="PlayerTextDrawSetPreviewModel" />
 * <seealso name="PlayerTextDrawSetPreviewRot" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks>The textdraw MUST use the font <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> and be showing
 * a vehicle in order for this function to have effect.</remarks>
 */
#if __namemax > 31
	native bool:PlayerTextDrawSetPreviewVehicleColours(playerid, PlayerText:textid, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 * <summary>Set the colour of a vehicle in a player-textdraw model preview (if a vehicle is shown).</summary>
 * <param name="playerid">The ID of the player whose player-textdraw to change</param>
 * <param name="textid">The ID of the player's player-textdraw to change</param>
 * <param name="colour1">The <a href="https://open.mp/docs/scripting/resources/vehicleColourid">colour</a> to set
 * the vehicle's primary colour to</param>
 * <param name="colour2">The <a href="https://open.mp/docs/scripting/resources/vehicleColourid">colour</a> to set
 * the vehicle's secondary colour to</param>
 * <seealso name="PlayerTextDrawSetPreviewModel" />
 * <seealso name="PlayerTextDrawSetPreviewRot" />
 * <seealso name="PlayerTextDrawFont" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks>The textdraw MUST use the font <b><c>TEXT_DRAW_FONT_MODEL_PREVIEW</c></b> and be showing
 * a vehicle in order for this function to have effect.</remarks>
 */
#if __namemax > 31
	#if !defined MIXED_SPELLINGS
		#pragma deprecated Use `PlayerTextDrawSetPreviewVehicleColours`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
	native bool:PlayerTextDrawSetPreviewVehicleColors(playerid, PlayerText:textid, colour1, colour2) = PlayerTextDrawSetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
native bool:IsValidPlayerTextDraw(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:IsPlayerTextDrawVisible(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawGetString(playerid, PlayerText:textid, string[], stringSize = sizeof (string));

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawSetPos(playerid, PlayerText:textid, Float:x, Float:y);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawGetLetterSize(playerid, PlayerText:textid, &Float:width, &Float:height);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawGetTextSize(playerid, PlayerText:textid, &Float:width, &Float:height);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawGetPos(playerid, PlayerText:textid, &Float:x, &Float:y);

/**
 * <library>omp_textdraw</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerTextDrawGetColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native PlayerTextDrawGetColor(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native PlayerTextDrawGetColour(playerid, PlayerText:textid) = PlayerTextDrawGetColor;

/**
 * <library>omp_textdraw</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerTextDrawGetBoxColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native PlayerTextDrawGetBoxColor(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native PlayerTextDrawGetBoxColour(playerid, PlayerText:textid) = PlayerTextDrawGetBoxColor;

/**
 * <library>omp_textdraw</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `PlayerTextDrawGetBackgroundColour`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native PlayerTextDrawGetBackgroundCol(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
#if __namemax > 31
	native PlayerTextDrawGetBackgroundColour(playerid, PlayerText:textid) = PlayerTextDrawGetBackgroundCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
#if __namemax > 31
	#if !defined MIXED_SPELLINGS
		#pragma deprecated Use `PlayerTextDrawGetBackgroundColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
	native PlayerTextDrawGetBackgroundColor(playerid, PlayerText:textid) = PlayerTextDrawGetBackgroundCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
native PlayerTextDrawGetShadow(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native PlayerTextDrawGetOutline(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native TEXT_DRAW_FONT:PlayerTextDrawGetFont(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawIsBox(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawIsProportional(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawIsSelectable(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native TEXT_DRAW_ALIGN:PlayerTextDrawGetAlignment(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native PlayerTextDrawGetPreviewModel(playerid, PlayerText:textid);

/**
 * <library>omp_textdraw</library>
 */
native bool:PlayerTextDrawGetPreviewRot(playerid, PlayerText:textid, &Float:rotationX, &Float:rotationY, &Float:rotationZ, &Float:zoom);

/**
 * <library>omp_textdraw</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `PlayerTextDrawGetPreviewVehicleColours`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:PlayerTextDrawGetPreviewVehCol(playerid, PlayerText:textid, &colour1, &colour2);

/**
 * <library>omp_textdraw</library>
 */
#if __namemax > 31
	native bool:PlayerTextDrawGetPreviewVehicleColours(playerid, PlayerText:textid, &colour1, &colour2) = PlayerTextDrawGetPreviewVehCol;
#endif

/**
 * <library>omp_textdraw</library>
 */
#if __namemax > 31
	#if !defined MIXED_SPELLINGS
		#pragma deprecated Use `PlayerTextDrawGetPreviewVehicleColours`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
	native bool:PlayerTextDrawGetPreviewVehicleColors(playerid, PlayerText:textid, &colour1, &colour2) = PlayerTextDrawGetPreviewVehCol;
#endif

/*
native # Selection();
native           Selection(
native      ====================(
native
*/

/**
 * <library>omp_textdraw</library>
 * <summary>Display the cursor and allow the player to select a textdraw.</summary>
 * <param name="playerid">The ID of the player that should be able to select a textdraw</param>
 * <param name="hoverColour">The colour of the textdraw when hovering over with mouse (<b>RGBA</b>)</param>
 * <seealso name="CancelSelectTextDraw" />
 * <seealso name="TextDrawSetSelectable" />
 * <seealso name="PlayerTextDrawSetSelectable" />
 * <seealso name="OnPlayerClickTextDraw" />
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <remarks><a href="#TextDrawSetSelectable">TextDrawSetSelectable</a> or
 * <a href="#PlayerTextDrawSetSelectable">PlayerTextDrawSetSelectable</a>
 * MUST be used first, to allow a textdraw to be selectable.</remarks>
 * <remarks>It is the TEXT which will be highlighted when hovered over, NOT the box (if one is shown).</remarks>
 */
native bool:SelectTextDraw(playerid, hoverColor);

/**
 * <library>omp_textdraw</library>
 * <summary>Cancel textdraw selection with the mouse.</summary>
 * <param name="playerid">The ID of the player that should be the textdraw selection disabled</param>
 * <seealso name="SelectTextDraw" />
 * <seealso name="TextDrawSetSelectable" />
 * <seealso name="OnPlayerClickTextDraw" />
 * <remarks>This function calls <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a> with <b><c>INVALID_TEXT_DRAW</c></b>
 * (<b><c>65535</c></b>).  Using this function inside <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a>
 * without catching this case will cause clients to go into an infinite loop.</remarks>
 */
native bool:CancelSelectTextDraw(playerid);

/*
                                                                                                  
      ,ad8888ba,               88  88  88                                   88                    
     d8"'    `"8b              88  88  88                                   88                    
    d8'                        88  88  88                                   88                    
    88             ,adPPYYba,  88  88  88,dPPYba,   ,adPPYYba,   ,adPPYba,  88   ,d8   ,adPPYba,  
    88             ""     `Y8  88  88  88P'    "8a  ""     `Y8  a8"     ""  88 ,a8"    I8[    ""  
    Y8,            ,adPPPPP88  88  88  88       d8  ,adPPPPP88  8b          8888[       `"Y8ba,   
     Y8a.    .a8P  88,    ,88  88  88  88b,   ,a8"  88,    ,88  "8a,   ,aa  88`"Yba,   aa    ]8I  
      `"Y8888Y"'   `"8bbdP"Y8  88  88  8Y"Ybbd8"'   `"8bbdP"Y8   `"Ybbd8"'  88   `Y8a  `"YbbdP"'  
                                                                                                  
                                                                                                  

*/

/**
 * <summary>This callback is called when a player clicks on a textdraw or cancels the select mode with
 * the Escape key.</summary>
 * <param name="playerid">The ID of the player that clicked on the textdraw</param>
 * <param name="clickedid">The ID of the clicked textdraw. <b><c>INVALID_TEXT_DRAW</c></b> if selection
 * was cancelled</param>
 * <seealso name="OnPlayerClickPlayerTextDraw" />
 * <seealso name="OnPlayerClickPlayer" />
 * <remarks>The clickable area is defined by <a href="#TextDrawTextSize">TextDrawTextSize</a>.  The
 * x and y parameters passed to that function must not be zero or negative. </remarks>
 * <remarks>Do not use <a href="#CancelSelectTextDraw">CancelSelectTextDraw</a> unconditionally within
 * this callback.  This results in an infinite loop. </remarks>
 * <returns>
 *   Returning <b><c>1</c></b> in this callback will prevent it being called in other scripts.  This
 * should be used to signal that the textdraw on which they clicked was 'found' and no further processing
 * is needed.  You should return <b><c>0</c></b> if the textdraw on which they clicked wasn't found,
 * just like in <a href="#OnPlayerCommandText">OnPlayerCommandText</a>.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there also blocks other
 * scripts from seeing it.
 * </returns>
 */
forward OnPlayerClickTextDraw(playerid, Text:clickedid);

/**
 * <summary>This callback is called when a player clicks on a player-textdraw.  It is not called when
 * player cancels the select mode (ESC) - however, <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a>
 * is.</summary>
 * <param name="playerid">The ID of the player that selected a textdraw</param>
 * <param name="playertextid">The ID of the player-textdraw that the player selected</param>
 * <seealso name="PlayerTextDrawSetSelectable" />
 * <seealso name="OnPlayerClickTextDraw" />
 * <seealso name="OnPlayerClickPlayer" />
 * <remarks>When a player presses ESC to cancel selecting a textdraw, <a href="#OnPlayerClickTextDraw">OnPlayerClickTextDraw</a>
 * is called with a textdraw ID of <b><c>INVALID_TEXT_DRAW</c></b>. <a href="#OnPlayerClickPlayerTextDraw">OnPlayerClickPlayerTextDraw</a>
 * won't be called also.</remarks>
 * <returns>
 *   Returning <b><c>1</c></b> in this callback will prevent it being called in other scripts.  This
 * should be used to signal that the textdraw on which they clicked was 'found' and no further processing
 * is needed.  You should return <b><c>0</c></b> if the textdraw on which they clicked wasn't found,
 * just like in <a href="#OnPlayerCommandText">OnPlayerCommandText</a>.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there also blocks other
 * scripts from seeing it.
 * </returns>
 */
forward OnPlayerClickPlayerTextDraw(playerid, PlayerText:playertextid);
