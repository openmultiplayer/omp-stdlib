#if defined _INC_omp_actor
	#endinput
#endif
#define _INC_omp_actor

/**
 * <library name="omp_actor" summary="open.mp actor functions.">
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
 * <library>omp_actor</library>
 */
#if defined MAX_ACTORS
	#if MAX_ACTORS < 1 || MAX_ACTORS > 1000
		#error MAX_ACTORS must be >= 1 and <= 1000
	#endif

	const __MAX_ACTORS                         = MAX_ACTORS;
	#define __MAX_ACTORS
#else
	const MAX_ACTORS                           = 1000;
	#define MAX_ACTORS                         1000
#endif

/**
 * <library>omp_actor</library>
 */
const INVALID_ACTOR_ID                         = 0xFFFF;
#define INVALID_ACTOR_ID                       65535

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
 * <library>omp_actor</library>
 * <summary>Create a static 'actor' in the world.  These 'actors' are like NPCs, however they have limited
 * functionality.  They do not take up server player slots.</summary>
 * <param name="skin">The model ID (skin ID) the actor should have</param>
 * <param name="x">The x coordinate to create the actor at</param>
 * <param name="y">The y coordinate to create the actor at</param>
 * <param name="z">The z coordinate to create the actor at</param>
 * <param name="angle">The facing angle (rotation) for the actor to have</param>
 * <seealso name="DestroyActor" />
 * <seealso name="SetActorPos" />
 * <seealso name="GetActorPos" />
 * <seealso name="SetActorFacingAngle" />
 * <seealso name="GetActorFacingAngle" />
 * <seealso name="SetActorVirtualWorld" />
 * <seealso name="GetActorVirtualWorld" />
 * <seealso name="ApplyActorAnimation" />
 * <seealso name="ClearActorAnimations" />
 * <seealso name="GetPlayerCameraTargetActor" />
 * <seealso name="IsActorStreamedIn" />
 * <seealso name="SetActorHealth" />
 * <seealso name="GetActorHealth" />
 * <seealso name="SetActorInvulnerable" />
 * <seealso name="IsActorInvulnerable" />
 * <seealso name="IsValidActor" />
 * <seealso name="GetActorPoolSize" />
 * <seealso name="GetPlayerTargetActor" />
 * <seealso name="OnActorStreamIn" />
 * <seealso name="OnActorStreamOut" />
 * <seealso name="OnPlayerGiveDamageActor" />
 * <remarks>
 *   Actors are completely separate from NPCs.  They do NOT use player IDs/slots on the server and CANNOT
 * be handled like NPCs.<br />
 *   Actors are limited to <b><c>1000</c></b> (<b><c>MAX_ACTORS</c></b>).<br />
 *   Actors can be pushed by vehicles, use a timer to put them back at their positions.<br />
 * </remarks>
 * <returns>
 *   The created Actor ID (start at <b><c>0</c></b>).<br />
 *   <b><c>INVALID_ACTOR_ID</c></b> (<b><c>65535</c></b>) If the actor limit (<b><c>1000</c></b>) is
 * reached.
 * </returns>
 */
native CreateActor(skin, Float:x, Float:y, Float:z, Float:angle);

/**
 * <library>omp_actor</library>
 * <summary>Destroy an actor which was created with <a href="#CreateActor">CreateActor</a>.</summary>
 * <param name="actorid">The ID of the actor to destroy.  Returned by <a href="#CreateActor">CreateActor</a></param>
 * <seealso name="CreateActor" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor with the ID specified does not exist.
 * </returns>
 */
native bool:DestroyActor(actorid);

/**
 * <library>omp_actor</library>
 * <summary>Checks if an actor is streamed in for a player.</summary>
 * <param name="actorid">The ID of the actor</param>
 * <param name="playerid">The ID of the player</param>
 * <seealso name="CreateActor" />
 * <seealso name="IsPlayerStreamedIn" />
 * <returns><b><c>1</c></b> if the actor is streamed in for the player, or <b><c>0</c></b> if it is
 * not.</returns>
 */
native bool:IsActorStreamedIn(actorid, playerid);

/**
 * <library>omp_actor</library>
 * <summary>Set the virtual world of an actor.  Only players in the same world will see the actor.</summary>
 * <param name="actorid">The ID of the actor (returned by <a href="#CreateActor">CreateActor</a>) to
 * set the virtual world of</param>
 * <param name="virtualWorld">The virtual world to put the actor ID</param>
 * <seealso name="GetActorVirtualWorld" />
 * <seealso name="CreateActor" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.
 * </returns>
 */
