#pragma once
#include "../core/core.hpp"
// マージソート 返り値は転倒数
// O(NlogN)
template <class Iterator> long long merge_sort(Iterator first, Iterator last) {
    using ValType = typename iterator_traits<Iterator>::value_type;
    int n = distance(first, last);
    if(n <= 1) return 0;

    Iterator mid = next(first, n / 2);
    long long inv_num = merge_sort(first, mid) + merge_sort(mid, last);
    vector<ValType> tmp(n);

    Iterator itr1 = first, itr2 = mid;
    for(int i = 0; i < n; i++) {
        if(itr1 == mid) {
            tmp[i] = *(itr2++);
        }
        else if(itr2 == last) {
            tmp[i] = *(itr1++);
            inv_num += distance(mid, itr2);
        }
        else {
            if(*itr1 <= *itr2) {
                tmp[i] = *(itr1++);
                inv_num += distance(mid, itr2);
            }
            else {
                tmp[i] = *(itr2++);
            }
        }
    }
    copy(tmp.begin(), tmp.end(), first);
    return inv_num;
}
