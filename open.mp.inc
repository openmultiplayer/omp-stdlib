#if defined _INC_open_mp_stdilb
	#endinput
#endif
#define _INC_open_mp_stdilb

#pragma tabsize 4
#define SAMP_CONST_CORRECT
#define OPEN_MP_CONST_CORRECT

/// <p/>

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
#elseif defined STRONG_TAGS
	#define __TAG(%0) E_%0
#else // if defined WEAK_TAGS
	#define __TAG(%0) e_%0
	#define WEAK_TAGS
#endif
#if defined MORE_TAGS
	#define __MORE(%0) __TAG(%0)
#else
	#define __MORE(%0) _
	#define LESS_TAGS
#endif
#define __LESS __TAG

#define OPEN_MP_TAGS {Float, _}


/**
 * <summary>
 *   An invalid value (<c>-1</c>) as a boolean for some natives (most notably
 *   the vehicle param ones) that can skip `true`/`false` parameters.
 * </summary>
 */
const bool:undef = bool:-1;

// Try many places to get the latest version.

#tryinclude "..\pawn-stdlib\console"
#tryinclude "..\pawn-stdlib\core"
#tryinclude "..\pawn-stdlib\file"
#tryinclude "..\pawn-stdlib\float"
#tryinclude "..\pawn-stdlib\string"
#tryinclude "..\pawn-stdlib\time"

#tryinclude <pawn-stdlib\console>
#tryinclude <pawn-stdlib\core>
#tryinclude <pawn-stdlib\file>
#tryinclude <pawn-stdlib\float>
#tryinclude <pawn-stdlib\string>
#tryinclude <pawn-stdlib\time>

#tryinclude "console"
#tryinclude "core"
#tryinclude "file"
#tryinclude "float"
#tryinclude "string"
#tryinclude "time"

#tryinclude <console>
#tryinclude <core>
#tryinclude <file>
#tryinclude <float>
#tryinclude <string>
#tryinclude <time>

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

#tryinclude "omp_menu"
#tryinclude <omp_menu>
#if !defined _INC_omp_menu
	#error cannot read from file: "omp_menu"
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

#tryinclude "omp_textlabel"
#tryinclude <omp_textlabel>
#if !defined _INC_omp_textlabel
	#error cannot read from file: "omp_textlabel"
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

