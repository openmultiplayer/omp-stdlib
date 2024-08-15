#if defined _INC_omp_variable
	#endinput
#endif
#define _INC_omp_variable

/**
 * <library name="omp_variable" summary="open.mp global data functions.">
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
 * <library>omp_variable</library>
 * <summary>PVar enumeration</summary>
 */
#define VARTYPE: __TAG(VARTYPE):
#define SERVER_VARTYPE: __TAG(VARTYPE):
#define PLAYER_VARTYPE: __TAG(VARTYPE):
enum VARTYPE:__VARTYPE
{
	UNKNOWN_VARTYPE                            = -1,

	VARTYPE_NONE,
	VARTYPE_INT,
	VARTYPE_STRING,
	VARTYPE_FLOAT,

	SERVER_VARTYPE_NONE                        = VARTYPE_NONE,
	SERVER_VARTYPE_INT,
	SERVER_VARTYPE_STRING,
	SERVER_VARTYPE_FLOAT,

	PLAYER_VARTYPE_NONE                        = VARTYPE_NONE,
	PLAYER_VARTYPE_INT,
	PLAYER_VARTYPE_STRING,
	PLAYER_VARTYPE_FLOAT
}
static stock VARTYPE:_@VARTYPE() { return __VARTYPE; }

#define UNKNOWN_VARTYPE                        (VARTYPE:-1)

#define VARTYPE_NONE                           (VARTYPE:0)
#define VARTYPE_INT                            (VARTYPE:1)
#define VARTYPE_STRING                         (VARTYPE:2)
#define VARTYPE_FLOAT                          (VARTYPE:3)

#define SERVER_VARTYPE_NONE                    (VARTYPE:0)
#define SERVER_VARTYPE_INT                     (VARTYPE:1)
#define SERVER_VARTYPE_STRING                  (VARTYPE:2)
#define SERVER_VARTYPE_FLOAT                   (VARTYPE:3)

#define PLAYER_VARTYPE_NONE                    (VARTYPE:0)
#define PLAYER_VARTYPE_INT                     (VARTYPE:1)
#define PLAYER_VARTYPE_STRING                  (VARTYPE:2)
#define PLAYER_VARTYPE_FLOAT                   (VARTYPE:3)

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

/*
native # Server Variables();
native        Server Variables(
native      ====================(
native
*/

/**
 * <library>omp_variable</library>
 * <summary>Set an integer server variable.</summary>
 * <param name="svar">The name of the server variable</param>
 * <param name="value">The integer to be set</param>
 * <seealso name="GetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="GetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The variable name is null or over 40 characters.
 * </returns>
 */
native bool:SetSVarInt(const svar[], value);

/**
 * <library>omp_variable</library>
 * <summary>Gets an integer server variable's value.</summary>
 * <param name="svar">The name of the server variable (case-insensitive).  Assigned in SetSVarInt</param>
 * <seealso name="SetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="GetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <returns>The integer value of the specified server variable.  It will still return <b><c>0</c></b>
 * if the variable is not set.</returns>
 */
native GetSVarInt(const svar[]);

/**
 * <library>omp_variable</library>
 * <summary>Set a string server variable.</summary>
 * <param name="svar">The name of the server variable</param>
 * <param name="value">The string to be set.  May be optionally formatted.</param>
 * <seealso name="SetSVarInt" />
 * <seealso name="GetSVarInt" />
 * <seealso name="GetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The variable name is null or over 40 characters.
 * </returns>
 */
native bool:SetSVarString(const svar[], const value[], OPEN_MP_TAGS:...);

/**
 * <library>omp_variable</library>
 * <summary>Gets a string server variable's value.</summary>
 * <param name="svar">The name of the server variable (case-insensitive).  Assigned in <a href="#SetSVarString">SetSVarString</a></param>
 * <param name="output">The array in which to store the string value in, passed by reference</param>
 * <param name="len">The maximum length of the returned string</param>
 * <seealso name="SetSVarInt" />
 * <seealso name="GetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <returns>The length of the string.</returns>
 */
native GetSVarString(const svar[], output[], len = sizeof (output));

/**
 * <library>omp_variable</library>
 * <summary>Set a float server variable.</summary>
 * <param name="svar">The name of the server variable</param>
 * <param name="value">The float to be set</param>
 * <seealso name="SetSVarInt" />
 * <seealso name="GetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="GetSVarString" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  The variable name is null or over 40 characters.
 * </returns>
 */
native bool:SetSVarFloat(const svar[], Float:value);

/**
 * <library>omp_variable</library>
 * <summary>Gets a float server variable's value.</summary>
 * <param name="svar">The name of the server variable (case-insensitive).  Assigned in <a href="#SetSVarFloat">SetSVarFloat</a></param>
 * <seealso name="SetSVarInt" />
 * <seealso name="GetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="GetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <returns>The float value of the specified server variable.  It will still return <b><c>0</c></b>
 * if the variable is not set.</returns>
 */
