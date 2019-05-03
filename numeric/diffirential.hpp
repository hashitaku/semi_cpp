/**
 * @file diffirential.hpp
 * @brief diffirential function
 * @author hashitaku
 * @data 2019/5/4
 */

#ifndef SEMI_CPP_NUMERIC_DIF
#define SEMI_CPP_NUMERIC_DIF

#include<complex>
#include<type_traits>

namespace semi_cpp::numeric{

template<typename Type, typename FuncType>
constexpr auto differential_function(size_t n, Type x, FuncType func, double delta = 0.01){
    if constexpr((std::is_same_v<Type, double> || std::is_same_v<Type, long double>) && (std::is_same_v<std::invoke_result_t<FuncType, Type>, double> || std::is_same_v<std::invoke_result_t<FuncType, Type>, long double>)){
        if(n == 0){
            return func(x);
        }else if(n == 1){
            return (func(x - 2.0 * delta) - 8.0 * func(x - delta) + 8.0 * func(x + delta) - func(x + 2.0 * delta)) / (12.0 * delta);
        }else{
            return (differential_function(n - 1.0, x - 2.0 * delta, func) - 8.0 * differential_function(n - 1.0, x - delta, func) + 8.0 * differential_function(n - 1.0, x + delta, func) - differential_function(n - 1.0, x + 2.0 * delta, func)) / (12.0 * delta);
        }
    }else if constexpr((std::is_same_v<Type, std::complex<double>> || std::is_same_v<Type, std::complex<long double>>) && (std::is_same_v<std::invoke_result_t<FuncType, Type>, std::complex<double>> || std::is_same_v<std::invoke_result_t<FuncType, Type>, std::complex<long double>>)){
        auto delta_x = delta * x;
        if(n == 0){
            return func(x);
        }else if(n == 1){
            return (func(x - 2.0 * delta_x) - 8.0 * func(x - delta_x) + 8.0 * func(x + delta_x) - func(x + 2.0 * delta_x)) / (12.0 * delta_x);
        }else{
            return (differential_function(n - 1.0, x - 2.0 * delta_x, func) - 8.0 * differential_function(n - 1.0, x - delta_x, func) + 8.0 * differential_function(n - 1.0, x + delta_x, func) - differential_function(n - 1.0, x + 2.0 * delta_x, func)) / (12.0 * delta_x);
        }
    }else{
        static_assert([](){ return false; }(), "function differential_function() only 'double' 'long double' 'std::complex<double>' 'std::complaex<long double>'");
    }
}

}

#endif //SEMI_CPP_NUMERIC_DIF
