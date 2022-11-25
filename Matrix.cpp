#include "Matrix.h"

Matrix::Matrix(int m, int n) {
    this->i = m;
    this->j = n;
}

auto Matrix::get(int m, int n) -> double {
    return matrix.at(m).at(n);
}

auto Matrix::set(int m, int n, double data) -> void {
    matrix.at(m).at(n) = data;
}
