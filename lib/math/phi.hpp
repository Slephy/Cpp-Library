#pragma once
#include "../core/core.hpp"

// [1, n] において n と互いに素な整数の個数を求める
// O(sqrt(n))
ll phi(ll n) {
    assert(n >= 0);
    ll ret = n;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ret -= ret / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ret -= ret / n;
    return ret;
}
