/**
 * @file abs.hpp
 * @brief constexpr function abs()
 * @author hashitaku
 * @data 2019/2/4
 */

#ifndef SEMI_CPP_ABS_HPP
#define SEMI_CPP_ABS_HPP

#include<type_traits>
#include<cstdint>

#include"./pow.hpp"

#include"../numeric/complex.hpp"
#include"../numeric/dual_number.hpp"

namespace semi_cpp::math{

/**
 * @brief template constexpr funtion "abs"
 * @return 引数xの絶対値を返す
 * @detail 整数型、浮動小数点型、複素数型、二重数への特殊化
 */
template<typename Type>
constexpr auto abs(Type x){
    if constexpr(std::is_floating_point_v<Type>){
        return x > 0.0 ? x : -x;
    }else if constexpr(std::is_integral_v<Type>){
        return x > 0 ? x : -static_cast<uintmax_t>(x);
    }else if constexpr(SEMI_CPP_COMPLEX_CONCEPT(Type)){
        if(x.real() == 0.0) return semi_cpp::math::abs(x.imag());
        if(x.imag() == 0.0) return semi_cpp::math::abs(x.real());
        if(semi_cpp::math::abs(x.imag()) > semi_cpp::math::abs(x.real())){
            auto t = x.real() / x.imag();
            return semi_cpp::math::abs(x.imag()) * semi_cpp::math::pow(1.0 + t * t, 0.5);
        }else{
            auto t = x.imag() / x.real();
            return semi_cpp::math::abs(x.real()) * semi_cpp::math::pow(1.0 + t * t, 0.5);           
        }
    }else if constexpr(SEMI_CPP_DUAL_NUM_CONCEPT(Type)){ //https://math.stackexchange.com/questions/1052247/what-is-the-magnitude-of-a-dual-number-im-not-finding-information-on-this
        return semi_cpp::math::abs(x.real());
    }else{
        static_assert([](){ return false; }());
    }
}

}

#endif //SEMI_CPP_ABS_HPP
