#pragma once
#include "../core/core.hpp"
ll mod_inv(ll val, ll mod) {
    ll b = mod, u = 1, v = 0;
    while(b) {
        ll t = val / b;
        val -= t * b;
        swap(val, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if(u < 0) u += mod;
    return u;
}
