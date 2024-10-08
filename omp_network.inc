#if defined _INC_omp_network
	#endinput
#endif
#define _INC_omp_network

/**
 * <library name="omp_network" summary="open.mp core functions and defines.">
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

/// <p/>
/**
 * <library>omp_network</library>
 * <summary>Connection statuses</summary>
 */
#define CONNECTION_STATUS: __TAG(CONNECTION_STATUS):
enum CONNECTION_STATUS:__CONNSTAT
{
	UNKNOWN_CONNECTION_STATUS                  = -1,
	CONNECTION_STATUS_NO_ACTION                = 0,
#if __namemax > 31
	CONNECTION_STATUS_DISCONNECT_ASAP,
	CONNECTION_STATUS_DISCONNECT_ASAP_SILENTLY,
	CONNECTION_STATUS_DISCONNECT_ON_NO_ACK,
	CONNECTION_STATUS_REQUESTED_CONNECTION,
	CONNECTION_STATUS_HANDLING_CONNECTION_REQUEST,
	CONNECTION_STATUS_UNVERIFIED_SENDER,
	CONNECTION_STATUS_SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET,
#endif
	CONNECTION_STATUS_CONNECTED                = 8,
	CONNSTAT_NO_ACTION                         = 0,
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

#define UNKNOWN_CONNECTION_STATUS              (CONNECTION_STATUS:-1)
#define CONNECTION_STATUS_NO_ACTION            (CONNECTION_STATUS:0)
#if __namemax > 31
#define CONNECTION_STATUS_DISCONNECT_ASAP      (CONNECTION_STATUS:1)
#define CONNECTION_STATUS_DISCONNECT_ASAP_SILENTLY (CONNECTION_STATUS:2)
#define CONNECTION_STATUS_DISCONNECT_ON_NO_ACK (CONNECTION_STATUS:3)
#define CONNECTION_STATUS_REQUESTED_CONNECTION (CONNECTION_STATUS:4)
#define CONNECTION_STATUS_HANDLING_CONNECTION_REQUEST (CONNECTION_STATUS:5)
#define CONNECTION_STATUS_UNVERIFIED_SENDER    (CONNECTION_STATUS:6)
#define CONNECTION_STATUS_SET_ENCRYPTION_ON_MULTIPLE_16_BYTE_PACKET (CONNECTION_STATUS:7)
#endif
#define CONNECTION_STATUS_CONNECTED            (CONNECTION_STATUS:8)
#define CONNSTAT_NO_ACTION                     (CONNECTION_STATUS:0)
#define CONNSTAT_DISCONNECT_ASAP               (CONNECTION_STATUS:1)
#define CONNSTAT_DISCONNECT_ASAP_SILNT         (CONNECTION_STATUS:2)
#define CONNSTAT_DISCONNECT_ON_NO_ACK          (CONNECTION_STATUS:3)
#define CONNSTAT_REQUESTED_CONNECTION          (CONNECTION_STATUS:4)
#define CONNSTAT_HANDLING_CONN_REQ             (CONNECTION_STATUS:5)
#define CONNSTAT_UNVERIFIED_SENDER             (CONNECTION_STATUS:6)
#define CONNSTAT_SET_ENCRYPTION                (CONNECTION_STATUS:7)
#define CONNSTAT_CONNECTED                     (CONNECTION_STATUS:8)

/// <p/>
/**
 * <library>omp_network</library>
 * <summary>Artwork/NetModels</summary>
 */
#define DOWNLOAD_REQUEST: __TAG(DOWNLOAD_REQUEST):
enum DOWNLOAD_REQUEST:__DOWNLOAD_REQUEST
{
	UNKNOWN_DOWNLOAD_REQUEST                   = -1,
	DOWNLOAD_REQUEST_EMPTY,
	DOWNLOAD_REQUEST_MODEL_FILE,
	DOWNLOAD_REQUEST_TEXTURE_FILE
}
static stock DOWNLOAD_REQUEST:_@DOWNLOAD_REQUEST() { return __DOWNLOAD_REQUEST; }

#define UNKNOWN_DOWNLOAD_REQUEST               (DOWNLOAD_REQUEST:-1)
#define DOWNLOAD_REQUEST_EMPTY                 (DOWNLOAD_REQUEST:0)
#define DOWNLOAD_REQUEST_MODEL_FILE            (DOWNLOAD_REQUEST:1)
#define DOWNLOAD_REQUEST_TEXTURE_FILE          (DOWNLOAD_REQUEST:2)

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

/**
 * <library>omp_network</library>
 * <summary>Kicks a player from the server.  They will have to quit the game and re-connect if they
 * wish to continue playing.</summary>
 * <param name="playerid">The ID of the player to kick</param>
 * <seealso name="Ban" />
 * <seealso name="BanEx" />
 * <remarks>Any action taken directly before Kick() (such as sending a message
 * with <a href="#SendClientMessage">SendClientMessage</a>) will not reach the player.  A timer must
 * be used to delay the kick.</remarks>
 * <returns>This function always returns <b><c>1</c></b>, even if the function failed to execute (player
 * specified doesn't exist).</returns>
 */
native bool:Kick(playerid);

/**
 * <library>omp_network</library>
 * <summary>Ban a player who is currently in the server.  They will be unable to join the server ever
 * again.  The ban will be IP-based, and be saved in the samp.ban file in the server's root directory.
 * <a href="#BanEx">BanEx</a> can be used to give a reason for the ban.  IP bans can be added/removed
 * using the RCON banip and unbanip commands (<a href="#SendRconCommand">SendRconCommand</a>).</summary>
 * <param name="playerid">The ID of the player to ban</param>
 * <seealso name="BanEx" />
 * <seealso name="Kick" />
 * <remarks>Any action taken directly before Ban() (such as sending a message
 * with SendClientMessage) will not reach the player.  A timer must be used to delay the ban.</remarks>
 * <remarks></remarks>
 */
native bool:Ban(playerid);

/**
 * <library>omp_network</library>
 * <summary>Ban a player with a reason.</summary>
 * <param name="playerid">The ID of the player to ban</param>
 * <param name="reason">The reason for the ban</param>
 * <seealso name="Ban" />
 * <seealso name="Kick" />
 * <remarks>Any action taken directly before Ban() (such as sending a message
 * with SendClientMessage) will not reach the player.  A timer must be used to delay the ban.</remarks>
 */
native bool:BanEx(playerid, const reason[]);

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
native bool:BlockIpAddress(const ipAddress[], timeMS);

/**
 * <library>omp_network</library>
 * <summary>Unblock an IP address that was previously blocked using <a href="#BlockIpAddress">BlockIpAddress</a>.</summary>
 * <param name="ipAddress">The IP address to unblock</param>
 * <seealso name="BlockIpAddress" />
 * <seealso name="OnIncomingConnection" />
 */
native bool:UnBlockIpAddress(const ipAddress[]);

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
 * <summary>Check if a player is logged in as an RCON admin.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <seealso name="SendRconCommand" />
 * <seealso name="OnRconLoginAttempt" />
 * <returns><b><c>1</c></b> if the player is an RCON admin, <b><c>0</c></b> if not.</returns>
 */
native bool:IsPlayerAdmin(playerid);

/**
 * <library>omp_player</library>
 */
native bool:SetPlayerAdmin(playerid, bool:admin);

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
native bool:SendRconCommand(const format[], OPEN_MP_TAGS:...);

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
#pragma deprecated Use `SendRconCommand`.
native bool:SendRconCommandf(const format[], OPEN_MP_TAGS:...) = SendRconCommand;

/**
 * <library>omp_network</library>
 * <summary>Returns the client version, as reported by the player.</summary>
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
native gpci(playerid, serial[], len = sizeof (serial));

/**
 * <library>omp_network</library>
 * <summary>Get a players unique ID.</summary>
 * <param name="playerid">The player to get the unique ID of</param>
 * <param name="serial">Where to save the unique ID</param>
 * <param name="len">The size of "serial" (the serial)</param>
 */
native GPCI(playerid, serial[], len = sizeof (serial)) = gpci;

/**
 * <library>omp_network</library>
 * <summary>Get the specified player's IP address and store it in a string.</summary>
 * <param name="playerid">The ID of the player to get the IP address of</param>
 * <param name="ip">An array into which to store the player's IP address, passed by reference</param>
 * <param name="len">The maximum length of the IP address (recommended 16)</param>
 * <seealso name="NetStats_GetIpPort" />
 * <seealso name="GetPlayerName" />
 * <seealso name="GetPlayerPing" />
 * <seealso name="GetPlayerVersion" />
 * <seealso name="OnIncomingConnection" />
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnPlayerDisconnect" />
 * <remarks>This function does not work when used in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>
 * because the player is already disconnected.  It will return an invalid IP (<b><c>255.255.255.255</c></b>).
 *  Save players' IPs under <a href="#OnPlayerConnect">OnPlayerConnect</a> if they need to be used under
 * <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>. </remarks>
 * <returns><b><c>1</c></b> on success and <b><c>0</c></b> on failure.</returns>
 */
native GetPlayerIp(playerid, ip[], len = sizeof (ip));

/**
 * <library>omp_player</library>
 */
native GetPlayerRawIp(playerid);

/**
 * <library>omp_network</library>
 * <summary>Get the ping of a player.  The ping measures the amount of time it takes for the server
 * to 'ping' the client and for the client to send the message back.</summary>
 * <param name="playerid">The ID of the player to get the ping of</param>
 * <seealso name="GetPlayerIp" />
 * <seealso name="GetPlayerName" />
 * <seealso name="GetPlayerVersion" />
 * <remarks>Player's ping may be <b><c>65535</c></b> for a while after a player connects</remarks>
 * <returns>The current ping of the player (expressed in milliseconds).</returns>
 */
native GetPlayerPing(playerid);

/**
 * <library>omp_network</library>
 * <summary>Perform a memory check on the client.</summary>
 * <param name="playerid">The ID of the player to check</param>
 * <param name="type">The type of check to perform</param>
 * <param name="memoryAddress">The base address to check</param>
 * <param name="memoryOffset">The offset from the base address</param>
 * <param name="byteCount">The number of bytes to check</param>
 */
native bool:SendClientCheck(playerid, type, memoryAddress, memoryOffset, byteCount);

/*
native # Netstats();
native            Netstats(
native      ====================(
native
*/

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
 * <remarks>A more accurate packetloss function can be found here:
 * <a href="https://sampforum.blast.hk/showthread.php?tid=281&pid=2488911#pid2488911">
 * https://sampforum.blast.hk/showthread.php?tid=281&pid=2488911#pid2488911</a></remarks>
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
 * <summary>Gets the player's current connection status.</summary>
 * <param name="playerid">The ID of the player to get the connection status of</param>
 * <seealso name="NetStats_ConnectionStatus" />
 * <seealso name="GetPlayerNetworkStats" />
 * <seealso name="GetNetworkStats" />
 * <seealso name="IsPlayerConnected" />
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnPlayerDisconnect" />
 * <returns>The player's connection status, as an integer value.</returns>
 */
native CONNECTION_STATUS:GetPlayerConnectMode(playerid) = NetStats_ConnectionStatus;

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

/*
native # Formatted();
native           Formatted(
native      ====================(
native
*/

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
native bool:GetNetworkStats(output[], size = sizeof (output));

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
native bool:GetPlayerNetworkStats(playerid, output[], size = sizeof (output));

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
 * <summary>This callback is called when a SendClientCheck request comletes</summary>
 * <param name="playerid">The ID of the player checked</param>
 * <param name="actionid">The type of check performed</param>
 * <param name="memaddr">The address requested</param>
 * <param name="retndata">The result of the check</param>
 * <seealso name="SendClientCheck" />
 */
forward OnClientCheckResponse(playerid, actionid, memaddr, retndata);

/**
 * <summary>This callback is called when someone attempts to log in to RCON in-game; successful or not.</summary>
 * <param name="ip">The IP of the player that tried to log in to RCON</param>
 * <param name="password">The password used to login with</param>
 * <param name="success"><b><c>0</c></b> if the password was incorrect or <b><c>1</c></b> if it was
 * correct</param>
 * <seealso name="OnRconCommand" />
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="SendRconCommand" />
 * <remarks>This callback is only called when /rcon login is used in-game. </remarks>
 * <remarks>This callback is only called when the player is not yet logged in.  When the player is logged
 * in, <a href="#OnRconCommand">OnRconCommand</a> is called instead.</remarks>
 * <returns>
 *   This callback does not handle returns.<br />
 *   It is always called first in filterscripts.
 * </returns>
 */
forward OnRconLoginAttempt(ip[], password[], success);

/**
 * <summary>This callback is called when a player finishes downloading custom models.  For more information
 * on how to add custom models to your server, see <a href="https://sampforum.blast.hk/showthread.php?tid=644105">the
 * release thread</a> and <a href="https://sampforum.blast.hk/showthread.php?tid=644123">this tutorial</a>.</summary>
 * <param name="playerid">The ID of the player that finished downloading custom models</param>
 * <param name="virtualworld">The ID of the virtual world the player finished downloading custom models
 * for</param>
 * <seealso name="OnPlayerConnect" />
 * <seealso name="OnPlayerDisconnect" />
 * <seealso name="OnIncomingConnection" />
 * <remarks>This callback is called every time a player changes virtual worlds, even if there are no
 * custom models present in that world.</remarks>
 * <returns>This callback does not handle returns.</returns>
 */
forward OnPlayerFinishedDownloading(playerid, virtualworld);

/**
 */
#if !defined DOWNLOAD_REQUEST
	#define DOWNLOAD_REQUEST: _:
#endif
forward OnPlayerRequestDownload(playerid, DOWNLOAD_REQUEST:type, crc);

/**
 * <summary>This callback is called when a command is sent through the server console, remote RCON,
 * or via the in-game "/rcon command".</summary>
 * <param name="cmd">A string containing the command that was typed, as well as any passed parameters</param>
 * <seealso name="IsPlayerAdmin" />
 * <seealso name="OnRconLoginAttempt" />
 * <remarks>You will need to include this callback in a loaded filterscript for it to work in the gamemode!</remarks>
 * <remarks>"/rcon" is not included in "cmd" when a player types a command. </remarks>
 * <remarks>If you use the <a href="#print">print</a> function here, it will send a message to the player
 * who typed the command in-game as well as the log.</remarks>
 * <remarks>This callback is not called when the player is not logged in as RCON admin. </remarks>
 * <remarks>When the player is not logged in as RCON admin and uses <b>/rcon login</b>, this callback
 * will not be called and <a href="#OnRconLoginAttempt">OnRconLoginAttempt</a> is called instead.  However,
 * when the player is logged in as RCON admin, the use of this command will call this callback. </remarks>
 * <returns>
 *   <b><c>0</c></b> if the command was not processed, it will be passed to another script or <b><c>1</c></b>
 * if the command was processed, will not be passed to other scripts.<br />
 *   It is always called first in filterscripts so returning <b><c>1</c></b> there blocks gamemode from
 * seeing it.
 * </returns>
 */
forward OnRconCommand(cmd[]);
