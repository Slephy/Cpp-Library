#pragma once
#include "../core/core.hpp"

// 素因数分解をし、素因数とその指数のペアを返す
// {素因数, 指数}
vector<pair<ll, int>> prime_factorization(ll n) {
    assert(n >= 1);
    if(n == 1) return {};

    vector<pair<ll, int>> ret;  // 素因数とその指数
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            ret.emplace_back(i, cnt);
        }
    }
    if(n > 1) ret.emplace_back(n, 1);
    return ret;
}
