#pragma once
#include "../core/core.hpp"

// O(sqrt(n))
// 素因数を昇順に列挙する
vector<ll> enum_prime_factors(ll n, bool with_repetition = false) {
    vector<ll> ret;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ret.emplace_back(i);
            n /= i;
            while(n % i == 0) {
                if(with_repetition) ret.emplace_back(i);
                n /= i;
            }
        }
    }
    if(n > 1) ret.emplace_back(n);
    return ret;
}
