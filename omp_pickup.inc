#if defined _INC_omp_pickup
	#endinput
#endif
#define _INC_omp_pickup

/**
 * <library name="omp_pickup" summary="open.mp pickup functions.">
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
 * <library>omp_pickup</library>
 */
#if defined MAX_PICKUPS
	#if MAX_PICKUPS < 1 || MAX_PICKUPS > 4096
		#error MAX_PICKUPS must be >= 1 and <= 4096
	#endif

	const __MAX_PICKUPS                        = MAX_PICKUPS;
	#define __MAX_PICKUPS
#else
	const MAX_PICKUPS                          = 4096;
	#define MAX_PICKUPS                        4096
#endif

/**
 * <library>omp_pickup</library>
 */
const INVALID_PICKUP                           = -1;
#define INVALID_PICKUP                         (-1)

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
 * <library>omp_pickup</library>
 * <summary>This function adds a 'static' pickup to the game.  These pickups support weapons, health,
 * armor etc., with the ability to function without scripting them (weapons/health/armor will be given
 * automatically).</summary>
 * <param name="model">The model of the pickup</param>
 * <param name="type">The pickup type.  Determines how the pickup responds when picked up</param>
 * <param name="x">The x coordinate to create the pickup at</param>
 * <param name="y">The y coordinate to create the pickup at</param>
 * <param name="z">The z coordinate to create the pickup at</param>
 * <param name="virtualWorld">The virtual world ID to put the pickup in.  Use -1 to show the pickup
 * in all worlds</param>
 * <returns>
 *   <b><c>1</c></b> if the pickup is successfully created.
 *   <br />
 *   <b><c>0</c></b> if failed to create.
 * </returns>
 * <remarks>This function doesn't return a pickup ID that you can use in, for example,
 * <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.
 *  Use <a href="#CreatePickup">CreatePickup</a> if you'd like to assign IDs.</remarks>
 * <seealso name="CreatePickup" />
 * <seealso name="DestroyPickup" />
 * <seealso name="OnPlayerPickUpPickup" />
 */
native AddStaticPickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0);

