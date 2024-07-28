#if defined _Float_included
	#endinput
#endif
#define _Float_included

/**
 * <library name="time" summary="Float arithmetic.">
 *   <license>
 *     (c) Copyright 1999, Artran, Inc.
 *     Written by Greg Garner (gmg@artran.com)
 *     Modified in March 2001 to include user defined
 *     operators for the floating point functions.
 *
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

#pragma library Float
#pragma rational Float

/// <p/>
/**
 * <library>float</library>
 * <summary>Different methods of rounding.</summary>
 */
enum floatround_method
{
	floatround_round,
	floatround_floor,
	floatround_ceil,
	floatround_tozero,
	floatround_unbiased
}
static stock floatround_method:_@floatround_method() { return floatround_method; }

/// <p/>
/**
 * <library>float</library>
 */
enum anglemode
{
	radian,
	degrees,
	grades
}
static stock anglemode:_@anglemode() { return anglemode; }

/**
 * <library>float</library>
 * <summary>Converts an integer into a float.</summary>
 * <param name="value">Integer value to convert to a float</param>
 * <seealso name="floatround"/>
 * <seealso name="floatstr"/>
 * <returns>The given integer as a float.</returns>
 */
native Float:float(value);

/**
 * <library>float</library>
 * <summary>Converts a string to a float.</summary>
 * <param name="string">The string to convert into a float</param>
 * <seealso name="floatround"/>
 * <seealso name="float"/>
 * <seealso name="strfloat"/>
 * <returns>The requested float value.</returns>
 */
native Float:floatstr(const string[]);

/**
 * <library>float</library>
 * <summary>Convert from text (string) to floating point.</summary>
 * <param name="string">A string containing a floating point number in characters.  This may be
 * either a packed or unpacked string.  The string may specify a fractional part, for example
 * <c>"123.45"</c>.</param>
 * <seealso name="float"/>
 * <seealso name="floatstr"/>
 * <returns>The value in the string, or zero if the string did not start with a valid number.</returns>
 */
native Float:strfloat(const string[]) = floatstr;

/**
 * <library>float</library>
 * <summary>Multiplies two floats with each other.</summary>
 * <param name="oper1">First Float</param>
 * <param name="oper2">Second Float, the first one gets multiplied with</param>
 * <seealso name="floatadd"/>
 * <seealso name="floatsub"/>
 * <seealso name="floatdiv"/>
 * <returns>The product of the two given floats.</returns>
 */
native Float:floatmul(Float:oper1, Float:oper2);

/**
 * <library>float</library>
 * <summary>Divide one float by another one.  Redundant as the division operator (/) does the same thing.</summary>
 * <param name="dividend">First float</param>
 * <param name="divisor">Second float (dividates the first float.)</param>
 * <seealso name="floatadd"/>
 * <seealso name="floatsub"/>
 * <seealso name="floatmul"/>
 * <returns>The quotient of the two given floats.</returns>
 */
native Float:floatdiv(Float:dividend, Float:divisor);

/**
 * <library>float</library>
 * <summary>Adds two floats together.  This function is redundant as the standard operator (+) does
 * the same thing.</summary>
 * <param name="oper1">First float</param>
 * <param name="oper2">Second float</param>
 * <seealso name="floatsub"/>
 * <seealso name="floatmul"/>
 * <seealso name="floatdiv"/>
 * <returns>The sum of the two given floats.</returns>
 */
native Float:floatadd(Float:oper1, Float:oper2);

/**
 * <library>float</library>
 * <summary>Subtracts one float from another one.  Note that this function has no real use, as one can
 * simply use the standard operator (-) instead.</summary>
 * <param name="oper1">First Float</param>
 * <param name="oper2">Second Float (gets subtracted from the first float.)</param>
 * <seealso name="floatadd"/>
 * <seealso name="floatmul"/>
 * <seealso name="floatdiv"/>
 * <returns>The difference of the two given floats.</returns>
 */
native Float:floatsub(Float:oper1, Float:oper2);

/**
 * <library>float</library>
 * <summary>Get the fractional part of a float.  This means the value of the numbers after the decimal
 * point.</summary>
 * <param name="value">The float to get the fractional part of</param>
 * <seealso name="floatround"/>
 * <returns>The fractional part of the float, as a float value.</returns>
 */
