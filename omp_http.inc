#if defined _INC_omp_http
	#endinput
#endif
#define _INC_omp_http

/**
 * <library name="omp_http" summary="open.mp legacy HTTP include.">
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

#pragma tabsize 4
#define SAMP_CONST_CORRECT

/// <p />

///

/**
 * <library>omp_http</library>
 * <summary>HTTP request types</summary>
 */
#define HTTP_METHOD: __TAG(HTTP_METHOD):
enum HTTP_METHOD:__HTTP_METHOD
{
	HTTP_GET                                   = 1,
	HTTP_POST,
	HTTP_HEAD
}
static stock HTTP_METHOD:_@HTTP_METHOD() { return __HTTP_METHOD; }

///

/**
 * <library>omp_http</library>
 * <summary>HTTP error response codes</summary>
 * <remarks>
 *   These codes compliment ordinary HTTP response codes returned in 'responseCode'
 *   (10x) (20x OK) (30x Moved) (40x Unauthorised) (50x Server Error)
 * </remarks>
 */
#define HTTP_ERROR: __TAG(HTTP_ERROR):
enum HTTP_ERROR:__HTTP_ERROR
{
	HTTP_ERROR_BAD_HOST                        = 1,
	HTTP_ERROR_NO_SOCKET,
	HTTP_ERROR_CANT_CONNECT,
	HTTP_ERROR_CANT_WRITE,
	HTTP_ERROR_CONTENT_TOO_BIG,
	HTTP_ERROR_MALFORMED_RESPONSE
}
static stock HTTP_ERROR:_@HTTP_ERROR() { return __HTTP_ERROR; }

/**
 * <library>a_http</library>
 * <summary>Sends a threaded HTTP request.</summary>
 * <param name="index">ID used to differentiate requests that are sent to the same callback (useful
 * for playerids)</param>
 * <param name="method">The type of request you wish to send</param>
 * <param name="url">The URL you want to request. (Without 'http://')</param>
 * <param name="data">Any POST data you want to send with the request</param>
 * <param name="callback">Name of the callback function you want to use to handle responses to this
 * request</param>
 * <remarks>This function was added in <b>SA-MP 0.3b</b> and will not work in earlier versions!</remarks>
 * <returns><b><c>1</c></b> on success, <b><c>0</c></b> on failure.</returns>
 * <remarks>
 *   <b>Request types:</b><br />
 *   <ul>
 *     <li><b><c>HTTP_GET</c></b></li>
 *     <li><b><c>HTTP_POST</c></b></li>
 *     <li><b><c>HTTP_HEAD</c></b></li>
 *   </ul>
 * </remarks>
 * <remarks>
 *   <b>Response codes:</b><br />
 *   <ul>
 *     <li><b><c>HTTP_ERROR_BAD_HOST</c></b></li>
 *     <li><b><c>HTTP_ERROR_NO_SOCKET</c></b></li>
 *     <li><b><c>HTTP_ERROR_CANT_CONNECT</c></b></li>
 *     <li><b><c>HTTP_ERROR_CANT_WRITE</c></b></li>
 *     <li><b><c>HTTP_ERROR_CONTENT_TOO_BIG</c></b></li>
 *     <li><b><c>HTTP_ERROR_MALFORMED_RESPONSE</c></b></li>
 *     <li>+ standard HTTP response codes</li>
 *   </ul>
 * </remarks>
 * <example>
 * 	 <code>
 *      // HTTP callback. <br />
 *      public MyHttpResponse(index, responseCode, const data[]) { ... }
 * 	 </code>
 * </example>
 */
#pragma deprecated Use literally anything else, like the requests plugin/component.
native HTTP(index, HTTP_METHOD:method, const url[], const data[], const callback[]);

