#pragma once
#include "../core/core.hpp"
bool is_leap_year(ll year) {
    if(year % 400 == 0) return true;
    if(year % 100 == 0) return false;
    if(year % 4 == 0) return true;
    else return false;
}
