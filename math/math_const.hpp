/**
 * @file math_const.hpp
 * @brief mathematical constant
 * @author hashitaku
 * @data 2019/1/28
 */

#ifndef SEMI_CPP_MATH_CONST_HPP
#define SEMI_CPP_MATH_CONST_HPP

#include<type_traits>

namespace semi_cpp::math{
/**
 * @struct math_const
 * @brief template struct math_const
 * @details 数学定数を定義 double, float, long doubleの特殊化
 */
template<typename Type = double>
struct math_const;

template<>
struct math_const<float>{
    static constexpr float e           = 2.7182818284590452354f;	/* e */
    static constexpr float log2e       = 1.4426950408889634074f;	/* log_2 e */
    static constexpr float log10e      = 0.43429448190325182765f; /* log_10 e */
    static constexpr float ln2         = 0.69314718055994530942f; /* log_e 2 */
    static constexpr float ln10        = 2.30258509299404568402f; /* log_e 10 */
    static constexpr float pi          = 3.14159265358979323846f; /* pi */
    static constexpr float pi_2        = 1.57079632679489661923f; /* pi/2 */
    static constexpr float pi_4        = 0.78539816339744830962f; /* pi/4 */
    static constexpr float one_pi      = 0.31830988618379067154f; /* 1/pi */
    static constexpr float two_pi      = 0.63661977236758134308f; /* 2/pi */
    static constexpr float two_sqrt_pi = 1.12837916709551257390f; /* 2/sqrt(pi) */
    static constexpr float sqrt_2      = 1.41421356237309504880f; /* sqrt(2) */
    static constexpr float one_sqrt_2  = 0.70710678118654752440f; /* 1/sqrt(2) */
};

template<>
struct math_const<double>{
    static constexpr double e           = 2.7182818284590452354; /* e */
    static constexpr double log2e       = 1.4426950408889634074; /* log_2 e */
    static constexpr double log10e      = 0.43429448190325182765; /* log_10 e */
    static constexpr double ln2         = 0.69314718055994530942; /* log_e 2 */
    static constexpr double ln10        = 2.30258509299404568402; /* log_e 10 */
    static constexpr double pi          = 3.14159265358979323846; /* pi */
    static constexpr double pi_2        = 1.57079632679489661923; /* pi/2 */
    static constexpr double pi_4        = 0.78539816339744830962; /* pi/4 */
    static constexpr double one_pi      = 0.31830988618379067154; /* 1/pi */
    static constexpr double two_pi      = 0.63661977236758134308; /* 2/pi */
    static constexpr double two_sqrt_pi = 1.12837916709551257390; /* 2/sqrt(pi) */
    static constexpr double sqrt_2      = 1.41421356237309504880; /* sqrt(2) */
    static constexpr double one_sqrt_2  = 0.70710678118654752440; /* 1/sqrt(2) */
};

template<>
struct math_const<long double>{
    static constexpr long double e           = 2.718281828459045235360287471352662498L; /* e */
    static constexpr long double log2e       = 1.442695040888963407359924681001892137L; /* log_2 e */
    static constexpr long double log10e      = 0.434294481903251827651128918916605082L; /* log_10 e */
    static constexpr long double ln2         = 0.693147180559945309417232121458176568L; /* log_e 2 */
    static constexpr long double ln10        = 2.302585092994045684017991454684364208L; /* log_e 10 */
    static constexpr long double pi          = 3.141592653589793238462643383279502884L; /* pi */
    static constexpr long double pi_2        = 1.570796326794896619231321691639751442L; /* pi/2 */
    static constexpr long double pi_4        = 0.785398163397448309615660845819875721L; /* pi/4 */
    static constexpr long double one_pi      = 0.318309886183790671537767526745028724L; /* 1/pi */
    static constexpr long double two_pi      = 0.636619772367581343075535053490057448L; /* 2/pi */
    static constexpr long double two_sqrt_pi = 1.128379167095512573896158903121545172L; /* 2/sqrt(pi) */
    static constexpr long double sqrt_2      = 1.414213562373095048801688724209698079L; /* sqrt(2) */
    static constexpr long double one_sqrt_2  = 0.707106781186547524400844362104849039L; /* 1/sqrt(2) */
};

}

#endif //SEMI_CPP_MATH_CONST_HPP
