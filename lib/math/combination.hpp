#pragma once
#include "../core/core.hpp"

template <floating_point Float> class Combination {
    Combination() {}
    Combination(int n) {}

    Float C(int n, int k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;

        if(k > n - k) k = n - k;

        Float ret = 1.0;
        for(int i = 1; i <= k; ++i) {
            ret *= Float(n - i + 1) / Float(i);
        }
        return ret;
    }

    Float P(int n, int k) {
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        Float ret = 1.0;
        for(int i = 0; i < k; ++i) {
            ret *= Float(n - i);
        }
        return ret;
    }

    Float H(int n, int k) {
        if(n == 0 && k == 0) return 1;
        return C(n + k - 1, k);
    }

    Float C_naive(int n, int k) { return C(n, k); }
};

template <class mint> class Combination {
    vector<mint> fac, finv, inv;
    int sz;

public:
    Combination() : fac(), finv(), inv(), sz(0) {}
    Combination(int n) : fac(n + 1), finv(n + 1), inv(n + 1), sz(0) { update_sz(n + 1); }

    mint C(int n, int k) {
        update_sz(n + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * finv[k] * finv[n - k];
    }

    mint P(int n, int k) {
        update_sz(n + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * finv[n - k];
    }

    mint H(int n, int k) {
        if(n == 0 && k == 0) return 1;
        return C(n + k - 1, k);
    }

    // O(k)
    mint C_naive(int n, int k) {
        update_sz(k + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        mint ret = 1;
        for(int i = 0; i < k; i++) {
            ret *= n - i;
            ret *= inv[i + 1];
        }
        return ret;
    }

private:
    void update_sz(int new_sz) {
        if(sz >= new_sz) return;
        if(new_sz < 2) new_sz = 2;
        fac.resize(new_sz);
        finv.resize(new_sz);
        inv.resize(new_sz);
        if(sz == 0) {
            fac[0] = fac[1] = 1;
            finv[0] = finv[1] = 1;
            inv[1] = 1;
            sz = 2;
        }
        for(int i = sz; i < new_sz; i++) {
            fac[i] = fac[i - 1] * i;
            inv[i] = -(inv[mint::mod() % i] * (mint::mod() / i));
            finv[i] = finv[i - 1] * inv[i];
        }
        sz = new_sz;
    }
};
