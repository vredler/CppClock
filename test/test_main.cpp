#pragma once
#define CATCH_CONFIG_RUNNER
#include "../src/include/catch.hpp"

int main(int argc, char* argv[])
{
    return Catch::Session{}.run(argc, argv);
}
