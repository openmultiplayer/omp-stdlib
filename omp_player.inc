#if defined _INC_omp_player
	#endinput
#endif
#define _INC_omp_player

/**
 * <library name="omp_player" summary="open.mp player functions.">
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
 * <library>omp_player</library>
 */
#if defined MAX_PLAYERS
	#if MAX_PLAYERS < 1 || MAX_PLAYERS > 1000
		#error MAX_PLAYERS must be >= 1 and <= 1000
	#endif

	const __MAX_PLAYERS                        = MAX_PLAYERS;
	#define __MAX_PLAYERS
#else
	const MAX_PLAYERS                          = 1000;
	#define MAX_PLAYERS                        1000
#endif

/**
 * <library>omp_player</library>
 */
#if defined MAX_PLAYER_NAME
	#if MAX_PLAYER_NAME < 3 || MAX_PLAYER_NAME > 24
		#error MAX_PLAYER_NAME must be >= 3 and <= 24
	#endif

	const __MAX_PLAYER_NAME                    = MAX_PLAYER_NAME;
	#define __MAX_PLAYER_NAME
#else
	const MAX_PLAYER_NAME                      = 24;
	#define MAX_PLAYER_NAME                    24
#endif

/**
 * <library>omp_player</library>
 */
#if defined MAX_PLAYER_ATTACHED_OBJECTS
	#if MAX_PLAYER_ATTACHED_OBJECTS < 1 || MAX_PLAYER_ATTACHED_OBJECTS > 10
		#error MAX_PLAYER_ATTACHED_OBJECTS must be >= 1 and <= 10
	#endif

	const __MAX_PLAYER_ATTACHED_OBJECTS        = MAX_PLAYER_ATTACHED_OBJECTS;
	#define __MAX_PLAYER_ATTACHED_OBJECTS
#else
	const MAX_PLAYER_ATTACHED_OBJECTS          = 10;
	#define MAX_PLAYER_ATTACHED_OBJECTS        10
#endif

/**
 * <library>omp_player</library>
 */
#if defined MAX_CHATBUBBLE_LENGTH
	#if MAX_CHATBUBBLE_LENGTH < 1 || MAX_CHATBUBBLE_LENGTH > 144
		#error MAX_CHATBUBBLE_LENGTH must be >= 1 and <= 144
	#endif

	const __MAX_CHATBUBBLE_LENGTH              = MAX_CHATBUBBLE_LENGTH;
	#define __MAX_CHATBUBBLE_LENGTH
#else
	const MAX_CHATBUBBLE_LENGTH                = 144;
	#define MAX_CHATBUBBLE_LENGTH              144
#endif

/**
 * <library>omp_player</library>
 */
const NO_TEAM                                  = 0xFF;
#define NO_TEAM                                255

/**
 * <library>omp_player</library>
 */
const INVALID_PLAYER_ID                        = 0xFFFF;
#define INVALID_PLAYER_ID                      65535

/// <p/>
/**
 * <library>omp_player</library>
 * <summary>States</summary>
 */
#define PLAYER_STATE: __TAG(PLAYER_STATE):
enum PLAYER_STATE:__PLAYER_STATE
{
	UNKNOWN_PLAYER_STATE                       = -1,
	PLAYER_STATE_NONE,
	PLAYER_STATE_ONFOOT,
	PLAYER_STATE_DRIVER,
	PLAYER_STATE_PASSENGER,
	PLAYER_STATE_WASTED                        = 7,
	PLAYER_STATE_SPAWNED,
	PLAYER_STATE_SPECTATING
}
static stock PLAYER_STATE:_@PLAYER_STATE() { return __PLAYER_STATE; }

#define UNKNOWN_PLAYER_STATE                   (PLAYER_STATE:-1)
#define PLAYER_STATE_NONE                      (PLAYER_STATE:0)
#define PLAYER_STATE_ONFOOT                    (PLAYER_STATE:1)
#define PLAYER_STATE_DRIVER                    (PLAYER_STATE:2)
#define PLAYER_STATE_PASSENGER                 (PLAYER_STATE:3)
#define PLAYER_STATE_WASTED                    (PLAYER_STATE:7)
#define PLAYER_STATE_SPAWNED                   (PLAYER_STATE:8)
#define PLAYER_STATE_SPECTATING                (PLAYER_STATE:9)

/**
 * <library>omp_player</library>
 * <summary>Used internally</summary>
 */
#pragma deprecated Used internally.
const PLAYER_STATE:PLAYER_STATE_EXIT_VEH       = PLAYER_STATE:4;
#define PLAYER_STATE_EXIT_VEH                  (PLAYER_STATE:4)

/**
 * <library>omp_player</library>
 * <summary>Used internally</summary>
 */
#pragma deprecated Used internally.
const PLAYER_STATE:PLAYER_STATE_EXIT_VEHICLE   = PLAYER_STATE:4;
#define PLAYER_STATE_EXIT_VEHICLE              (PLAYER_STATE:4)

/**
 * <library>omp_player</library>
 * <summary>Used internally</summary>
 */
#pragma deprecated Used internally.
const PLAYER_STATE:PLAYER_STATE_ENTER_VEHICLE_DRV  = PLAYER_STATE:5;
#define PLAYER_STATE_ENTER_VEHICLE_DRV         (PLAYER_STATE:5)

/**
 * <library>omp_player</library>
 * <summary>Used internally</summary>
 */
#pragma deprecated Used internally.
#if __namemax > 31
	const PLAYER_STATE:PLAYER_STATE_ENTER_VEHICLE_DRIVER = PLAYER_STATE:5;
#else
	const __PLAYER_STATE_ENTER_VD = 0;
#endif
#define PLAYER_STATE_ENTER_VEHICLE_DRIVER      (PLAYER_STATE:5)

/**
 * <library>omp_player</library>
 * <summary>Used internally</summary>
 */
#pragma deprecated Used internally.
const PLAYER_STATE:PLAYER_STATE_ENTER_VEHICLE_PASS = PLAYER_STATE:6;
#define PLAYER_STATE_ENTER_VEHICLE_PASS        (PLAYER_STATE:6)

/**
 * <library>omp_player</library>
 * <summary>Used internally</summary>
 */
#pragma deprecated Used internally.
#if __namemax > 31
	const PLAYER_STATE:PLAYER_STATE_ENTER_VEHICLE_PASSENGER = PLAYER_STATE:6;
#else
	const __PLAYER_STATE_ENTER_VP = 0;
#endif
#define PLAYER_STATE_ENTER_VEHICLE_PASSENGER   (PLAYER_STATE:6)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define SPECIAL_ACTION: __TAG(SPECIAL_ACTION):
enum SPECIAL_ACTION:__SPECIAL_ACTION
{
	UNKNOWN_SPECIAL_ACTION                     = -1,
	SPECIAL_ACTION_NONE,
	SPECIAL_ACTION_DUCK,
	SPECIAL_ACTION_USEJETPACK,
	SPECIAL_ACTION_ENTER_VEHICLE,
	SPECIAL_ACTION_EXIT_VEHICLE,
	SPECIAL_ACTION_DANCE1,
	SPECIAL_ACTION_DANCE2,
	SPECIAL_ACTION_DANCE3,
	SPECIAL_ACTION_DANCE4,
	SPECIAL_ACTION_HANDSUP                     = 10,
	SPECIAL_ACTION_USECELLPHONE,
	SPECIAL_ACTION_SITTING,
	SPECIAL_ACTION_STOPUSECELLPHONE,
	SPECIAL_ACTION_DRINK_BEER                  = 20,
	SPECIAL_ACTION_SMOKE_CIGGY,
	SPECIAL_ACTION_DRINK_WINE,
	SPECIAL_ACTION_DRINK_SPRUNK,
	SPECIAL_ACTION_CUFFED,
	SPECIAL_ACTION_CARRY,
	SPECIAL_ACTION_PISSING                     = 68
}
static stock SPECIAL_ACTION:_@SPECIAL_ACTION() { return __SPECIAL_ACTION; }

#define UNKNOWN_SPECIAL_ACTION                 (SPECIAL_ACTION:-1)
#define SPECIAL_ACTION_NONE                    (SPECIAL_ACTION:0)
#define SPECIAL_ACTION_DUCK                    (SPECIAL_ACTION:1)
#define SPECIAL_ACTION_USEJETPACK              (SPECIAL_ACTION:2)
#define SPECIAL_ACTION_ENTER_VEHICLE           (SPECIAL_ACTION:3)
#define SPECIAL_ACTION_EXIT_VEHICLE            (SPECIAL_ACTION:4)
#define SPECIAL_ACTION_DANCE1                  (SPECIAL_ACTION:5)
#define SPECIAL_ACTION_DANCE2                  (SPECIAL_ACTION:6)
#define SPECIAL_ACTION_DANCE3                  (SPECIAL_ACTION:7)
#define SPECIAL_ACTION_DANCE4                  (SPECIAL_ACTION:8)
#define SPECIAL_ACTION_HANDSUP                 (SPECIAL_ACTION:10)
#define SPECIAL_ACTION_USECELLPHONE            (SPECIAL_ACTION:11)
#define SPECIAL_ACTION_SITTING                 (SPECIAL_ACTION:12)
#define SPECIAL_ACTION_STOPUSECELLPHONE        (SPECIAL_ACTION:13)
#define SPECIAL_ACTION_DRINK_BEER              (SPECIAL_ACTION:20)
#define SPECIAL_ACTION_SMOKE_CIGGY             (SPECIAL_ACTION:21)
#define SPECIAL_ACTION_DRINK_WINE              (SPECIAL_ACTION:22)
#define SPECIAL_ACTION_DRINK_SPRUNK            (SPECIAL_ACTION:23)
#define SPECIAL_ACTION_CUFFED                  (SPECIAL_ACTION:24)
#define SPECIAL_ACTION_CARRY                   (SPECIAL_ACTION:25)
#define SPECIAL_ACTION_PISSING                 (SPECIAL_ACTION:68)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define FIGHT_STYLE: __TAG(FIGHT_STYLE):
enum FIGHT_STYLE:MAX_FIGHT_STYLES
{
	UNKNOWN_FIGHT_STYLE                        = -1,
	FIGHT_STYLE_NORMAL                         = 4,
	FIGHT_STYLE_BOXING,
	FIGHT_STYLE_KUNGFU,
	FIGHT_STYLE_KNEEHEAD,
	FIGHT_STYLE_GRABKICK                       = 15,
	FIGHT_STYLE_ELBOW
}
static stock FIGHT_STYLE:_@FIGHT_STYLE() { return MAX_FIGHT_STYLES; }

#define UNKNOWN_FIGHT_STYLE                    (FIGHT_STYLE:-1)
#define FIGHT_STYLE_NORMAL                     (FIGHT_STYLE:4)
#define FIGHT_STYLE_BOXING                     (FIGHT_STYLE:5)
#define FIGHT_STYLE_KUNGFU                     (FIGHT_STYLE:6)
#define FIGHT_STYLE_KNEEHEAD                   (FIGHT_STYLE:7)
#define FIGHT_STYLE_GRABKICK                   (FIGHT_STYLE:15)
#define FIGHT_STYLE_ELBOW                      (FIGHT_STYLE:16)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define WEAPONSKILL: __TAG(WEAPONSKILL):
enum WEAPONSKILL:MAX_WEAPONSKILLS
{
	UNKNOWN_WEAPONSKILL                        = -1,
	WEAPONSKILL_PISTOL,
	WEAPONSKILL_PISTOL_SILENCED,
	WEAPONSKILL_DESERT_EAGLE,
	WEAPONSKILL_SHOTGUN,
	WEAPONSKILL_SAWNOFF_SHOTGUN,
	WEAPONSKILL_SPAS12_SHOTGUN,
	WEAPONSKILL_MICRO_UZI,
	WEAPONSKILL_MP5,
	WEAPONSKILL_AK47,
	WEAPONSKILL_M4,
	WEAPONSKILL_SNIPERRIFLE
}
static stock WEAPONSKILL:_@WEAPONSKILL() { return MAX_WEAPONSKILLS; }

#define UNKNOWN_WEAPONSKILL                    (WEAPONSKILL:-1)
#define WEAPONSKILL_PISTOL                     (WEAPONSKILL:0)
#define WEAPONSKILL_PISTOL_SILENCED            (WEAPONSKILL:1)
#define WEAPONSKILL_DESERT_EAGLE               (WEAPONSKILL:2)
#define WEAPONSKILL_SHOTGUN                    (WEAPONSKILL:3)
#define WEAPONSKILL_SAWNOFF_SHOTGUN            (WEAPONSKILL:4)
#define WEAPONSKILL_SPAS12_SHOTGUN             (WEAPONSKILL:5)
#define WEAPONSKILL_MICRO_UZI                  (WEAPONSKILL:6)
#define WEAPONSKILL_MP5                        (WEAPONSKILL:7)
#define WEAPONSKILL_AK47                       (WEAPONSKILL:8)
#define WEAPONSKILL_M4                         (WEAPONSKILL:9)
#define WEAPONSKILL_SNIPERRIFLE                (WEAPONSKILL:10)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define WEAPONSTATE: __TAG(WEAPONSTATE):
enum WEAPONSTATE:__WEAPONSTATE
{
	UNKNOWN_WEAPONSTATE                        = -1,
	WEAPONSTATE_UNKNOWN                        = UNKNOWN_WEAPONSTATE,
	WEAPONSTATE_NO_BULLETS,
	WEAPONSTATE_LAST_BULLET,
	WEAPONSTATE_MORE_BULLETS,
	WEAPONSTATE_RELOADING
}
static stock WEAPONSTATE:_@WEAPONSTATE() { return __WEAPONSTATE; }

#define UNKNOWN_WEAPONSTATE                    (WEAPONSTATE:-1)
#define WEAPONSTATE_NO_BULLETS                 (WEAPONSTATE:0)
#define WEAPONSTATE_LAST_BULLET                (WEAPONSTATE:1)
#define WEAPONSTATE_MORE_BULLETS               (WEAPONSTATE:2)
#define WEAPONSTATE_RELOADING                  (WEAPONSTATE:3)

#define WEAPONSTATE_UNKNOWN UNKNOWN_WEAPONSTATE

/// <p/>
/**
 * <library>omp_player</library>
 * <summary>Keys</summary>
 */
#define KEY: __TAG(KEY):
enum KEY:__KEY (<<= 1)
{
	UNKNOWN_KEY                                = -1,
	KEY_NONE                                   = 0,
	KEY_ACTION                                 = 1,
	KEY_CROUCH,
	KEY_FIRE,
	KEY_SPRINT,
	KEY_SECONDARY_ATTACK,
	KEY_JUMP,
	KEY_LOOK_RIGHT,
	KEY_HANDBRAKE,
	KEY_AIM                                    = KEY_HANDBRAKE,
	KEY_LOOK_LEFT,
	KEY_SUBMISSION,
	KEY_LOOK_BEHIND                            = KEY_SUBMISSION,
	KEY_WALK,
	KEY_ANALOG_UP,
	KEY_ANALOG_DOWN,
	KEY_ANALOG_LEFT,
	KEY_ANALOG_RIGHT,
	KEY_YES                                    = 65536,
	KEY_NO,
	KEY_CTRL_BACK,

	KEY_UP                                     = -128,
	KEY_DOWN                                   =  128,
	KEY_LEFT                                   = -128,
	KEY_RIGHT                                  =  128
}
static stock KEY:_@KEY() { return __KEY; }

#define UNKNOWN_KEY                            (KEY:-1)
#define KEY_NONE                               (KEY:0x00000000)
#define KEY_ACTION                             (KEY:0x00000001)
#define KEY_CROUCH                             (KEY:0x00000002)
#define KEY_FIRE                               (KEY:0x00000004)
#define KEY_SPRINT                             (KEY:0x00000008)
#define KEY_SECONDARY_ATTACK                   (KEY:0x00000010)
#define KEY_JUMP                               (KEY:0x00000020)
#define KEY_LOOK_RIGHT                         (KEY:0x00000040)
#define KEY_HANDBRAKE                          (KEY:0x00000080)
#define KEY_AIM                                (KEY:0x00000080)
#define KEY_LOOK_LEFT                          (KEY:0x00000100)
#define KEY_SUBMISSION                         (KEY:0x00000200)
#define KEY_LOOK_BEHIND                        (KEY:0x00000200)
#define KEY_WALK                               (KEY:0x00000400)
#define KEY_ANALOG_UP                          (KEY:0x00000800)
#define KEY_ANALOG_DOWN                        (KEY:0x00001000)
#define KEY_ANALOG_LEFT                        (KEY:0x00002000)
#define KEY_ANALOG_RIGHT                       (KEY:0x00004000)
#define KEY_YES                                (KEY:0x00010000)
#define KEY_NO                                 (KEY:0x00020000)
#define KEY_CTRL_BACK                          (KEY:0x00040000)

// Untagged.
#define KEY_UP                                 (-128)
#define KEY_DOWN                               (128)
#define KEY_LEFT                               (-128)
#define KEY_RIGHT                              (128)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define CAM_MOVE: __TAG(CAM_MOVE):
enum CAM_MOVE:__CAMERA
{
	UNKNOWN_CAM_MOVE                           = -1,
	CAMERA_MOVE                                = 1,
	CAMERA_CUT
}
static stock CAMERA_MOVE:_@CAMERA_MOVE() { return __CAMERA_MOVE; }

#define UNKNOWN_CAM_MOVE                       (CAM_MOVE:-1)
#define CAMERA_MOVE                            (CAM_MOVE:1)
#define CAMERA_CUT                             (CAM_MOVE:2)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define CAM_MODE: __TAG(CAM_MODE):
enum CAM_MODE:__CAM_MODE
{
	UNKNOWN_CAM_MODE                           = -1,
	CAM_MODE_DISCONNECTED                      = -1,
	CAM_MODE_NONE                              = 0,
	CAM_MODE_BEHINDCAR                         = 3,
	CAM_MODE_FOLLOWPED                         = 4,
	CAM_MODE_SNIPER                            = 7,
	CAM_MODE_ROCKETLAUNCHER                    = 8,
	CAM_MODE_FIXED                             = 15,
	CAM_MODE_1STPERSON                         = 16,
	CAM_MODE_CAM_ON_A_STRING                   = 18,
	CAM_MODE_BEHINDBOAT                        = 22,
	CAM_MODE_CAMERA                            = 46,
	CAM_MODE_ROCKETLAUNCHER_HS                 = 51,
	CAM_MODE_AIMWEAPON                         = 53,
	CAM_MODE_AIMWEAPON_FROMCAR                 = 55,
	CAM_MODE_DW_HELI_CHASE                     = 56
}
static stock CAM_MODE:_@CAM_MODE() { return __CAM_MODE; }

#define UNKNOWN_CAM_MODE                       (CAM_MODE:-1)
#define CAM_MODE_DISCONNECTED                  (CAM_MODE:-1)
#define CAM_MODE_NONE                          (CAM_MODE:0)
#define CAM_MODE_BEHINDCAR                     (CAM_MODE:3)
#define CAM_MODE_FOLLOWPED                     (CAM_MODE:4)
#define CAM_MODE_SNIPER                        (CAM_MODE:7)
#define CAM_MODE_ROCKETLAUNCHER                (CAM_MODE:8)
#define CAM_MODE_FIXED                         (CAM_MODE:15)
#define CAM_MODE_1STPERSON                     (CAM_MODE:16)
#define CAM_MODE_CAM_ON_A_STRING               (CAM_MODE:18)
#define CAM_MODE_BEHINDBOAT                    (CAM_MODE:22)
#define CAM_MODE_CAMERA                        (CAM_MODE:46)
#define CAM_MODE_ROCKETLAUNCHER_HS             (CAM_MODE:51)
#define CAM_MODE_AIMWEAPON                     (CAM_MODE:53)
#define CAM_MODE_AIMWEAPON_FROMCAR             (CAM_MODE:55)
#define CAM_MODE_DW_HELI_CHASE                 (CAM_MODE:56)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define MAPICON: __TAG(MAPICON):
enum MAPICON:__MAPICON
{
	UNKNOWN_MAPICON                            = -1,
	MAPICON_LOCAL,                             // Displays in the player's local area
	MAPICON_GLOBAL,                            // Displays always
	MAPICON_LOCAL_CHECKPOINT,                  // Displays in the player's local area and has a checkpoint marker
	MAPICON_GLOBAL_CHECKPOINT                  // Displays always and has a checkpoint marker
}
static stock MAPICON:_@MAPICON() { return __MAPICON; }

