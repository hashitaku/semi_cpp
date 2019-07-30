#include<gtest/gtest.h>

#include"../math/abs.hpp"

TEST(TestAbs, TestInt){
    constexpr auto test_int = semi_cpp::math::abs(-314);
    ASSERT_EQ(test_int, 314);
}

TEST(TestAbs, TestFloat){
    constexpr auto test_float = semi_cpp::math::abs(-3.14);
    ASSERT_FLOAT_EQ(test_float, 3.14f);   
}

TEST(TestAbs, TestDouble){
    constexpr auto test_double = semi_cpp::math::abs(-3.14);
    ASSERT_DOUBLE_EQ(test_double, 3.14);
}
