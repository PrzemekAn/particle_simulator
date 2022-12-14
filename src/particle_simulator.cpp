#include <iostream>
#include "normal.h"
#include "antigravity.h"
#include "positive.h"
#include "negative.h"
#include "split.h"
#include "antimater.h"
#include "physics_engine.h"
#include "simulation_data_base.h"
#include "simulation_data_generator.h"
#include "simulation_data_from_file.h"
#include <typeinfo>

int give_id(){
    static int id{0};
    return id++;
}

double calculate_force(Particle& p1, Particle& p2){
    // const double G = 6.67*10e-11;

    float tmp_x{p1.position()[0] - p2.position()[0]};
    if(tmp_x < 0) tmp_x *= -1;

    float tmp_y{p1.position()[1] - p2.position()[1]};
    if(tmp_y < 0) tmp_x *= -1;

    // float distance{std::sqrt(tmp_x*tmp_x - tmp_y*tmp_y)};
    float distance_squared{tmp_x*tmp_x + tmp_y*tmp_y};

    double F = (p1.mass()*p2.mass()/distance_squared);
    return F;
}

int main(int argc, char **argv)
{
    int part_count {3};
    // std::unique_ptr<Simulation_data> sim_data(new Simulation_data_generator(part_count));
    std::unique_ptr<Simulation_data> sim_data_file(new Simulation_data_from_file("../project_assumptions/Output_example.json"));
    // Physics_engine engine(std::move(sim_data));
    Physics_engine engine(std::move(sim_data_file));
    // engine.get_simulation_data().print_properties();
    engine.get_simulation_data().print_particles_data();
    // for(int i = 0; i < part_count; ++i){
    //     std::cout << engine.type_info(i) << std::endl << std::endl;   
    // }
    // engine.run(0);
    // engine.run_all();
    // engine.start_simulation();
    // engine.get_simulation_data().print_particles_data();
    
    return 0;
}