native Float:floatfract(Float:value);

/**
 * <library>float</library>
 * <summary>Round a floating point number to an integer value.</summary>
 * <param name="value">The value to round</param>
 * <param name="method">The floatround method to use (optional=<b><c>floatround_round</c></b>)</param>
 * <seealso name="float"/>
 * <seealso name="floatstr"/>
 * <remarks>
 *   <b>Rounding methods:</b><p/>
 *   <ul>
 *     <li><b><c>floatround_round</c></b> - round to the nearest integer.  A fractional part of exactly
 * 0.5 rounds upwards (this is the default).</li>
 *     <li><b><c>floatround_floor</c></b> - round downwards.</li>
 *     <li><b><c>floatround_ceil</c></b> - round upwards.</li>
 *     <li><b><c>floatround_tozero</c></b> - round downwards for positive values and upwards for negative
 * values ("truncate").</li>
 *   </ul>
 * </remarks>
 * <returns>The rounded value as an integer.</returns>
 */
native floatround(Float:value, floatround_method:method = floatround_round);

/**
 * <library>float</library>
 * <summary>floatcmp can be used to compare float values to each other, to validate the comparison.</summary>
 * <param name="oper1">The first float value to compare</param>
 * <param name="oper2">The second float value to compare</param>
 * <returns><b><c>0</c></b> if value does match, <b><c>1</c></b> if the first value is bigger and <b><c>-1</c></b>
 * if the 2nd value is bigger.</returns>
 */
native floatcmp(Float:oper1, Float:oper2);

/**
 * <library>float</library>
 * <summary>Calculates the square root of given value.</summary>
 * <param name="value">The value to calculate the square root of</param>
 * <seealso name="floatpower"/>
 * <seealso name="floatlog"/>
 * <remarks>This function raises a "domain" error if the input value is negative.  You may use <a href="#floatabs">floatabs</a>
 * to get the absolute (positive) value.</remarks>
 * <returns>The square root of the input value, as a float.</returns>
 */
native Float:floatsqroot(Float:value);

/**
 * <library>float</library>
 * <summary>Raises the given value to the power of the exponent.</summary>
 * <param name="value">The value to raise to a power, as a floating-point number</param>
 * <param name="exponent">The exponent is also a floating-point number.  It may be zero or negative</param>
 * <seealso name="floatsqroot"/>
 * <seealso name="floatlog"/>
 * <returns>The result of 'value' to the power of 'exponent'.</returns>
 */
native Float:floatpower(Float:value, Float:exponent);

/**
 * <library>float</library>
 * <summary>This function allows you to get the logarithm of a float value.</summary>
 * <param name="value">The value of which to get the logarithm</param>
 * <param name="base">The logarithm base (optional=<b><c>10.0</c></b>)</param>
 * <seealso name="floatsqroot"/>
 * <seealso name="floatpower"/>
 * <returns>The logarithm as a float value.</returns>
 */
native Float:floatlog(Float:value, Float:base = 10.0);

/**
 * <library>float</library>
 * <summary>Get the sine from a given angle.  The input angle may be in radians, degrees or grades.</summary>
 * <param name="value">The angle from which to get the sine</param>
 * <param name="mode">The angle mode (see below) to use, depending on the value entered (optional=<b><c>radian</c></b>)</param>
 * <seealso name="floattan"/>
 * <seealso name="floatcos"/>
 * <remarks>GTA/open.mp use <b>degrees</b> for angles in most circumstances, for example
 * <a href="#GetPlayerFacingAngle">GetPlayerFacingAngle</a>.
 *  Therefore, it is most likely you'll want to use the <b>degrees</b> angle mode, not radians. </remarks>
 * <remarks>Also note that angles in GTA are counterclockwise; 270 is East and 90 is West.  South
 * is still 180 and North still 0/360. </remarks>
 * <remarks>
 *   <b>Angle modes:</b><p/>
 *   <ul>
 *     <li>radian</li>
 *     <li>degrees</li>
 *     <li>grades </li>
 *   </ul>
 * </remarks>
 * <returns>The sine of the value entered.</returns>
 */
native Float:floatsin(Float:value, anglemode:mode = radian);

