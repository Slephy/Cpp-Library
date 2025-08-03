#pragma once
#include "../core/core.hpp"

bool is_sq(ll val) {
    if(val < 0) return false;
    ll sq = sqrt(val);
    return sq * sq == val;
}
