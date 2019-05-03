/**
 * @file abs.hpp
 * @brief constexpr function atan()
 * @author hashitaku
 * @data 2019/2/23
 */

#ifndef SEMI_CPP_ATAN_HPP
#define SEMI_CPP_ATAN_HPP

#include"./fmod.hpp"
#include"./math_const.hpp"

namespace semi_cpp::math{

template<typename Type>
constexpr Type atan(Type x){
    Type retval = static_cast<Type>(0);

    int n = 24; //連分数展開の階数 適当な数

    if(x < -1){
        x = 1 / x;

        while(n > 0){
            retval = ((n * n) * (x * x)) / ((2 * n + 1) + retval);
            n--;
        }

        retval = (-semi_cpp::math::math_const<Type>::pi / 2.0) - (x / (1 + retval));
    }else if(x > 1){
        x = 1 / x;

        while(n > 0){
            retval = ((n * n) * (x * x)) / ((2 * n + 1) + retval);
            n--;
        }

        retval = (semi_cpp::math::math_const<Type>::pi / 2.0) - (x / (1 + retval));
    }else{
        retval = x / (1 + retval);
    }

    return retval;
}

}

#endif //SEMI_CPP_ATAN_HPP
