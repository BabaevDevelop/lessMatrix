//
// Created by Andrey on 14.12.2020.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>

class Matrix {
private:
    double **data;
    uint32_t rows;
    uint32_t cols;
public:
    Matrix(uint32_t rows, uint32_t cols);

    Matrix(const Matrix &m);

    virtual ~Matrix();

    friend std::ostream &operator<<(std::ostream &out, const Matrix &m);

    friend std::istream &operator>>(std::istream &in, const Matrix &m);

    friend Matrix operator+(const Matrix &a, const Matrix &b);

    Matrix& operator=(const Matrix &m);
};


#endif //MATRIX_MATRIX_H
