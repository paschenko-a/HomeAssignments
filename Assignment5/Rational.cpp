#include "Rational.h"
#include <stdexcept>
#include <cmath>
#include <limits>

Rational::Rational(int num, int den) : numerator(num), denominator(den)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    reduce();
}

void Rational::reduce()
{
    if (numerator == 0)
    {
        denominator = 1;
        return;
    }

    int gcd = std::gcd(std::abs(numerator), denominator);

    numerator /= gcd;
    denominator /= gcd;
}

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

Rational Rational::operator+(const Rational& other) const
{
    int new_num = numerator * other.denominator + other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Rational(new_num, new_den);
}

Rational Rational::operator-(const Rational& other) const
{
    int new_num = numerator * other.denominator - other.numerator * denominator;
    int new_den = denominator * other.denominator;
    return Rational(new_num, new_den);
}

Rational Rational::operator*(const Rational& other) const
{
    int new_num = numerator * other.numerator;
    int new_den = denominator * other.denominator;
    return Rational(new_num, new_den);
}

Rational Rational::operator/(const Rational& other) const
{
    if (other.numerator == 0)
    {
        throw std::invalid_argument("Division by zero rational number");
    }

    int new_num = numerator * other.denominator;
    int new_den = denominator * other.numerator;
    return Rational(new_num, new_den);
}

Rational Rational::operator-() const
{
    return Rational(-numerator, denominator);
}

Rational& Rational::operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other)
{
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other)
{
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other)
{
    *this = *this / other;
    return *this;
}

bool Rational::operator==(const Rational& other) const
{
    return (numerator == other.numerator) && (denominator == other.denominator);
}

bool Rational::operator!=(const Rational& other) const
{
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const
{
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Rational::operator<=(const Rational& other) const
{
    return (*this < other) || (*this == other);
}

bool Rational::operator>(const Rational& other) const
{
    return !(*this <= other);
}

bool Rational::operator>=(const Rational& other) const
{
    return !(*this < other);
}

Rational::operator double() const
{
    return static_cast<double>(numerator) / denominator;
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
    if (r.denominator == 1)
    {
        os << r.numerator;
    }
    else
    {
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r)
{
    int num, den = 1;
    char slash = '\0';

    is >> num;

    if (is.peek() == '/')
    {
        is >> slash >> den;
    }

    r = Rational(num, den);
    return is;
}