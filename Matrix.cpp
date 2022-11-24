#include "Matrix.h"

Matrix::Matrix(int m, int n) {
    this->i = m;
    this->j = n;
}

auto Matrix::get_cell(int m, int n) -> Cell {
    return matrix.at(m).at(n);
}

auto Matrix::set_cell(int m, int n, Cell data) -> void {
    matrix.at(m).at(n) = data;
}
