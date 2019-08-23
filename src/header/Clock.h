#pragma once
#include <iostream>

class Clock
{
private:
    int _hour;
    int _minute;
    int _second;
    bool _isMilitaryTime;

    void time_cleanup();
    void init(int hour, int minute, int second);

public:
    //Constructors
    Clock(int hour, int minute, int second);
    Clock(int hour, int minute);
    Clock(int hour);

    //Const methods
    std::string to_string() const;
    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    bool is_military_time() const;
    bool is_pm() const;

    //Operator overloads
    Clock operator+(int seconds);
    Clock operator-(int seconds);
    Clock operator++();
    Clock operator++(int);
    Clock operator--();
    Clock operator--(int);

    //Non const methods
    void switch_clock_type();
    // void add_seconds(int amountOfSeconds);
    // void add_minutes(int amountOfMinutes);
    // void add_hours(int amountOfHours);
};