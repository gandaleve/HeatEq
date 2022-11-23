//
// Created by Inderpal Singh on 11/12/22.
//

#include "HeatSystem.h"
#include <utility>
#include <fstream>

HeatSystem::HeatSystem(Matrix& system ) : system(std::move(system)) {
}

HeatSystem::HeatSystem(Matrix& system, double dt) : system(std::move(system)), dt(dt) {

}

auto HeatSystem::simulate(double tf) -> void {
    time_elapsed = 0.0f;
    std::fstream outfile;
    outfile.open("HeatSystem.txt");

    if (!outfile.is_open())
        throw std::runtime_error("Error! output file not open");

    while(time_elapsed <= tf){
        update();
        write(outfile);
        time_elapsed += dt;
    }
    outfile.close();
}

auto HeatSystem::write(std::fstream &outfile) -> void {
    for (int i = 0; i < system.get_width(); ++i) {
        for (int j = 0; j < system.get_height(); ++j) {
            outfile << system.get_cell(i,j).temp <<"\n";
        }
    }
}
//steady state
// no generation
auto HeatSystem::update() -> void {
    for (int i = 0; i < system.get_width(); ++i) {
        for (int j = 0; j < system.get_height(); ++j) {

        }
    }

}