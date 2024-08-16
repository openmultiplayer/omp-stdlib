#if defined _INC_open_mp
	#endinput
#endif
#define _INC_open_mp

/**
 * <library name="open.mp" summary="open.mp includes entry point.">
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

#define SAMP_CONST_CORRECT
#define OPEN_MP_CONST_CORRECT

/**
 *   <remarks>
 *   Version examples:
 *   <ul>
 *     <li><c>0.3.DL R1       - 03D010</c></li>
 *     <li>                               </li>
 *     <li><c>0.3.7 R3        - 037030</c></li>
 *     <li><c>0.3.7 R2-2      - 037022</c></li>
 *     <li><c>0.3.7 R1-2      - 037012</c></li>
 *     <li><c>0.3.7           - 037000</c></li>
 *     <li>                               </li>
 *     <li><c>0.3z R4         - 030700</c></li>
 *     <li><c>0.3z R3         - 030700</c></li>
 *     <li><c>0.3z R2-1       - 030700</c></li>
 *     <li><c>0.3z R1-2       - 030700</c></li>
 *     <li><c>0.3z            - 030700</c></li>
 *     <li><c>0.3x R2 patch 1 - 030621</c></li>
 *     <li><c>0.3x R2         - 030620</c></li>
 *     <li><c>0.3x R1-2       - 030612</c></li>
 *     <li><c>0.3x            - 030600</c></li>
 *     <li><c>0.3e            - 030500</c></li>
 *     <li><c>0.3d            - 030400</c></li>
 *     <li><c>0.3c            - 030300</c></li>
 *     <li><c>0.3b            - 030200</c></li>
 *     <li><c>0.3a            - 030100</c></li>
 *     <li>                               </li>
 *     <li><c>0.2X            - 02A000</c></li>
 *     <li><c>0.2.2 R3        - 022300</c></li>
 *   </ul>
 *   Rough rules:
 *
 *   <p />
 *   Uses (roughtly) BCD.  Special versions are denoted outside 0-9.
 *   <code>
 *   0.1.2c R4-5
 *   | | ||  | |
 *   0 1 23  4 5
 *   =
 *   0x012345
 *   </code>
 *   (assuming c is the third revision)
 *
 *   <p />
 *   0.2X becomes 02A000 because it is basically 0.2.3, but not, while higher than
 *   0.2.2 so can't be 020400 (for example).  Also, its a capital letter, so doesn't
 *   use the revision method.
 *
 *   <p />
 *   P.S.  Making a consistent scheme for SA:MP versions is REALLY hard.
 *
 *   <p />
 *   open.mp releases can use `A` as the first digit.
 *   </remarks>
 */

public const __SAMP_INCLUDES_VERSION = 0x037030;
#pragma unused __SAMP_INCLUDES_VERSION

/**
 *   <remarks>
 *   If running on SA:MP this will remain <c>0</c>, open.mp will set it.
 *   open.mp versions look like:
 *   <code>
 *      01.04.02.0544
 *   </code>
 *   Thus they are encoded here as:
 *   <code>
 *      (major &lt;&lt; 28) | (minor &lt;&lt; 21) | (patch &lt;&lt; 14) | (prerel)
 *   </code>
 *   </remarks>
 */
public const __OPEN_MP_VERSION = 0;
#pragma unused __OPEN_MP_VERSION

#if defined __PawnBuild
	#if __PawnBuild == 0
		#undef __PawnBuild
		#define __pawn_build 0
	#else
		#define __pawn_build __PawnBuild
	#endif
#else
	#define __pawn_build 0
#endif

#if defined SAMP_COMPAT
	#if !defined NO_TAGS
		#define NO_TAGS
	#endif

	#if !defined MIXED_SPELLINGS
		#define MIXED_SPELLINGS
	#endif

	#if !defined OPEN_MP_NO_WRAPPER_WARNING
		#define OPEN_MP_NO_WRAPPER_WARNING
	#endif

	#if !defined LEGACY_SCRIPTING_API
		#define LEGACY_SCRIPTING_API
	#endif
#endif

// Optionally stricter tags.
#if defined NO_TAGS
	#define __TAG(%0) _
