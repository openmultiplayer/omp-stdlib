#if defined _INC_a_vehicles
	#endinput
#endif

#if defined SAMP_COMPAT
	#if !defined OPEN_MP_NO_WRAPPER_WARNING
		#define OPEN_MP_NO_WRAPPER_WARNING
	#endif
#endif

#if defined OPEN_MP_NO_WRAPPER_WARNING
	#include <open.mp>
	#endinput
#endif

#if !defined __PawnBuild
	// Doesn't support `#warning`.
	static Using_a_vehicles_legacy_wrapper;
	static Include_open@mp_directly;
	static Also_update_your_compiler;
	#include <open.mp>
	// The old compiler doesn't like `#warning`, even within `#if`.
	#endinput
#endif
	
// This is just a backwards-compatible wrapper.
#warning Using <a_vehicles> legacy wrapper.  Include <open.mp> directly.
#include <open.mp>
