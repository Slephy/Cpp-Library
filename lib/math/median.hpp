#pragma once
#include "../core/core.hpp"
// 昇順または降順にソート済みの配列を入力とする
// floor(中央値)を返す
template <class T> T median(const vector<T> &v) {
    static_assert(is_integral<T>::value, "T must be integral");
    // assert(is_sorted(v.begin(), v.end()));

    int n = v.size();
    const T &l = v[n / 2 - 1];
    const T &r = v[n / 2];
    if(n % 2 == 1) return r;
    else if(l > 0 != r > 0) return floor_div(l + r, 2);
    else return l + floor_div(r - l, 2);
}

// 昇順または降順にソート済みの配列を入力とする
template <class T> string median_string(const vector<T> &v) {
    static_assert(is_integral<T>::value, "T must be integral");
    // assert(is_sorted(v.begin(), v.end()));

    int n = v.size();
    const T &l = v[n / 2 - 1];
    const T &r = v[n / 2];
    T mid;
    bool is_odd = false;  // 真の中央値が整数でない場合はtrue
    if(n % 2 == 1) mid = r;
    else if(l > 0 != r > 0) {
        mid = floor_div(l + r, 2);
        is_odd = (l + r) % 2;
    }
    else {
        mid = l + floor_div(r - l, 2);
        is_odd = (r - l) % 2;
    }

    string ret = "";
    if(is_odd) {
        // 真の中央値は mid+0.5 である
        if(mid < 0) {
            mid++;
            mid = abs(mid);
            ret += "-";
        }
        ret += to_string(mid) + (string) ".5";
    }
    else {
        ret += to_string(mid);
    }
    return ret;
}

// 昇順または降順にソート済みの配列を入力とする
template <class T> double median_double(const vector<T> &v) {
    int n = v.size();
    double l = v[n / 2 - 1];
    double r = v[n / 2];
    if(n % 2 == 1) return r;
    else if(l > 0 != r > 0) return (l + r) / 2.;
    else return l - (l - r) / 2.;
}
