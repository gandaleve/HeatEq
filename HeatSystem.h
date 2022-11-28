//
// Created by Inderpal Singh on 11/12/22.
//

#pragma once
#include <vector>
#include "Matrix.h"

class HeatSystem {
public:
    HeatSystem(std::unique_ptr<Matrix>, double dt);
    auto simulate(double tf) -> void;
private:

    std::unique_ptr<Matrix> system;
    double dt = 0.001;
    double time_elapsed = 0.0f;
    double alpha = 2.0;
    double gamma = (alpha * dt);
    auto write(std::ofstream &outfile) -> void;
    auto update() -> void;
};
