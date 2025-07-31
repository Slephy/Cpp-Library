#pragma once
#include "../core/core.hpp"
// インターフェースは 0-indexed 半開区間
template <class T> class BIT {
private:
    int n;
    vector<T> bit;

public:
    // constructor
    BIT(int n) : n(n), bit(n + 1, 0) {}

    // O(logN)
    void add(int index, T value) {
        index++;
        assert(1 <= index && index <= n);
        for(int i = index; i <= n; i += (i & (-i))) {
            bit[i] += value;
        }
        return;
    }

    // O(logN)
    void set(int index, T value) {
        add(index, value - get(index));
        return;
    }

    // O(logN)
    // return value of val[index]
    T get(int index) const { return sum(index, index + 1); }

    // O(logN)
    // return sum of val[l, r)
    T sum(int l, int r) const { return _sum(r) - _sum(l); }
    T sum(int l) const { return sum(l, n); }

    size_t size() const { return n; }

    friend ostream &operator<<(ostream &o, const BIT<T> &bit) {
        for(int i = 0; i < bit.n; i++) {
            o << bit.sum(i, i + 1) << (i + 1 == bit.n ? ELM_SEP : " ");
        }
        return o;
    }

private:
    // O(logN)
    // return sum of val[0, index)
    T _sum(int index) const {
        T res = 0;
        assert(0 <= index && index <= n);
        for(int i = index; i > 0; i -= (i & (-i))) {
            res += bit[i];
        }
        return res;
    }
};
