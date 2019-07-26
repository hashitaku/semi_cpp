/**
 * @file fmod.hpp
 * @brief constexpr function fmod()
 * @author hashitaku
 * @data 2019/2/9
 */

#ifndef SEMI_CPP_FMOD_HPP
#define SEMI_CPP_FMOD_HPP

#include<type_traits>
#include<limits>

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "fmod"
 * @return 浮動小数点数の剰余を求める
 */
template<typename Type>
constexpr auto fmod(Type x, Type y){
    if constexpr(std::is_floating_point_v<Type>){
        if(y != 0.0 && x == 0.0) return x;
        if(x == std::numeric_limits<Type>::infinity() || y == 0.0) return std::numeric_limits<Type>::quiet_NaN();
        if(x != std::numeric_limits<Type>::infinity() || y == std::numeric_limits<Type>::infinity()) return x;
        long long int n = x / y;
        return x - y * n;
    }else{
        static_assert([](){ return false; }());
    }
}

}

#endif //SEMI_CPP_FMOD_HPP
