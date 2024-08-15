#if defined _INC_omp_menu
	#endinput
#endif
#define _INC_omp_menu

/**
 * <library name="omp_menu" summary="open.mp menu functions.">
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
 * <library>omp_menu</library>
 */
#if defined MAX_MENUS
	#if MAX_MENUS < Menu:1 || MAX_MENUS > Menu:128
		#error MAX_MENUS must be >= 1 and <= 128
	#endif

	const Menu:__MAX_MENUS                     = MAX_MENUS;
	#define __MAX_MENUS
#else
	const Menu:MAX_MENUS                       = Menu:128;
	#define MAX_MENUS                          (Menu:128)
#endif

/**
 * <library>omp_menu</library>
 */
const Menu:INVALID_MENU                        = Menu:-1;
#define INVALID_MENU                           (Menu:-1)

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
 * <library>omp_menu</library>
 * <summary>Creates a menu.</summary>
 * <param name="title">The title for the new menu.  May be optionally formatted.</param>
 * <param name="columns">How many colums shall the new menu have</param>
 * <param name="x">The x position of the menu (640x460 canvas - <b><c>0</c></b> would put the menu at
 * the far left)</param>
 * <param name="y">The y position of the menu (640x460 canvas - <b><c>0</c></b> would put the menu at
 * the far top)</param>
 * <param name="column1width">The width for the first column</param>
 * <param name="column2width">The width for the second column (optional=<b><c>0.0</c></b>)</param>
 * <seealso name="AddMenuItem" />
 * <seealso name="SetMenuColumnHeader" />
 * <seealso name="DestroyMenu" />
 * <seealso name="ShowMenuForPlayer" />
 * <seealso name="HideMenuForPlayer" />
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <seealso name="OnPlayerExitedMenu" />
 * <remarks>
 *   This function merely CREATES the menu - <a href="#ShowMenuForPlayer">ShowMenuForPlayer</a> must
 * be used to show it.<br />
 *   You can only create and access <b><c>2</c></b> columns (<b><c>0</c></b> and <b><c>1</c></b>).<br
 * />
 *   If the title's length is equal to or greater than <b><c>32</c></b> chars the title is truncated
 * to <b><c>30</c></b> characters.
 * </remarks>
 * <remarks>There is a limit of <b><c>12</c></b> items per menu, and a limit of <b><c>128</c></b> menus
 * in total.</remarks>
 * <returns>The ID of the new menu or <b><c>-1</c></b> on failure.</returns>
 */
native Menu:CreateMenu(const title[], columns, Float:x, Float:y, Float:column1width, Float:column2width = 0.0, OPEN_MP_TAGS:...);

/**
 * <library>omp_menu</library>
 * <summary>Destroys the specified menu.</summary>
 * <param name="menuid">The menu ID to destroy</param>
 * <seealso name="CreateMenu" />
 * <seealso name="SetMenuColumnHeader" />
 * <seealso name="AddMenuItem" />
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <seealso name="OnPlayerExitedMenu" />
 * <returns><b><c>1</c></b> if the destroying was successful, otherwise <b><c>0</c></b>.</returns>
 */
native bool:DestroyMenu(Menu:menuid);

/**
 * <library>omp_menu</library>
 * <summary>Adds an item to a specified menu.</summary>
 * <param name="menuid">The menu ID to add an item to</param>
 * <param name="column">The column to add the item to</param>
 * <param name="text">The text for the new menu item.  May be optionally formatted.</param>
 * <remarks>
 *   <ul>
 *     <li>Crashes when passed an invalid menu ID.</li>
 *     <li>You can only have <b><c>12</c></b> items per menu (13th goes to the right side of the header
 * of column name (coloured), 14th and higher not display at all).</li>
 *     <li>You can only use <b><c>2</c></b> columns (<b><c>0</c></b> and <b><c>1</c></b>).</li>
 *     <li>You can only add <b><c>8</c></b> colour codes per one item (<b><c>~r~</c></b>, <b><c>~g~</c></b>
 * etc.).</li>
 *     <li>Maximum length of menu item is <b><c>31</c></b> symbols. </li>
 *   </ul>
 * </remarks>
 * <returns>The index of the row this item was added to.</returns>
 * <seealso name="CreateMenu" />
 * <seealso name="SetMenuColumnHeader" />
 * <seealso name="DestroyMenu" />
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <seealso name="OnPlayerExitedMenu" />
 */
