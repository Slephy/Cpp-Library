#pragma once
#include "../core/core.hpp"

// std::merge と基本的に同じ
// ただし [first1, last1) と [first2, last2) がそれぞれソート済みであることを仮定しない
// より広い用途で使えるが、merge後の配列がソート済みであることは保証されない
// O(N + M)

// 出力イテレータ版
template <class InputIterator1, class InputIterator2, class OutputIterator, class Compare>
constexpr OutputIterator custom_merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
                                      InputIterator2 last2, OutputIterator result, Compare cmp) {
    while(first1 != last1 && first2 != last2) {
        if(cmp(*first1, *first2)) {
            *result = *first1;
            ++first1;
        }
        else {
            *result = *first2;
            ++first2;
        }
        ++result;
    }

    // 残りの要素をコピー
    result = std::copy(first1, last1, result);
    result = std::copy(first2, last2, result);

    return result;
}

// vector返却版
template <class InputIterator, class Compare>
auto custom_merge(InputIterator first1, InputIterator last1, InputIterator first2, InputIterator last2, Compare cmp) {
    using T = typename iterator_traits<InputIterator>::value_type;

    vector<T> result;
    result.reserve(distance(first1, last1) + distance(first2, last2));

    custom_merge(first1, last1, first2, last2, back_inserter(result), cmp);

    return result;
}
