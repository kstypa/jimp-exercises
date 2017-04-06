//
// Created by karol on 4/6/17.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H

#include <complex>
#include <vector>

namespace algebra {
    class Matrix {
    public:
        Matrix();
        Matrix(size_t rows, size_t cols);
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) : matrix_(elements) {}
        Matrix(const Matrix &matrix);
        Matrix(const std::string &str);

        std::pair<size_t, size_t> Size();
        std::complex<double> GetElement(size_t row, size_t col);
        void SetElement(size_t row, size_t col, std::complex<double> value);

        Matrix Add(const Matrix &matrix);
        Matrix Sub(const Matrix &matrix);
        Matrix Mul(const Matrix &matrix);
        Matrix Pow(int power);

        void Print();

    private:
        std::vector<std::vector<std::complex<double>>> matrix_;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