native bool:SetActorVirtualWorld(actorid, virtualWorld);

/**
 * <library>omp_actor</library>
 * <summary>Get the virtual world of an actor.</summary>
 * <param name="actorid">The ID of the actor to get the virtual world of</param>
 * <seealso name="SetActorVirtualWorld" />
 * <returns>The virtual world of the actor.  By default this is <b><c>0</c></b>.  Also returns <b><c>0</c></b>
 * if actor specified does not exist.</returns>
 */
native GetActorVirtualWorld(actorid);

/**
 * <library>omp_actor</library>
 * <summary>Apply an animation to an actor.</summary>
 * <param name="actorid">The ID of the actor to apply the animation to</param>
 * <param name="animationLibrary">The animation library from which to apply an animation</param>
 * <param name="animationName">The name of the animation to apply, within the specified library</param>
 * <param name="delta">The speed to play the animation (use <b><c>4.1</c></b>)</param>
 * <param name="loop">If set to <b><c>1</c></b>, the animation will loop.  If set to <b><c>0</c></b>,
 * the animation will play once</param>
 * <param name="lockX">If set to <b><c>0</c></b>, the actor is returned to their old x coordinate once
 * the animation is complete (for animations that move the actor such as walking). <b><c>1</c></b> will
 * not return them to their old position</param>
 * <param name="lockY">Same as above but for the y axis.  Should be kept the same as the previous parameter</param>
 * <param name="freeze">Setting this to <b><c>1</c></b> will freeze an actor at the end of the animation.
 * <b><c>0</c></b> will not</param>
 * <param name="time">Timer in milliseconds.  For a never-ending loop it should be <b><c>0</c></b></param>
 * <seealso name="ClearActorAnimations" />
 * <remarks>You must preload the animation library for the player the actor will be applying the animation
 * for, and not for the actor.  Otherwise, the animation won't be applied to the actor until the function
 * is executed again.</remarks>
 * <returns>
 * <b><c>1</c></b>: The function executed successfully.<br />
 * <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.
 * </returns>
 */
native bool:ApplyActorAnimation(actorid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time);

/**
 * <library>omp_actor</library>
 * <summary>Clear any animations applied to an actor.</summary>
 * <param name="actorid">The ID of the actor (returned by <a href="#CreateActor">CreateActor</a>) to
 * clear the animations for</param>
 * <seealso name="ApplyActorAnimation" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.
 * </returns>
 */
native bool:ClearActorAnimations(actorid);

/**
 * <library>omp_actor</library>
 * <summary>Set the position of an actor.</summary>
 * <param name="actorid">The ID of the actor to set the position of.  Returned by <a href="#CreateActor">CreateActor</a></param>
 * <param name="x">The x coordinate to position the actor at</param>
 * <param name="y">The y coordinate to position the actor at</param>
 * <param name="z">The z coordinate to position the actor at</param>
 * <seealso name="GetActorPos" />
 * <seealso name="CreateActor" />
 * <remarks>When creating an actor with <a href="#CreateActor">CreateActor</a>, you specify it's position.
 *  You do not need to use this function unless you want to change its position later.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.
 * </returns>
 */
native bool:SetActorPos(actorid, Float:x, Float:y, Float:z);

/**
 * <library>omp_actor</library>
 * <summary>Get the position of an actor.</summary>
 * <param name="actorid">The ID of the actor to get the position of.  Returned by <a href="# CreateActor">CreateActor</a></param>
 * <param name="x">A float variable, passed by reference, in which to store the x coordinate of the
 * actor</param>
 * <param name="y">A float variable, passed by reference, in which to store the y coordinate of the
 * actor</param>
 * <param name="z">A float variable, passed by reference, in which to store the z coordinate of the
 * actor</param>
 * <seealso name="SetActorPos" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.<br />
 * </returns>
 */
