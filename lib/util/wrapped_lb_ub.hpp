#pragma once
#include "../core/core.hpp"

namespace slephy_wrapped_lb_ub {
template <typename Container, typename Key>
concept SupportsStdLowerBound = requires(Container container, Key key) {
    { std::lower_bound(container.begin(), container.end(), key) } -> std::same_as<typename Container::iterator>;
};

template <typename Container, typename Key>
concept HasMemberLowerBound = requires(Container container, Key key) {
    { container.lower_bound(key) } -> std::same_as<typename Container::iterator>;
};

template <typename Container, typename Key>
    requires HasMemberLowerBound<Container, Key>
auto lower_bound_wrap(const Container &container, const Key &key) {
    return container.lower_bound(key);
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> && !HasMemberLowerBound<Container, Key>)
auto lower_bound_wrap(const Container &container, const Key &key) {
    return std::lower_bound(container.begin(), container.end(), key);
}

template <typename Container, typename Key>
    requires HasMemberLowerBound<Container, Key>
auto upper_bound_wrap(const Container &container, const Key &key) {
    return container.upper_bound(key);
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> && !HasMemberLowerBound<Container, Key>)
auto upper_bound_wrap(const Container &container, const Key &key) {
    return std::upper_bound(container.begin(), container.end(), key);
}
}  // namespace slephy_wrapped_lb_ub
using namespace slephy_wrapped_lb_ub;
