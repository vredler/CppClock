#pragma once
#include "../../src/include/catch.hpp"
#include "../../src/header/HelperMethods.h"

TEST_CASE("To string with leading '0'", "[to_string_with_leading_0]")
{
    int lessThan10 = 4;
    int moreThen10 = 14;
    int is10 = 10;
    int is0 = 0;
    int lessThan0 = -1;

    CHECK(to_string_with_leading_0(lessThan10) == "04");
    CHECK(to_string_with_leading_0(moreThen10) == "14");
    CHECK(to_string_with_leading_0(is10) == "10");
    CHECK(to_string_with_leading_0(is0) == "00");
    CHECK_THROWS_AS(to_string_with_leading_0(lessThan0), std::invalid_argument);
}