native AddMenuItem(Menu:menuid, column, const text[], OPEN_MP_TAGS:...);

/**
 * <library>omp_menu</library>
 * <summary>Sets the caption of a column in a menu.</summary>
 * <param name="menuid">ID of the menu to change</param>
 * <param name="column">The column (<b><c>0</c></b> or <b><c>1</c></b>) to set the header of</param>
 * <param name="heading">The caption text for the column.  May be optionally formatted.</param>
 * <seealso name="AddMenuItem" />
 * <seealso name="CreateMenu" />
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <remarks>Crashes when passed an invalid menu ID.</remarks>
 * <remarks>Note that you can add only <b><c>12</c></b> items with <a href="#AddMenuItem">AddMenuItem</a>.
 *  The 13th object of a menu would replace the header of the column which is correctly set with this
 * function.</remarks>
 */
native bool:SetMenuColumnHeader(Menu:menuid, column, const heading[], OPEN_MP_TAGS:...);

/**
 * <library>omp_menu</library>
 * <summary>Shows a previously created menu for a player.</summary>
 * <param name="menuid">The ID of the menu to show.  Returned by CreateMenu</param>
 * <param name="playerid">The ID of the player to whom the menu will be shown</param>
 * <seealso name="CreateMenu" />
 * <seealso name="AddMenuItem" />
 * <seealso name="SetMenuColumnHeader" />
 * <seealso name="ShowPlayerDialog" />
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <seealso name="OnPlayerExitedMenu" />
 * <remarks>Crashes the both server and player if an invalid menu ID given.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Menu and/or player doesn't exist.
 * </returns>
 */
native bool:ShowMenuForPlayer(Menu:menuid, playerid);

/**
 * <library>omp_menu</library>
 * <summary>Hides a menu for a player.</summary>
 * <param name="menuid">The ID of the menu to hide.  Returned by <a href="#CreateMenu">CreateMenu</a>
 * and passed to <a href="#OnPlayerSelectedMenuRow">OnPlayerSelectedMenuRow</a></param>
 * <param name="playerid">The ID of the player that the menu will be hidden for</param>
 * <seealso name="ShowMenuForPlayer" />
 * <seealso name="AddMenuItem" />
 * <seealso name="SetMenuColumnHeader" />
 * <seealso name="CreateMenu" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:HideMenuForPlayer(Menu:menuid, playerid);

/**
 * <library>omp_menu</library>
 * <summary>Check if a menu ID is vliad.</summary>
 * <param name="menuid">The menu to check for existance</param>
 * <seealso name="CreateMenu" />
 * <seealso name="DestroyMenu" />
 * <returns><b><c>1</c></b> if the menu is valid, otherwise <b><c>0</c></b>.</returns>
 */
native bool:IsValidMenu(Menu:menuid);

/**
 * <library>omp_menu</library>
 * <summary>Disable a menu.</summary>
 * <param name="menuid">The ID of the menu to disable</param>
 * <seealso name="CreateMenu" />
 * <seealso name="DestroyMenu" />
 * <seealso name="AddMenuItem" />
 * <remarks>Crashes when passed an invalid menu ID.</remarks>
 */
native bool:DisableMenu(Menu:menuid);

/**
 * <library>omp_menu</library>
 * <summary>Disable a specific row in a menu <b>for all players</b>.  It will be greyed-out and can't
 * be selected by players.</summary>
 * <param name="menuid">The ID of the menu to disable a row of.  Ensure this is valid, as an invalid
 * menu ID will crash the entire server</param>
 * <param name="row">The ID of the row to disable (rows start at 0)</param>
 * <seealso name="CreateMenu" />
 * <seealso name="DestroyMenu" />
 * <seealso name="AddMenuItem" />
 * <remarks>
 *   Crashes when passed an invalid menu ID.<br />
 *   This function disabled the specified menu row for <b>all players</b>.  There is no function to
 * disable a menu row for a specific player.  You'd have to create two menus - one with a row disabled,
 * and one without.  Or one per player.
 * </remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if the function fails.  If an invalid
 * row is specified, nothing will happen.  If an invalid menu ID is specified, the server will crash.</returns>
 */
