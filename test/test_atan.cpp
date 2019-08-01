#include<gtest/gtest.h>

#include<cmath>
#include<limits>

#include"../math/atan.hpp"

TEST(TestAtan, TestZero){
    constexpr auto val = semi_cpp::math::atan(0.0);

    ASSERT_DOUBLE_EQ(val, std::atan(0.0));
}

TEST(TestAtan, TestInf){
    constexpr auto val = semi_cpp::math::atan(std::numeric_limits<double>::infinity());

    ASSERT_DOUBLE_EQ(val, std::atan(std::numeric_limits<double>::infinity()));
}

TEST(TesrAtan, TestDouble){
    constexpr auto val = semi_cpp::math::atan(1.5);

    ASSERT_DOUBLE_EQ(val, std::atan(1.5));
}
