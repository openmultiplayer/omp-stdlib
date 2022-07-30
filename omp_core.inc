#if defined _INC_omp_core
	#endinput
#endif
#define _INC_omp_core

/**
 * <library name="omp_core" summary="open.mp core functions and defines.">
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

/**
 * <library>omp_core</library>
 * <summary>Prints a string to the server console (not in-game chat) and logs (server_log.txt).</summary>
 * <param name="string">The string to print</param>
 * <seealso name="printf" />
 */
#if defined _console_included
	// Fixes a pawndoc bug - comments on `#ifdef`ed out functions are still put
	// in the output, unattached to any function.  So make a function.
	native a_samp_unused_print(const string[]);
	#define a_samp_unused_print
#else
	native print(const string[]);
#endif

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
#if defined _console_included
	// Fixes a pawndoc bug - comments on `#ifdef`ed out functions are still put
	// in the output, unattached to any function.  So make a function.
	native a_samp_unused_printf(const format[], OPEN_MP_TAGS:...);
	#define a_samp_unused_printf
#else
	native printf(const format[], OPEN_MP_TAGS:...);
#endif

#if !defined _console_included
	#define _console_included
#endif

/**
 * <library>omp_core</library>
 * <summary>Sets a 'timer' to call a function after some time.  Can be set to repeat.</summary>
 * <param name="functionName">Name of the function to call as a string.  This must be a public function
 * (forwarded).  A null string here will crash the server</param>
 * <param name="interval">Interval in milliseconds</param>
 * <param name="repeating">Whether the timer should repeat or not</param>
 * <seealso name="SetTimerEx" />
 * <seealso name="KillTimer" />
 * <remarks>Timer intervals are not accurate (roughly 25% off).  There's a fix available
 * <a href="http://forum.sa-mp.com/showthread.php?t=289675">here</a>.
 * </remarks>
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
 * <remarks>Timer intervals are not accurate (roughly 25% off).  There's a fix available
 * <a href="http://forum.sa-mp.com/showthread.php?t=289675">here</a>.
 * </remarks>
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
 * array's size <b>[CURRENTLY UNUSABLE]</b></li>
 *     <li><b><c>s</c></b> - string <b>[CURRENTLY UNUSABLE]</b></li>
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
native void:KillTimer(timerid);

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
 * <summary>Returns the uptime of the actual server (not the SA-MP server) in milliseconds.</summary>
 * <seealso name="tickcount" />
 * <remarks>GetTickCount will cause problems on servers with uptime of over 24 days as GetTickCount
 * will eventually warp past the integer size constraints.  However using
 * <a href="https://gist.github.com/ziggi/5d7d8dc42f54531feba7ae924c608e73">this</a>
 * function fixes the problem.</remarks>
 * <remarks>One common use for GetTickCount is for benchmarking.  It can be used to calculate how much
 * time some code takes to execute.</remarks>
 * <returns>Uptime of the actual server (not the SA-MP server).</returns>
 */
native GetTickCount();

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
 * <summary>Returns the norm (length) of the provided vector.</summary>
 * <param name="x">The vector's magnitude on the x axis</param>
 * <param name="y">The vector's magnitude on the y axis</param>
 * <param name="z">The vector's magnitude on the z axis</param>
 * <seealso name="GetPlayerDistanceFromPoint" />
 * <seealso name="GetVehicleDistanceFromPoint" />
 * <seealso name="floatsqroot" />
 * <remarks>This function was added in <b>SA-MP 0.3z</b> and will not work in earlier versions!</remarks>
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
 * <summary>Get the inversed value of a cosine in degrees.</summary>
 * <param name="value">The cosine for which to find the angle for</param>
 * <seealso name="floatcos" />
 * <returns>The angle in degrees.</returns>
 */
native Float:acos(Float:value);

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
 * <summary>Gets the highest playerid currently in use on the server.</summary>
 * <seealso name="GetVehiclePoolSize" />
 * <seealso name="GetMaxPlayers" />
 * <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
 * <returns>The highest playerid currently in use on the server or <b><c>0</c></b> if there are no connected
 * players.</returns>
 */
#pragma deprecated This function is fundamentally broken.  See: open.mp/docs/scripting/functions/GetPlayerPoolSize
native GetPlayerPoolSize();

/**
 * <library>omp_core</library>
 * <summary>Gets the highest vehicleid currently in use on the server.</summary>
 * <seealso name="GetPlayerPoolSize" />
 * <remarks>This function was added in <b>SA-MP 0.3.7</b> and will not work in earlier versions!</remarks>
 * <returns>The highest vehicleid currently in use on the server or <b><c>0</c></b> if there are no
 * created vehicles.</returns>
 */
#pragma deprecated This function is fundamentally broken.  See: open.mp/docs/scripting/functions/GetVehiclePoolSize
native GetVehiclePoolSize();

