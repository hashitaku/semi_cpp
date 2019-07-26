/**
 * @file tan.hpp
 * @brief constexpr function tan()
 * @author hashitaku
 * @data 2019/2/9
 */

#ifndef SEMI_CPP_TAN_HPP
#define SEMI_CPP_TAN_HPP

#include<limits>
#include<type_traits>

#include"./math_const.hpp"
#include"./fmod.hpp"

#include"../numeric/complex.hpp"

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "tan"
 * @return 三角関数tan(x)をコンパイル時定数で返します
 * @details tan(x) を連分数展開して求める
 */
template<typename Type>
constexpr Type tan(Type x){
    if constexpr(std::is_floating_point_v<Type>){
        x = semi_cpp::math::fmod(x, semi_cpp::math::math_const<Type>::pi);

        if(x == Type{} || x == semi_cpp::math::math_const<Type>::pi){
            return Type{};
        }

        if(x == semi_cpp::math::math_const<Type>::pi / 2.0 || x == semi_cpp::math::math_const<Type>::pi / -2.0){
            return std::numeric_limits<Type>::infinity();
        }

        int n = 14; //連分数展開の階数適当な数
        Type retval{};
        while(n > 0){
            retval = (x * x) / ((2.0 * n - 1) - retval);  
            n--;
        }

        return retval / x;
    }else{
        static_assert([](){ return false; }());
    }
}

}

#endif //SEMI_CPP_TAN_HPP
