#if defined _time_included
	#endinput
#endif
#define _time_included

/**
 * <library name="time" summary="Date/time functions.">
 *   <license>
 *     (c) Copyright 2001-2005, ITB CompuPhase
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

#pragma library Time

/// <p/>

/**
 * <library>time</library>
 * <summary>Get the current server time.</summary>
 * <param name="hour">The variable to store the hour in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="minute">The variable to store the minute in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="second">The variable to store the seconds in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <seealso name="getdate"/>
 * <returns>The function itself returns a Unix Timestamp.</returns>
 */
native gettime(&hour = 0, &minute = 0, &second = 0);

/**
 * <library>time</library>
 * <summary>Get the current server date.</summary>
 * <param name="year">The variable to store the year in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="month">The variable to store the month in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="day">The variable to store the day in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <seealso name="gettime"/>
 * <returns>The number of days since the start of the year.</returns>
 */
native getdate(&year = 0, &month = 0, &day = 0);

/**
 * <library>time</library>
 * <summary>This function can be used as a replacement for <a href="#GetTickCount">GetTickCount</a>,
 * as it returns the number of milliseconds since the start-up of the server.</summary>
 * <param name="granularity">Upon return, this value contains the number of ticks that the internal
 * system time will tick per second.  This value therefore indicates the accuracy of the return value
 * of this function (optional=<b><c>0</c></b>)</param>
 * <returns>The number of milliseconds since start-up of the system.  For a 32-bit cell, this count
 * overflows after approximately 24 days of continuous operation.</returns>
 */
native tickcount(&granularity = 0);

/**
 * <library>time</library>
 * <summary>A timer event occurred.</summary>
 * <remarks>
 * This function executes after the configured delay or interval expires.  See <c>settimer</c> to
 * set the delay or interval.  Depending on the timing precision of the host, the call may occur
 * later than the delay that was set.
 * <p/>
 * If the timer was set as a "single-shot", it must be ex plicitly set again for a next execution
 * for the <c>@timer</c>function.  If the timer is set to be repetitive, <c>@timer</c> will continue
 * to be called with the set interval until it is disabled with another call to <c>settimer</c>.
 * </remarks>
 * <returns>The return value of this function is currently ignored.</returns>
 */
forward @timer();

/**
 * <library>time</library>
 */
/* */ native __settimer(const callback[], milliseconds, bool:multishot) = SetTimer;

/**
 * <library>time</library>
 */
/* */ native __killtimer(id) = KillTimer;

/**
 * <library>time</library>
 * <summary>Configure the event timer.</summary>
 * <param name="milliseconds">The number of milliseconds to wait before calling the <c>@timer</c>
 * callback function.  If the timer is repetitive, this is the interval.  When this parameter is 0
 * (zero), the timer is shut off.</param>
 * <param name="singleshot">If <c>false</c>, the timer is a repetitive timer; if <c>true</c> the
 * timer is shut off after invoking the <c>@timer</c> event once.</param>
 * <remarks>
 * See the chapter "Usage" for an example of this function, and the <c>@timer</c> event function.
 * </remarks>
 * <returns>This function always returns 0.</returns>
 */
/*
native settimer(milliseconds, bool:singleshot = false);
*/
stock settimer(__milliseconds, bool:__singleshot = false)
{
	static __id = 0;
	if (__id)
	{
		__killtimer(__id);
	}
	__id = 0;
	if (__milliseconds)
	{
		__id = __settimer("@timer", __milliseconds, !__singleshot);
	}
	return 0;
}

/**
 * <library>time</library>
 * <summary>Halts execution a number of milliseconds.</summary>
 * <param name="milliseconds">The delay, in milliseconds.</param>
 * <remarks>
 * On some platforms, the <c>sleep</c> instruction also delays for a given number of milliseconds.
 * The difference between the <c>sleep</c> instruction and the <c>delay</c> function is that the
 * <c>delay</c> function does not yield events and the <c>sleep</c> instruction typically yields.
 * When yielding events, any pending events are handled.  As a result, the <c>delay</c> function
 * waits without handling any pending events and the <c>sleep</c> instruction waits and deals with
 * events.
 * </remarks>
 * <returns>This function always returns 0.</returns>
 */
/*
native delay(milliseconds);
*/
stock delay(__milliseconds)
{
	// This arrangement accounts for integer overflows.
	new __end = tickcount() + __milliseconds;
	while (tickcount() - __end < 0)
	{
		// Do nothing.
	}
	return 0;
}

