//
// Created by Andrey on 14.12.2020.
//

#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix:: Matrix(uint32_t rows, uint32_t cols) : rows(rows), cols(cols) {
    data = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
    }
}

Matrix:: Matrix(const Matrix &m) :
        rows(m.rows), cols(m.cols) {
    data = new double *[m.rows];
    for (int i = 0; i < m.rows; ++i) {
        data[i] = new double[m.cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m.data[i][j];
        }
    }
}

Matrix:: ~Matrix() {
    if (data){
        for (int i = 0; i < rows; ++i) {
            delete[]data[i];
        }
        delete []data;
        data = nullptr;
    }
}


ostream &operator<<(ostream &out, const Matrix &m) {

    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            out << m.data[i][j] << ' ';
        }
        out << '\n';
    }

    return out;
}

istream &operator>>(istream &in, const Matrix &m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            in >> m.data[i][j];
        }
    }
    return in;
}

Matrix operator+(const Matrix &a, const Matrix &b) {
    Matrix result(a.rows, a.cols);
    for (int i = 0; i < a.rows; ++i) {
        for (int j = 0; j < a.cols; ++j) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix:: operator=(const Matrix &m){
    if (this == &m){
        return *this;
    }
    if (data){
        for (int i = 0; i < rows; ++i) {
            delete[]data[i];
        }
        delete []data;
        data = nullptr;
    }
    rows = m.rows;
    cols = m.cols;
    data = new double *[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m.data[i][j];
        }
    }



    return *this;
}