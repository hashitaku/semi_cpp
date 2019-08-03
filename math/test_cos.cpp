#include<gtest/gtest.h>

#include"../math/cos.hpp"
#include<cmath>
#include<limits>

TEST(TestCos, TestZero){
    constexpr auto val = semi_cpp::math::cos(0.0);

    ASSERT_DOUBLE_EQ(val, 1.0);
}

TEST(TestCos, TestInf){
    constexpr auto val = semi_cpp::math::cos(std::numeric_limits<double>::infinity());

    ASSERT_EQ(std::isnan(val), true);
}

TEST(TestCos, TestDouble){
    constexpr auto val = semi_cpp::math::cos(1.5);

    ASSERT_DOUBLE_EQ(val, std::cos(1.5));
}
