/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number five
*/

#include <gtest/gtest.h>
#include "Rational.h"

TEST(RationalTest, ConstructorsAndInvariants)
{
    Rational r1(3, 4);
    EXPECT_EQ(r1.getNumerator(), 3);
    EXPECT_EQ(r1.getDenominator(), 4);

    Rational r2(6, 8);
    EXPECT_EQ(r2.getNumerator(), 3);
    EXPECT_EQ(r2.getDenominator(), 4);

    Rational r3(10, 5);
    EXPECT_EQ(r3.getNumerator(), 2);
    EXPECT_EQ(r3.getDenominator(), 1);

    Rational r4(3, -4);
    EXPECT_EQ(r4.getNumerator(), -3);
    EXPECT_EQ(r4.getDenominator(), 4);

    Rational r5(-3, -4);
    EXPECT_EQ(r5.getNumerator(), 3);
    EXPECT_EQ(r5.getDenominator(), 4);

    Rational r6(0, 5);
    EXPECT_EQ(r6.getNumerator(), 0);
    EXPECT_EQ(r6.getDenominator(), 1);

    Rational r7(5);
    EXPECT_EQ(r7.getNumerator(), 5);
    EXPECT_EQ(r7.getDenominator(), 1);

    Rational r8;
    EXPECT_EQ(r8.getNumerator(), 0);
    EXPECT_EQ(r8.getDenominator(), 1);
}

TEST(RationalTest, Exceptions)
{
    EXPECT_THROW(Rational(1, 0), std::invalid_argument);

    Rational r1(1, 2);
    Rational r2(0, 1);
    EXPECT_THROW(r1 / r2, std::invalid_argument);
}

TEST(RationalTest, ArithmeticOperations)
{
    Rational a(1, 2);
    Rational b(1, 3);

    Rational sum = a + b;
    EXPECT_EQ(sum.getNumerator(), 5);
    EXPECT_EQ(sum.getDenominator(), 6);

    Rational diff = a - b;
    EXPECT_EQ(diff.getNumerator(), 1);
    EXPECT_EQ(diff.getDenominator(), 6);

    Rational prod = a * b;
    EXPECT_EQ(prod.getNumerator(), 1);
    EXPECT_EQ(prod.getDenominator(), 6);

    Rational quot = a / b;
    EXPECT_EQ(quot.getNumerator(), 3);
    EXPECT_EQ(quot.getDenominator(), 2);
}

TEST(RationalTest, CompoundOperators)
{
    Rational a(1, 2);
    Rational b(1, 3);

    Rational c = a;
    c += b;
    EXPECT_EQ(c, Rational(5, 6));

    c -= b;
    EXPECT_EQ(c, a);

    c *= b;
    EXPECT_EQ(c, Rational(1, 6));

    c = a;
    c /= b;
    EXPECT_EQ(c, Rational(3, 2));
}

TEST(RationalTest, UnaryMinus)
{
    Rational a(3, 4);
    Rational b = -a;

    EXPECT_EQ(b.getNumerator(), -3);
    EXPECT_EQ(b.getDenominator(), 4);

    Rational c(-3, 4);
    Rational d = -c;

    EXPECT_EQ(d.getNumerator(), 3);
    EXPECT_EQ(d.getDenominator(), 4);
}

TEST(RationalTest, Comparison)
{
    Rational a(1, 2);
    Rational b(1, 3);
    Rational c(2, 4);

    EXPECT_TRUE(a == c);
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != c);

    EXPECT_TRUE(b < a);
    EXPECT_TRUE(b <= a);
    EXPECT_TRUE(a > b);
    EXPECT_TRUE(a >= b);
    EXPECT_TRUE(a <= c);
    EXPECT_TRUE(a >= c);

    Rational d(-1, 2);
    Rational e(1, 2);
    EXPECT_TRUE(d < e);
    EXPECT_TRUE(d < Rational(0, 1));
}

TEST(RationalTest, InvariantPreservation)
{
    Rational a(2, 4);
    Rational b(2, 6);

    Rational sum = a + b;
    EXPECT_EQ(sum.getNumerator(), 5);
    EXPECT_EQ(sum.getDenominator(), 6);

    Rational prod = a * b;
    EXPECT_EQ(prod.getNumerator(), 1);
    EXPECT_EQ(prod.getDenominator(), 6);

    EXPECT_GT(a.getDenominator(), 0);
    EXPECT_GT(b.getDenominator(), 0);
    EXPECT_GT(sum.getDenominator(), 0);
    EXPECT_GT(prod.getDenominator(), 0);

    Rational c(-3, 4);
    Rational d(2, 5);
    Rational e = c * d;
    EXPECT_GT(e.getDenominator(), 0);
}

TEST(RationalTest, DoubleConversion)
{
    Rational a(1, 2);
    EXPECT_DOUBLE_EQ(static_cast<double>(a), 0.5);

    Rational b(3, 4);
    EXPECT_DOUBLE_EQ(static_cast<double>(b), 0.75);

    Rational c(-2, 5);
    EXPECT_DOUBLE_EQ(static_cast<double>(c), -0.4);

    Rational d(5, 2);
    EXPECT_DOUBLE_EQ(static_cast<double>(d), 2.5);
}

TEST(RationalTest, InputOutput)
{
    {
        std::stringstream ss;
        ss << Rational(3, 4);
        EXPECT_EQ(ss.str(), "3/4");
    }

    {
        std::stringstream ss;
        ss << Rational(5, 1);
        EXPECT_EQ(ss.str(), "5");
    }

    {
        std::stringstream ss;
        ss << Rational(-2, 3);
        EXPECT_EQ(ss.str(), "-2/3");
    }

    {
        std::stringstream ss("7/8");
        Rational r;
        ss >> r;
        EXPECT_EQ(r.getNumerator(), 7);
        EXPECT_EQ(r.getDenominator(), 8);
    }

    {
        std::stringstream ss("9");
        Rational r;
        ss >> r;
        EXPECT_EQ(r.getNumerator(), 9);
        EXPECT_EQ(r.getDenominator(), 1);
    }

    {
        std::stringstream ss("-2/3");
        Rational r;
        ss >> r;
        EXPECT_EQ(r.getNumerator(), -2);
        EXPECT_EQ(r.getDenominator(), 3);
    }
}