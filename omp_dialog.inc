#if defined _INC_omp_dialog
	#endinput
#endif
#define _INC_omp_dialog

/**
 * <library name="omp_dialog" summary="open.mp dialog functions.">
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
 * <library>omp_dialog</library>
 */
const INVALID_DIALOG_ID                        = -1;
#define INVALID_DIALOG_ID                      (-1)

/**
 * <library>omp_dialog</library>
 * <remarks>Any show dialogs must have an ID lower than this.</remarks>
 */
const MAX_DIALOG                               = 32768;
#define MAX_DIALOG                             (32768)

/// <p/>
/**
 * <library>omp_dialog</library>
 * <summary>Player GUI dialog</summary>
 */
#define DIALOG_STYLE: __TAG(DIALOG_STYLE):
enum DIALOG_STYLE:__DIALOG_STYLE
{
	UNKNOWN_DIALOG_STYLE                       = -1,
	DIALOG_STYLE_MSGBOX,
	DIALOG_STYLE_INPUT,
	DIALOG_STYLE_LIST,
	DIALOG_STYLE_PASSWORD,
	DIALOG_STYLE_TABLIST,
	DIALOG_STYLE_TABLIST_HEADERS
}
static stock DIALOG_STYLE:_@DIALOG_STYLE() { return __DIALOG_STYLE; }

#define UNKNOWN_DIALOG_STYLE                   (DIALOG_STYLE:-1)
#define DIALOG_STYLE_MSGBOX                    (DIALOG_STYLE:0)
#define DIALOG_STYLE_INPUT                     (DIALOG_STYLE:1)
#define DIALOG_STYLE_LIST                      (DIALOG_STYLE:2)
#define DIALOG_STYLE_PASSWORD                  (DIALOG_STYLE:3)
#define DIALOG_STYLE_TABLIST                   (DIALOG_STYLE:4)
#define DIALOG_STYLE_TABLIST_HEADERS           (DIALOG_STYLE:5)

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

/**
 * <library>omp_dialog</library>
 * <summary>Shows the player a synchronous (only one at a time) dialog box.</summary>
 * <param name="playerid">The ID of the player to show the dialog to</param>
 * <param name="dialogid">An ID to assign this dialog to, so responses can be processed.  Max dialogid
 * is <b><c>32767</c></b>.  Using negative values will close any open dialog</param>
 * <param name="style">The style of the dialog</param>
 * <param name="title">The title at the top of the dialog.  The length of the title can not exceed
 * more than 64 characters before it starts to cut off</param>
 * <param name="body">The text to display in the main dialog.  Use <b><c>\n</c></b> to start a new line
 * and <b><c>\t</c></b> to tabulate.  May be optionally formatted.</param>
 * <param name="button1">The text on the left button</param>
 * <param name="button2">The text on the right button.  Leave it blank ( "" ) to hide it</param>
 * <seealso name="TextDrawShowForPlayer" />
 * <seealso name="OnDialogResponse" />
 * <remarks>Use colour embedding for multiple colours in the text. </remarks>
 * <remarks>Using <b><c>-1</c></b> as dialogid closes all dialogs currently shown on the client's screen.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.<br />
 * </returns>
 */
native bool:ShowPlayerDialog(playerid, dialogid, DIALOG_STYLE:style, const title[], const body[], const button1[], const button2[], OPEN_MP_TAGS:...);

/**
 * <library>omp_dialog</library>
 * <summary>Hides any dialog the player may currently be able to see.</summary>
 * <param name="playerid">The ID of the player to hide their current dialog from</param>
 * <seealso name="TextDrawShowForPlayer" />
 * <seealso name="OnDialogResponse" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected or they aren't looking at a dialog.<br />
 * </returns>
 */
native bool:HidePlayerDialog(playerid);

/**
 * <library>omp_dialog</library>
 * <summary>Get the data of the dialog currently show to the player.</summary>
 * <param name="playerid">The ID of the player to get the data for</param>
 * <param name="style">The style of the dialog</param>
 * <param name="title">The title at the top of the dialog.</param>
 * <param name="body">The text in the main dialog.</param>
 * <param name="button1">The text on the left button</param>
 * <param name="button2">The text on the right button.  Blank if it is hidden.</param>
 * <seealso name="TextDrawShowForPlayer" />
 * <seealso name="OnDialogResponse" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected or they don't have a dialog open.<br />
 * </returns>
 */
native bool:GetPlayerDialogData(playerid, &DIALOG_STYLE:style, title[], titleSize = sizeof (title), body[], bodySize = sizeof (body), button1[], button1Size = sizeof (button1), button2[], button2Size = sizeof (button2));

/**
 * <library>omp_dialog</library>
 * <summary>Get the ID of the dialog currently show to the player.</summary>
 * <param name="playerid">The ID of the player to get the ID for</param>
 * <returns>
 *   The ID, or <b><c>INVALID_DIALOG_ID</c></b> if there's no player or open dialog.<br />
 * </returns>
 */
native GetPlayerDialogID(playerid);

/*
native # Deprecated();
native           Deprecated(
native      ====================(
native
*/

/**
 * <library>omp_dialog</library>
 * <summary>Get the ID of the dialog currently show to the player.</summary>
 * <param name="playerid">The ID of the player to get the ID for</param>
 * <remarks>
 * Added for fixes.inc compatibility, but as <c>GetPlayerDialogID</c> from YSF also exists we don't
 * need two.  This one is thus deprecated as then we have <c>ID</c> and <c>Data</c> suffixes for
 * differentiation and clarity.
 * </remarks>
 * <returns>
 *   The ID, or <b><c>INVALID_DIALOG_ID</c></b> if there's no player or open dialog.<br />
 * </returns>
 */
#pragma deprecated Use `GetPlayerDialogID`.
native GetPlayerDialog(playerid) = GetPlayerDialogID;

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
 * <library>omp_dialog</library>
 * <summary>This callback is called when a player responds to a dialog shown using <a href="#ShowPlayerDialog">ShowPlayerDialog</a>
 * by either clicking a button, pressing ENTER/ESC or double-clicking a list item (if using a list style
 * dialog).</summary>
 * <param name="playerid">The ID of the player that responded to the dialog</param>
 * <param name="dialogid">The ID of the dialog the player responded to, assigned in ShowPlayerDialog</param>
 * <param name="response"><b><c>1</c></b> for left button and <b><c>0</c></b> for right button (if only
 * one button shown, always <b><c>1</c></b>)</param>
 * <param name="listitem">The ID of the list item selected by the player (starts at <b><c>0</c></b>)
 * (only if using a list style dialog)</param>
 * <param name="inputtext">The text entered into the input box by the player or the selected list item
 * text</param>
 * <seealso name="ShowPlayerDialog" />
 * <remarks>A player's dialog doesn't hide when the gamemode restarts, causing the server to print <c>"Warning:
 * PlayerDialogResponse PlayerId: 0 dialog ID doesn't match last sent dialog ID"</c> if a player responded
 * to this dialog after restart.</remarks>
 * <remarks>Parameters can contain different values, based on dialog's
 * <a href="https://open.mp/docs/scripting/resources/dialogstyles">style</a>.
 * </remarks>
 * <returns>
 *   Returning <b><c>0</c></b> in this callback will pass the dialog to another script in case no matching
 * code were found in your gamemode's callback.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnDialogResponse(playerid, dialogid, response, listitem, inputtext[]);
