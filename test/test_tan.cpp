#include<gtest/gtest.h>

#include<cmath>
#include<limits>
#include"../math/tan.hpp"

TEST(TestTan, TestZero){
    constexpr auto val1 = semi_cpp::math::tan(+0.0);
    ASSERT_DOUBLE_EQ(val1, std::tan(+0.0));

    constexpr auto val2 = semi_cpp::math::tan(-0.0);
    ASSERT_DOUBLE_EQ(val2, std::tan(-0.0));
}

TEST(TestTan, TestInf){
    constexpr auto val = semi_cpp::math::tan(+std::numeric_limits<double>::infinity());

    ASSERT_EQ(std::isnan(val), true);
}

TEST(TestTan, TestDouble){
    constexpr auto val1 = semi_cpp::math::tan(1.5);

    ASSERT_DOUBLE_EQ(val1, std::tan(1.5));
}