/**
 * <library>time</library>
 * <summary>Convert a time-stamp into a date and time.</summary>
 * <param name="year">This will hold the year upon return.</param>
 * <param name="month">This will hold the month (1-12) upon return.</param>
 * <param name="day">This will hold the day of (1-31) the month upon return.</param>
 * <param name="hour">This will hold the hour (0-23) upon return.</param>
 * <param name="minute">This will hold the minute (0-59) upon return.</param>
 * <param name="second">This will hold the second (0-59) upon return.</param>
 * <remarks>
 * Some file and system functions return time-stamps as the number of seconds since midnight, 1
 * January 1970, which is the start of the UNIX system epoch.  This function allows to convert these
 * time stamps into date and time fields.  <c>cvttimestamp</c> = <em>ConVerT TIMESTAMP</em>.
 * </remarks>
 * <returns>This function always returns 0.</returns>
 */
/*
native cvttimestamp(seconds1970, &year = 0, &month = 0, &day = 0, &hour = 0, &minute = 0, &second = 0);
*/
stock cvttimestamp(__seconds1970, &__year = 0, &__month = 0, &__day = 0, &__hour = 0, &__minute = 0, &__second = 0)
{
	// Based on the amxtime.c code, with some fixed bugs...
	new __days, __seconds;
	static __monthdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Find the year.
	for (__year = 1970; ; ++__year)
	{
		// Leap year check.
		__days = 365 + _:((__year % 4) == 0) - _:((__year % 100) == 0) + _:((__year % 400) == 0);
		__seconds = __days * 86400;
		if (__seconds - __seconds1970 > 0)
		{
			break;
		}
		__seconds1970 -= __seconds;
	}

	// Find the month.
	for (__month = 1; ; ++__month)
	{
		__days = __monthdays[__month - 1];
		__seconds = __days * 86400;
		if (__seconds - __seconds1970 > 0)
		{
			break;
		}
		__seconds1970 -= __seconds;
	}

	// Find the day.
	for (__day = 1; __seconds1970 >= 86400; ++__day)
	{
		__seconds1970 -= 86400;
	}

	// Find the hour.
	for (__hour = 0; __seconds1970 >= 3600; ++__hour)
	{
		__seconds1970 -= 3600;
	}

	// Find the minute.
	for (__minute = 0; __seconds1970 >= 60; ++__minute)
	{
		__seconds1970 -= 60;
	}

	// Remainder is the number of seconds.
	__second = __seconds1970;

	return 0;
}

/**
 * <library>time</library>
 * <summary>Set the system date.</summary>
 * <param name="year">The year to set; if set to <c>"cellmin"</c>, the default value, it is ignored.</param>
 * <param name="month">The month to set; if set to <c>"cellmin"</c>, the default value, it is ignored.</param>
 * <param name="day">The day to set; if set to <c>"cellmin"</c>, the default value, it is ignored.</param>
 * <returns>This function always returns 0.</returns>
 * <remarks>The date fields are kept in a valid range.  For example, when setting the month to 13,
 * it wraps back to 1 - this is always wrapped to the min/max, not modulo.</remarks>
 */
forward setdate(year = cellmin, month = cellmin, day = cellmin);

/**
 * <library>time</library>
 * <summary>Set the system time.</summary>
 * <param name="hour">The hour to set, in the range 0-23; if set to <c>"cellmin"</c>, the default value, it is ignored.</param>
 * <param name="minute">The minute to set, in the range 0-59; if set to <c>"cellmin"</c>, the default value, it is ignored.</param>
 * <param name="second">The second to set, in the range 0-59; if set to <c>"cellmin"</c>, the default value, it is ignored.</param>
 * <returns>This function always returns 0.</returns>
 * <remarks>The time fields are kept in a valid range.  For example, when setting the hour to 24, it
 * wraps back to 0 - this is always wrapped to the min/max, not modulo.</remarks>
 */
forward settime(hour = cellmin, minute = cellmin, second = cellmin);

/**
 * <library>time</library>
 * <summary>Sets the date and time with a single value.</summary>
 * <param name="seconds1970">The number of seconds that have elapsed since 00:00 hours, 1 January
 * 1970.  This particular date, 1 January 1970, is the <em>UNIX system epoch</em>.</param>
 * <returns>This function always returns 0.</returns>
 * <remarks>The function <c>getdate</c> returns the number of seconds since 1 January 1970.</remarks>
 */
/*
native settimestamp(seconds1970);
*/
stock settimestamp(__seconds1970)
{
	new __year, __month, __day, __hour, __minute, __second;
	cvttimestamp(__seconds1970, __year, __month, __day, __hour, __minute, __second);
	setdate(__year, __month, __day);
	settime(__hour, __minute, __second);
	return 0;
}
