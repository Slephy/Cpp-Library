#pragma once
#include "../core/core.hpp"
bool is_add_overflow(ll a, ll b){ return __builtin_add_overflow_p(a, b, 0LL); }
bool is_sub_overflow(ll a, ll b){ return __builtin_sub_overflow_p(a, b, 0LL); }
bool is_mul_overflow(ll a, ll b){ return __builtin_mul_overflow_p(a, b, 0LL); }
