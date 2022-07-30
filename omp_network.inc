#if defined _INC_omp_network
	#endinput
#endif
#define _INC_omp_network

/**
 * <library name="omp_network" summary="open.mp core functions and defines.">
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
 * <library>omp_network</library>
 * <summary>Connection statuses</summary>
 */
#define CONNECTION_STATUS: __TAG(CONNECTION_STATUS):
enum CONNECTION_STATUS:__CONNSTAT
{
#if OPEN_MP_LONG_NAMES
	CONNECTION_STATUS_NO_ACTION,
	CONNECTION_STATUS_DISCONNECT_ASAP,
	CONNECTION_STATUS_DISCONNECT_ASAP_SILENTLY,
	CONNECTION_STATUS_DISCONNECT_ON_NO_ACK,
	CONNECTION_STATUS_REQUESTED_CONNECTION,
	CONNECTION_STATUS_HANDLING_CONNECTION_REQUEST,
	CONNECTION_STATUS_UNVERIFIED_SENDER,
	CONNECTION_STATUS_SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET,
	CONNECTION_STATUS_CONNECTED,
#endif
	CONNSTAT_NO_ACTION = 0,
	CONNSTAT_DISCONNECT_ASAP,
	CONNSTAT_DISCONNECT_ASAP_SILNT,
	CONNSTAT_DISCONNECT_ON_NO_ACK,
	CONNSTAT_REQUESTED_CONNECTION,
	CONNSTAT_HANDLING_CONN_REQ,
	CONNSTAT_UNVERIFIED_SENDER,
	CONNSTAT_SET_ENCRYPTION,
	CONNSTAT_CONNECTED
}
static stock CONNECTION_STATUS:_@CONNECTION_STATUS() { return __CONNSTAT; }

/**
 * <library>omp_network</library>
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
 * <library>omp_network</library>
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
 * <library>omp_network</library>
 * <summary>Ban a player with a reason.</summary>
 * <param name="playerid">The ID of the player to ban</param>
 * <param name="reason">The reason for the ban</param>
 * <seealso name="Ban" />
 * <seealso name="Kick" />
 * <remarks>As of <b>SA-MP 0.3x</b>, any action taken directly before Ban() (such as sending a message
 * with SendClientMessage) will not reach the player.  A timer must be used to delay the ban.</remarks>
 */
native BanEx(playerid, const reason[]);

/**
 * <library>omp_network</library>
 * <summary>Blocks an IP address from further communication with the server for a set amount of time
 * (with wildcards allowed).  Players trying to connect to the server with a blocked IP address will
 * receive the generic "You are banned from this server." message.  Players that are online on the specified
 * IP before the block will timeout after a few seconds and, upon reconnect, will receive the same message.</summary>
 * <param name="ipAddress">The IP to block</param>
 * <param name="timeMS">The time (in milliseconds) that the connection will be blocked for. <b><c>0</c></b>
 * can be used for an indefinite block</param>
 * <seealso name="UnBlockIpAddress" />
 * <seealso name="OnIncomingConnection" />
 * <remarks>Wildcards can be used with this function, for example blocking the IP <b><c>6.9.*.*</c></b>
 * will block all IPs where the first two octets are <b><c>6</c></b> and <b><c>9</c></b> respectively.
 *  Any number can be in place of an asterisk.</remarks>
 */
native BlockIpAddress(const ipAddress[], timeMS);

/**
 * <library>omp_network</library>
 * <summary>Unblock an IP address that was previously blocked using <a href="#BlockIpAddress">BlockIpAddress</a>.</summary>
 * <param name="ipAddress">The IP address to unblock</param>
 * <seealso name="BlockIpAddress" />
 * <seealso name="OnIncomingConnection" />
 */
native UnBlockIpAddress(const ipAddress[]);

/**
 * <library>omp_network</library>
 */
native bool:ClearBanList();

/**
 * <library>omp_network</library>
 */
native bool:IsBanned(const ipaddress[]);

/**
 * <library>omp_network</library>
 * <summary>Gets the tick rate (like FPS) of the server.</summary>
 * <seealso name="GetNetworkStats" />
 * <returns>The server tick rate (per second).  Returns <b><c>0</c></b> when the server is just started.</returns>
 */
native GetServerTickRate();

/**
 * <library>omp_network</library>
 * <summary>Gets the amount of time (in milliseconds) that a player has been connected to the server
 * for.</summary>
 * <param name="playerid">The ID of the player to get the connected time of</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <remarks>The return value is not reset to zero after changing the game mode (using the RCON command
 * "gmx").</remarks>
 * <returns>This function returns the amount of time (in milliseconds) that a player has been connected
 * to the server for. <b><c>0</c></b> is returned if the player is not connected.</returns>
 */