#elseif defined STRONG_TAGS
	#define __TAG(%0) T_%0
	#if __pawn_build >= 11
		#define OPEN_MP_TAGS {LANDING_GEAR_STATE, T_CONNECTION_STATUS, T_CP_TYPE, T_WEAPON, T_PLAYER_MARKERS_MODE, T_DIALOG_STYLE, T_HTTP_METHOD, T_HTTP_ERROR, T_DOWNLOAD_REQUEST, T_SELECT_OBJECT, T_OBJECT_MATERIAL_SIZE, T_OBJECT_MATERIAL_TEXT_ALIGN, T_EDIT_RESPONSE, T_PLAYER_STATE, T_SPECIAL_ACTION, T_FIGHT_STYLE, T_WEAPONSKILL, T_WEAPONSTATE, T_KEY, T_CAM_MODE, T_MAPICON, T_SPECTATE_MODE, T_PLAYER_RECORDING_TYPE, T_FORCE_SYNC, T_CLICK_SOURCE, T_BULLET_HIT_TYPE, T_TEXT_DRAW_FONT, T_TEXT_DRAW_ALIGN, T_VARTYPE, T_CARMODTYPE, T_VEHICLE_MODEL_INFO, T_VEHICLE_PANEL_STATUS, T_VEHICLE_DOOR_STATUS, T_VEHICLE_LIGHT_STATUS, T_VEHICLE_TYRE_STATUS, T_WEAPON_SLOT, Bit, Bitmap, XML, XMLEntry, Group, INI, Language, Style, DB, DBResult, Menu, Text, PlayerText, Text3D, PlayerText3D, File, Float, CUSTOM_TAG_TYPES, _}
	#else
		#define OPEN_MP_TAGS {T_WEAPON, Text, PlayerText, Text3D, PlayerText3D, File, Float, CUSTOM_TAG_TYPES, _}
	#endif
#else // if defined WEAK_TAGS
	#define __TAG(%0) t_%0
	#define WEAK_TAGS
#endif

#if defined OPEN_MP_TAGS
#elseif __pawn_build >= 11
	// Why does this contain YSI tags?  `Bit` - `Style`?  People have been
	// trained to use `CUSTOM_TAG_TYPES` to add tags to various call checks,
	// but not for YSI internal tags.  Not having them here would be a change
	// for many existing scripts that didn't previously have to specify those
	// tags.  Having more here isn't a problem, so they're just all here.
	#define OPEN_MP_TAGS {LANDING_GEAR_STATE, Bit, Bitmap, XML, XMLEntry, Group, INI, Language, Style, DB, DBResult, Menu, Text, PlayerText, Text3D, PlayerText3D, File, Float, CUSTOM_TAG_TYPES, _}
#else
	// I say it isn't a problem - the old compiler is limited to only 16 tags,
	// thus `CUSTOM_TAG_TYPES` is limited to eight tags.  To keep the numbers
	// down these are the most common (IMHO) tags plus those from old defines.
	#define OPEN_MP_TAGS {Text, PlayerText, Text3D, PlayerText3D, File, Float, CUSTOM_TAG_TYPES, _}
#endif

// Optionally use `void:` tags on natives - ensure they don't return anything.
// This is not the default as it adds a tiny bit of overhead to the calls.
#if defined VOID_TAGS
	//
	// For the input:
	//
	#if 0
		/* */ native void:ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode);
	#endif
	//
	// The generated code looks like:
	//
	#if 0
		// This is internal and doesn't need the parameters declaring.  It is
		// also hidden from Qawno by using `/* */` before `native`.
		/* */ native __ShowPlayerMarkers();

		// This does need the parameters as it is what users call.
		stock ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode)
		{
			// Remove the previous frame and return address from the stack.  We
			// need to store these both temporarily across the `SYSREQ` call.
			// The return address we store in `alt` because `SYSREQ` never
			// clobbers that register (even a re-entrant native like
			// `CallLocalFunction` saves and restores it), and we store the
			// frame address in the frame pointer register, because why not?
			#emit POP.pri
			#emit POP.alt
			#emit SCTRL       5
			// Call the underlying native, with the current stack, thus the
			// parameters passed to the containing function.
			#emit SYSREQ.C    __ShowPlayerMarkers
			// `SYSREQ` doesn't empty the stack so the parameters are still
			// there.  Push the return address back as if we were calling the
			// function and then put the frame pointer back on the stack with
			// `PROC` to be used by the return code straight away.  It is faster
			// to call `PROC`/`RETN` than any more explicit code because they
			// both do so much that would have to be imitated.
			#emit PUSH.alt
			#emit PROC
			// End the function with no value returned.
		}

		// The ideal would be:
		#pragma naked
		stock ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode)
		{
			#emit POP.alt
			#emit SYSREQ.C    __ShowPlayerMarkers
			#emit PUSH.alt
			#emit PROC
			#emit RETN
		}

		// But we can't do that in macros without `__pragma`.  Even if we could
		// determine the parameter count in the macro (which we can't) the
		// result with explicit removal of parameters and a `JUMP` instead of
		// `RETN` would be no shorter than the `PROC` trick here.

	#endif
	//
	// The parameters are not used in this code, the entire stack is instead
	// forwarded to the native; hence the `disable 203` below so that we don't
	// get loads of warnings in native declarations.
	//
	// The macro matches `native` with `void:` anywhere later in the line, but
	// before brackets.  This does mean it will match `native not_void:` and any
	// other tags that end with `void:` and no earlier `v`s.
	#define native%9void:%0(%1); %0(%1);native __%0() = %0; stock %0(%1) { __emit(POP.pri, POP.alt, SCTRL 5, SYSREQ.C __%0, PUSH.alt, PROC); }
