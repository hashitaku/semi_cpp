/**
 * @file diffirential.hpp
 * @brief diffirential function
 * @author hashitaku
 * @data 2019/5/4
 */

#ifndef SEMI_CPP_NUMERIC_DIF
#define SEMI_CPP_NUMERIC_DIF

#include"./complex.hpp"
#include<type_traits>

namespace semi_cpp::numeric{

template<typename Type, typename FuncType>
constexpr auto differential_function(size_t n, Type x, FuncType func, double delta = 0.01){
    namespace ns = semi_cpp::numeric;
    if constexpr((std::is_floating_point_v<Type> || std::is_same_v<Type, ns::complex<double>> || std::is_same_v<Type, ns::complex<long double>>) &&
                 (std::is_floating_point_v<std::invoke_result_t<FuncType, Type>> || std::is_same_v<std::invoke_result_t<FuncType, Type>, ns::complex<double>> || std::is_same_v<std::invoke_result_t<FuncType, Type>, ns::complex<long double>>)){
        auto delta_x = delta * x;
        if(n == 0){
            return func(x);
        }else if(n == 1){
            return (func(x - 2.0 * delta_x) - 8.0 * func(x - delta_x) + 8.0 * func(x + delta_x) - func(x + 2.0 * delta_x)) / (12.0 * delta_x);
        }else{
            return (differential_function(n - 1.0, x - 2.0 * delta_x, func) - 8.0 * differential_function(n - 1.0, x - delta_x, func) + 8.0 * differential_function(n - 1.0, x + delta_x, func) - differential_function(n - 1.0, x + 2.0 * delta_x, func)) / (12.0 * delta_x);
        }
    }else{
        static_assert([](){ return false; }(), "function differential_function() is only floating points");
    }
}

}

#endif //SEMI_CPP_NUMERIC_DIF
