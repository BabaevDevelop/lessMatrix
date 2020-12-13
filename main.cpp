#include<iostream>
#include "Matrix.h"

using namespace std;

int main() {
    uint32_t rows;
    uint32_t cols;


    cin >> rows >> cols;

    Matrix A(rows, cols);
    cin >> A;

    Matrix B(rows, cols);
    cin >> B;

    cout << A;
    cout << B;

    Matrix C(rows, cols);
    C = A + B;
    cout << C;
    return 0;
}