native bool:DisableMenuRow(Menu:menuid, row);

/**
 * <library>omp_menu</library>
 * <summary>Gets the ID of the menu the player is currently viewing (shown by <a href="#ShowMenuForPlayer">ShowMenuForPlayer</a>).</summary>
 * <param name="playerid">The ID of the player to get the current menu of</param>
 * <seealso name="ShowMenuForPlayer" />
 * <seealso name="HideMenuForPlayer" />
 * <seealso name="CreateMenu" />
 * <seealso name="DestroyMenu" />
 * <seealso name="AddMenuItem" />
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <seealso name="OnPlayerExitedMenu" />
 * <remarks>Returns previous menu when none is displayed.</remarks>
 * <returns>The ID of the player's currently shown menu, or <b><c>INVALID_MENU</c></b> (<b><c>255</c></b>)
 * if no menu shown.</returns>
 */
native Menu:GetPlayerMenu(playerid);

/**
 * <library>omp_menu</library>
 * <summary>Is this menu disabled?</param>
 */
native bool:IsMenuDisabled(Menu:menuid);

/**
 * <library>omp_menu</library>
 * <summary>Is this row disabled?</param>
 */
native bool:IsMenuRowDisabled(Menu:menuid, row);

/**
 * <library>omp_menu</library>
 * <summary>Get the number of active columns.</param>
 */
native GetMenuColumns(Menu:menuid);

/**
 * <library>omp_menu</library>
 * <summary>Get the number of rows in the given column.</param>
 */
native GetMenuItems(Menu:menuid, column);

/**
 * <library>omp_menu</library>
 * <summary>Get the x/y screen position of the menu.</param>
 */
native bool:GetMenuPos(Menu:menuid, &Float:x, &Float:y);

/**
 * <library>omp_menu</library>
 * <summary>Get the width of the one or two columns.</param>
 */
native bool:GetMenuColumnWidth(Menu:menuid, &Float:column1Width, &Float:column2Width = 0.0);

/**
 * <library>omp_menu</library>
 * <summary>Get the text in the header of the specified column.</param>
 */
native bool:GetMenuColumnHeader(Menu:menuid, column, header[], len = sizeof (header));

/**
 * <library>omp_menu</library>
 * <summary>Get the text in the specified cell - addressed by column and row.</param>
 */
native bool:GetMenuItem(Menu:menuid, column, row, cell[], len = sizeof (cell));

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
 * <summary>This callback is called when a player selects an item from a menu (<a href="#ShowMenuForPlayer">ShowMenuForPlayer</a>).</summary>
 * <param name="playerid">The ID of the player that selected a menu item</param>
 * <param name="row">The ID of the row that was selected.  The first row is ID <b><c>0</c></b></param>
 * <seealso name="OnPlayerExitedMenu" />
 * <seealso name="OnDialogResponse" />
 * <seealso name="CreateMenu" />
 * <seealso name="DestroyMenu" />
 * <seealso name="AddMenuItem" />
 * <seealso name="ShowMenuForPlayer" />
 * <seealso name="HideMenuForPlayer" />
 * <remarks>The menu ID is not passed to this callback. <a href="#GetPlayerMenu">GetPlayerMenu</a> must
 * be used to determine which menu the player selected an item on.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerSelectedMenuRow(playerid, row);

/**
 * <summary>Called when a player exits a menu.</summary>
 * <param name="playerid">The ID of the player that exited the menu</param>
 * <seealso name="OnPlayerSelectedMenuRow" />
 * <seealso name="CreateMenu" />
 * <seealso name="DestroyMenu" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerExitedMenu(playerid);
