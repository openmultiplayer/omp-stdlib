#if defined _INC_omp_database
	#endinput
#endif
#define _INC_omp_database

/**
 * <library name="omp_database" summary="open.mp SQLite functions.">
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
 * <library>omp_database</library>
 */
enum SQLITE_OPEN:__SQLITE_OPEN
{
	UNKNOWN_SQLITE_OPEN                        = -1,
	SQLITE_OPEN_READONLY                       = 0x00000001,
	SQLITE_OPEN_READWRITE                      = 0x00000002,
	SQLITE_OPEN_CREATE                         = 0x00000004,
	SQLITE_OPEN_DELETEONCLOSE                  = 0x00000008, // Requires VFS.
	SQLITE_OPEN_EXCLUSIVE                      = 0x00000010, // Requires VFS.
	SQLITE_OPEN_AUTOPROXY                      = 0x00000020, // Requires VFS.
	SQLITE_OPEN_URI                            = 0x00000040,
	SQLITE_OPEN_MEMORY                         = 0x00000080,
	SQLITE_OPEN_MAIN_DB                        = 0x00000100, // Requires VFS.
	SQLITE_OPEN_TEMP_DB                        = 0x00000200, // Requires VFS.
	SQLITE_OPEN_TRANSIENT_DB                   = 0x00000400, // Requires VFS.
	SQLITE_OPEN_MAIN_JOURNAL                   = 0x00000800, // Requires VFS.
	SQLITE_OPEN_TEMP_JOURNAL                   = 0x00001000, // Requires VFS.
	SQLITE_OPEN_SUBJOURNAL                     = 0x00002000, // Requires VFS.
	SQLITE_OPEN_SUPER_JOURNAL                  = 0x00004000, // Requires VFS.
	SQLITE_OPEN_NOMUTEX                        = 0x00008000,
	SQLITE_OPEN_FULLMUTEX                      = 0x00010000,
	SQLITE_OPEN_SHAREDCACHE                    = 0x00020000,
	SQLITE_OPEN_PRIVATECACHE                   = 0x00040000,
	SQLITE_OPEN_WAL                            = 0x00080000, // Requires VFS.
	SQLITE_OPEN_NOFOLLOW                       = 0x01000000,
	SQLITE_OPEN_EXRESCODE                      = 0x02000000
}
static stock SQLITE_OPEN:_@SQLITE_OPEN() { return __SQLITE_OPEN; }

#define UNKNOWN_SQLITE_OPEN                    (SQLITE_OPEN:-1)
#define SQLITE_OPEN_READONLY                   (SQLITE_OPEN:0x00000001)
#define SQLITE_OPEN_READWRITE                  (SQLITE_OPEN:0x00000002)
#define SQLITE_OPEN_CREATE                     (SQLITE_OPEN:0x00000004)
#define SQLITE_OPEN_DELETEONCLOSE              (SQLITE_OPEN:0x00000008) // Requires VFS.
#define SQLITE_OPEN_EXCLUSIVE                  (SQLITE_OPEN:0x00000010) // Requires VFS.
#define SQLITE_OPEN_AUTOPROXY                  (SQLITE_OPEN:0x00000020) // Requires VFS.
#define SQLITE_OPEN_URI                        (SQLITE_OPEN:0x00000040)
#define SQLITE_OPEN_MEMORY                     (SQLITE_OPEN:0x00000080)
#define SQLITE_OPEN_MAIN_DB                    (SQLITE_OPEN:0x00000100) // Requires VFS.
#define SQLITE_OPEN_TEMP_DB                    (SQLITE_OPEN:0x00000200) // Requires VFS.
#define SQLITE_OPEN_TRANSIENT_DB               (SQLITE_OPEN:0x00000400) // Requires VFS.
#define SQLITE_OPEN_MAIN_JOURNAL               (SQLITE_OPEN:0x00000800) // Requires VFS.
#define SQLITE_OPEN_TEMP_JOURNAL               (SQLITE_OPEN:0x00001000) // Requires VFS.
#define SQLITE_OPEN_SUBJOURNAL                 (SQLITE_OPEN:0x00002000) // Requires VFS.
#define SQLITE_OPEN_SUPER_JOURNAL              (SQLITE_OPEN:0x00004000) // Requires VFS.
#define SQLITE_OPEN_NOMUTEX                    (SQLITE_OPEN:0x00008000)
#define SQLITE_OPEN_FULLMUTEX                  (SQLITE_OPEN:0x00010000)
#define SQLITE_OPEN_SHAREDCACHE                (SQLITE_OPEN:0x00020000)
#define SQLITE_OPEN_PRIVATECACHE               (SQLITE_OPEN:0x00040000)
#define SQLITE_OPEN_WAL                        (SQLITE_OPEN:0x00080000) // Requires VFS.
#define SQLITE_OPEN_NOFOLLOW                   (SQLITE_OPEN:0x01000000)
#define SQLITE_OPEN_EXRESCODE                  (SQLITE_OPEN:0x02000000)

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
 * <library>omp_database</library>
 * <summary>This function is used to open a connection to a SQLite database, which is inside the <b><c>/scriptfiles</c></b>
 * folder.</summary>
 * <param name="name">File name of the database</param>
 * <remarks>
 *   It will create a new SQLite database, if there is no SQLite database with the same file name available.<br
 * />
 *   <b>Close</b> your database connection with <a href="#db_close">db_close</a>!
 * </remarks>
 * <returns>Returns index (starting at <b><c>1</c></b>) of the database connection .</returns>
 */
