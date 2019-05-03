/**
 * @file tan.hpp
 * @brief constexpr function tan()
 * @author hashitaku
 * @data 2019/2/9
 */

#ifndef SEMI_CPP_TAN_HPP
#define SEMI_CPP_TAN_HPP

#include"./math_const.hpp"
#include"./fmod.hpp"

#include<limits>

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "tan"
 * @return 三角関数tan(x)をコンパイル時定数で返します
 * @details tan(x) を連分数展開して求める
 */
template<typename Type>
constexpr Type tan(Type x){
    x = small_tmp::fmod(x, small_tmp::math_const<Type>::pi);

    if(x == static_cast<Type>(0) || x == small_tmp::math_const<Type>::pi){
        return static_cast<Type>(0);
    }

    if(x == small_tmp::math_const<Type>::pi / 2.0 || x == small_tmp::math_const<Type>::pi / -2.0){
        return std::numeric_limits<Type>::infinity();
    }

    int n = 12; //連分数展開の階数適当な数
    Type retval = static_cast<Type>(0);
    while(n > 0){
        retval = (x * x) / ((2 * n - 1) - retval);  
        n--;
    }

    return retval / x;
}

}

#endif //SEMI_CPP_TAN_HPP
