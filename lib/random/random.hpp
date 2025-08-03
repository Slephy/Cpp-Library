#pragma once
#include "../core/core.hpp"
namespace my_random {
random_device random_dvc;
mt19937 mt(random_dvc());

// l以上r以下の整数乱数を返す
int rand_int(int l, int r) {
    uniform_int_distribution<int> dist(l, r);
    return dist(mt);
}
// l以上r以下の整数乱数を返す
ll rand_ll(ll l, ll r) {
    uniform_int_distribution<ll> dist(l, r);
    return dist(mt);
}
__int128_t rand_i128(__int128_t l, __int128_t r) {
    uniform_int_distribution<long long> dist(0, numeric_limits<long long>::max());
    __int128_t res = dist(mt);
    res <<= 64;
    res += dist(mt);
    return res % (r - l + 1) + l;
}
__uint128_t rand_u128(__uint128_t l, __uint128_t r) {
    uniform_int_distribution<unsigned long long> dist(0, numeric_limits<unsigned long long>::max());
    __uint128_t res = dist(mt);
    res <<= 64;
    res += dist(mt);
    return res % (r - l + 1) + l;
}
double rand_double(double l, double r) {
    uniform_real_distribution<double> dist(l, r);
    return dist(mt);
}
double rand_double01() { return rand_double(0, 1); }
bool rand_bool(double probability) { return rand_double01() < probability; }
}  // namespace my_random
using namespace my_random;