/**
 * <library>float</library>
 * <summary>Get the cosine from a given angle.  The input angle may be in radians, degrees or grades.</summary>
 * <param name="value">The angle from which to get the cosine</param>
 * <param name="mode">The angle mode (see below) to use, depending on the value entered (optional=<b><c>radian</c></b>)</param>
 * <seealso name="floatsin"/>
 * <seealso name="floattan"/>
 * <remarks>GTA/open.mp use <b>degrees</b> for angles in most circumstances, for example
 * <a href="#GetPlayerFacingAngle">GetPlayerFacingAngle</a>.
 *  Therefore, it is most likely you'll want to use the <b>degrees</b> angle mode, not radians. </remarks>
 * <remarks>Also note that angles in GTA are counterclockwise; 270 is East and 90 is West.  South
 * is still 180 and North still 0/360. </remarks>
 * <remarks>
 *   <b>Angle modes:</b><p/>
 *   <ul>
 *     <li>radian</li>
 *     <li>degrees</li>
 *     <li>grades </li>
 *   </ul>
 * </remarks>
 * <returns>The cosine of the value entered.</returns>
 */
native Float:floatcos(Float:value, anglemode:mode = radian);

/**
 * <library>float</library>
 * <summary>Get the tangent from a given angle.  The input angle may be in radians, degrees or grades.</summary>
 * <param name="value">The angle from which to get the tangent</param>
 * <param name="mode">The angle mode to use, depending on the value entered</param>
 * <seealso name="floatsin"/>
 * <seealso name="floatcos"/>
 * <remarks>GTA/open.mp use <b>degrees</b> for angles in most circumstances, for example
 * <a href="#GetPlayerFacingAngle">GetPlayerFacingAngle</a>.
 *  Therefore, it is most likely you'll want to use the <b>degrees</b> angle mode, not radians. </remarks>
 * <remarks>Also note that angles in GTA are counterclockwise; 270 is East and 90 is West.  South
 * is still 180 and North still 0/360. </remarks>
 * <remarks>
 *   <b>Angle modes:</b><p/>
 *   <ul>
 *     <li>radian</li>
 *     <li>degrees</li>
 *     <li>grades </li>
 *   </ul>
 * </remarks>
 * <returns>The tangent from the value entered.</returns>
 */
native Float:floattan(Float:value, anglemode:mode = radian);

/**
 * <library>float</library>
 * <summary>This function returns the absolute value of float.</summary>
 * <param name="value">The float value to get the absolute value of</param>
 * <returns>The absolute value of the float (as a float value).</returns>
 */
native Float:floatabs(Float:value);

/* user defined operators */
/**
 * <library>float</library>
 */
native Float:operator*(Float:oper1, Float:oper2) = floatmul;

/**
 * <library>float</library>
 */
native Float:operator/(Float:oper1, Float:oper2) = floatdiv;

/**
 * <library>float</library>
 */
native Float:operator+(Float:oper1, Float:oper2) = floatadd;

/**
 * <library>float</library>
 */
native Float:operator-(Float:oper1, Float:oper2) = floatsub;

/**
 * <library>float</library>
 */
native Float:operator=(oper) = float;

/**
 * <library>float</library>
 */
/*
native Float:operator++(Float:oper);
*/
stock Float:operator++(Float:__oper)
{
	return __oper + 1.0;
}

/**
 * <library>float</library>
 */
/*
native Float:operator--(Float:oper);
*/
stock Float:operator--(Float:__oper)
{
	return __oper - 1.0;
}

/**
 * <library>float</library>
 */
/*
native Float:operator-(Float:oper);
*/
stock Float:operator-(Float:__oper)
{
	return __oper ^ Float:cellmin;                /* IEEE values are sign/magnitude */
}

/**
 * <library>float</library>
 */
/*
native Float:operator*(Float:oper1, oper2);
*/
stock Float:operator*(Float:__oper1, __oper2)
{
	return floatmul(__oper1, float(__oper2)); /* "*" is commutative */
}

/**
 * <library>float</library>
 */
/*
native Float:operator/(Float:oper1, oper2);
*/
stock Float:operator/(Float:__oper1, __oper2)
{
	return floatdiv(__oper1, float(__oper2));
}

/**
 * <library>float</library>
 */
/*
native Float:operator/(oper1, Float:oper2);
*/
stock Float:operator/(__oper1, Float:__oper2)
{
	return floatdiv(float(__oper1), __oper2);
}

