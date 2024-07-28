#if defined _args_included
	#endinput
#endif
#define _args_included

/**
 * <library name="args" summary="Script arguments support functions.">
 *   <license>
 *     (c) Copyright 2005, ITB CompuPhase
 *     This file is provided as is (no warranties).
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

#pragma library Args

/**
 * <library>args</library>
 * <summary>Get the number of arguments passed to the script (those after <c>--</c>).</summary>
 * <seealso name="argindex"/>
 * <seealso name="argstr"/>
 * <seealso name="argvalue"/>
 * <return>The number of arguments passed directly to the script.</return>
 */
native argcount();

/**
 * <library>args</library>
 * <summary>Get the name of the argument at the given index after <c>--</c>.</summary>
 * <param name="index">The naught-based offset to the script argument.</param>
 * <param name="value">The output string destination.</param>
 * <param name="size">The size of the destination.</param>
 * <param name="pack">Should the return value be packed?</param>
 * <seealso name="argcount"/>
 * <seealso name="argstr"/>
 * <seealso name="argvalue"/>
 * <remarks>Separate parameters also count for the index here.  For example with
 * <c>--load test --run</c> the argument <c>--run</c> is index <c>2</c>.</remarks>
 * <return><c>true</c> - the argument was found, <c>false</c> - it wasn't.</return>
 */
native bool:argindex(index, value[], size = sizeof (value), bool:pack = false);

/**
 * <library>args</library>
 * <summary>Get the string value of an argument by name.</summary>
 * <param name="skip">The number of arguments (with potentially the same name) to skip.</param>
 * <param name="argument">The name of the argument, including <c>-</c>s and <c>/</c>s.</param>
 * <param name="value">The output string destination.</param>
 * <param name="size">The size of the destination.</param>
 * <param name="pack">Should the return value be packed?</param>
 * <seealso name="argcount"/>
 * <seealso name="argindex"/>
 * <seealso name="argvalue"/>
 * <remarks>This only returns <c>true</c> if the argument name is found AND it is followed by a
 * value separated by <c>=</c>.  For example <c>--arg=7</c> or <c>-a=5</c>.  It does not handle
 * long-form arguments with separated parameters such as <c>--arg hello</c> nor short-form arguments
 * collected together, such as <c>-xvf</c>.  For those a higher-level library such as
 * <c>&lt;YSI_Server\y_args&gt;</c> is required.</remarks>
 * <remarks>Values may include spaces when enclosed in double quotes, for example:
 * <c>"--motd=Hello and welcome to my server!"</c>.</remarks>
 * <return><c>true</c> - the argument was found with value, <c>false</c> - it wasn't.</return>
 */
native bool:argstr(skip = 0, const argument[] = "", value[] = "", size = sizeof (value), bool:pack = false);

/**
 * <library>args</library>
 * <summary>Get the number of arguments passed to the script (those after <c>--</c>).</summary>
 * <param name="skip">The number of arguments (with potentially the same name) to skip.</param>
 * <param name="argument">The name of the argument, including <c>-</c>s and <c>/</c>s.</param>
 * <param name="value">The output destination.</param>
 * <param name="pack">Should the return value be packed?</param>
 * <seealso name="argcount"/>
 * <seealso name="argindex"/>
 * <seealso name="argstr"/>
 * <remarks>This only returns <c>true</c> if the argument name is found AND it is followed by a
 * value separated by <c>=</c>.  For example <c>--arg=7</c> or <c>-a=5</c>.  It does not handle
 * long-form arguments with separated parameters such as <c>--arg hello</c> nor short-form arguments
 * collected together, such as <c>-xvf</c>.  For those a higher-level library such as
 * <c>&lt;YSI_Server\y_args&gt;</c> is required.</remarks>
 * <return><c>true</c> - the argument was found with value, <c>false</c> - it wasn't.</return>
 */
native bool:argvalue(skip = 0, const argument[] = "", &value = cellmin);
