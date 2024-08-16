#if defined _INC_omp_gangzone
	#endinput
#endif
#define _INC_omp_gangzone

/**
 * <library name="omp_gangzone" summary="open.mp text draw functions.">
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
 * <library>omp_gangzone</library>
 */
#if defined MAX_GANG_ZONES
	#if MAX_GANG_ZONES < 1 || MAX_GANG_ZONES > 1024
		#error MAX_GANG_ZONES must be >= 1 and <= 1024
	#endif

	const __MAX_GANG_ZONES                     = MAX_GANG_ZONES;
	#define __MAX_GANG_ZONES
#else
	const MAX_GANG_ZONES                       = 1024;
	#define MAX_GANG_ZONES                     1024
#endif

/**
 * <library>omp_gangzone</library>
 */
const INVALID_GANG_ZONE                        = 0xFFFFFFFF;
#define INVALID_GANG_ZONE                      -1

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
 * <library>omp_gangzone</library>
 * <summary>Create a gangzone (coloured radar area).</summary>
 * <param name="minX">The x coordinate for the west side of the gangzone</param>
 * <param name="minY">The y coordinate for the south side of the gangzone</param>
 * <param name="maxX">The x coordinate for the east side of the gangzone</param>
 * <param name="maxY">The y coordinate for the north side of the gangzone</param>
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 * <remarks>
 *   There is a limit of <b><c>1024</c></b> gangzones.<br />
 *   Putting the parameters in the wrong order results in glitchy behavior.
 * </remarks>
 * <remarks>This function merely CREATES the gangzone, you must use <a href="#GangZoneShowForPlayer">GangZoneShowForPlayer</a>
 * or <a href="#GangZoneShowForAll">GangZoneShowForAll</a> to show it.</remarks>
 * <returns>The ID of the created zone, returns <b><c>-1</c></b> if not created.</returns>
 */
native GangZoneCreate(Float:minX, Float:minY, Float:maxX, Float:maxY);

/**
 * <library>omp_gangzone</library>
 * <summary>Destroy a gangzone.</summary>
 * <param name="zoneid">The ID of the zone to destroy</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 */
