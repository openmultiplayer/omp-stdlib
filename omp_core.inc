#if defined _INC_omp_core
	#endinput
#endif
#define _INC_omp_core

/**
 * <library name="omp_core" summary="open.mp core functions and defines.">
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
 * <library>omp_core</library>
 */
const INVALID_TIMER                            = 0;
#define INVALID_TIMER                          0

/// <p/>
/**
 * <library>open.mp</library>
 * <summary>Weapons</summary>
 */
#define WEAPON: __TAG(WEAPON):
enum WEAPON:MAX_WEAPONS
{
	UNKNOWN_WEAPON                             = -1,
	// Special `OnPlayerDeath` `reason` values.  NOT included in `MAX_WEAPONS`.
	REASON_VEHICLE                             = 49,
	REASON_HELICOPTER_BLADES                   = 50,
	REASON_EXPLOSION                           = 51,
	REASON_DROWN                               = 53,
	REASON_COLLISION                           = 54,
	REASON_SPLAT                               = 54,
	REASON_CONNECT                             = 200,
	REASON_DISCONNECT                          = 201,
	REASON_SUICIDE                             = 255,

	WEAPON_UNKNOWN                             = UNKNOWN_WEAPON,
	WEAPON_VEHICLE                             = REASON_VEHICLE,
	WEAPON_DROWN                               = REASON_DROWN,
	WEAPON_COLLISION                           = REASON_COLLISION,
	WEAPON_SPLAT                               = REASON_SPLAT,

	// The main weapon types.  Done after the reasons so sizes are correct.
	WEAPON_FIST                                =  0,
	WEAPON_BRASSKNUCKLE                        =  1,
	WEAPON_GOLFCLUB                            =  2,
	WEAPON_NITESTICK                           =  3,
	WEAPON_NIGHTSTICK                          = WEAPON_NITESTICK,
	WEAPON_KNIFE                               =  4,
	WEAPON_BAT                                 =  5,
	WEAPON_SHOVEL                              =  6,
	WEAPON_POOLSTICK                           =  7,
	WEAPON_KATANA                              =  8,
	WEAPON_CHAINSAW                            =  9,
	WEAPON_DILDO                               = 10,
	WEAPON_DILDO2                              = 11,
	WEAPON_VIBRATOR                            = 12,
	WEAPON_VIBRATOR2                           = 13,
	WEAPON_FLOWER                              = 14,
	WEAPON_CANE                                = 15,
	WEAPON_GRENADE                             = 16,
	WEAPON_TEARGAS                             = 17,
	WEAPON_MOLTOV                              = 18,
	WEAPON_MOLOTOV                             = WEAPON_MOLTOV,
	WEAPON_COLT45                              = 22,
	WEAPON_SILENCED                            = 23,
	WEAPON_DEAGLE                              = 24,
	WEAPON_SHOTGUN                             = 25,
	WEAPON_SAWEDOFF                            = 26,
	WEAPON_SHOTGSPA                            = 27,
	WEAPON_UZI                                 = 28,
	WEAPON_MP5                                 = 29,
	WEAPON_AK47                                = 30,
	WEAPON_M4                                  = 31,
	WEAPON_TEC9                                = 32,
	WEAPON_RIFLE                               = 33,
	WEAPON_SNIPER                              = 34,
	WEAPON_ROCKETLAUNCHER                      = 35,
	WEAPON_HEATSEEKER                          = 36,
	WEAPON_FLAMETHROWER                        = 37,
	WEAPON_MINIGUN                             = 38,
	WEAPON_SATCHEL                             = 39,
	WEAPON_BOMB                                = 40,
	WEAPON_SPRAYCAN                            = 41,
	WEAPON_FIREEXTINGUISHER                    = 42,
	WEAPON_CAMERA                              = 43,
	WEAPON_NIGHT_VISION_GOGGLES                = 44,
	WEAPON_THERMAL_GOGGLES                     = 45,
	WEAPON_PARACHUTE                           = 46
}
static stock WEAPON:_@WEAPON() { return MAX_WEAPONS; }

#define UNKNOWN_WEAPON                         (WEAPON:-1)

// Special `OnPlayerDeath` `reason` values.  NOT included in `MAX_WEAPONS`.
#define REASON_VEHICLE                         (WEAPON:49)
#define REASON_HELICOPTER_BLADES               (WEAPON:50)
#define REASON_EXPLOSION                       (WEAPON:51)
#define REASON_DROWN                           (WEAPON:53)
#define REASON_COLLISION                       (WEAPON:54)
#define REASON_SPLAT                           (WEAPON:54)
#define REASON_CONNECT                         (WEAPON:200)
#define REASON_DISCONNECT                      (WEAPON:201)
#define REASON_SUICIDE                         (WEAPON:255)

// The main weapon types.
#define WEAPON_FIST                            (WEAPON:0)
#define WEAPON_BRASSKNUCKLE                    (WEAPON:1)
#define WEAPON_GOLFCLUB                        (WEAPON:2)
#define WEAPON_NITESTICK                       (WEAPON:3)
#define WEAPON_NIGHTSTICK                      (WEAPON:3)
#define WEAPON_KNIFE                           (WEAPON:4)
#define WEAPON_BAT                             (WEAPON:5)
#define WEAPON_SHOVEL                          (WEAPON:6)
#define WEAPON_POOLSTICK                       (WEAPON:7)
#define WEAPON_KATANA                          (WEAPON:8)
#define WEAPON_CHAINSAW                        (WEAPON:9)
#define WEAPON_DILDO                           (WEAPON:10)
#define WEAPON_DILDO2                          (WEAPON:11)
#define WEAPON_VIBRATOR                        (WEAPON:12)
#define WEAPON_VIBRATOR2                       (WEAPON:13)
#define WEAPON_FLOWER                          (WEAPON:14)
#define WEAPON_CANE                            (WEAPON:15)
#define WEAPON_GRENADE                         (WEAPON:16)
#define WEAPON_TEARGAS                         (WEAPON:17)
#define WEAPON_MOLTOV                          (WEAPON:18)
#define WEAPON_MOLOTOV                         (WEAPON:18)
#define WEAPON_COLT45                          (WEAPON:22)
#define WEAPON_SILENCED                        (WEAPON:23)
#define WEAPON_DEAGLE                          (WEAPON:24)
#define WEAPON_SHOTGUN                         (WEAPON:25)
#define WEAPON_SAWEDOFF                        (WEAPON:26)
#define WEAPON_SHOTGSPA                        (WEAPON:27)
#define WEAPON_UZI                             (WEAPON:28)
#define WEAPON_MP5                             (WEAPON:29)
#define WEAPON_AK47                            (WEAPON:30)
#define WEAPON_M4                              (WEAPON:31)
#define WEAPON_TEC9                            (WEAPON:32)
#define WEAPON_RIFLE                           (WEAPON:33)
#define WEAPON_SNIPER                          (WEAPON:34)
#define WEAPON_ROCKETLAUNCHER                  (WEAPON:35)
#define WEAPON_HEATSEEKER                      (WEAPON:36)
#define WEAPON_FLAMETHROWER                    (WEAPON:37)
#define WEAPON_MINIGUN                         (WEAPON:38)
#define WEAPON_SATCHEL                         (WEAPON:39)
#define WEAPON_BOMB                            (WEAPON:40)
#define WEAPON_SPRAYCAN                        (WEAPON:41)
#define WEAPON_FIREEXTINGUISHER                (WEAPON:42)
#define WEAPON_CAMERA                          (WEAPON:43)
#define WEAPON_NIGHT_VISION_GOGGLES            (WEAPON:44)
#define WEAPON_THERMAL_GOGGLES                 (WEAPON:45)
#define WEAPON_PARACHUTE                       (WEAPON:46)