/**
 * <library>omp_core</library>
 * <summary>Gets the highest actorid created on the server.</summary>
 * <seealso name="CreateActor" />
 * <seealso name="IsValidActor" />
 * <seealso name="SetActorHealth" />
 * <remarks>This function was added in <b><b>SA-MP 0.3.7</b></b> and will not work in earlier versions!</remarks>
 * <returns>The highest actorid created on the server or <b><c>0</c></b> if there are no created actors.</returns>
 */
#pragma deprecated This function is fundamentally broken.  See: open.mp/docs/scripting/functions/GetActorPoolSize
native GetActorPoolSize();

/**
 * <library>omp_core</library>
 * <remarks>Not implemented.</remarks>
 */
forward AddCharModel(baseid, newid, const dff[], const textureLibrary[]);

/**
 * <library>omp_core</library>
 * <remarks>Not implemented.</remarks>
 */
forward AddSimpleModel(virtualWorld, baseid, newid, const dff[], const textureLibrary[]);

/**
 * <library>omp_core</library>
 * <remarks>Not implemented.</remarks>
 */
forward AddSimpleModelTimed(virtualWorld, baseid, newid, const dff[], const textureLibrary[], timeOn, timeOff);

/**
 * <library>omp_core</library>
 * <summary>This function will determine whether RCON admins will be teleported to their waypoint when
 * they set one.</summary>
 * <param name="allow"><b><c>0</c></b> to disable and <b><c>1</c></b> to enable</param>
 * <remarks><b>This function is deprecated.  Please see <a href="#OnPlayerClickMap">OnPlayerClickMap</a>.</b></remarks>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="AllowPlayerTeleport" />
 */
#pragma deprecated Use `OnPlayerClickMap`.
forward void:AllowAdminTeleport(bool:allow);

/**
 * <library>omp_core</library>
 * <summary>Toggle whether the usage of weapons in interiors is allowed or not.</summary>
 * <param name="allow"><b><c>1</c></b> to enable weapons in interiors (enabled by default), <b><c>0</c></b>
 * to disable weapons in interiors</param>
 * <seealso name="SetPlayerInterior" />
 * <seealso name="GetPlayerInterior" />
 * <seealso name="OnPlayerInteriorChange" />
 */
#pragma deprecated Use `OnPlayerInteriorChange`.
forward void:AllowInteriorWeapons(bool:allow);

/**
 * <library>omp_core</library>
 * <summary>Connect an NPC to the server.</summary>
 * <param name="name">The name the NPC should connect as.  Must follow the same rules as normal player
 * names</param>
 * <param name="script">The NPC script name that is located in the <b>npcmodes</b> folder (without the
 * .amx extension)</param>
 * <seealso name="IsPlayerNPC" />
 * <seealso name="OnPlayerConnect" />
 * <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
 * <remarks>NPCs do not have nametags.  These can be scripted with
 * <a href="#Attach3DTextLabelToPlayer">Attach3DTextLabelToPlayer</a>.</remarks>
 * <returns>This function always return <b><c>1</c></b>.</returns>
 */
native ConnectNPC(const name[], const script[]);

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
native DisableInteriorEnterExits();

/**
 * <library>omp_core</library>
 * <summary>Disables the nametag Line-Of-Sight checking so that players can see nametags through objects.</summary>
 * <seealso name="ShowNameTags" />
 * <seealso name="ShowPlayerNameTagForPlayer" />
 * <remarks>This function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
 * <remarks>This can not be reversed until the server restarts.</remarks>
 */
native DisableNameTagLOS();

/**
 * <library>omp_core</library>
 * <param name="enable"><b><c>1</c></b> to enable, <b><c>0</c></b> to disable tire popping</param>
 * <remarks>This function was removed in <b>SA-MP 0.3</b>.  Tire popping is enabled by default.  If
 * you want to disable tire popping, you'll have to manually script it using <a href="#OnVehicleDamageStatusUpdate">
 * OnVehicleDamageStatusUpdate</a>.</remarks>
 */
#pragma deprecated Use `OnVehicleDamageStatusUpdate`.
forward void:EnableTirePopping(bool:enable);

/**
 * <library>omp_core</library>
 * <summary>This function allows to turn on zone / area names such as the "Vinewood" or "Doherty" text
 * at the bottom-right of the screen as they enter the area.  This is a gamemode option and should be
 * set in the callback <a href="#OnGameModeInit">OnGameModeInit</a>.</summary>
 * <param name="enable">A toggle option for whether or not you'd like zone names on or off</param>
 */
#pragma deprecated Show names manually.
forward EnableZoneNames(bool:enable);

/**
 * <library>omp_core</library>
 * <remarks>Not implemented.</remarks>
 */
forward FindModelFileNameFromCRC(crc, output[], size = sizeof (output));

/**
 * <library>omp_core</library>
 * <remarks>Not implemented.</remarks>
 */
forward FindTextureFileNameFromCRC(crc, output[], size = sizeof (output));

/**
 * <library>omp_core</library>
 * <summary>Ends the current gamemode.</summary>
 * <seealso name="OnGameModeExit" />
 */
