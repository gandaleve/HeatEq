//
// Created by Inderpal Singh on 11/12/22.
//

#pragma once
#include <vector>
#include "Cell.h"


class Matrix {
public:
    Matrix(int m, int n);
    auto get_cell(int m, int n) -> Cell;
    [[nodiscard]] auto get_width() const -> int{ return n; };
    [[nodiscard]] auto get_height() const -> int{ return m; };
private:
    int m;
    int n;
    std::vector<std::vector<Cell>> matrix;

};