#define WEAPON_UNKNOWN UNKNOWN_WEAPON
#define WEAPON_VEHICLE REASON_VEHICLE
#define WEAPON_DROWN REASON_DROWN
#define WEAPON_COLLISION REASON_COLLISION
#define WEAPON_SPLAT REASON_SPLAT

/// <p/>
/**
 * <library>open.mp</library>
 * <summary>Weapon Slots</summary>
 */
#define WEAPON_SLOT: __TAG(WEAPON_SLOT):
enum WEAPON_SLOT:MAX_WEAPON_SLOTS
{
	UNKNOWN_WEAPON_SLOT                        = -1,
	WEAPON_SLOT_UNKNOWN                        = UNKNOWN_WEAPON_SLOT,
	WEAPON_SLOT_UNARMED                        =  0,
	WEAPON_SLOT_MELEE                          =  1,
	WEAPON_SLOT_PISTOL                         =  2,
	WEAPON_SLOT_SHOTGUN                        =  3,
	WEAPON_SLOT_MACHINE_GUN                    =  4,
	WEAPON_SLOT_ASSAULT_RIFLE                  =  5,
	WEAPON_SLOT_LONG_RIFLE                     =  6,
	WEAPON_SLOT_ARTILLERY                      =  7,
	WEAPON_SLOT_EXPLOSIVES                     =  8,
	WEAPON_SLOT_EQUIPMENT                      =  9,
	WEAPON_SLOT_GIFT                           = 10,
	WEAPON_SLOT_GADGET                         = 11,
	WEAPON_SLOT_DETONATOR                      = 12
}
static stock WEAPON_SLOT:_@WEAPON_SLOT() { return MAX_WEAPON_SLOTS; }

#define UNKNOWN_WEAPON_SLOT                    (WEAPON_SLOT:-1)
#define WEAPON_SLOT_UNARMED                    (WEAPON_SLOT:0)
#define WEAPON_SLOT_MELEE                      (WEAPON_SLOT:1)
#define WEAPON_SLOT_PISTOL                     (WEAPON_SLOT:2)
#define WEAPON_SLOT_SHOTGUN                    (WEAPON_SLOT:3)
#define WEAPON_SLOT_MACHINE_GUN                (WEAPON_SLOT:4)
#define WEAPON_SLOT_ASSAULT_RIFLE              (WEAPON_SLOT:5)
#define WEAPON_SLOT_LONG_RIFLE                 (WEAPON_SLOT:6)
#define WEAPON_SLOT_ARTILLERY                  (WEAPON_SLOT:7)
#define WEAPON_SLOT_EXPLOSIVES                 (WEAPON_SLOT:8)
#define WEAPON_SLOT_EQUIPMENT                  (WEAPON_SLOT:9)
#define WEAPON_SLOT_GIFT                       (WEAPON_SLOT:10)
#define WEAPON_SLOT_GADGET                     (WEAPON_SLOT:11)
#define WEAPON_SLOT_DETONATOR                  (WEAPON_SLOT:12)

#define WEAPON_SLOT_UNKNOWN UNKNOWN_WEAPON_SLOT

/// <p/>
/**
 * <library>omp_core</library>
 * <summary>Marker modes used by <c>ShowPlayerMarkers()</c></summary>
 */
#define PLAYER_MARKERS_MODE: __TAG(PLAYER_MARKERS_MODE):
enum PLAYER_MARKERS_MODE:__PLAYER_MARKERS_MODE
{
	UNKNOWN_PLAYER_MARKERS_MODE                = -1,
	PLAYER_MARKERS_MODE_UNKNOWN                = UNKNOWN_PLAYER_MARKERS_MODE,
	PLAYER_MARKERS_MODE_OFF                    =  0,
	PLAYER_MARKERS_MODE_GLOBAL                 =  1,
	PLAYER_MARKERS_MODE_STREAMED               =  2
}
static stock PLAYER_MARKERS_MODE:_@PLAYER_MARKERS_MODE() { return __PLAYER_MARKERS_MODE; }

#define UNKNOWN_PLAYER_MARKERS_MODE            (PLAYER_MARKERS_MODE:-1)
#define PLAYER_MARKERS_MODE_OFF                (PLAYER_MARKERS_MODE:0)
#define PLAYER_MARKERS_MODE_GLOBAL             (PLAYER_MARKERS_MODE:1)
#define PLAYER_MARKERS_MODE_STREAMED           (PLAYER_MARKERS_MODE:2)

