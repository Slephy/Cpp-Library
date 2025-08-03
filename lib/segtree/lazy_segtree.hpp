#pragma once
#include "../core/core.hpp"

// ACLの実装を一部改変したもの
// == 変更点 ==
// internal::ceil_pow2 を埋め込んだ
// add関数を追加
// size関数を追加
// データの初期化用途で init を渡せるようにした（従来の実装では e で初期化される）

template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)(),
          S (*init)() = e>
struct lazy_segtree {
public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(vector<S>(n, init())) {}
    explicit lazy_segtree(const vector<S>& v) : _n(int(v.size())) {
        log = 0;
        while((1U << log) < (unsigned int)(_n)) log++;
        _size = 1 << log;
        d = vector<S>(2 * _size, e());
        lz = vector<F>(_size, id());
        for(int i = 0; i < _n; i++) d[_size + i] = v[i];
        for(int i = _size - 1; i >= 1; i--) {
            update(i);
        }
    }

    size_t size() const { return _n; }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    void add(int p, S x) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] += x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return e();

        l += _size;
        r += _size;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += _size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for(int i = 1; i <= log; i++) update(p >> i);
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

        for(int i = 1; i <= log; i++) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if(l == _n) return _n;
        l += _size;
        for(int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!g(op(sm, d[l]))) {
                while(l < _size) {
                    push(l);
                    l = (2 * l);
                    if(g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if(r == 0) return 0;
        r += _size;
        for(int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!g(op(d[r], sm))) {
                while(r < _size) {
                    push(r);
                    r = (2 * r + 1);
                    if(g(op(d[r], sm))) {
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

    friend ostream& operator<<(ostream& os, lazy_segtree& seg) {
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
    vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if(k < _size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};


template <class S, class F> struct RangeAdd_RangeMin {
    static S op(S a, S b) { return min(a, b); }
    static S e() { return numeric_limits<S>::max(); }
    static S mapping(F f, S x) { return f + x; }
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; }
    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id>;
};

template <class S, class F> struct RangeAdd_RangeMax {
    static S op(S a, S b) { return max(a, b); }
    static S e() { return numeric_limits<S>::min(); }
    static S mapping(F f, S x) { return f + x; }
    static F composition(F f, F g) { return f + g; }
    static F id() { return 0; }
    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id>;
};

template <class ValType, class F> struct RangeAdd_RangeSum {
    struct S {
        ValType value;
        int size;
    };
    static S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
    static S e() { return {0, 0}; }
    static S mapping(F f, S x) { return {x.value + f * x.size, x.size}; }
    static F composition(F f, F g) { return f + g; }
    static F id() { return numeric_limits<F>::max(); }
    static S init() { return {0, 1}; }
    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id, init>;
};

template <class S, class F> struct RangeSet_RangeMin {
    static S op(S a, S b) { return min(a, b); }
    static S e() { return numeric_limits<S>::max(); }
    static S mapping(F f, S x) { return (f == id() ? x : f); }
    static F composition(F f, F g) { return (f == id() ? g : f); }
    static F id() { return numeric_limits<F>::max(); }
    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id>;
};

template <class S, class F> struct RangeSet_RangeMax {
    static S op(S a, S b) { return max(a, b); }
    static S e() { return numeric_limits<S>::min(); }
    static S mapping(F f, S x) { return (f == id() ? x : f); }
    static F composition(F f, F g) { return (f == id() ? g : f); }
    static F id() { return numeric_limits<F>::max(); }
    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id>;
};

template <class ValType, class F> struct RangeSet_RangeSum {
    struct S {
        ValType value;
        int size;
    };
    static S op(S a, S b) { return {a.value + b.value, a.size + b.size}; }
    static S e() { return {0, 0}; }
    static S mapping(F f, S x) {
        if(f != id()) x.value = x.size * f;
        return x;
    }
    static F composition(F f, F g) { return (f == id() ? g : f); }
    static F id() { return numeric_limits<F>::max(); }
    static S init() { return {0, 1}; }
    using Type = struct lazy_segtree<S, op, e, F, mapping, composition, id, init>;
};
