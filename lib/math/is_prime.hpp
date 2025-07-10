#pragma once
#include "../core/core.hpp"

// O(sqrt(n))
bool is_prime(ll n) {
    assert(n >= 0);
    if(n == 0 || n == 1) return false;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
