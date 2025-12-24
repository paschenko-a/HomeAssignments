/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number five
*/

#include <gtest/gtest.h>
#include "Matrix.h"
#include "Rational.h"

TEST(MatrixTest, ConstructorsAndAccess)
{
    Matrix<int> m1(2, 3, 5);
    EXPECT_EQ(m1.getRows(), 2);
    EXPECT_EQ(m1.getCols(), 3);
    EXPECT_EQ(m1(0, 0), 5);
    EXPECT_EQ(m1(1, 2), 5);

    Matrix<int> m2 = {{1, 2, 3}, {4, 5, 6}};
    EXPECT_EQ(m2.getRows(), 2);
    EXPECT_EQ(m2.getCols(), 3);
    EXPECT_EQ(m2(0, 0), 1);
    EXPECT_EQ(m2(1, 2), 6);

    Matrix<int> m3 = m2;
    EXPECT_EQ(m3.getRows(), 2);
    EXPECT_EQ(m3.getCols(), 3);
    EXPECT_EQ(m3(0, 0), 1);

    std::vector<std::vector<int>> vec = {{7, 8}, {9, 10}};
    Matrix<int> m4(vec);
    EXPECT_EQ(m4.getRows(), 2);
    EXPECT_EQ(m4.getCols(), 2);
    EXPECT_EQ(m4(1, 1), 10);
}

