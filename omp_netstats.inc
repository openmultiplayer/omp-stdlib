#if defined _INC_omp_netstats
	#endinput
#endif
#define _INC_omp_netstats

/**
 * <library name="omp_netstats" summary="open.mp core functions and defines.">
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
 * <library>omp_netstats</library>
 * <summary>Gets the tick rate (like FPS) of the server.</summary>
 * <seealso name="GetNetworkStats" />
 * <returns>The server tick rate (per second).  Returns <b><c>0</c></b> when the server is just started.</returns>
 */
native GetServerTickRate();

/**
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
native NetStats_ConnectionStatus(playerid);

/**
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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
 * <library>omp_netstats</library>
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

