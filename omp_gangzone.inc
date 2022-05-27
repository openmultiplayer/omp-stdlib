#if defined _INC_omp_gangzone
	#endinput
#endif
#define _INC_omp_gangzone

/**
 * <library name="omp_gangzone" summary="open.mp text draw functions.">
 *   <license>
 *     (c) Copyright 2022, open.mp team.
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
#define INVALID_GANG_ZONE                      0xFFFFFFFF

#if MAX_GANG_ZONES < 1 || MAX_GANG_ZONES > 1024
	#error MAX_GANG_ZONES must be >= 1 and <= 1024
#endif

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
native GangZoneDestroy(zoneid);

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
native GangZoneShowForPlayer(playerid, zoneid, colour);

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
native GangZoneShowForAll(zoneid, colour);

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
native GangZoneHideForPlayer(playerid, zoneid);

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
native GangZoneHideForAll(zoneid);

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
native GangZoneFlashForPlayer(playerid, zoneid, flashColour);

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
native GangZoneFlashForAll(zoneid, flashColour);

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
native GangZoneStopFlashForPlayer(playerid, zoneid);

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
native GangZoneStopFlashForAll(zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsValidGangZone(zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsPlayerInGangZone(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsGangZoneVisibleForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
#pragma deprecated Use `GangZoneGetColourForPlayer`
native GangZoneGetColorForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
#pragma deprecated Use `GangZoneGetFlashColourForPlayer`
native GangZoneGetFlashColorForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native GangZoneGetColourForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native GangZoneGetFlashColourForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsGangZoneFlashingForPlayer(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native GangZoneGetPos(zoneid, &Float:minX, &Float:minY = 0.0, &Float:maxX = 0.0, &Float:maxY = 0.0);

/**
 * <library>omp_gangzone</library>
 * <summary>Enables the callback when a player enters this zone.</summary>
 * <param name="zoneid">The ID of the zone to enable area detection for</param>
 * <param name="enable">Should entry detection be started or stopped?</param>
 */
native UseGangZoneCheck(zoneid, bool:enable);

/**
 * <library>omp_gangzone</library>
 */
native CreatePlayerGangZone(playerid, Float:minx, Float:miny, Float:maxx, Float:maxy);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneDestroy(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneShow(playerid, zoneid, colour);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneHide(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneFlash(playerid, zoneid, flashColour);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneStopFlash(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsValidPlayerGangZone(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsPlayerInPlayerGangZone(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsPlayerGangZoneVisible(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
#pragma deprecated Use `PlayerGangZoneGetColour`
native PlayerGangZoneGetColor(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
#pragma deprecated Use `PlayerGangZoneGetFlashColour`
native PlayerGangZoneGetFlashColor(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneGetColour(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneGetFlashColour(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native IsPlayerGangZoneFlashing(playerid, zoneid);

/**
 * <library>omp_gangzone</library>
 */
native PlayerGangZoneGetPos(playerid, zoneid, &Float:minX, &Float:minY = 0.0, &Float:maxX = 0.0, &Float:maxY = 0.0);

/**
 * <library>omp_gangzone</library>
 * <summary>Enables the callback when a player enters this zone.</summary>
 * <param name="zoneid">The ID of the zone to enable area detection for</param>
 * <param name="enable">Should entry detection be started or stopped?</param>
 */
native UsePlayerGangZoneCheck(zoneid, bool:enable);

forward OnPlayerEnterGangZone(playerid, zoneid);

forward OnPlayerLeaveGangZone(playerid, zoneid);

forward OnPlayerEnterPlayerGangZone(playerid, zoneid);

forward OnPlayerLeavePlayerGangZone(playerid, zoneid);

forward OnPlayerClickGangZone(playerid, zoneid);

forward OnPlayerClickPlayerGangZone(playerid, zoneid);

