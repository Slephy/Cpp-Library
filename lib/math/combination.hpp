#pragma once
#include "../core/core.hpp"

namespace slephy_combination {
template <class Float> class Combination_Float {
    vector<Float> fac_, finv_, inv_;
    const int MAX_SZ = 150;

public:
    Combination_Float() { init_sz(MAX_SZ); }
    Combination_Float(int n) { init_sz(min(n + 1, MAX_SZ)); }

    // O(k)
    Float C(ll n, ll k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;

        if(k > n - k) k = n - k;

        Float ret = 1.0;
        for(int i = 1; i <= k; ++i) {
            ret *= Float(n - i + 1) / Float(i);
        }
        return ret;
    }

    // O(k)
    Float P(ll n, ll k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        Float ret = 1.0;
        for(int i = 0; i < k; ++i) {
            ret *= Float(n - i);
        }
        return ret;
    }

    // O(k)
    Float H(ll n, ll k) {
        if(n == 0 && k == 0) return 1;
        return C(n + k - 1, k);
    }

    // O(k)
    Float C_naive(ll n, ll k) { return C(n, k); }

    Float fac(ll n) { return fac_[n]; }
    Float finv(ll n) { return finv_[n]; }
    Float inv(ll n) { return inv_[n]; }


private:
    void init_sz(ll sz) {
        if(sz < 2) sz = 2;
        fac_.resize(sz);
        finv_.resize(sz);
        inv_.resize(sz);
        fac_[0] = fac_[1] = 1.0;
        finv_[0] = finv_[1] = 1.0;
        inv_[1] = 1.0;
        for(ll i = 2; i < sz; ++i) {
            fac_[i] = fac_[i - 1] * i;
            inv_[i] = 1.0 / i;
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
};

template <class mint> class Combination_Modint {
    vector<mint> fac_, finv_, inv_;
    int sz;

public:
    Combination_Modint() : fac_(), finv_(), inv_(), sz(0) {}
    Combination_Modint(int n) : fac_(n + 1), finv_(n + 1), inv_(n + 1), sz(0) { update_sz(n + 1); }

    mint C(ll n, ll k) {
        update_sz(n + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac_[n] * finv_[k] * finv_[n - k];
    }

    mint P(ll n, ll k) {
        update_sz(n + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac_[n] * finv_[n - k];
    }

    mint H(ll n, ll k) {
        if(n == 0 && k == 0) return 1;
        return C(n + k - 1, k);
    }

    // O(k)
    mint C_naive(ll n, ll k) {
        update_sz(k + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        mint ret = 1;
        for(ll i = 0; i < k; i++) {
            ret *= n - i;
            ret *= inv_[i + 1];
        }
        return ret;
    }

    mint fac(ll n) {
        update_sz(n + 1);
        return fac_[n];
    }
    mint finv(ll n) {
        update_sz(n + 1);
        return finv_[n];
    }
    mint inv(ll n) {
        update_sz(n + 1);
        return inv_[n];
    }

private:
    void update_sz(ll new_sz) {
        if(sz >= new_sz) return;
        if(new_sz < 2) new_sz = 2;
        fac_.resize(new_sz);
        finv_.resize(new_sz);
        inv_.resize(new_sz);
        if(sz == 0) {
            fac_[0] = fac_[1] = 1;
            finv_[0] = finv_[1] = 1;
            inv_[1] = 1;
            sz = 2;
        }
        for(ll i = sz; i < new_sz; i++) {
            fac_[i] = fac_[i - 1] * i;
            inv_[i] = -(inv_[mint::mod() % i] * (mint::mod() / i));
            finv_[i] = finv_[i - 1] * inv_[i];
        }
        sz = new_sz;
    }
};
};  // namespace slephy_combination

template <class T>
using Combination = conditional_t<std::floating_point<T>, slephy_combination::Combination_Float<T>,
                                  slephy_combination::Combination_Modint<T>>;
