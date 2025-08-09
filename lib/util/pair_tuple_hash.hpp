#pragma once
#include "../core/core.hpp"

namespace std {
template <> template <typename T1, typename T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const {
        size_t h1 = hash<T1>()(p.first);
        size_t h2 = hash<T2>()(p.second);
        h1 ^= (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
        return h1 ^ (h1 >> 16) ^ (h1 << 3);
    }
};

template <typename... Args> struct hash<tuple<Args...>> {
    size_t operator()(const tuple<Args...>& t) const { return hash_tuple_impl(t, std::index_sequence_for<Args...>{}); }

private:
    template <typename Tuple, size_t... I> size_t hash_tuple_impl(const Tuple& tpl, std::index_sequence<I...>) const {
        size_t seed = 0;
        (..., (seed ^=
               std::hash<std::tuple_element_t<I, Tuple>>{}(std::get<I>(tpl)) + 0x9e3779b9 + (seed << 6) + (seed >> 2)));
        return seed;
    }
};
}  // namespace std
