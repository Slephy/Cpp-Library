#pragma once

template <class mint> class Combination {
    vector<mint> fac, finv, inv;
    int sz;

public:
    mint COM(int n, int k) {
        update_sz(n + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * finv[k] * finv[n - k];
    }

    mint PER(int n, int k) {
        update_sz(n + 1);
        if(n < k) return 0;
        if(n < 0 || k < 0) return 0;
        return fac[n] * finv[n - k];
    }

    mint HCOM(int n, int k) {
        if(n == 0 && k == 0) return 1;
        return COM(n + k - 1, k);
    }

    // O(k), k <= N_MAX
    mint COM_small_k(int n, int k) {
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
