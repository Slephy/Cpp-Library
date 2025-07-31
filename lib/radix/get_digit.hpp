#pragma once
#include "../core/core.hpp"
// n を k 進法で表した時の digit 桁目を返す (0-indexed)
int inline get_digit_by_based_k(ll n, ll k, ll digit) {
    assert(n >= 0);
    assert(2 <= k && k <= 10);
    assert(digit >= 0);

    return (n / powll(k, digit)) % k;
}
