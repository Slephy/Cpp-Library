#pragma once
#include "../core/core.hpp"

template <class Judgement> long long binary_search_integer(long long ok, long long ng, Judgement judge) {
    auto need_continue = [&]() -> bool {
        if(ok > ng) return ((__int128_t)ok - (__int128_t)ng > 1);
        else return ((__int128_t)ng - (__int128_t)ok > 1);
    };
    while(need_continue()) {
        ll mid = ((__int128_t)ok + (__int128_t)ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
};