#define UNKNOWN_MAPICON                        (MAPICON:-1)
#define MAPICON_LOCAL                          (MAPICON:0) // Displays in the player's local area.
#define MAPICON_GLOBAL                         (MAPICON:1) // Displays always.
#define MAPICON_LOCAL_CHECKPOINT               (MAPICON:2) // Displays in the player's local area and has a checkpoint marker.
#define MAPICON_GLOBAL_CHECKPOINT              (MAPICON:3) // Displays always and has a checkpoint marker.

/// <p/>
/**
 * <library>omp_player</library>
 * <summary>Spectating</summary>
 */
#define SPECTATE_MODE: __TAG(SPECTATE_MODE):
enum SPECTATE_MODE:__SPECTATE_MODE
{
	UNKNOWN_SPECTATE_MODE                      = -1,
	SPECTATE_MODE_NORMAL                       = 1,
	SPECTATE_MODE_FIXED,
	SPECTATE_MODE_SIDE
}
static stock SPECTATE_MODE:_@SPECTATE_MODE() { return __SPECTATE_MODE; }

#define UNKNOWN_SPECTATE_MODE                  (SPECTATE_MODE:-1)
#define SPECTATE_MODE_NORMAL                   (SPECTATE_MODE:1)
#define SPECTATE_MODE_FIXED                    (SPECTATE_MODE:2)
#define SPECTATE_MODE_SIDE                     (SPECTATE_MODE:3)

/// <p/>
/**
 * <library>omp_player</library>
 * <summary>Recording for NPC playback</summary>
 */
#define PLAYER_RECORDING_TYPE: __TAG(PLAYER_RECORDING_TYPE):
enum PLAYER_RECORDING_TYPE:__PLAYER_RECORDING_TYPE
{
	UNKNOWN_PLAYER_RECORDING_TYPE              = -1,
	PLAYER_RECORDING_TYPE_NONE,
	PLAYER_RECORDING_TYPE_DRIVER,
	PLAYER_RECORDING_TYPE_ONFOOT
}
static stock PLAYER_RECORDING_TYPE:_@PLAYER_RECORDING_TYPE() { return __PLAYER_RECORDING_TYPE; }

#define UNKNOWN_PLAYER_RECORDING_TYPE          (PLAYER_RECORDING_TYPE:-1)
#define PLAYER_RECORDING_TYPE_NONE             (PLAYER_RECORDING_TYPE:0)
#define PLAYER_RECORDING_TYPE_DRIVER           (PLAYER_RECORDING_TYPE:1)
#define PLAYER_RECORDING_TYPE_ONFOOT           (PLAYER_RECORDING_TYPE:2)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define FORCE_SYNC: __TAG(FORCE_SYNC):
enum FORCE_SYNC:__FORCE_SYNC
{
	UNKNOWN_FORCE_SYNC                         = -1,
	//REMOVE_FROM_VEHICLES                       = 128, // Remove players from vehicles.
	SYNC_NONE                                  = 0, // Don't force sync to anyone else.
	SYNC_ALL,                                  // Sync to all streamed-in players.
	SYNC_OTHER                                 // Sync to all streamed-in players, except the player with the animation.
}
static stock FORCE_SYNC:_@FORCE_SYNC() { return __FORCE_SYNC; }

#define UNKNOWN_FORCE_SYNC                     (FORCE_SYNC:-1)
//#define REMOVE_FROM_VEHICLES                   (FORCE_SYNC:128) // Remove players from vehicles.
#define SYNC_NONE                              (FORCE_SYNC:0) // Don't force sync to anyone else.
#define SYNC_ALL                               (FORCE_SYNC:1) // Sync to all streamed-in players.
#define SYNC_OTHER                             (FORCE_SYNC:2) // Sync to all streamed-in players, except the player with the animation.

/// <p/>
/**
 * <library>omp_player</library>
 */
#define CLICK_SOURCE: __TAG(CLICK_SOURCE):
enum CLICK_SOURCE:__CLICK_SOURCE
{
	UNKNOWN_CLICK_SOURCE                       = -1,
	CLICK_SOURCE_SCOREBOARD
}
static stock CLICK_SOURCE:_@CLICK_SOURCE() { return __CLICK_SOURCE; }

#define UNKNOWN_CLICK_SOURCE                   (CLICK_SOURCE:-1)
#define CLICK_SOURCE_SCOREBOARD                (CLICK_SOURCE:0)

/// <p/>
/**
 * <library>omp_player</library>
 */
#define BULLET_HIT_TYPE: __TAG(BULLET_HIT_TYPE):
enum BULLET_HIT_TYPE:__BULLET_HIT_TYPE
{
	UNKNOWN_BULLET_HIT_TYPE                    = -1,
	BULLET_HIT_TYPE_NONE,
	BULLET_HIT_TYPE_PLAYER,
	BULLET_HIT_TYPE_VEHICLE,
	BULLET_HIT_TYPE_OBJECT,
	BULLET_HIT_TYPE_PLAYER_OBJECT
}
static stock BULLET_HIT_TYPE:_@BULLET_HIT_TYPE() { return __BULLET_HIT_TYPE; }

#define UNKNOWN_BULLET_HIT_TYPE                (BULLET_HIT_TYPE:-1)
#define BULLET_HIT_TYPE_NONE                   (BULLET_HIT_TYPE:0)
#define BULLET_HIT_TYPE_PLAYER                 (BULLET_HIT_TYPE:1)
#define BULLET_HIT_TYPE_VEHICLE                (BULLET_HIT_TYPE:2)
#define BULLET_HIT_TYPE_OBJECT                 (BULLET_HIT_TYPE:3)
#define BULLET_HIT_TYPE_PLAYER_OBJECT          (BULLET_HIT_TYPE:4)

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
native #World()
*/

/**
 * <library>omp_player</library>
 * <summary>Set a player's wanted level (6 brown stars under HUD).</summary>
 * <param name="playerid">The ID of the player to set the wanted level of</param>
 * <param name="level">The wanted level to set for the player (0-6)</param>
 * <seealso name="GetPlayerWantedLevel" />
 * <seealso name="PlayCrimeReportForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:SetPlayerWantedLevel(playerid, level);

/**
 * <library>omp_player</library>
 * <summary>Gets the wanted level of a player.</summary>
 * <param name="playerid">The ID of the player that you want to get the wanted level of</param>
 * <seealso name="SetPlayerWantedLevel" />
 * <seealso name="PlayCrimeReportForPlayer" />
 * <returns>The player's wanted level.</returns>
 */
