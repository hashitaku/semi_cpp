#include<gtest/gtest.h>

#include"../math/exp.hpp"
#include"../math/math_const.hpp"
#include<cmath>
#include<limits>

TEST(TestExp, TestZero){
    constexpr auto val = semi_cpp::math::exp(0.0);

    ASSERT_DOUBLE_EQ(val, 1.0);
}

TEST(TestExp, TestMinusInf){
    constexpr auto val = semi_cpp::math::exp(-std::numeric_limits<double>::infinity());

    ASSERT_DOUBLE_EQ(val, 0.0);
}

TEST(TestExp, TestPlusInf){
    constexpr auto val = semi_cpp::math::exp(std::numeric_limits<double>::infinity());

    ASSERT_DOUBLE_EQ(val, std::numeric_limits<double>::infinity());
}

TEST(TestExp, TestDouble){
    constexpr auto val1 = semi_cpp::math::exp(1.0);
    ASSERT_DOUBLE_EQ(val1, semi_cpp::math::math_const<double>::e);

    constexpr auto val2 = semi_cpp::math::exp(1.5);
    ASSERT_DOUBLE_EQ(val2, std::exp(1.5));
}