native bool:GangZoneDestroy(zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Show a gangzone for a player.  Must be created with <a href="#GangZoneCreate">GangZoneCreate</a>
 * first.</summary>
 * <param name="playerid">The ID of the player you would like to show the gangzone for.</param>
 * <param name="zoneid">The ID of the gang zone to show for the player.  Returned by <a href="#GangZoneCreate">GangZoneCreate</a></param>
 * <param name="colour">The colour to show the gang zone, as an integer or hex in <b>RGBA</b> colour
 * format.  Alpha transparency supported</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 * <returns><b><c>1</c></b> if the gangzone was shown, otherwise <b><c>0</c></b> (non-existant).</returns>
 */
native bool:GangZoneShowForPlayer(playerid, zoneid, colour);

/**
 * <library>omp_gangzone</library>
 * <summary>Shows a gangzone with the desired colour to all players.</summary>
 * <param name="zoneid">The ID of the gangzone to show (returned by <a href="# GangZoneCreate">GangZoneCreate</a>)</param>
 * <param name="colour">The colour to show the gang zone, as an integer or hex in <b>RGBA</b> colour
 * format.  Alpha transparency supported</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  The gang zone was shown for all players.<br
 * />
 *   <b><c>0</c></b>: The function failed to execute.  The gangzone does not exist.
 * </returns>
 */
native bool:GangZoneShowForAll(zoneid, colour);

/**
 * <library>omp_gangzone</library>
 * <summary>Hides a gangzone for a player.</summary>
 * <param name="playerid">The ID of the player to hide the gangzone for</param>
 * <param name="zoneid">The ID of the zone to hide</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 */
native bool:GangZoneHideForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>GangZoneHideForAll hides a gangzone from all players.</summary>
 * <param name="zoneid">The zone to hide</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 */
native bool:GangZoneHideForAll(zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Makes a gangzone flash for a player.</summary>
 * <param name="playerid">The ID of the player to flash the gangzone for</param>
 * <param name="zoneid">The ID of the zone to flash</param>
 * <param name="flashColour">The colour to flash the gang zone, as an integer or hex in <b>RGBA</b>
 * colour format.  Alpha transparency supported</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 */
native bool:GangZoneFlashForPlayer(playerid, zoneid, flashColour);

/**
 * <library>omp_gangzone</library>
 * <summary>GangZoneFlashForAll flashes a gangzone for all players.</summary>
 * <param name="zoneid">The zone to flash</param>
 * <param name="flashColour">The colour to flash the gang zone, as an integer or hex in <b>RGBA</b>
 * colour format.  Alpha transparency supported</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <seealso name="GangZoneStopFlashForAll" />
 */
native bool:GangZoneFlashForAll(zoneid, flashColour);

/**
 * <library>omp_gangzone</library>
 * <summary>Stops a gangzone flashing for a player.</summary>
 * <param name="playerid">The ID of the player to stop the gangzone flashing for</param>
 * <param name="zoneid">The ID of the gangzonezone to stop flashing</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForAll" />
 */
native bool:GangZoneStopFlashForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Stops a gangzone flashing for all players.</summary>
 * <param name="zoneid">The ID of the zone to stop flashing.  Returned by <a href="#GangZoneCreate">GangZoneCreate</a></param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is reported even if the gang zone
 * wasn't flashing to begin with.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The gangzone specified does not exist.
 * </returns>
 */
native bool:GangZoneStopFlashForAll(zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the gangzone valid.</summary>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The gangzone is valid.
 *   <b><c>0</c></b>: The gangzone is not valid.
 * </returns>
 */
native bool:IsValidGangZone(zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the player in gangzone.</summary>
 * <param name="playerid">The ID of the player to check if he is in a gangzone</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The player is in gangzone.
 *   <b><c>0</c></b>: The player is not in gangzone.
 * </returns>
 */
native bool:IsPlayerInGangZone(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the gangzone is visible for player.</summary>
 * <param name="playerid">The ID of the player to check for</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The gangzone is visible for player.
 *   <b><c>0</c></b>: The gangzone is not visible for player.
 * </returns>
 */
native bool:IsGangZoneVisibleForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the colour of a gangzone for player.</summary>
 * <param name="playerid">The ID of the player you need to get</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>Color of gangzone for player. <b><c>0</c></b>: Failed to execute the function. The gangzone is not showned for the player.</returns>
 */
native GangZoneGetColourForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the colour of a gangzone for player.</summary>
 * <param name="playerid">The ID of the player you need to get</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>Color of gangzone for player. <b><c>0</c></b>: Failed to execute the function. The gangzone is not showned for the player.</returns>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `GangZoneGetColourForPlayer`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native GangZoneGetColorForPlayer(playerid, zoneid) = GangZoneGetColourForPlayer;

/**
 * <library>omp_gangzone</library>
 * <summary>Get the flashing colour of a gangzone for player.</summary>
 * <param name="playerid">The ID of the player you need to get</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>Flashing color of gangzone for player. <b><c>0</c></b>: Failed to execute the function. The gangzone is not showned for the player.</returns>
 */
native GangZoneGetFlashColourForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the flashing colour of a gangzone for player.</summary>
 * <param name="playerid">The ID of the player you need to get</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>Flashing color of gangzone for player. <b><c>0</c></b>: Failed to execute the function. The gangzone is not showned for the player.</returns>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `GangZoneGetFlashColourForPlayer`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native GangZoneGetFlashColorForPlayer(playerid, zoneid) = GangZoneGetFlashColourForPlayer;

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the gangzone is flashing for player.</summary>
 * <param name="playerid">The ID of the player to be checked</param>
 * <param name="zoneid">The ID of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The gangzone is flashing for player.
 *   <b><c>0</c></b>: The gangzone is not flashing for player.
 * </returns>
 */
native bool:IsGangZoneFlashingForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the position of a gangzone, represented by minX, minY, maxX, maxY coordinates.</summary>
 * <param name="zoneid">The ID of the zone to the coordinates of which want to get</param>
 * <param name="minX">The X coordinate for the west side of the gangzone</param>
 * <param name="minY">The Y coordinate for the south side of the gangzone</param>
 * <param name="maxX">The X coordinate for the east side of the gangzone</param>
 * <param name="maxY">The Y coordinate for the north side of the gangzone</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native bool:GangZoneGetPos(zoneid, &Float:minX, &Float:minY, &Float:maxX, &Float:maxY);

/**
 * <library>omp_gangzone</library>
 * <summary>Enables the callback when a player enters this zone.</summary>
 * <param name="zoneid">The ID of the zone to enable area detection for</param>
 * <param name="enable">Should entry detection be started or stopped?</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="GangZoneShowForPlayer" />
 * <seealso name="GangZoneShowForAll" />
 * <seealso name="GangZoneHideForPlayer" />
 * <seealso name="GangZoneHideForAll" />
 * <seealso name="GangZoneFlashForPlayer" />
 * <seealso name="GangZoneFlashForAll" />
 * <seealso name="GangZoneStopFlashForPlayer" />
 */
native bool:UseGangZoneCheck(zoneid, bool:enable);

/*
native # Per-Player();
native           Per-Player(
native      ====================(
native
*/

/**
 * <library>omp_gangzone</library>
 * <summary>Create player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom the player gangzone will be created</param>
 * <param name="minX">The X coordinate for the west side of the player gangzone</param>
 * <param name="minY">The Y coordinate for the south side of the player gangzone</param>
 * <param name="maxX">The X coordinate for the east side of the player gangzone</param>
 * <param name="maxY">The Y coordinate for the north side of the player gangzone</param>
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <remarks>
 *   There is a limit of <b><c>1024</c></b> player gangzones.<br />
 *   Putting the parameters in the wrong order results in glitchy behavior.
 * </remarks>
 * <returns>The ID of the created player gangzone, returns <b><c>-1</c></b> if not created.</returns>
 */
native CreatePlayerGangZone(playerid, Float:minx, Float:miny, Float:maxx, Float:maxy);

/**
 * <library>omp_gangzone</library>
 * <summary>Destroy player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone for destroy</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.
 *   <b><c>0</c></b>: The function failed to execute. The gangzone specified does not exist.
 * </returns>
 */
native bool:PlayerGangZoneDestroy(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Show player gangzone in a color.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone for in show</param>
 * <param name="colour">The color by which the player gangzone will be shown</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully. Success is reported even if the gangzone
 * was show to begin with.<br />
 *   <b><c>0</c></b>: The function failed to execute. The gangzone specified does not exist.
 * </returns>
 */
native bool:PlayerGangZoneShow(playerid, zoneid, colour);

/**
 * <library>omp_gangzone</library>
 * <summary>Hide player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone for in hide</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully. Success is reported even if the player gangzone
 * was hide to begin with.<br />
 *   <b><c>0</c></b>: The function failed to execute. The gangzone specified does not exist.
 * </returns>
 */
native bool:PlayerGangZoneHide(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Start player gangzone flash.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone for in start flashing</param>
 * <param name="flashColour">The colour by which the player gangzone will be flashing</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully. Success is reported even if the player gangzone
 * was flashing to begin with.<br />
 *   <b><c>0</c></b>: The function failed to execute. The gangzone specified does not exist.
 * </returns>
 */
native bool:PlayerGangZoneFlash(playerid, zoneid, flashColour);

/**
 * <library>omp_gangzone</library>
 * <summary>Stop player gangzone flash.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone for in stop flashing</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully. Success is reported even if the player gangzone
 * wasn't flashing to begin with.<br />
 *   <b><c>0</c></b>: The function failed to execute. The gangzone specified does not exist.
 * </returns>
 */
native bool:PlayerGangZoneStopFlash(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the player gangzone valid.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The player gangzone is valid.
 *   <b><c>0</c></b>: The player gangzone is not valid.
 * </returns>
 */
native bool:IsValidPlayerGangZone(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the player in player gangzone.</summary>
 * <param name="playerid">The ID of the check if the player in player gangzone</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The player is in player gangzone.
 *   <b><c>0</c></b>: The player is not in player gangzone.
 * </returns>
 */
native bool:IsPlayerInPlayerGangZone(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the player gangzone is visible.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The player gangzone is visible.
 *   <b><c>0</c></b>: The player gangzone is not visible.
 * </returns>
 */
native bool:IsPlayerGangZoneVisible(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the colour of a player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>Color of player gangzone. <b><c>0</c></b>: Failed to execute the function. The player gangzone is not showned for the player.</returns>
 */
native PlayerGangZoneGetColour(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the colour of a player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>Color of player gangzone. <b><c>0</c></b>: Failed to execute the function. The player gangzone is not showned for the player.</returns>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerGangZoneGetColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native PlayerGangZoneGetColor(playerid, zoneid) = PlayerGangZoneGetColour;

/**
 * <library>omp_gangzone</library>
 * <summary>Get the flashing colour of a player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>Flashing color of player gangzone. <b><c>0</c></b>: Failed to execute the function. The player gangzone is not showned for the player.</returns>
 */
native PlayerGangZoneGetFlashColour(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the flashing colour of a player gangzone.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>Flashing color of player gangzone. <b><c>0</c></b>: Failed to execute the function. The player gangzone is not showned for the player.</returns>
 */
#if !defined MIXED_SPELLINGS
	#pragma deprecated Use `PlayerGangZoneGetFlashColour`. To silence this warning and use different spellings define `MIXED_SPELLINGS` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native PlayerGangZoneGetFlashColor(playerid, zoneid) = PlayerGangZoneGetFlashColour;

/**
 * <library>omp_gangzone</library>
 * <summary>Check if the player gangzone is flashing.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   <b><c>1</c></b>: The player gangzone is flashing.
 *   <b><c>0</c></b>: The player gangzone is not flashing.
 * </returns>
 */
native bool:IsPlayerGangZoneFlashing(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 * <summary>Get the position of a gangzone, represented by minX, minY, maxX, maxY coordinates.</summary>
 * <param name="playerid">The ID of the player to whom player gangzone is bound</param>
 * <param name="zoneid">The ID of the zone to the coordinates of which want to get</param>
 * <param name="minX">The X coordinate for the west side of the player gangzone</param>
 * <param name="minY">The Y coordinate for the south side of the player gangzone</param>
 * <param name="maxX">The X coordinate for the east side of the player gangzone</param>
 * <param name="maxY">The Y coordinate for the north side of the player gangzone</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native bool:PlayerGangZoneGetPos(playerid, zoneid, &Float:minX, &Float:minY, &Float:maxX, &Float:maxY);

/**
 * <library>omp_gangzone</library>
 * <summary>Enables the callback when a player enters this zone.</summary>
 * <param name="playerid">The ID of the player for whom you want to enable callback triggering when the player enters this zone</param>
 * <param name="zoneid">The ID of the zone to enable area detection for</param>
 * <param name="enable">Should entry detection be started or stopped?</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="PlayerGangZoneShow" />
 * <seealso name="PlayerGangZoneHide" />
 * <seealso name="PlayerGangZoneFlash" />
 * <seealso name="PlayerGangZoneStopFlash" />
 * <seealso name="PlayerGangZoneGetColour" />
 * <seealso name="PlayerGangZoneGetFlashColour" />
 * <seealso name="PlayerGangZoneGetPos" />
 * <seealso name="IsValidPlayerGangZone" />
 * <seealso name="IsPlayerInPlayerGangZone" />
 * <seealso name="IsPlayerGangZoneVisible" />
 * <seealso name="IsPlayerGangZoneFlashing" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.
 *   <b><c>0</c></b>: The function failed to execute.  The gangzone specified does not exist.
 * </returns>
 */
native bool:UsePlayerGangZoneCheck(playerid, zoneid, bool:enable);

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
 * <summary>This callback is called when a player enters a gangzone.</summary>
 * <param name="playerid">The ID of the player that entered the gangzone</param>
 * <param name="zoneid">The ID of the gangzone the player entered</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="UseGangZoneCheck" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerEnterGangZone(playerid, zoneid);

/**
 * <summary>This callback is called when a player exited a gangzone.</summary>
 * <param name="playerid">The ID of the player that exited the gangzone</param>
 * <param name="zoneid">The ID of the gangzone the player exited</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="UseGangZoneCheck" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerLeaveGangZone(playerid, zoneid);

/**
 * <summary>This callback is called when a player enters a player gangzone.</summary>
 * <param name="playerid">The ID of the player that entered the player gangzone</param>
 * <param name="zoneid">The ID of the player gangzone the player entered</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerEnterPlayerGangZone(playerid, zoneid);

/**
 * <summary>This callback is called when a player exited a player gangzone.</summary>
 * <param name="playerid">The ID of the player that exited the player gangzone</param>
 * <param name="zoneid">The ID of the player gangzone the player exited</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerLeavePlayerGangZone(playerid, zoneid);

/**
 * <summary>This callback is called when a player clicked a gangzone.</summary>
 * <param name="playerid">The ID of the player that clicked a gangzone</param>
 * <param name="zoneid">The ID of the gangzone the player clicked</param>
 * <seealso name="GangZoneCreate" />
 * <seealso name="GangZoneDestroy" />
 * <seealso name="UseGangZoneCheck" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerClickGangZone(playerid, zoneid);

/**
 * <summary>This callback is called when a player clicked a player gangzone.</summary>
 * <param name="playerid">The ID of the player that clicked a player gangzone</param>
 * <param name="zoneid">The ID of the player gangzone the player clicked</param>
 * <seealso name="CreatePlayerGangZone" />
 * <seealso name="PlayerGangZoneDestroy" />
 * <seealso name="UsePlayerGangZoneCheck" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerClickPlayerGangZone(playerid, zoneid);
