#pragma once
#include "../core/core.hpp"
#include "wrapped_lb_ub.hpp"

namespace slephy_lt_le_gt_ge {
template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> get_lt(const Container &container, const Key &key) {
    auto it = lower_bound_wrap(container, key);
    if(it == container.begin()) return nullopt;
    return *prev(it);
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> get_le(const Container &container, const Key &key) {
    auto it = upper_bound_wrap(container, key);
    if(it == container.begin()) return nullopt;
    return *prev(it);
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> get_gt(const Container &container, const Key &key) {
    auto it = upper_bound_wrap(container, key);
    if(it == container.end()) return nullopt;
    return *it;
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> get_ge(const Container &container, const Key &key) {
    auto it = lower_bound_wrap(container, key);
    if(it == container.end()) return nullopt;
    return *it;
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> pop_lt(Container &container, const Key &key) {
    auto it = lower_bound_wrap(container, key);
    if(it == container.begin()) return nullopt;
    Key ret = *prev(it);
    container.erase(prev(it));
    return ret;
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> pop_le(Container &container, const Key &key) {
    auto it = upper_bound_wrap(container, key);
    if(it == container.begin()) return nullopt;
    Key ret = *prev(it);
    container.erase(prev(it));
    return ret;
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> pop_gt(Container &container, const Key &key) {
    auto it = upper_bound_wrap(container, key);
    if(it == container.end()) return nullopt;
    Key ret = *it;
    container.erase(it);
    return ret;
}

template <typename Container, typename Key>
    requires(SupportsStdLowerBound<Container, Key> || HasMemberLowerBound<Container, Key>)
optional<Key> pop_ge(Container &container, const Key &key) {
    auto it = lower_bound_wrap(container, key);
    if(it == container.end()) return nullopt;
    Key ret = *it;
    container.erase(it);
    return ret;
}
}  // namespace slephy_lt_le_gt_ge
using namespace slephy_lt_le_gt_ge;