#endif

#define void:
#define string:

// Silly extension to syntax.  It means we can do:
//
//    const open.mp_VERSION = 6;
//    #if open.mp_TEST
//    #endif
//
//#define open.mp OPEN_MP

/**
 * <summary>
 *   The maximum length of symbol names, excluding any NULLs.
 * </summary>
 */
#if __pawn_build == 0
	const __namemax = 31;
#else
	// Disable the symbol length warning.
	//
	// BuT I tHouGHt DiSaBlInG WArNiNGs Was BaD!
	//
	// Not when there's an actual reason.  In this case we're exploiting the
	// fact that the compiler truncates some symbol names if they're too long to
	// check if they were truncated and thus determine the maximum symbol
	// length.  However, the compiler will normally (rightfully) give a warning
	// when it does this.  We don't want excess warnings for behaviour we are
	// actually exploiting, so don't issue the warning.  But make sure we re-
	// enable it afterwards.
	#pragma warning push
	#pragma warning disable 200

	// Define a symbol and check another one.  They're the same when truncated.
	#define __OPEN_MP_LONG_SYMBOL_NAME_TEST
	#if defined __OPEN_MP_LONG_SYMBOL_NAME_TEST@
		const __namemax = 31;
	#else
		#define __OPEN_MP_LONG_SYMBOL_NAME_TEST_____padding_________padding____
		#if defined __OPEN_MP_LONG_SYMBOL_NAME_TEST_____padding_________padding____@
			const __namemax = 63;
		#else
			#error Unknown compiler max symbol length.
		#endif
	#endif

	// Maybe re-enable the symbol length warning.
	#pragma warning pop
#endif


// Try many places to get the latest version.

#tryinclude "args"
#tryinclude "console"
#tryinclude "core"
#tryinclude "file"
#tryinclude "float"
#tryinclude "string"
#tryinclude "time"

#tryinclude <args>
#tryinclude <console>
#tryinclude <core>
#tryinclude <file>
#tryinclude <float>
#tryinclude <string>
#tryinclude <time>

#tryinclude "..\pawn-stdlib\args"
#tryinclude "..\pawn-stdlib\console"
#tryinclude "..\pawn-stdlib\core"
#tryinclude "..\pawn-stdlib\file"
#tryinclude "..\pawn-stdlib\float"
#tryinclude "..\pawn-stdlib\string"
#tryinclude "..\pawn-stdlib\time"

#tryinclude <pawn-stdlib\args>
#tryinclude <pawn-stdlib\console>
#tryinclude <pawn-stdlib\core>
#tryinclude <pawn-stdlib\file>
#tryinclude <pawn-stdlib\float>
#tryinclude <pawn-stdlib\string>
#tryinclude <pawn-stdlib\time>

// No `args` check - it is optional.

// No `console` check - it is optional.

#if !defined _core_included
	#error cannot read from file: "core"
#endif

#if !defined _file_included
	#error cannot read from file: "file"
#endif

#if !defined _Float_included // Not `_float_included`.
	#error cannot read from file: "float"
#endif

#if !defined _string_included
	#error cannot read from file: "string"
#endif

#if !defined _time_included
	#error cannot read from file: "time"
#endif

/// <p/>
#if defined VOID_TAGS
	// Disable the unused parameters warning.
	#pragma warning push
	#pragma warning disable 203
#endif

#tryinclude "omp_core"
#tryinclude <omp_core>
#if !defined _INC_omp_core
	#error cannot read from file: "omp_core"
#endif

#tryinclude "omp_player"
#tryinclude <omp_player>
#if !defined _INC_omp_player
	#error cannot read from file: "omp_player"
#endif

#tryinclude "omp_actor"
#tryinclude <omp_actor>
#if !defined _INC_omp_actor
	#error cannot read from file: "omp_actor"
#endif

#tryinclude "omp_checkpoint"
#tryinclude <omp_checkpoint>
#if !defined _INC_omp_checkpoint
	#error cannot read from file: "omp_checkpoint"
#endif

// Relies on `omp_player`
#tryinclude "omp_class"
#tryinclude <omp_class>
#if !defined _INC_omp_class
	#error cannot read from file: "omp_class"
#endif

#tryinclude "omp_database"
#tryinclude <omp_database>
#if !defined _INC_omp_database
	#error cannot read from file: "omp_database"
#endif

#tryinclude "omp_dialog"
#tryinclude <omp_dialog>
#if !defined _INC_omp_dialog
	#error cannot read from file: "omp_dialog"