native NetStats_GetConnectedTime(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the number of messages the server has received from the player.</summary>
 * <param name="playerid">The ID of the player to get the data from</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <returns>This function returns the number of messages the server has received from the player. <b><c>0</c></b>
 * is returned if the player is not connected.</returns>
 */
native NetStats_MessagesReceived(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the amount of data (in bytes) that the server has received from the player.</summary>
 * <param name="playerid">The ID of the player to get the data from</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <returns>This function returns the number of bytes the server has received from the player. <b><c>0</c></b>
 * is returned if the player is not connected.</returns>
 */
native NetStats_BytesReceived(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the number of messages the server has sent to the player.</summary>
 * <param name="playerid">The ID of the player to get the data from</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <returns>The number of messages the server has sent to the player.</returns>
 */
native NetStats_MessagesSent(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the amount of data (in bytes) that the server has sent to the player.</summary>
 * <param name="playerid">The ID of the player to get the data from</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <returns>This function returns the number of bytes the server has sent to the player. <b><c>0</c></b>
 * is returned if the player is not connected.</returns>
 */
native NetStats_BytesSent(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the number of messages the player has received in the last second.</summary>
 * <param name="playerid">The ID of the player to get the data from</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <returns>the number of messages the player has received in the last second.</returns>
 */
native NetStats_MessagesRecvPerSecond(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the packet loss percentage of a player.  Packet loss means data the player is sending
 * to the server is being lost (or vice-versa).</summary>
 * <param name="playerid">The ID of the player to get the data from</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <remarks>Anything greater than 0.0% should already be a cause of concern.  Anything greater than
 * 1.0% is outright bad.</remarks>
 * <remarks>This function has been found to be currently unreliable the output is not as expected when
 * compared to the client.  Therefore this function should not be used as a packet loss kicker. </remarks>
 * <remarks>A more accurate packetloss function can be found here: <a href="http://forum.sa-mp.com/showpost.php?p=2488911&amp;postcount=984">
 * http://forum.sa-mp.com/showpost.php?p=2488911&amp;postcount=984</a></remarks>
 * <returns>The percentage packet loss as a float. <b><c>0.0</c></b> if player not connected.</returns>
 */
native Float:NetStats_PacketLossPercent(playerid);

/**
 * <library>omp_network</library>
 * <summary>Gets the player's current connection status.</summary>
 * <param name="playerid">The ID of the player to get the connection status of</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_GetIpPort" />
 * <seealso name="IsPlayerConnected" />
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnPlayerDisconnect" />
 * <remarks>
 *   <b>Status:</b><br />
 *   <ul>
 *     <li><b><c>0 - NO_ACTION</c></b></li>
 *     <li><b><c>1 - DISCONNECT_ASAP</c></b></li>
 *     <li><b><c>2 - DISCONNECT_ASAP_SILENTLY</c></b></li>
 *     <li><b><c>3 - DISCONNECT_ON_NO_ACK</c></b></li>
 *     <li><b><c>4 - REQUESTED_CONNECTION</c></b></li>
 *     <li><b><c>5 - HANDLING_CONNECTION_REQUEST</c></b></li>
 *     <li><b><c>6 - UNVERIFIED_SENDER</c></b></li>
 *     <li><b><c>7 - SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET</c></b></li>
 *     <li><b><c>8 - CONNECTED</c></b></li>
 *   </ul>
 * </remarks>
 * <returns>The player's connection status, as an integer value.</returns>
 */
native CONNECTION_STATUS:NetStats_ConnectionStatus(playerid);

/**
 * <library>omp_network</library>
 * <summary>Get a player's IP and port.</summary>
 * <param name="playerid">The ID of the player to get the IP and port of</param>
 * <param name="output">A string array to store the IP and port in, passed by reference</param>
 * <param name="size">The maximum length of the IP/port.  22 is recommended</param>
 * <seealso name="GetPlayerIp" />
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 */
native NetStats_GetIpPort(playerid, output[], size = sizeof (output));

/**
 * <library>omp_network</library>
 * <summary>Gets the server's network stats and stores them in a string.</summary>
 * <param name="output">The string to store the network stats in, passed by reference</param>
 * <param name="size">The length of the string to be stored</param>
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <remarks>
 *   <b>Example output:</b><br />
 *   <c>
 *     Server Ticks: 200<br />
 *     Messages in Send buffer: 0<br />
 *     Messages sent: 142<br />
 *     Bytes sent: 8203<br />
 *     Acks sent: 11<br />
 *     Acks in send buffer: 0<br />
 *     Messages waiting for ack: 0<br />
 *     Messages resent: 0<br />
 *     Bytes resent: 0<br />
 *     Packetloss: 0.0%<br />
 *     Messages received: 54<br />
 *     Bytes received: 2204<br />
 *     Acks received: 0<br />
 *     Duplicate acks received: 0<br />
 *     Inst.  KBits per second: 28.8<br />
 *     KBits per second sent: 10.0<br />
 *     KBits per second received: 2.7<br />
 *   </c>
 * </remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 */
native GetNetworkStats(output[], size = sizeof (output));

/**
 * <library>omp_network</library>
 * <summary>Gets a player's network stats and saves them into a string.</summary>
 * <param name="playerid">The ID of the player you want to get the networkstats of</param>
 * <param name="output">The string to store the networkstats in, passed by reference</param>
 * <param name="size">The length of the string that should be stored</param>
 * <seealso name="GetNetworkStats" />
 * <seealso name="NetStats_GetConnectedTime" />
 * <seealso name="NetStats_MessagesReceived" />
 * <seealso name="NetStats_BytesReceived" />
 * <seealso name="NetStats_MessagesSent" />
 * <seealso name="NetStats_BytesSent" />
 * <seealso name="NetStats_MessagesRecvPerSecond" />
 * <seealso name="NetStats_PacketLossPercent" />
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="NetStats_GetIpPort" />
 * <remarks>This function may not return accurate data when used under <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>
 * if the player has quit normally.  It usually returns accurate data if the player has been kicked
 * or has timed out.</remarks>
 */
native GetPlayerNetworkStats(playerid, output[], size = sizeof (output));

/**
 * <library>omp_network</library>
 * <summary>Check if a player is logged in as an RCON admin.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="SendRconCommand" />
 * <seealso name="OnRconLoginAttempt" />
 * <returns><b><c>1</c></b> if the player is an RCON admin, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerAdmin(playerid);

/**
 * <library>omp_network</library>
 * <summary>Sends an RCON (Remote Console) command.</summary>
 * <param name="format">The RCON command to be executed.  May be optionally formatted.</param>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="OnRconCommand" />
 * <seealso name="OnRconLoginAttempt" />
 * <remarks>Does not support login, due to the lack of a 'playerid' parameter.</remarks>
 * <remarks>'password 0' will remove the server's password if one is set.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 * <remarks>This function will result in <a href="#OnRconCommand">OnRconCommand</a> being called.</remarks>
 */
native SendRconCommand(const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_network</library>
 * <summary>Sends an RCON (Remote Console) command.</summary>
 * <param name="format">The RCON command to be executed.  May be optionally formatted.</param>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="OnRconCommand" />
 * <seealso name="OnRconLoginAttempt" />
 * <remarks>Does not support login, due to the lack of a 'playerid' parameter.</remarks>
 * <remarks>'password 0' will remove the server's password if one is set.</remarks>
 * <returns>This function always returns <b><c>1</c></b>.</returns>
 * <remarks>This function will result in <a href="#OnRconCommand">OnRconCommand</a> being called.</remarks>
 */
#pragma deprecated Use `SendRconCommand`
native SendRconCommandf(const format[], OPEN_MP_TAGS:...);

/**
 * <library>omp_network</library>
 * <summary>Returns the SA-MP client version, as reported by the player.</summary>
 * <param name="playerid">The ID of the player to get the client version of</param>
 * <param name="version">The string to store the player's version in, passed by reference</param>
 * <param name="len">The maximum length of the version</param>
 * <seealso name="GetPlayerName" />
 * <seealso name="GetPlayerPing" />
 * <seealso name="GetPlayerIp" />
 * <remarks>The string the version gets stored in will be empty if playerid is an NPC.</remarks>
 * <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure (if player specified doesn't exist).</returns>
 */
native GetPlayerVersion(playerid, version[], len = sizeof (version));

/**
 * <library>omp_network</library>
 * <summary>Get a players unique ID.</summary>
 * <param name="playerid">The player to get the unique ID of</param>
 * <param name="serial">Where to save the unique ID</param>
 * <param name="len">The size of "output" (the serial)</param>
 */
#pragma deprecated Use `GPCI`.
native gpci(playerid, serial[], len = sizeof (serial));

/**
 * <library>omp_network</library>
 * <summary>Get a players unique ID.</summary>
 * <param name="playerid">The player to get the unique ID of</param>
 * <param name="serial">Where to save the unique ID</param>
 * <param name="len">The size of "serial" (the serial)</param>
 */
native GPCI(playerid, serial[], len = sizeof (serial)) = gpci;

