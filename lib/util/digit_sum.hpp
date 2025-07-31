#pragma once
#include "../core/core.hpp"
int digit_sum(ull n) {
    int ret = 0;
    while(n != 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}
