/**
 * @file exp.hpp
 * @brief constexpr function exp()
 * @author hashitaku
 * @data 2019/2/15
 */

#ifndef SEMI_CPP_EXP_HPP
#define SEMI_CPP_EXP_HPP

#include<type_traits>
#include<limits>

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "exp"
 * @return e の x 乗を返す。
 * @details e^x を連分数展開する。
 */
template<typename Type>
constexpr Type exp(Type x){
    if constexpr(std::is_floating_point_v<Type>){
        if(x == 0) return Type{1};
        if(x == std::numeric_limits<Type>::infinity()) return std::numeric_limits<Type>::infinity();
        if(x == -std::numeric_limits<Type>::infinity()) return Type{0};

        Type retval = Type{};

        int n = 22; //連分数展開の階数 適当な数
        
        while(n > 0){
            retval = (x * x) / ((4 * n + 2) + retval);
            n--;
        }

        retval += Type{2};

        return (retval + x) / (retval - x);
    }else{
        static_assert([](){ return false; }());
    }
}

}

#endif //SEMI_CPP_EXP_HPP