native DB:DB_Open(const name[], SQLITE_OPEN:flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);

/**
 * <library>omp_database</library>
 * <summary>Closes an SQLite database that was opened with <a href="#db_open">db_open</a>.</summary>
 * <param name="db">The handle of the database connection to close (returned by <a href="#db_open">db_open</a>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>
 *   <b><c>1</c></b>: The function executed successfully.<br />
 *   <b><c>0</c></b>: The function failed to execute.  May mean that the database handle specified is
 * not open.
 * </returns>
 */
native bool:DB_Close(DB:db);

/**
 * <library>omp_database</library>
 * <summary>This function is used to execute an SQL query on an opened SQLite database.</summary>
 * <param name="db">The database handle to query</param>
 * <param name="query">The query to execute.  May be optionally formatted.</param>
 * <remarks><b>Always</b> free the result by using <a href="#db_free_result">db_free_result</a>!</remarks>
 * <returns>The query result index (<b>starting at 1</b>).</returns>
 */
native DBResult:DB_ExecuteQuery(DB:db, const query[], OPEN_MP_TAGS:...);

/**
 * <library>omp_database</library>
 * <summary>Frees result memory allocated from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result to free</param>
 * <returns>If <b><c>DBResult:dbhandle</c></b> is a valid handle, it returns <b><c>1</c></b>, otherwise
 * <b><c>0</c></b> if <b><c>DBResult:dbhandle</c></b> is a <b><c>NULL</c></b> reference.</returns>
 */
