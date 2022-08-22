#if defined _INC_open_mp
	#endinput
#endif
#define _INC_open_mp

/**
 * <library name="open.mp" summary="open.mp includes entry point.">
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
 *      (major << 28) | (minor << 21) | (patch << 14) | (prerel)
 *   </code>
 *   </remarks>
 */
public const __OPEN_MP_VERSION = 0;
#pragma unused __OPEN_MP_VERSION

// Optionally stricter tags.
#if defined NO_TAGS
	#define __TAG(%0) _
	#define OPEN_MP_TAGS {Float, _}
#elseif defined STRONG_TAGS
	#define __TAG(%0) T_%0
	// TODO: Add all the other tags.
	#define OPEN_MP_TAGS {Float, _}
#else // if defined WEAK_TAGS
	#define __TAG(%0) t_%0
	#define WEAK_TAGS
	// TODO: Add all the other tags.
	#define OPEN_MP_TAGS {Float, _}
#endif

// Optionally use `void:` tags on natives - ensure they don't return anything.
// This is not the default as it adds a tiny bit of overhead to the calls.
#if defined VOID_TAGS
	//
	// For the input:
	//
	#if 0
		native void:ShowPlayerMarkers(PLAYER_MARKERS_MODE:mode);
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
			// Remove the previous frame and return address from the stack.
			#emit POP.pri
			#emit POP.alt
			#emit SCTRL       5
			// Call the underlying native, with the current stack, thus the
			// parameters passed to the containing function.
			#emit SYSREQ.C    __ShowPlayerMarkers
			// `SYSREQ` doesn't empty the stack so the parameters are still
			// there.  Push the return address back as if we were calling the
			// function (`alt` is not clobbered by `SYSREQ`) and then put the
			// frame pointer back on the stack to be used by the return code.
			#emit PUSH.alt
			#emit PROC
			// End the function with no value returned.
		}
	#endif
	//
	// The parameters are not used in this code, the entire stack is instead
	// forwarded to the native; hence the `disable 203` below so that we don't
	// get loads of warnings in native declarations.
	//
	// The macro matches `native` with `void:` anywhere later in the line, but
	// before brackets.  This does mean it will match `native not_void:` and any
	// other tags that end with `void:` and no earlier `v`.
	#define native%9void:%0(%1); native __%0() = %0; stock %0(%1) { __emit(POP.pri, POP.alt, SCTRL 5, SYSREQ.C __%0, PUSH.alt, PROC); }
#endif

#define void:
#define string:

// Disable the symbol length warning.
#pragma warning push
#pragma warning disable 200

// Define a symbol and check another one.  They're the same when truncated.
#if !defined __COMPILER_sNAMEMAX
	#define __COMPILER_SYMBOL_NAME_CHECK_1F
	#if defined __COMPILER_SYMBOL_NAME_CHECK_1F@
		#define __COMPILER_sNAMEMAX (31)
		#define OPEN_MP_LONG_NAMES (0)
	#endif
#endif
#if !defined __COMPILER_sNAMEMAX
	#define __COMPILER_SYMBOL_NAME_CHECK_3F_________padding_________padding
	#if defined __COMPILER_SYMBOL_NAME_CHECK_3F_________padding_________padding@
		#define __COMPILER_sNAMEMAX (63)
		#define OPEN_MP_LONG_NAMES (1)
	#endif
#endif
#if !defined __COMPILER_sNAMEMAX
	#error Unknown compiler max symbol length.
#endif

// Maybe re-enable the symbol length warning.
#pragma warning pop

/**
 * <summary>
 *   An invalid value (<c>-1</c>) as a boolean for some natives (most notably
 *   the vehicle param ones) that can skip `true`/`false` parameters.
 * </summary>
 */
const bool:undefined = bool:-1;

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

// Backwards-compatibility defines.
#define _YSF_included
#define _inc_ysf

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

