#pragma once
#include "../core/core.hpp"

template<class Judgement>
double binary_search_float(double ok, double ng, Judgement judge, double tolerance, bool considerRelativeError = true){
    auto need_continue = [&]() -> bool {
        if((fabs(ok - ng) < tolerance)) return false; // 絶対誤差
        if(considerRelativeError && (fabs(ok - ng) < tolerance * fabs((ok + ng) * 0.5))) return false; // 相対誤差
        return true;
    };

    while(need_continue()){
        double mid = midpoint(ok, ng);
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
};
