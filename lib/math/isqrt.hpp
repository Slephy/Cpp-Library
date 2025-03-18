#pragma once
optional<ll> isqrt(ll val) {
    if(val < 0) return nullopt;
    ll sq = sqrt(val);
    if(sq * sq == val) return sq;
    else return nullopt;
}
