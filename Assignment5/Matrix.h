#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>

template<typename T>
class Matrix
{
private:
    size_t rows;
    size_t cols;
    std::vector<std::vector<T>> data;

    void checkBounds(size_t row, size_t col) const
    {
        if (row >= rows || col >= cols)
        {
            throw std::out_of_range("Index out of range");
        }
    }

public:
    Matrix(size_t m, size_t n, const T& value = T())
        : rows(m), cols(n), data(m, std::vector<T>(n, value)) {}

    Matrix(const std::vector<std::vector<T>>& vec)
        : rows(vec.size()), cols(vec.empty() ? 0 : vec[0].size()), data(vec)
    {
        for (const auto& row : data)
        {
            if (row.size() != cols)
            {
                throw std::invalid_argument("Rows must have the same length");
            }
        }
    }

    Matrix(std::initializer_list<std::initializer_list<T>> list)
        : rows(list.size()), cols(list.begin()->size())
    {
        data.reserve(rows);
        for (const auto& rowList : list)
        {
            if (rowList.size() != cols)
            {
                throw std::invalid_argument("Rows must have the same length");
            }
            data.emplace_back(rowList);
        }
    }

    Matrix(const Matrix<T>& other)
        : rows(other.rows), cols(other.cols), data(other.data) {}

    Matrix(Matrix<T>&& other) noexcept
        : rows(other.rows), cols(other.cols), data(std::move(other.data))
    {
        other.rows = 0;
        other.cols = 0;
    }

    ~Matrix() = default;

    Matrix<T>& operator=(const Matrix<T>& other)
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    Matrix<T>& operator=(Matrix<T>&& other) noexcept
    {
        if (this != &other)
        {
            rows = other.rows;
            cols = other.cols;
            data = std::move(other.data);
            other.rows = 0;
            other.cols = 0;
        }
        return *this;
    }

    size_t getRows() const
    {
        return rows;
    }
    size_t getCols() const
    {
        return cols;
    }

    T& operator()(size_t row, size_t col)
    {
        checkBounds(row, col);
        return data[row][col];
    }

    const T& operator()(size_t row, size_t col) const
    {
        checkBounds(row, col);
        return data[row][col];
    }

    Matrix<T> operator+(const Matrix<T>& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw std::invalid_argument("Matrixes must have the same size");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw std::invalid_argument("Matrixes must have the same size");
        }

        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                result(i, j) = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) const
    {
        if (cols != other.rows)
        {
            throw std::invalid_argument(
                "Number of columns in first matrix and number of rows in second matrix must be equal");
        }

        Matrix<T> result(rows, other.cols, T());

        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t k = 0; k < cols; ++k)
            {
                const T& aik = data[i][k];
                for (size_t j = 0; j < other.cols; ++j)
                {
                    result(i, j) += aik * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix<T> operator*(const T& scalar) const
    {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                result(i, j) = data[i][j] * scalar;
            }
        }
        return result;
    }

    Matrix<T>& operator+=(const Matrix<T>& other)
    {
        *this = *this + other;
        return *this;
    }

    Matrix<T>& operator-=(const Matrix<T>& other)
    {
        *this = *this - other;
        return *this;
    }

    Matrix<T>& operator*=(const T& scalar)
    {
        *this = *this * scalar;
        return *this;
    }

    // Унарный минус
    Matrix<T> operator-() const
    {
        return *this * T(-1);
    }

    bool operator==(const Matrix<T>& other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            return false;
        }

        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                if (data[i][j] != other.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix<T>& other) const
    {
        return !(*this == other);
    }

    Matrix<T> transpose() const
    {
        Matrix<T> result(cols, rows);
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                result(j, i) = data[i][j];
            }
        }
        return result;
    }

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
{
    for (size_t i = 0; i < matrix.rows; ++i)
    {
        for (size_t j = 0; j < matrix.cols; ++j)
        {
            os << matrix.data[i][j];
            if (j < matrix.cols - 1)
            {
                os << " ";
            }
        }
        if (i < matrix.rows - 1)
        {
            os << "\n";
        }
    }
    return os;
}

template<typename T>
Matrix<T> operator*(const T& scalar, const Matrix<T>& matrix)
{
    return matrix * scalar;
}

#endif