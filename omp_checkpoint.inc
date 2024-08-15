#if defined _INC_omp_checkpoint
	#endinput
#endif
#define _INC_omp_checkpoint

/**
 * <library name="omp_checkpoint" summary="open.mp checkpoint functions.">
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

/// <p/>
/**
 * <library>omp_checkpoint</library>
 */
#define CP_TYPE: __TAG(CP_TYPE):
enum CP_TYPE:__CP_TYPE
{
	UNKNOWN_CP_TYPE                            = -1,
	CP_TYPE_GROUND_NORMAL                      = 0,
	CP_TYPE_GROUND_FINISH                      = 1,
	CP_TYPE_GROUND_EMPTY                       = 2,
	CP_TYPE_AIR_NORMAL                         = 3,
	CP_TYPE_AIR_FINISH                         = 4,
	CP_TYPE_AIR_ROTATING                       = 5,
	CP_TYPE_AIR_STROBING                       = 6,
	CP_TYPE_AIR_SWINGING                       = 7,
	CP_TYPE_AIR_BOBBING                        = 8
}
static stock CP_TYPE:_@CP_TYPE() { return __CP_TYPE; }

#define UNKNOWN_CP_TYPE                        (CP_TYPE:-1)
#define CP_TYPE_GROUND_NORMAL                  (CP_TYPE:0)
#define CP_TYPE_GROUND_FINISH                  (CP_TYPE:1)
#define CP_TYPE_GROUND_EMPTY                   (CP_TYPE:2)
#define CP_TYPE_AIR_NORMAL                     (CP_TYPE:3)
#define CP_TYPE_AIR_FINISH                     (CP_TYPE:4)
#define CP_TYPE_AIR_ROTATING                   (CP_TYPE:5)
#define CP_TYPE_AIR_STROBING                   (CP_TYPE:6)
#define CP_TYPE_AIR_SWINGING                   (CP_TYPE:7)
#define CP_TYPE_AIR_BOBBING                    (CP_TYPE:8)

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
native # Player Checkpoints();
native       Player Checkpoints(
native      ====================(
native
*/

/**
 * <library>omp_checkpoint</library>
 * <summary>Sets a checkpoint (red cylinder) for a player.  Also shows a red blip on the radar.  When
 * players enter a checkpoint, <a href="#OnPlayerEnterCheckpoint">OnPlayerEnterCheckpoint</a> is called
 * and actions can be performed.</summary>
 * <param name="playerid">The ID of the player for whom to set a checkpoint</param>
 * <param name="centreX">The x coordinate to set the checkpoint at</param>
 * <param name="centreY">The y coordinate to set the checkpoint at</param>
 * <param name="centreZ">The z coordinate to set the checkpoint at</param>
 * <param name="radius">The radius of the checkpoint</param>
 * <remarks>
 *   If a checkpoint is already set it will use the radius of that checkpoint instead of the new one.<br
 * />
 *   Checkpoints created on server-created objects (<a href="#CreateObject">CreateObject</a>/
 * <a href="#CreatePlayerObject">CreatePlayerObject</a>)
 * will appear down on the 'real' ground, but will still function correctly.  A pickup can be used instead.
 * </remarks>
 * <remarks>Checkpoints are asynchronous, meaning only one can be shown at a time.  To 'stream' checkpoints
 * (only show them when players are close enough), use a checkpoint streamer.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerCheckpoint(playerid, Float:centreX, Float:centreY, Float:centreZ, Float:radius);

/**
 * <library>omp_checkpoint</library>
 * <summary>Disables (hides/destroys) a player's set checkpoint.  Players can only have a single checkpoint
 * set at a time.  Checkpoints don't need to be disabled before setting another one.</summary>
 * <param name="playerid">The ID of the player whose checkpoint to disable</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is also returned if the player doesn't
 * have a checkpoint shown already.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:DisablePlayerCheckpoint(playerid);

/**
 * <library>omp_checkpoint</library>
 * <summary>Check if the player is currently inside a checkpoint, this could be used for properties
 * or teleport points for example.</summary>
 * <param name="playerid">The player you want to know the status of</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns><b><c>0</c></b> if player isn't in his checkpoint else <b><c>1</c></b>.</returns>
 */
native bool:IsPlayerInCheckpoint(playerid);

/**
 * <library>omp_checkpoint</library>
 * <summary>Check if the player currently has a checkpoint visible.</summary>
 * <param name="playerid">The player you want to know the status of</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns><b><c>0</c></b> if there is no checkpoint currently shown else <b><c>1</c></b>.</returns>
 */
native bool:IsPlayerCheckpointActive(playerid);

/**
 * <library>omp_checkpoint</library>
 * <summary>Get the location of the current checkpoint.</summary>
 * <param name="playerid">The player you want to get the checkpoint for</param>
 * <param name="centreX">Return for the x coordinate of the checkpoint</param>
 * <param name="centreY">Return for the y coordinate of the checkpoint</param>
 * <param name="centreZ">Return for the z coordinate of the checkpoint</param>
 * <param name="radius">The radius of the checkpoint</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns><b><c>0</c></b> if the player isn't connected else <b><c>1</c></b>.</returns>
 */
native bool:GetPlayerCheckpoint(playerid, &Float:centreX = 0.0, &Float:centreY = 0.0, &Float:centreZ = 0.0, &Float:radius = 0.0);

/*
native # Race Checkpoints();
native        Race Checkpoints(
native      ====================(
native
*/

/**
 * <library>omp_checkpoint</library>
 * <summary>Creates a race checkpoint.  When the player enters it, the <a href="#OnPlayerEnterRaceCheckpoint">OnPlayerEnterRaceCheckpoint</a>
 * callback is called.</summary>
 * <param name="playerid">The ID of the player to set the checkpoint for</param>
 * <param name="type">Type of checkpoint. <b><c>0</c></b>-Normal, <b><c>1</c></b>-Finish, <b><c>2</c></b>-Nothing(Only
 * the checkpoint without anything on it), <b><c>3</c></b>-Air normal, <b><c>4</c></b>-Air finish, <b><c>5</c></b>-Air
 * (rotates and stops), <b><c>6</c></b>-Air (increases, decreases and disappears), <b><c>7</c></b>-Air
 * (swings down and up), <b><c>8</c></b>-Air (swings up and down)</param>
 * <param name="centreX">x-Coordinate</param>
 * <param name="centreY">y-Coordinate</param>
 * <param name="centreZ">z-Coordinate</param>
 * <param name="nextX">x-Coordinate of the next point, for the arrow facing direction</param>
 * <param name="nextY">y-Coordinate of the next point, for the arrow facing direction</param>
 * <param name="nextZ">z-Coordinate of the next point, for the arrow facing direction</param>
 * <param name="radius">Radius of the checkpoint</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <remarks>If a race checkpoint is already set it will use the radius of that checkpoint instead of the
 * new one. </remarks>
 * <remarks>
 *   Race checkpoints created on server-created objects (<a href="#CreateObject">CreateObject</a>/<a
 * href="#CreatePlayerObject">CreatePlayerObject</a>) will appear down on the 'real' ground, but will
 * still function correctly.<br />
 *   Race checkpoints are asynchronous, meaning only one can be shown at a time.  To 'stream' race checkpoints
 * (only show them when players are close enough), use a race checkpoint streamer.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerRaceCheckpoint(playerid, CP_TYPE:type, Float:centreX, Float:centreY, Float:centreZ, Float:nextX, Float:nextY, Float:nextZ, Float:radius);

/**
 * <library>omp_checkpoint</library>
 * <summary>Disable any initialized race checkpoints for a specific player, since you can only have
 * one at any given time.</summary>
 * <param name="playerid">The player to disable the current checkpoint for</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 */
native bool:DisablePlayerRaceCheckpoint(playerid);

/**
 * <library>omp_checkpoint</library>
 * <summary>Check if the player is inside their current set race checkpoint
 * (<a href="#SetPlayerRaceCheckpoint">SetPlayerRaceCheckpoint</a>).</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns><b><c>1</c></b> is the player is in a race checkpoint, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerInRaceCheckpoint(playerid);

/**
 * <library>omp_checkpoint</library>
 * <summary>Check if the player currently has a race checkpoint visible.</summary>
 * <param name="playerid">The player you want to know the status of</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns><b><c>0</c></b> if there is no checkpoint currently shown else <b><c>1</c></b>.</returns>
 */
native bool:IsPlayerRaceCheckpointActive(playerid);

/**
 * <library>omp_checkpoint</library>
 * <summary>Get the location of the current race checkpoint.</summary>
 * <param name="playerid">The player you want to get the checkpoint for</param>
 * <param name="centreX">Return for the x coordinate of the checkpoint</param>
 * <param name="centreY">Return for the y coordinate of the checkpoint</param>
 * <param name="centreZ">Return for the z coordinate of the checkpoint</param>
 * <param name="nextX">x-Coordinate of the next point, for the arrow facing direction</param>
 * <param name="nextY">y-Coordinate of the next point, for the arrow facing direction</param>
 * <param name="nextZ">z-Coordinate of the next point, for the arrow facing direction</param>
 * <param name="radius">The radius of the checkpoint</param>
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <returns><b><c>0</c></b> if the player isn't connected else <b><c>1</c></b>.</returns>
 */
native bool:GetPlayerRaceCheckpoint(playerid, &Float:centreX = 0.0, &Float:centreY = 0.0, &Float:centreZ = 0.0, &Float:nextX = 0.0, &Float:nextY = 0.0, &Float:nextZ = 0.0, &Float:radius = 0.0);

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
 * <summary>This callback is called when a player enters the checkpoint set for that player.</summary>
 * <param name="playerid">The player who entered the checkpoint</param>
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerEnterCheckpoint(playerid);

/**
 * <summary>This callback is called when a player leaves the checkpoint set for them by
 * <a href="#SetPlayerCheckpoint">SetPlayerCheckpoint</a>.
 *  Only one checkpoint can be set at a time.</summary>
 * <param name="playerid">The ID of the player that left their checkpoint</param>
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerLeaveCheckpoint(playerid);

/**
 * <summary>This callback is called when a player enters a race checkpoint.</summary>
 * <param name="playerid">The ID of the player who entered the race checkpoint</param>
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerLeaveRaceCheckpoint" />
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerEnterRaceCheckpoint(playerid);

/**
 * <summary>This callback is called when a player leaves the race checkpoint.</summary>
 * <param name="playerid">The ID of the player that left the race checkpoint</param>
 * <seealso name="OnPlayerEnterCheckpoint" />
 * <seealso name="OnPlayerLeaveCheckpoint" />
 * <seealso name="OnPlayerEnterRaceCheckpoint" />
 * <seealso name="SetPlayerCheckpoint" />
 * <seealso name="DisablePlayerCheckpoint" />
 * <seealso name="IsPlayerInCheckpoint" />
 * <seealso name="SetPlayerRaceCheckpoint" />
 * <seealso name="DisablePlayerRaceCheckpoint" />
 * <seealso name="IsPlayerInRaceCheckpoint" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerLeaveRaceCheckpoint(playerid);
