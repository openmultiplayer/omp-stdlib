#if defined _INC_omp_class
	#endinput
#endif
#define _INC_omp_class

/**
 * <library name="omp_class" summary="open.mp class functions.">
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
 * <library>omp_class</library>
 * <summary>Adds a class to class selection.  Classes are used so players may spawn with a skin of their
 * choice.</summary>
 * <param name="skin">The <a href="https://open.mp/docs/scripting/resources/skins">skin</a> which the player will
 * spawn with</param>
 * <param name="spawnX">The x coordinate of the spawnpoint of this class</param>
 * <param name="spawnY">The y coordinate of the spawnpoint of this class</param>
 * <param name="spawnZ">The z coordinate of the spawnpoint of this class</param>
 * <param name="angle">The direction in which the player should face after spawning</param>
 * <param name="weapon1">The first spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo1">The amount of ammunition for the primary spawn weapon</param>
 * <param name="weapon2">The second spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo2">The amount of ammunition for the second spawn weapon</param>
 * <param name="weapon3">The third spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo3">The amount of ammunition for the third spawn weapon</param>
 * <returns>
 *   <ul>
 *     <li>The <b>ID of the class</b> which was just added.</li>
 *     <li><b><c>319</c></b> if the class limit (<b><c>320</c></b>) was reached.  The highest possible
 * class ID is <b><c>319</c></b>.</li>
 *   </ul>
 * </returns>
 * <remarks>
 *    The maximum class ID is <b><c>319</c></b> (starting from <b><c>0</c></b>, so a total of <b><c>320</c></b>
 * classes).
 *    When this limit is reached, any more classes that are added will replace ID <b><c>319</c></b>.
 * </remarks>
 * <seealso name="AddPlayerClassEx" />
 * <seealso name="SetSpawnInfo" />
 * <seealso name="SetPlayerSkin" />
 */
native AddPlayerClass(skin, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, WEAPON:weapon1 = WEAPON_FIST, ammo1 = 0, WEAPON:weapon2 = WEAPON_FIST, ammo2 = 0, WEAPON:weapon3 = WEAPON_FIST, ammo3 = 0);

/**
 * <library>omp_class</library>
 * <summary>This function is exactly the same as the <a href="#AddPlayerClass">AddPlayerClass</a> function,
 * with the addition of a team parameter.</summary>
 * <param name="team">The team you want the player to spawn in</param>
 * <param name="skin">The <a href="https://open.mp/docs/scripting/resources/skins">skin</a> which the player will
 * spawn with</param>
 * <param name="spawnX">The x coordinate of the spawnpoint of this class</param>
 * <param name="spawnY">The y coordinate of the spawnpoint of this class</param>
 * <param name="spawnZ">The z coordinate of the spawnpoint of this class</param>
 * <param name="angle">The direction in which the player should face after spawning</param>
 * <param name="weapon1">The first spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo1">The amount of ammunition for the primary spawn weapon</param>
 * <param name="weapon2">The second spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo2">The amount of ammunition for the second spawn weapon</param>
 * <param name="weapon3">The third spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo3">The amount of ammunition for the third spawn weapon</param>
 * <returns>
 *   <ul>
 *     <li>The <b>ID of the class</b> which was just added.</li>
 *     <li><b><c>319</c></b> if the class limit (<b><c>320</c></b>) was reached.  The highest possible
 * class ID is <b><c>319</c></b>.</li>
 *   </ul>
 * </returns>
 * <remarks>The maximum class ID is <b><c>319</c></b> (starting from <b><c>0</c></b>, so a total of
 * <b><c>320</c></b> classes).  When this limit is reached, any more classes that are added will replace
 * ID <b><c>319</c></b>.</remarks>
 * <seealso name="AddPlayerClass" />
 * <seealso name="SetSpawnInfo" />
 * <seealso name="SetPlayerTeam" />
 * <seealso name="SetPlayerSkin" />
 */
native AddPlayerClassEx(team, skin, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, WEAPON:weapon1 = WEAPON_FIST, ammo1 = 0, WEAPON:weapon2 = WEAPON_FIST, ammo2 = 0, WEAPON:weapon3 = WEAPON_FIST, ammo3 = 0);

/**
 * <library>omp_class</library>
 * <summary>This function can be used to change the spawn information of a specific player.  It allows
 * you to automatically set someone's spawn weapons, their team, skin and spawn position, normally used
 * in case of minigames or automatic-spawn systems.</summary>
 * <param name="playerid">The Playerid of who you want to set the spawn information</param>
 * <param name="team">The Team-ID of the chosen player</param>
 * <param name="skin">The <a href="https://open.mp/docs/scripting/resources/skins">skin</a> which the player will
 * spawn with</param>
 * <param name="spawnX">The x coordinate of the player's spawn position</param>
 * <param name="spawnY">The y coordinate of the player's spawn position</param>
 * <param name="spawnZ">The z coordinate of the player's spawn position</param>
 * <param name="angle">The direction in which the player should face after spawning</param>
 * <param name="weapon1">The first spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo1">The amount of ammunition for the primary spawnweapon</param>
 * <param name="weapon2">The second spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo2">The amount of ammunition for the second spawnweapon</param>
 * <param name="weapon3">The third spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo3">The amount of ammunition for the third spawnweapon</param>
 * <seealso name="SetPlayerSkin" />
 * <seealso name="SetPlayerTeam" />
 * <seealso name="SpawnPlayer" />
 */
native bool:SetSpawnInfo(playerid, team, skin, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, WEAPON:weapon1 = WEAPON_FIST, ammo1 = 0, WEAPON:weapon2 = WEAPON_FIST, ammo2 = 0, WEAPON:weapon3 = WEAPON_FIST, ammo3 = 0);

/**
 * <library>omp_class</library>
 * <summary>Return the current spawn data for a player, where they will spawn next.</summary>
 * <param name="playerid">The Playerid of who you want to get the spawn information</param>
 * <param name="team">The Team-ID of the chosen player</param>
 * <param name="skin">The skin which the player will spawn with</param>
 * <param name="spawnX">The x coordinate of the player's spawn position</param>
 * <param name="spawnY">The y coordinate of the player's spawn position</param>
 * <param name="spawnZ">The z coordinate of the player's spawn position</param>
 * <param name="angle">The direction in which the player should face after spawning</param>
 * <param name="weapon1">The first spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo1">The amount of ammunition for the primary spawnweapon</param>
 * <param name="weapon2">The second spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo2">The amount of ammunition for the second spawnweapon</param>
 * <param name="weapon3">The third spawn-<a href="https://open.mp/docs/scripting/resources/weaponids">weapon</a> for
 * the player</param>
 * <param name="ammo3">The amount of ammunition for the third spawnweapon</param>
 * <seealso name="SetPlayerSkin" />
 * <seealso name="SetPlayerTeam" />
 * <seealso name="SpawnPlayer" />
 */
native bool:GetSpawnInfo(playerid, &team, &skin = 0, &Float:spawnX = 0.0, &Float:spawnY = 0.0, &Float:spawnZ = 0.0, &Float:angle = 0.0, &WEAPON:weapon1 = WEAPON_FIST, &ammo1 = 0, &WEAPON:weapon2 = WEAPON_FIST, &ammo2 = 0, &WEAPON:weapon3 = WEAPON_FIST, &ammo3 = 0);

/**
 * <library>omp_class</library>
 * <summary>(Re)Spawns a player.</summary>
 * <param name="playerid">The ID of the player to spawn</param>
 * <seealso name="SetSpawnInfo" />
 * <seealso name="AddPlayerClass" />
 * <seealso name="OnPlayerSpawn" />
 * <remarks>Kills the player if they are in a vehicle and then they spawn with a bottle in their hand.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:SpawnPlayer(playerid);

/**
 * <library>omp_class</library>
 * <summary>This function is used to change the amount of teams used in the gamemode.  It has no obvious
 * way of being used, but can help to indicate the number of teams used for better (more effective)
 * internal handling.  This function should only be used in the <a href="#OnGameModeInit">OnGameModeInit</a>
 * callback.  Important: You can pass 2 billion here if you like, this function has no effect at all.</summary>
 * <param name="count">Number of teams the gamemode knows</param>
 * <seealso name="GetPlayerTeam" />
 * <seealso name="SetPlayerTeam" />
 */
forward void:SetTeamCount(count);

/**
 * <library>omp_class</library>
 * <summary>Forces a player to go back to class selection.</summary>
 * <param name="playerid">The player to send back to class selection</param>
 * <seealso name="AddPlayerClass" />
 * <seealso name="SetPlayerSkin" />
 * <seealso name="GetPlayerSkin" />
 * <seealso name="OnPlayerRequestClass" />
 * <remarks>The player will not return to class selection until they re-spawn.  This can be achieved
 * with <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>, as seen in the below example.</remarks>
 */
native bool:ForceClassSelection(playerid);

/**
 * <library>omp_class</library>
 * <summary>Returns the number of classes defined.</summary>
 */
native GetAvailableClasses();

/**
 * <library>omp_class</library>
 */
native bool:GetPlayerClass(classid, &team, &skin = 0, &Float:spawnX = 0.0, &Float:spawnY = 0.0, &Float:spawnZ = 0.0, &Float:angle = 0.0, &WEAPON:weapon1 = WEAPON_FIST, &ammo1 = 0, &WEAPON:weapon2 = WEAPON_FIST, &ammo2 = 0, &WEAPON:weapon3 = WEAPON_FIST, &ammo3 = 0);

/**
 * <library>omp_class</library>
 */
native bool:EditPlayerClass(classid, team, skin, Float:spawnX, Float:spawnY, Float:spawnZ, Float:angle, WEAPON:weapon1 = WEAPON_FIST, ammo1 = 0, WEAPON:weapon2 = WEAPON_FIST, ammo2 = 0, WEAPON:weapon3 = WEAPON_FIST, ammo3 = 0);

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
 * <summary>Called when a player changes class at class selection (and when class selection first appears).</summary>
 * <param name="playerid">The ID of the player that changed class</param>
 * <param name="classid">The ID of the current class being viewed (returned by <a href="#AddPlayerClass">AddPlayerClass</a>)</param>
 * <seealso name="OnPlayerRequestSpawn" />
 * <seealso name="AddPlayerClass" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>This callback is also called when a player presses <b>F4</b>.</remarks>
 * <returns>
 *   Returning <b><c>0</c></b> in this callback will prevent the player from spawning.  The player can
 * be forced to spawn when <a href="#SpawnPlayer">SpawnPlayer</a> is used.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerRequestClass(playerid, classid);

/**
 * <summary>Called when a player attempts to spawn via class selection either by pressing SHIFT or clicking
 * the 'Spawn' button.</summary>
 * <param name="playerid">The ID of the player that requested to spawn</param>
 * <seealso name="OnPlayerSpawn" />
 * <seealso name="OnPlayerRequestClass" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>To prevent players from spawning with certain classes, the last viewed class must be saved
 * in a variable in <a href="#OnPlayerRequestClass">OnPlayerRequestClass</a>.</remarks>
 * <returns>
 *   Returning <b><c>0</c></b> in this callback will prevent the player from spawning.<br />
 *   It is always called first in filterscripts so returning <b><c>0</c></b> there also blocks other
 * scripts from seeing it.
 * </returns>
 */
forward OnPlayerRequestSpawn(playerid);

/**
 * <summary>This callback is called when a player spawns.(i.e.  after caling <a href="#SpawnPlayer">SpawnPlayer</a>
 * function).</summary>
 * <param name="playerid">The ID of the player that spawned</param>
 * <seealso name="OnPlayerDeath" />
 * <seealso name="OnVehicleSpawn" />
 * <seealso name="SpawnPlayer" />
 * <seealso name="AddPlayerClass" />
 * <seealso name="SetSpawnInfo" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>The game sometimes deducts $100 from players after spawn.</remarks>
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerSpawn(playerid);