native void:GameModeExit();

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
native void:GameTextForAll(const format[], time, style, OPEN_MP_TAGS:...);

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
#pragma deprecated Use `GameTextForAll`.
native void:GameTextForAllf(const format[], time, style, OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Get the string value of a console variable.</summary>
 * <param name="cvar">The name of the string variable to get the value of</param>
 * <param name="buffer">An array into which to store the value, passed by reference</param>
 * <param name="len">The length of the string that should be stored</param>
 * <seealso name="GetConsoleVarAsInt" />
 * <seealso name="GetConsoleVarAsBool" />
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
 * <remarks>Type <b><c>varlist</c></b> in the server console to display a list of available console
 * variables and their types.</remarks>
 * <returns>The value of the specified console variable. <b><c>0</c></b> if the specified console variable
 * is not an integer or doesn't exist.</returns>
 */
native GetConsoleVarAsInt(const cvar[]);

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
 * <summary>Set a radius limitation for the chat.  Only players at a certain distance from the player
 * will see their message in the chat.  Also changes the distance at which a player can see other players
 * on the map at the same distance.</summary>
 * <param name="chatRadius">The range in which players will be able to see chat</param>
 * <seealso name="SetNameTagDrawDistance" />
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendPlayerMessageToAll" />
 * <seealso name="OnPlayerText" />
 */
native LimitGlobalChatRadius(Float:chatRadius);

/**
 * <library>omp_core</library>
 * <summary>Set the player marker radius.</summary>
 * <param name="markerRadius">The radius that markers will show at</param>
 * <seealso name="ShowPlayerMarkers" />
 * <seealso name="SetPlayerMarkerForPlayer" />
 * <seealso name="LimitGlobalChatRadius" />
 * <remarks>This Function was added in <b>SA-MP 0.3a</b> and will not work in earlier versions!</remarks>
 */
native LimitPlayerMarkerRadius(Float:markerRadius);

/**
 * <library>omp_core</library>
 * <remarks>Not implemented.</remarks>
 */
forward RedirectDownload(playerid, const url[]);

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
#pragma deprecated Use `SendPlayerMessageToAll`.
native bool:SendPlayerMessageToAllf(senderid, const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>This function does not work in the current SA:MP version! </summary>
 * <seealso name="CreatePickup" />
 * <seealso name="GivePlayerMoney" />
 * <seealso name="OnPlayerDeath" />
 */
#pragma deprecated Use `CreatePickup`.
forward void:SetDeathDropAmount(amount);

/**
 * <library>omp_core</library>
 * <summary>Set the name of the game mode, which appears in the server browser.</summary>
 * <param name="format">The gamemode name to display.  May be optionally formatted.</param>
 */
native SetGameModeText(const format[], OPEN_MP_TAGS:...);

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
 * <library>omp_core</library>
 * <summary>Set the world weather for all players.</summary>
 * <param name="weatherid">The <a href="http://wiki.sa-mp.com/wiki/Weatherid">weather</a> to set</param>
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
 * <summary>Hashes a password using the SHA-256 hashing algorithm.  Includes a salt.  The output is
 * always 256 bytes in length, or the equivalent of 64 Pawn cells.</summary>
 * <param name="password">The password to hash</param>
 * <param name="salt">The salt to use in the hash</param>
 * <param name="output">The returned hash</param>
 * <param name="size">The returned hash maximum length</param>
 * <remarks>This function was added in <b>SA-MP 0.3.7-R1</b> and will not work in earlier versions!</remarks>
 * <remarks>The salt is appended to the end of the password, meaning password 'foo' and salt 'bar' would
 * form 'foobar'. </remarks>
 * <remarks>The salt should be random, unique for each player and at least as long as the hashed password.
 *  It is to be stored alongside the actual hash in the player's account. </remarks>
 * <remarks>The result is 64 charaters long, so the output array must be at least 65 cells big.</remarks>
 */
#pragma deprecated Use BCrypt for hashing passwords.
native SHA256_PassHash(const password[], const salt[], output[], size = sizeof (output));

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
native UsePlayerPedAnims();

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
native ToggleChatTextReplacement(bool:enable);

/**
 * <library>omp_core</library>
 */
native bool:ChatTextReplacementToggled();

/**
 * <library>omp_core</library>
 */
native bool:IsValidNickName(const name[]);

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
native void:CreateExplosion(Float:x, Float:y, Float:z, type, Float:radius);

/**
 * <library>omp_core</library>
 */
native GetWeaponSlot(WEAPON:weaponid);

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

/**
 * <library>omp_core</library>
 */
forward bool:SetServerRuleFlags(const rule[], E_SERVER_RULE_FLAGS:flags);

/**
 * <library>omp_core</library>
 */
forward E_SERVER_RULE_FLAGS:GetServerRuleFlags(const rule[]);

/**
 * <library>omp_core</library>
 */
native GetRunningTimers();

