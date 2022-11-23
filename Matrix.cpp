#include "Matrix.h"

Matrix::Matrix(int m, int n) {
    this->m = m;
    this->n = n;
}

auto Matrix::get_cell(int m, int n) -> Cell {
    return matrix.at(m).at(n);
}