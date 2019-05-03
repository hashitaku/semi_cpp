/**
 * @file cos.hpp
 * @brief constexpr function cos()
 * @author hashitaku
 * @data 2019/2/12
 */

#ifndef SEMI_CPP_COS_HPP
#define SEMI_CPP_COS_HPP

#include"./fmod.hpp"
#include"./math_const.hpp"

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "cos"
 * @return 三角関数cos(x)をコンパイル時定数で返します
 * @details cos(x) を sin(x + pi/2) で求める
 */
template<typename Type>
constexpr Type cos(Type x){
    x = small_tmp::fmod(x, static_cast<Type>(2) * small_tmp::math_const<Type>::pi);

    return small_tmp::sin(x + (small_tmp::math_const<Type>::pi / static_cast<Type>(2)));
}

}

#endif //SEMI_CPP_COS_HPP