#endif

#tryinclude "omp_gangzone"
#tryinclude <omp_gangzone>
#if !defined _INC_omp_gangzone
	#error cannot read from file: "omp_gangzone"
#endif

#tryinclude "omp_http"
#tryinclude <omp_http>
#if !defined _INC_omp_http
	#error cannot read from file: "omp_http"
#endif

#tryinclude "omp_menu"
#tryinclude <omp_menu>
#if !defined _INC_omp_menu
	#error cannot read from file: "omp_menu"
#endif

#tryinclude "omp_network"
#tryinclude <omp_network>
#if !defined _INC_omp_network
	#error cannot read from file: "omp_network"
#endif

#tryinclude "omp_object"
#tryinclude <omp_object>
#if !defined _INC_omp_object
	#error cannot read from file: "omp_object"
#endif

#tryinclude "omp_pickup"
#tryinclude <omp_pickup>
#if !defined _INC_omp_pickup
	#error cannot read from file: "omp_pickup"
#endif

#tryinclude "omp_textdraw"
#tryinclude <omp_textdraw>
#if !defined _INC_omp_textdraw
	#error cannot read from file: "omp_textdraw"
#endif

#tryinclude "omp_variable"
#tryinclude <omp_variable>
#if !defined _INC_omp_variable
	#error cannot read from file: "omp_variable"
#endif

#tryinclude "omp_vehicle"
#tryinclude <omp_vehicle>
#if !defined _INC_omp_vehicle
	#error cannot read from file: "omp_vehicle"
#endif

// Relies on `omp_vehicle`.
#tryinclude "omp_textlabel"
#tryinclude <omp_textlabel>
#if !defined _INC_omp_textlabel
	#error cannot read from file: "omp_textlabel"
#endif

#if defined VOID_TAGS
	// Maybe re-enable the unused parameters warning.
	#pragma warning pop
#endif

#if __pawn_build > 4
	// Disable the deprecation warning.  There's a bug on some compiler versions
	// where using a deprecated function shows two warnings - one at the call
	// site and one at the declaration site.  There's no point having the
	// latter, this disables that.
	#pragma warning push
	#pragma warning disable 234
#endif

// Some compatibility functions that need defines.  These functions don't call
// the natives in the server because doing so would print a deprecation warning
// in the console.  Obviously we want people to have a deprecation warning, but
// as they're using these includes they get those warnings at compile-time, and
// we can reserve the runtime warnings for code built with other includes.

/**
 * <library>omp_core</library>
 * <summary>Gets the highest playerid currently in use on the server.</summary>
 * <seealso name="GetVehiclePoolSize" />
 * <seealso name="GetMaxPlayers" />
 * <returns>The highest playerid currently in use on the server or <b><c>0</c></b> if there are no connected
 * players.</returns>
 */
#pragma deprecated This function is broken.  See: open.mp/docs/scripting/functions/GetPlayerPoolSize
stock GetPlayerPoolSize()
{
	return MAX_PLAYERS - 1;
}

/**
 * <library>omp_core</library>
 * <summary>Gets the highest vehicleid currently in use on the server.</summary>
 * <seealso name="GetPlayerPoolSize" />
 * <returns>The highest vehicleid currently in use on the server or <b><c>0</c></b> if there are no
 * created vehicles.</returns>
 */
#pragma deprecated This function is broken.  See: open.mp/docs/scripting/functions/GetVehiclePoolSize
stock GetVehiclePoolSize()
{
	return MAX_VEHICLES - 1;
}

/**
 * <library>omp_core</library>
 * <summary>Gets the highest actorid created on the server.</summary>
 * <seealso name="CreateActor" />
 * <seealso name="IsValidActor" />
 * <seealso name="SetActorHealth" />
 * <returns>The highest actorid created on the server or <b><c>0</c></b> if there are no created actors.</returns>
 */
#pragma deprecated This function is broken.  See: open.mp/docs/scripting/functions/GetActorPoolSize
stock GetActorPoolSize()
{
	return MAX_ACTORS - 1;
}

#if __pawn_build > 4
	// Maybe re-enable the deprecation warning.
	#pragma warning pop
#endif

// Backwards-compatibility defines.
#define _actor_included
#define _http_included
#define _objects_included
#define _players_included
#define _samp_included
#define _sampdb_included
#define _vehicles_included

#define _INC_a_actor
#define _INC_a_http
#define _INC_a_objects
#define _INC_a_players
#define _INC_a_samp
#define _INC_a_sampdb
#define _INC_a_vehicles

#define _inc_a_actor
#define _inc_a_http
#define _inc_a_objects
#define _inc_a_players
#define _inc_a_samp
#define _inc_a_sampdb
#define _inc_a_vehicles