native Float:GetSVarFloat(const svar[]);

/**
 * <library>omp_variable</library>
 * <summary>Deletes a previously set server variable.</summary>
 * <param name="svar">The name of the server variable to delete</param>
 * <seealso name="SetSVarInt" />
 * <seealso name="GetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="GetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="GetSVarFloat" />
 * <remarks>Once a variable is deleted, attempts to retrieve the value will return <b><c>0</c></b> (for
 * integers and floats and <b><c>NULL</c></b> for strings.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  There is no variable set with the given name.
 * </returns>
 */
native bool:DeleteSVar(const svar[]);

/**
 * <library>omp_variable</library>
 * <summary>Each SVar (server-variable) has its own unique identification number for lookup, this function
 * returns the highest ID.</summary>
 * <seealso name="GetSVarNameAtIndex" />
 * <seealso name="GetSVarType" />
 * <returns>The highest set SVar ID.</returns>
 */
native GetSVarsUpperIndex();

/**
 * <library>omp_variable</library>
 * <summary>Retrieve the name of a sVar via the index.</summary>
 * <param name="index">The index of the sVar</param>
 * <param name="output">A string to store the sVar's name in, passed by reference</param>
 * <param name="size">The max length of the returned string</param>
 * <seealso name="GetSVarType" />
 * <seealso name="GetSVarInt" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="GetSVarString" />
 */
native bool:GetSVarNameAtIndex(index, output[], size = sizeof (output));

/**
 * <library>omp_variable</library>
 * <summary>Gets the type (integer, float or string) of a server variable.</summary>
 * <param name="svar">The name of the server variable to get the type of</param>
 * <seealso name="SetSVarInt" />
 * <seealso name="GetSVarInt" />
 * <seealso name="SetSVarString" />
 * <seealso name="GetSVarString" />
 * <seealso name="SetSVarFloat" />
 * <seealso name="GetSVarFloat" />
 * <seealso name="DeleteSVar" />
 * <remarks>
 *   <b>Variable types:</b><br />
 *   <ul>
 *     <li><b><c>VARTYPE_NONE</c></b> (sVar with name given does not exist)</li>
 *     <li><b><c>VARTYPE_INT</c></b></li>
 *     <li><b><c>VARTYPE_STRING</c></b></li>
 *     <li><b><c>VARTYPE_FLOAT</c></b></li>
 *   </ul>
 * </remarks>
 * <returns>Returns the type of the SVar.  See table below.</returns>
 */
native VARTYPE:GetSVarType(const svar[]);

/*
native # Player Variables();
native        Player Variables(
native      ====================(
native
*/

/**
 * <library>omp_variable</library>
 * <summary>Set an integer player variable.</summary>
 * <param name="playerid">The ID of the player whose player variable will be set</param>
 * <param name="pvar">The name of the player variable</param>
 * <param name="value">The integer to be set</param>
 * <seealso name="GetPVarInt" />
 * <seealso name="SetPVarString" />
 * <seealso name="GetPVarString" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="DeletePVar" />
 * <remarks>Variables aren't reset until after <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>
 * is called, so the values are still accessible in <a href="#OnPlayerDisconnect">OnPlayerDisconnect</a>.</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Either the player specified is not connected,
 * or the variable name is null or over 40 characters.
 * </returns>
 */
native bool:SetPVarInt(playerid, const pvar[], value);

/**
 * <library>omp_variable</library>
 * <summary>Gets an integer player variable's value.</summary>
 * <param name="playerid">The ID of the player whose player variable to get</param>
 * <param name="pvar">The name of the player variable (case-insensitive).  Assigned in SetPVarInt</param>
 * <seealso name="SetPVarInt" />
 * <seealso name="SetPVarString" />
 * <seealso name="GetPVarString" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="DeletePVar" />
 * <returns>The integer value of the specified player variable.  It will still return <b><c>0</c></b>
 * if the variable is not set, or the player does not exist.</returns>
 */
native GetPVarInt(playerid, const pvar[]);

/**
 * <library>omp_variable</library>
 * <summary>Saves a string into a player variable.</summary>
 * <param name="playerid">The ID of the player whose player variable will be set</param>
 * <param name="pvar">The name of the player variable</param>
 * <param name="value">The string you want to save in the player variable.  May be optionally formatted.</param>
 * <seealso name="SetPVarInt" />
 * <seealso name="GetPVarInt" />
 * <seealso name="GetPVarString" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="DeletePVar" />
 */
native bool:SetPVarString(playerid, const pvar[], const value[], OPEN_MP_TAGS:...);

