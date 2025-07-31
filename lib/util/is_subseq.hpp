#pragma once
#include "../core/core.hpp"
// [sub_first, sub_last) が [first, last) の連続とは限らない部分列かどうか
template <class InputItr> bool is_subseq(InputItr first, InputItr last, InputItr sub_first, InputItr sub_last) {
    if(sub_first == sub_last) return true;
    while(first != last) {
        if(*first == *sub_first) {
            sub_first++;
            if(sub_first == sub_last) return true;
        }
        first++;
    }
    return false;
}

// sub が v の連続とは限らない部分列かどうか
template <class T> bool is_subseq(const vector<T> &v, const vector<T> &sub) {
    return is_subseq(v.cbegin(), v.cend(), sub.cbegin(), sub.cend());
}