/**
 * <library>float</library>
 */
/*
native Float:operator+(Float:oper1, oper2);
*/
stock Float:operator+(Float:__oper1, __oper2)
{
	return floatadd(__oper1, float(__oper2)); /* "+" is commutative */
}

/**
 * <library>float</library>
 */
/*
native Float:operator-(Float:oper1, oper2);
*/
stock Float:operator-(Float:__oper1, __oper2)
{
	return floatsub(__oper1, float(__oper2));
}

/**
 * <library>float</library>
 */
/*
native Float:operator-(oper1, Float:oper2);
*/
stock Float:operator-(__oper1, Float:__oper2)
{
	return floatsub(float(__oper1), __oper2);
}

/**
 * <library>float</library>
 */
/*
native bool:operator==(Float:oper1, Float:oper2);
*/
stock bool:operator==(Float:__oper1, Float:__oper2)
{
	return floatcmp(__oper1, __oper2) == 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator==(Float:oper1, oper2);
*/
stock bool:operator==(Float:__oper1, __oper2)
{
	return floatcmp(__oper1, float(__oper2)) == 0; /* "==" is commutative */
}

/**
 * <library>float</library>
 */
/*
native bool:operator!=(Float:oper1, Float:oper2);
*/
stock bool:operator!=(Float:__oper1, Float:__oper2)
{
	return floatcmp(__oper1, __oper2) != 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator!=(Float:oper1, Float:oper2);
*/
stock bool:operator!=(Float:__oper1, __oper2)
{
	return floatcmp(__oper1, float(__oper2)) != 0; /* "!=" is commutative */
}

/**
 * <library>float</library>
 */
/*
native bool:operator>(Float:oper1, Float:oper2);
*/
stock bool:operator>(Float:__oper1, Float:__oper2)
{
	return floatcmp(__oper1, __oper2) > 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator>(Float:oper1, oper2);
*/
stock bool:operator>(Float:__oper1, __oper2)
{
	return floatcmp(__oper1, float(__oper2)) > 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator>(oper1, Float:oper2);
*/
stock bool:operator>(__oper1, Float:__oper2)
{
	return floatcmp(float(__oper1), __oper2) > 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator>=(Float:oper1, Float:oper2);
*/
stock bool:operator>=(Float:__oper1, Float:__oper2)
{
	return floatcmp(__oper1, __oper2) >= 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator>=(Float:oper1, oper2);
*/
stock bool:operator>=(Float:__oper1, __oper2)
{
	return floatcmp(__oper1, float(__oper2)) >= 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator>=(oper1, Float:oper2);
*/
stock bool:operator>=(__oper1, Float:__oper2)
{
	return floatcmp(float(__oper1), __oper2) >= 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator<(Float:oper1, Float:oper2);
*/
stock bool:operator<(Float:__oper1, Float:__oper2)
{
	return floatcmp(__oper1, __oper2) < 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator<(Float:oper1, oper2);
*/
stock bool:operator<(Float:__oper1, __oper2)
{
	return floatcmp(__oper1, float(__oper2)) < 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator<(oper1, Float:oper2);
*/
stock bool:operator<(__oper1, Float:__oper2)
{
	return floatcmp(float(__oper1), __oper2) < 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator<=(Float:oper1, Float:oper2);
*/
stock bool:operator<=(Float:__oper1, Float:__oper2)
{
	return floatcmp(__oper1, __oper2) <= 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator<=(Float:oper1, oper2);
*/
stock bool:operator<=(Float:__oper1, __oper2)
{
	return floatcmp(__oper1, float(__oper2)) <= 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator<=(oper1, Float:oper2);
*/
stock bool:operator<=(__oper1, Float:__oper2)
{
	return floatcmp(float(__oper1), __oper2) <= 0;
}

/**
 * <library>float</library>
 */
/*
native bool:operator!(Float:oper);
*/
stock bool:operator!(Float:__oper)
{
	return (_:__oper & cellmax) == 0;
}

/* forbidden operations */
/**
 * <library>float</library>
 */
forward operator%(Float:oper1, Float:oper2);

/**
 * <library>float</library>
 */
forward operator%(Float:oper1, oper2);

/**
 * <library>float</library>
 */
forward operator%(oper1, Float:oper2);
