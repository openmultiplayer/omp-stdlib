// Look for an upgraded version of this file in common locations.
#tryinclude ".\omp-stdlib\_open_mp"
#tryinclude "..\omp-stdlib\_open_mp"
#tryinclude <omp-stdlib\_open_mp>
#tryinclude ".\omp-stdlib-master\_open_mp"
#tryinclude "..\omp-stdlib-master\_open_mp"
#tryinclude <omp-stdlib-master\_open_mp>
#tryinclude "_open_mp"
#tryinclude <_open_mp>

#if !defined _INC_open_mp
	#error Could not find the latest version of the open.mp includes.
#endif
