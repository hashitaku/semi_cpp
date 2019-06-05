/**
 * @file sin.hpp
 * @brief constexpr function sin()
 * @author hashitaku
 * @data 2019/2/12
 */

#ifndef SEMI_CPP_SIN_HPP
#define SEMI_CPP_SIN_HPP

#include"./tan.hpp"
#include"./fmod.hpp"

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "sin"
 * @return 三角関数sin(x)をコンパイル時定数で返します
 * @details sin(x) を 2tan(x/2) / (1 + tan^2(x/2)) で求める
 */
template<typename Type>
 constexpr Type sin(Type x){
    using semi_cpp::math::tan;

    x = semi_cpp::math::fmod(x, static_cast<Type>(2) * semi_cpp::math::math_const<Type>::pi);
        
    if(x == static_cast<Type>(0) || x == semi_cpp::math::math_const<Type>::pi){
        return static_cast<Type>(0);
    }

    return (2 * tan(x / 2.0)) / (1 + tan(x / 2.0) * tan(x / 2.0));
}

}

#endif //SEMI_CPP_SIN_HPP
