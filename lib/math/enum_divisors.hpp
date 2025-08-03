#pragma once
#include "../core/core.hpp"

// O(sqrt(n))
// 正の約数を照準に列挙する
vector<ll> enum_divisors(ll n) {
    vector<ll> ret1, ret2;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret1.emplace_back(i);
            if(i * i != n) ret2.emplace_back(n / i);
        }
    }
    reverse(ret2.begin(), ret2.end());
    ret1.insert(ret1.end(), ret2.begin(), ret2.end());
    return ret1;
}
