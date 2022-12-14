//
// Created by Inderpal Singh on 11/12/22.
//

#include "HeatSystem.h"
#include <utility>
#include <fstream>

HeatSystem::HeatSystem(std::unique_ptr<Matrix> system, double dt) : system( std::move(system)), dt(dt) {

}

auto HeatSystem::simulate(double tf) -> void {
    time_elapsed = 0.0f;
    std::ofstream outfile;
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

auto HeatSystem::write(std::ofstream &outfile) -> void {
    int x, y;
    x = system->get_width();
    y = system->get_height();
    for (int i = 0; i < y; i+=1) {
        for (int j = 0; j < x; j+=1) {
            outfile << system->get(i, j)<<" ";
        }
        outfile << "\n";
    }
    outfile << "\n" << std::endl;

}
// steady state
// no generation
auto HeatSystem::update() -> void {
    Matrix new_system(system->get_width(),system->get_height());
    for (int i = 1; i < system->get_height()-1; i+=1) {
        for (int j = 1; j < system->get_width()-1;j+=1) {
            double new_temp = gamma * (system->get(i + 1, j) + system->get(i - 1, j) + system->get(i, j + 1)
                                       + system->get(i, j - 1) - (4 * system->get(i, j))) + system->get(i, j);
            new_system.set(i, j, new_temp);
        }
    }
    system.reset(nullptr);
    system = std::make_unique<Matrix>(new_system);
}
