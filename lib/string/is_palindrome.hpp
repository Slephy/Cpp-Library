#pragma once
#include "../core/core.hpp"
bool is_palindrome(const string &s){
    return equal(s.begin(), s.begin()+s.size()/2, s.rbegin());
}

template<class T>
bool is_palindrome(const T &v){
    return equal(v.begin(), v.begin()+v.size()/2, v.rbegin());
}
