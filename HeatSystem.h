//
// Created by Inderpal Singh on 11/12/22.
//

#pragma once
#include <vector>
#include "Matrix.h"

class HeatSystem {
public:
    explicit HeatSystem(Matrix& system);
    HeatSystem(Matrix &system, double dt);
    auto simulate(double tf) -> void;
private:
    Matrix system;
    double dt = 0.001;
    double time_elapsed = 0.0f;

    auto write(std::fstream &outfile) -> void;
    auto update() -> void;
};
