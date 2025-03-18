#pragma once
#include <cassert>
#include <string>
#include <vector>
using namespace std;

template <class mint> class RollingHash {
    using value_type = decltype(mint().val());
    using u64 = unsigned long long;
    using u128 = __uint128_t;

    static const value_type mod = mint::mod();
    const u128 base;

public:
    RollingHash(const string &s, u128 base, bool use_reverse = false)
        : n(s.size()), hash(n + 1, 0), pow(n + 1, 1), base(base), use_reverse(use_reverse) {
        assert(base <= mod - 1);
        for(int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + s[i];
            pow[i + 1] = pow[i] * base;
        }
        if(use_reverse) {
            rev_hash.resize(n + 1, 0);
            for(int i = n - 1; i >= 0; i--) {
                rev_hash[i] = rev_hash[i + 1] * base + s[i];
            }
        }
    }
    // iteratorを受け取るコンストラクタ
    template <class Iterator>
    RollingHash(const Iterator first, const Iterator last, u128 base, bool use_reverse = false)
        : n(distance(first, last)), hash(n + 1, 0), pow(n + 1, 1), base(base), use_reverse(use_reverse) {
        assert(base <= mod - 1);
        for(int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + *(first + i);
            pow[i + 1] = pow[i] * base;
        }
        if(use_reverse) {
            rev_hash.resize(n + 1, 0);
            for(int i = n - 1; i >= 0; i--) {
                rev_hash[i] = rev_hash[i + 1] * base + *(first + i);
            }
        }
    }

    // O(1)
    // [l, r)のハッシュ値を求める
    value_type get(int l, int r) const {
        mint res = hash[r] - hash[l] * pow[r - l];
        return res.val();
    }
    value_type get(int l) const { return get(l, n); }
    value_type get() const { return hash[n].val(); }

    // O(1)
    // [l, r) の逆向きハッシュ値を求める
    // [l, r) -> s_{r-1}, s_{r-2}, ..., s_l
    value_type get_rev(int l, int r) const {
        mint res = rev_hash[l] - rev_hash[r] * pow[r - l];
        return res.val();
    }
    value_type get_rev(int l) const { return get_rev(l, n); }
    value_type get_rev() const { return rev_hash[0].val(); }


private:
    int n;
    bool use_reverse;
    vector<mint> hash;      // hash[i] := s[0, i)のハッシュ値
    vector<mint> pow;       // pow[i] := base^i
    vector<mint> rev_hash;  // rev_hash[i] := s[i, n)のハッシュ値

public:
    // O(log(min(len1, len2)))
    // s1[from1, from1+len) と s2[from2, from2+len) のマッチング長を求める
    // rev1, rev2 はそれぞれs1, s2を逆向きにするかどうか
    // 例えば rev1 が true のとき、{s1[from1], s1[from-1], ...} が処理対象となる部分文字列である
    friend int matching_length(const RollingHash<mint> &rh1, int from1, bool rev1, const RollingHash<mint> &rh2,
                               int from2, bool rev2) {
        assert(0 <= from1 && from1 < rh1.n);
        assert(0 <= from2 && from2 < rh2.n);

        ll len1 = (!rev1 ? rh1.n - from1 : from1 + 1);
        ll len2 = (!rev2 ? rh2.n - from2 : from2 + 1);

        ll ok = 0;
        ll ng = min(len1, len2) + 1;
        while(abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            ll hash1 = !rev1 ? rh1.get(from1, from1 + mid) : rh1.get_rev(from1 + 1 - mid, from1 + 1);
            ll hash2 = !rev2 ? rh2.get(from2, from2 + mid) : rh2.get_rev(from2 + 1 - mid, from2 + 1);
            if(hash1 == hash2) ok = mid;
            else ng = mid;
        }
        return ok;
    }

    // O(log(min(len1, len2)))
    // s1[from1, from1+len) と s2[from2, from2+len) のマッチング長を求める
    // どちらも逆向きでない場合
    friend int matching_length(const RollingHash<mint> &rh1, int from1, const RollingHash<mint> &rh2, int from2) {
        return matching_length(rh1, from1, false, rh2, from2, false);
    }
};
