#pragma once
#include "../core/core.hpp"

// ACLの実装を一部改変したもの
// == 変更点 ==
// internal::ceil_pow2 を埋め込み
// add 関数 を追加
// size 関数 を追加
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(vector<S>(n, e())) {}
    explicit segtree(const vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while((1U << log) < (unsigned int)(_n)) log++;
        _size = 1 << log;
        d = vector<S>(2 * _size, e());
        for(int i = 0; i < _n; i++) d[_size + i] = v[i];
        for(int i = _size - 1; i >= 1; i--) {
            update(i);
        }
    }

    size_t size() const { return _n; }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += _size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    void add(int p, S x) {
        assert(0 <= p && p < _n);
        p += _size;
        d[p] += x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + _size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += _size;
        r += _size;

        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if(l == _n) return _n;
        l += _size;
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, d[l]))) {
                while(l < _size) {
                    l = (2 * l);
                    if(f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - _size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if(r == 0) return 0;
        r += _size;
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(d[r], sm))) {
                while(r < _size) {
                    r = (2 * r + 1);
                    if(f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - _size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    friend ostream& operator<<(ostream& os, const segtree& seg) {
        os << "[";
        for(int i = 0; i < seg._n; i++) {
            if(i != 0) os << ", ";
            os << seg.get(i);
        }
        os << "]";
        return os;
    }


private:
    int _n, _size, log;
    vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};


template <class S> struct RangeSum {
    static S op(S l, S r) { return l + r; }
    static S e() { return 0; }
    using Type = struct segtree<S, op, e>;
};
template <class S> struct RangeMin {
    static S op(S l, S r) { return min(l, r); }
    static S e() { return numeric_limits<S>::max(); }
    using Type = struct segtree<S, op, e>;
};
template <class S> struct RangeMax {
    static S op(S l, S r) { return max(l, r); }
    static S e() { return numeric_limits<S>::min(); }
    using Type = struct segtree<S, op, e>;
};
// ex) RangeMin<int>::Type seg(10);
