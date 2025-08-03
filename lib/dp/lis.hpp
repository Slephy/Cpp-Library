#pragma once
#include "../core/core.hpp"
enum class LISType {
    value,  // LISを構成する値を返す
    index,  // LISを構成するインデックスを返す
};

// LISを構成して返す
// O(NlogN)
template <class T> vector<T> LIS(const vector<T> &vec, LISType lisType = LISType::value) {
    if(vec.empty()) return {};
    int n = vec.size();
    vector<T> dp(n, numeric_limits<T>::max());  // 数値型以外で使う場合は、最大値を自分で定義する必要あり
    vector<int> dp_pos(n);                      // 各要素のLISでの位置
    int max_length = 0;                         // LISの長さ
    int end_id = 0;                             // 最後にLISの長さが更新されたときのインデックス

    // LISを計算
    for(int i = 0; i < n; i++) {
        int lb_index = lower_bound(dp.begin(), dp.end(), vec[i]) - dp.begin();
        dp[lb_index] = vec[i];
        dp_pos[i] = lb_index;
        if(chmax(max_length, lb_index + 1)) end_id = i;
    }

    // LISを構築
    vector<T> ret;
    int index = max_length - 1;
    for(int i = end_id; i >= 0; i--) {
        if(dp_pos[i] == index) {
            if(lisType == LISType::value) ret.emplace_back(vec[i]);
            if(lisType == LISType::index) ret.emplace_back(i);
            index--;
            if(index < 0) break;
        }
    }

    reverse(ret.begin(), ret.end());
    return ret;
}
