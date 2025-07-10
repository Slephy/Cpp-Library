#pragma once
#include <ext/pb_ds/assoc_container.hpp>

#include "../core/core.hpp"
using namespace __gnu_pbds;
template <class T, class Compare = std::less<T>>
using gnuSet = tree<T, null_type, Compare, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class U, class Compare = std::less<T>>
using gnuMap = tree<T, U, Compare, rb_tree_tag, tree_order_statistics_node_update>;
