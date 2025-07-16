#pragma once
#include "../core/core.hpp"

namespace slephy_extgcd {

// ax + by = gcd(a, b) の整数特殊解 x, y を得る
// 制約: a >= 0, b >= 0
pair<ll, ll> extgcd_impl(ll a, ll b) {
    if(b == 0) return {1, 0};
    auto [x, y] = extgcd_impl(b, a % b);
    ll nx = y, ny = x - a / b * y;
    return {nx, ny};
}

// ax + by = gcd(a, b) の整数特殊解 x, y を得る
// 制約: なし
pair<ll, ll> extgcd(ll a, ll b) {
    auto [x, y] = extgcd_impl(abs(a), abs(b));
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return {x, y};
}

// ax + by = ans の整数特殊解 x, y を得る
// 返り値のfirstは解が存在するかどうか
tuple<bool, ll, ll> extgcd(ll a, ll b, ll ans) {
    if(a == 0 && b == 0) return {ans == 0, 0, 0};
    if(ans % gcd(a, b) != 0) return {false, 0, 0};

    bool swapped = false;
    if(abs(a) < abs(b)) swap(a, b), swapped = true;  // |a| >= |b|
    auto [x, y] = extgcd(a, b);

    // ans <- ans % a
    const ll ANS = ans;
    ll addx = 0;
    if(abs(ans) > abs(a)) {
        addx = ans / a;
        ans -= a * addx;
    }

    // ax + by = gcd(a, b) の特殊解から ax + by = ans の特殊解を得る
    ll p = ans / gcd(a, b);
    x *= p, y *= p;
    x += addx;

    // swap をもとに戻す
    if(swapped) swap(a, b), swap(x, y);
    return {true, x, y};
}
}  // namespace slephy_extgcd
using::slephy_extgcd::extgcd;
