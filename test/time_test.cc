#include "../src/includes/catch.hpp";
#include "../src/headers/Clock.h";

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