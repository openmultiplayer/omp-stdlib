#if defined _INC_omp_npc
	#endinput
#endif
#define _INC_omp_npc

/**
 * <library name="omp_npc" summary="open.mp NPC functions.">
 *   <license>
 *     This Source Code Form is subject to the terms of the Mozilla Public License,
 *     v. 2.0. If a copy of the MPL was not distributed with this file, You can
 *     obtain one at http://mozilla.org/MPL/2.0/.
 *
 *     The original code is copyright (c) 2022, open.mp team and contributors.
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
 * <library>omp_npc</library>
 */
#if defined MAX_NPCS
	#if MAX_NPCS < 1 || MAX_NPCS > 1000
		#error MAX_NPCS must be >= 1 and <= 1000
	#endif

	const __MAX_NPCS                           = MAX_NPCS;
	#define __MAX_NPCS
#else
	const MAX_NPCS                             = 1000;
	#define MAX_NPCS                           1000
#endif

/**
 * <library>omp_npc</library>
 */
const INVALID_NPC_ID                           = -1;
#define INVALID_NPC_ID                         (-1)

/**
 * <library>omp_npc</library>
 */
const INVALID_PATH_ID                          = -1;
#define INVALID_PATH_ID                        (-1)

/**
 * <library>omp_npc</library>
 */
const INVALID_NODE_ID                          = -1;
#define INVALID_NODE_ID                        (-1)

/**
 * <library>omp_npc</library>
 */
const INVALID_RECORD_ID                        = -1;
#define INVALID_RECORD_ID                      (-1)

/**
 * <library>omp_npc</library>
 */
const NPC_MAX_NODES                            = 64;
#define NPC_MAX_NODES                          64

/// <p/>
/**
 * <library>omp_npc</library>
 */
#define NPC_MOVE_TYPE: __TAG(NPC_MOVE_TYPE):
enum NPC_MOVE_TYPE:MAX_NPC_MOVE_TYPES
{
	UNKNOWN_NPC_MOVE_TYPE                      = -1,
	NPC_MOVE_TYPE_NONE                         = 0,
	NPC_MOVE_TYPE_WALK,
	NPC_MOVE_TYPE_JOG,
	NPC_MOVE_TYPE_SPRINT,
	NPC_MOVE_TYPE_DRIVE,
	NPC_MOVE_TYPE_AUTO
}
static stock NPC_MOVE_TYPE:_@NPC_MOVE_TYPE() { return MAX_NPC_MOVE_TYPES; }

#define UNKNOWN_NPC_MOVE_TYPE                  (NPC_MOVE_TYPE:-1)
#define NPC_MOVE_TYPE_NONE                     (NPC_MOVE_TYPE:0)
#define NPC_MOVE_TYPE_WALK                     (NPC_MOVE_TYPE:1)
#define NPC_MOVE_TYPE_JOG                      (NPC_MOVE_TYPE:2)
#define NPC_MOVE_TYPE_SPRINT                   (NPC_MOVE_TYPE:3)
#define NPC_MOVE_TYPE_DRIVE                    (NPC_MOVE_TYPE:4)
#define NPC_MOVE_TYPE_AUTO                     (NPC_MOVE_TYPE:5)

/// <p/>
/**
 * <library>omp_npc</library>
 */
#define NPC_ENTITY_CHECK: __TAG(NPC_ENTITY_CHECK):
enum NPC_ENTITY_CHECK:MAX_NPC_ENTITY_CHECK
{
	NPC_ENTITY_CHECK_NONE                      = 0,
	NPC_ENTITY_CHECK_PLAYER                    = 1,
	NPC_ENTITY_CHECK_NPC                       = 2,
	NPC_ENTITY_CHECK_ACTOR                     = 4,
	NPC_ENTITY_CHECK_VEHICLE                   = 8,
	NPC_ENTITY_CHECK_OBJECT                    = 16,
	NPC_ENTITY_CHECK_POBJECT_ORIG              = 32,
	NPC_ENTITY_CHECK_POBJECT_TARG              = 64,
	NPC_ENTITY_CHECK_MAP                       = 128,
	NPC_ENTITY_CHECK_ALL                       = 255
}
static stock NPC_ENTITY_CHECK:_@NPC_ENTITY_CHECK() { return MAX_NPC_ENTITY_CHECK; }