native bool:DB_FreeResultSet(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Returns the number of rows from a <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result of <a href="#db_query">db_query</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>The number of rows in the result.</returns>
 */
native DB_GetRowCount(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Moves to the next row of the result allocated from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result of <a href="#db_query">db_query</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b> on success, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the last row is reached.</returns>
 */
native bool:DB_SelectNextRow(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Get the number of fields in a result.</summary>
 * <param name="result">The result of <a href="#db_query">db_query</a></param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>The number of fields in the result.</returns>
 */
native DB_GetFieldCount(DBResult:result);

/**
 * <library>omp_database</library>
 * <summary>Returns the name of a field at a particular index.</summary>
 * <param name="result">The result to get the data from; returned by <a href="#db_query">db_query</a></param>
 * <param name="field">The index of the field to get the name of</param>
 * <param name="output">The returned value</param>
 * <param name="size">The max length of the field</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b>, if the function was successful, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the column index not available.</returns>
 */
native bool:DB_GetFieldName(DBResult:result, field, output[], size = sizeof (output));

/**
 * <library>omp_database</library>
 * <summary>Get the content of a field from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The field to get the data from</param>
 * <param name="output">The returned value</param>
 * <param name="size">The max length of the field</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b> if successful, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the column index not available.</returns>
 */
native bool:DB_GetFieldString(DBResult:result, field, output[], size = sizeof (output));

/**
 * <library>omp_database</library>
 * <summary>Get the content of a field as an integer from <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The field to get the data from (optional=<b><c>0</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as integer (number).</returns>
 */
native DB_GetFieldInt(DBResult:result, field = 0);

/**
 * <library>omp_database</library>
 * <summary>Get the content of a field as a float from db_query.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The field to get the data from (optional=<b><c>0</c></b>)</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as floating point number.</returns>
 */
native Float:DB_GetFieldFloat(DBResult:result, field = 0);

/**
 * <library>omp_database</library>
 * <summary>Get the contents of field with specified name.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The fieldname to get the data from</param>
 * <param name="output">The returned value</param>
 * <param name="size">The max length of the field</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Returns <b><c>1</c></b> if successful, otherwise <b><c>0</c></b> if <b><c>DBResult:result</c></b>
 * is a <b><c>NULL</c></b> reference or the column index not available.</returns>
 */
native bool:DB_GetFieldStringByName(DBResult:result, const field[], output[], size = sizeof (output));

/**
 * <library>omp_database</library>
 * <summary>Get the contents of field as an integer with specified name.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The fieldname to get the data from</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as integer (number).</returns>
 */
native DB_GetFieldIntByName(DBResult:result, const field[]);

/**
 * <library>omp_database</library>
 * <summary>Get the contents of field as a float with specified name.</summary>
 * <param name="result">The result to get the data from</param>
 * <param name="field">The fieldname to get the data from</param>
 * <remarks>Using an <b>invalid handle</b> will crash your server! Get a <b>valid handle</b> by using
 * <a href="#db_open">db_open</a>.  But it's protected against <b><c>NULL</c></b> references</remarks>
 * <returns>Retrieved value as floating point number.</returns>
 */
native Float:DB_GetFieldFloatByName(DBResult:result, const field[]);

/**
 * <library>omp_database</library>
 * <summary>Get memory handle for an SQLite database that was opened with <a href="#db_open">db_open</a>.</summary>
 * <param name="db">The index of the database connection (returned by <a href="#db_open">db_open</a>)</param>
 * <returns>Returns the memory handle for a specified database.</returns>
 */
native DB_GetMemHandle(DB:db);

/**
 * <library>omp_database</library>
 * <summary>Get <b>memory handle</b> for an SQLite query that was executed with <a href="#db_query">db_query</a>.</summary>
 * <param name="result">The index of the query (returned by <a href="#db_query">db_query</a>)</param>
 * <returns>Returns the memory handle for a specified query.</returns>
 */
native DB_GetLegacyDBResult(DBResult:result);

/**
 * <library>omp_database</library>
 */
native DB_GetDatabaseConnectionCount();

/**
 * <library>omp_database</library>
 */
native DB_GetDatabaseResultSetCount();

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_Open`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native DB:db_open(const name[]) = DB_Open;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_Close`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:db_close(DB:db) = DB_Close;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_ExecuteQuery`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native DBResult:db_query(DB:db, const query[]) = DB_ExecuteQuery;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_FreeResultSet`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:db_free_result(DBResult:result) = DB_FreeResultSet;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetRowCount`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_num_rows(DBResult:result) = DB_GetRowCount;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_SelectNextRow`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:db_next_row(DBResult:result) = DB_SelectNextRow;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldCount`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_num_fields(DBResult:result) = DB_GetFieldCount;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldName`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:db_field_name(DBResult:result, field, output[], size = sizeof (output)) = DB_GetFieldName;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldString`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:db_get_field(DBResult:result, field, output[], size = sizeof (output)) = DB_GetFieldString;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldInt`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_get_field_int(DBResult:result, field = 0) = DB_GetFieldInt;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldFloat`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native Float:db_get_field_float(DBResult:result, field = 0) = DB_GetFieldFloat;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldStringByName`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native bool:db_get_field_assoc(DBResult:result, const field[], output[], size = sizeof (output)) = DB_GetFieldStringByName;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldIntByName`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_get_field_assoc_int(DBResult:result, const field[]) = DB_GetFieldIntByName;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetFieldFloatByName`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native Float:db_get_field_assoc_float(DBResult:result, const field[]) = DB_GetFieldFloatByName;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetMemHandle`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_get_mem_handle(DB:db) = DB_GetMemHandle;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetLegacyDBResult`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_get_result_mem_handle(DBResult:result) = DB_GetLegacyDBResult;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetDatabaseConnectionCount`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_debug_openfiles() = DB_GetDatabaseConnectionCount;

/**
 * <library>omp_database</library>
 */
#if !defined LEGACY_SCRIPTING_API
	#pragma deprecated Use `DB_GetDatabaseResultSetCount`. To silence this warning define `LEGACY_SCRIPTING_API` or define `SAMP_COMPAT` for general SA-MP API compatibility.
#endif
native db_debug_openresults() = DB_GetDatabaseResultSetCount;
