#pragma once
#include "../core/core.hpp"
// 参考
// https://mugen1337.hatenablog.com/entry/2020/10/14/134022
// https://rsk0315.hatenablog.com/entry/2020/10/11/125049
// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
enum class RangeSetType {
    NotMergeAdjacent = 0,  // [l, x]と[x, r]を結合しない
    MergeAdjcent = 1,      // [l, x]と[x, r]を結合する
};

template <class T> class RangeSet {
    const RangeSetType rs_type;
    const int OFFSET;
    set<pair<T, T>> st;

public:
    const pair<T, T> npos;
    RangeSet(RangeSetType rs_type = RangeSetType::MergeAdjcent)
        : rs_type(rs_type),
          OFFSET(static_cast<int>(rs_type)),
          npos(numeric_limits<T>::max(), numeric_limits<T>::max()) {
        st.emplace(npos);
        st.emplace(numeric_limits<T>::min(), numeric_limits<T>::min());
    }

    // 閉区間 [l, r] が一つの区間に被覆されているかを返す
    bool covered(T l, T r) {
        assert(l <= r);
        auto itr = prev(st.lower_bound({l + 1, l + 1}));
        return (itr->first <= l && r <= itr->second);
    }

    bool covered(T x) { return covered(x, x); }

    // 閉区間 [l, r] を被覆するような区間が存在するならばそれを返す。存在しないならば npos を返す。
    pair<T, T> covered_by(T l, T r) {
        assert(l <= r);
        auto itr = prev(st.lower_bound({l + 1, l + 1}));
        if(itr->first <= l && r <= itr->second) return *itr;
        else return this->npos;
    }

    pair<T, T> covered_by(T x) { return covered_by(x, x); }

    // 閉区間 [l, r] を挿入し、要素の増加量を返す
    T insert(T l, T r) {
        assert(l <= r);
        auto itr = prev(st.lower_bound({l + 1, l + 1}));
        // ✅ itr->first <= l

        T ret = 0;
        auto update_ret = [&ret](auto itr) -> void { ret -= (itr->second - itr->first + 1); };
        if(itr->second >= r) {  // *itrに完全に含まれているとき
            return 0;
        }
        else if(itr->second + OFFSET >= l) {  // *itrと共通部分を持つとき、merge
            update_ret(itr);
            l = itr->first;
            itr = st.erase(itr);
        }
        else {  // そうでないとき、skip
            itr = next(itr);
        }
        // ✅ itr->first > l

        // *itrが[l, r]に完全に包含されるとき
        while(itr->second <= r) {
            update_ret(itr);
            itr = st.erase(itr);
        }
        // ✅ itr->first >= l && itr->second > r

        if(itr->first <= r + OFFSET) {
            update_ret(itr);
            r = itr->second;
            st.erase(itr);
        }

        st.emplace(l, r);
        ret += r - l + 1;
        return ret;
    }

    T insert(T x) { return insert(x, x); }

    // 閉区間 [l, r] を削除し、要素の減少量を返す
    T erase(T l, T r) {
        assert(l <= r);
        auto itr = prev(st.lower_bound({l + 1, l + 1}));
        // ✅ itr->first <= l

        // *itrに完全に含まれている
        if(r <= itr->second) {
            if(itr->first < l) st.emplace(itr->first, l - 1);
            if(r < itr->second) st.emplace(r + 1, itr->second);
            st.erase(itr);
            return r - l + 1;
        }

        T ret = 0;
        if(l <= itr->second) {
            ret += itr->second - l + 1;
            if(itr->first < l) st.emplace(itr->first, l - 1);
            itr = st.erase(itr);
        }
        else {
            itr = next(itr);
        }
        // ✅ itr->first > l

        while(itr->second <= r) {
            ret += itr->second - itr->first + 1;
            itr = st.erase(itr);
        }

        if(itr->first <= r) {
            ret += r - itr->first + 1;
            if(r < itr->second) st.emplace(r + 1, itr->second);
            st.erase(itr);
        }
        return ret;
    }

    T erase(T x) { return erase(x, x); }

    // 格納されている閉区間の個数を返す
    int size() { return (int)st.size() - 2; }

    // x 以上の値で、どの区間にも含まれない整数のうち最小の整数を返す
    T mex(T x = 0) {
        auto itr = prev(st.lower_bound({x + 1, x + 1}));
        if(x <= itr->second) return itr->second + 1;
        else return x;
    }

    // x, y が同じ閉区間に含まれるかを判定する
    // x, y のいずれかがどの閉区間にも含まれないのであれば false と判定する
    bool same(T x, T y) {
        auto cover_x = covered_by(x);
        auto cover_y = covered_by(y);
        if(cover_x == this->npos || cover_y == this->npos) return false;
        else return (cover_x == cover_y);
    }
};
