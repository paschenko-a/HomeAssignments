/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number five
*/

#include <gtest/gtest.h>
#include "Matrix.h"
#include "Rational.h"

TEST(MatrixTest, RequirementsCheck)
{
    {
        Matrix<int> intMat = {{1, 2}, {3, 4}};
        auto intScaled = intMat * 3;
        EXPECT_EQ(intScaled(0, 0), 3);

        Matrix<double> doubleMat = {{1.5, 2.5}, {3.5, 4.5}};
        auto doubleScaled = doubleMat * 2.0;
        EXPECT_DOUBLE_EQ(doubleScaled(0, 0), 3.0);

        Matrix<Rational> ratMat = {{Rational(1, 2), Rational(1, 3)}};
        auto ratScaled = ratMat * Rational(2, 1);
        EXPECT_EQ(ratScaled(0, 0), Rational(1, 1));
    }

    {
        Matrix<int> intA = {{1, 2}, {3, 4}};
        Matrix<int> intB = {{5, 6}, {7, 8}};
        auto intSum = intA + intB;
        EXPECT_EQ(intSum(0, 0), 6);

        Matrix<double> doubleA = {{1.5, 2.5}};
        Matrix<double> doubleB = {{0.5, 1.0}};
        auto doubleSum = doubleA + doubleB;
        EXPECT_DOUBLE_EQ(doubleSum(0, 0), 2.0);

        Matrix<Rational> ratA = {{Rational(1, 2), Rational(1, 3)}};
        Matrix<Rational> ratB = {{Rational(1, 6), Rational(1, 7)}};
        auto ratSum = ratA + ratB;
        EXPECT_EQ(ratSum(0, 0), Rational(1, 2) + Rational(1, 6));
    }

    {
        Matrix<int> intA = {{1, 2, 3}, {4, 5, 6}};
        Matrix<int> intB = {{7, 8}, {9, 10}, {11, 12}};
        auto intProd = intA * intB;
        EXPECT_EQ(intProd(0, 0), 58);

        Matrix<double> doubleA = {{1.5, 2.5}, {3.5, 4.5}};
        Matrix<double> doubleB = {{0.5, 1.0}, {1.5, 2.0}};
        auto doubleProd = doubleA * doubleB;
        EXPECT_DOUBLE_EQ(doubleProd(0, 0), 1.5*0.5 + 2.5*1.5);

        Matrix<Rational> ratA = {{Rational(1, 2), Rational(1, 3)}};
        Matrix<Rational> ratB = {{Rational(2, 1)}, {Rational(3, 1)}};
        auto ratProd = ratA * ratB;
        EXPECT_EQ(ratProd(0, 0), Rational(1, 2)*Rational(2, 1) + Rational(1, 3)*Rational(3, 1));
    }

    {
        Matrix<int> intMat = {{1, 2, 3}, {4, 5, 6}};
        auto intTrans = intMat.transpose();
        EXPECT_EQ(intTrans.getRows(), 3);
        EXPECT_EQ(intTrans.getCols(), 2);

        Matrix<double> doubleMat = {{1.5, 2.5}, {3.5, 4.5}};
        auto doubleTrans = doubleMat.transpose();
        EXPECT_EQ(doubleTrans.getRows(), 2);

        Matrix<Rational> ratMat = {{Rational(1, 2), Rational(1, 3)}};
        auto ratTrans = ratMat.transpose();
        EXPECT_EQ(ratTrans.getRows(), 2);
    }
}

TEST(ErrorTest, BasicErrors)
{
    Matrix<int> A(2, 3);
    Matrix<int> B(3, 2);
    EXPECT_THROW({ auto r = A + B; }, std::invalid_argument);

    Matrix<int> C(2, 3);
    Matrix<int> D(4, 2);
    EXPECT_THROW({ auto r = C * D; }, std::invalid_argument);

    Matrix<int> M(2, 2);
    EXPECT_THROW({ M(2, 0) = 1; }, std::out_of_range);

    EXPECT_THROW({ Rational r(1, 0); }, std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}