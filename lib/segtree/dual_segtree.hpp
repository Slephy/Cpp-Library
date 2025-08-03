#pragma once
#include "../core/core.hpp"

// ACLの遅延セグ木の実装を改変して双対セグ木にしたもの
// 非可換な作用に対応
// == 変更点 ==
// internal::ceil_pow2 を埋め込み
// add 関数を追加
// size 関数を追加

template <class S, class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> struct dual_segtree {
public:
    dual_segtree() : dual_segtree(0) {}
    explicit dual_segtree(int n) : dual_segtree(vector<S>(n, S{})) {}
    explicit dual_segtree(const vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while((1U << log) < (unsigned int)(_n)) log++;
        _size = 1 << log;
        d = vector<S>(2 * _size);
        lz = vector<F>(_size, id());
        for(int i = 0; i < _n; i++) d[_size + i] = v[i];
    }

    size_t size() const { return _n; }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
    }

    void add(int p, S x) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] += x;
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;

        l += _size;
        r += _size;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }
    }

private:
    int _n, _size, log;
    vector<S> d;
    vector<F> lz;

    void all_apply(int k, F f) {
        if(k >= _size) d[k] = mapping(f, d[k]);
        if(k < _size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};


template <class S, class F> struct RangeSet_PointGet {
    static S mapping(F f, S x) { return (f == id() ? x : f); }
    static F composition(F f, F g) { return (f == id() ? g : f); }
    static F id() { return numeric_limits<F>::max(); }
    using Type = struct dual_segtree<S, F, mapping, composition, id>;
};
template <class S, class F> struct RangeAdd_PointGet {
    static S mapping(F f, S x) { return f + x; }
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; }
    using Type = struct dual_segtree<S, F, mapping, composition, id>;
};
