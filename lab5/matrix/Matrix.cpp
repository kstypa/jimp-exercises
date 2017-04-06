//
// Created by karol on 4/6/17.
//

#include <iostream>
#include "Matrix.h"

using ::std::string;

namespace algebra {

    Matrix::Matrix() {}

    Matrix::Matrix(size_t rows, size_t cols) {
        size_.first = rows;
        size_.second = cols;
    }

    Matrix::Matrix(const Matrix &matrix) {
        size_.first = matrix.size_.first;
        size_.second = matrix.size_.second;
        matrix_ = matrix.matrix_;
    }

    Matrix::~Matrix() {}

    std::pair<size_t, size_t> Matrix::Size() const {
        return size_;
    }

    std::complex<double> Matrix::GetElement(size_t row, size_t col) const {
        return matrix_[row][col];
    }

    void Matrix::SetElement(size_t row, size_t col, std::complex<double> value) {
        matrix_[row][col] = value;
    }

    Matrix Matrix::Add(const Matrix &matrix) const {
        Matrix m3;
        m3.size_.first = size_.first;
        m3.size_.second = size_.second;
        m3.matrix_.resize(m3.size_.first);
        for(size_t i = 0; i < m3.size_.first; i++){
            m3.matrix_[i].resize(m3.size_.second);
        }
            for(size_t i = 0; i < m3.size_.first; i++){
                for(size_t j = 0; j < m3.size_.second; j++)
                    m3.matrix_[i][j] = matrix_[i][j] + matrix.matrix_[i][j];
            }
        return m3;
    }

    Matrix Matrix::Sub(const Matrix &matrix) const {
        Matrix m3;
        m3.size_.first = size_.first;
        m3.size_.second = size_.second;
        m3.matrix_.resize(m3.size_.first);
        for(size_t i = 0; i < m3.size_.first; i++){
            m3.matrix_[i].resize(m3.size_.second);
        }
        for(size_t i = 0; i < m3.size_.first; i++){
            for(size_t j = 0; j < m3.size_.second; j++)
                m3.matrix_[i][j] = matrix_[i][j] - matrix.matrix_[i][j];
        }
        return m3;
    }

    Matrix Matrix::Mul(const Matrix &matrix) const {
        Matrix m3;
        if(size_.second == matrix.size_.first){
            m3.size_.first = size_.first;
            m3.size_.second = matrix.size_.second;
            m3.matrix_.resize(m3.size_.first);
            for(size_t i = 0; i < m3.size_.first; i++){
                m3.matrix_[i].resize(m3.size_.second);
            }
            for(size_t i = 0; i < m3.size_.first; i++){
                for(size_t j = 0; j < m3.size_.second; j++) {
                    m3.matrix_[i][j] = 0;
                    for (size_t k = 0; k < matrix.size_.first; k++)
                        m3.matrix_[i][j] += matrix_[i][k] * matrix.matrix_[k][j];
                }
            }
        }
        return m3;
    }

    Matrix Matrix::Pow(int power) const {
        Matrix m2;
        if(size_.first != size_.second){
            return m2;
        }
        m2.size_.first = size_.first;
        m2.size_.second = size_.second;
        m2.matrix_.resize(m2.size_.first);
        for(size_t i = 0; i < m2.size_.first; i++){
            m2.matrix_[i].resize(m2.size_.second);
        }
        if(power == 0){
            for(int i = 0; i < size_.first; i++)
                m2.matrix_[i][i] = 1;
        }
        else if(power == 1){
            return *this;
        }
        else{
            m2 = *this;
            for(int i = 1; i < power; i++){
                m2 = m2.Mul(*this);
            }
        }

        return m2;
    }

    std::string Matrix::Print() const {
        std::stringstream ss;
        ss << "[";
        for(size_t i = 0; i < size_.first; i++){
            for(size_t j = 0; j < size_.second; j++) {
                ss << matrix_[i][j].real() << "i" << matrix_[i][j].imag();
                if(j < size_.second - 1)
                    ss << ", ";
            }
            if(i < size_.first - 1)
                ss << "; ";
        }
        ss << "]";
        return ss.str();
    }
}