#define PLAYER_MARKERS_MODE_UNKNOWN UNKNOWN_PLAYER_MARKERS_MODE

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
native # Pawn Utilities();
native         Pawn Utilities(
native      ====================(
native
*/

/**
 * <library>omp_core</library>
 * <summary>Prints a string to the server console (not in-game chat) and logs (server_log.txt).</summary>
 * <param name="string">The string to print</param>
 * <seealso name="printf" />
 */
#if defined __print
	// Fixes a pawndoc bug - comments on `#ifdef`ed out functions are still put
	// in the output, unattached to any function.  So make a function.
	/* */ native __open_mp_unused_print(const string[]);
	#define __open_mp_unused_print
	#define print( __print(
	#define _ALS_print
#else
	native print(const string[]);
#endif

/**
 * <library>omp_core</library>
 * <summary>Prints a string to the server console (not in-game chat) and logs (server_log.txt).</summary>
 * <param name="string">The string to print</param>
 * <seealso name="printf" />
 */
native Print(const string[]) = print;

/**
 * <library>omp_core</library>
 * <summary>Outputs a formatted string on the console (the server window, not the in-game chat).</summary>
 * <param name="format">The format string</param>
 * <param name="">Indefinite number of arguments of any tag</param>
 * <seealso name="print" />
 * <seealso name="format" />
 * <remarks>The format string or its output should not exceed 1024 characters.  Anything beyond that
 * length can lead to a server to crash.</remarks>
 * <remarks>This function doesn't support <a href="#strpack">packed</a> strings.</remarks>
 * <remarks>
 *   <b>Format Specifiers:</b><br />
 *   <ul>
 *     <li><b><c>%i</c></b> - integer (whole number)</li>
 *     <li><b><c>%d</c></b> - integer (whole number).</li>
 *     <li><b><c>%s</c></b> - string</li>
 *     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
 *     <li><b><c>%c</c></b> - ASCII character</li>
 *     <li><b><c>%x</c></b> - hexadecimal number</li>
 *     <li><b><c>%b</c></b> - binary number</li>
 *     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
 *     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
 *   </ul>
 * </remarks>
 * <remarks>The values for the placeholders follow in the exact same order as parameters in the call.
 *  For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer
 * variable, which is the person's age.</remarks>
 * <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder
 * code.  This number indicates the field width; if the size of the parameter to print at the position
 * of the placeholder is smaller than the field width, the field is expanded with spaces.  To cut the
 * number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between
 * the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
 */
native __printf(const format[], OPEN_MP_TAGS:...) = printf;
#define printf( __printf(
#define _ALS_printf

/**
 * <library>omp_core</library>
 * <summary>Outputs a formatted string on the console (the server window, not the in-game chat).</summary>
 * <param name="format">The format string</param>
 * <param name="">Indefinite number of arguments of any tag</param>
 * <seealso name="print" />
 * <seealso name="format" />
 * <remarks>The format string or its output should not exceed 1024 characters.  Anything beyond that
 * length can lead to a server to crash.</remarks>
 * <remarks>This function doesn't support <a href="#strpack">packed</a> strings.</remarks>
 * <remarks>
 *   <b>Format Specifiers:</b><br />
 *   <ul>
 *     <li><b><c>%i</c></b> - integer (whole number)</li>
 *     <li><b><c>%d</c></b> - integer (whole number).</li>
 *     <li><b><c>%s</c></b> - string</li>
 *     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
 *     <li><b><c>%c</c></b> - ASCII character</li>
 *     <li><b><c>%x</c></b> - hexadecimal number</li>
 *     <li><b><c>%b</c></b> - binary number</li>
 *     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
 *     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
 *   </ul>
 * </remarks>
 * <remarks>The values for the placeholders follow in the exact same order as parameters in the call.
 *  For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer
 * variable, which is the person's age.</remarks>
 * <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder
 * code.  This number indicates the field width; if the size of the parameter to print at the position
 * of the placeholder is smaller than the field width, the field is expanded with spaces.  To cut the
 * number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between
 * the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
 */
native PrintF(const format[], OPEN_MP_TAGS:...) = printf;

#if !defined _console_included
	#define _console_included
#endif

/**
 * <library>omp_core</library>
 * <summary>Formats a string to include variables and other strings inside it.</summary>
 * <param name="output">The string to output the result to</param>
 * <param name="len">The maximum length output can contain</param>
 * <param name="format">The format string</param>
 * <param name="">Indefinite number of arguments of any tag</param>
 * <seealso name="print" />
 * <seealso name="printf" />
 * <remarks>This function doesn't support <a href="#strpack">packed strings</a>.</remarks>
 * <remarks>
 *   <b>Format Specifiers:</b><br />
 *   <ul>
 *     <li><b><c>%i</c></b> - integer (whole number)</li>
 *     <li><b><c>%d</c></b> - integer (whole number).</li>
 *     <li><b><c>%s</c></b> - string</li>
 *     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
 *     <li><b><c>%c</c></b> - ASCII character</li>
 *     <li><b><c>%x</c></b> - hexadecimal number</li>
 *     <li><b><c>%b</c></b> - binary number</li>
 *     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
 *     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
 *   </ul>
 * </remarks>
 * <remarks>The values for the placeholders follow in the exact same order as parameters in the call.
 *  For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer
 * variable, which is the person's age.</remarks>
 * <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder
 * code.  This number indicates the field width; if the size of the parameter to print at the position
 * of the placeholder is smaller than the field width, the field is expanded with spaces.  To cut the
 * number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between
 * the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
 */
native format(output[], len = sizeof (output), const format[], {Float, _}:...);

/**
 * <library>omp_core</library>
 * <summary>Formats a string to include variables and other strings inside it.</summary>
 * <param name="output">The string to output the result to</param>
 * <param name="len">The maximum length output can contain</param>
 * <param name="format">The format string</param>
 * <param name="">Indefinite number of arguments of any tag</param>
 * <seealso name="print" />
 * <seealso name="printf" />
 * <remarks>This function doesn't support <a href="#strpack">packed strings</a>.</remarks>
 * <remarks>
 *   <b>Format Specifiers:</b><br />
 *   <ul>
 *     <li><b><c>%i</c></b> - integer (whole number)</li>
 *     <li><b><c>%d</c></b> - integer (whole number).</li>
 *     <li><b><c>%s</c></b> - string</li>
 *     <li><b><c>%f</c></b> - floating-point number (Float: tag)</li>
 *     <li><b><c>%c</c></b> - ASCII character</li>
 *     <li><b><c>%x</c></b> - hexadecimal number</li>
 *     <li><b><c>%b</c></b> - binary number</li>
 *     <li><b><c>%%</c></b> - literal <b><c>%</c></b></li>
 *     <li><b><c>%q</c></b> - escape a text for SQLite. (Added in <b>0.3.7 R2</b>)</li>
 *   </ul>
 * </remarks>
 * <remarks>The values for the placeholders follow in the exact same order as parameters in the call.
 *  For example, <b><c>"I am %i years old"</c></b> - the <b><c>%i</c></b> will be replaced with an Integer
 * variable, which is the person's age.</remarks>
 * <remarks>You may optionally put a number between the <b><c>%</c></b> and the letter of the placeholder
 * code.  This number indicates the field width; if the size of the parameter to print at the position
 * of the placeholder is smaller than the field width, the field is expanded with spaces.  To cut the
 * number of decimal places beeing shown of a float, you can add <b><c>.&lt;max number&gt;</c></b> between
 * the <b><c>%</c></b> and the <b><c>f</c></b>. (example: <b><c>%.2f</c></b>)</remarks>
 */
native Format(output[], len = sizeof (output), const format[], {Float, _}:...) = format;

/**
 * <library>omp_core</library>
 * <summary>Sets a 'timer' to call a function after some time.  Can be set to repeat.</summary>
 * <param name="functionName">Name of the function to call as a string.  This must be a public function
 * (forwarded).  A null string here will crash the server</param>
 * <param name="interval">Interval in milliseconds</param>
 * <param name="repeating">Whether the timer should repeat or not</param>
 * <seealso name="SetTimerEx" />
 * <seealso name="KillTimer" />
 * <remarks>Timer IDs are never used twice.  You can use <a href="#KillTimer">KillTimer</a> on a timer
 * ID and it won't matter if it's running or not. </remarks>
 * <remarks>The function that should be called must be public. </remarks>
 * <remarks>The use of many timers will result in increased memory/cpu usage. </remarks>
 * <returns>The ID of the timer that was started.  Timer IDs start at <b><c>1</c></b>.</returns>
 */
native SetTimer(const functionName[], interval, bool:repeating);

/**
 * <library>omp_core</library>
 * <summary>Sets a timer to call a function after the specified interval.  This variant ('Ex') can pass
 * parameters (such as a player ID) to the function.</summary>
 * <param name="functionName">The name of a public function to call when the timer expires</param>
 * <param name="interval">Interval in milliseconds</param>
 * <param name="repeating">Whether the timer should be called repeatedly (can only be stopped with <a
 * href="#KillTimer">KillTimer</a>) or only once</param>
 * <param name="specifiers">Special format indicating the types of values the timer will pass</param>
 * <param name="">Indefinite number of arguments to pass (must follow format specified in previous parameter)</param>
 * <seealso name="SetTimer" />
 * <seealso name="KillTimer" />
 * <seealso name="CallLocalFunction" />
 * <seealso name="CallRemoteFunction" />
 * <remarks>Timer IDs are never used twice.  You can use KillTimer() on a timer ID and it won't matter
 * if it's running or not. </remarks>
 * <remarks>The function that should be called must be public. </remarks>
 * <remarks>The use of many timers will result in increased memory/cpu usage. </remarks>
 * <remarks>
 *   <b>Specifier syntax:</b><br />
 *   <ul>
 *     <li><b><c>i</c></b> - integer</li>
 *     <li><b><c>d</c></b> - integer</li>
 *     <li><b><c>a</c></b> - array The next parameter must be an integer (<b><c>"i"</c></b>) with the
 * array's size</li>
 *     <li><b><c>s</c></b> - string</li>
 *     <li><b><c>f</c></b> - float</li>
 *     <li><b><c>b</c></b> - boolean</li>
 *   </ul>
 * </remarks>
 * <returns>The ID of the timer that was started.  Timer IDs start at <b><c>1</c></b> and are never
 * reused.  There are no internal checks to verify that the parameters passed are valid (e.g.  duration
 * not a minus value).</returns>
 */
native SetTimerEx(const functionName[], interval, bool:repeating, const specifiers[] = "", OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Kills (stops) a running timer.</summary>
 * <param name="timerid">The ID of the timer to kill (returned by <a href="#SetTimer">SetTimer</a> or
 * <a href="#SetTimerEx">SetTimerEx</a>)</param>
 * <seealso name="SetTimer" />
 * <seealso name="SetTimerEx" />
 * <returns>This function always returns <b><c>0</c></b>.</returns>
 */
native bool:KillTimer(timerid);

/**
 * <library>omp_core</library>
 */
native bool:IsValidTimer(timerid);

/**
 * <library>omp_core</library>
 */
native bool:IsRepeatingTimer(timerid);

/**
 * <library>omp_core</library>
 */
native GetTimerRemaining(timerid);

/**
 * <library>omp_core</library>
 */
native GetTimerInterval(timerid);

/**
 * <library>omp_core</library>
 */
native CountRunningTimers();

/**
 * <library>omp_core</library>
 * <summary>Calls a public function in any script that is loaded.</summary>
 * <param name="functionName">Public function's name</param>
 * <param name="specifiers">Tag/format of each variable</param>
 * <param name="">'Indefinite' number of arguments of any tag</param>
 * <seealso name="CallLocalFunction" />
 * <returns>The value that the last public function returned.</returns>
 * <remarks>CallRemoteFunction crashes the server if it's passing an empty string.</remarks>
 * <remarks>
 *   Specifier string placeholders:<br />
 *   <ul>
 *     <li><b><c>c</c></b> - a single character</li>
 *     <li><b><c>d</c></b> - an integer (whole) number</li>
 *     <li><b><c>i</c></b> - an integer (whole) number</li>
 *     <li><b><c>x</c></b> - a number in hexadecimal notation</li>
 *     <li><b><c>f</c></b> - a floating point number</li>
 *     <li><b><c>s</c></b> - a string</li>
 *   </ul>
 * </remarks>
 */
native CallRemoteFunction(const functionName[], const specifiers[] = "", OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Calls a public function from the script in which it is used.</summary>
 * <param name="functionName">Public function's name</param>
 * <param name="specifiers">Tag/format of each variable</param>
 * <param name="">'Indefinite' number of arguments of any tag</param>
 * <seealso name="CallRemoteFunction" />
 * <returns>The value that the <b>only</b> public function returned.</returns>
 * <remarks>CallLocalFunction crashes the server if it's passing an empty string.</remarks>
 * <remarks>
 *   Specifier string placeholders:<br />
 *   <ul>
 *     <li><b><c>c</c></b> - a single character</li>
 *     <li><b><c>d</c></b> - an integer (whole) number</li>
 *     <li><b><c>i</c></b> - an integer (whole) number</li>
 *     <li><b><c>x</c></b> - a number in hexadecimal notation</li>
 *     <li><b><c>f</c></b> - a floating point number</li>
 *     <li><b><c>s</c></b> - a string</li>
 *   </ul>
 * </remarks>
 */
native CallLocalFunction(const functionName[], const specifiers[] = "", OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Shows 'game text' (on-screen text) for a certain length of time for all players.</summary>
 * <param name="format">The text to be displayed or formatted</param>
 * <param name="time">The duration of the text being shown in milliseconds</param>
 * <param name="style">The style of text to be displayed</param>
 * <seealso name="GameTextForPlayer" />
 * <seealso name="TextDrawShowForAll" />
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native bool:GameTextForAll(const format[], time, style, OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Shows 'game text' (on-screen text) for a certain length of time for all players.</summary>
 * <param name="format">The text to be displayed or formatted</param>
 * <param name="time">The duration of the text being shown in milliseconds</param>
 * <param name="style">The style of text to be displayed</param>
 * <seealso name="GameTextForPlayer" />
 * <seealso name="TextDrawShowForAll" />
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
#pragma deprecated Use `GameTextForAll`
native bool:GameTextForAllf(const format[], time, style, OPEN_MP_TAGS:...) = GameTextForAll;

/**
 * <library>omp_player</library>
 * <summary>Stop showing a gametext style to everyone.</summary>
 * <param name="style">The style of text to hide</param>
 * <seealso name="GameTextForAll" />
 * <seealso name="GameTextForPlayer" />
 * <seealso name="HideGameTextForPlayer" />
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native bool:HideGameTextForAll(style);

/**
 * <library>omp_core</library>
 * <summary>Displays a message in chat to all players.  This is a multi-player equivalent of
 * <a href="#SendClientMessage">SendClientMessage</a>.</summary>
 * <param name="colour">The colour of the message (<b>RGBA</b>)</param>
 * <param name="format">The message to show (<b>max 144 characters</b>).  Optionally formatted.</param>
 * <seealso name="SendClientMessage" />
 * <seealso name="SendPlayerMessageToAll" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native bool:SendClientMessageToAll(colour, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_player</library>
 * <summary>Displays a message in chat to all players.  This is a multi-player equivalent of
 * <a href="#SendClientMessage">SendClientMessage</a>.</summary>
 * <param name="colour">The colour of the message (<b>RGBA</b>)</param>
 * <param name="format">The message to show (<b>max 144 characters</b>).  Optionally formatted.</param>
 * <seealso name="SendClientMessage" />
 * <seealso name="SendPlayerMessageToAll" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
#pragma deprecated Use `SendClientMessageToAll`
native bool:SendClientMessageToAllf(colour, const format[], OPEN_MP_TAGS:...) = SendClientMessageToAll;

/**
 * <library>omp_core</library>
 * <summary>Sends a message in the name of a player to all other players on the server.  The line will
 * start with the sender's name in their colour, followed by the message in white.</summary>
 * <param name="senderid">The ID of the sender.  If invalid, the message will not be sent</param>
 * <param name="format">The message that will be sent.  May be optionally formatted.</param>
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="OnPlayerText" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 */
native bool:SendPlayerMessageToAll(senderid, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Sends a message in the name of a player to all other players on the server.  The line will
 * start with the sender's name in their colour, followed by the message in white.</summary>
 * <param name="senderid">The ID of the sender.  If invalid, the message will not be sent</param>
 * <param name="format">The message that will be sent.  May be optionally formatted.</param>
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="OnPlayerText" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 */
#pragma deprecated Use `SendPlayerMessageToAll`
native bool:SendPlayerMessageToAllf(senderid, const format[], OPEN_MP_TAGS:...) = SendPlayerMessageToAll;

/**
 * <library>omp_core</library>
 * <summary>Adds a death to the 'killfeed' on the right-hand side of the screen for all players.</summary>
 * <param name="killer">The ID of the killer (can be <b><c>INVALID_PLAYER_ID</c></b>)</param>
 * <param name="killee">The ID of the player that died</param>
 * <param name="weapon">The <a href="https://www.open.mp/docs/scripting/resources/weaponids">reason</a> (not always a weapon)
 * for the victim's death.  Special icons can also be used (<b><c>ICON_CONNECT</c></b> and <b><c>ICON_DISCONNECT</c></b>)</param>
 * <seealso name="SendDeathMessageToPlayer" />
 * <seealso name="OnPlayerDeath" />
 * <remarks>Death messages can be cleared by using a valid player ID for <paramref name="killee" />
 * that is not connected.</remarks>
 * <remarks>To show a death message for just a single player, use <a href="#SendDeathMessageToPlayer">SendDeathMessageToPlayer</a>.
 * </remarks>
 * <remarks>You can use NPCs to create your own custom death reasons. </remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if the function fails to execute.  The
 * function fails to execute (no death message shown) if <paramref name="killee" /> is invalid.  If
 * <paramref name="reason" /> is invalid, a generic skull-and-crossbones icon is shown. <paramref name="killer"
 * /> being invalid (<b><c>INVALID_PLAYER_ID</c></b>) is valid.</returns>
 */
native bool:SendDeathMessage(killer, killee, weapon);

/**
 * <library>omp_core</library>
 * <summary>Get the name of a weapon.</summary>
 * <param name="weaponid">The ID of the weapon to get the name of</param>
 * <param name="weapon">An array to store the weapon's name in, passed by reference</param>
 * <param name="len">The maximum length of the weapon name to store.</param>
 * <seealso name="GetPlayerWeapon" />
 * <seealso name="AllowInteriorWeapons" />
 * <seealso name="GivePlayerWeapon" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The weapon specified does not exist.
 * </returns>
 */
native bool:GetWeaponName(WEAPON:weaponid, weapon[], len = sizeof (weapon));

/**
 * <library>omp_core</library>
 */
native bool:IsValidNickName(const name[]);

/**
 * <library>omp_core</library>
 */
native WEAPON_SLOT:GetWeaponSlot(WEAPON:weaponid);

/**
 * <library>omp_core</library>
 * <summary>Get the animation library/name for the index.</summary>
 * <param name="index">The animation index, returned by <a href="#GetPlayerAnimationIndex">GetPlayerAnimationIndex</a></param>
 * <param name="animationLibrary">String variable that stores the animation library</param>
 * <param name="len1">Size of the string that stores the animation library</param>
 * <param name="animationName">String variable that stores the animation name</param>
 * <param name="len2">Size of the string that stores the animation name</param>
 * <seealso name="GetPlayerAnimationIndex" />
 * <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
 */
native GetAnimationName(index, animationLibrary[], len1 = sizeof (animationLibrary), animationName[], len2 = sizeof (animationName));

/**
 * <library>omp_core</library>
 * <summary>Create an explosion at the specified coordinates.</summary>
 * <param name="x">The x coordinate of the explosion</param>
 * <param name="y">The y coordinate of the explosion</param>
 * <param name="z">The z coordinate of the explosion</param>
 * <param name="type">The type of explosion</param>
 * <param name="radius">The explosion radius</param>
 * <seealso name="CreateExplosionForPlayer" />
 * <remarks>There is a limit as to how many explosions can be seen at once by a player.  This is roughly
 * 10.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even when the explosion type and/or radius
 * values are invalid.</returns>
 */
native bool:CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius);

/*
native # Maths();
native             Maths(
native      ====================(
native
*/

/**
 * <library>omp_core</library>
 * <summary>Returns the norm (length) of the provided vector.</summary>
 * <param name="x">The vector's magnitude on the x axis</param>
 * <param name="y">The vector's magnitude on the y axis</param>
 * <param name="z">The vector's magnitude on the z axis</param>
 * <seealso name="GetPlayerDistanceFromPoint" />
 * <seealso name="GetVehicleDistanceFromPoint" />
 * <seealso name="floatsqroot" />
 * <returns>The norm (length) of the provided vector as a float.</returns>
 */
native Float:VectorSize(Float:x, Float:y, Float:z);

/**
 * <library>omp_core</library>
 * <summary>Get the inversed value of a sine in degrees.</summary>
 * <param name="value">The sine for which to find the angle for</param>
 * <seealso name="floatsin" />
 * <returns>The angle in degrees.</returns>
 */
native Float:asin(Float:value);

/**
 * <library>omp_core</library>
 * <summary>Get the inversed value of a sine in degrees.</summary>
 * <param name="value">The sine for which to find the angle for</param>
 * <seealso name="floatsin" />
 * <returns>The angle in degrees.</returns>
 */
native Float:ASin(Float:value) = asin;

/**
 * <library>omp_core</library>
 * <summary>Get the inversed value of a cosine in degrees.</summary>
 * <param name="value">The cosine for which to find the angle for</param>
 * <seealso name="floatcos" />
 * <returns>The angle in degrees.</returns>
 */
native Float:acos(Float:value);

/**
 * <library>omp_core</library>
 * <summary>Get the inversed value of a cosine in degrees.</summary>
 * <param name="value">The cosine for which to find the angle for</param>
 * <seealso name="floatcos" />
 * <returns>The angle in degrees.</returns>
 */
native Float:ACos(Float:value) = acos;

/**
 * <library>omp_core</library>
 * <summary>Get the inversed value of a tangent in degrees.</summary>
 * <param name="value">The tangent for which to find the angle for</param>
 * <seealso name="atan2" />
 * <seealso name="floattan" />
 * <returns>The angle in degrees.</returns>
 */
native Float:atan(Float:value);

/**
 * <library>omp_core</library>
 * <summary>Get the inversed value of a tangent in degrees.</summary>
 * <param name="value">The tangent for which to find the angle for</param>
 * <seealso name="atan2" />
 * <seealso name="floattan" />
 * <returns>The angle in degrees.</returns>
 */
native Float:ATan(Float:value) = atan;

/**
 * <library>omp_core</library>
 * <summary>Get the multi-valued inversed value of a tangent in degrees.</summary>
 * <param name="y">y size</param>
 * <param name="x">x size</param>
 * <seealso name="atan" />
 * <seealso name="floattan" />
 * <returns>The angle in degrees.</returns>
 */
native Float:atan2(Float:y, Float:x);

/**
 * <library>omp_core</library>
 * <summary>Get the multi-valued inversed value of a tangent in degrees.</summary>
 * <param name="y">y size</param>
 * <param name="x">x size</param>
 * <seealso name="atan" />
 * <seealso name="floattan" />
 * <returns>The angle in degrees.</returns>
 */
native Float:ATan2(Float:y, Float:x) = atan2;

/*
native # Server Config();
native         Server Config(
native      ====================(
native
*/

/**
 * <library>omp_core</library>
 * <summary>Returns the uptime of the actual server (not the open.mp server) in milliseconds.</summary>
 * <seealso name="tickcount" />
 * <remarks>GetTickCount will cause problems on servers with uptime of over 24 days as GetTickCount
 * will eventually warp past the integer size constraints.  However using
 * <a href="https://gist.github.com/ziggi/5d7d8dc42f54531feba7ae924c608e73">this</a>
 * function fixes the problem.</remarks>
 * <remarks>One common use for GetTickCount is for benchmarking.  It can be used to calculate how much
 * time some code takes to execute.</remarks>
 * <returns>Uptime of the actual server (not the open.mp server).</returns>
 */
native GetTickCount();

/**
 * <library>omp_core</library>
 * <summary>Gets the tick rate (like FPS) of the server.</summary>
 * <seealso name="GetNetworkStats" />
 * <returns>The server tick rate (per second).  Returns <b><c>0</c></b> when the server is just started.</returns>
 */
native GetServerTickRate();

/**
 * <library>omp_core</library>
 * <summary>Returns the maximum number of players that can join the server, as set by the server variable
 * 'maxplayers' in server.cfg.</summary>
 * <seealso name="GetPlayerPoolSize" />
 * <seealso name="IsPlayerConnected" />
 * <remarks>This function can not be used in place of <b><c>MAX_PLAYERS</c></b>.  It can not be used
 * at compile time (e.g.  for array sizes). <b><c>MAX_PLAYERS</c></b> should always be re-defined to
 * what the 'maxplayers' var will be, or higher.</remarks>
 * <returns>The maximum number of players that can join the server.</returns>
 */
native GetMaxPlayers();

/**
 * <library>omp_core</library>
 * <param name="seconds">The delay between loading main scripts, in seconds.</param>
 */
native bool:SetModeRestartTime(Float:seconds);

/**
 * <library>omp_core</library>
 * <returns>The delay between loading main scripts, in seconds.</returns>
 */
native Float:GetModeRestartTime();

/**
 * <library>omp_core</library>
 * <summary>Ends the current gamemode.</summary>
 * <seealso name="OnGameModeExit" />
 */
native void:GameModeExit();

/**
 * <library>omp_core</library>
 * <summary>Get the string value of a console variable.</summary>
 * <param name="cvar">The name of the string variable to get the value of</param>
 * <param name="buffer">An array into which to store the value, passed by reference</param>
 * <param name="len">The length of the string that should be stored</param>
 * <seealso name="GetConsoleVarAsInt" />
 * <seealso name="GetConsoleVarAsBool" />
 * <seealso name="GetConsoleVarAsFloat" />
 * <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console
 * variables and their types.</remarks>
 * <remarks>When filterscripts or plugins are specified as the cvar, this function only returns the
 * name of the first specified filterscript or plugin.</remarks>
 * <remarks>Using this function with anything other than a <b>string</b> (integer, boolean or float)
 * will cause your server to crash.  Using it with a nonexistent console variable will also cause your
 * server to crash.</remarks>
 * <returns>The length of the returned string. <b><c>0</c></b> if the specified console variable is
 * not a string or doesn't exist.</returns>
 */
native GetConsoleVarAsString(const cvar[], buffer[], len = sizeof (buffer));

/**
 * <library>omp_core</library>
 * <summary>Get the integer value of a console variable.</summary>
 * <param name="cvar">The name of the integer variable to get the value of</param>
 * <seealso name="GetConsoleVarAsString" />
 * <seealso name="GetConsoleVarAsBool" />
 * <seealso name="GetConsoleVarAsFloat" />
 * <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console
 * variables and their types.</remarks>
 * <returns>The value of the specified console variable. <b><c>0</c></b> if the specified console variable
 * is not an integer or doesn't exist.</returns>
 */
native GetConsoleVarAsInt(const cvar[]);

/**
 * <library>omp_core</library>
 * <summary>Get the float value of a console variable.</summary>
 * <param name="cvar">The name of the float variable to get the value of</param>
 * <seealso name="GetConsoleVarAsString" />
 * <seealso name="GetConsoleVarAsBool" />
 * <seealso name="GetConsoleVarAsInt" />
 * <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console
 * variables and their types.</remarks>
 * <returns>The value of the specified console variable. <b><c>0</c></b> if the specified console variable
 * is not a float or doesn't exist.</returns>
 */
native Float:GetConsoleVarAsFloat(const cvar[]);

/**
 * <library>omp_core</library>
 * <summary>Get the boolean value of a console variable.</summary>
 * <param name="cvar">The name of the boolean variable to get the value of</param>
 * <seealso name="GetConsoleVarAsString" />
 * <seealso name="GetConsoleVarAsInt" />
 * <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console
 * variables and their types.</remarks>
 * <returns>The value of the specified console variable. <b><c>0</c></b> if the specified console variable
 * is not a boolean or doesn't exist.</returns>
 */
native bool:GetConsoleVarAsBool(const cvar[]);

/**
 * <library>omp_core</library>
 */
native void:AllowNickNameCharacter(character, bool:allow);

/**
 * <library>omp_core</library>
 */
native bool:IsNickNameCharacterAllowed(character);

/**
 * <library>omp_core</library>
 */
native bool:AddServerRule(const rule[], const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 */
native bool:SetServerRule(const rule[], const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 */
native bool:RemoveServerRule(const rule[]);

/**
 * <library>omp_core</library>
 */
native bool:IsValidServerRule(const rule[]);

/*
native # Client Config();
native         Client Config(
native      ====================(
native
*/

/**
 * <library>omp_core</library>
 * <summary>Disable all the interior entrances and exits in the game (the yellow arrows at doors).</summary>
 * <seealso name="AllowInteriorWeapons" />
 * <remarks>If the gamemode is changed after this function has been used, and the new gamemode doesn't
 * disable markers, the markers will NOT reappear for already-connected players (but will for newly
 * connected players).</remarks>
 * <remarks>This function will only work if it has been used BEFORE a player connects (it is recommended
 * to use it in OnGameModeInit).  It will not remove a connected player's markers.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native void:DisableInteriorEnterExits();

/**
 * <library>omp_core</library>
 * <summary>Disables the nametag Line-Of-Sight checking so that players can see nametags through objects.</summary>
 * <seealso name="ShowNameTags" />
 * <seealso name="ShowPlayerNameTagForPlayer" />
 * <remarks>This can not be reversed until the server restarts.</remarks>
 */
native void:DisableNameTagLOS();

/**
 * <library>omp_core</library>
 * <summary>Set a radius limitation for the chat.  Only players at a certain distance from the player
 * will see their message in the chat.  Also changes the distance at which a player can see other players
 * on the map at the same distance.</summary>
 * <param name="chatRadius">The range in which players will be able to see chat</param>
 * <seealso name="SetNameTagDrawDistance" />
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendPlayerMessageToAll" />
 * <seealso name="OnPlayerText" />
 */
native bool:LimitGlobalChatRadius(Float:chatRadius);

/**
 * <library>omp_core</library>
 * <summary>Set the player marker radius.</summary>
 * <param name="markerRadius">The radius that markers will show at</param>
 * <seealso name="ShowPlayerMarkers" />
 * <seealso name="SetPlayerMarkerForPlayer" />
 * <seealso name="LimitGlobalChatRadius" />
 */
native bool:LimitPlayerMarkerRadius(Float:markerRadius);

/**
 * <library>omp_core</library>
 * <summary>Set the name of the game mode, which appears in the server browser.</summary>
 * <param name="format">The gamemode name to display.  May be optionally formatted.</param>
 */
native bool:SetGameModeText(const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Set the gravity for all players.</summary>
 * <param name="gravity">The value that the gravity should be set to (between -50 and 50)</param>
 * <seealso name="GetGravity" />
 * <seealso name="SetWeather" />
 * <seealso name="SetWorldTime" />
 * <remarks>Default gravity is <b><c>0.008</c></b>.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even when it fails to execute if the gravity
 * is out of the limits (lower than <b><c>-50.0</c></b> or higher than <b><c>+50.0</c></b>).</returns>
 */
native void:SetGravity(Float:gravity);

/**
 * <library>omp_core</library>
 * <summary>Get the currently set gravity.</summary>
 * <seealso name="SetGravity" />
 * <returns>The current set gravity (as a float).</returns>
 */
native Float:GetGravity();

/**
 * <library>omp_core</library>
 * <summary>Set the maximum distance to display the names of players.</summary>
 * <param name="distance">The distance to set</param>
 * <seealso name="LimitGlobalChatRadius" />
 * <seealso name="ShowNameTags" />
 * <seealso name="ShowPlayerNameTagForPlayer" />
 * <remarks>Default distance is <b>70</b> SA units</remarks>
 */
native void:SetNameTagDrawDistance(Float:distance);

/**
 * <library>omp_core</library>
 * <summary>Set the world weather for all players.</summary>
 * <param name="weatherid">The <a href="https://www.open.mp/docs/scripting/resources/weatherid">weather</a> to set</param>
 * <seealso name="SetPlayerWeather" />
 * <seealso name="SetGravity" />
 * <remarks>If <a href="#TogglePlayerClock">TogglePlayerClock</a> is enabled, weather will slowly change
 * over time, instead of changing instantly.</remarks>
 */
native void:SetWeather(weatherid);

/**
 * <library>omp_core</library>
 * <summary>Sets the world time (for all players) to a specific hour.</summary>
 * <param name="hour">The hour to set (<b><c>0</c></b>-<b><c>23</c></b>)</param>
 * <seealso name="SetPlayerTime" />
 * <seealso name="SetWeather" />
 * <seealso name="SetGravity" />
 * <remarks>To set the minutes and/or to set the time for individual players, see <a href="#SetPlayerTime">SetPlayerTime</a>.</remarks>
 * <remarks>This function is only relevant for players that do not use a passing clock - see <a href="#TogglePlayerClock">
 * TogglePlayerClock</a>.</remarks>
 */
native void:SetWorldTime(hour);

/**
 * <library>omp_core</library>
 * <summary>Toggle the drawing of nametags, health bars and armor bars above players.</summary>
 * <param name="show"><b><c>0</c></b> to disable, <b><c>1</c></b> to enable (enabled by default)</param>
 * <seealso name="DisableNameTagLOS" />
 * <seealso name="ShowPlayerNameTagForPlayer" />
 * <seealso name="ShowPlayerMarkers" />
 * <remarks>This function can only be used in <a href="#OnGameModeInit">OnGameModeInit</a>.  For other
 * times, see <a href="#ShowPlayerNameTagForPlayer">ShowPlayerNameTagForPlayer</a>.</remarks>
 */
native void:ShowNameTags(bool:show);

/**
 * <library>omp_core</library>
 * <summary>Toggles player markers (blips on the radar).  Must be used when the server starts (<a href="#OnGameModeInit">OnGameModeInit</a>).
 *  For other times, see <a href="#SetPlayerMarkerForPlayer">SetPlayerMarkerForPlayer</a>.</summary>
 * <param name="mode">The mode to use for markers.  They can be streamed, meaning they are only visible
 * to nearby players.  See table below</param>
 * <seealso name="SetPlayerMarkerForPlayer" />
 * <seealso name="LimitPlayerMarkerRadius" />
 * <seealso name="ShowNameTags" />
 * <seealso name="SetPlayerColor" />
 * <remarks>
 *   <b>Marker modes:</b><br />
 *   <ul>
 *     <li><b><c>PLAYER_MARKERS_MODE_OFF</c></b> 0</li>
 *     <li><b><c>PLAYER_MARKERS_MODE_GLOBAL</c></b> 1</li>
 *     <li><b><c>PLAYER_MARKERS_MODE_STREAMED</c></b> 2</li>
 *   </ul>
 * </remarks>
 * <remarks>It is also possible to set a player's colour to a colour that has full transparency (no
 * alpha value).  This makes it possible to show markers on a per-player basis.</remarks>
 */
native void:ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode);

/**
 * <library>omp_core</library>
 * <summary>Uses standard player walking animation (animation of the CJ skin) instead of custom animations
 * for every skin (e.g.  skating for skater skins).</summary>
 * <seealso name="ApplyAnimation" />
 * <seealso name="ClearAnimations" />
 * <remarks>Only works when placed under <a href="#OnGameModeInit">OnGameModeInit</a>.</remarks>
 * <remarks>Not using this function causes two-handed weapons (not dual-handed - a single weapon that
 * is held by both hands) to be held in only one hand.</remarks>
 */
native void:UsePlayerPedAnims();

/**
 * <library>omp_core</library>
 * <summary>Get the world weather for all players.</summary>
 * <seealso name="SetWeather" />
 * <seealso name="GetGravity" />
 */
native GetWeather();

/**
 * <library>omp_core</library>
 * <summary>Get the world time for all players.</summary>
 * <seealso name="GetWeather" />
 * <seealso name="GetGravity" />
 */
native GetWorldTime();

/**
 * <library>omp_core</library>
 */
native void:ToggleChatTextReplacement(bool:enable);

/**
 * <library>omp_core</library>
 */
native bool:ChatTextReplacementToggled();

/**
 * <library>omp_core</library>
 * <summary>Enables or disables stunt bonuses for all players.  If enabled, players will receive monetary
 * rewards when performing a stunt in a vehicle (e.g.  a wheelie).</summary>
 * <param name="enable"><b><c>1</c></b> to enable stunt bonuses or <b><c>0</c></b> to disable them</param>
 * <seealso name="EnableStuntBonusForPlayer" />
 */
native void:EnableStuntBonusForAll(bool:enable);

/**
 * <library>omp_core</library>
 * <summary>This function will determine whether RCON admins will be teleported to their waypoint when
 * they set one.</summary>
 * <param name="allow"><b><c>0</c></b> to disable and <b><c>1</c></b> to enable</param>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="AllowPlayerTeleport" />
 */
native void:AllowAdminTeleport(bool:allow);

/**
 * <library>omp_core</library>
 * <summary>Can admins teleport by right-clicking on the map?</summary>
 * <seealso name="AllowAdminTeleport" />
 * <seealso name="AllowPlayerTeleport" />
 */
native bool:IsAdminTeleportAllowed();

/**
 * <library>omp_core</library>
 * <summary>Toggle whether the usage of weapons in interiors is allowed or not.</summary>
 * <param name="allow"><b><c>1</c></b> to enable weapons in interiors (enabled by default), <b><c>0</c></b>
 * to disable weapons in interiors</param>
 * <seealso name="SetPlayerInterior" />
 * <seealso name="GetPlayerInterior" />
 * <seealso name="OnPlayerInteriorChange" />
 */
native void:AllowInteriorWeapons(bool:allow);

/**
 * <library>omp_core</library>
 * <summary>Can weapons be used in interiors?</summary>
 * <seealso name="AllowInteriorWeapons" />
 */
native bool:AreInteriorWeaponsAllowed();

/**
 * <library>omp_core</library>
 * <summary>Allow use of the animations missing from some versions.</summary>
 * <seealso name="AreAllAnimationsEnabled" />
 */
native void:EnableAllAnimations(bool:enable);

/**
 * <library>omp_core</library>
 * <summary>Are the animations missing from some versions enabled?</summary>
 * <seealso name="EnableAllAnimations" />
 */
native bool:AreAllAnimationsEnabled();

/**
 * <library>omp_core</library>
 * <summary>This function allows to turn on zone / area names such as the "Vinewood" or "Doherty" text
 * at the bottom-right of the screen as they enter the area.  This is a gamemode option and should be
 * set in the callback <a href="#OnGameModeInit">OnGameModeInit</a>.</summary>
 * <param name="enable">A toggle option for whether or not you'd like zone names on or off</param>
 */
native void:EnableZoneNames(bool:enable);

/*
native # NPCs();
native              NPCs(
native      ====================(
native
*/

/**
 * <library>omp_core</library>
 * <summary>Connect an NPC to the server.</summary>
 * <param name="name">The name the NPC should connect as.  Must follow the same rules as normal player
 * names</param>
 * <param name="script">The NPC script name that is located in the <b>npcmodes</b> folder (without the
 * .amx extension)</param>
 * <seealso name="IsPlayerNPC" />
 * <seealso name="OnPlayerConnect" />
 * <remarks>NPCs do not have nametags.  These can be scripted with
 * <a href="#Attach3DTextLabelToPlayer">Attach3DTextLabelToPlayer</a>.</remarks>
 * <returns>This function always return <b><c>1</c></b>.</returns>
 */
native ConnectNPC(const name[], const script[]);

/*
native # Deprecated();
native           Deprecated(
native      ====================(
native
*/

// These three functions are like this for qawno.
/*
native GetPlayerPoolSize();
*/

/*
native GetVehiclePoolSize();
*/

/*
native GetActorPoolSize();
*/

/**
 * <library>omp_core</library>
 * <param name="enable"><b><c>1</c></b> to enable, <b><c>0</c></b> to disable tire popping</param>
 * <remarks>Tire popping is enabled by default.  If
 * you want to disable tire popping, you'll have to manually script it using <a href="#OnVehicleDamageStatusUpdate">
 * OnVehicleDamageStatusUpdate</a>.</remarks>
 */
#pragma deprecated Use `OnVehicleDamageStatusUpdate`.
forward void:EnableTirePopping(bool:enable);

/**
 * <library>omp_core</library>
 * <summary>Get the string value of a server variable.</summary>
 * <param name="cvar">The name of the string variable to get the value of</param>
 * <param name="buffer">An array into which to store the value, passed by reference</param>
 * <param name="len">The length of the string that should be stored</param>
 * <seealso name="GetServerVarAsInt" />
 * <seealso name="GetServerVarAsBool" />
 * <remarks>This function is deprecated.  Please see
 * <a href="#GetConsoleVarAsString">GetConsoleVarAsString</a></remarks>
 * <remarks>Using this function on anything other than a <b>string</b> (int, bool or float) or a <b>nonexistent</b>
 * server variable, will <b>crash</b> your server! This is a bug.</remarks>
 * <remarks>Type 'varlist' in the server console to display a list of available server variables and
 * their types.</remarks>
 * <remarks>When filterscripts or plugins is specified as the cvar, this function only returns the name
 * of the first specified filterscript or plugin.  This is a bug.</remarks>
 * <returns>The length of the returned string. <b><c>0</c></b> if the specified server variable is not
 * a string or doesn't exist.</returns>
 */
#pragma deprecated Use `GetConsoleVarAsString`.
native GetServerVarAsString(const cvar[], buffer[], len = sizeof (buffer)) = GetConsoleVarAsString;

/**
 * <library>omp_core</library>
 * <summary>Get the integer value of a server variable.</summary>
 * <param name="cvar">The name of the integer variable to get the value of</param>
 * <seealso name="GetServerVarAsString" />
 * <seealso name="GetServerVarAsBool" />
 * <remarks>This function is deprecated.  Please see <a href="#GetConsoleVarAsInt">GetConsoleVarAsInt</a></remarks>
 * <remarks>Type 'varlist' in the server console to display a list of available server variables and
 * their types.</remarks>
 * <returns>The value of the specified server variable.  0 if the specified server variable is not an
 * integer or doesn't exist.</returns>
 */
#pragma deprecated Use `GetConsoleVarAsInt`.
native GetServerVarAsInt(const cvar[]) = GetConsoleVarAsInt;

/**
 * <library>omp_core</library>
 * <summary>Get the float value of a server variable.</summary>
 * <param name="cvar">The name of the float variable to get the value of</param>
 * <seealso name="GetServerVarAsString" />
 * <seealso name="GetServerVarAsBool" />
 * <remarks>This function is deprecated.  Please see <a href="#GetConsoleVarAsInt">GetConsoleVarAsInt</a></remarks>
 * <remarks>Type 'varlist' in the server console to display a list of available server variables and
 * their types.</remarks>
 * <returns>The value of the specified server variable.  0 if the specified server variable is not a
 * float or doesn't exist.</returns>
 */
#pragma deprecated Use `GetConsoleVarAsFloat`.
native Float:GetServerVarAsFloat(const cvar[]) = GetConsoleVarAsFloat;

/**
 * <library>omp_core</library>
 * <summary>Get the boolean value of a server variable.</summary>
 * <param name="cvar">The name of the boolean variable to get the value of</param>
 * <seealso name="GetServerVarAsString" />
 * <seealso name="GetServerVarAsInt" />
 * <remarks>This function is deprecated.  Please see <a href="#GetConsoleVarAsBool">GetConsoleVarAsBool</a></remarks>
 * <remarks>Type 'varlist' in the server console to display a list of available server variables and
 * their types.</remarks>
 * <returns>The value of the specified server variable. <b><c>0</c></b> if the specified server variable
 * is not a boolean or doesn't exist.</returns>
 */
#pragma deprecated Use `GetConsoleVarAsBool`.
native bool:GetServerVarAsBool(const cvar[]) = GetConsoleVarAsBool;

/**
 * <library>omp_core</library>
 * <summary>This function does not work in the current SA:MP version!/</summary>
 * <seealso name="CreatePickup" />
 * <seealso name="GivePlayerMoney" />
 * <seealso name="OnPlayerDeath" />
 */
#pragma deprecated Use `CreatePickup`.
forward void:SetDeathDropAmount(amount);

/**
 * <library>omp_core</library>
 * <summary>Hashes a password using the SHA-256 hashing algorithm.  Includes a salt.  The output is
 * always 256 bytes in length, or the equivalent of 64 Pawn cells.</summary>
 * <param name="password">The password to hash</param>
 * <param name="salt">The salt to use in the hash</param>
 * <param name="output">The returned hash</param>
 * <param name="size">The returned hash maximum length</param>
 * <remarks>The salt is appended to the end of the password, meaning password 'foo' and salt 'bar' would
 * form 'foobar'. </remarks>
 * <remarks>The salt should be random, unique for each player and at least as long as the hashed password.
 *  It is to be stored alongside the actual hash in the player's account. </remarks>
 * <remarks>The result is 64 charaters long, so the output array must be at least 65 cells big.</remarks>
 */
#pragma deprecated Use BCrypt for hashing passwords. For other purposes use SHA256_Hash
native SHA256_PassHash(const password[], const salt[], output[], size = sizeof (output));

/**
 * <library>omp_core</library>
 * <summary>Hashes a string using the SHA-256 hashing algorithm.  Includes a salt.  The output is
 * always 256 bytes in length, or the equivalent of 64 Pawn cells.</summary>
 * <param name="content">The string content to hash</param>
 * <param name="salt">The salt to use in the hash</param>
 * <param name="output">The returned hash</param>
 * <param name="size">The returned hash maximum length</param>
 * <remarks>The salt is appended to the end of the string content, meaning string 'foo' and salt 'bar' would
 * form 'foobar'. </remarks>
 * <remarks>The result is 64 charaters long, so the output array must be at least 65 cells big.</remarks>
 */
native SHA256_Hash(const content[], const salt[], output[], size = sizeof (output)) = SHA256_PassHash;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `CountRunningTimers`.
native GetRunningTimers() = CountRunningTimers;

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
 * <summary>This callback is triggered when the gamemode starts.</summary>
 * <seealso name="OnGameModeExit" />
 * <seealso name="OnFilterScriptInit" />
 * <seealso name="OnFilterScriptExit" />
 * <remarks>This function can also be used in a filterscript to detect if the gamemode changes with
 * RCON commands like changemode or gmx, as changing the gamemode does not reload a filterscript.</remarks>
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnGameModeInit();

/**
 * <summary>This callback is called when a gamemode ends, either through 'gmx', the server being shut
 * down, or <a href="#GameModeExit">GameModeExit</a>.</summary>
 * <seealso name="OnGameModeInit" />
 * <seealso name="OnFilterScriptExit" />
 * <seealso name="OnFilterScriptInit" />
 * <seealso name="GameModeExit" />
 * <remarks>This function can also be used in a filterscript to detect if the gamemode changes with
 * RCON commands like changemode or gmx, as changing the gamemode does not reload a filterscript.</remarks>
 * <remarks>When using OnGameModeExit in conjunction with the 'rcon gmx' console command keep in mind
 * there is a potential for client bugs to occur an example of this is excessive
 * <a href="#RemoveBuildingForPlayer">RemoveBuildingForPlayer</a>
 * calls during OnGameModeInit which could result in a client crash. </remarks>
 * <remarks>This callback will NOT be called if the server crashes or the process is killed by other
 * means, such as using the Linux kill command or pressing the close-button on the Windows console.
 * </remarks>
 * <returns>
 *   <b><c>0</c></b> - Will prevent other filterscripts from receiving this callback.<br />
 *   <b><c>1</c></b> - Indicates that this callback will be passed to the next filterscript.<br />
 *   It is always called first in gamemode.
 * </returns>
 */
forward OnGameModeExit();

/**
 * <summary>This callback is called when a filterscript is initialized (loaded).  It is only called
 * inside the filterscript which is starting.</summary>
 * <seealso name="OnFilterScriptExit" />
 * <seealso name="OnGameModeInit" />
 * <seealso name="OnGameModeExit" />
 * <returns>This callback does not handle returns.</returns>
 */
forward OnFilterScriptInit();

/**
 * <summary>This callback is called when a filterscript is unloaded.  It is only called inside the filterscript
 * which is unloaded.</summary>
 * <seealso name="OnFilterScriptInit" />
 * <seealso name="OnGameModeInit" />
 * <seealso name="OnGameModeExit" />
 * <returns>This callback does not handle returns.</returns>
 */
forward OnFilterScriptExit();

/**
 * <summary>This callback is called for each connected player when a script is loaded.</summary>
 * <seealso name="OnFilterScriptInit" />
 * <seealso name="OnFilterScriptExit" />
 * <seealso name="OnGameModeInit" />
 * <seealso name="OnGameModeExit" />
 * <returns>This callback does not handle returns.</returns>
 */
forward OnScriptLoadPlayer(playerid, bool:isEntryScript);

/**
 * <summary>This callback is called for each connected player when a script is unloaded.</summary>
 * <seealso name="OnFilterScriptInit" />
 * <seealso name="OnFilterScriptExit" />
 * <seealso name="OnGameModeInit" />
 * <seealso name="OnGameModeExit" />
 * <returns>This callback does not handle returns.</returns>
 */
forward OnScriptUnloadPlayer(playerid, bool:isEntryScript);
