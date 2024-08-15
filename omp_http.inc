#if defined _INC_omp_http
	#endinput
#endif
#define _INC_omp_http

/**
 * <library name="omp_http" summary="open.mp legacy HTTP include.">
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

/// <p />
/**
 * <library>omp_http</library>
 * <summary>HTTP request types</summary>
 */
#define HTTP_METHOD: __TAG(HTTP_METHOD):
enum HTTP_METHOD:__HTTP_METHOD
{
	UNKNOWN_HTTP_METHOD                        = -1,
	HTTP_GET                                   = 1,
	HTTP_POST,
	HTTP_HEAD
}
static stock HTTP_METHOD:_@HTTP_METHOD() { return __HTTP_METHOD; }

#define UNKNOWN_HTTP_METHOD                    (HTTP_METHOD:-1)
#define HTTP_GET                               (HTTP_METHOD:1)
#define HTTP_POST                              (HTTP_METHOD:2)
#define HTTP_HEAD                              (HTTP_METHOD:3)

/// <p/>
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
	UNKNOWN_HTTP_ERROR                         = -1,
	HTTP_ERROR_BAD_HOST                        = 1,
	HTTP_ERROR_NO_SOCKET,
	HTTP_ERROR_CANT_CONNECT,
	HTTP_ERROR_CANT_WRITE,
	HTTP_ERROR_CONTENT_TOO_BIG,
	HTTP_ERROR_MALFORMED_RESPONSE
}
static stock HTTP_ERROR:_@HTTP_ERROR() { return __HTTP_ERROR; }

#define UNKNOWN_HTTP_ERROR                     (HTTP_ERROR:-1)
#define HTTP_ERROR_BAD_HOST                    (HTTP_ERROR:1)
#define HTTP_ERROR_NO_SOCKET                   (HTTP_ERROR:2)
#define HTTP_ERROR_CANT_CONNECT                (HTTP_ERROR:3)
#define HTTP_ERROR_CANT_WRITE                  (HTTP_ERROR:4)
#define HTTP_ERROR_CONTENT_TOO_BIG             (HTTP_ERROR:5)
#define HTTP_ERROR_MALFORMED_RESPONSE          (HTTP_ERROR:6)

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
 * <library>omp_http</library>
 * <summary>Sends a threaded HTTP request.</summary>
 * <param name="index">ID used to differentiate requests that are sent to the same callback (useful
 * for playerids)</param>
 * <param name="method">The type of request you wish to send</param>
 * <param name="url">The URL you want to request. (Without 'http://')</param>
 * <param name="data">Any POST data you want to send with the request</param>
 * <param name="callback">Name of the callback function you want to use to handle responses to this
 * request</param>
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
native HTTP(index, HTTP_METHOD:method, const url[], const data[], const callback[]);
