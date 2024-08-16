#if defined _INC_omp_textlabel
	#endinput
#endif
#define _INC_omp_textlabel

/**
 * <library name="omp_textlabel" summary="open.mp 3D text label functions.">
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
 * <library>omp_textlabel</library>
 */
#if defined MAX_3DTEXT_GLOBAL
	#if MAX_3DTEXT_GLOBAL < Text3D:1 || MAX_3DTEXT_GLOBAL > Text3D:1024
		#error MAX_3DTEXT_GLOBAL must be >= 1 and <= 1024
	#endif

	const Text3D:__MAX_3DTEXT_GLOBAL           = MAX_3DTEXT_GLOBAL;
	#define __MAX_3DTEXT_GLOBAL
#else
	const Text3D:MAX_3DTEXT_GLOBAL             = Text3D:1024;
	#define MAX_3DTEXT_GLOBAL                  (Text3D:1024)
#endif

/**
 * <library>omp_textlabel</library>
 */
#if defined MAX_3DTEXT_PLAYER
	#if MAX_3DTEXT_PLAYER < PlayerText3D:1 || MAX_3DTEXT_PLAYER > PlayerText3D:1024
		#error MAX_3DTEXT_PLAYER must be >= 1 and <= 1024
	#endif

	const PlayerText3D:__MAX_3DTEXT_PLAYER     = MAX_3DTEXT_PLAYER;
	#define __MAX_3DTEXT_PLAYER
#else
	const PlayerText3D:MAX_3DTEXT_PLAYER       = PlayerText3D:1024;
	#define MAX_3DTEXT_PLAYER                  (PlayerText3D:1024)
#endif

/**
 * <library>omp_textlabel</library>
 */
const Text3D:INVALID_3DTEXT_ID                 = Text3D:0xFFFF;
#define INVALID_3DTEXT_ID                      (Text3D:65535)

/**
 * <library>omp_textlabel</library>
 */