native bool:GetActorPos(actorid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_actor</library>
 * <summary>Set the facing angle of an actor.</summary>
 * <param name="actorid">The ID of the actor to set the facing angle of.  Returned by <a href="#CreateActor">CreateActor</a></param>
 * <param name="angle">The facing angle to set for the actor</param>
 * <seealso name="GetActorFacingAngle" />
 * <seealso name="SetActorPos" />
 * <remarks>Players will see actor's facing angle changed only when it is restreamed to them.</remarks>
 * <remarks>When creating an actor with <a href="#CreateActor">CreateActor</a>, you specify it's facing
 * angle.  You do not need to use this function unless you want to change its facing angle later.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.
 * </returns>
 */
native bool:SetActorFacingAngle(actorid, Float:angle);

/**
 * <library>omp_actor</library>
 * <summary>Get the facing angle of an actor.</summary>
 * <param name="actorid">The ID of the actor to get the facing angle of.  Returned by <a href="#CreateActor">CreateActor</a></param>
 * <param name="angle">A float variable, passed by reference, in to which the actor's facing angle will
 * be stored</param>
 * <seealso name="SetActorFacingAngle" />
 * <seealso name="GetActorPos" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The actor specified does not exist.
 * </returns>
 */
native bool:GetActorFacingAngle(actorid, &Float:angle);

/**
 * <library>omp_actor</library>
 * <summary>Set the health of an actor.</summary>
 * <param name="actorid">The ID of the actor to set the health of</param>
 * <param name="health">The value to set the actors's health to</param>
 * <returns>
 *   <b><c>1</c></b> on success.<br />
 *   <b><c>0</c></b> on failure (i.e.  actor is not created).
 * </returns>
 */
native bool:SetActorHealth(actorid, Float:health);

/**
 * <library>omp_actor</library>
 * <summary>Get the health of an actor.</summary>
 * <param name="actorid">The ID of the actor to get the health of</param>
 * <param name="health">A float variable, passed by reference, in to which to store the actor's health</param>
 * <returns>
 *   <b><c>1</c></b> - success.<br />
 *   <b><c>0</c></b> - failure (i.e.  actor is not created).<br />
 * </returns>
 */
native bool:GetActorHealth(actorid, &Float:health);

/**
 * <library>omp_actor</library>
 * <summary>Toggle an actor's invulnerability.</summary>
 * <param name="actorid">The ID of the actor to set invulnerability</param>
 * <param name="invulnerable"><b><c>false</c></b> to make them vulnerable, <b><c>true</c></b> to make
 * them invulnerable (optional=<b><c>true</c></b>)</param>
 * <remarks>Once set invulnerable, the actor does not call <a href="#OnPlayerGiveDamageActor">OnPlayerGiveDamageActor</a>.</remarks>
 * <remarks>Players will have actor's invulnerability state changed only when it is restreamed to them.</remarks>
 * <returns>
 *   <b><c>1</c></b> - Success.<br />
 *   <b><c>0</c></b> - Failure (i.e.  Actor is not created).
 * </returns>
 */
native bool:SetActorInvulnerable(actorid, bool:invulnerable = true);

/**
 * <library>omp_actor</library>
 * <summary>Check if an actor is invulnerable.</summary>
 * <param name="actorid">The ID of the actor to check</param>
 * <seealso name="CreateActor" />
 * <seealso name="SetActorInvulnerable" />
 * <seealso name="SetActorHealth" />
 * <returns><b><c>1</c></b> if the actor is invulnerable, <b><c>0</c></b> otherwise.</returns>
 */
native bool:IsActorInvulnerable(actorid);

/**
 * <library>omp_actor</library>
 * <summary>Checks if an actor ID is valid.</summary>
 * <param name="actorid">The ID of the actor to check</param>
 * <returns><b><c>1</c></b> if the actor is valid, <b><c>0</c></b> if not.</returns>
 */
native bool:IsValidActor(actorid);

/**
 * <library>omp_actor</library>
 * <summary>Set the skin of the actor.</summary>
 * <param name="actorid">The ID of the actor to set</param>
 * <param name="skin">The ID of the skin to give them</param>
 * <returns><b><c>1</c></b> if the actor is valid, <b><c>0</c></b> if not.</returns>
 */
native bool:SetActorSkin(actorid, skin);

/**
 * <library>omp_actor</library>
 * <summary>Get the skin of the actor.</summary>
 * <param name="actorid">The ID of the actor to set</param>
 * <returns>The actor's current skin.</returns>
 */
native GetActorSkin(actorid);

/**
 * <library>omp_actor</library>
 * <summary>Get the animation the actor is currently performing.</summary>
 * <param name="actorid">The ID of the actor to get the animation of</param>
 * <param name="animationLibrary">The animation library in which the animation is</param>
 * <param name="animationName">The name of the animation applied, within the specified library</param>
 * <param name="delta">The speed to play the animation (use <b><c>4.1</c></b>)</param>
 * <param name="loop">If set to <b><c>1</c></b>, the animation will loop.  If set to <b><c>0</c></b>,
 * the animation will play once</param>
 * <param name="lockX">If set to <b><c>0</c></b>, the actor is returned to their old x coordinate once
 * the animation is complete (for animations that move the actor such as walking). <b><c>1</c></b> will
 * not return them to their old position</param>
 * <param name="lockY">Same as above but for the y axis.  Should be kept the same as the previous parameter</param>
 * <param name="freeze">Setting this to <b><c>1</c></b> will freeze an actor at the end of the animation.
 * <b><c>0</c></b> will not</param>
 * <param name="time">Timer in milliseconds.  For a never-ending loop it should be <b><c>0</c></b></param>
 * <returns><b><c>1</c></b> if the actor is valid, <b><c>0</c></b> if not.</returns>
 */
native bool:GetActorAnimation(actorid, animationLibrary[], librarySize = sizeof (animationLibrary), animationName[], nameSize = sizeof (animationName), &Float:delta, &bool:loop = false, &bool:lockX = false, &bool:lockY = false, &bool:freeze = false, &time = 0);

/**
 * <library>omp_actor</library>
 * <summary>Get the initial spawn point of the actor.</summary>
 * <param name="actorid">The ID of the actor to get the spawn point of</param>
 * <param name="skin">The model they have</param>
 * <param name="spawnX">The X co-ordinate</param>
 * <param name="spawnY">The Y co-ordinate</param>
 * <param name="spawnZ">The Z co-ordinate</param>
 * <param name="spawnAngle">The angle</param>
 * <returns><b><c>1</c></b> if the actor is valid, <b><c>0</c></b> if not.</returns>
 */
native bool:GetActorSpawnInfo(actorid, &skin, &Float:spawnX = 0.0, &Float:spawnY = 0.0, &Float:spawnZ = 0.0, &Float:spawnAngle = 0.0);

/**
 * <library>omp_actor</library>
 * <summary>Get an array variable of the IDs of the created actors on the server.</summary>
 * <param name="actors">An array into which to store the actor IDs, passed by reference.</param>
 * <param name="size">The size of the array.</param>
 * <seealso name="GetPlayers" />
 * <seealso name="GetVehicles" />
 * <returns>The number of actors stored in the array.</returns>
 */
native GetActors(actors[], size = sizeof (actors));

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
 * <summary>This callback is called when a player gives damage to an actor.</summary>
 * <param name="playerid">The ID of the player that gave damage</param>
 * <param name="damaged_actorid">The ID of the actor that received damage</param>
 * <param name="amount">The amount of health/armour damaged_actorid has lost</param>
 * <param name="weaponid">The reason that caused the damage</param>
 * <param name="bodypart">The body part that was hit</param>
 * <seealso name="CreateActor" />
 * <seealso name="SetActorInvulnerable" />
 * <seealso name="SetActorHealth" />
 * <seealso name="GetActorHealth" />
 * <seealso name="IsActorInvulnerable" />
 * <seealso name="IsValidActor" />
 * <seealso name="OnActorStreamOut" />
 * <seealso name="OnPlayerStreamIn" />
 * <remarks>This function does not get called if the actor is set invulnerable (WHICH IS BY DEFAULT).
 *  See <a href="#SetActorInvulnerable">SetActorInvulnerable</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b> - Callback will not be called in other filterscripts.<br />
 *   <b><c>0</c></b> - Allows this callback to be called in other filterscripts.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnPlayerGiveDamageActor(playerid, damaged_actorid, Float:amount, WEAPON:weaponid, bodypart);

/**
 * <summary>This callback is called when an actor is streamed in by a player's client.</summary>
 * <param name="actorid">The ID of the actor that has been streamed in for the player</param>
 * <param name="forplayerid">The ID of the player that streamed the actor in</param>
 * <seealso name="OnActorStreamOut" />
 * <seealso name="OnPlayerStreamIn" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>It is always called first in filterscripts.</remarks>
 * <returns>This callback does not handle returns.</returns>
 */
forward OnActorStreamIn(actorid, forplayerid);

/**
 * <summary>This callback is called when an actor is streamed out by a player's client.</summary>
 * <param name="actorid">The ID of the actor that has been streamed out for the player</param>
 * <param name="forplayerid">The ID of the player that streamed the actor out</param>
 * <seealso name="OnActorStreamIn" />
 * <seealso name="OnPlayerStreamOut" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>It is always called first in filterscripts.</remarks>
 * <returns>This callback does not handle returns.</returns>
 */
forward OnActorStreamOut(actorid, forplayerid);
