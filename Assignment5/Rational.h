/*
* Pashchenko Alexey
* st141278@student.spbu.ru
* My project number five
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>

class Rational
{
private:
    int numerator;
    int denominator;

    void reduce();

public:
    Rational(int num = 0, int den = 1);
    Rational(const Rational& other) = default;

    int getNumerator() const;
    int getDenominator() const;

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    Rational operator-() const;

    Rational& operator=(const Rational& other) = default;
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator>=(const Rational& other) const;

    explicit operator double() const;

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);
};

#endif