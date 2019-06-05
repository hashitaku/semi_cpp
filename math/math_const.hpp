/**
 * @file math_const.hpp
 * @brief mathematical constant
 * @author hashitaku
 * @data 2019/1/28
 */

#ifndef SEMI_CPP_MATH_CONST_HPP
#define SEMI_CPP_MATH_CONST_HPP
#include"./exp.hpp"

namespace semi_cpp::math{
/**
 * @struct math_const
 * @brief template struct math_const
 * @details 数学定数を定義
 */
template<typename Type>
struct math_const{
    static constexpr Type e = semi_cpp::math::exp(static_cast<Type>(1));
    static constexpr Type pi = 3.14159265358979323846;
};

}

#endif //SEMI_CPP_MATH_CONST_HPP
