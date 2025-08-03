#pragma once
#include "../core/core.hpp"
// Mo's algorithm
// [l, r) の半開区間に対してクエリを処理する
// solveは何度でも呼び出し可能
template <class AnsType> class Mo {
    ll n, q;
    vector<int> l, r;
    vector<int> order;
    int blockSize;

public:
    Mo(ll n, const vector<int> &l, const vector<int> &r)
        : n(n),
          q(l.size()),
          l(l),
          r(r),
          order(q),
          blockSize(max<int>(1, 1.0 * n / max<double>(1.0, sqrt(q * 2.0 / 3.0)))) {
        assert(l.size() == r.size());
        sort_query();
    }

    template <class AddLeft, class AddRight, class DelLeft, class DelRight, class GetAns>
    vector<AnsType> solve(AddLeft &add_left, AddRight &add_right, DelLeft &del_left, DelRight &del_right,
                          GetAns &get_ans) {
        vector<AnsType> ans(q);
        int curL = 0, curR = 0;
        for(int i = 0; i < q; i++) {
            int id = order[i];
            while(curL > l[id]) add_left(--curL);
            while(curR < r[id]) add_right(curR++);
            while(curL < l[id]) del_left(curL++);
            while(curR > r[id]) del_right(--curR);
            ans[id] = get_ans(order[i]);
        }
        return ans;
    }

    // void add(int i) : add i-th element
    // void del(int i) : delete i-th element
    // AnsType get_ans(int j) : return answer of j-th query
    template <class Add, class Del, class GetAns> vector<AnsType> solve(Add &add, Del &del, GetAns &get_ans) {
        return solve(add, add, del, del, get_ans);
    }

private:
    void sort_query() {
        iota(order.begin(), order.end(), 0);
        vector<int> block_id(q);
        for(int i = 0; i < q; i++) block_id[i] = l[i] / blockSize;
        sort(order.begin(), order.end(), [&](int i, int j) {
            if(block_id[i] != block_id[j]) return l[i] < l[j];
            if(block_id[i] % 2 == 0) return r[i] < r[j];
            return r[i] > r[j];
        });
    }
};
