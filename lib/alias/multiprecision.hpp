#pragma once
#include "../core/core.hpp"
#include <boost/multiprecision/cpp_int.hpp>
using i128 = boost::multiprecision::int128_t;
using i256 = boost::multiprecision::int256_t;
using i512 = boost::multiprecision::int512_t;
using i1024 = boost::multiprecision::int1024_t;
using iINF = boost::multiprecision::cpp_int;

#include <boost/multiprecision/cpp_dec_float.hpp>
using d30 = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<30>>;
using d50 = boost::multiprecision::cpp_dec_float_50;
using d100 = boost::multiprecision::cpp_dec_float_100;
