/**
 * @file pow.hpp
 * @brief constexpr function pow()
 * @author hashitaku
 * @data 2019/2/15
 */

#ifndef SEMI_CPP_POW_HPP
#define SEMI_CPP_POW_HPP

#include"./exp.hpp"
#include"./log.hpp"

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "pow"
 * @return a を x 乗した値を返す
 * @details exp(x * log(a)) を計算
 */
template<typename Type>
constexpr Type pow(Type a, Type x){

    if(a == static_cast<Type>(0)) return static_cast<Type>(0);
    if(x == static_cast<Type>(0)) return static_cast<Type>(1);
    //TODO: IEC 60559 https://cpprefjp.github.io/reference/cmath/pow.html

    return semi_cpp::math::exp(x * semi_cpp::math::log(a));
}

}

#endif //SEMI_CPP_POW_HPP
