#pragma once
#include "../header/Clock.h"
#include "../header/HelperMethods.h"
#include <iostream>
#include <string>
#include <assert.h>

Clock::Clock(
    int hour,
    int minute,
    int second)
{
    _hour = hour;
    _minute = minute;
    _second = second;
    _isMilitaryTime = true;

    time_cleanup();
}

Clock::Clock(
    int hour,
    int minute)
    : Clock(hour, minute, 0)
{
}

Clock::Clock(
    int hour)
    : Clock(hour, 0, 0)
{
}

int Clock::get_hour() const
{
    return _hour;
}

int Clock::get_minute() const
{
    return _minute;
}

int Clock::get_second() const
{
    return _second;
}

bool Clock::is_military_time() const
{
    return _isMilitaryTime;
}

std::string Clock::to_string() const
{
    if (_isMilitaryTime)
    {
        return to_string_with_leading_0(_hour) + ":" +
               to_string_with_leading_0(_minute) + ":" +
               to_string_with_leading_0(_second);
    }

    if (_hour > 11 && _hour < 24)
    {
        return to_string_with_leading_0(_hour - 12) + ":" +
               to_string_with_leading_0(_minute) + ":" +
               to_string_with_leading_0(_second) +
               " PM";
    }

    if (_hour == 24 || _hour == 00)
    {
        return to_string_with_leading_0(12) + ":" +
               to_string_with_leading_0(_minute) + ":" +
               to_string_with_leading_0(_second) +
               " AM";
    }

    return to_string_with_leading_0(_hour - 12) + ":" +
           to_string_with_leading_0(_minute) + ":" +
           to_string_with_leading_0(_second) +
           " AM";
}

void Clock::switch_clock_type()
{
    _isMilitaryTime = !_isMilitaryTime;
}

bool Clock::is_pm() const
{
    return _hour > 11;
}

std::ostream &operator<<(std::ostream &out, const Clock &clock)
{
    out << clock.to_string();
    return out;
}

Clock Clock::operator+(
    int seconds)
{
    Clock returnClock(
        _hour,
        _minute,
        _second + seconds);
    return returnClock;
}

Clock Clock::operator-(
    int seconds)
{
    Clock returnClock(
        _hour,
        _minute,
        _second - seconds);
    return returnClock;
}

Clock Clock::operator++()
{
    _second = _second + 1;
    time_cleanup();
    return *this;
}

Clock Clock::operator++(int)
{
    Clock temp(
        _hour,
        _minute,
        _second);

    ++temp;
    ++_second;
    time_cleanup();
    return temp;
}

Clock Clock::operator--()
{
    _second = _second - 1;
    time_cleanup();
    return *this;
}

Clock Clock::operator--(int)
{
    Clock temp(
        _hour,
        _minute,
        _second);

    --temp;
    --_second;
    time_cleanup();
    return temp;
}

bool Clock::operator<(const Clock &compare)
{
    try
    {
        return !bigger_than(compare);
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool Clock::operator<=(const Clock &compare)
{
    if (is_equal(compare))
        return true;

    try
    {
        return !bigger_than(compare);
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool Clock::operator>(const Clock &compare)
{
    try
    {
        return bigger_than(compare);
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool Clock::operator>=(const Clock &compare)
{
    if (is_equal(compare))
        return true;

    try
    {
        return bigger_than(compare);
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool Clock::bigger_than(const Clock &compare)
{
    if (_hour < compare.get_hour())
        return false;
    if (_hour > compare.get_hour())
        return true;

    if (_minute < compare.get_minute())
        return false;
    if (_minute > compare.get_minute())
        return true;

    if (_second < compare.get_second())
        return false;
    if (_second > compare.get_second())
        return true;

    throw std::exception("is equal");
}

bool Clock::is_equal(const Clock &compare)
{
    return _hour == compare.get_hour() &&
           _minute == compare.get_minute() &&
           _second == compare.get_second();
}

bool Clock::operator==(const Clock &compare)
{
    return is_equal(compare);
}

bool Clock::operator!=(const Clock &compare)
{
    return !is_equal(compare);
}

void Clock::time_cleanup()
{
    if (_second > 59)
    {
        _minute = _minute + (_second / 60);
        _second = _second - 60;
    }
    if (_second < 0)
    {
        int abs = std::abs(_second);

        _minute = _minute - ((abs / 60) + 1);
        _second = 60 - (abs % 60);
    }

    if (_minute > 59)
    {
        _hour = _hour + (_minute / 60);
        _minute = _minute - 60;
    }
    if (_minute < 0)
    {
        int abs = std::abs(_minute);

        _hour = _hour - ((abs / 60) + 1);
        _minute = 60 - (abs % 60);
    }

    if (_hour > 23)
    {
        _hour = _hour - 24;
    }
    if (_hour < 0)
    {
        _hour = 24 - std::abs(_hour);
    }
}