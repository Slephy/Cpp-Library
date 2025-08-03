#pragma once
#include "../core/core.hpp"

enum class TernalySearchDirection {
    Downward,
    Upward,
};

// 三分探索
// 狭義単調性を持つ単峰関数について最小値を取るときの引数を求める
// @need left <= right
template <class Evaluate>
ll ternary_search_integer(ll left, ll right,
                          Evaluate eval,  // param: ll, return: any
                          TernalySearchDirection direction = TernalySearchDirection::Downward) {
    assert(left <= right);

    // corner case
    if((__int128_t)right - left <= 1) {
        if(direction == TernalySearchDirection::Downward) {
            return ((eval(left) < eval(right)) ? left : right);
        }
        if(direction == TernalySearchDirection::Upward) {
            return ((eval(left) > eval(right)) ? left : right);
        }
    }

    // ✅ left < right && right - left >= 2
    auto need_continue = [&]() -> bool { return ((__int128_t)right - left > 2); };

    while(need_continue()) {
        ll mid1 = left + ((__int128_t)right - (__int128_t)left) / 3;
        ll mid2 = right - ((__int128_t)right - (__int128_t)left) / 3;

        if(direction == TernalySearchDirection::Downward) {
            if(eval(mid1) < eval(mid2)) right = mid2;
            else left = mid1;
        }
        if(direction == TernalySearchDirection::Upward) {
            if(eval(mid1) > eval(mid2)) right = mid2;
            else left = mid1;
        }
    }

    assert(right - left == 2);  // これが三分探索の終了条件
    ll mid = left + 1;
    if(direction == TernalySearchDirection::Downward) {
        if(eval(left) < eval(mid)) return left;
        if(eval(right) < eval(mid)) return right;
        else return mid;
    }
    if(direction == TernalySearchDirection::Upward) {
        if(eval(left) > eval(mid)) return left;
        if(eval(right) > eval(mid)) return right;
        else return mid;
    }
    else exit(1);
}
