/**
 * @file abs.hpp
 * @brief constexpr function atan()
 * @author hashitaku
 * @data 2019/2/23
 */

#ifndef SEMI_CPP_ATAN_HPP
#define SEMI_CPP_ATAN_HPP

#include<type_traits>

#include"./fmod.hpp"
#include"./math_const.hpp"

namespace semi_cpp::math{

template<typename Type>
constexpr Type atan(Type x){
    if constexpr(std::is_floating_point_v<Type>){
        Type retval{};

        int n = 24; //連分数展開の階数 適当な数

        if(x < -1){
            x = 1 / x;

            while(n > 0){
                retval = ((n * n) * (x * x)) / ((2 * n + 1) + retval);
                n--;
            }

            retval = (-semi_cpp::math::math_const<Type>::pi_2) - (x / (1 + retval));
        }else if(x > 1){
            x = 1 / x;

            while(n > 0){
                retval = ((n * n) * (x * x)) / ((2 * n + 1) + retval);
                n--;
            }

            retval = (semi_cpp::math::math_const<Type>::pi_2) - (x / (1 + retval));
        }else{
            while(n > 0){
                retval = ((n * n) * (x * x)) / ((2 * n + 1) + retval);
                n--;
            }
        
            retval = x / (1 + retval);
        }

        return retval;
    }else{
        static_assert([](){ return false; }());
    }
}

}

#endif //SEMI_CPP_ATAN_HPP
