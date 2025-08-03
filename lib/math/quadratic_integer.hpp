#pragma once
#include "../core/core.hpp"
#include "../math/isqrt.hpp"

// return integer solutions of the quadratic equation ax^2 + bx + c = 0
vector<ll> solve_quadratic_integer(ll a, ll b, ll c) {
    assert(a != 0 || b != 0 || c != 0); // infinite solutions
    if(a == 0) {
        if(b == 0) return {};
        else return (c % b == 0) ? vector<ll>{-c / b} : vector<ll>{};
    }

    vector<ll> ret;
    ll d = b * b - 4 * a * c;
    if(d < 0) return ret;
    else if(d == 0) {
        ret.push_back(-b / (2 * a));
        return ret;
    }
    else {
        auto sq = isqrt(d);
        if(!sq) return {};
        auto emplace_if_integer = [&](ll sq) -> void {
            ll nume = -b + sq;
            ll deno = 2 * a;
            if(nume % deno == 0) ret.emplace_back(nume / deno);
        };
        emplace_if_integer(*sq);
        emplace_if_integer(-*sq);
        return ret;
    }
}
