#pragma once
#include "../core/core.hpp"
// コンストラクタを呼び出した後にvalの値を変更しても構わないが、変更は反映されない
// STEP 個とばしの累積和を計算する
template <class T> class SkippedPrefixSum {
    vector<T> prefix_sum;
    const int STEP;
    const int SIZE;

    void init_prefix_sum(const vector<T> &val) {
        prefix_sum.resize(val.size() + 1);
        for(int i = 1; i <= val.size(); i++) {
            if(i < STEP) {
                prefix_sum[i] = val[i - 1];
            }
            else {
                prefix_sum[i] = prefix_sum[i - STEP] + val[i - 1];
            }
        }
        return;
    }

public:
    SkippedPrefixSum() {}
    SkippedPrefixSum(const vector<T> &val, int step = 1) : STEP(step), SIZE(val.size()) {
        assert(STEP > 0);
        init_prefix_sum(val);
    }

    // ⚠️ 閉区間 [l, r] であることに注意
    // return sum[l, r] := val[l] + val[l+STEP] + ... + val[r]
    // O(1)
    T get(int l, int r) const {
        assert(0 <= l && l < SIZE);
        assert(0 <= r && r < SIZE);
        assert((r - l) % STEP == 0);
        if(l > r) return T(0);
        int l_ = max(0, l - (STEP - 1));
        int r_ = r + 1;
        return prefix_sum[r_] - prefix_sum[l_];
    }

    // from から STEP 刻みで num 個取った和を返す
    T get2(int from, int num) const { return get(from, from + (num - 1) * STEP); }
};
