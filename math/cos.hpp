/**
 * @file cos.hpp
 * @brief constexpr function cos()
 * @author hashitaku
 * @data 2019/2/12
 */

#ifndef SEMI_CPP_COS_HPP
#define SEMI_CPP_COS_HPP

#include<type_traits>
#include<limits>

#include"./fmod.hpp"
#include"./sin.hpp"
#include"./math_const.hpp"

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "cos"
 * @return 三角関数cos(x)をコンパイル時定数で返します
 * @details cos(x) を sin(x + pi/2) で求める
 */
template<typename Type>
constexpr Type cos(Type x){
    if constexpr(std::is_floating_point_v<Type>){
        if(x == std::numeric_limits<Type>::infinity()) return std::numeric_limits<Type>::quiet_NaN();

        x = semi_cpp::math::fmod(x, static_cast<Type>(2) * semi_cpp::math::math_const<Type>::pi);

        return semi_cpp::math::sin(x + semi_cpp::math::math_const<Type>::pi_2);  
    }else{
        static_assert([](){ return false; }());
    }
}

}

#endif //SEMI_CPP_COS_HPP
