/**
 * @file fmod.hpp
 * @brief constexpr function fmod()
 * @author hashitaku
 * @data 2019/2/9
 */

#ifndef SEMI_CPP_FMOD_HPP
#define SEMI_CPP_FMOD_HPP

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "fmod"
 * @return 浮動小数点数の剰余を求める
 */
template<typename Type>
constexpr auto fmod(Type x, Type y){
    long long int n = x / y;
    return x - y * n;
}

/*
TODO:UB踏む可能性あり要修正
*/

}

#endif //SEMI_CPP_FMOD_HPP