/**
 * <library>omp_pickup</library>
 * <summary>This function does exactly the same as AddStaticPickup, except it returns a pickup ID which
 * can be used to destroy it afterwards and be tracked using <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</summary>
 * <param name="model">The <a href="https://open.mp/docs/scripting/resources/pickupids">model</a> of the pickup</param>
 * <param name="type">The pickup spawn type (see table under remarks)</param>
 * <param name="x">The x coordinate to create the pickup at</param>
 * <param name="y">The y coordinate to create the pickup at</param>
 * <param name="z">The z coordinate to create the pickup at</param>
 * <param name="virtualWorld">The virtual world ID of the pickup.  Use <b><c>-1</c></b> to make the
 * pickup show in all worlds (optional=<b><c>0</c></b>)</param>
 * <seealso name="AddStaticPickup" />
 * <seealso name="DestroyPickup" />
 * <seealso name="OnPlayerPickUpPickup" />
 * <remarks>
 *   <b>Known Bugs:</b><br />
 *   Pickups that have a x or y lower than <b><c>-4096.0</c></b> or bigger than <b><c>4096.0</c></b>
 * won't show up and won't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a> either.
 * </remarks>
 * <remarks>
 *   The only type of pickup that can be picked up from inside a vehicle is <b><c>14</c></b> (except
 * for special pickups such as bribes).<br />
 *   Pickups are shown to, and can be picked up by all players.<br />
 *   It is possible that if <a href="#DestroyPickup">DestroyPickup</a> is used when a pickup is picked
 * up, more than one player can pick up the pickup, due to lag.  This can be circumvented through the
 * use of variables.<br />
 *   Certain pickup types come with 'automatic responses', for example using an M4 model in the pickup
 * will automatically give the player the weapon and some ammo.  For fully scripted pickups, type <b><c>1</c></b>
 * should be used. <br />
 * </remarks>
 * <remarks>
 *   <b>Available Pickup Types</b><br />
 *   Most other IDs are either undocumented or are similar to type <b><c>1</c></b> (but do not use them
 * just because they seem similar to ID <b><c>1</c></b>, they might have side-effects like ID <b><c>18</c></b>
 * and <b><c>20</c></b>).
 *   <ul>
 *     <li><b><c>0</c></b> - The pickup does not always display.  If displayed, it can't be picked up
 * and does not trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a> and it will stay after
 * server shutdown.  Now disabled.</li>
 *     <li><b><c>1</c></b> - Exists always.  Disables pickup scripts such as horseshoes and oysters
 * to allow for scripted actions ONLY.  Will trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>
 * every few seconds.</li>
 *     <li><b><c>2</c></b> - Disappears after pickup, respawns after 30 seconds if the player is at
 * a distance of at least 15 meters.</li>
 *     <li><b><c>3</c></b> - Disappears after pickup, respawns after death.</li>
 *     <li><b><c>4</c></b> - Disappears after 15 to 20 seconds.  Respawns after death.</li>
 *     <li><b><c>8</c></b> - Disappears after pickup, but has no effect.</li>
 *     <li><b><c>11</c></b> - Blows up a few seconds after being created (bombs?)</li>
 *     <li><b><c>12</c></b> - Blows up a few seconds after being created.</li>
 *     <li><b><c>13</c></b> - Invisible.  Triggers checkpoint sound when picked up with a vehicle, but
 * doesn't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</li>
 *     <li><b><c>14</c></b> - Disappears after pickup, can only be picked up with a vehicle.  Triggers
 * checkpoint sound.</li>
 *     <li><b><c>15</c></b> - Same as type <b><c>2</c></b>.</li>
 *     <li><b><c>18</c></b> - Similar to type <b><c>1</c></b>.  Pressing Tab (<b><c>KEY_ACTION</c></b>)
 * makes it disappear but the key press doesn't trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</li>
 *     <li><b><c>19</c></b> - Disappears after pickup, but doesn't respawn.  Makes "cash pickup" sound
 * if picked up.</li>
 *     <li><b><c>20</c></b> - Similar to type <b><c>1</c></b>.  Disappears when you take a picture of
 * it with the Camera weapon, which triggers "Snapshot # out of 0" message.  Taking a picture doesn't
 * trigger <a href="#OnPlayerPickUpPickup">OnPlayerPickUpPickup</a>.</li>
 *     <li><b><c>22</c></b> - Same as type <b><c>3</c></b>.</li>
 *   </ul>
 * </remarks>
 * <returns>The ID of the created pickup, <b><c>-1</c></b> on failure (<a href="https://open.mp/docs/scripting/resources/limits">pickup
 * max limit</a>).</returns>
 */
native CreatePickup(model, type, Float:x, Float:y, Float:z, virtualWorld = 0);

/**
 * <library>omp_pickup</library>
 * <summary>Destroys a pickup created with <a href="#CreatePickup">CreatePickup</a>.</summary>
 * <param name="pickup">The ID of the pickup to destroy (returned by <a href="#CreatePickup">CreatePickup</a>)</param>
 * <seealso name="CreatePickup" />
 * <seealso name="OnPlayerPickUpPickup" />
 */
native bool:DestroyPickup(pickup);

/**
 * <library>omp_pickup</library>
 */
