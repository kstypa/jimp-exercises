//
// Created by karol on 4/6/17.
//

#include <iostream>
#include "Matrix.h"

namespace algebra {

    Matrix::Matrix() : matrix_(0) {

    }

    Matrix::Matrix(size_t rows, size_t cols) {

    }

    Matrix::Matrix(const Matrix &matrix) {
        matrix_ = matrix.matrix_;
    }

    Matrix::Matrix(const std::string &str) {

    }

    std::pair<size_t, size_t> Matrix::Size() {
        return std::make_pair(matrix_.size(), matrix_[0].size());
    }

    std::complex<double> Matrix::GetElement(size_t row, size_t col) {
        return matrix_[row][col];
    }

    void Matrix::SetElement(size_t row, size_t col, std::complex<double> value) {
        matrix_[row][col] = value;
    }

    Matrix Matrix::Add(const Matrix &matrix) {
        Matrix m2 = matrix;
        Matrix m3;
        if(this->Size() == m2.Size()){

            for(size_t i = 0; i < matrix_.size(); i++){
                for(size_t j = 0; j < matrix_[i].size(); j++)
                    m3.matrix_[i][j] = this->matrix_[i][j] + matrix.matrix_[i][j];
            }
        }

        return m3;
    }

    Matrix Matrix::Sub(const Matrix &matrix) {
        return Matrix();
    }

    Matrix Matrix::Mul(const Matrix &matrix) {
        return Matrix();
    }

    Matrix Matrix::Pow(int power) {
        return Matrix();
    }

    void Matrix::Print() {
        for(size_t i = 0; i < matrix_.size(); i++){
            for(size_t j = 0; j < matrix_[i].size(); j++)
                std::cout << matrix_[i][j] << std::endl;
        }
    }
}