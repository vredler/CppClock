#pragma once
#include "../header/Clock.h"
#include "../header/HelperMethods.h"
#include <iostream>
#include <string>
#include <assert.h>

Clock::Clock(int hour, int minute, int second){
    _hour = hour;
    _minute = minute;
    _second = second;

    _isMilitaryTime = true;
}

Clock::Clock(int hour, int minute){
    _hour = hour;
    _minute = minute;

    _isMilitaryTime = true;
}

Clock::Clock(int hour){
    _hour = hour;

    _isMilitaryTime = true;
}

int const Clock::get_hour(){
    return _hour;
}

int const Clock::get_minute(){
    return _minute;
}

int const Clock::get_second(){
    return _second;
}

bool const Clock::is_military_time(){
    return _isMilitaryTime;
}

std::string const Clock::to_string(){
    if (_isMilitaryTime)
    {
        return to_string_with_leading_0(_hour) + ":" + 
        to_string_with_leading_0(_minute) + ":" + 
        to_string_with_leading_0(_second);
    }
    
    if (_hour > 11 && _hour < 24)
    {
        return to_string_with_leading_0(_hour-12) + ":" + 
        to_string_with_leading_0(_minute) + ":" + 
        to_string_with_leading_0(_second) + 
        " PM";
    }
    if (_hour == 24 || _hour == 00)
    {
        return to_string_with_leading_0(12) + ":" + to_string_with_leading_0(_minute) + ":" + to_string_with_leading_0(_second) + " AM";
    }

    return to_string_with_leading_0(_hour-12) + ":" + to_string_with_leading_0(_minute) + ":" + to_string_with_leading_0(_second) + " AM";
}

void Clock::switch_clock_type(){
    _isMilitaryTime = !_isMilitaryTime;
}

bool const Clock::is_pm(){
    if (_hour > 11)
    {
        return true;
    }
    
    return false;
}