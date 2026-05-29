#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTest, AddTest)
{
    EXPECT_EQ(5, Calculator::add(2, 3));
}

TEST(CalculatorTest, SubtractTest)
{
    EXPECT_EQ(2, Calculator::subtract(5, 3));
}

TEST(CalculatorTest, MultiplyTest)
{
    EXPECT_EQ(15, Calculator::multiply(3, 5));
}

TEST(CalculatorTest, DivideTest)
{
    EXPECT_EQ(5, Calculator::divide(10, 2));
}