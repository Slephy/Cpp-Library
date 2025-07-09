#pragma once
#include "../core/core.hpp"
template <typename T> int sign(T val) {
    if(val == 0) return 0;
    else if(val > 0) return 1;
    else return -1;
}
