#pragma once
#include "../core/core.hpp"

template <class Judgement> ll binary_search_integer(ll ok, ll ng, Judgement judge) {
    while(true) {
        ll mid = midpoint(ok, ng);
        if(mid == ok || mid == ng) break;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
};
