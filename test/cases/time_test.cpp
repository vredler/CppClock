#pragma once
#include "../../src/include/catch.hpp"
#include "../../src/header/Clock.h"

TEST_CASE("If constructor hour is 10 then get 10", "[get_hour]"){
    Clock *onlyHour = new Clock(10);
    Clock *hourAndMinute = new Clock(10, 5);
    Clock *fullClock = new Clock(10, 5, 45);

    REQUIRE(onlyHour->get_hour() == 10);
    REQUIRE(hourAndMinute->get_hour() == 10);
    REQUIRE(fullClock->get_hour() == 10);
}

TEST_CASE("If constructor minute is 5 then get 5", "[get_minute]"){
    Clock *minute = new Clock(10, 5);
    Clock *fullClock = new Clock(10, 5, 45);

    REQUIRE(minute->get_minute() == 5);
    REQUIRE(fullClock->get_minute() == 5);
}

TEST_CASE("If construtor second is 36 then get 36", "[get_second]"){
    Clock *clock = new Clock(10, 5, 36);
    
    REQUIRE(clock->get_second() == 36);
}

TEST_CASE("If clock is instantiated as 13:30:15 then string is '13:30:15'"){
    Clock *clock = new Clock(13, 30, 15);

    REQUIRE(clock->to_string() == "13:30:15");
}

TEST_CASE("Testing AM and PM", "[to_string]"){
    Clock *pmClock = new Clock(13, 30, 15);
    pmClock->switch_clock_type();

    Clock *amClock = new Clock(00, 05, 10);
    amClock->switch_clock_type();

    Clock *testClock = new Clock(14, 21, 23);
    testClock->switch_clock_type();

    REQUIRE(pmClock->to_string() == "01:30:15 PM");
    REQUIRE(amClock->to_string() == "12:05:10 AM");

    REQUIRE(testClock->to_string() == "02:21:23 PM");
    testClock->switch_clock_type();
    REQUIRE(testClock->to_string() == "14:21:23");
}

TEST_CASE("Check if AM OR PM", "[is_pm]"){
    Clock *testClock = new Clock(14, 21, 23);
    Clock *amTest = new Clock(11, 59, 59);

    REQUIRE(testClock->is_pm() == true);
    REQUIRE(amTest->is_pm() == false);
}

// TEST_CASE(){

// }