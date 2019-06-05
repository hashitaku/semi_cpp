/**
 * @file log.hpp
 * @brief constexpr function log()
 * @author hashitaku
 * @data 2019/2/15
 */

#ifndef SEMI_CPP_LOG_HPP
#define SEMI_CPP_LOG_HPP

#include<limits>

namespace semi_cpp::math{
/**
 * @brief template constexpr funtion "log"
 * @return 引数 x の e を底とする自然対数を返す。
 * @details log(1 + u) を連分数展開して求める。
 */
template<typename Type>
constexpr Type log(Type x){

    if(x == 1){
        return 0;
    }

    if(x == 0){
        return -std::numeric_limits<Type>::infinity();
    }
        
    if(x < 0){
        return std::numeric_limits<Type>::quiet_NaN();
    }

    x = x - 1; // u = x - 1なので
    int n = 13; //連分数展開の階数 適当な数
    Type retval = static_cast<Type>(0);
    while(n > 0){
        retval = (n * x) / ((n * x / ((2 * n + 1) + retval)) + 2);
        n--;
    }

    return x / (retval + 1);
}

}

#endif //SEMI_CPP_LOG_HPP
