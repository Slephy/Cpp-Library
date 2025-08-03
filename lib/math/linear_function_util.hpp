#pragma once
#include "../core/core.hpp"

// ax + b >= min_value を満たすギリギリの x を返す
// ⚠️ 制約: a != 0
// min_value - b がオーバーフローしないならば、オーバーフローしない
ll min_linear_x(ll a, ll b, ll min_value) {
    assert(a != 0);
    ll x;
    if(a > 0) x = ceil_div(min_value - b, a);
    else x = floor_div(min_value - b, a);
    return x;
}

// ax + b <= max_value を満たすギリギリの x を返す
// ⚠️ 制約: a != 0
// max_value - b がオーバーフローしないならば、オーバーフローしない
ll max_linear_x(ll a, ll b, ll max_value) {
    assert(a != 0);
    ll x;
    if(a > 0) x = floor_div(max_value - b, a);
    else x = ceil_div(max_value - b, a);
    return x;
}

// ax + b >= min_value を満たす最小の ax + b を返す
// ⚠️ 制約: a != 0
// min_value - b がオーバーフローしないならば、オーバーフローしない
ll min_linear_value(ll a, ll b, ll min_value) { return a * min_linear_x(a, b, min_value) + b; }

// ax + b <= max_value を満たす最大の ax + b を返す
// ⚠️ 制約: a != 0
// max_value - b がオーバーフローしないならば、オーバーフローしない
ll max_linear_value(ll a, ll b, ll max_value) { return a * max_linear_x(a, b, max_value) + b; }

// ax + b と表される整数のうち、target に最も近いものを返す
// ⚠️ 制約: a != 0
// prioritize_big が true のとき、target に最も近いものが複数あるときは大きい方を返す
// target - b がオーバーフローしないならば、オーバーフローしない
ll nearest_linear_value(ll a, ll b, ll target, bool prioritize_big = true) {
    assert(a != 0);
    ll big = min_linear_value(a, b, target);    // >= target
    ll small = max_linear_value(a, b, target);  // <= target
    assert(small <= big);
    if(abs(big - target) == abs(small - target)) {
        if(prioritize_big) return big;
        else return small;
    }
    else {
        if(abs(big - target) < abs(small - target)) return big;
        else return small;
    }
}

// min_value <= ax + b <= max_value を満たす x の範囲を返す
// そのような x が存在しない場合は false を返す
// ⚠️ 制約: a != 0
tuple<bool, ll, ll> linear_range_x(ll a, ll b, ll min_value, ll max_value) {
    assert(a != 0);
    assert(min_value <= max_value);
    ll min_x = min_linear_x(a, b, min_value);
    ll max_x = max_linear_x(a, b, max_value);
    if(a < 0) swap(min_x, max_x);
    if(min_x > max_x) return {false, 0, 0};
    else return {true, min_x, max_x};
}
