#pragma once
#include "../core/core.hpp"
namespace std {
template <class T, class U> struct numeric_limits<pair<T, U>> {
    static constexpr bool is_specialized = true;
    static constexpr auto max() { return pair<T, U>(numeric_limits<T>::max(), numeric_limits<U>::max()); }
    static constexpr auto min() { return pair<T, U>(numeric_limits<T>::min(), numeric_limits<U>::min()); }
};

template <typename... Ts> struct numeric_limits<tuple<Ts...>> {
    static constexpr bool is_specialized = true;

    template <size_t... Is> static constexpr auto make_tuple_max(index_sequence<Is...>) {
        return make_tuple(numeric_limits<tuple_element_t<Is, tuple<Ts...>>>::max()...);
    }

    template <size_t... Is> static constexpr auto make_tuple_min(index_sequence<Is...>) {
        return make_tuple(numeric_limits<tuple_element_t<Is, tuple<Ts...>>>::min()...);
    }

    static constexpr auto max() { return make_tuple_max(index_sequence_for<Ts...>{}); }

    static constexpr auto min() { return make_tuple_min(index_sequence_for<Ts...>{}); }
};
};  // namespace std
