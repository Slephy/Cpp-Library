#pragma once
#include "../core/core.hpp"

ll mod_power(ll base, ll exponent, ll mod) {
    if(exponent < 0) return 0;
    ll ret = 1;
    base %= mod;
    while(exponent > 0) {
        if(exponent & 1) ret = ret * base % mod;
        base = base * base % mod;
        exponent >>= 1;
    }
    if(ret < 0) ret += mod;
    return ret;
}
