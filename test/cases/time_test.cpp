#pragma once
#include "../../src/include/catch.hpp"
#include "../../src/header/Clock.h"

TEST_CASE("If constructor hour is 10 then get 10", "[get_hour]")
{
    Clock *onlyHour = new Clock(10);
    Clock *hourAndMinute = new Clock(10, 5);
    Clock *fullClock = new Clock(10, 5, 45);

    CHECK(onlyHour->get_hour() == 10);
    CHECK(hourAndMinute->get_hour() == 10);
    CHECK(fullClock->get_hour() == 10);
}

TEST_CASE("If constructor minute is 5 then get 5", "[get_minute]")
{
    Clock minute(10, 5);
    Clock fullClock(10, 5, 45);

    CHECK(minute.get_minute() == 5);
    CHECK(fullClock.get_minute() == 5);
}

TEST_CASE("If construtor second is 36 then get 36", "[get_second]")
{
    Clock &clock = *std::make_unique<Clock>(10, 5, 36);

    CHECK(clock.get_second() == 36);
}

TEST_CASE("If clock is instantiated as 13:30:15 then string is '13:30:15'")
{
    Clock *clock = new Clock(13, 30, 15);

    CHECK(clock->to_string() == "13:30:15");
}

TEST_CASE("Testing AM and PM", "[to_string]")
{
    Clock *pmClock = new Clock(13, 30, 15);
    pmClock->switch_clock_type();

    Clock *amClock = new Clock(00, 05, 10);
    amClock->switch_clock_type();

    Clock *testClock = new Clock(14, 21, 23);
    testClock->switch_clock_type();

    CHECK(pmClock->to_string() == "01:30:15 PM");
    CHECK(amClock->to_string() == "12:05:10 AM");

    CHECK(testClock->to_string() == "02:21:23 PM");
    testClock->switch_clock_type();
    CHECK(testClock->to_string() == "14:21:23");
}

TEST_CASE("Check if AM OR PM", "[is_pm]")
{
    Clock *testClock = new Clock(14, 21, 23);
    Clock *amTest = new Clock(11, 59, 59);

    CHECK(testClock->is_pm() == true);
    CHECK(amTest->is_pm() == false);
}

#pragma region + / -Operators

TEST_CASE("Adding Clock by seconds to get new time", "[Clock+int]")
{
    SECTION("Add 1 second")
    {
        Clock clock(14, 21, 23);

        auto result = clock + 1;

        CHECK(result.get_second() == 24);
        CHECK(result.get_minute() == 21);
        CHECK(result.get_hour() == 14);
    }

    SECTION("Add 61 seconds")
    {
        Clock clock(14, 21, 0);

        auto result = clock + 61;

        CHECK(result.get_second() == 1);
        CHECK(result.get_minute() == 22);
        CHECK(result.get_hour() == 14);
    }
}

TEST_CASE("Subtracting Clock by seconds to get new time", "[Clock-int]")
{
    SECTION("Subtract 1 second")
    {
        Clock clock(14, 21, 23);

        auto result = clock - 1;

        CHECK(result.get_second() == 22);
        CHECK(result.get_minute() == 21);
        CHECK(result.get_hour() == 14);
    }

    SECTION("Subtract 61 seconds")
    {
        Clock clock(14, 21, 23);

        auto result = clock - 61;

        CHECK(result.get_second() == 22);
        CHECK(result.get_minute() == 20);
        CHECK(result.get_hour() == 14);
    }
}

#pragma endregion + / -Operators

#pragma region Increment / Decrement

