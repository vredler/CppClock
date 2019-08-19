#define CATCH_CONFIG_RUNNER
#include "../src/includes/catch.hpp";
#include "../src/headers/Clock.h";

int main(int argc, char* argv[])
{
    return Catch::Session{}.run(argc, argv);
}
