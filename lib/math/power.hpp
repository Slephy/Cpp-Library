#pragma once
#include "../core/core.hpp"

template <typename T>
concept HasPowMember = requires(T a, ll b) {
    { a.pow(b) };
};

// 主に modint を想定
template <HasPowMember T> T power(T val, ll exp) { return val.pow(exp); }