TEST_CASE("Prefix increment Clock by 1 second", "[prefix Clock]")
{
    SECTION("Normal")
    {
        Clock clock(14, 21, 24);

        ++clock;

        CHECK(clock.get_second() == 25);
        CHECK(clock.get_minute() == 21);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Minuteswitch")
    {
        Clock clock(14, 21, 59);

        ++clock;

        CHECK(clock.get_second() == 0);
        CHECK(clock.get_minute() == 22);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Hourswitch")
    {
        Clock clock(14, 59, 59);

        ++clock;

        CHECK(clock.get_second() == 0);
        CHECK(clock.get_minute() == 0);
        CHECK(clock.get_hour() == 15);
    }
}

TEST_CASE("Postfix increment Clock by 1 second", "[postfix Clock]")
{
    SECTION("Normal")
    {
        Clock clock(14, 21, 24);

        clock++;

        CHECK(clock.get_second() == 25);
        CHECK(clock.get_minute() == 21);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Minuteswitch")
    {
        Clock clock(14, 21, 59);

        clock++;

        CHECK(clock.get_second() == 0);
        CHECK(clock.get_minute() == 22);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Hourswitch")
    {
        Clock clock(14, 59, 59);

        clock++;

        CHECK(clock.get_second() == 0);
        CHECK(clock.get_minute() == 0);
        CHECK(clock.get_hour() == 15);
    }
}

TEST_CASE("Prefix decrement Clock by 1 second", "[predecrement Clock]")
{
    SECTION("Normal")
    {
        Clock clock(14, 21, 24);

        --clock;

        CHECK(clock.get_second() == 23);
        CHECK(clock.get_minute() == 21);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Minuteswitch")
    {
        Clock clock(14, 21, 0);

        --clock;

        CHECK(clock.get_second() == 59);
        CHECK(clock.get_minute() == 20);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Hourswitch")
    {
        Clock clock(14, 0, 0);

        --clock;

        CHECK(clock.get_second() == 59);
        CHECK(clock.get_minute() == 59);
        CHECK(clock.get_hour() == 13);
    }
}

TEST_CASE("Postfix decrement Clock by 1 second", "[postdecrement Clock]")
{
    SECTION("Normal")
    {
        Clock clock(14, 21, 24);

        clock--;

        CHECK(clock.get_second() == 23);
        CHECK(clock.get_minute() == 21);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Minuteswitch")
    {
        Clock clock(14, 21, 0);

        clock--;

        CHECK(clock.get_second() == 59);
        CHECK(clock.get_minute() == 20);
        CHECK(clock.get_hour() == 14);
    }

    SECTION("Hourswitch")
    {
        Clock clock(14, 0, 0);

        clock--;

        CHECK(clock.get_second() == 59);
        CHECK(clock.get_minute() == 59);
        CHECK(clock.get_hour() == 13);
    }
}

#pragma endregion

#pragma region Comparison Operators

TEST_CASE("Less than operator")
{
    Clock clock(14, 21, 23);

    SECTION("Positive check")
    {
        Clock diff(15, 1, 1);
        CHECK((clock < diff) == true);
    }

    SECTION("Negative check")
    {
        Clock diff(13, 1, 1);
        CHECK((clock < diff) == false);
    }

    SECTION("Equal results in false")
    {
        Clock diff(14, 21, 23);
        CHECK((clock < diff) == false);
    }
}

TEST_CASE("Greater than operator")
{
    Clock clock(14, 21, 23);

    SECTION("Negative check")
    {
        Clock diff(15, 1, 1);
        CHECK((clock > diff) == false);
    }

    SECTION("Positive check")
    {
        Clock diff(13, 1, 1);
        CHECK((clock > diff) == true);
    }

    SECTION("Equal results in false")
    {
        Clock diff(14, 21, 23);
        CHECK((clock > diff) == false);
    }
}

TEST_CASE("Equal operator")
{
    Clock clock(14, 21, 23);

    SECTION("Positive check")
    {
        Clock diff(14, 21, 23);
        CHECK((clock == diff) == true);
    }

    SECTION("Negative check")
    {
        Clock diff(14, 21, 24);
        CHECK((clock == diff) == false);
    }
}

TEST_CASE("Not equal operator")
{
    Clock clock(14, 21, 23);

    SECTION("Positive check")
    {
        Clock diff(14, 21, 24);
        CHECK((clock != diff) == true);
    }

    SECTION("Negative check")
    {
        Clock diff(14, 21, 23);
        CHECK((clock != diff) == false);
    }
}

TEST_CASE("Less than or equal operator")
{
    Clock clock(14, 21, 23);

    SECTION("Positive check")
    {
        Clock diff(15, 1, 1);
        CHECK((clock <= diff) == true);
    }

    SECTION("Negative check")
    {
        Clock diff(13, 1, 1);
        CHECK((clock <= diff) == false);
    }

    SECTION("Equal results in true")
    {
        Clock diff(14, 21, 23);
        CHECK((clock <= diff) == true);
    }
}

TEST_CASE("Greater than or equal operator")
{
    Clock clock(14, 21, 23);

    SECTION("Negative check")
    {
        Clock diff(15, 1, 1);
        CHECK((clock >= diff) == false);
    }

    SECTION("Positive check")
    {
        Clock diff(13, 1, 1);
        CHECK((clock >= diff) == true);
    }

    SECTION("Equal results in false")
    {
        Clock diff(14, 21, 23);
        CHECK((clock >= diff) == true);
    }
}

#pragma endregion Comparison Operators

#pragma region I / O Operators

TEST_CASE("Output operator")
{
    Clock clock(14, 1, 23);

    std::stringstream stream;
    stream << clock;

    std::string clockString = stream.str();

    CHECK(clockString == "14:01:23");
}

// TEST_CASE("Input operator")
// {
// }

#pragma endregion I / O Operators
