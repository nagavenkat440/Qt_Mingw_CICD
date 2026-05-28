#include <gtest/gtest.h>
#include "calculator.h"

TEST(CalculatorTest, AddTest)
{
    Calculator calc;

    EXPECT_EQ(calc.add(5, 5), 10);
    EXPECT_EQ(calc.add(10, 2), 12);
}