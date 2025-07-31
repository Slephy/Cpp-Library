#pragma once
#include "../core/core.hpp"
// インターフェイスは 0-indexed 半開区間
template <class T> class BIT2D {
private:
    int H, W;
    vector<vector<T>> bit;

public:
    // constructor
    BIT2D(int H, int W) : H(H), W(W), bit(H + 1, vector<T>(W + 1, 0)) {}

    // O(logH * logW)
    void add(int h, int w, T value) {
        h++;
        w++;
        assert(1 <= h && h <= H);
        assert(1 <= w && w <= W);
        for(int i = h; i <= H; i += (i & (-i))) {
            for(int j = w; j <= W; j += (j & (-j))) {
                bit[i][j] += value;
            }
        }
        return;
    }

    // O(logH * logW)
    void set(int h, int w, T value) {
        add(h, w, value - get(h, w));
        return;
    }

    // O(logH * logW)
    // return value of val[index]
    T get(int h, int w) { return sum(h, w, h + 1, w + 1); }

    // O(logH * logW)
    // return sum of val[l, r)
    T sum(int h1, int w1, int h2, int w2) { return _sum(h2, w2) - _sum(h2, w1) - _sum(h1, w2) + _sum(h1, w1); }
    T sum(int h1, int w1) { return sum(h1, w1, H, W); }

private:
    // O(logH * logW)
    // return sum of val[0, index)
    T _sum(int h, int w) {
        T res = 0;
        assert(0 <= h && h <= H);
        assert(0 <= w && w <= W);
        for(int i = h; i > 0; i -= (i & (-i))) {
            for(int j = w; j > 0; j -= (j & (-j))) {
                res += bit[i][j];
            }
        }
        return res;
    }
};
