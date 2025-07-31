#pragma once
#include "../core/core.hpp"
// ヒストグラムの最大長方形を返す
// h の要素がすべて0以上であることが必要
ll calc_max_rectangle(const vector<ll> &h) {
#ifdef DEBUG
    for(int i = 0; i < h.size(); i++) assert(h[i] >= 0);
#endif
    if(h.empty()) return 0;

    const int n = h.size();
    vector<ll> l(n), r(n);  // 高さ h[i] を広げられるのは最大で [l[i], r[i]) である
    vector<ll> st;
    // l を求める
    for(int i = 0; i < n; i++) {
        while(!st.empty() && h[st.back()] >= h[i]) st.pop_back();
        if(st.empty()) l[i] = 0;
        else l[i] = st.back() + 1;
        st.emplace_back(i);
    }

    st.clear();
    // r を求める
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && h[st.back()] >= h[i]) st.pop_back();
        if(st.empty()) r[i] = n;
        else r[i] = st.back();
        st.emplace_back(i);
    }

    // 答えを求める
    ll ret = 0;
    for(int i = 0; i < n; i++) {
        ll area = h[i] * (r[i] - l[i]);
        chmax(ret, area);
    }
    return ret;
}