native GetPlayerWantedLevel(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set a player's weather.</summary>
 * <param name="playerid">The ID of the player whose weather to set</param>
 * <param name="weather">The <a href="https://www.open.mp/docs/scripting/resources/weatherid">weather</a> to set</param>
 * <seealso name="SetWeather" />
 * <seealso name="SetGravity" />
 * <remarks>If <a href="#TogglePlayerClock">TogglePlayerClock</a> is enabled, weather will slowly change
 * over time, instead of changing instantly.</remarks>
 */
native bool:SetPlayerWeather(playerid, weather);

/**
 * <library>omp_player</library>
 */
native GetPlayerWeather(playerid);

/**
 * <library>omp_player</library>
 * <summary>Loads or unloads an interior script for a player (for example the ammunation menu).</summary>
 * <param name="playerid">The ID of the player to load the interior script for</param>
 * <param name="shopName">The shop script to load.  Leave blank ("") to unload scripts</param>
 * <seealso name="DisableInteriorEnterExits" />
 * <seealso name="SetPlayerInterior" />
 * <remarks>This function does not support casino scripts.</remarks>
 * <remarks>
 *   <b>Shop names:</b><br />
 *   <ul>
 *     <li><b><c>"FDPIZA"</c></b> Pizza Stack</li>
 *     <li><b><c>"FDBURG"</c></b> Burger Shot</li>
 *     <li><b><c>"FDCHICK"</c></b>Cluckin' Bell</li>
 *     <li><b><c>"AMMUN1"</c></b> Ammunation 1</li>
 *     <li><b><c>"AMMUN2"</c></b> Ammunation 2</li>
 *     <li><b><c>"AMMUN3"</c></b> Ammunation 3</li>
 *     <li><b><c>"AMMUN4"</c></b> Ammunation 4</li>
 *     <li><b><c>"AMMUN5"</c></b> Ammunation 5</li>
 *   </ul>
 * </remarks>
 */
native bool:SetPlayerShopName(playerid, const shopName[]);

/**
 * <library>omp_player</library>
 * <summary>Play an 'audio stream' for a player.  Normal audio files also work (e.g.  MP3).</summary>
 * <param name="playerid">The ID of the player to play the audio for</param>
 * <param name="url">The url to play.  Valid formats are mp3 and ogg/vorbis.  A link to a .pls (playlist)
 * file will play that playlist</param>
 * <param name="posX">The x position at which to play the audio.  Has no effect unless usepos is set
 * to 1 (optional=<b><c>0.0</c></b>)</param>
 * <param name="posY">The y position at which to play the audio.  Has no effect unless usepos is set
 * to 1 (optional=<b><c>0.0</c></b>)</param>
 * <param name="posZ">The z position at which to play the audio.  Has no effect unless usepos is set
 * to 1 (optional=<b><c>0.0</c></b>)</param>
 * <param name="distance">The distance over which the audio will be heard.  Has no effect unless usepos
 * is set to 1 (optional=<b><c>50.0</c></b>)</param>
 * <param name="usepos">Use the positions and distance specified. (optional=<b><c>0</c></b>)</param>
 * <seealso name="StopAudioStreamForPlayer" />
 * <seealso name="PlayerPlaySound" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:PlayAudioStreamForPlayer(playerid, const url[], Float:posX = 0.0, Float:posY = 0.0, Float:posZ = 0.0, Float:distance = 50.0, bool:usepos = false);

/**
 * <library>omp_player</library>
 * <summary>Stops the current audio stream for a player.</summary>
 * <param name="playerid">The player you want to stop the audio stream for</param>
 * <seealso name="PlayAudioStreamForPlayer" />
 * <seealso name="PlayerPlaySound" />
 */
native bool:StopAudioStreamForPlayer(playerid);

/**
 * <library>omp_player</library>
 * <summary>Creates an explosion that is only visible to a single player.  This can be used to isolate
 * explosions from other players or to make them only appear in specific
 * <a href="https://www.open.mp/docs/scripting/functions/SetPlayerVirtualWorld">virtual
 * worlds</a>.</summary>
 * <param name="playerid">The ID of the player to create the explosion for</param>
 * <param name="x">The x coordinate of the explosion</param>
 * <param name="y">The y coordinate of the explosion</param>
 * <param name="z">The z coordinate of the explosion</param>
 * <param name="type">The explosion type</param>
 * <param name="radius">The radius of the explosion</param>
 * <seealso name="CreateExplosion" />
 * <remarks>There is a limit as to how many explosions can be seen at once by a player.  This is roughly
 * 10.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if the function failed to excute (player
 * doesn't exist, invalid radius, or invalid explosion type).</returns>
 */
native bool:CreateExplosionForPlayer(playerid, Float:x, Float:y, Float:z, type, Float:radius);

/**
 * <library>omp_player</library>
 * <summary>Sets the game time for a player.  If a player's clock is enabled (<a href="#TogglePlayerClock">TogglePlayerClock</a>)
 * the time displayed by it will update automatically.</summary>
 * <param name="playerid">The ID of the player to set the game time of</param>
 * <param name="hour">Hour to set (0-23)</param>
 * <param name="minute">Minutes to set (0-59)</param>
 * <seealso name="SetWorldTime" />
 * <seealso name="GetPlayerTime" />
 * <seealso name="TogglePlayerClock" />
 * <remarks>Using this function under <a href="#OnPlayerConnect">OnPlayerConnect</a> doesn't work.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:SetPlayerTime(playerid, hour, minute);

/**
 * <library>omp_player</library>
 * <summary>Get the player's current game time.  Set by <a href="#SetWorldTime">SetWorldTime</a> or
 * <a href="#SetPlayerTime">SetPlayerTime</a>, or by the game automatically if <a href="#TogglePlayerClock">TogglePlayerClock</a>
 * is used.</summary>
 * <param name="playerid">The ID of the player to get the game time of</param>
 * <param name="hour">A variable in which to store the hour, passed by reference</param>
 * <param name="minute">A variable in which to store the minutes, passed by reference</param>
 * <seealso name="SetPlayerTime" />
 * <seealso name="SetWorldTime" />
 * <seealso name="TogglePlayerClock" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.<br />
 * </returns>
 */
native bool:GetPlayerTime(playerid, &hour, &minute);

/**
 * <library>omp_player</library>
 * <summary>Checks whether this player has their in-game clock enabled.</summary>
 * <param name="playerid">The player whose clock you want to check</param>
 * <remarks>Time is not synced with other players! Time can be synced using <a href="#SetPlayerTime">SetPlayerTime</a>.</remarks>
 * <remarks>Time will automatically advance 6 hours when the player dies.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The clock is enabled.<br />
 *   <b><c>0</c></b>: The clock isn't enabled, or the specified player does not exist.
 * </returns>
 */
native bool:PlayerHasClockEnabled(playerid);

/**
 * <library>omp_player</library>
 * <summary>Toggle the in-game clock (top-right corner) for a specific player.  When this is enabled,
 * time will progress at 1 minute per second.  Weather will also interpolate (slowly change over time)
 * when set using <a href="#SetWeather">SetWeather</a>/<a href="#SetPlayerWeather">SetPlayerWeather</a>.</summary>
 * <param name="playerid">The player whose clock you want to enable/disable</param>
 * <param name="toggle"><b><c>1</c></b> to show and <b><c>0</c></b> to hide.  Hidden by default</param>
 * <remarks>Time is not synced with other players! Time can be synced using <a href="#SetPlayerTime">SetPlayerTime</a>.</remarks>
 * <remarks>Time will automatically advance 6 hours when the player dies.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The specified player does not exist.
 * </returns>
 */
native bool:TogglePlayerClock(playerid, bool:toggle);

/**
 * <library>omp_player</library>
 * <summary>Plays the specified sound for a player.</summary>
 * <param name="playerid">The ID of the player for whom to play the sound</param>
 * <param name="soundid">The sound to play</param>
 * <param name="x">x coordinate for the sound to play at. (<b><c>optional=0.0</c></b>)</param>
 * <param name="y">y coordinate for the sound to play at. (<b><c>optional=0.0</c></b>)</param>
 * <param name="z">z coordinate for the sound to play at. (<b><c>optional=0.0</c></b>)</param>
 * <seealso name="PlayCrimeReportForPlayer" />
 * <seealso name="PlayAudioStreamForPlayer" />
 * <seealso name="StopAudioStreamForPlayer" />
 * <remarks>Only use the coordinates if you want the sound to be played at a certain position. By
 * default, the sound will be played with no position at a certain position.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:PlayerPlaySound(playerid, soundid, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0);

/**
 * <library>omp_player</library>
 * <summary>Set the world boundaries for a player.  Players can not go out of the boundaries (they will
 * be pushed back in).</summary>
 * <param name="playerid">The ID of the player to set the world boundaries of</param>
 * <param name="maxX">The maximum x coordinate the player can go to</param>
 * <param name="minX">The minimum x coordinate the player can go to</param>
 * <param name="maxY">The maximum y coordinate the player can go to</param>
 * <param name="minY">The minimum y coordinate the player can go to</param>
 * <seealso name="GangZoneCreate" />
 * <remarks>This function does not work if used in <a href="#OnPlayerConnect">OnPlayerConnect</a></remarks>
 * <remarks>A player's world boundaries can be reset by setting them to <b><c>20000.0</c></b>, <b><c>-20000.0</c></b>,
 * <b><c>20000.0</c></b>, <b><c>-20000.0</c></b>.  These are the default values.</remarks>
 * <remarks>This function doesn't work in interiors!</remarks>
 */
native bool:SetPlayerWorldBounds(playerid, Float:maxX, Float:minX, Float:maxY, Float:minY);

/**
 * <library>omp_player</library>
 */
native bool:ClearPlayerWorldBounds(playerid);

/**
 * <library>omp_player</library>
 */
native bool:GetPlayerWorldBounds(playerid, &Float:maxX, &Float:minX, &Float:maxY, &Float:minY);

/**
 * <library>omp_player</library>
 * <summary>Removes a standard San Andreas model for a single player within a specified range.</summary>
 * <param name="playerid">The ID of the player to remove the objects for</param>
 * <param name="modelid">The model to remove</param>
 * <param name="centerX">The x coordinate around which the objects will be removed</param>
 * <param name="centerY">The y coordinate around which the objects will be removed</param>
 * <param name="centerZ">The z coordinate around which the objects will be removed</param>
 * <param name="radius">The radius around the specified point to remove objects with the specified model</param>
 * <seealso name="DestroyObject" />
 * <seealso name="DestroyPlayerObject" />
 * <remarks>There appears to be a limit of around <b><c>1000</c></b> lines/objects.  There is no workaround.
 * </remarks>
 * <remarks>When removing the same object for a player, they will crash.  Commonly, players crash when
 * reconnecting to the server because the server removes buildings on <a href="#OnPlayerConnect">OnPlayerConnect</a>.
 * </remarks>
 * <remarks>You can use <b><c>-1</c></b> for the modelid to remove all objects
 * within the specified radius.</remarks>
 */
native bool:RemoveBuildingForPlayer(playerid, modelid, Float:centerX, Float:centerY, Float:centerZ, Float:radius);

/**
 * <library>omp_player</library>
 */
native GetPlayerBuildingsRemoved(playerid);

/**
 * <library>omp_player</library>
 * <summary>Removes a map icon that was set earlier for a player using <a href="#SetPlayerMapIcon">SetPlayerMapIcon</a>.</summary>
 * <param name="playerid">The ID of the player whose icon to remove</param>
 * <param name="iconid">The ID of the icon to remove.  This is the second parameter of
 * <a href="#SetPlayerMapIcon">SetPlayerMapIcon</a></param>
 * <seealso name="SetPlayerMapIcon" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:RemovePlayerMapIcon(playerid, iconid);

/**
 * <library>omp_player</library>
 * <summary>Place an icon/marker on a player's map.  Can be used to mark locations such as banks and
 * hospitals to players.</summary>
 * <param name="playerid">The ID of the player to set the map icon for</param>
 * <param name="iconid">The player's icon ID, ranging from <b><c>0</c></b> to <b><c>99</c></b>.  This
 * means there is a maximum of <b><c>100</c></b> map icons.  ID can be used in <a href="#RemovePlayerMapIcon">RemovePlayerMapIcon</a></param>
 * <param name="x">The x coordinate to place the map icon at</param>
 * <param name="y">The y coordinate to place the map icon at</param>
 * <param name="z">The z coordinate to place the map icon at</param>
 * <param name="markerType">The icon to set</param>
 * <param name="colour">The colour of the icon (<b>RGBA</b>).  This should only be used with the square
 * icon (ID: <b><c>0</c></b>)</param>
 * <param name="style">The style of icon (optional=<b><c>MAPICON_LOCAL</c></b>)</param>
 * <seealso name="RemovePlayerMapIcon" />
 * <seealso name="SetPlayerMarkerForPlayer" />
 * <remarks>If you use an invalid marker type, it will create ID <b><c>1</c></b> (White Square). </remarks>
 * <remarks>If you use an icon ID that is already in use, it will replace the current map icon using
 * that ID. </remarks>
 * <remarks>Marker type <b><c>1</c></b> (square), <b><c>2</c></b> (player blip), <b><c>4</c></b> (north),
 * and <b><c>56</c></b> (single airstrip blip) will cause your game to crash if you have map legends
 * enabled while viewing the map.</remarks>
 * <remarks>
 *   <b>Map icon styles:</b><br />
 *   <ul>
 *     <li><b><c>0 MAPICON_LOCAL</c></b> - close proximity only</li>
 *     <li><b><c>1 MAPICON_GLOBAL</c></b> - show on radar edge as long as in range</li>
 *     <li><b><c>2 MAPICON_LOCAL_CHECKPOINT</c></b> - Close proximity only (with checkpoint)</li>
 *     <li><b><c>3 MAPICON_GLOBAL_CHECKPOINT</c></b> - Show on radar edge as long as in range (with
 * checkpoint)</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Player is not connected.
 * </returns>
 */
native bool:SetPlayerMapIcon(playerid, iconid, Float:x, Float:y, Float:z, markerType, colour, MAPICON:style = MAPICON_LOCAL);

/**
 * <library>omp_player</library>
 * <summary>Toggle stunt bonuses for a player.  Enabled by default.</summary>
 * <param name="playerid">The ID of the player to toggle stunt bonuses for</param>
 * <param name="enable"><b><c>1</c></b> to enable stunt bonuses and <b><c>0</c></b> to disable them</param>
 * <seealso name="EnableStuntBonusForAll" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player is not connected.
 * </returns>
 */
native bool:EnableStuntBonusForPlayer(playerid, bool:enable);

/**
 * <library>omp_player</library>
 * <summary>Checks if a player is in range of a point.  This native function is faster than the PAWN
 * implementation using distance formula.</summary>
 * <param name="playerid">The ID of the player</param>
 * <param name="range">The furthest distance the player can be from the point to be in range</param>
 * <param name="x">The x coordinate of the point to check the range to</param>
 * <param name="y">The y coordinate of the point to check the range to</param>
 * <param name="z">The z coordinate of the point to check the range to</param>
 * <seealso name="GetPlayerDistanceFromPoint" />
 * <seealso name="GetVehicleDistanceFromPoint" />
 * <seealso name="GetPlayerPos" />
 * <returns><b><c>1</c></b> if the player is in range, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerInRangeOfPoint(playerid, Float:range, Float:x, Float:y, Float:z);

/**
 * <library>omp_player</library>
 * <summary>This function plays a crime report for a player - just like in single-player when CJ commits
 * a crime.</summary>
 * <param name="playerid">The ID of the player that will hear the crime report</param>
 * <param name="suspectid">The ID of the suspect player whom will be described in the crime report</param>
 * <param name="crime">The crime ID, which will be reported as a 10-code (i.e.  10-16 if 16 was passed
 * as the crime)</param>
 * <seealso name="PlayerPlaySound" />
 * <remarks>
 *   <b>Crime list:</b><br />
 *   <ul>
 *     <li><b><c>3</c></b> 10-71 Advise nature of fire (size, type, contents of building)</li>
 *     <li><b><c>4</c></b> 10-47 Emergency road repairs needed</li>
 *     <li><b><c>5</c></b> 10-81 Breatherlizer Report</li>
 *     <li><b><c>6</c></b> 10-24 Assignment Completed</li>
 *     <li><b><c>7</c></b> 10-21 Call () by phone</li>
 *     <li><b><c>8</c></b> 10-21 Call () by phone</li>
 *     <li><b><c>9</c></b> 10-21 Call () by phone</li>
 *     <li><b><c>10</c></b> 10-17 Meet Complainant</li>
 *     <li><b><c>11</c></b> 10-81 Breatherlizer Report</li>
 *     <li><b><c>12</c></b> 10-91 Pick up prisoner/subject</li>
 *     <li><b><c>13</c></b> 10-28 Vehicle registration information</li>
 *     <li><b><c>14</c></b> 10-81 Breathalyzer</li>
 *     <li><b><c>15</c></b> 10-28 Vehicle registration information</li>
 *     <li><b><c>16</c></b> 10-91 Pick up prisoner/subject</li>
 *     <li><b><c>17</c></b> 10-34 Riot</li>
 *     <li><b><c>18</c></b> 10-37 (Investigate) suspicious vehicle</li>
 *     <li><b><c>19</c></b> 10-81 Breathalyzer</li>
 *     <li><b><c>21</c></b> 10-7 Out of service</li>
 *     <li><b><c>22</c></b> 10-7 Out of service </li>
 *   </ul>
 * </remarks>
 */
native bool:PlayCrimeReportForPlayer(playerid, suspectid, crime);

/**
 * <library>omp_player</library>
 * <summary>Disables collisions between occupied vehicles for a player.</summary>
 * <param name="playerid">The ID of the player for whom you want to disable collisions</param>
 * <param name="disable"><b><c>1</c></b> to disable collisions, <b><c>0</c></b> to enable collisions</param>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:DisableRemoteVehicleCollisions(playerid, bool:disable);

/**
 * <library>omp_player</library>
 */
native bool:SetPlayerGravity(playerid, Float:gravity);

/**
 * <library>omp_player</library>
 */
native Float:GetPlayerGravity(playerid);

/*
native #Character()
*/

/**
 * <library>omp_player</library>
 * <summary>Sets the drunk level of a player which makes the player's camera sway and vehicles hard
 * to control.</summary>
 * <param name="playerid">The ID of the player to set the drunkenness of</param>
 * <param name="level">The level of drunkenness to set</param>
 * <seealso name="GetPlayerDrunkLevel" />
 * <remarks>
 *   Players' drunk level will automatically decrease over time, based on their FPS (players with <b><c>50</c></b>
 * FPS will lose <b><c>50</c></b> 'levels' per second.  This is useful for determining a player's FPS!).<br
 * />
 *   In <b>0.3a</b> the drunk level will decrement and stop at <b><c>2000</c></b>.  In <b>0.3b+</b>
 * the drunk level decrements to <b><c>0</c></b>)<br />
 *   Levels over <b><c>2000</c></b> make the player drunk (camera swaying and vehicles difficult to
 * control).<br />
 *   Max drunk level is <b><c>50000</c></b>.<br />
 *   While the drunk level is above <b><c>5000</c></b>, the player's HUD (radar etc.) will be hidden.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:SetPlayerDrunkLevel(playerid, level);

/**
 * <library>omp_player</library>
 * <summary>
 *   Checks the player's level of drunkenness.  If the level is less than <b><c>2000</c></b>, the player
 * is sober.  The player's level of drunkness goes down slowly automatically (1 level per frame) but
 * will always reach <b><c>2000</c></b> at the end (in <b>0.3b</b> it will stop at <b><c>0</c></b>).
 *   The higher drunkenness levels affect the player's camera, and the car driving handling.  The level
 * of drunkenness increases when the player drinks from a bottle (You can use <a href="#SetPlayerSpecialAction">SetPlayerSpecialAction</a>
 * to give them bottles).
 * </summary>
 * <param name="playerid">The player you want to check the drunkenness level of</param>
 * <seealso name="SetPlayerDrunkLevel" />
 * <returns>An integer with the level of drunkenness of the player.</returns>
 */
native GetPlayerDrunkLevel(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set a player's interior.  A list of currently known interiors and their positions can be
 * found <a href="https://www.open.mp/docs/scripting/resources/interiorids">here</a>.</summary>
 * <param name="playerid">The ID of the player to set the interior of</param>
 * <param name="interiorid">The <a href="https://www.open.mp/docs/scripting/resources/interiorids">interior ID</a> to
 * set the player in</param>
 * <seealso name="GetPlayerInterior" />
 * <seealso name="LinkVehicleToInterior" />
 * <seealso name="OnPlayerInteriorChange" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:SetPlayerInterior(playerid, interiorid);

/**
 * <library>omp_player</library>
 * <summary>Set the skin of a player.  A player's skin is their character model.</summary>
 * <param name="playerid">The ID of the player to set the skin of</param>
 * <param name="skinid">The <a href="https://www.open.mp/docs/scripting/resources/skins">skin</a> the player should use</param>
 * <seealso name="GetPlayerSkin" />
 * <seealso name="SetSpawnInfo" />
 * <remarks>If a player's skin is set when they are crouching, in a vehicle, or performing certain animations,
 * they will become frozen or otherwise glitched.  This can be fixed by using
 * <a href="#TogglePlayerControllable">TogglePlayerControllable</a>.
 *  Players can be detected as being crouched through <a href="#GetPlayerSpecialAction">GetPlayerSpecialAction</a>
 * (<b><c>SPECIAL_ACTION_DUCK</c></b>).</remarks>
 * <remarks>Setting a player's skin when he is dead may crash players around him.</remarks>
 * <remarks>Note that 'success' is reported even when skin ID is invalid (not <b><c>0</c></b>-<b><c>311</c></b>,
 * or <b><c>74</c></b>), but the skin will be set to ID <b><c>0</c></b> (CJ).</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.<br
 * />
 * </returns>
 */
native bool:SetPlayerSkin(playerid, skinid);

/**
 * <library>omp_player</library>
 * <summary>Returns the class of the players skin.</summary>
 * <param name="playerid">The player you want to get the skin from</param>
 * <seealso name="SetPlayerSkin" />
 * <remarks>Returns the new skin after <a href="#SetSpawnInfo">SetSpawnInfo</a> is called but before
 * the player actually respawns to get the new skin. </remarks>
 * <remarks>Returns the old skin if the player was spawned through <a href="#SpawnPlayer">SpawnPlayer</a>
 * function. </remarks>
 * <returns>The skin ID (<b><c>0</c></b> if invalid).</returns>
 */
native GetPlayerSkin(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set the health of a player.</summary>
 * <param name="playerid">The ID of the player to set the health of</param>
 * <param name="health">The value to set the player's health to.  Max health that can be displayed in
 * the HUD is <b><c>100</c></b>, though higher values are valid</param>
 * <seealso name="GetPlayerHealth" />
 * <seealso name="GetPlayerArmour" />
 * <seealso name="SetPlayerArmour" />
 * <remarks>Health is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b></remarks>
 * <remarks>If a player's health is set to <b><c>0</c></b> or a minus value, they will die instantly.</remarks>
 * <remarks>If a player's health is below <b><c>10</c></b> or above <b><c>98303</c></b>, their health
 * bar will flash. </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerHealth(playerid, Float:health);

/**
 * <library>omp_player</library>
 * <summary>The function GetPlayerHealth allows you to retrieve the health of a player.  Useful for
 * cheat detection, among other things.</summary>
 * <param name="playerid">The ID of the player</param>
 * <param name="health">Float to store health, passed by reference</param>
 * <seealso name="SetPlayerHealth" />
 * <seealso name="GetVehicleHealth" />
 * <seealso name="GetPlayerArmour" />
 * <remarks>
 *   Even though the health can be set to near infinite values on the server side, the individual clients
 * will only report values up to <b><c>255</c></b>.  Anything higher will wrap around; <b><c>256</c></b>
 * becomes <b><c>0</c></b>, <b><c>257</c></b> becomes <b><c>1</c></b>, etc.<br />
 *   Health is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b> - success.<br />
 *   <b><c>0</c></b> - failure (i.e.  player not connected).<br />
 * </returns>
 */
native bool:GetPlayerHealth(playerid, &Float:health);

/**
 * <library>omp_player</library>
 * <summary>Get a player's current state.</summary>
 * <param name="playerid">The ID of the player to get the current state of</param>
 * <seealso name="GetPlayerSpecialAction" />
 * <seealso name="SetPlayerSpecialAction" />
 * <seealso name="OnPlayerStateChange" />
 * <remarks>
 *   <b>States:</b><br />
 *   <ul>
 *     <li><b><c>PLAYER_STATE_NONE</c></b> - empty (while initializing)</li>
 *     <li><b><c>PLAYER_STATE_ONFOOT</c></b> - player is on foot</li>
 *     <li><b><c>PLAYER_STATE_DRIVER</c></b> - player is the driver of a vehicle</li>
 *     <li><b><c>PLAYER_STATE_PASSENGER</c></b> - player is passenger of a vehicle</li>
 *     <li><b><c>PLAYER_STATE_WASTED</c></b> - player is dead or on class selection</li>
 *     <li><b><c>PLAYER_STATE_SPAWNED</c></b> - player is spawned</li>
 *     <li><b><c>PLAYER_STATE_SPECTATING</c></b> - player is spectating</li>
 *     <li><b><c>PLAYER_STATE_EXIT_VEHICLE</c></b> - player exits a vehicle</li>
 *     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_DRIVER</c></b> - player enters a vehicle as driver</li>
 *     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_PASSENGER</c></b> - player enters a vehicle as passenger
 * </li>
 *   </ul>
 * </remarks>
 * <returns>The player's current state as an integer.</returns>
 */
native PLAYER_STATE:GetPlayerState(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set a player's special fighting style.  To use in-game, aim and press the 'secondary attack'
 * key (<b>ENTER</b> by default).</summary>
 * <param name="playerid">The ID of player to set the fighting style of</param>
 * <param name="style">The fighting style that should be set</param>
 * <seealso name="GetPlayerFightingStyle" />
 * <remarks>This does not affect normal fist attacks - only special/secondary attacks (aim + press 'secondary
 * attack' key).</remarks>
 * <remarks>
 *   <b>Fighting styles:</b><br />
 *   <ul>
 *     <li><b><c>FIGHT_STYLE_NORMAL</c></b></li>
 *     <li><b><c>FIGHT_STYLE_BOXING</c></b></li>
 *     <li><b><c>FIGHT_STYLE_KUNGFU</c></b></li>
 *     <li><b><c>FIGHT_STYLE_KNEEHEAD</c></b></li>
 *     <li><b><c>FIGHT_STYLE_GRABKICK</c></b></li>
 *     <li><b><c>FIGHT_STYLE_ELBOW</c></b></li>
 *   </ul>
 * </remarks>
 */
native bool:SetPlayerFightingStyle(playerid, FIGHT_STYLE:style);

/**
 * <library>omp_player</library>
 * <summary>Get the fighting style the player currently using.</summary>
 * <param name="playerid">The ID of the player to get the fighting style of</param>
 * <seealso name="SetPlayerFightingStyle" />
 * <remarks>
 *   <b>Fighting styles:</b><br />
 *   <ul>
 *     <li><b><c>FIGHT_STYLE_NORMAL</c></b></li>
 *     <li><b><c>FIGHT_STYLE_BOXING</c></b></li>
 *     <li><b><c>FIGHT_STYLE_KUNGFU</c></b></li>
 *     <li><b><c>FIGHT_STYLE_KNEEHEAD</c></b></li>
 *     <li><b><c>FIGHT_STYLE_GRABKICK</c></b></li>
 *     <li><b><c>FIGHT_STYLE_ELBOW</c></b></li>
 *   </ul>
 * </remarks>
 * <returns>The ID of the fighting style of the player.</returns>
 */
native FIGHT_STYLE:GetPlayerFightingStyle(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set a player's velocity on the x, y and z axes.</summary>
 * <param name="playerid">The player to apply the speed to</param>
 * <param name="x">The velocity (speed) on the x axis</param>
 * <param name="y">The velocity (speed) on the y axis</param>
 * <param name="z">The velocity (speed) on the z axis</param>
 * <seealso name="GetPlayerVelocity" />
 * <seealso name="SetVehicleVelocity" />
 * <seealso name="GetVehicleVelocity" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:SetPlayerVelocity(playerid, Float:x, Float:y, Float:z);

/**
 * <library>omp_player</library>
 * <summary>Get the velocity (speed) of a player on the x, y and z axes.</summary>
 * <param name="playerid">The player to get the speed from</param>
 * <param name="x">A float variable in which to store the velocity on the x axis, passed by reference</param>
 * <param name="y">A float variable in which to store the velocity on the y axis, passed by reference</param>
 * <param name="z">A float variable in which to store the velocity on the z axis, passed by reference</param>
 * <seealso name="SetPlayerVelocity" />
 * <seealso name="SetVehicleVelocity" />
 * <seealso name="GetVehicleVelocity" />
 */
native bool:GetPlayerVelocity(playerid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_player</library>
 * <summary>Calculate the distance between a player and a map coordinate.</summary>
 * <param name="playerid">The ID of the player to calculate the distance from</param>
 * <param name="x">The x map coordinate</param>
 * <param name="y">The y map coordinate</param>
 * <param name="z">The z map coordinate</param>
 * <seealso name="IsPlayerInRangeOfPoint" />
 * <seealso name="GetVehicleDistanceFromPoint" />
 * <seealso name="GetPlayerPos" />
 * <returns>The distance between the player and the point as a float.</returns>
 */
native Float:GetPlayerDistanceFromPoint(playerid, Float:x, Float:y, Float:z);

/**
 * <library>omp_player</library>
 * <summary>Retrieves the player's current interior.  A list of currently known interiors with their
 * positions can be found on <a href="https://www.open.mp/docs/scripting/resources/interiorids">this</a> page.</summary>
 * <param name="playerid">The player to get the interior ID of</param>
 * <seealso name="SetPlayerInterior" />
 * <seealso name="GetPlayerVirtualWorld" />
 * <remarks>Always returns <b><c>0</c></b> for NPCs.</remarks>
 * <returns>The interior ID the player is currently in.</returns>
 */
native GetPlayerInterior(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set a player's position.</summary>
 * <param name="playerid">The ID of the player to set the position of</param>
 * <param name="x">The x coordinate to position the player at</param>
 * <param name="y">The y coordinate to position the player at</param>
 * <param name="z">The z coordinate to position the player at</param>
 * <seealso name="SetPlayerPosFindZ" />
 * <seealso name="SetPlayerFacingAngle" />
 * <seealso name="GetPlayerPos" />
 * <seealso name="SetVehiclePos" />
 * <seealso name="GetVehiclePos" />
 * <remarks>Using this function on a player in a vehicle will instantly remove them from the vehicle.
 *  Useful for quickly ejecting players.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerPos(playerid, Float:x, Float:y, Float:z);

/**
 * <library>omp_player</library>
 * <summary>Get the position of a player, represented by x, y and z coordinates.</summary>
 * <param name="playerid">The ID of the player to get the position of</param>
 * <param name="x">A float variable in which to store the x coordinate in, passed by reference</param>
 * <param name="y">A float variable in which to store the y coordinate in, passed by reference</param>
 * <param name="z">A float variable in which to store the z coordinate in, passed by reference</param>
 * <seealso name="SetPlayerPos" />
 * <seealso name="GetVehiclePos" />
 * <seealso name="IsPlayerInRangeOfPoint" />
 * <seealso name="GetPlayerDistanceFromPoint" />
 * <remarks>This function is known to return unreliable values when used in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>
 * and <a href="#OnPlayerRequestClass">OnPlayerRequestClass</a>.  This is because the player is not
 * spawned.</remarks>
 * <returns><b><c>true</c></b> on success, <b><c>false</c></b> on failure (i.e.  player not connected).</returns>
 */
native bool:GetPlayerPos(playerid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_player</library>
 * <summary>Set a player's facing angle (z rotation).</summary>
 * <param name="playerid">The ID of the player to set the facing angle of</param>
 * <param name="angle">The angle the player should face</param>
 * <seealso name="GetPlayerFacingAngle" />
 * <seealso name="SetPlayerPos" />
 * <remarks>Angles are reversed in GTA:SA; 90 degrees would be East in the real world, but in GTA:SA
 * 90 degrees is in fact West.  North and South are still 0/360 and 180.  To convert this, simply do
 * <b>360 - angle</b>.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:SetPlayerFacingAngle(playerid, Float:angle);

/**
 * <library>omp_player</library>
 * <summary>Gets the angle a player is facing.</summary>
 * <param name="playerid">The player you want to get the angle of</param>
 * <param name="angle">The Float to store the angle in, passed by reference</param>
 * <seealso name="GetVehicleZAngle" />
 * <seealso name="SetPlayerFacingAngle" />
 * <remarks>Angles are reversed in GTA:SA; 90 degrees would be East in the real world, but in GTA:SA
 * 90 degrees is in fact West.  North and South are still 0/360 and 180.  To convert this, simply do
 * <b>360 - angle</b>.</remarks>
 * <remarks>Angles returned when inside a vehicle is rarely correct.  To get the correct facing angle
 * while inside a vehicle, use <a href="#GetVehicleZAngle">GetVehicleZAngle</a>.</remarks>
 */
native bool:GetPlayerFacingAngle(playerid, &Float:angle);

/**
 * <library>omp_player</library>
 * <summary>This sets the players position then adjusts the players z-coordinate to the nearest solid
 * ground under the position.</summary>
 * <param name="playerid">The ID of the player to set the position of</param>
 * <param name="x">The x coordinate to position the player at</param>
 * <param name="y">The x coordinate to position the player at</param>
 * <param name="z">The z coordinate to position the player at</param>
 * <seealso name="SetPlayerPos" />
 * <seealso name="OnPlayerClickMap" />
 * <remarks>This function does not work if the new coordinates are far away from where the player currently
 * is.  The z height will be <b><c>0</c></b>, which will likely put them underground.  It is highly
 * recommended that the <a href="https://github.com/philip1337/samp-plugin-mapandreas">MapAndreas plugin</a>
 * be used instead.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerPosFindZ(playerid, Float:x, Float:y, Float:z);

/**
 * <library>omp_player</library>
 * <summary>Set the skill level of a certain weapon type for a player.</summary>
 * <param name="playerid">The ID of the player to set the weapon skill of</param>
 * <param name="skill">The weapon to set the skill of</param>
 * <param name="level">The skill level to set for that weapon, ranging from <b><c>0</c></b> to <b><c>999</c></b>.
 *  A level out of range will max it out</param>
 * <seealso name="SetPlayerArmedWeapon" />
 * <seealso name="GivePlayerWeapon" />
 * <remarks>
 *   <b>Weapon skills:</b><br />
 *   <ul>
 *     <li><b><c>WEAPONSKILL_PISTOL(0)</c></b></li>
 *     <li><b><c>WEAPONSKILL_PISTOL_SILENCED(1)</c></b></li>
 *     <li><b><c>WEAPONSKILL_DESERT_EAGLE(2)</c></b></li>
 *     <li><b><c>WEAPONSKILL_SHOTGUN(3)</c></b></li>
 *     <li><b><c>WEAPONSKILL_SAWNOFF_SHOTGUN(4)</c></b></li>
 *     <li><b><c>WEAPONSKILL_SPAS12_SHOTGUN(5)</c></b></li>
 *     <li><b><c>WEAPONSKILL_MICRO_UZI(6)</c></b></li>
 *     <li><b><c>WEAPONSKILL_MP5(7)</c></b></li>
 *     <li><b><c>WEAPONSKILL_AK47(8)</c></b></li>
 *     <li><b><c>WEAPONSKILL_M4(9)</c></b></li>
 *     <li><b><c>WEAPONSKILL_SNIPERRIFLE(10)</c></b></li>
 *   </ul>
 * </remarks>
 */
native bool:SetPlayerSkillLevel(playerid, WEAPONSKILL:skill, level);

/**
 * <library>omp_player</library>
 * <summary>This function allows to set players special action.</summary>
 * <param name="playerid">The player that should perform the action</param>
 * <param name="actionid">The action that should be performed</param>
 * <seealso name="GetPlayerSpecialAction" />
 * <seealso name="ApplyAnimation" />
 * <remarks>Removing jetpacks from players by setting their special action to <b><c>0</c></b> causes
 * the sound to stay until death.</remarks>
 * <remarks>
 *   <b>Special actions: (marked with * cannot be set)</b><br />
 *   <ul>
 *     <li><b><c>0 - SPECIAL_ACTION_NONE</c></b></li>
 *     <li><b><c>1 - SPECIAL_ACTION_DUCK *</c></b> - Detect if the player is crouching.</li>
 *     <li><b><c>2 - SPECIAL_ACTION_USEJETPACK</c></b></li>
 *     <li><b><c>3 - SPECIAL_ACTION_ENTER_VEHICLE *</c></b> - Detect if the player is entering a vehicle
 * via an animation.</li>
 *     <li><b><c>4 - SPECIAL_ACTION_EXIT_VEHICLE *</c></b> - Detect if the player is exiting a vehicle
 * via an animation.</li>
 *     <li><b><c>5 - SPECIAL_ACTION_DANCE1</c></b></li>
 *     <li><b><c>6 - SPECIAL_ACTION_DANCE2</c></b></li>
 *     <li><b><c>7 - SPECIAL_ACTION_DANCE3</c></b></li>
 *     <li><b><c>8 - SPECIAL_ACTION_DANCE4</c></b></li>
 *     <li><b><c>10 - SPECIAL_ACTION_HANDSUP</c></b></li>
 *     <li><b><c>11 - SPECIAL_ACTION_USECELLPHONE</c></b></li>
 *     <li><b><c>12 - SPECIAL_ACTION_SITTING *</c></b></li>
 *     <li><b><c>13 - SPECIAL_ACTION_STOPUSECELLPHONE</c></b></li>
 *     <li><b><c>20 - SPECIAL_ACTION_DRINK_BEER</c></b> - Will increase the player's drunk level when
 * used</li>
 *     <li><b><c>21 - SPECIAL_ACTION_SMOKE_CIGGY</c></b> - Will give the player a cigar</li>
 *     <li><b><c>22 - SPECIAL_ACTION_DRINK_WINE</c></b> - Will give the player a wine bottle to get
 * drunk from</li>
 *     <li><b><c>23 - SPECIAL_ACTION_DRINK_SPRUNK</c></b> - Will give the player a sprunk bottle to
 * drink from</li>
 *     <li><b><c>24 - SPECIAL_ACTION_CUFFED</c></b> - Will force the player in to cuffs (hands are behind
 * their back) (<b>does not work on CJ skin</b>)</li>
 *     <li><b><c>25 - SPECIAL_ACTION_CARRY</c></b>         - Will apply a 'carrying' animation to the
 * player and make them unable to sprint, jump or punch (<b>does not work on CJ skin</b>)</li>
 *     <li><b><c>68 - SPECIAL_ACTION_PISSING</c></b> - Will make make the player perform the pissing
 * animation with visible pee.</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:SetPlayerSpecialAction(playerid, SPECIAL_ACTION:actionid);

/**
 * <library>omp_player</library>
 * <summary>Apply an animation to a player.</summary>
 * <param name="playerid">The ID of the player to apply the animation to</param>
 * <param name="animationLibrary">The animation library from which to apply an animation</param>
 * <param name="animationName">The name of the animation to apply, within the specified library</param>
 * <param name="delta">The speed to play the animation (use 4.1)</param>
 * <param name="loop">If set to <b><c>1</c></b>, the animation will loop.  If set to <b><c>0</c></b>,
 * the animation will play once</param>
 * <param name="lockX">If set to <b><c>0</c></b>, the player is returned to their old x coordinate once
 * the animation is complete (for animations that move the player such as walking). <b><c>1</c></b>
 * will not return them to their old position</param>
 * <param name="lockY">Same as above but for the y axis.  Should be kept the same as the previous parameter</param>
 * <param name="freeze">Setting this to <b><c>1</c></b> will freeze the player at the end of the animation.
 * <b><c>0</c></b> will not</param>
 * <param name="time">Timer in milliseconds.  For a never-ending loop it should be <b><c>0</c></b></param>
 * <param name="forceSync">Set to <b><c>1</c></b> to make server sync the animation with all other players
 * in streaming radius. <b><c>2</c></b> works same as <b><c>1</c></b>, but will ONLY apply the animation
 * to streamed-in players, but NOT the actual player being animated (useful for npc animations and persistent
 * animations when players are being streamed) (optional=<b><c>0</c></b>)</param>
 * <seealso name="ClearAnimations" />
 * <seealso name="SetPlayerSpecialAction" />
 * <remarks>The <paramref name="forceSync" /> optional parameter, which defaults to <b><c>0</c></b>,
 * in most cases is not needed since players sync animations themselves.  The <paramref name="forceSync"
 * /> parameter can force all players who can see <paramref name="playerid" /> to play the animation
 * regardless of whether the player is performing that animation.  This is useful in circumstances where
 * the player can't sync the animation themselves.  For example, they may be paused.</remarks>
 * <remarks>An invalid animation library will crash the player's game.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if the player specified does not exist,
 * or any of the parameters are invalid (e.g.  invalid library).</returns>
 */
native bool:ApplyAnimation(playerid, const animationLibrary[], const animationName[], Float:delta, bool:loop, bool:lockX, bool:lockY, bool:freeze, time, FORCE_SYNC:forceSync = SYNC_NONE);

/**
 * <library>omp_player</library>
 * <summary>Returns the index of any running applied animations.</summary>
 * <param name="playerid">ID of the player of whom you want to get the animation index of</param>
 * <seealso name="GetAnimationName" />
 * <returns><b><c>0</c></b> if there is no animation applied.</returns>
 */
native GetPlayerAnimationIndex(playerid);

/**
 * <library>omp_player</library>
 * <summary>Clears all animations for the given player (it also cancels all current tasks such as jetpacking,parachuting,entering
 * vehicles, driving (removes player out of vehicle), swimming, etc.. ).</summary>
 * <param name="playerid">The ID of the player to clear the animations of</param>
 * <param name="forceSync">Set to <b><c>1</c></b> to force playerid to sync the animation with other
 * players in streaming radius (optional=<b><c>0</c></b>)</param>
 * <seealso name="ApplyAnimation" />
 * <remarks>ClearAnimations doesn't do anything when the animation ends if we pass 1 for the freeze
 * parameter in <a href="#ApplyAnimation">ApplyAnimation</a>.</remarks>
 * <remarks>Unlike some other ways to remove player from a vehicle, this will also reset the vehicle's
 * velocity to zero, instantly stopping the car.  Player will appear on top of the vehicle with the
 * same location as he was in his car seat.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even when the player specified is not connected.</returns>
 */
native bool:ClearAnimations(playerid, FORCE_SYNC:forceSync = SYNC_NONE);

/**
 * <library>omp_player</library>
 * <summary>Retrieves a player's current <a href="https://www.open.mp/docs/scripting/resources/specialactions">special
 * action</a>.</summary>
 * <param name="playerid">The ID of the player to get the <a href="https://www.open.mp/docs/scripting/resources/specialactions">special
 * action</a> of</param>
 * <seealso name="SetPlayerSpecialAction" />
 * <seealso name="GetPlayerState" />
 * <remarks>
 *   <b>Special actions: (marked with * cannot be set)</b><br />
 *   <ul>
 *     <li><b><c>0 - SPECIAL_ACTION_NONE</c></b></li>
 *     <li><b><c>1 - SPECIAL_ACTION_DUCK *</c></b> - Detect if the player is crouching.</li>
 *     <li><b><c>2 - SPECIAL_ACTION_USEJETPACK</c></b></li>
 *     <li><b><c>3 - SPECIAL_ACTION_ENTER_VEHICLE *</c></b> - Detect if the player is entering a vehicle
 * via an animation.</li>
 *     <li><b><c>4 - SPECIAL_ACTION_EXIT_VEHICLE *</c></b> - Detect if the player is exiting a vehicle
 * via an animation.</li>
 *     <li><b><c>5 - SPECIAL_ACTION_DANCE1</c></b></li>
 *     <li><b><c>6 - SPECIAL_ACTION_DANCE2</c></b></li>
 *     <li><b><c>7 - SPECIAL_ACTION_DANCE3</c></b></li>
 *     <li><b><c>8 - SPECIAL_ACTION_DANCE4</c></b></li>
 *     <li><b><c>10 - SPECIAL_ACTION_HANDSUP</c></b></li>
 *     <li><b><c>11 - SPECIAL_ACTION_USECELLPHONE</c></b></li>
 *     <li><b><c>12 - SPECIAL_ACTION_SITTING *</c></b></li>
 *     <li><b><c>13 - SPECIAL_ACTION_STOPUSECELLPHONE</c></b></li>
 *     <li><b><c>20 - SPECIAL_ACTION_DRINK_BEER</c></b> - Will increase the player's drunk level when
 * used</li>
 *     <li><b><c>21 - SPECIAL_ACTION_SMOKE_CIGGY</c></b> - Will give the player a cigar</li>
 *     <li><b><c>22 - SPECIAL_ACTION_DRINK_WINE</c></b> - Will give the player a wine bottle to get
 * drunk from</li>
 *     <li><b><c>23 - SPECIAL_ACTION_DRINK_SPRUNK</c></b> - Will give the player a sprunk bottle to
 * drink from</li>
 *     <li><b><c>24 - SPECIAL_ACTION_CUFFED</c></b> - Will force the player in to cuffs (hands are behind
 * their back) (<b>does not work on CJ skin</b>)</li>
 *     <li><b><c>25 - SPECIAL_ACTION_CARRY</c></b>         - Will apply a 'carrying' animation to the
 * player and make them unable to sprint, jump or punch (<b>does not work on CJ skin</b>)</li>
 *     <li><b><c>68 - SPECIAL_ACTION_PISSING</c></b> - Will make make the player perform the pissing
 * animation with visible pee.</li>
 *   </ul>
 * </remarks>
 * <returns>The <a href="https://www.open.mp/docs/scripting/resources/specialactions">special action</a> of the player.</returns>
 */
native SPECIAL_ACTION:GetPlayerSpecialAction(playerid);

/**
 * <library>omp_player</library>
 * <summary>Returns the class of the players skin.</summary>
 * <param name="playerid">The player you want to get the skin from</param>
 * <seealso name="SetPlayerSkin" />
 * <remarks>Returns the new skin after <a href="#SetSpawnInfo">SetSpawnInfo</a> is called but before
 * the player actually respawns to get the new skin. </remarks>
 * <remarks>Returns the old skin if the player was spawned through <a href="#SpawnPlayer">SpawnPlayer</a>
 * function. </remarks>
 * <returns>The skin id (<b><c>0</c></b> if invalid).</returns>
 */
native GetPlayerCustomSkin(playerid);

/**
 * <library>omp_player</library>
 */
native GetPlayerSkillLevel(playerid, WEAPONSKILL:skill);

/**
 * <library>omp_player</library>
 */
native bool:GetPlayerRotationQuat(playerid, &Float:w, &Float:x, &Float:y, &Float:z);

/*
native #Client()
*/

/**
 * <library>omp_player</library>
 * <summary>This function sends a message to a specific player with a chosen colour in the chat.  The
 * whole line in the chatbox will be in the set colour unless colour embedding is used (since <b><c>0.3c</c></b>).</summary>
 * <param name="playerid">The ID of the player to display the message to</param>
 * <param name="colour">The colour of the message (<b>RGBA</b>)</param>
 * <param name="format">The text that will be displayed <b>(max 144 characters).  Optionally formatted.</b></param>
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendPlayerMessageToAll" />
 * <remarks>If a message is longer than 144 characters, it will not be sent.  Truncation can be used
 * to prevent this.  Displaying a message on multiple lines will also solve this issue. </remarks>
 * <remarks>Avoid using the percent sign (or format specifiers) in the actual message text without properly
 * escaping it (like <b><c>%%</c></b>).  It will result in crashes otherwise. </remarks>
 * <remarks>You can use colour embedding for multiple colours in the message. </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is reported when the string is over
 * 144 characters, but the message won't be sent.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player is not connected.
 * </returns>
 */
native bool:SendClientMessage(playerid, colour, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_player</library>
 * <summary>This function sends a message to a specific player with a chosen colour in the chat.  The
 * whole line in the chatbox will be in the set colour unless colour embedding is used (since <b><c>0.3c</c></b>).</summary>
 * <param name="playerid">The ID of the player to display the message to</param>
 * <param name="colour">The colour of the message (<b>RGBA</b>)</param>
 * <param name="format">The text that will be displayed <b>(max 144 characters).  Optionally formatted.</b></param>
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendPlayerMessageToAll" />
 * <remarks>If a message is longer than 144 characters, it will not be sent.  Truncation can be used
 * to prevent this.  Displaying a message on multiple lines will also solve this issue. </remarks>
 * <remarks>Avoid using the percent sign (or format specifiers) in the actual message text without properly
 * escaping it (like <b><c>%%</c></b>).  It will result in crashes otherwise. </remarks>
 * <remarks>You can use colour embedding for multiple colours in the message. </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is reported when the string is over
 * 144 characters, but the message won't be sent.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player is not connected.
 * </returns>
 */
#pragma deprecated Use `SendClientMessage`
native bool:SendClientMessagef(playerid, colour, const format[], OPEN_MP_TAGS:...) = SendClientMessage;

/**
 * <library>omp_player</library>
 * <summary>Shows 'game text' (on-screen text) for a certain length of time for a specific player.</summary>
 * <param name="playerid">The ID of the player to show the gametext for</param>
 * <param name="format">The text to be displayed.  May be formatted.</param>
 * <param name="time">The duration of the text being shown in milliseconds</param>
 * <param name="style">The style of text to be displayed</param>
 * <seealso name="GameTextForAll" />
 * <seealso name="TextDrawShowForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.
 *   <b><c>0</c></b>: The function failed to execute.  This means either the string is null or the player
 * is not connected.
 * </returns>
 */
native bool:GameTextForPlayer(playerid, const format[], time, style, OPEN_MP_TAGS:...);

/**
 * <library>omp_player</library>
 * <summary>Shows 'game text' (on-screen text) for a certain length of time for a specific player.</summary>
 * <param name="playerid">The ID of the player to show the gametext for</param>
 * <param name="format">The text to be displayed.  May be formatted.</param>
 * <param name="time">The duration of the text being shown in milliseconds</param>
 * <param name="style">The style of text to be displayed</param>
 * <seealso name="GameTextForAll" />
 * <seealso name="TextDrawShowForPlayer" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is reported when the style and/or
 * time is invalid.  Nothing will happen though (no text displayed).  May also cause game crashes.<br
 * />
 *   <b><c>0</c></b>: The function failed to execute.  This means either the string is null or the player
 * is not connected.
 * </returns>
 */
#pragma deprecated Use `GameTextForPlayer`
native bool:GameTextForPlayerf(playerid, const format[], time, style, OPEN_MP_TAGS:...) = GameTextForPlayer;

/**
 * <library>omp_player</library>
 * <summary>Stop showing a gametext style to a player.</summary>
 * <param name="playerid">The ID of the player to hide the gametext for</param>
 * <param name="style">The style of text to hide</param>
 * <seealso name="GameTextForPlayer" />
 * <seealso name="HasGameText" />
 * <seealso name="GetGameText" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.
 *   <b><c>0</c></b>: The function failed to execute.  This means either the style isn't displayed
 *   or the player is not connected.
 * </returns>
 */
native bool:HideGameTextForPlayer(playerid, style);

/**
 * <library>omp_player</library>
 * <summary>Does this player currently have text in the given gametext style displayed?</summary>
 * <param name="playerid">The ID of the player to check the gametext for</param>
 * <param name="style">The style of text to check</param>
 * <seealso name="GameTextForPlayer" />
 * <seealso name="HideGameTextForPlayer" />
 * <seealso name="GetGameText" />
 * <returns>
 *   Does this player currently have text in the given gametext style displayed?
 * </returns>
 */
native bool:HasGameText(playerid, style);

/**
 * <library>omp_player</library>
 * <summary>Returns all the information on the given game text style.</summary>
 * <param name="playerid">The ID of the player to get the gametext data for</param>
 * <param name="style">The style of text to get the data for</param>
 * <param name="message">Return array for the text string</param>
 * <param name="len">Size of the output</param>
 * <param name="time">The time the gametext was originally shown for</param>
 * <param name="remaining">How much of that time is still remaining</param>
 * <seealso name="GameTextForPlayer" />
 * <seealso name="HideGameTextForPlayer" />
 * <seealso name="HasGameText" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.
 *   <b><c>0</c></b>: The function failed to execute.  This means either the style isn't displayed
 *   or the player is not connected.
 * </returns>
 */
native bool:GetGameText(playerid, style, message[], len = sizeof (message), time, remaining);

/**
 * <library>omp_player</library>
 * <summary>Adds a death to the 'killfeed' on the right-hand side of the screen for a single player.</summary>
 * <param name="playerid">The ID of the player to send the death message to</param>
 * <param name="killer">The ID of the killer (can be <b><c>INVALID_PLAYER_ID</c></b>)</param>
 * <param name="killee">The ID of the player that died</param>
 * <param name="weapon">The <a href="https://www.open.mp/docs/scripting/resources/weaponids">reason</a> (not always a weapon)
 * for the victim's death.  Special icons can also be used (<b><c>ICON_CONNECT</c></b> and <b><c>ICON_DISCONNECT</c></b>)</param>
 * <seealso name="SendDeathMessage" />
 * <seealso name="OnPlayerDeath" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:SendDeathMessageToPlayer(playerid, killer, killee, weapon);

/**
 * <library>omp_player</library>
 * <summary>Sends a message in the name of a player to another player on the server.  The message will
 * appear in the chat box but can only be seen by the user specified with <paramref name="playerid"
 * />.  The line will start with the sender's name in their colour, followed by the message in white.</summary>
 * <param name="playerid">The ID of the player who will receive the message</param>
 * <param name="senderid">The sender's ID.  If invalid, the message will not be sent</param>
 * <param name="format">The message that will be sent.  May be formatted.</param>
 * <seealso name="SendPlayerMessageToAll" />
 * <seealso name="SendClientMessage" />
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="OnPlayerText" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 */
native bool:SendPlayerMessageToPlayer(playerid, senderid, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_player</library>
 * <summary>Sends a message in the name of a player to another player on the server.  The message will
 * appear in the chat box but can only be seen by the user specified with <paramref name="playerid"
 * />.  The line will start with the sender's name in their colour, followed by the message in white.</summary>
 * <param name="playerid">The ID of the player who will receive the message</param>
 * <param name="senderid">The sender's ID.  If invalid, the message will not be sent</param>
 * <param name="format">The message that will be sent.  May be formatted.</param>
 * <seealso name="SendPlayerMessageToAll" />
 * <seealso name="SendClientMessage" />
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="OnPlayerText" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 */
#pragma deprecated Use `SendPlayerMessageToPlayer`
native bool:SendPlayerMessageToPlayerf(playerid, senderid, const format[], OPEN_MP_TAGS:...) = SendPlayerMessageToPlayer;

/**
 * <library>omp_player</library>
 * <summary>Set the team of a player.</summary>
 * <param name="playerid">The ID of the player you want to set the team of</param>
 * <param name="teamid">The team to put the player in.  Use <b><c>NO_TEAM</c></b> to remove the player
 * from any team</param>
 * <seealso name="GetPlayerTeam" />
 * <seealso name="SetTeamCount" />
 * <seealso name="EnableVehicleFriendlyFire" />
 * <remarks>Players can not damage/kill players on the same team unless they use a knife to slit their
 * throat.  Players are also unable to damage vehicles driven by a player from
 * the same team.  This can be enabled with <a href="#EnableVehicleFriendlyFire">EnableVehicleFriendlyFire</a>.</remarks>
 * <remarks><b><c>255</c></b> (or <b><c>NO_TEAM</c></b>) is the default team to be able to shoot other
 * players, not <b><c>0</c></b>.</remarks>
 */
native bool:SetPlayerTeam(playerid, teamid);

/**
 * <library>omp_player</library>
 * <summary>Get the ID of the team the player is on.</summary>
 * <param name="playerid">The ID of the player to get the team of</param>
 * <seealso name="SetPlayerTeam" />
 * <seealso name="SetTeamCount" />
 * <returns>
 *   <b><c>0-254</c></b>: The player's team. (<b><c>0</c></b> is a valid team).<br />
 *   <b><c>255</c></b>: Defined as <b><c>NO_TEAM</c></b>.  The player is not on any team.<br />
 *   <b><c>-1</c></b>: The function failed to execute.  Player is not connected.
 * </returns>
 */
native GetPlayerTeam(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set a player's score.  Players' scores are shown in the scoreboard (shown by holding the
 * TAB key).</summary>
 * <param name="playerid">The ID of the player to set the score of</param>
 * <param name="score">The value to set the player's score to</param>
 * <seealso name="GetPlayerScore" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerScore(playerid, score);

/**
 * <library>omp_player</library>
 * <summary>This function returns a player's score as it was set using <a href="#SetPlayerScore">SetPlayerScore</a>.</summary>
 * <param name="playerid">The player to get the score of</param>
 * <seealso name="SetPlayerScore" />
 * <seealso name="GetPlayerPing" />
 * <returns>The player's score.</returns>
 */
native GetPlayerScore(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set the colour of a player's nametag and marker (radar blip).</summary>
 * <param name="playerid">The ID of the player whose colour to set</param>
 * <param name="colour">The colour to set.  Supports alpha values (<b>RGBA</b>)</param>
 * <seealso name="SetPlayerMarkerForPlayer" />
 * <seealso name="GetPlayerColor" />
 * <seealso name="ChangeVehicleColor" />
 * <remarks>This function will change player's colour for everyone, even if player's colour was changed
 * with <a href="#SetPlayerMarkerForPlayer">SetPlayerMarkerForPlayer</a> for any other player. </remarks>
 * <remarks>If used under <a href="#OnPlayerConnect">OnPlayerConnect</a>, the affecting player will
 * not see the colour in the TAB menu. </remarks>
 */
native bool:SetPlayerColor(playerid, colour);

/**
 * <library>omp_player</library>
 * <summary>Gets the colour of the player's name and radar marker.  Only works after <a href="#SetPlayerColor">SetPlayerColor</a>.</summary>
 * <param name="playerid">The ID of the player to get the colour of</param>
 * <seealso name="SetPlayerColor" />
 * <seealso name="ChangeVehicleColor" />
 * <remarks>GetPlayerColor will return <b><c>0</c></b> unless <a href="#SetPlayerColor">SetPlayerColor</a>
 * has been used first.</remarks>
 * <returns>The player's colour. <b><c>0</c></b> if no colour set or player not connected.</returns>
 */
native GetPlayerColor(playerid);

/**
 * <library>omp_player</library>
 * <summary>Gets the default colour for this player ID.</summary>
 * <param name="playerid">The ID of the player to get the colour of.  Doesn't need to be connected</param>
 * <seealso name="GetPlayerColor" />
 */
native GetDefaultPlayerColour(playerid);

/**
 * <library>omp_player</library>
 * <summary>Sets the name of a player.</summary>
 * <param name="playerid">The ID of the player to set the name of</param>
 * <param name="name">The name to set.  Must be 1-24 characters long and only contain valid characters
 * (<b>0-9</b>, <b>a-z</b>, <b>A-z</b>, <b>[]</b>, <b>()</b>, <b>$</b>, <b>@</b>, <b>.</b>, <b>_</b>,
 * <b>=</b>)</param>
 * <seealso name="GetPlayerName" />
 * <remarks>Changing the players' name to the same name but with different character cases (e.g. "John"
 * to "JOHN") will not work. </remarks>
 * <remarks>If used in <a href="#OnPlayerConnect">OnPlayerConnect</a>, the new name will <b>not</b>
 * be shown for the connecting player. </remarks>
 * <remarks>Passing a null string as the new name will crash the server. </remarks>
 * <remarks>Player names can be up to 24 characters when using this function, but when joining the server
 * from the server browser, players' names must be no more than 20 and less than 3 characters
 * (the server will deny entry).  This allows for 4 characters extra when using <a href="#SetPlayerName">SetPlayerName</a>.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b> The name was changed successfully.<br />
 *   <b><c>0</c></b> The player is not connected or the name is already in use.<br />
 *   <b><c>-1</c></b> The name can not be changed (it's less than 3 symbols, too long or has invalid characters).
 * </returns>
 */
native SetPlayerName(playerid, const name[]);

/**
 * <library>omp_player</library>
 * <summary>Get a player's name.</summary>
 * <param name="playerid">The ID of the player to get the name of</param>
 * <param name="name">An array into which to store the name, passed by reference</param>
 * <param name="len">The length of the string that should be stored.  Recommended to be <b><c>MAX_PLAYER_NAME</c></b></param>
 * <seealso name="SetPlayerName" />
 * <seealso name="GetPlayerIp" />
 * <seealso name="GetPlayerPing" />
 * <seealso name="GetPlayerScore" />
 * <seealso name="GetPlayerVersion" />
 * <remarks>A player's name can be up to 24 characters long (as of <b>0.3d R2</b>) by using <a href="#SetPlayerName">SetPlayerName</a>.
 * This is defined as <b><c>24</c></b> by default.  However, the client can
 * only join with a nickname between 3 and 20 characters, otherwise the connection will be rejected
 * and the player has to quit to choose a valid name.</remarks>
 * <returns>The length of the player's name. <b><c>0</c></b> if player specified doesn't exist.</returns>
 */
native GetPlayerName(playerid, name[], len = sizeof (name));

/**
 * <library>omp_player</library>
 * <summary>Set the virtual world of a player.  They can only see other players or vehicles that are
 * in that same world.</summary>
 * <param name="playerid">The ID of the player you want to set the virtual world of</param>
 * <param name="virtualWorld">The virtual world ID to put the player in</param>
 * <seealso name="GetPlayerVirtualWorld" />
 * <seealso name="SetVehicleVirtualWorld" />
 * <remarks>The default virtual world is <b><c>0</c></b></remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:SetPlayerVirtualWorld(playerid, virtualWorld);

/**
 * <library>omp_player</library>
 * <summary>Retrieves the current virtual world the player is in.</summary>
 * <param name="playerid">The ID of the player to get the virtual world of</param>
 * <seealso name="SetPlayerVirtualWorld" />
 * <seealso name="GetVehicleVirtualWorld" />
 * <seealso name="GetPlayerInterior" />
 * <returns>The ID of the virtual world the player is currently in.</returns>
 */
native GetPlayerVirtualWorld(playerid);

/**
 * <library>omp_player</library>
 * <summary>Check if a player is an actual player or an NPC.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="ConnectNPC" />
 * <seealso name="IsPlayerAdmin" />
 * <returns><b><c>1</c></b> if the player is an NPC, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerNPC(playerid);

/**
 * <library>omp_player</library>
 * <summary>Checks if a player is streamed in another player's client.</summary>
 * <param name="targetid">The ID of the player to check is streamed in</param>
 * <param name="playerid">The ID of the player to check if playerid is streamed in for</param>
 * <seealso name="IsActorStreamedIn" />
 * <seealso name="IsVehicleStreamedIn" />
 * <seealso name="OnPlayerStreamIn" />
 * <seealso name="OnPlayerStreamOut" />
 * <seealso name="OnVehicleStreamIn" />
 * <seealso name="OnVehicleStreamOut" />
 * <remarks>Players aren't streamed in on their own client, so if playerid is the same as targetid it
 * will return false!</remarks>
 * <remarks>Players stream out if they are more than <b><c>150</c></b> meters away (see <c>server.cfg</c>
 * - <c>stream_distance</c>)</remarks>
 * <returns><b><c>1</c></b> if the player is streamed in, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerStreamedIn(targetid, playerid);

/**
 * <library>omp_player</library>
 * <summary>Checks if a player is connected (if an ID is taken by a connected player).</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnPlayerDisconnect" />
 * <remarks>This function can be omitted in a lot of cases.  Many other functions already have some
 * sort of connection check built in.</remarks>
 * <returns><b><c>1</c></b> if the player is connected, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerConnected(playerid);

/**
 * <library>omp_player</library>
 * <summary>Creates a chat bubble above a player's name tag.</summary>
 * <param name="playerid">The player which should have the chat bubble</param>
 * <param name="text">The text to display</param>
 * <param name="colour">The text colour</param>
 * <param name="drawDistance">The distance from where players are able to see the chat bubble</param>
 * <param name="expireTime">The time in miliseconds the bubble should be displayed for</param>
 * <remarks>You can't see your own chatbubbles.  The same applies to attached 3D text labels.</remarks>
 * <remarks>You can use colour embedding for multiple colours in the message.</remarks>
 */
native bool:SetPlayerChatBubble(playerid, const text[], colour, Float:drawDistance, expireTime, OPEN_MP_TAGS:...);

/**
 * <library>omp_player</library>
 * <summary>This functions allows you to toggle the drawing of player nametags, healthbars and armor
 * bars which display above their head.  For use of a similar function like this on a global level,
 * <a href="#ShowNameTags">ShowNameTags</a> function.</summary>
 * <param name="playerid">Player who will see the results of this function</param>
 * <param name="targetid">Player whose name tag will be shown or hidden</param>
 * <param name="show"><b><c>1</c></b>-show name tag, <b><c>0</c></b>-hide name tag</param>
 * <seealso name="ShowNameTags" />
 * <seealso name="DisableNameTagLOS" />
 * <seealso name="SetPlayerMarkerForPlayer" />
 * <remarks><a href="#ShowNameTags">ShowNameTags</a> must be set to <b><c>1</c></b> to be able to show
 * name tags with ShowPlayerNameTagForPlayer, that means that in order to be effective you need to <c>ShowPlayerNameTagForPlayer(forplayerid,
 * playerid, 0)</c> ahead of time(<a href="#OnPlayerStreamIn">OnPlayerStreamIn</a> is a good spot).</remarks>
 */
native bool:ShowPlayerNameTagForPlayer(playerid, targetid, bool:show);

/**
 * <library>omp_player</library>
 * <summary>Toggles whether a player can control their character or not.  The player will also be unable
 * to move their camera.</summary>
 * <param name="playerid">The ID of the player to toggle the controllability of</param>
 * <param name="toggle"><b><c>0</c></b> to make them uncontrollable, <b><c>1</c></b> to make them controllable</param>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:TogglePlayerControllable(playerid, bool:controllable);

/**
 * <library>omp_player</library>
 * <summary>Check which keys a player is pressing.</summary>
 * <param name="playerid">The ID of the player to get the keys of</param>
 * <param name="keys">Bitmask containing the player's key states. <a href="https://www.open.mp/docs/scripting/resources/keys">List
 * of keys</a></param>
 * <param name="updown">Up/down state</param>
 * <param name="leftright">Left/right state</param>
 * <seealso name="OnPlayerKeyStateChange" />
 * <remarks>Only the FUNCTION of keys can be detected; not actual keys.  For example, it is not possible
 * to detect if a player presses <b>SPACE</b>, but you can detect if they press <b>SPRINT</b> (which
 * can be mapped (assigned/binded) to ANY key (but is space by default)). </remarks>
 * <remarks>As of update <b>0.3.7</b>, the keys "A" and "D" are not recognized when in a vehicle.  However,
 * keys "W" and "S" can be detected with the "keys" parameter. </remarks>
 * <returns>The keys are stored in the specified variables.</returns>
 */
native bool:GetPlayerKeys(playerid, &KEY:keys, &updown, &leftright);

/**
 * <library>omp_player</library>
 * <summary>Change the colour of a player's <b>nametag</b> and <b>radar blip</b> for another player.</summary>
 * <param name="playerid">The player that will see the player's changed blip/nametag colour</param>
 * <param name="targetid">The player whose colour will be changed</param>
 * <param name="colour">New colour. (<b>RGBA</b>)</param>
 * <seealso name="ShowPlayerMarkers" />
 * <seealso name="LimitPlayerMarkerRadius" />
 * <seealso name="SetPlayerColor" />
 * <seealso name="ShowPlayerNameTagForPlayer" />
 * <seealso name="GetPlayerMarkerForPlayer" />
 */
native bool:SetPlayerMarkerForPlayer(playerid, targetid, colour);

/**
 * <library>omp_player</library>
 * <summary>Get the colour of a player's <b>nametag</b> and <b>radar blip</b> for another player.</summary>
 * <param name="playerid">The player that can see the player's changed blip/nametag colour</param>
 * <param name="targetid">The player whose colour has been changed</param>
 * <seealso name="ShowPlayerMarkers" />
 * <seealso name="LimitPlayerMarkerRadius" />
 * <seealso name="SetPlayerColor" />
 * <seealso name="ShowPlayerNameTagForPlayer" />
 * <seealso name="SetPlayerMarkerForPlayer" />
 */
native GetPlayerMarkerForPlayer(playerid, targetid);

/**
 * <library>omp_player</library>
 * <summary>Starts recording a player's movements to a file, which can then be reproduced by an NPC.</summary>
 * <param name="playerid">The ID of the player to record</param>
 * <param name="recordType">The type of recording</param>
 * <param name="recordFile">The name of the file which will hold the recorded data. It will be saved
 * in the scriptfiles directory, with an automatically added .rec extension, you will need to move the
 * file to npcmodes/recordings to use for playback</param>
 * <seealso name="StopRecordingPlayerData" />
 */
native bool:StartRecordingPlayerData(playerid, PLAYER_RECORDING_TYPE:recordType, const recordFile[]);

/**
 * <library>omp_player</library>
 * <summary>Stops all the recordings that had been started with <a href="#StartRecordingPlayerData">StartRecordingPlayerData</a>
 * for a specific player.</summary>
 * <param name="playerid">The player you want to stop the recordings of</param>
 * <seealso name="StartRecordingPlayerData" />
 */
native bool:StopRecordingPlayerData(playerid);

/**
 * <library>omp_player</library>
 * <summary>Checks if a player is spawned.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <returns><b><c>true</c></b> if the player is spawned, <b><c>false</c></b> if not.</returns>
 * <seealso name="SpawnPlayer" />
 */
native bool:IsPlayerSpawned(playerid);

/**
 * <library>omp_player</library>
 * <summary>Check if the player is controllable.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <returns>
 *   <b><c>true</c></b>: Controllable.<br />
 *   <b><c>false</c></b>: Uncontrollable.
 * </returns>
 * <seealso name="SpawnPlayer" />
 */
native bool:IsPlayerControllable(playerid);

/**
 * <library>omp_player</library>
 * <summary>Toggle player's ghost mode. Ghost mode disables the collision between player models.</summary>
 * <param name="playerid">The ID of the player to toggle the ghost mode.</param>
 * <param name="enable">true for enable and false for disable.</param>
 * <returns>This function always returns <b><c>true</c></b>.</returns>
 * <seealso name="GetPlayerGhostMode" />
 */
native bool:TogglePlayerGhostMode(playerid, bool:enable);

/**
 * <library>omp_player</library>
 * <summary>Gets player's ghost mode.</summary>
 * <param name="playerid">The ID of the player to get the ghost mode of.</param>
 * <returns>
 *   <b><c>true</c></b>: Controllable.<br />
 *   <b><c>false</c></b>: Uncontrollable.
 * </returns>
 * <seealso name="SpawnPlayer" />
 */
native bool:GetPlayerGhostMode(playerid);

/*
native #Equipment()
*/

/**
 * <library>omp_player</library>
 * <summary>Retrieves the amount of money a player has.</summary>
 * <param name="playerid">The ID of the player to get the money of</param>
 * <seealso name="GivePlayerMoney" />
 * <seealso name="ResetPlayerMoney" />
 * <returns>The amount of money the player has.</returns>
 */
native GetPlayerMoney(playerid);

/**
 * <library>omp_player</library>
 * <summary>Reset a player's money to $0.</summary>
 * <param name="playerid">The ID of the player to reset the money of</param>
 * <seealso name="GetPlayerMoney" />
 * <seealso name="GivePlayerMoney" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
 * </returns>
 */
native bool:ResetPlayerMoney(playerid);

/**
 * <library>omp_player</library>
 * <summary>Give money to or take money from a player.</summary>
 * <param name="playerid">The ID of the player to give money to or take money from</param>
 * <param name="money">The amount of money to give the player.  Use a minus value to take money</param>
 * <seealso name="ResetPlayerMoney" />
 * <seealso name="GetPlayerMoney" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.
 * </returns>
 */
native bool:GivePlayerMoney(playerid, money);

/**
 * <library>omp_player</library>
 * <summary>Set a player's armor level.</summary>
 * <param name="playerid">The ID of the player to set the armour of</param>
 * <param name="armour">The amount of armour to set, as a percentage (float).  Values larger than <b><c>100</c></b>
 * are valid, but won't be displayed in the HUD's armour bar</param>
 * <seealso name="GetPlayerArmour" />
 * <seealso name="SetPlayerHealth" />
 * <seealso name="GetPlayerHealth" />
 * <remarks>Armour is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b></remarks>
 * <remarks>The function's name is armour, not armor (Americanized).</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
 * </returns>
 */
native bool:SetPlayerArmour(playerid, Float:armour);

/**
 * <library>omp_player</library>
 * <summary>This function stores the armour of a player into a variable.</summary>
 * <param name="playerid">The ID of the player that you want to get the armour of</param>
 * <param name="armour">The float to to store the armour in, passed by reference</param>
 * <seealso name="SetPlayerArmour" />
 * <seealso name="GetPlayerHealth" />
 * <seealso name="GetVehicleHealth" />
 * <remarks>Even though the armour can be set to near infinite values on the server side, the individual
 * clients will only report values up to <b><c>255</c></b>.  Anything higher will wrap around; <b><c>256</c></b>
 * becomes <b><c>0</c></b>, <b><c>257</c></b> becomes <b><c>1</c></b>, etc. </remarks>
 * <remarks>Armour is obtained rounded to integers: set <b><c>50.15</c></b>, but get <b><c>50.0</c></b>
 * </remarks>
 * <remarks>The function's name is armour, not armor (Americanized).</remarks>
 * <returns>
 *   <b><c>1</c></b> - success.<br />
 *   <b><c>0</c></b> - failure (i.e.  player not connected).<br />
 * </returns>
 */
native bool:GetPlayerArmour(playerid, &Float:armour);

/**
 * <library>omp_player</library>
 * <summary>Give a player a weapon with a specified amount of ammo.</summary>
 * <param name="playerid">The ID of the player to give a weapon to</param>
 * <param name="weaponid">The ID of the weapon to give to the player</param>
 * <param name="ammo">The amount of ammo to give to the player</param>
 * <seealso name="SetPlayerArmedWeapon" />
 * <seealso name="GetPlayerWeapon" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player is not connected.<br />
 * </returns>
 */
native bool:GivePlayerWeapon(playerid, WEAPON:weaponid, ammo);

/**
 * <library>omp_player</library>
 * <summary>Remove a specified weapon from a player.</summary>
 * <param name="playerid">The ID of the player whose weapon to remove</param>
 * <param name="weaponid">The ID of the weapon to remove</param>
 * <seealso name="GivePlayerWeapon" />
 * <seealso name="GetPlayerWeapon" />
 * <remarks>To remove individual weapons from a player, set their ammo to <b><c>0</c></b> using
 * <a href="#SetPlayerAmmo">SetPlayerAmmo</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully, even if they didn't have the weapon (they absolutely don't have it now)<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
 * </returns>
 */
native bool:RemovePlayerWeapon(playerid, WEAPON:weaponid);

/**
 * <library>omp_player</library>
 * <summary>Returns the ID of the weapon a player is currently holding.</summary>
 * <param name="playerid">The ID of the player to get the currently held weapon of</param>
 * <seealso name="GetPlayerWeaponData" />
 * <seealso name="GivePlayerWeapon" />
 * <seealso name="ResetPlayerWeapons" />
 * <remarks>Prior to version <b>0.3z R1-2</b>, when the player state is <b>PLAYER_STATE_PASSENGER</b>
 * this function returns the weapon held by the player before they entered the vehicle.  If a cheat
 * is used to spawn a weapon inside a vehicle, this function will not report it.</remarks>
 * <returns>The ID of the player's current weapon. Returns <b><c>-1</c></b> if the player specified
 * does not exist.</returns>
 */
native WEAPON:GetPlayerWeapon(playerid);

/**
 * <library>omp_player</library>
 * <summary>Removes all weapons from a player.</summary>
 * <param name="playerid">The ID of the player whose weapons to remove</param>
 * <seealso name="GivePlayerWeapon" />
 * <seealso name="GetPlayerWeapon" />
 * <remarks>To remove individual weapons from a player, set their ammo to <b><c>0</c></b> using
 * <a href="#SetPlayerAmmo">SetPlayerAmmo</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
 * </returns>
 */
native bool:ResetPlayerWeapons(playerid);

/**
 * <library>omp_player</library>
 * <summary>Set the ammo of a player's weapon.</summary>
 * <param name="playerid">The ID of the player to set the weapon ammo of</param>
 * <param name="weaponid">The ID of the <a href="https://www.open.mp/docs/scripting/resources/weaponids">weapon</a> to set
 * the ammo of.</param>
 * <param name="ammo">The amount of ammo to set</param>
 * <seealso name="GetPlayerAmmo" />
 * <seealso name="GivePlayerWeapon" />
 * <seealso name="SetPlayerArmedWeapon" />
 * <remarks>Set the ammo to <b><c>0</c></b> to remove a weapon from a player's inventory.  Note that
 * the weapon will still show up in <a href="#GetPlayerWeaponData">GetPlayerWeaponData</a>, albeit with
 * <b><c>0</c></b> ammo.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully. Success is also returned when the weapon
 * specified is invalid.<br />
 *   <b><c>0</c></b>: The function failed to execute. The player isn't connected.<br />
 * </returns>
 */
native bool:SetPlayerAmmo(playerid, WEAPON:weaponid, ammo);

/**
 * <library>omp_player</library>
 * <summary>Sets which weapon (that a player already has) the player is holding.</summary>
 * <param name="playerid">The ID of the player to arm with a weapon</param>
 * <param name="weaponid">The ID of the weapon that the player should be armed with</param>
 * <seealso name="GivePlayerWeapon" />
 * <seealso name="GetPlayerWeapon" />
 * <remarks>This function arms a player with a weapon they <b>already have</b>; it does not give them
 * a new weapon.  See <a href="#GivePlayerWeapon">GivePlayerWeapon</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Success is returned even when the function
 * fails to execute (the player doesn't have the weapon specified, or it is an invalid weapon).<br />
 *   <b><c>0</c></b>: The function failed to execute. The player is not connected.
 * </returns>
 */
native bool:SetPlayerArmedWeapon(playerid, WEAPON:weaponid);

/**
 * <library>omp_player</library>
 * <summary>Gets the amount of ammo in a player's current weapon.</summary>
 * <param name="playerid">The ID of the player whose ammo to get</param>
 * <seealso name="SetPlayerAmmo" />
 * <seealso name="GetPlayerWeaponData" />
 * <remarks>The ammo can hold 16-bit values, therefore values over <b><c>32767</c></b> will return erroneous
 * values.</remarks>
 * <returns>The amount of ammo in the player's current weapon.</returns>
 */
native GetPlayerAmmo(playerid);

/**
 * <library>omp_player</library>
 * <summary>Get the weapon and ammo in a specific player's weapon slot (e.g.  the weapon in the 'SMG'
 * slot).</summary>
 * <param name="playerid">The ID of the player whose weapon data to retrieve</param>
 * <param name="slot">The weapon slot to get data for (<b><c>0-12</c></b>)</param>
 * <param name="weapons">A variable in which to store the weapon ID, passed by reference</param>
 * <param name="ammo">A variable in which to store the ammo, passed by reference</param>
 * <seealso name="GetPlayerWeapon" />
 * <seealso name="GivePlayerWeapon" />
 * <remarks>Old weapons with no ammo left are still returned.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. The player isn't connected and/or the weapon
 * slot specified is invalid (valid is <b><c>0-12</c></b>).
 * </returns>
 */
native bool:GetPlayerWeaponData(playerid, WEAPON_SLOT:slot, &WEAPON:weapon, &ammo);

/**
 * <library>omp_player</library>
 * <summary>Check the state of a player's weapon.</summary>
 * <param name="playerid">The ID of the player to obtain the weapon state of</param>
 * <seealso name="GivePlayerWeapon" />
 * <remarks>
 *   <b>Weapon states:</b><br />
 *   <ul>
 *     <li><b><c>WEAPONSTATE_UNKNOWN</c></b> - unknown (Set when in a vehicle)</li>
 *     <li><b><c>WEAPONSTATE_NO_BULLETS</c></b> - The weapon has no remaining ammo</li>
 *     <li><b><c>WEAPONSTATE_LAST_BULLET</c></b> - the weapon has one remaining bullet</li>
 *     <li><b><c>WEAPONSTATE_MORE_BULLETS</c></b> - the weapon has multiple bullets</li>
 *     <li><b><c>WEAPONSTATE_RELOADING</c></b> - the player is reloading their weapon </li>
 *   </ul>
 * </remarks>
 * <returns>The state of the player's weapon. <b><c>0</c></b> if player specified does not exist.</returns>
 */
native WEAPONSTATE:GetPlayerWeaponState(playerid);

/**
 * <library>omp_player</library>
 * <summary>This function gets the ID of the vehicle the player is currently in.  Note: <b>NOT</b> the
 * model ID of the vehicle. See <a href="#GetVehicleModel">GetVehicleModel</a> for that.</summary>
 * <param name="playerid">The ID of the player in the vehicle that you want to get the ID of</param>
 * <seealso name="IsPlayerInVehicle" />
 * <seealso name="IsPlayerInAnyVehicle" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <seealso name="GetVehicleModel" />
 * <returns>ID of the vehicle or <b><c>0</c></b> if not in a vehicle.</returns>
 */
native GetPlayerVehicleID(playerid);

/**
 * <library>omp_player</library>
 * <summary>Find out which seat a player is in.</summary>
 * <param name="playerid">The ID of the player you want to get the seat of</param>
 * <seealso name="GetPlayerVehicleid" />
 * <seealso name="PutPlayerInVehicle" />
 * <remarks>Sometimes the result can be <b><c>128</c></b> which is an invalid seat ID.  Circumstances
 * of this are not yet known, but it is best to discard information when returned seat number is <b><c>128</c></b>.</remarks>
 * <returns>The ID of the seat the player is in. <b><c>-1</c></b> is not in vehicle, <b><c>0</c></b>
 * is the driver, <b><c>1</c></b> is the front passenger, and <b><c>2</c></b> &amp; <b><c>3</c></b>
 * are the rear passengers.</returns>
 */
native GetPlayerVehicleSeat(playerid);

/**
 * <library>omp_player</library>
 * <summary>Puts a player in a vehicle.</summary>
 * <param name="playerid">The ID of the player to put in a vehicle</param>
 * <param name="vehicleid">The ID of the vehicle to put the player in</param>
 * <param name="seatid">The ID of the seat to put the player in</param>
 * <seealso name="RemovePlayerFromVehicle" />
 * <seealso name="GetPlayerVehicleid" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <seealso name="OnPlayerEnterVehicle" />
 * <remarks>If this function is used on a player that is already in a vehicle, other players will still
 * see them in their previous vehicle.  To fix this, first remove the player from the vehicle.</remarks>
 * <remarks>If the seat is invalid or is taken, will cause a crash when they EXIT the vehicle.</remarks>
 * <remarks>You can use <a href="#GetPlayerVehicleSeat">GetPlayerVehicleSeat</a> in a loop to check
 * if a seat is occupied by any players.</remarks>
 * <remarks>
 *   <b>Seats:</b><br />
 *   <ul>
 *     <li><b><c>0</c></b> - driver.</li>
 *     <li><b><c>1</c></b> - front passenger.</li>
 *     <li><b><c>2</c></b> - back-left passenger.</li>
 *     <li><b><c>3</c></b> - back-right passenger.</li>
 *     <li><b><c>4+</c></b> - passenger seats (coach etc.).</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player or vehicle don't exist.
 * </returns>
 */
native bool:PutPlayerInVehicle(playerid, vehicleid, seatid);

/**
 * <library>omp_player</library>
 * <summary>Checks if a player is in a specific vehicle.</summary>
 * <param name="playerid">ID of the player</param>
 * <param name="vehicleid">ID of the vehicle</param>
 * <seealso name="IsPlayerInAnyVehicle" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <returns><b><c>1</c></b> if the player is in the vehicle, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerInVehicle(playerid, vehicleid);

/**
 * <library>omp_player</library>
 * <summary>Check if a player is inside any vehicle (as a driver or passenger).</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="IsPlayerInVehicle" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <returns><b><c>1</c></b> if the player is in a vehicle, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerInAnyVehicle(playerid);

/**
 * <library>omp_player</library>
 * <summary>Removes/ejects a player from their vehicle.</summary>
 * <param name="playerid">The ID of the player to remove from their vehicle</param>
 * <seealso name="PutPlayerInVehicle" />
 * <remarks>
 *   The exiting animation is not synced for other players.<br />
 *   This function will not work when used in <a href="#OnPlayerEnterVehicle">OnPlayerEnterVehicle</a>,
 * because the player isn't in the vehicle when the callback is called.  Use <a href="#OnPlayerStateChange">OnPlayerStateChange</a>
 * instead.<br />
 *   The player isn't removed if he is in a RC Vehicle.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  This means the player is not connected.
 * </returns>
 */
native bool:RemovePlayerFromVehicle(playerid, bool:force = false);

/**
 * <library>omp_player</library>
 * <summary>Get the ID of the vehicle that the player is surfing (stuck to the roof of).</summary>
 * <param name="playerid">The ID of the player you want to know the surfing vehicle ID of</param>
 * <seealso name="GetPlayerVehicleid" />
 * <seealso name="GetPlayerVehicleSeat" />
 * <returns>The ID of the vehicle that the player is surfing.  If they are not surfing a vehicle or
 * the vehicle they are surfing has no driver, <b><c>INVALID_VEHICLE_ID</c></b>.  If the player specified
 * is not connected, <b><c>INVALID_VEHICLE_ID</c></b> also.</returns>
 */
native GetPlayerSurfingVehicleID(playerid);

/**
 * <library>omp_player</library>
 * <summary>Returns the ID of the object the player is surfing on.</summary>
 * <param name="playerid">The ID of the player surfing the object</param>
 * <returns>The ID of the <b>moving</b> object the player is surfing.  If the player isn't surfing a
 * <b>moving</b> object, it will return <b><c>INVALID_OBJECT_ID</c></b>.</returns>
 */
native GetPlayerSurfingObjectID(playerid);

/**
 * <library>omp_player</library>
 */
native bool:GetPlayerSurfingOffsets(playerid, &Float:offsetX, &Float:offsetY, &Float:offsetZ);

/*
native #Camera()
*/

/**
 * <library>omp_player</library>
 * <summary>Sets the camera to a specific position for a player.</summary>
 * <param name="playerid">ID of the player</param>
 * <param name="x">The x coordinate to place the camera at</param>
 * <param name="y">The y coordinate to place the camera at</param>
 * <param name="z">The z coordinate to place the camera at</param>
 * <seealso name="SetPlayerCameraLookAt" />
 * <seealso name="SetCameraBehindPlayer" />
 * <remarks>You may also have to use <a href="#SetPlayerCameraLookAt">SetPlayerCameraLookAt</a> with
 * this function in order to work properly.</remarks>
 * <remarks>Use <a href="#SetCameraBehindPlayer">SetCameraBehindPlayer</a> to reset the camera to behind
 * the player.</remarks>
 * <remarks>Using the camera functions directly after enabling spectator mode doesn't work.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified doesn't exist.
 * </returns>
 */
native bool:SetPlayerCameraPos(playerid, Float:x, Float:y, Float:z);

/**
 * <library>omp_player</library>
 * <summary>Set the direction a player's camera looks at.  Generally meant to be used in combination
 * with <a href="#SetPlayerCameraPos">SetPlayerCameraPos</a>.</summary>
 * <param name="playerid">The ID of the player whose camera to set</param>
 * <param name="x">The x coordinate for the player's camera to look at</param>
 * <param name="y">The y coordinate for the player's camera to look at</param>
 * <param name="z">The z coordinate for the player's camera to look at</param>
 * <param name="cut">The style of the change.  Can be used to interpolate (change slowly) from old pos
 * to new pos using <b><c>CAMERA_MOVE</c></b>.  Added in <b>0.3e</b>.  Leave out for older versions
 * (optional=<b><c>CAMERA_CUT</c></b>)</param>
 * <seealso name="SetPlayerCameraPos" />
 * <seealso name="SetCameraBehindPlayer" />
 * <seealso name="GetPlayerCameraPos" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>Using the camera functions directly after enabling spectator mode doesn't work.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.
 * </returns>
 */
native bool:SetPlayerCameraLookAt(playerid, Float:x, Float:y, Float:z, CAM_MOVE:cut = CAMERA_CUT);

/**
 * <library>omp_player</library>
 * <summary>Restore the camera to a place behind the player, after using a function like
 * <a href="#SetPlayerCameraPos">SetPlayerCameraPos</a>.</summary>
 * <param name="playerid">The player you want to restore the camera for</param>
 * <seealso name="SetPlayerCameraPos" />
 * <seealso name="SetPlayerCameraLookAt" />
 */
native bool:SetCameraBehindPlayer(playerid);

/**
 * <library>omp_player</library>
 * <summary>Get the position of the player's camera.</summary>
 * <param name="playerid">The ID of the player to get the camera position of</param>
 * <param name="x">A float variable to store the x coordinate in, passed by reference</param>
 * <param name="y">A float variable to store the y coordinate in, passed by reference</param>
 * <param name="z">A float variable to store the z coordinate in, passed by reference</param>
 * <seealso name="SetPlayerCameraPos" />
 * <seealso name="GetPlayerCameraZoom" />
 * <seealso name="GetPlayerCameraAspectRatio" />
 * <seealso name="GetPlayerCameraMode" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>Player's camera positions are only updated once a second, <b>unless aiming</b>.</remarks>
 * <remarks>It is recommended to set a 1 second timer if you wish to take action that relies on a player's
 * camera position.</remarks>
 */
native bool:GetPlayerCameraPos(playerid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_player</library>
 * <summary>Makes a player spectate (watch) another player.</summary>
 * <param name="playerid">The ID of the player that will spectate</param>
 * <param name="targetid">The ID of the player that should be spectated</param>
 * <param name="mode">The mode to spectate with (optional=<b><c>SPECTATE_MODE_NORMAL</c></b>)</param>
 * <seealso name="PlayerSpectateVehicle" />
 * <seealso name="TogglePlayerSpectating" />
 * <remarks>Order is CRITICAL! Ensure that you use <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>
 * before <a href="#PlayerSpectatePlayer">PlayerSpectatePlayer</a>. </remarks>
 * <remarks>playerid and targetid's virtual world and interior must be the same for this function to
 * work properly. </remarks>
 * <remarks>
 *   <b>Spectate modes:</b><br />
 *   <ul>
 *     <li><b><c>SPECTATE_MODE_NORMAL</c></b> - normal spectate mode (third person point of view).
 * Camera can not be changed.</li>
 *     <li><b><c>SPECTATE_MODE_FIXED </c></b> - use SetPlayerCameraPos after this to position the player's
 * camera, and it will track the player/vehicle set with PlayerSpectatePlayer/PlayerSpectateVehicle.</li>
 *     <li><b><c>SPECTATE_MODE_SIDE</c></b> - the camera will be attached to the side of the player/vehicle
 * (like when you're in first-person camera on a bike and you do a wheelie).</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  One of the players specified does not exist.
 * </returns>
 */
native bool:PlayerSpectatePlayer(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL);

/**
 * <library>omp_player</library>
 * <summary>Sets a player to spectate another vehicle.  Their camera will be attached to the vehicle
 * as if they are driving it.</summary>
 * <param name="playerid">The ID of the player who should spectate a vehicle</param>
 * <param name="targetid">The ID of the vehicle the player should spectate</param>
 * <param name="mode">The spectate mode.  Can generally be left blank as it defaults to 'normal'</param>
 * <seealso name="PlayerSpectatePlayer" />
 * <seealso name="TogglePlayerSpectating" />
 * <remarks>Order is CRITICAL! Ensure that you use <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>
 * before <a href="#PlayerSpectatePlayer">PlayerSpectatePlayer</a>. </remarks>
 * <remarks>playerid and targetid have to be in the same interior for this function to work properly.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.  Note that success is reported if the player
 * is not in spectator mode (<a href="#TogglePlayerSpectating">TogglePlayerSpectating</a>), but nothing
 * will happen. <a href="#TogglePlayerSpectating">TogglePlayerSpectating</a> MUST be used first.<br
 * />
 *   <b><c>0</c></b>: The function failed to execute.  The player, vehicle, or both don't exist.
 * </returns>
 */
native bool:PlayerSpectateVehicle(playerid, targetid, SPECTATE_MODE:mode = SPECTATE_MODE_NORMAL);

/**
 * <library>omp_player</library>
 * <summary>Retrieves the start and end (hit) position of the last bullet a player fired.</summary>
 * <param name="playerid">The ID of the player to get the last bullet shot information of</param>
 * <param name="originX">A float variable in which to save the x coordinate of where the bullet originated
 * from</param>
 * <param name="originY">A float variable in which to save the y coordinate of where the bullet originated
 * from</param>
 * <param name="originZ">A float variable in which to save the z coordinate of where the bullet originated
 * from</param>
 * <param name="hitPosX">A float variable in which to save the x coordinate of where the bullet hit</param>
 * <param name="hitPosY">A float variable in which to save the y coordinate of where the bullet hit</param>
 * <param name="hitPosZ">A float variable in which to save the z coordinate of where the bullet hit</param>
 * <seealso name="GetPlayerWeaponData" />
 * <seealso name="GetPlayerWeapon" />
 * <seealso name="VectorSize" />
 * <seealso name="OnPlayerWeaponShot" />
 * <remarks>This function will only work when <a href="https://www.open.mp/docs/server/LagCompensation">lag
 * compensation</a> is <b>enabled</b>. </remarks>
 * <remarks>If the player hit nothing, the hit positions will be <b><c>0</c></b>.  This means you can't
 * currently calculate how far a bullet travels through open air. </remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player specified does not exist.<br />
 * </returns>
 */
native bool:GetPlayerLastShotVectors(playerid, &Float:originX, &Float:originY, &Float:originZ, &Float:hitPosX, &Float:hitPosY, &Float:hitPosZ);

/**
 * <library>omp_player</library>
 * <summary>Allows you to retrieve the ID of the player the playerid is looking at.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="GetPlayerCameraTargetActor" />
 * <seealso name="GetPlayerCameraTargetVehicle" />
 * <seealso name="GetPlayerCameraTargetObject" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>This function is disabled by default to save bandwidth.  Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a>
 * to enable it for each player.</remarks>
 * <remarks>Do not confuse this function with <a href="#GetPlayerTargetPlayer">GetPlayerTargetPlayer</a>.
 * <a href="#GetPlayerTargetPlayer">GetPlayerTargetPlayer</a> returns the ID of the player playerid
 * is aming at (with a weapon). <a href="#GetPlayerCameraTargetPlayer">GetPlayerCameraTargetPlayer</a>
 * returns the ID of the player playerid is looking at (reference point is the <b>center of the screen</b>).</remarks>
 * <returns>The ID of the player the playerid is looking at.</returns>
 */
native GetPlayerCameraTargetPlayer(playerid);

/**
 * <library>omp_player</library>
 * <summary>Allows you to retrieve the ID of the actor the player is looking at (if any).</summary>
 * <param name="playerid">The ID of the player to get the target actor of</param>
 * <seealso name="GetPlayerTargetActor" />
 * <seealso name="GetPlayerCameraTargetPlayer" />
 * <seealso name="GetPlayerCameraTargetVehicle" />
 * <seealso name="GetPlayerCameraTargetObject" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>This function is disabled by default to save bandwidth.  Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a>
 * to enable it for each player.</remarks>
 * <remarks>This function only tells you which actor (if any) the player is <b>looking</b> at.  To find
 * out if they are <b>aiming</b> at them, you need to use <a href="#GetPlayerTargetActor">GetPlayerTargetActor</a>.</remarks>
 * <returns>The ID of the actor the player is looking at.</returns>
 */
native GetPlayerCameraTargetActor(playerid);

/**
 * <library>omp_player</library>
 * <summary>Allows you to retrieve the ID of the object the player is looking at.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="GetPlayerCameraTargetVehicle" />
 * <seealso name="GetPlayerCameraTargetPlayer" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>This function is disabled by default to save bandwidth.  Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a>
 * to enable it for each player.</remarks>
 * <returns>The ID of the object playerid is looking at.  If <b><c>INVALID_OBJECT_ID (65535)</c></b>
 * is returned, playerid isn't looking at any object.</returns>
 */
native GetPlayerCameraTargetObject(playerid);

/**
 * <library>omp_player</library>
 * <summary>Get the ID of the vehicle the player is looking at.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="GetPlayerCameraTargetPlayer" />
 * <seealso name="GetPlayerCameraTargetObject" />
 * <seealso name="EnablePlayerCameraTarget" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>This function is disabled by default to save bandwidth.  Use <a href="#EnablePlayerCameraTarget">EnablePlayerCameraTarget</a>
 * to enable it for each player.</remarks>
 * <remarks>This function can (obviously) only return one vehicle ID at a time, while the player may
 * be looking at multiple.  It generally seems to detect the closest vehicle first.</remarks>
 * <returns>The vehicle ID of the vehicle the player is looking at. <b><c>INVALID_VEHICLE_ID</c></b>
 * if none.</returns>
 */
native GetPlayerCameraTargetVehicle(playerid);

/**
 * <library>omp_player</library>
 * <summary>Toggle whether a player is in spectator mode or not.  While in spectator mode a player can
 * spectate (watch) other players and vehicles.  After using this function, either <a href="#PlayerSpectatePlayer">PlayerSpectatePlayer</a>
 * or <a href="#PlayerSpectateVehicle">PlayerSpectateVehicle</a> needs to be used.</summary>
 * <param name="playerid">The ID of the player who should spectate</param>
 * <param name="toggle"><b><c>1</c></b> to enable spectating and <b><c>0</c></b> to disable</param>
 * <seealso name="PlayerSpectatePlayer" />
 * <seealso name="PlayerSpectateVehicle" />
 * <remarks>If the player is not loaded in before setting the spectate status to false, the connection
 * can be closed unexpectedly.</remarks>
 * <remarks>When spectator mode is disabled, <a href="#OnPlayerSpawn">OnPlayerSpawn</a> will automatically
 * be called, if you wish to restore player to state before spectating, you will have to handle that
 * in <a href="#OnPlayerSpawn">OnPlayerSpawn</a>.  Note also, that player can also go to class selection
 * before if they used F4 during spectate, a player also CAN die in spectate mode due to various glitches.</remarks>
 * <remarks>When a player is in spectate mode their HUD is hidden, making it useful for setting a player's
 * camera without the HUD.  Also, objects near the player's camera will be streamed in, making this
 * useful for interpolating cameras.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player does not exist.
 * </returns>
 */
native bool:TogglePlayerSpectating(playerid, bool:toggle);

/**
 * <library>omp_player</library>
 * <summary>Toggle camera targeting functions for a player.  Disabled by default to save bandwidth.</summary>
 * <param name="playerid">The ID of the player to toggle camera targeting functions for</param>
 * <param name="enable"><b><c>1</c></b> to enable camera targeting functions and <b><c>0</c></b> to
 * disable them</param>
 * <seealso name="GetPlayerCameraTargetVehicle" />
 * <seealso name="GetPlayerCameraTargetPlayer" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The player is not connected.
 * </returns>
 */
native bool:EnablePlayerCameraTarget(playerid, bool:enable);

/**
 * <library>omp_player</library>
 * <summary>Move a player's camera from one position to another, within the set time.  Useful for scripted
 * cut scenes.</summary>
 * <param name="playerid">The ID of the player the camera should be moved for</param>
 * <param name="fromX">The x position the camera should start to move from</param>
 * <param name="fromY">The y position the camera should start to move from</param>
 * <param name="fromZ">The z position the camera should start to move from</param>
 * <param name="toX">The x position the camera should move to</param>
 * <param name="toY">The y position the camera should move to</param>
 * <param name="toZ">The z position the camera should move to</param>
 * <param name="time">Time in milliseconds</param>
 * <param name="cut">The jumpcut to use.  Set to <b><c>CAMERA_MOVE</c></b> for a smooth movement (optional=<b><c>CAMERA_CUT</c></b>)</param>
 * <seealso name="InterpolateCameraLookAt" />
 * <seealso name="SetPlayerCameraPos" />
 * <seealso name="SetPlayerCameraLookAt" />
 * <remarks>Use <b><c>TogglePlayerSpectating</c></b> to make objects stream in for the player while
 * the camera is moving.  You can reset the camera behind the player with <b><c>SetCameraBehindPlayer</c></b>.</remarks>
 */
native bool:InterpolateCameraPos(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT);

/**
 * <library>omp_player</library>
 * <summary>Interpolate a player's camera's 'look at' point between two coordinates with a set speed.
 *  Can be be used with <a href="#InterpolateCameraPos">InterpolateCameraPos</a>.</summary>
 * <param name="playerid">The ID of the player the camera should be moved for</param>
 * <param name="fromX">The x position the camera should start to move from</param>
 * <param name="fromY">The y position the camera should start to move from</param>
 * <param name="fromZ">The z position the camera should start to move from</param>
 * <param name="toX">The x position the camera should move to</param>
 * <param name="toY">The y position the camera should move to</param>
 * <param name="toZ">The z position the camera should move to</param>
 * <param name="time">Time in milliseconds to complete interpolation</param>
 * <param name="cut">The 'jumpcut' to use.  Set to <b><c>CAMERA_MOVE</c></b> for interpolation (optional=<b><c>CAMERA_CUT</c></b>)</param>
 * <seealso name="InterpolateCameraPos" />
 * <seealso name="SetPlayerCameraLookAt" />
 * <seealso name="SetPlayerCameraPos" />
 * <remarks>Use <b><c>TogglePlayerSpectating</c></b> to make objects stream in for the player while
 * the camera is moving.  You can reset the camera behind the player with <b><c>SetCameraBehindPlayer</c></b>.</remarks>
 */
native bool:InterpolateCameraLookAt(playerid, Float:fromX, Float:fromY, Float:fromZ, Float:toX, Float:toY, Float:toZ, time, CAM_MOVE:cut = CAMERA_CUT);

/**
 * <library>omp_player</library>
 * <summary>You can use this function to attach the player camera to objects.</summary>
 * <param name="playerid">The ID of the player which will have your camera attached on object</param>
 * <param name="objectid">The object ID which you want to attach the player camera</param>
 * <seealso name="AttachCameraToPlayerObject" />
 * <remarks>You need to create the object first, before attempting to attach a player camera for that.</remarks>
 */
native bool:AttachCameraToObject(playerid, objectid);

/**
 * <library>omp_player</library>
 * <summary>Attaches a player's camera to a player-object.  The player is able to move their camera
 * while it is attached to an object.  Can be used with MovePlayerObject and AttachPlayerObjectToVehicle.</summary>
 * <param name="playerid">The ID of the player which will have their camera attached to a player-object</param>
 * <param name="objectid">The ID of the player-object to which the player's camera will be attached</param>
 * <seealso name="AttachCameraToObject" />
 * <seealso name="SetPlayerCameraPos" />
 * <seealso name="SetPlayerCameraLookAt" />
 * <remarks>The player-object must be created before attempting to attach the player's camera to it.</remarks>
 */
native bool:AttachCameraToPlayerObject(playerid, objectid);

/**
 * <library>omp_player</library>
 * <summary>Retrieves the aspect ratio of a player's camera.</summary>
 * <param name="playerid">The ID of the player to get the camera aspect ratio of</param>
 * <seealso name="GetPlayerCameraZoom" />
 * <seealso name="GetPlayerCameraPos" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>The return value of this function represents the value of the "widescreen" option in the
 * game's display settings, not the actual aspect ratio of the player's display.</remarks>
 * <returns>The aspect ratio of the player's camera, as a float.  The aspect ratio can be one of three
 * values: 4:3 (<b><c>1.3333334</c></b>, <b><c>Float:0x3FAAAAAB</c></b>) when widescreen is turned off,
 * 5:4 (<b><c>1.2470589</c></b>, <b><c>Float:0x3F9F9FA0</c></b>) when letterbox mode is turned on, and
 * 16:9 (<b><c>1.7764707</c></b>, <b><c>Float:0x3FE36364</c></b>) when widescreen is turned on regardless
 * of the letterbox mode.</returns>
 */
native Float:GetPlayerCameraAspectRatio(playerid);

/**
 * <library>omp_player</library>
 * <summary>This function will return the current direction of player's aiming in 3-D space, the coords
 * are relative to the camera position, see <a href="#GetPlayerCameraPos">GetPlayerCameraPos</a>.</summary>
 * <param name="playerid">The ID of the player you want to obtain the camera front vector of</param>
 * <param name="x">A float to store the x coordinate, passed by reference</param>
 * <param name="y">A float to store the y coordinate, passed by reference</param>
 * <param name="z">A float to store the z coordinate, passed by reference</param>
 * <seealso name="GetPlayerCameraPos" />
 * <remarks>In <b>0.3a</b> the camera front vector is only obtainable when player is inside a rhino,
 * S.W.A.T tank, fire truck, or on foot. </remarks>
 * <remarks>Since <b>0.3b</b> the camera data can be obtained when the player is in any vehicle or on
 * foot. </remarks>
 * <returns>The position is stored in the specified variables.</returns>
 */
native bool:GetPlayerCameraFrontVector(playerid, &Float:x, &Float:y, &Float:z);

/**
 * <library>omp_player</library>
 * <summary>Returns the current GTA camera mode for the requested player.  The camera modes are useful
 * in determining whether a player is aiming, doing a passenger driveby etc.</summary>
 * <param name="playerid">The ID of the player whose camera mode to retrieve</param>
 * <seealso name="GetPlayerCameraPos" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <seealso name="SetPlayerCameraPos" />
 * <seealso name="SetPlayerCameraLookAt" />
 * <seealso name="SetCameraBehindPlayer" />
 * <returns>The camera mode as an integer (or <b><c>-1</c></b> if player is not connected).</returns>
 */
native CAM_MODE:GetPlayerCameraMode(playerid);

/**
 * <library>omp_player</library>
 * <summary>Check who a player is aiming at.</summary>
 * <param name="playerid">The ID of the player to get the target of</param>
 * <seealso name="GetPlayerCameraFrontVector" />
 * <seealso name="OnPlayerGiveDamage" />
 * <seealso name="OnPlayerTakeDamage" />
 * <remarks>Does not work for joypads/controllers, and after a certain distance. </remarks>
 * <remarks>Does not work for the sniper rifle, as it doesn't lock on to anything and as such can't
 * and won't return a player. </remarks>
 * <returns>The ID of the target player, or <b><c>INVALID_PLAYER_ID</c></b> if none.</returns>
 */
native GetPlayerTargetPlayer(playerid);

/**
 * <library>omp_player</library>
 * <summary>Gets ID of an actor which is aimed by certain player.</summary>
 * <param name="playerid">The ID of the player to get the target of</param>
 * <seealso name="GetPlayerCameraTargetActor" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <seealso name="OnPlayerGiveDamageActor" />
 * <remarks>Does not work for joypads/controllers, and after a certain distance. </remarks>
 * <remarks>Does not work for the sniper rifle, as it doesn't lock on to anything and as such can't
 * and won't return a player. </remarks>
 * <returns>The ID of the targeted actor, or <b><c>INVALID_ACTOR_ID</c></b> if none.</returns>
 */
native GetPlayerTargetActor(playerid);

/**
 * <library>omp_player</library>
 * <summary>Retrieves the game camera zoom level for a given player.</summary>
 * <param name="playerid">The ID of the player to get the camera zoom level of</param>
 * <seealso name="GetPlayerCameraAspectRatio" />
 * <seealso name="GetPlayerCameraPos" />
 * <seealso name="GetPlayerCameraFrontVector" />
 * <remarks>This retrieves the zoom level of the GAME camera, not the camera WEAPON.</remarks>
 * <returns>The player's camera zoom level (camera, sniper etc.), a float.</returns>
 */
native Float:GetPlayerCameraZoom(playerid);

/**
 * <library>omp_player</library>
 * <summary>Check if the player camera target is enabled.</summary>
 * <param name="playerid">The ID of the player to check the camera target is enabled.</param>
 * <seealso name="EnablePlayerCameraTarget" />
 * <returns>
 *   <b><c>1</c></b>: If camera target enabled.<br />
 *   <b><c>0</c></b>: If camera target not enabled or the player specified does not exist.
 * </returns>
 */
native bool:IsPlayerCameraTargetEnabled(playerid);

/**
 * <library>omp_player</library>
 * <summary>Toggle player's widescreen.</summary>
 * <param name="playerid">The ID of the player to toggle the widescreen.</param>
 * <param name="wide">true for turn on and false for turn off.</param>
 * <seealso name="IsPlayerWidescreenToggled" />
 * <returns>
 *   <b><c>1</c></b>: The function was executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute. This means the player specified does not exist.
 * </returns>
 */
native bool:TogglePlayerWidescreen(playerid, bool:wide);

/**
 * <library>omp_player</library>
 * <summary>Checks if a player widescreen is on or off.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <seealso name="TogglePlayerWidescreen" />
 * <returns>
 *   <b><c>1</c></b>: The player widescreen is on.<br />
 *   <b><c>0</c></b>: The player widescreen is off or the player specified does not exist.
 * </returns>
 */
native bool:IsPlayerWidescreenToggled(playerid);

/**
 * <library>omp_player</library>
 * <summary>Get the ID of the player or vehicle the player is spectating.</summary>
 * <param name="playerid">The ID of the player.</param>
 * <seealso name="PlayerSpectatePlayer" />
 * <seealso name="PlayerSpectateVehicle" />
 * <seealso name="TogglePlayerSpectating" />
 * <seealso name="GetPlayerSpectateType" />
 * <returns>ID of the player or vehicle.</returns>
 */
native GetPlayerSpectateID(playerid);

/**
 * <library>omp_player</library>
 * <summary>Returns the player's spectate type.</summary>
 * <param name="playerid">The ID of the player to get spectate type of.</param>
 * <seealso name="PlayerSpectatePlayer" />
 * <seealso name="PlayerSpectateVehicle" />
 * <seealso name="TogglePlayerSpectating" />
 * <seealso name="GetPlayerSpectateID" />
 * <returns>The player's spectate type.</returns>
 */
native GetPlayerSpectateType(playerid);

/**
 * <library>omp_player</library>
 * <summary>Get the player animation flags.</summary>
 * <param name="playerid">The player id you want to get the animation flags from.</param>
 * <seealso name="ApplyAnimation" />
 * <returns>The player animation flags as an integer.</returns>
 */
native GetPlayerAnimFlags(playerid);

/**
 * <library>omp_player</library>
 * <summary>Get the player animation flags.</summary>
 * <param name="playerid">The player id you want to get the animation flags from.</param>
 * <seealso name="ApplyAnimation" />
 * <returns>The player animation flags as an integer.</returns>
 */
native GetPlayerAnimationFlags(playerid) = GetPlayerAnimFlags;

/**
 * <library>omp_player</library>
 * <summary>Check if the player is in driveby mode.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <returns>
 *   <b><c>1</c></b>: The player is in driveby mode.<br />
 *   <b><c>0</c></b>: The player is not in driveby mode or the player specified does not exist.
 * </returns>
 */
native bool:IsPlayerInDriveByMode(playerid);

/**
 * <library>omp_player</library>
 * <summary>Check if the player special action is cuffed.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <returns>
 *   <b><c>1</c></b>: The player is cuffed.<br />
 *   <b><c>0</c></b>: The player is not cuffed or the player specified does not exist.
 * </returns>
 */
native bool:IsPlayerCuffed(playerid);

/**
 * <library>omp_player</library>
 * <summary>Gets a player's Z Aim (related to the camera and aiming).</summary>
 * <param name="playerid">The ID of the player to get Z Aim of.</param>
 * <seealso name="GetPlayerCameraPos" />
 * <returns>The player's Z Aim as a float value.</returns>
 */
native Float:GetPlayerZAim(playerid);

/**
 * <library>omp_player</library>
 * <summary>Gets a player's Z Aim (related to the camera and aiming).</summary>
 * <param name="playerid">The ID of the player to get Z Aim of.</param>
 * <seealso name="GetPlayerCameraPos" />
 * <returns>The player's Z Aim as a float value.</returns>
 */
native Float:GetPlayerAimZ(playerid) = GetPlayerZAim;

/**
 * <library>omp_player</library>
 * <summary>Get an array variable of the IDs of the current players on the server.</summary>
 * <param name="players">An array into which to store the player IDs, passed by reference.</param>
 * <param name="size">The size of the array.</param>
 * <seealso name="GetVehicles" />
 * <seealso name="GetActors" />
 * <returns>The number of players stored in the array.</returns>
 */
native GetPlayers(players[], size = sizeof (players));

/**
 * <library>omp_player</library>
 * <summary>Check if the player is using the official SA-MP client.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <seealso name="SendClientCheck" />
 * <returns>
 *   <b><c>1</c></b>: The player is using official client.<br />
 *   <b><c>0</c></b>: The player is not using official client or the player specified does not exist.
 * </returns>
 */
native bool:IsPlayerUsingOfficialClient(playerid);

/**
 * <library>omp_player</library>
 * <summary>Enable/Disable the teleporting ability for a player by right-clicking on the map.</summary>
 * <param name="playerid">The ID of the player to allow teleport</param>
 * <param name="allow"><b><c>1</c></b> to allow, <b><c>0</c></b> to disallow</param>
 * <seealso name="AllowAdminTeleport" />
 */
native bool:AllowPlayerTeleport(playerid, bool:allow);

/**
 * <library>omp_player</library>
 * <summary>Can this player teleport by right-clicking on the map?</summary>
 * <param name="playerid">The ID of the player to allow teleport</param>
 * <seealso name="AllowAdminTeleport" />
 * <seealso name="AllowPlayerTeleport" />
 */
native bool:IsPlayerTeleportAllowed(playerid);

/**
 * <library>omp_player</library>
 * <summary>Enable/Disable weapons for a player.</summary>
 * <param name="playerid">The ID of the player to allow weapons</param>
 * <param name="allow"><b><c>1</c></b> to allow, <b><c>0</c></b> to disallow</param>
 * <remarks>Players still have weapons server-side, they just can't arm them.</remarks>
 * <seealso name="IsPlayerWeaponsAllowed" />
 */
native bool:AllowPlayerWeapons(playerid, bool:allow);

/**
 * <library>omp_player</library>
 * <summary>Can this player use weapons?</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="AllowPlayerWeapons" />
 */
native bool:ArePlayerWeaponsAllowed(playerid);

/**
 * <library>omp_player</library>
 * <summary>Check if the player is using the open.mp launcher.</summary>
 * <param name="playerid">The ID of the player to check.</param>
 * <seealso name="IsPlayerUsingOfficialClient" />
 * <returns>
 *   <b><c>true</c></b>: The player is using open.mp launcher.<br />
 *   <b><c>false</c></b>: The player is not using open.mp launcher or the player specified does not exist.
 * </returns>
 */
native bool:IsPlayerUsingOmp(playerid);

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
 * <summary>This callback is called when a player is streamed by some other player's client.</summary>
 * <param name="playerid">The ID of the player who has been streamed</param>
 * <param name="forplayerid">The ID of the player that streamed the other player in</param>
 * <seealso name="OnPlayerStreamOut" />
 * <seealso name="OnActorStreamIn" />
 * <seealso name="OnVehicleStreamIn" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerStreamIn(playerid, forplayerid);

/**
 * <summary>This callback is called when a player is streamed out from some other player's client.</summary>
 * <param name="playerid">The player who has been destreamed</param>
 * <param name="forplayerid">The player who has destreamed the other player</param>
 * <seealso name="OnPlayerStreamIn" />
 * <seealso name="OnActorStreamOut" />
 * <seealso name="OnVehicleStreamOut" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerStreamOut(playerid, forplayerid);

/**
 * <summary>This callback is called when a player takes damage.</summary>
 * <param name="playerid">The ID of the player that took damage</param>
 * <param name="issuerid">The ID of the player that caused the damage. <b><c>INVALID_PLAYER_ID</c></b>
 * if self-inflicted</param>
 * <param name="amount">The amount of damage the player took (health and armour combined)</param>
 * <param name="weaponid">The ID of the <a href="https://www.open.mp/docs/scripting/resources/weaponids">weapon/reason</a>
 * for the damage</param>
 * <param name="bodypart">The body part that was hit.</param>
 * <seealso name="OnPlayerGiveDamage" />
 * <seealso name="OnPlayerWeaponShot" />
 * <remarks><a href="#GetPlayerHealth">GetPlayerHealth</a> and <a href="#GetPlayerArmour">GetPlayerArmour</a>
 * will return the old amounts of the player before this callback. </remarks>
 * <remarks>
 *   The weaponid will return <b><c>37</c></b> (flame thrower) from any fire sources (e.g.  molotov,
 * <b><c>18</c></b>).<br />
 *   The weaponid will return <b><c>51</c></b> from any weapon that creates an explosion (e.g.  RPG,
 * grenade)<br />
 *   <b>playerid</b> is the only one who can call the callback.<br />
 *   The amount is always the maximum damage the weaponid can do, even when the health left is less
 * than that maximum damage.  So when a player has <b><c>100.0</c></b> health and gets shot with a Desert
 * Eagle which has a damage value of <b><c>46.2</c></b>, it takes 3 shots to kill that player.  All
 * 3 shots will show an amount of <b><c>46.2</c></b>, even though when the last shot hits, the player
 * only has <b><c>7.6</c></b> health left.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b> - Callback will not be called in other filterscripts.<br />
 *   <b><c>0</c></b> - Allows this callback to be called in other filterscripts.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnPlayerTakeDamage(playerid, issuerid, Float:amount, WEAPON:weaponid, bodypart);

/**
 * <summary>This callback is called when a player gives damage to another player.</summary>
 * <param name="playerid">The ID of the player that gave damage</param>
 * <param name="damagedid">The ID of the player that received damage</param>
 * <param name="amount">The amount of health/armour damagedid has lost (combined)</param>
 * <param name="weaponid">The <a href="https://www.open.mp/docs/scripting/resources/weaponids">reason</a> that caused the
 * damage</param>
 * <param name="bodypart">The body part that was hit.</param>
 * <seealso name="OnPlayerTakeDamage" />
 * <remarks>
 *   Keep in mind this function can be inaccurate in some cases.<br />
 *   If you want to prevent certain players from damaging eachother, use <a href="#SetPlayerTeam">SetPlayerTeam</a>.<br
 * />
 *   The weaponid will return <b><c>37</c></b> (flame thrower) from any fire sources (e.g.  molotov,
 * 18)<br />
 *   The weaponid will return <b><c>51</c></b> from any weapon that creates an explosion (e.g.  RPG,
 * grenade)<br />
 *   <b>playerid</b> is the only one who can call the callback.<br />
 *   The amount is always the maximum damage the weaponid can do, even when the health left is less
 * than that maximum damage.  So when a player has <b><c>100.0</c></b> health and gets shot with a Desert
 * Eagle which has a damage value of <b><c>46.2</c></b>, it takes 3 shots to kill that player.  All
 * 3 shots will show an amount of <b><c>46.2</c></b>, even though when the last shot hits, the player
 * only has <b><c>7.6</c></b> health left.
 * </remarks>
 * <returns>
 *   <b><c>1</c></b> - Callback will not be called in other filterscripts.<br />
 *   <b><c>0</c></b> - Allows this callback to be called in other filterscripts.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there blocks other filterscripts
 * from seeing it.
 * </returns>
 */
forward OnPlayerGiveDamage(playerid, damagedid, Float:amount, WEAPON:weaponid, bodypart);

/**
 * <summary>Called when a player double-clicks on a player on the scoreboard.</summary>
 * <param name="playerid">The ID of the player that clicked on a player on the scoreboard</param>
 * <param name="clickedplayerid">The ID of the player that was clicked on</param>
 * <param name="source">The source of the player's click</param>
 * <seealso name="OnPlayerClickTextDraw" />
 * <remarks>There is currently only one <paramref name="source" /> (<b><c>0 - CLICK_SOURCE_SCOREBOARD</c></b>).
 *  The existence of this argument suggests that more sources may be supported in the future.</remarks>
 * <returns>
 *   <b><c>1</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerClickPlayer(playerid, clickedplayerid, CLICK_SOURCE:source);

/**
 * <summary>This callback is called when a player dies, either by suicide or by being killed by another
 * player.</summary>
 * <param name="playerid">The ID of the player that died</param>
 * <param name="killerid">The ID of the player that killed the player who died, or <b><c>INVALID_PLAYER_ID</c></b>
 * if there was none</param>
 * <param name="reason">The ID of the <a href="https://www.open.mp/docs/scripting/resources/weaponids">reason</a> for the
 * player's death</param>
 * <seealso name="OnPlayerSpawn" />
 * <seealso name="SendDeathMessage" />
 * <seealso name="SetPlayerHealth" />
 * <remarks>
 *   The reason will return 37 (flame thrower) from any fire sources (e.g.  molotov, 18)<br />
 *   The reason will return 51 from any weapon that creates an explosion (e.g.  RPG, grenade)<br />
 *   You do not need to check whether killerid is valid before using it in <a href="#SendDeathMessage">SendDeathMessage</a>.
 * <b><c>INVALID_PLAYER_ID</c></b> is a valid killerid ID parameter in that function.<br />
 *   <b>playerid</b> is the only one who can call the callback. (good to know for anti fake death)
 * </remarks>
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerDeath(playerid, killerid, WEAPON:reason);

/**
 * <summary>This callback is called when a player fires a shot from a weapon.  Only bullet weapons are
 * supported.  Only <b>passenger</b> drive-by is supported (not driver drive-by, and not sea sparrow
 * / hunter shots).</summary>
 * <param name="playerid">The ID of the player that shot a weapon</param>
 * <param name="weaponid">The ID of the <a href="https://www.open.mp/docs/scripting/resources/weaponids">weapon</a> shot
 * by the player</param>
 * <param name="hittype">The type of thing the shot hit (none, player, vehicle, or (player)object)</param>
 * <param name="hitid">The ID of the player, vehicle or object that was hit</param>
 * <param name="fX">The X coordinate that the shot hit</param>
 * <param name="fY">The Y coordinate that the shot hit</param>
 * <param name="fZ">The Z coordinate that the shot hit</param>
 * <seealso name="OnPlayerGiveDamage" />
 * <seealso name="GetPlayerLastShotVectors" />
 * <remarks>
 *     <li><b><c>BULLET_HIT_TYPE_NONE(0)</c></b></li>
 *     <li><b><c>BULLET_HIT_TYPE_PLAYER(1)</c></b></li>
 *     <li><b><c>BULLET_HIT_TYPE_VEHICLE(2)</c></b></li>
 *     <li><b><c>BULLET_HIT_TYPE_OBJECT(3)</c></b></li>
 *     <li><b><c>BULLET_HIT_TYPE_PLAYER_OBJECT(4)</c></b></li>
 * </remarks>
 * <remarks><b><c>BULLET_HIT_TYPE_PLAYER</c></b> is also called for NPCs.  Actors are ignored by this
 * callback and detects as <b><c>BULLET_HIT_TYPE_NONE</c></b>.</remarks>
 * <remarks>This callback is only called when lag compensation is <b>enabled</b>. </remarks>
 * <remarks>
 *   If hittype is:<br />
 *   <ul>
 *     <li>- <b><c>BULLET_HIT_TYPE_NONE</c></b>: the fX, fY and fZ parameters are normal coordinates,
 * will give 0.0 for coordinates if nothing was hit (e.g.  far object that the bullet can't reach);</li>
 *     <li>- Others: the fX, fY and fZ are offsets relative to the hitid.</li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   Isn't called if you fired in vehicle as driver or if you are looking behind with the aim enabled
 * (shooting in air).<br />
 *   It is called as <b><c>BULLET_HIT_TYPE_VEHICLE</c></b> with the correct hitid (the hit player's
 * vehicleid) if you are shooting a player which is in a vehicle.  It won't be called as <b><c>BULLET_HIT_TYPE_PLAYER</c></b>
 * at all.<br />
 * </remarks>
 * <remarks>
 * </remarks>
 * <remarks><a href="#GetPlayerLastShotVectors">GetPlayerLastShotVectors</a> can be used in this callback
 * for more detailed bullet vector information.</remarks>
 * <returns>
 *   <b><c>0</c></b> - Prevent the bullet from causing damage.<br />
 *   <b><c>1</c></b> - Allow the bullet to cause damage.<br />
 *   It is always called first in filterscripts so returning <b><c>0</c></b> there also blocks other
 * scripts from seeing it.
 * </returns>
 */
forward OnPlayerWeaponShot(playerid, WEAPON:weaponid, BULLET_HIT_TYPE:hittype, hitid, Float:fX, Float:fY, Float:fZ);

/**
 * <summary>OnPlayerClickMap is called when a player places a target/waypoint on the pause menu map
 * (by right-clicking).</summary>
 * <param name="playerid">The ID of the player that placed a target/waypoint</param>
 * <param name="fX">The X float coordinate where the player clicked</param>
 * <param name="fY">The Y float coordinate where the player clicked</param>
 * <param name="fZ">The Z float coordinate where the player clicked (inaccurate - see note below)</param>
 * <seealso name="SetPlayerPos" />
 * <seealso name="SetPlayerPosFindZ" />
 * <seealso name="GetPlayerPos" />
 * <remarks>The Z value returned will be <b><c>0</c></b> (invalid) if it is far away from the player;
 * use the <a href="https://github.com/philip1337/samp-plugin-mapandreas">MapAndreas plugin</a> to get a more
 * accurate Z coordinate.</remarks>
 * <returns>
 *   <b><c>1</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ);

/**
 * <summary>This callback is called when an IP address attempts a connection to the server.  To block
 * incoming connections, use <a href="#BlockIpAddress">BlockIpAddress</a>.</summary>
 * <param name="playerid">The ID of the player attempting to connect</param>
 * <param name="ip_address">The IP address of the player attempting to connect</param>
 * <param name="port">The port of the attempted connection</param>
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnPlayerDisconnect" />
 * <seealso name="OnPlayerFinishedDownloading" />
 * <seealso name="BlockIpAddress" />
 * <seealso name="UnBlockIpAddress" />
 * <returns>
 *   <b><c>1</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>0</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnIncomingConnection(playerid, ip_address[], port);

/**
 * <summary>This callback is called every time a client/player updates the server with their status.
 *  It is often used to create custom callbacks for client updates that aren't actively tracked by the
 * server, such as health or armor updates or players switching weapons.</summary>
 * <param name="playerid">ID of the player sending an update packet</param>
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>This callback is called, on average, 30 times per second, per player; only use it when you
 * know what it's meant for (or more importantly what it's NOT meant for). </remarks>
 * <remarks>The frequency with which this callback is called for each player varies, depending on what
 * the player is doing.  Driving or shooting will trigger a lot more updates than idling. </remarks>
 * <returns>
 *   <b><c>0</c></b> - Update from this player will not be replicated to other clients.<br />
 *   <b><c>1</c></b> - Indicates that this update can be processed normally and sent to other players.<br
 * />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerUpdate(playerid);

/**
 * <summary>Called when a player changes interior.  Can be triggered by SetPlayerInterior or when a
 * player enter/exits a building.</summary>
 * <param name="playerid">The playerid who changed interior</param>
 * <param name="newinteriorid">The interior the player is now in</param>
 * <param name="oldinteriorid">The interior the player was in before</param>
 * <seealso name="SetPlayerInterior" />
 * <seealso name="GetPlayerInterior" />
 * <seealso name="LinkVehicleToInterior" />
 * <seealso name="OnPlayerStateChange" />
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid);

/**
 * <summary>This callback is called when the state of any supported key is changed (pressed/released).
 *  Directional keys do not trigger OnPlayerKeyStateChange (up/down/left/right).</summary>
 * <param name="playerid">The ID of the player that pressed or released a key</param>
 * <param name="newkeys">A map (bitmask) of the keys currently held - see <a href="https://www.open.mp/docs/scripting/resources/keys">here</a>
 * </param>
 * <param name="oldkeys">A map (bitmask) of the keys held prior to the current change - see
 * <a href="https://www.open.mp/docs/scripting/resources/keys">here</a></param>
 * <seealso name="GetPlayerKeys" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>
 *   Useful macros:<br />
 *   <code>
 *     // HOLDING(keys)<br />
 *     #define HOLDING(%0) ((newkeys &amp; (%0)) == (%0))<br />
 *     <br />
 *     // PRESSED(keys)<br />
 *     #define PRESSED(%0) (((newkeys &amp; (%0)) == (%0)) &amp;&amp; ((oldkeys &amp; (%0)) != (%0)))<br
 * />
 *     <br />
 *     // PRESSING(keyVariable, keys)<br />
 *     #define PRESSING(%0,%1) (%0 &amp; (%1))<br />
 *     <br />
 *     // RELEASED(keys)<br />
 *     #define RELEASED(%0) (((newkeys &amp; (%0)) != (%0)) &amp;&amp; ((oldkeys &amp; (%0)) == (%0)))<br
 * />
 *   </code>
 * </remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys);

/**
 * <summary>This callback is called when a player changes state.  For example, when a player changes
 * from being the driver of a vehicle to being on-foot.</summary>
 * <param name="playerid">The ID of the player that changed state</param>
 * <param name="newstate">The player's new state</param>
 * <param name="oldstate">The player's previous state</param>
 * <seealso name="OnPlayerInteriorChange" />
 * <seealso name="GetPlayerState" />
 * <seealso name="GetPlayerSpecialAction" />
 * <seealso name="SetPlayerSpecialAction" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>
 *   <b>States:</b><br />
 *   <ul>
 *     <li><b><c>PLAYER_STATE_NONE</c></b> - empty (while initializing)</li>
 *     <li><b><c>PLAYER_STATE_ONFOOT</c></b> - player is on foot</li>
 *     <li><b><c>PLAYER_STATE_DRIVER</c></b> - player is the driver of a vehicle</li>
 *     <li><b><c>PLAYER_STATE_PASSENGER</c></b> - player is passenger of a vehicle</li>
 *     <li><b><c>PLAYER_STATE_WASTED</c></b> - player is dead or on class selection</li>
 *     <li><b><c>PLAYER_STATE_SPAWNED</c></b> - player is spawned</li>
 *     <li><b><c>PLAYER_STATE_SPECTATING</c></b> - player is spectating</li>
 *     <li><b><c>PLAYER_STATE_EXIT_VEHICLE</c></b> - player exits a vehicle</li>
 *     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_DRIVER</c></b> - player enters a vehicle as driver</li>
 *     <li><b><c>PLAYER_STATE_ENTER_VEHICLE_PASSENGER</c></b> - player enters a vehicle as passenger
 * </li>
 *   </ul>
 * </remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate);

/**
 * <summary>Called when a player sends a chat message.</summary>
 * <param name="playerid">The ID of the player who typed the text</param>
 * <param name="text">The text the player typed</param>
 * <seealso name="OnPlayerCommandText" />
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendPlayerMessageToAll" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   Returning <b><c>0</c></b> in this callback will stop the text from being sent to all players.<br
 * />
 *   It is always called first in filterscripts so returning <b><c>0</c></b> there blocks other scripts
 * from seeing it.
 * </returns>
 */
forward OnPlayerText(playerid, text[]);

/**
 * <summary>This callback is called when a player enters a command into the client chat window.  Commands
 * are anything that start with a forward slash, e.g. <c>/help</c>.</summary>
 * <param name="playerid">The ID of the player that entered a command</param>
 * <param name="cmdtext">The command that was entered (including the forward slash)</param>
 * <seealso name="OnPlayerText" />
 * <seealso name="OnRconCommand" />
 * <seealso name="SendRconCommand" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   Return <b><c>1</c></b> if the command was processed, otherwise <b><c>0</c></b>; If the command
 * was not found both in filterscripts and in gamemode, the player will be received a message: <em>SERVER:
 * Unknown command</em>.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there blocks other scripts
 * from seeing it.
 * </returns>
 */
forward OnPlayerCommandText(playerid, cmdtext[]);

/**
 * <summary>This callback is called when a player connects to the server.</summary>
 * <param name="playerid">The ID of the player that connected</param>
 * <seealso name="OnPlayerDisconnect" />
 * <seealso name="OnIncomingConnection" />
 * <seealso name="OnPlayerFinishedDownloading" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerConnect(playerid);

/**
 * <summary>This callback is called when a player disconnects from the server.</summary>
 * <param name="playerid">The ID of the player that disconnected</param>
 * <param name="reason">The reason for the disconnection.  See table below</param>
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnIncomingConnection" />
 * <seealso name="OnPlayerFinishedDownloading" />
 * <remarks>This callback can also be called by NPC.</remarks>
 * <remarks>Some functions might not work correctly when used in this callback because the player is
 * already disconnected when the callback is called.  This means that you can't get unambiguous information
 * from functions like <a href="#GetPlayerIp">GetPlayerIp</a> and <a href="#GetPlayerPos">GetPlayerPos</a>.</remarks>
 * <remarks>
 *   <b>Reasons:</b><br />
 *   <ul>
 *     <li><b><c>0</c></b> - timeout/Crash - the player's connection was lost.  Either their game crashed
 * or their network had a fault.</li>
 *     <li><b><c>1</c></b> - quit - the player purposefully quit, either using the <b><c>/quit (/q)</c></b>
 * command or via the pause menu.</li>
 *     <li><b><c>2</c></b> - kick/ban - the player was kicked or banned by the server.</li>
 *   </ul>
 * </remarks>
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnPlayerDisconnect(playerid, reason);