/**
 * <library>omp_variable</library>
 * <summary>Gets a player variable as a string.</summary>
 * <param name="playerid">The ID of the player whose player variable to get</param>
 * <param name="pvar">The name of the player variable, set by <a href="#SetPVarString">SetPVarString</a></param>
 * <param name="output">The array in which to store the string value in, passed by reference</param>
 * <param name="len">The maximum length of the returned string</param>
 * <seealso name="SetPVarString" />
 * <seealso name="SetPVarInt" />
 * <seealso name="GetPVarInt" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="DeletePVar" />
 * <remarks>If length of string is zero (value not set), output text will not be updated or set to anything
 * and will remain with old data, neccesying that you clear the variable to blank value if <a href="#GetPVarString">GetPVarString</a>
 * returns <b><c>0</c></b> if that behavior is undesired </remarks>
 * <returns>The length of the string.</returns>
 */
native GetPVarString(playerid, const pvar[], output[], len = sizeof (output));

/**
 * <library>omp_variable</library>
 * <summary>Set a float player variable's value.</summary>
 * <param name="playerid">The ID of the player whose player variable will be set</param>
 * <param name="pvar">The name of the player variable</param>
 * <param name="value">The float you want to save in the player variable</param>
 * <seealso name="SetPVarInt" />
 * <seealso name="GetPVarInt" />
 * <seealso name="SetPVarString" />
 * <seealso name="GetPVarString" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="DeletePVar" />
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Either the player specified is not connected,
 * or the variable name is null or over 40 characters.
 * </returns>
 */
native bool:SetPVarFloat(playerid, const pvar[], Float:value);

/**
 * <library>omp_variable</library>
 * <summary>Gets a player variable as a float.</summary>
 * <param name="playerid">The ID of the player whose player variable you want to get</param>
 * <param name="pvar">The name of the player variable</param>
 * <seealso name="SetPVarInt" />
 * <seealso name="GetPVarInt" />
 * <seealso name="SetPVarString" />
 * <seealso name="GetPVarString" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="DeletePVar" />
 * <returns>The float from the specified player variable.</returns>
 */
native Float:GetPVarFloat(playerid, const pvar[]);

/**
 * <library>omp_variable</library>
 * <summary>Deletes a previously set player variable.</summary>
 * <param name="playerid">The ID of the player whose player variable to delete</param>
 * <param name="pvar">The name of the player variable to delete</param>
 * <seealso name="SetPVarInt" />
 * <seealso name="GetPVarInt" />
 * <seealso name="SetPVarString" />
 * <seealso name="GetPVarString" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="GetPVarFloat" />
 * <remarks>Once a variable is deleted, attempts to retrieve the value will return <b><c>0</c></b> (for
 * integers and floats and <b><c>NULL</c></b> for strings).</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  Either the player specified isn't connected or
 * there is no variable set with the given name.
 * </returns>
 */
native bool:DeletePVar(playerid, const pvar[]);

/**
 * <library>omp_variable</library>
 * <summary>Each PVar (player-variable) has its own unique identification number for lookup, this function
 * returns the highest ID set for a player.</summary>
 * <param name="playerid">The ID of the player to get the upper PVar index of</param>
 * <seealso name="GetPVarNameAtIndex" />
 * <seealso name="GetPVarType" />
 * <returns>The highest set PVar ID.</returns>
 */
native GetPVarsUpperIndex(playerid);

/**
 * <library>omp_variable</library>
 * <summary>Retrieve the name of a player's pVar via the index.</summary>
 * <param name="playerid">The ID of the player whose player variable to get the name of</param>
 * <param name="index">The index of the player's pVar</param>
 * <param name="output">A string to store the pVar's name in, passed by reference</param>
 * <param name="size">The max length of the returned string</param>
 * <seealso name="GetPVarType" />
 * <seealso name="GetPVarInt" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="GetPVarString" />
 */
native bool:GetPVarNameAtIndex(playerid, index, output[], size = sizeof (output));

/**
 * <library>omp_variable</library>
 * <summary>Gets the type (integer, float or string) of a player variable.</summary>
 * <param name="playerid">The ID of the player whose player variable to get the type of</param>
 * <param name="pvar">The name of the player variable to get the type of</param>
 * <seealso name="SetPVarInt" />
 * <seealso name="GetPVarInt" />
 * <seealso name="SetPVarString" />
 * <seealso name="GetPVarString" />
 * <seealso name="SetPVarFloat" />
 * <seealso name="GetPVarFloat" />
 * <seealso name="DeletePVar" />
 * <remarks>
 *   <b>Variable types:</b><br />
 *   <ul>
 *     <li><b><c>VARTYPE_NONE</c></b> (pVar with name given does not exist)</li>
 *     <li><b><c>VARTYPE_INT</c></b></li>
 *     <li><b><c>VARTYPE_STRING</c></b></li>
 *     <li><b><c>VARTYPE_FLOAT</c></b></li>
 *   </ul>
 * </remarks>
 * <returns>Returns the type of the PVar.  See table below.</returns>
 */
native VARTYPE:GetPVarType(playerid, const pvar[]);