TEST(MatrixTest, ScalarMultiplication)
{
    Matrix<int> intMat = {{1, 2}, {3, 4}};
    auto intResult = intMat * 3;
    EXPECT_EQ(intResult(0, 0), 3);
    EXPECT_EQ(intResult(0, 1), 6);
    EXPECT_EQ(intResult(1, 0), 9);
    EXPECT_EQ(intResult(1, 1), 12);

    auto intResult2 = 3 * intMat;
    EXPECT_EQ(intResult, intResult2);

    Matrix<double> doubleMat = {{1.5, 2.5}, {3.5, 4.5}};
    auto doubleResult = doubleMat * 2.0;
    EXPECT_DOUBLE_EQ(doubleResult(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(doubleResult(1, 1), 9.0);

    Matrix<Rational> ratMat = {{Rational(1, 2), Rational(1, 3)},
        {Rational(1, 4), Rational(1, 5)}
    };
    auto ratResult = ratMat * Rational(2, 1);
    EXPECT_EQ(ratResult(0, 0), Rational(1, 1));
    EXPECT_EQ(ratResult(0, 1), Rational(2, 3));
}

TEST(MatrixTest, MatrixAddition)
{
    Matrix<int> intA = {{1, 2}, {3, 4}};
    Matrix<int> intB = {{5, 6}, {7, 8}};
    auto intSum = intA + intB;
    EXPECT_EQ(intSum(0, 0), 6);
    EXPECT_EQ(intSum(1, 1), 12);

    auto intSum2 = intB + intA;
    EXPECT_EQ(intSum, intSum2);

    Matrix<double> doubleA = {{1.5, 2.5}, {3.5, 4.5}};
    Matrix<double> doubleB = {{0.5, 1.0}, {1.5, 2.0}};
    auto doubleSum = doubleA + doubleB;
    EXPECT_DOUBLE_EQ(doubleSum(0, 0), 2.0);
    EXPECT_DOUBLE_EQ(doubleSum(1, 1), 6.5);

    Matrix<Rational> ratA = {{Rational(1, 2), Rational(1, 3)},
        {Rational(2, 3), Rational(3, 4)}
    };
    Matrix<Rational> ratB = {{Rational(1, 6), Rational(1, 7)},
        {Rational(1, 8), Rational(1, 9)}
    };
    auto ratSum = ratA + ratB;
    EXPECT_EQ(ratSum(0, 0), Rational(1, 2) + Rational(1, 6));
    EXPECT_EQ(ratSum(1, 1), Rational(3, 4) + Rational(1, 9));
}

TEST(MatrixTest, MatrixMultiplication)
{
    Matrix<int> intA = {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> intB = {{7, 8}, {9, 10}, {11, 12}};
    auto intProduct = intA * intB;

    EXPECT_EQ(intProduct.getRows(), 2);
    EXPECT_EQ(intProduct.getCols(), 2);
    EXPECT_EQ(intProduct(0, 0), 58);
    EXPECT_EQ(intProduct(0, 1), 64);
    EXPECT_EQ(intProduct(1, 0), 139);
    EXPECT_EQ(intProduct(1, 1), 154);

    Matrix<double> doubleA = {{1.5, 2.5}, {3.5, 4.5}};
    Matrix<double> doubleB = {{0.5, 1.0}, {1.5, 2.0}};
    auto doubleProduct = doubleA * doubleB;

    EXPECT_DOUBLE_EQ(doubleProduct(0, 0), 1.5*0.5 + 2.5*1.5);
    EXPECT_DOUBLE_EQ(doubleProduct(0, 1), 1.5*1.0 + 2.5*2.0);
    EXPECT_DOUBLE_EQ(doubleProduct(1, 0), 3.5*0.5 + 4.5*1.5);
    EXPECT_DOUBLE_EQ(doubleProduct(1, 1), 3.5*1.0 + 4.5*2.0);

    Matrix<Rational> ratA = {{Rational(1, 2), Rational(1, 3)},
        {Rational(1, 4), Rational(1, 5)}
    };
    Matrix<Rational> ratB = {{Rational(2, 1), Rational(3, 1)},
        {Rational(4, 1), Rational(5, 1)}
    };
    auto ratProduct = ratA * ratB;

    EXPECT_EQ(ratProduct(0, 0), Rational(7, 3));
    EXPECT_EQ(ratProduct(0, 1), Rational(19, 6));
    EXPECT_EQ(ratProduct(1, 0), Rational(13, 10));
    EXPECT_EQ(ratProduct(1, 1), Rational(7, 4));
}

TEST(MatrixTest, Transposition)
{
    Matrix<int> intMat = {{1, 2, 3}, {4, 5, 6}};
    auto intTrans = intMat.transpose();

    EXPECT_EQ(intTrans.getRows(), 3);
    EXPECT_EQ(intTrans.getCols(), 2);
    EXPECT_EQ(intTrans(0, 0), 1);
    EXPECT_EQ(intTrans(0, 1), 4);
    EXPECT_EQ(intTrans(2, 0), 3);
    EXPECT_EQ(intTrans(2, 1), 6);

    auto intTrans2 = intTrans.transpose();
    EXPECT_EQ(intMat, intTrans2);

    Matrix<double> doubleMat = {{1.5, 2.5}, {3.5, 4.5}, {5.5, 6.5}};
    auto doubleTrans = doubleMat.transpose();

    EXPECT_EQ(doubleTrans.getRows(), 2);
    EXPECT_EQ(doubleTrans.getCols(), 3);
    EXPECT_DOUBLE_EQ(doubleTrans(0, 0), 1.5);
    EXPECT_DOUBLE_EQ(doubleTrans(1, 2), 6.5);

    Matrix<Rational> ratMat = {{Rational(1, 2), Rational(1, 3)},
        {Rational(2, 3), Rational(3, 4)}
    };
    auto ratTrans = ratMat.transpose();

    EXPECT_EQ(ratTrans.getRows(), 2);
    EXPECT_EQ(ratTrans.getCols(), 2);
    EXPECT_EQ(ratTrans(0, 0), Rational(1, 2));
    EXPECT_EQ(ratTrans(1, 1), Rational(3, 4));
}

TEST(MatrixTest, CompoundOperators)
{
    Matrix<int> A = {{1, 2}, {3, 4}};
    Matrix<int> B = {{5, 6}, {7, 8}};

    Matrix<int> C = A;
    C += B;
    EXPECT_EQ(C(0, 0), 6);
    EXPECT_EQ(C(1, 1), 12);

    C -= B;
    EXPECT_EQ(C, A);

    C *= 3;
    EXPECT_EQ(C(0, 0), 3);
    EXPECT_EQ(C(1, 1), 12);

    auto D = -A;
    EXPECT_EQ(D(0, 0), -1);
    EXPECT_EQ(D(1, 1), -4);
}

TEST(MatrixTest, Comparison)
{
    Matrix<int> A = {{1, 2}, {3, 4}};
    Matrix<int> B = {{1, 2}, {3, 4}};
    Matrix<int> C = {{5, 6}, {7, 8}};

    EXPECT_TRUE(A == B);
    EXPECT_FALSE(A == C);
    EXPECT_TRUE(A != C);
    EXPECT_FALSE(A != B);
}

TEST(MatrixTest, ErrorHandling)
{
    Matrix<int> A(2, 3);
    Matrix<int> B(3, 2);
    EXPECT_THROW((void)(A + B), std::invalid_argument);

    Matrix<int> C(2, 3);
    Matrix<int> D(4, 2);
    EXPECT_THROW((void)(C * D), std::invalid_argument);

    Matrix<int> M(2, 2);
    EXPECT_THROW(M(2, 0) = 1, std::out_of_range);
    EXPECT_THROW(M(0, 2) = 1, std::out_of_range);
    EXPECT_THROW(M(2, 2) = 1, std::out_of_range);
}
