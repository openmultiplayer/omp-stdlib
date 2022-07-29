#if defined _INC_omp_player
	#endinput
#endif
#define _INC_omp_player

/**
 * <library name="omp_variable" summary="open.mp player functions.">
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

/// <p/>
/**
 * <library>omp_player</library>
 */
#if defined MAX_PLAYERS
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
	const __MAX_PLAYER_NAME                    = MAX_PLAYER_NAME;
	#define __MAX_PLAYER_NAME
#else
	const MAX_PLAYER_NAME                      = 24;
	#define MAX_PLAYER_NAME                    24
#endif

/**
 * <library>a_players</library>
 */
const NO_TEAM                                  = 0xFF;
#define NO_TEAM                                0xFF

/**
 * <library>a_players</library>
 */
const INVALID_PLAYER_ID                        = 0xFFFF;
#define INVALID_PLAYER_ID                      0xFFFF

/// <p/>

/**
 * <library>open.mp</library>
 * <summary>Weapons</summary>
 */
#define WEAPON: __TAG(WEAPON):
enum WEAPON:__WEAPON
{
	WEAPON_FIST,
	WEAPON_BRASSKNUCKLE,
	WEAPON_GOLFCLUB,
	WEAPON_NITESTICK,
	WEAPON_NIGHTSTICK                          = WEAPON_NITESTICK,
	WEAPON_KNIFE,
	WEAPON_BAT,
	WEAPON_SHOVEL,
	WEAPON_POOLSTICK,
	WEAPON_KATANA,
	WEAPON_CHAINSAW,
	WEAPON_DILDO,
	WEAPON_DILDO2,
	WEAPON_VIBRATOR,
	WEAPON_VIBRATOR2,
	WEAPON_FLOWER,
	WEAPON_CANE,
	WEAPON_GRENADE,
	WEAPON_TEARGAS,
	WEAPON_MOLTOV,
	WEAPON_MOLOTOV                             = WEAPON_MOLTOV,
	WEAPON_COLT45                              = 22,
	WEAPON_SILENCED,
	WEAPON_DEAGLE,
	WEAPON_SHOTGUN,
	WEAPON_SAWEDOFF,
	WEAPON_SHOTGSPA,
	WEAPON_UZI,
	WEAPON_MP5,
	WEAPON_AK47,
	WEAPON_M4,
	WEAPON_TEC9,
	WEAPON_RIFLE,
	WEAPON_SNIPER,
	WEAPON_ROCKETLAUNCHER,
	WEAPON_HEATSEEKER,
	WEAPON_FLAMETHROWER,
	WEAPON_MINIGUN,
	WEAPON_SATCHEL,
	WEAPON_BOMB,
	WEAPON_SPRAYCAN,
	WEAPON_FIREEXTINGUISHER,
	WEAPON_CAMERA,
	WEAPON_NIGHT_VISION_GOGGLES,
	WEAPON_THERMAL_GOGGLES,
	WEAPON_PARACHUTE,
	WEAPON_VEHICLE                             = 49,
	WEAPON_DROWN                               = 53,
	WEAPON_COLLISION,
	WEAPON_SPLAT                               = WEAPON_COLLISION,
}
static stock WEAPON:_@WEAPON() { return __WEAPON; }

/// <p/>

/**
 * <library>omp_player</library>
 * <summary>Keys</summary>
 */
#define KEY: __TAG(KEY):
enum KEY:__KEY (<<= 1)
{
	KEY_ACTION                                 = 1,
	KEY_CROUCH,
	KEY_FIRE,
	KEY_SPRINT,
	KEY_SECONDARY_ATTACK,
	KEY_JUMP,
	KEY_LOOK_RIGHT,
	KEY_HANDBRAKE,
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
	KEY_RIGHT                                  =  128,
}
static stock KEY:_@KEY() { return __KEY; }