#define NPC_ENTITY_CHECK_NONE                  (NPC_ENTITY_CHECK:0)
#define NPC_ENTITY_CHECK_PLAYER                (NPC_ENTITY_CHECK:1)
#define NPC_ENTITY_CHECK_NPC                   (NPC_ENTITY_CHECK:2)
#define NPC_ENTITY_CHECK_ACTOR                 (NPC_ENTITY_CHECK:4)
#define NPC_ENTITY_CHECK_VEHICLE               (NPC_ENTITY_CHECK:8)
#define NPC_ENTITY_CHECK_OBJECT                (NPC_ENTITY_CHECK:16)
#define NPC_ENTITY_CHECK_POBJECT_ORIG          (NPC_ENTITY_CHECK:32)
#define NPC_ENTITY_CHECK_POBJECT_TARG          (NPC_ENTITY_CHECK:64)
#define NPC_ENTITY_CHECK_MAP                   (NPC_ENTITY_CHECK:128)
#define NPC_ENTITY_CHECK_ALL                   (NPC_ENTITY_CHECK:255)

/**
 * <library>omp_npc</library>
 */
const Float:NPC_MOVE_SPEED_AUTO                = -1.0;
const Float:NPC_MOVE_SPEED_WALK                = 0.1552086;
const Float:NPC_MOVE_SPEED_JOG                 = 0.56444;
const Float:NPC_MOVE_SPEED_SPRINT              = 0.926784;
#define NPC_MOVE_SPEED_AUTO                    (-1.0)
#define NPC_MOVE_SPEED_WALK                    (0.1552086)
#define NPC_MOVE_SPEED_JOG                     (0.56444)
#define NPC_MOVE_SPEED_SPRINT                  (0.926784)


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
native # Core();
native        Core(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 * <summary>Creates a new NPC with the specified name.</summary>
 * <param name="name">The name for the NPC (max 24 characters)</param>
 * <returns>The ID of the created NPC, or <b><c>INVALID_NPC_ID</c></b> on failure.</returns>
 * <seealso name="NPC_Destroy" />
 * <seealso name="NPC_Spawn" />
 * <seealso name="NPC_IsValid" />
 */
native NPC_Create(const name[]);

/**
 * <library>omp_npc</library>
 * <summary>Destroys an NPC.</summary>
 * <param name="npcid">The ID of the NPC to destroy</param>
 * <seealso name="NPC_Create" />
 * <seealso name="NPC_IsValid" />
 */
native NPC_Destroy(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Checks if an NPC ID is valid.</summary>
 * <param name="npcid">The NPC ID to check</param>
 * <returns>Returns true if the NPC is valid, false otherwise.</returns>
 * <seealso name="NPC_Create" />
 * <seealso name="NPC_IsDead" />
 */
native bool:NPC_IsValid(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Checks if an NPC is dead.</summary>
 * <param name="npcid">The ID of the NPC to check</param>
 * <returns>Returns true if the NPC is dead, false otherwise.</returns>
 * <seealso name="NPC_IsValid" />
 * <seealso name="NPC_Spawn" />
 */
native bool:NPC_IsDead(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Spawns an NPC into the game world.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <returns>Returns true if the NPC was spawned successfully, false otherwise.</returns>
 * <seealso name="NPC_Create" />
 * <seealso name="NPC_Respawn" />
 */
native NPC_Spawn(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Respawns an NPC.</summary>
 * <param name="npcid">The ID of the NPC to respawn</param>
 * <returns>Returns true if the NPC was respawned successfully, false otherwise.</returns>
 * <seealso name="NPC_Spawn" />
 * <seealso name="NPC_IsDead" />
 */
native NPC_Respawn(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Checks if an NPC is spawned in the game world.</summary>
 * <param name="npcid">The ID of the NPC to check</param>
 * <returns>Returns true if the NPC is spawned, false otherwise.</returns>
 * <seealso name="NPC_Spawn" />
 * <seealso name="NPC_Respawn" />
 * <seealso name="NPC_IsDead" />
 */
native bool:NPC_IsSpawned(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Gets all NPC IDs and stores them in an array.</summary>
 * <param name="npcs">Array to store the NPC IDs</param>
 * <param name="size">Size of the array (default: sizeof(npcs))</param>
 * <returns>Returns the number of NPCs found.</returns>
 * <seealso name="NPC_IsValid" />
 * <seealso name="NPC_Create" />
 */
native NPC_GetAll(npcs[], size = sizeof(npcs));

/*
native # Position & Movement();
native                Position & Movement(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 * <summary>Sets the position of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="x">The X coordinate</param>
 * <param name="y">The Y coordinate</param>
 * <param name="z">The Z coordinate</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_GetPos" />
 * <seealso name="NPC_Move" />
 */
native NPC_SetPos(npcid, Float:x, Float:y, Float:z);

/**
 * <library>omp_npc</library>
 * <summary>Gets the position of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="x">Variable to store the X coordinate in, passed by reference</param>
 * <param name="y">Variable to store the Y coordinate in, passed by reference</param>
 * <param name="z">Variable to store the Z coordinate in, passed by reference</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_SetPos" />
 * <seealso name="NPC_IsValid" />
 */
native NPC_GetPos(npcid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_SetRot(npcid, Float:x, Float:y, Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_GetRot(npcid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_SetFacingAngle(npcid, Float:angle);

/**
 * <library>omp_npc</library>
 */
native NPC_SetAngleToPos(npcid, Float:x, Float:y, Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_SetAngleToPlayer(npcid, playerid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetFacingAngle(npcid, &Float:angle);

/**
 * <library>omp_npc</library>
 */
native NPC_SetVirtualWorld(npcid, virtualWorld);

/**
 * <library>omp_npc</library>
 */
native NPC_GetVirtualWorld(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Makes an NPC move to a specific position.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="x">The X coordinate to move to</param>
 * <param name="y">The Y coordinate to move to</param>
 * <param name="z">The Z coordinate to move to</param>
 * <param name="moveType">The movement type (default: NPC_MOVE_TYPE_AUTO)</param>
 * <param name="moveSpeed">Movement speed (default: NPC_MOVE_SPEED_AUTO)</param>
 * <param name="stopRange">Distance to target before stopping (default: 0.2)</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_StopMove" />
 * <seealso name="NPC_IsMoving" />
 */
native NPC_Move(npcid, Float:x, Float:y, Float:z, NPC_MOVE_TYPE:moveType = NPC_MOVE_TYPE_AUTO, Float:moveSpeed = NPC_MOVE_SPEED_AUTO, Float:stopRange = 0.2);

/**
 * <library>omp_npc</library>
 * <summary>Makes an NPC move toward and follow a player.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="playerid">The ID of the player to move toward</param>
 * <param name="moveType">Movement type (default: NPC_MOVE_TYPE_AUTO)</param>
 * <param name="moveSpeed">Movement speed (default: NPC_MOVE_SPEED_AUTO)</param>
 * <param name="stopRange">Distance to stop from player (default: 0.2)</param>
 * <param name="updateDelayMS">Position check update delay in milliseconds (default: 500)</param>
 * <param name="autoRestart">Whether to automatically restart following (default: false)</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_Move" />
 * <seealso name="NPC_StopMove" />
 */
native NPC_MoveToPlayer(npcid, playerid, NPC_MOVE_TYPE:moveType = NPC_MOVE_TYPE_AUTO, Float:moveSpeed = NPC_MOVE_SPEED_AUTO, Float:stopRange = 0.2, updateDelayMS = 500, autoRestart = false);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StopMove(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsMoving(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Checks if an NPC is moving toward a specific player.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="playerid">The ID of the player to check</param>
 * <returns>Returns true if the NPC is moving toward the specified player, false otherwise.</returns>
 * <seealso name="NPC_MoveToPlayer" />
 * <seealso name="NPC_IsMoving" />
 */
native bool:NPC_IsMovingToPlayer(npcid, playerid);

/**
 * <library>omp_npc</library>
 * <summary>Sets the velocity of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="x">The X velocity component</param>
 * <param name="y">The Y velocity component</param>
 * <param name="z">The Z velocity component</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_GetVelocity" />
 * <seealso name="NPC_SetPos" />
 */
native NPC_SetVelocity(npcid, Float:x, Float:y, Float:z);

/**
 * <library>omp_npc</library>
 * <summary>Gets the velocity of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="x">Variable to store the X velocity component, passed by reference</param>
 * <param name="y">Variable to store the Y velocity component, passed by reference</param>
 * <param name="z">Variable to store the Z velocity component, passed by reference</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_SetVelocity" />
 * <seealso name="NPC_GetPos" />
 */
native NPC_GetVelocity(npcid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_npc</library>
 * <summary>Gets the position that the NPC is currently moving toward.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="x">Variable to store the X coordinate of the target position, passed by reference</param>
 * <param name="y">Variable to store the Y coordinate of the target position, passed by reference</param>
 * <param name="z">Variable to store the Z coordinate of the target position, passed by reference</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_Move" />
 * <seealso name="NPC_IsMoving" />
 * <seealso name="NPC_GetPos" />
 */
native NPC_GetPosMovingTo(npcid, &Float:x, &Float:y, &Float:z);

/*
native # Appearance();
native          Appearance(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_SetSkin(npcid, skinid);

/**
 * <library>omp_npc</library>
 * <summary>Gets the skin/model ID of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <returns>Returns the skin/model ID of the NPC, or -1 if invalid.</returns>
 * <seealso name="NPC_SetSkin" />
 * <seealso name="NPC_IsValid" />
 */
native NPC_GetSkin(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Gets the custom skin ID of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <returns>Returns the custom skin ID of the NPC, or -1 if the NPC has no custom skin or is invalid.</returns>
 * <seealso name="NPC_SetSkin" />
 * <seealso name="NPC_GetSkin" />
 */
native NPC_GetCustomSkin(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsStreamedIn(npcid, playerid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsAnyStreamedIn(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetInterior(npcid, interiorid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetInterior(npcid);

/*
native # Health & Combat();
native              Health & Combat(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_SetHealth(npcid, Float:health);

/**
 * <library>omp_npc</library>
 */
native Float:NPC_GetHealth(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetArmour(npcid, Float:armour);

/**
 * <library>omp_npc</library>
 */
native Float:NPC_GetArmour(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetInvulnerable(npcid, bool:toggle);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsInvulnerable(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Kills an NPC with a specific weapon/reason.</summary>
 * <param name="npcid">The ID of the NPC to kill</param>
 * <param name="killerid">The ID of the player who killed the NPC (optional, use INVALID_PLAYER_ID for no killer)</param>
 * <param name="reason">The weapon ID or reason for death (default: 255 for suicide)</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_IsDead" />
 * <seealso name="NPC_SetHealth" />
 */
native NPC_Kill(npcid, killerid = INVALID_PLAYER_ID, WEAPON:reason = REASON_SUICIDE);

/*
native # Weapons & Combat();
native                Weapons & Combat(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_SetWeapon(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeapon(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetAmmo(npcid, ammo);

/**
 * <library>omp_npc</library>
 */
native NPC_GetAmmo(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetAmmoInClip(npcid, ammo);

/**
 * <library>omp_npc</library>
 */
native NPC_GetAmmoInClip(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetKeys(npcid, upAndDown, leftAndRight, keys);

/**
 * <library>omp_npc</library>
 */
native NPC_GetKeys(npcid, &upAnddown, &leftandRight, &keys);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_MeleeAttack(npcid, time, bool:secondaryAttack = false);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StopMeleeAttack(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsMeleeAttacking(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetFightingStyle(npcid, FIGHT_STYLE:style);

/**
 * <library>omp_npc</library>
 */
native NPC_GetFightingStyle(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_EnableReloading(npcid, bool:enable);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsReloadEnabled(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsReloading(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_EnableInfiniteAmmo(npcid, bool:enable);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsInfiniteAmmoEnabled(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeaponState(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Sets the weapon state of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="weaponState">The weapon state to set</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_GetWeaponState" />
 * <seealso name="NPC_SetWeapon" />
 */
native NPC_SetWeaponState(npcid, WEAPONSTATE:weaponState);

/**
 * <library>omp_npc</library>
 * <summary>Makes an NPC fire a weapon shot.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="weaponid">The weapon ID to use for shooting</param>
 * <param name="hitId">The ID of the target entity being shot</param>
 * <param name="hitType">The type of entity being hit (player, NPC, vehicle, etc.)</param>
 * <param name="endPointX">X coordinate of the bullet end point</param>
 * <param name="endPointY">Y coordinate of the bullet end point</param>
 * <param name="endPointZ">Z coordinate of the bullet end point</param>
 * <param name="offsetX">X offset from the hit point</param>
 * <param name="offsetY">Y offset from the hit point</param>
 * <param name="offsetZ">Z offset from the hit point</param>
 * <param name="isHit">Whether the shot actually hits the target</param>
 * <param name="checkInBetweenFlags">Entity check flags (default: NPC_ENTITY_CHECK_ALL)</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_AimAt" />
 * <seealso name="NPC_SetWeapon" />
 */
native NPC_Shoot(npcid, WEAPON:weaponid, hitId, hitType, Float:endPointX, Float:endPointY, Float:endPointZ, Float:offsetX, Float:offsetY, Float:offsetZ, bool:isHit, NPC_ENTITY_CHECK:checkInBetweenFlags = NPC_ENTITY_CHECK_ALL);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsShooting(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_AimAt(npcid, Float:pointX, Float:pointY, Float:pointZ, bool:shoot, shootDelay, bool:updateAngle, Float:offsetFromX, Float:offsetFromY, Float:offsetFromZ, NPC_ENTITY_CHECK:checkInBetweenFlags = NPC_ENTITY_CHECK_ALL);

/**
 * <library>omp_npc</library>
 */
native NPC_AimAtPlayer(npcid, playerid, bool:shoot, shootDelay, bool:updateAngle, Float:offsetX, Float:offsetY, Float:offsetZ, Float:offsetFromX, Float:offsetFromY, Float:offsetFromZ, NPC_ENTITY_CHECK:checkInBetweenFlags = NPC_ENTITY_CHECK_ALL);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StopAim(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsAiming(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsAimingAtPlayer(npcid, playerid);

/**
 * <library>omp_npc</library>
 * <summary>Gets the ID of the player that an NPC is currently aiming at.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <returns>Returns the ID of the player being aimed at, or INVALID_PLAYER_ID if not aiming at anyone.</returns>
 * <seealso name="NPC_AimAtPlayer" />
 * <seealso name="NPC_IsAiming" />
 * <seealso name="NPC_GetPlayerMovingTo" />
 */
native NPC_GetPlayerAimingAt(npcid);

/**
 * <library>omp_npc</library>
 * <summary>Gets the ID of the player that an NPC is currently moving toward.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <returns>Returns the ID of the player being moved toward, or INVALID_PLAYER_ID if not moving toward anyone.</returns>
 * <seealso name="NPC_MoveToPlayer" />
 * <seealso name="NPC_IsMovingToPlayer" />
 * <seealso name="NPC_GetPlayerAimingAt" />
 */
native NPC_GetPlayerMovingTo(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetWeaponAccuracy(npcid, WEAPON:weaponid, Float:accuracy);

/**
 * <library>omp_npc</library>
 */
native Float:NPC_GetWeaponAccuracy(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetWeaponReloadTime(npcid, WEAPON:weaponid, time);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeaponReloadTime(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeaponActualReloadTime(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetWeaponShootTime(npcid, WEAPON:weaponid, time);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeaponShootTime(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetWeaponClipSize(npcid, WEAPON:weaponid, size);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeaponClipSize(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetWeaponActualClipSize(npcid, WEAPON:weaponid);

/**
 * <library>omp_npc</library>
 * <summary>Sets the weapon skill level for an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="skill">The weapon skill type (WEAPONSKILL)</param>
 * <param name="level">The skill level to set (0-999)</param>
 * <returns>Returns true on success, false on failure.</returns>
 * <seealso name="NPC_GetWeaponSkillLevel" />
 */
native bool:NPC_SetWeaponSkillLevel(npcid, WEAPONSKILL:skill, level);

/**
 * <library>omp_npc</library>
 * <summary>Gets the weapon skill level of an NPC.</summary>
 * <param name="npcid">The ID of the NPC</param>
 * <param name="skill">The weapon skill type (WEAPONSKILL)</param>
 * <returns>Returns the weapon skill level (0-999), or UNKNOWN_WEAPONSKILL on failure.</returns>
 * <seealso name="NPC_SetWeaponSkillLevel" />
 */
native NPC_GetWeaponSkillLevel(npcid, WEAPONSKILL:skill);

/*
native # Vehicles();
native          Vehicles(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native bool:NPC_EnterVehicle(npcid, vehicleid, seatid, NPC_MOVE_TYPE:moveType = NPC_MOVE_TYPE_AUTO);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_ExitVehicle(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_PutInVehicle(npcid, vehicleid, seatid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_RemoveFromVehicle(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetVehicle(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetVehicleID(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetVehicleSeat(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetEnteringVehicle(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetEnteringVehicleID(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetEnteringVehicleSeat(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsEnteringVehicle(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_UseVehicleSiren(npcid, bool:use = true);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsVehicleSirenUsed(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetVehicleHealth(npcid, Float:health);

/**
 * <library>omp_npc</library>
 */
native Float:NPC_GetVehicleHealth(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetVehicleHydraThrusters(npcid, direction);

/**
 * <library>omp_npc</library>
 */
native NPC_GetVehicleHydraThrusters(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetVehicleGearState(npcid, gearState);

/**
 * <library>omp_npc</library>
 */
native LANDING_GEAR_STATE:NPC_GetVehicleGearState(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetVehicleTrainSpeed(npcid, Float:speed);

/**
 * <library>omp_npc</library>
 */
native Float:NPC_GetVehicleTrainSpeed(npcid);

/*
native # Animations();
native            Animations(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_ResetAnimation(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetAnimation(npcid, animationId, Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time);

/**
 * <library>omp_npc</library>
 */
native NPC_GetAnimation(npcid, &animationId, &Float:delta, &bool:loop, &bool:lockX, &bool:lockY, &bool:freeze, &time);

/**
 * <library>omp_npc</library>
 */
native NPC_ApplyAnimation(npcid, const animlib[], const animname[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time);

/**
 * <library>omp_npc</library>
 */
native NPC_ClearAnimations(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetSpecialAction(npcid, SPECIAL_ACTION:actionid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetSpecialAction(npcid);

/*
native # Playback();
native          Playback(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StartPlayback(npcid, const recordName[], bool:autoUnload, Float:startX, Float:startY, Float:startZ, Float:rotX, Float:rotY, Float:rotZ);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StartPlaybackEx(npcid, recordId, bool:autoUnload, Float:startX, Float:startY, Float:startZ, Float:rotX, Float:rotY, Float:rotZ);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StopPlayback(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_PausePlayback(npcid, bool:paused);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsPlayingPlayback(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsPlaybackPaused(npcid);

/*
native # Surfing();
native          Surfing(
native      ====================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_SetSurfingOffsets(npcid, Float:x, Float:y, Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_GetSurfingOffsets(npcid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_SetSurfingVehicle(npcid, vehicleid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetSurfingVehicle(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetSurfingObject(npcid, objectid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetSurfingObject(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_SetSurfingPlayerObject(npcid, objectid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetSurfingPlayerObject(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_ResetSurfingData(npcid);

/*
native # Records();
native          Records(
native      ============================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_LoadRecord(const filePath[]);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_UnloadRecord(recordId);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsValidRecord(recordId);

/**
 * <library>omp_npc</library>
 */
native NPC_GetRecordCount();

/**
 * <library>omp_npc</library>
 */
native bool:NPC_UnloadAllRecords();

/*
native # Paths();
native          Paths(
native      ========================(
native
*/

/**
 * <library>omp_npc</library>
 */
native NPC_CreatePath();

/**
 * <library>omp_npc</library>
 */
native bool:NPC_DestroyPath(pathid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_DestroyAllPath();

/**
 * <library>omp_npc</library>
 */
native NPC_GetPathCount();

/**
 * <library>omp_npc</library>
 */
native bool:NPC_AddPointToPath(pathid, Float:x, Float:y, Float:z, Float:stopRange);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_RemovePointFromPath(pathid, pointIndex);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_ClearPath(pathid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetPathPointCount(pathid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_GetPathPoint(pathid, pointIndex, &Float:x, &Float:y, &Float:z, &Float:stopRange);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsValidPath(pathid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetCurrentPathPointIndex(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_MoveByPath(npcid, pathid, NPC_MOVE_TYPE:moveType = NPC_MOVE_TYPE_AUTO, Float:moveSpeed = NPC_MOVE_SPEED_AUTO, bool:reversed = false);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_HasPathPointInRange(pathId, Float:x, Float:y, Float:z, Float:radius);

/*
native # Nodes();
native          Nodes(
native      ========================(
native
*/

/**
 * <library>omp_npc</library>
 */
native bool:NPC_OpenNode(nodeid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_CloseNode(nodeid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsNodeOpen(nodeid);

/**
 * <library>omp_npc</library>
 */
native NPC_GetNodeType(nodeid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_SetNodePoint(nodeid, pointid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_GetNodePointPosition(nodeid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_npc</library>
 */
native NPC_GetNodePointCount(nodeid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_GetNodeInfo(nodeid, &vehnodes, &pednodes, &navinode);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_PlayNode(npcid, nodeid, NPC_MOVE_TYPE:moveType = NPC_MOVE_TYPE_AUTO, Float:speed = NPC_MOVE_SPEED_AUTO, Float:radius = 0.0, bool:setAngle = true);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_StopPlayingNode(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_PausePlayingNode(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_ResumePlayingNode(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsPlayingNode(npcid);

/**
 * <library>omp_npc</library>
 */
native NPC_ChangeNode(npcid, nodeid, linkid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_IsPlayingNodePaused(npcid);

/**
 * <library>omp_npc</library>
 */
native bool:NPC_UpdateNodePoint(npcid, pointid);

/*
native # Callbacks();
native          Callbacks(
native      ============================(
native
*/

/**
 * <library>omp_npc</library>
 */
forward OnNPCFinishMove(npcid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCCreate(npcid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCDestroy(npcid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCSpawn(npcid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCRespawn(npcid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCWeaponStateChange(npcid, newState, oldState);

/**
 * <library>omp_npc</library>
 */
forward OnNPCTakeDamage(npcid, issuerid, Float:amount, WEAPON:weaponid, bodypart);

/**
 * <library>omp_npc</library>
 */
forward OnNPCGiveDamage(npcid, damagedid, Float:amount, WEAPON:weaponid, bodypart);

/**
 * <library>omp_npc</library>
 */
forward OnNPCDeath(npcid, killerid, WEAPON:reason);

/**
 * <library>omp_npc</library>
 */
forward OnNPCPlaybackStart(npcid, recordid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCPlaybackEnd(npcid, recordid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCWeaponShot(npcid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ);

/**
 * <library>omp_npc</library>
 */
forward OnNPCFinishNodePoint(npcid, nodeid, pointid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCFinishNode(npcid, nodeid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCChangeNode(npcid, newnodeid, oldnodeid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCFinishMovePath(npcid, pathid);

/**
 * <library>omp_npc</library>
 */
forward OnNPCFinishMovePathPoint(npcid, pathid, pointid);
