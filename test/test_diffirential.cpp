#include<gtest/gtest.h>

#include"../numeric/diffirential.hpp"

TEST(TestDiff, TestOneDiff){
    auto f = [](double x){ return x * x * x + x * x + 2.0 * x; }; // x^3 + x^2 + 2x
    auto df = [](double x){ return 3.0 * x * x + 2.0 * x + 2.0; }; // 3x^2 + 2x + 2
    constexpr auto val = semi_cpp::numeric::differential_function(1, 1.5, f);

    ASSERT_NEAR(val, df(1.5), 1e-10);
    // EXPECT_DOUBLE_EQ(val, df(1.5));
}

TEST(TestDiff, TestZeroDiff){
    auto f = [](double x){ return x * x * x + x * x + 2.0 * x; }; // x^3 + x^2 + 2x
    constexpr auto val = semi_cpp::numeric::differential_function(0, 1.5, f);

    ASSERT_NEAR(val, f(1.5), 1e-10);
}