native bool:IsValidPickup(pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:IsPickupStreamedIn(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:GetPickupPos(pickupid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_pickup</library>
 */
native GetPickupModel(pickupid);

/**
 * <library>omp_pickup</library>
 */
native GetPickupType(pickupid);

/**
 * <library>omp_pickup</library>
 */
native GetPickupVirtualWorld(pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPickupPos(pickupid, Float:x, Float:y, Float:z, bool:update = true);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPickupModel(pickupid, model, bool:update = true);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPickupType(pickupid, type, bool:update = true);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPickupVirtualWorld(pickupid, virtualWorld);

/**
 * <library>omp_pickup</library>
 */
native bool:ShowPickupForPlayer(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:HidePickupForPlayer(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:IsPickupHiddenForPlayer(playerid, pickupid);

/*
native # Per-Player();
native           Per-Player(
native      ====================(
native
*/

/**
 * <library>omp_pickup</library>
 */
native CreatePlayerPickup(playerid, model, type, Float:x, Float:y, Float:z, virtualWorld = 0);

/**
 * <library>omp_pickup</library>
 */
native bool:DestroyPlayerPickup(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:IsValidPlayerPickup(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:IsPlayerPickupStreamedIn(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native bool:GetPlayerPickupPos(playerid, pickupid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPlayerPickupPos(playerid, pickupid, Float:x, Float:y, Float:z, bool:update = true);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPlayerPickupModel(playerid, pickupid, model, bool:update = true);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPlayerPickupType(playerid, pickupid, type, bool:update = true);

/**
 * <library>omp_pickup</library>
 */
native bool:SetPlayerPickupVirtualWorld(playerid, pickupid, virtualWorld);

/**
 * <library>omp_pickup</library>
 */
native GetPlayerPickupModel(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native GetPlayerPickupType(playerid, pickupid);

/**
 * <library>omp_pickup</library>
 */
native GetPlayerPickupVirtualWorld(playerid, pickupid);

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
 * <summary>Called when a player picks up a pickup created with <a href="#CreatePickup">CreatePickup</a>.</summary>
 * <param name="playerid">The ID of the player that picked up the pickup</param>
 * <param name="pickupid">The ID of the pickup, returned by CreatePickup</param>
 * <seealso name="CreatePickup" />
 * <seealso name="DestroyPickup" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerPickUpPickup(playerid, pickupid);

/**
 * <summary>Called when a player picks up a pickup created with <a href="#CreatePickup">CreatePlayerPickup</a>.</summary>
 * <param name="playerid">The ID of the player that picked up the pickup</param>
 * <param name="pickupid">The ID of the pickup, returned by CreatePlayerPickup</param>
 * <seealso name="CreatePlayerPickup" />
 * <seealso name="DestroyPlayerPickup" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerPickUpPlayerPickup(playerid, pickupid);

/**
 * <summary>Called when a pickup enters the visual range of a player.</summary>
 * <param name="playerid">The ID of the player that picked up the pickup</param>
 * <param name="pickupid">The ID of the pickup, returned by CreatePickup</param>
 * <seealso name="CreatePickup" />
 * <seealso name="DestroyPickup" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPickupStreamIn(pickupid, playerid);

/**
 * <summary>Called when a pickup leaves the visual range of a player.</summary>
 * <param name="playerid">The ID of the player that picked up the pickup</param>
 * <param name="pickupid">The ID of the pickup, returned by CreatePickup</param>
 * <seealso name="CreatePickup" />
 * <seealso name="DestroyPickup" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPickupStreamOut(pickupid, playerid);

/**
 * <summary>Called when a pickup enters the visual range of a player.</summary>
 * <param name="playerid">The ID of the player that picked up the pickup</param>
 * <param name="pickupid">The ID of the pickup, returned by CreatePickup</param>
 * <seealso name="CreatePickup" />
 * <seealso name="DestroyPickup" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerPickupStreamIn(pickupid, playerid);

/**
 * <summary>Called when a pickup leaves the visual range of a player.</summary>
 * <param name="playerid">The ID of the player that picked up the pickup</param>
 * <param name="pickupid">The ID of the pickup, returned by CreatePickup</param>
 * <seealso name="CreatePickup" />
 * <seealso name="DestroyPickup" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerPickupStreamOut(pickupid, playerid);
