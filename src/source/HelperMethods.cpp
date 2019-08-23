#pragma once
#include <iostream>
#include <string>
#include "../header/HelperMethods.h"

std::string to_string_with_leading_0(int value){
    if (value < 0)
    {
        throw std::invalid_argument("input value can not be less than 0");
    }

    if (value < 10 && value >= 0)
    {
        return "0" + 
        std::to_string(value);
    }
    
    return std::to_string(value);
}
