#pragma once
#include <iostream>

class Clock
{
    private:
        int _hour;
        int _minute;
        int _second;
        bool _isMilitaryTime;

    public:
        //Constructors
        Clock(int hour, int minute, int second);
        Clock(int hour, int minute);
        Clock(int hour);

        //Const methods
        std::string const to_string();
        int const get_hour();
        int const get_minute();
        int const get_second();
        bool const is_military_time();
        bool const is_pm();

        //Non const methods
        void switch_clock_type();
        // void add_seconds(int amountOfSeconds);
        // void add_minutes(int amountOfMinutes);
        // void add_hours(int amountOfHours);
};