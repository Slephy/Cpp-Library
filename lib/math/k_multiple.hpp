#pragma once
#include "../core/core.hpp"

namespace slephy_k_multiple {
// O(1)
// where 0 <= inf <= sup
ll _k_multiple_between(ll inf, ll sup, ll n) {
    assert(0 <= inf && inf <= sup);
    return floor_div(sup, n) - floor_div(inf - 1, n);
}

// O(1)
// where inf <= sup
// return the number of multiple of n betweem [inf, sup];
ll k_multiple_between(ll inf, ll sup, ll n) {
    if(inf > sup) return 0;
    if(inf <= 0 && sup <= 0) return _k_multiple_between(-sup, -inf, n);
    else if(inf <= 0 && sup >= 0) return _k_multiple_between(0, -inf, n) + _k_multiple_between(0, sup, n) - 1;
    else return _k_multiple_between(inf, sup, n);
}

// O(1)
// where inf <= sup
// return the number of nk + r betweem [inf, sup] (where k is integer)
ll k_multiple_between(ll inf, ll sup, ll n, ll r) { return k_multiple_between(inf - r, sup - r, n); }

};  // namespace slephy_k_multiple
using slephy_k_multiple::k_multiple_between;
