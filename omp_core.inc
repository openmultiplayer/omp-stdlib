
/**
 * <library>omp_core</library>
 * <summary>This function sends a message to a specific player with a chosen colour in the chat.  The
 * whole line in the chatbox will be in the set colour unless colour embedding is used (since <b><c>0.3c</c></b>).</summary>
 * <param name="playerid">The ID of the player to display the message to</param>
 * <param name="colour">The colour of the message (<b>RGBA</b>)</param>
 * <param name="message">The text that will be displayed <b>(max 144 characters)</b></param>
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
native bool:SendClientMessage(playerid, colour, const message[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Displays a message in chat to all players.  This is a multi-player equivalent of
 * <a href="#SendClientMessage">SendClientMessage</a>.</summary>
 * <param name="colour">The colour of the message (<b>RGBA</b>)</param>
 * <param name="message">The message to show (<b>max 144 characters</b>)</param>
 * <seealso name="SendClientMessage" />
 * <seealso name="SendPlayerMessageToAll" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native void:SendClientMessageToAll(colour, const message[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Sends a message in the name of a player to another player on the server.  The message will
 * appear in the chat box but can only be seen by the user specified with <paramref name="playerid"
 * />.  The line will start with the sender's name in their colour, followed by the message in white.</summary>
 * <param name="playerid">The ID of the player who will receive the message</param>
 * <param name="senderid">The sender's ID.  If invalid, the message will not be sent</param>
 * <param name="message">The message that will be sent</param>
 * <seealso name="SendPlayerMessageToAll" />
 * <seealso name="SendClientMessage" />
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="OnPlayerText" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 */
native bool:SendPlayerMessageToPlayer(playerid, senderid, const message[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Sends a message in the name of a player to all other players on the server.  The line will
 * start with the sender's name in their colour, followed by the message in white.</summary>
 * <param name="senderid">The ID of the sender.  If invalid, the message will not be sent</param>
 * <param name="message">The message that will be sent</param>
 * <seealso name="SendPlayerMessageToPlayer" />
 * <seealso name="SendClientMessageToAll" />
 * <seealso name="OnPlayerText" />
 * <remarks>Avoid using format specifiers in your messages without formatting the string that is sent.
 *  It will result in crashes otherwise.</remarks>
 */
native bool:SendPlayerMessageToAll(senderid, const message[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Adds a death to the 'killfeed' on the right-hand side of the screen for all players.</summary>
 * <param name="killer">The ID of the killer (can be <b><c>INVALID_PLAYER_ID</c></b>)</param>
 * <param name="killee">The ID of the player that died</param>
 * <param name="weapon">The <a href="http://wiki.sa-mp.com/wiki/Weapons">reason</a> (not always a weapon)
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
 * <summary>Adds a death to the 'killfeed' on the right-hand side of the screen for a single player.</summary>
 * <param name="playerid">The ID of the player to send the death message to</param>
 * <param name="killer">The ID of the killer (can be <b><c>INVALID_PLAYER_ID</c></b>)</param>
 * <param name="killee">The ID of the player that died</param>
 * <param name="weapon">The <a href="http://wiki.sa-mp.com/wiki/Weapons">reason</a> (not always a weapon)
 * for the victim's death.  Special icons can also be used (<b><c>ICON_CONNECT</c></b> and <b><c>ICON_DISCONNECT</c></b>)</param>
 * <seealso name="SendDeathMessage" />
 * <seealso name="OnPlayerDeath" />
 * <remarks>This Function was added in <b>SA-MP 0.3z R2-2</b> and will not work in earlier versions!</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.
 * </returns>
 */
native bool:SendDeathMessageToPlayer(playerid, killer, killee, weapon);

/**
 * <library>omp_core</library>
 * <summary>Shows 'game text' (on-screen text) for a certain length of time for all players.</summary>
 * <param name="string">The text to be displayed</param>
 * <param name="time">The duration of the text being shown in milliseconds</param>
 * <param name="style">The style of text to be displayed</param>
 * <seealso name="GameTextForPlayer" />
 * <seealso name="TextDrawShowForAll" />
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native void:GameTextForAll(const string[], time, style, OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Shows 'game text' (on-screen text) for a certain length of time for a specific player.</summary>
 * <param name="playerid">The ID of the player to show the gametext for</param>
 * <param name="string">The text to be displayed</param>
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
native bool:GameTextForPlayer(playerid, const string[], time, style, OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 * <summary>Sends an RCON (Remote Console) command.</summary>
 * <param name="command">The RCON command to be executed</param>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="OnRconCommand" />
 * <seealso name="OnRconLoginAttempt" />
 * <remarks>Does not support login, due to the lack of a 'playerid' parameter.</remarks>
 * <remarks>'password 0' will remove the server's password if one is set.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 * <remarks>This function will result in <a href="#OnRconCommand">OnRconCommand</a> being called.</remarks>
 */
native SendRconCommand(const command[]);

/**
 * <library>omp_core</library>
 * <summary>Kicks a player from the server.  They will have to quit the game and re-connect if they
 * wish to continue playing.</summary>
 * <param name="playerid">The ID of the player to kick</param>
 * <seealso name="Ban" />
 * <seealso name="BanEx" />
 * <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Kick() (such as sending a message
 * with <a href="#SendClientMessage">SendClientMessage</a>) will not reach the player.  A timer must
 * be used to delay the kick.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if the function failed to execute (player
 * specified doesn't exist).</returns>
 */
native Kick(playerid);

/**
 * <library>omp_core</library>
 * <summary>Ban a player who is currently in the server.  They will be unable to join the server ever
 * again.  The ban will be IP-based, and be saved in the samp.ban file in the server's root directory.
 * <a href="#BanEx">BanEx</a> can be used to give a reason for the ban.  IP bans can be added/removed
 * using the RCON banip and unbanip commands (<a href="#SendRconCommand">SendRconCommand</a>).</summary>
 * <param name="playerid">The ID of the player to ban</param>
 * <seealso name="BanEx" />
 * <seealso name="Kick" />
 * <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Ban() (such as sending a message
 * with SendClientMessage) will not reach the player.  A timer must be used to delay the ban.</remarks>
 * <remarks></remarks>
 */
native Ban(playerid);

/**
 * <library>omp_core</library>
 * <summary>Ban a player with a reason.</summary>
 * <param name="playerid">The ID of the player to ban</param>
 * <param name="reason">The reason for the ban</param>
 * <seealso name="Ban" />
 * <seealso name="Kick" />
 * <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Ban() (such as sending a message
 * with SendClientMessage) will not reach the player.  A timer must be used to delay the ban.</remarks>
 */
native BanEx(playerid, const reason[], OPEN_MP_TAGS:...);

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `SendClientMessage`
native SendClientMessagef(playerid, colour, const message[], OPEN_MP_TAGS:...) = SendClientMessage;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `SendClientMessageToAll`
native SendClientMessageToAllf(colour, const message[], OPEN_MP_TAGS:...) = SendClientMessageToAll;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `GameTextForPlayer`
native GameTextForPlayerf(playerid, time, style, const message[], OPEN_MP_TAGS:...) = GameTextForPlayer;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `GameTextForAll`
native GameTextForAllf(time, style, const message[], OPEN_MP_TAGS:...) = GameTextForAll;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `SendPlayerMessageToPlayer`
native SendPlayerMessageToPlayerf(playerid, senderid, const message[], OPEN_MP_TAGS:...) = SendPlayerMessageToPlayer;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `SendPlayerMessageToAll`
native SendPlayerMessageToAllf(senderid, const message[], OPEN_MP_TAGS:...) = SendPlayerMessageToAll;

/**
 * <library>omp_core</library>
 */
#pragma deprecated Use `SendRconCommand`
native SendRconCommandf(const command[], OPEN_MP_TAGS:...) = SendRconCommand;

/**
 * <library>a_samp</library>
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
 * <library>a_samp</library>
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
 * <library>a_samp</library>
 * <summary>Toggle whether the usage of weapons in interiors is allowed or not.</summary>
 * <param name="allow"><b><c>1</c></b> to enable weapons in interiors (enabled by default), <b><c>0</c></b>
 * to disable weapons in interiors</param>
 * <remarks>This function does not work in the current SA:MP version!</remarks>
 * <seealso name="SetPlayerInterior" />
 * <seealso name="GetPlayerInterior" />
 * <seealso name="OnPlayerInteriorChange" />
 */
#pragma deprecated Use `OnPlayerInteriorChange`.
native void:AllowInteriorWeapons(bool:allow);

/**
 * <library>a_samp</library>
 * <summary>Set the world weather for all players.</summary>
 * <param name="weatherid">The <a href="http://wiki.sa-mp.com/wiki/Weatherid">weather</a> to set</param>
 * <seealso name="SetPlayerWeather" />
 * <seealso name="SetGravity" />
 * <remarks>If <a href="#TogglePlayerClock">TogglePlayerClock</a> is enabled, weather will slowly change
 * over time, instead of changing instantly.</remarks>
 */
native void:SetWeather(weatherid);

/**
 * <library>a_samp</library>
 * <summary>Get the currently set gravity.</summary>
 * <seealso name="SetGravity" />
 * <returns>The current set gravity (as a float).</returns>
 */
native Float:GetGravity();

/**
 * <library>a_samp</library>
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

