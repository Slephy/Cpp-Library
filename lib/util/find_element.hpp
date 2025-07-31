#pragma once
#include "../core/core.hpp"
// コンテナ内 [first, last) に要素valが初めて現れる(もしくは現れない）イテレータを線形探索して返す
// find_first_*が先頭から、find_last_*が末尾から探索する
// 返り値はイテレータ
// 見つからなかった場合はlastを返す
template <class Iterator>
Iterator find_first_itr(const Iterator &first, const Iterator &last,
                        const typename iterator_traits<Iterator>::value_type &val) {
    for(auto itr = first; itr != last; itr++)
        if(*itr == val) return itr;
    return last;
};
template <class Iterator>
Iterator find_first_not_itr(const Iterator &first, const Iterator &last,
                            const typename iterator_traits<Iterator>::value_type &val) {
    for(auto itr = first; itr != last; itr++)
        if(*itr != val) return itr;
    return last;
};
template <class Iterator>
Iterator find_last_itr(const Iterator &first, const Iterator &last,
                       const typename iterator_traits<Iterator>::value_type &val) {
    if(first == last) return last;
    for(auto itr = prev(last);; itr--) {
        if(*itr == val) return itr;
        else if(itr == first) return last;
    }
};
template <class Iterator>
Iterator find_last_not_itr(const Iterator &first, const Iterator &last,
                           const typename iterator_traits<Iterator>::value_type &val) {
    if(first == last) return last;
    for(auto itr = prev(last);; itr--) {
        if(*itr != val) return itr;
        else if(itr == first) return last;
    }
};
template <class Iterator>
Iterator find_first_itr(const Iterator &first, const Iterator &last,
                        const function<bool(typename iterator_traits<Iterator>::value_type)> &func) {
    for(auto itr = first; itr != last; itr++)
        if(func(*itr)) return itr;
    return last;
};
template <class Iterator>
Iterator find_last_itr(const Iterator &first, const Iterator &last,
                       const function<bool(typename iterator_traits<Iterator>::value_type)> &func) {
    if(first == last) return last;
    for(auto itr = prev(last);; itr--) {
        if(func(*itr)) return itr;
        else if(itr == first) return last;
    }
};
