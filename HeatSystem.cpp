//
// Created by Inderpal Singh on 11/12/22.
//

#include "HeatSystem.h"
#include <utility>
#include <fstream>

HeatSystem::HeatSystem(std::unique_ptr<Matrix> system ) : system (std::move(system)) {
}

HeatSystem::HeatSystem(std::unique_ptr<Matrix> system, double dt) : system( std::move(system)), dt(dt) {

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
    for (int i = 0; i < system->get_width(); ++i) {
        for (int j = 0; j < system->get_height(); ++j) {
            outfile << system->get(i, j) << "\n";
        }
    }
}
// steady state
// no generation
auto HeatSystem::update() -> void {
    Matrix new_system(system->get_height(),system->get_width());
    for (int i = 1; i < system->get_width(); i+=1) {
        for (int j = 1; j < system->get_height();j+=1) {
            double new_temp = gamma * (system->get(i + 1, j) + system->get(i - 1, j) + system->get(i, j + 1)
                                       + system->get(i, j - 1) - 4 * system->get(i, j)) + system->get(i, j);
            new_system.set(i, j, new_temp);
        }
    }
    system.reset(nullptr);
    system = std::make_unique<Matrix>(new_system);
}
