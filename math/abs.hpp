/**
 * @file abs.hpp
 * @brief constexpr function abs()
 * @author hashitaku
 * @data 2019/2/4
 */

#ifndef SEMI_CPP_ABS_HPP
#define SEMI_CPP_ABS_HPP

#include<type_traits>

namespace semi_cpp::math{

/**
 * @brief template constexpr funtion "abs"
 * @return 引数xの絶対値を返す
 */
template<typename Type>
constexpr auto abs(Type x){
    if constexpr(std::is_floating_point_v<Type>){
        return x > 0 ? x : -x;
    }else{
        return x > 0 ? x : -static_cast<uintmax_t>(x);
    }
}

}

#endif //SEMI_CPP_ABS_HPP
