#pragma once
#include "../core/core.hpp"
// absが使える型に限る
template <class T> T nearest_value(const vector<T> &v, T key, bool prioritizeBig = true) {
    assert(v.size() > 0);
    if(v.size() == 1) return *v.begin();

    auto lb = lower_bound(v.begin(), v.end(), key);
    if(lb == v.begin()) lb++;
    else if(lb == v.end()) lb--;
    T big = *lb;
    T small = *prev(lb);

    if(abs(big - key) < abs(small - key)) return big;
    else if(abs(big - key) > abs(small - key)) return small;
    else {
        if(prioritizeBig) return big;
        else return small;
    }
}


template <class T> T nearest_value(const set<T> &v, T key, bool prioritizeBig = true) {
    assert(v.size() > 0);
    if(v.size() == 1) return *v.begin();

    auto lb = v.lower_bound(key);
    if(lb == v.begin()) lb++;
    else if(lb == v.end()) lb--;
    T big = *lb;
    T small = *prev(lb);

    if(abs(big - key) < abs(small - key)) return big;
    else if(abs(big - key) > abs(small - key)) return small;
    else {
        if(prioritizeBig) return big;
        else return small;
    }
}

// 最も近いkeyの値を返す valueは無視
template <class T, class U> T nearest_value(const map<T, U> &v, T key, bool prioritizeBig = true) {
    assert(v.size() > 0);
    if(v.size() == 1) return v.begin()->first;

    auto lb = v.lower_bound(key);
    if(lb == v.begin()) lb++;
    else if(lb == v.end()) lb--;
    T big = lb->first;
    T small = prev(lb)->first;

    if(abs(big - key) < abs(small - key)) return big;
    else if(abs(big - key) > abs(small - key)) return small;
    else {
        if(prioritizeBig) return big;
        else return small;
    }
}