const PlayerText3D:INVALID_PLAYER_3DTEXT_ID    = PlayerText3D:0xFFFF;
#define INVALID_PLAYER_3DTEXT_ID               (PlayerText3D:65535)

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
native             Global(
native      ====================(
native
*/

/**
 * <library>omp_textlabel</library>
 * <summary>Creates a 3D Text Label at a specific location in the world.</summary>
 * <param name="text">The initial text string.  May be optionally formatted.</param>
 * <param name="colour">The text colour, as an integer or hex in <b>RGBA</b> colour format</param>
 * <param name="x">x-Coordinate</param>
 * <param name="y">y-Coordinate</param>
 * <param name="z">z-Coordinate</param>
 * <param name="drawDistance">The distance from where you are able to see the 3D Text Label</param>
 * <param name="virtualWorld">The virtual world in which you are able to see the 3D Text</param>
 * <param name="testLOS">Test the line-of-sight so this text can't be seen through objects (optional=<b><c>0</c></b>)</param>
 * <seealso name="Delete3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * <remarks>
 *   If <paramref name="text" /> is empty, the server/clients next to the text might crash!<br />
 *   If the virtualWorld is set as <b><c>-1</c></b> the text will not appear.
 * </remarks>
 * <remarks>drawdistance seems to be a lot smaller when spectating.</remarks>
 * <remarks>Use <a href="https://www.open.mp/docs/scripting/resources/colorslist">colour embedding</a>
 * for multiple colours in the text.</remarks>
 * <returns>The ID of the newly created 3D Text Label, or <b><c>INVALID_3DTEXT_ID</c></b> if the 3D
 * Text Label limit (<b><c>MAX_3DTEXT_GLOBAL</c></b>) was reached.</returns>
 */
native Text3D:Create3DTextLabel(const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, virtualWorld, bool:testLOS = false, OPEN_MP_TAGS:...);

/**
 * <library>omp_textlabel</library>
 * <summary>Delete a 3D text label (created with <a href="#Create3DTextLabel">Create3DTextLabel</a>).</summary>
 * <param name="textid">The ID of the 3D text label to delete</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * <returns><b><c>1</c></b> if the 3D text label was deleted, otherwise <b><c>0</c></b>.</returns>
 */
native bool:Delete3DTextLabel(Text3D:textid);

/**
 * <library>omp_textlabel</library>
 * <summary>Attach a 3D text label to a player.</summary>
 * <param name="textid">The ID of the 3D text label to attach.  Returned by <a href="#Create3DTextLabel">Create3DTextLabel</a></param>
 * <param name="parentid">The ID of the player to attach the label to</param>
 * <param name="offsetX">The x offset from the player</param>
 * <param name="offsetY">The y offset from the player</param>
 * <param name="offsetZ">The z offset from the player</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Delete3DTextLabel" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * <returns>
 * <b><c>1</c></b>: The function executed successfully.<br />
 * <b><c>0</c></b>: The function failed to execute.  This means the player and/or label do not exist.
 * </returns>
 */
native bool:Attach3DTextLabelToPlayer(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ);

/**
 * <library>omp_textlabel</library>
 * <summary>Attaches a 3D Text Label to a specific vehicle.</summary>
 * <param name="textid">The ID of the 3D text label to attach.  Returned by <a href="#Create3DTextLabel">Create3DTextLabel</a></param>
 * <param name="parentid">The vehicle you want to attach the 3D Text Label to</param>
 * <param name="offsetX">The offset-x coordinate of the player vehicle (the vehicle is 0.0, 0.0, 0.0).</param>
 * <param name="offsetY">The offset-y coordinate of the player vehicle (the vehicle is 0.0, 0.0, 0.0).</param>
 * <param name="offsetZ">The offset-z coordinate of the player vehicle (the vehicle is 0.0, 0.0, 0.0).</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Delete3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * and will not work in earlier versions!</remarks>
 */
native bool:Attach3DTextLabelToVehicle(Text3D:textid, parentid, Float:offsetX, Float:offsetY, Float:offsetZ);

/**
 * <library>omp_textlabel</library>
 * <summary>Updates a 3D Text Label text and colour.</summary>
 * <param name="textid">The 3D Text Label you want to update</param>
 * <param name="colour">The colour the 3D Text Label should have from now on</param>
 * <param name="text">The new text which the 3D Text Label should have from now on.  May be optionally formatted.</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Delete3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * <remarks>If <paramref name="text" /> is empty, the server/clients next to the text might crash!</remarks>
 */
native bool:Update3DTextLabelText(Text3D:textid, colour, const text[], OPEN_MP_TAGS:...);

/**
 * <library>omp_textlabel</library>
 */
native bool:IsValid3DTextLabel(Text3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:Is3DTextLabelStreamedIn(playerid, Text3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:Get3DTextLabelText(Text3D:textid, text[], len = sizeof (text));

/**
 * <library>omp_textlabel</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `Get3DTextLabelColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native Get3DTextLabelColor(Text3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native Get3DTextLabelColour(Text3D:textid) = Get3DTextLabelColor;

/**
 * <library>omp_textlabel</library>
 */
native bool:Get3DTextLabelPos(Text3D:textid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_textlabel</library>
 */
native Float:Get3DTextLabelDrawDistance(Text3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:Set3DTextLabelDrawDistance(Text3D:textid, Float:drawDistance);

/**
 * <library>omp_textlabel</library>
 */
native bool:Get3DTextLabelLOS(Text3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:Set3DTextLabelLOS(Text3D:textid, bool:enable);

/**
 * <library>omp_textlabel</library>
 */
native Get3DTextLabelVirtualWorld(Text3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:Set3DTextLabelVirtualWorld(Text3D:textid, virtualWorld);

/**
 * <library>omp_textlabel</library>
 */
native bool:Get3DTextLabelAttachedData(Text3D:textid, &parentPlayerid, &parentVehicleid);

/*
native # Per-Player();
native           Per-Player(
native      ====================(
native
*/

/**
 * <library>omp_textlabel</library>
 * <summary>Creates a 3D Text Label only for a specific player.</summary>
 * <param name="playerid">The player which should see the newly created 3DText Label</param>
 * <param name="text">The text to display.  May be optionally formatted.</param>
 * <param name="colour">The text colour</param>
 * <param name="x">x Coordinate (or offset if attached)</param>
 * <param name="y">y Coordinate (or offset if attached)</param>
 * <param name="z">z Coordinate (or offset if attached)</param>
 * <param name="drawDistance">The distance where you are able to see the 3D Text Label</param>
 * <param name="parentPlayerid">The player you want to attach the 3D Text Label to. (optional=<b><c>INVALID_PLAYER_ID</c></b>)</param>
 * <param name="parentVehicleid">The vehicle you want to attach the 3D Text Label to. (optional=<b><c>INVALID_VEHICLE_ID</c></b>)</param>
 * <param name="testLOS">Test the line-of-sight so this text can't be seen through walls (optional=<b><c>0</c></b>)</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Delete3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * <remarks>If <paramref name="text" /> is empty, the server/clients next to the text might crash!</remarks>
 * <remarks>drawdistance seems to be a lot smaller when spectating.</remarks>
 * <returns>The ID of the newly created Player 3D Text Label, or <b><c>INVALID_3DTEXT_ID</c></b> if
 * the Player 3D Text Label limit (<b><c>MAX_3DTEXT_PLAYER</c></b>) was reached.</returns>
 */
native PlayerText3D:CreatePlayer3DTextLabel(playerid, const text[], colour, Float:x, Float:y, Float:z, Float:drawDistance, parentPlayerid = INVALID_PLAYER_ID, parentVehicleid = INVALID_VEHICLE_ID, bool:testLOS = false, OPEN_MP_TAGS:...);

/**
 * <library>omp_textlabel</library>
 * <summary>Destroy a 3D text label that was created using <a href="#CreatePlayer3DTextLabel">CreatePlayer3DTextLabel</a>.</summary>
 * <param name="playerid">The ID of the player whose 3D text label to delete</param>
 * <param name="textid">The ID of the player's 3D text label to delete</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="UpdatePlayer3DTextLabelText" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the label specified doesn't exist.
 * </returns>
 */
native bool:DeletePlayer3DTextLabel(playerid, PlayerText3D:textid);

/**
 * <library>omp_textlabel</library>
 * <summary>Updates a player 3D Text Label's text and colour.</summary>
 * <param name="playerid">The ID of the player for which the 3D Text Label was created</param>
 * <param name="textid">The 3D Text Label you want to update</param>
 * <param name="colour">The colour the 3D Text Label should have from now on</param>
 * <param name="text">The new text which the 3D Text Label should have from now on.  May be optionally formatted.</param>
 * <seealso name="Create3DTextLabel" />
 * <seealso name="Delete3DTextLabel" />
 * <seealso name="Attach3DTextLabelToPlayer" />
 * <seealso name="Attach3DTextLabelToVehicle" />
 * <seealso name="Update3DTextLabelText" />
 * <seealso name="CreatePlayer3DTextLabel" />
 * <seealso name="DeletePlayer3DTextLabel" />
 * <remarks>If <paramref name="text" /> is empty, the server/clients next to the text might crash!</remarks>
 */
native bool:UpdatePlayer3DTextLabelText(playerid, PlayerText3D:textid, colour, const text[], OPEN_MP_TAGS:...);

/**
 * <library>omp_textlabel</library>
 */
native bool:IsValidPlayer3DTextLabel(playerid, PlayerText3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:GetPlayer3DTextLabelText(playerid, PlayerText3D:textid, text[], len = sizeof (text));

/**
 * <library>omp_textlabel</library>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `GetPlayer3DTextLabelColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native GetPlayer3DTextLabelColor(playerid, PlayerText3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native GetPlayer3DTextLabelColour(playerid, PlayerText3D:textid) = GetPlayer3DTextLabelColor;

/**
 * <library>omp_textlabel</library>
 */
native bool:GetPlayer3DTextLabelPos(playerid, PlayerText3D:textid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_textlabel</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `GetPlayer3DTextLabelDrawDistance`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native Float:GetPlayer3DTextLabelDrawDist(playerid, PlayerText3D:textid);

/**
 * <library>omp_textlabel</library>
 */
#if __namemax > 31
	native Float:GetPlayer3DTextLabelDrawDistance(playerid, PlayerText3D:textid) = GetPlayer3DTextLabelDrawDist;
#endif

/**
 * <library>omp_textlabel</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `SetPlayer3DTextLabelDrawDistance`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:SetPlayer3DTextLabelDrawDist(playerid, PlayerText3D:textid, Float:drawDistance);

/**
 * <library>omp_textlabel</library>
 */
#if __namemax > 31
	native bool:SetPlayer3DTextLabelDrawDistance(playerid, PlayerText3D:textid, Float:drawDistance) = SetPlayer3DTextLabelDrawDist;
#endif

/**
 * <library>omp_textlabel</library>
 */
native bool:GetPlayer3DTextLabelLOS(playerid, PlayerText3D:textid);

/**
 * <library>omp_textlabel</library>
 */
native bool:SetPlayer3DTextLabelLOS(playerid, PlayerText3D:textid, bool:enable);

/**
 * <library>omp_textlabel</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `GetPlayer3DTextLabelVirtualWorld`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native GetPlayer3DTextLabelVirtualW(playerid, PlayerText3D:textid);

/**
 * <library>omp_textlabel</library>
 */
#if __namemax > 31
	native GetPlayer3DTextLabelVirtualWorld(playerid, PlayerText3D:textid) = GetPlayer3DTextLabelVirtualW;
#endif

/**
 * <library>omp_textlabel</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#if __namemax > 31
		#pragma deprecated Use `GetPlayer3DTextLabelAttachedData`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
	#endif
#endif
native bool:GetPlayer3DTextLabelAttached(playerid, PlayerText3D:textid, &parentPlayerid, &parentVehicleid);

/**
 * <library>omp_textlabel</library>
 */
#if __namemax > 31
	native bool:GetPlayer3DTextLabelAttachedData(playerid, PlayerText3D:textid, &parentPlayerid, &parentVehicleid) = GetPlayer3DTextLabelAttached;
#endif
