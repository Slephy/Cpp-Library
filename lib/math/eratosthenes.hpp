#pragma once
#include "../core/core.hpp"

vector<bool> eratosthenes(ll n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false, is_prime[1] = false;

    for(ll i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(ll j = 2 * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}
