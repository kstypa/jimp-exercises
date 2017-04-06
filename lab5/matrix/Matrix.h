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
        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements) : matrix_(elements) {
            size_.first = matrix_.size();
            size_.second = matrix_[0].size();
        }
        Matrix(const Matrix &matrix);
        ~Matrix();

        std::pair<size_t, size_t> Size() const;
        std::complex<double> GetElement(size_t row, size_t col) const;
        void SetElement(size_t row, size_t col, std::complex<double> value);

        Matrix Add(const Matrix &matrix) const;
        Matrix Sub(const Matrix &matrix) const;
        Matrix Mul(const Matrix &matrix) const;
        Matrix Pow(int power) const;

        std::string Print() const;

    private:
        std::vector<std::vector<std::complex<double>>> matrix_;
        std::pair<size_t, size_t> size_;
    };
}


#endif //JIMP_EXERCISES_MATRIX_H
