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
#include <gtest/gtest.h>

// TEST(ParticleCreation, FromFile){
//     std::unique_ptr<Simulation_data> sim_data_file(new 
//     Simulation_data_from_file("./Output_example.json"));
//     Physics_engine engine(std::move(sim_data_file));
//     long unsigned int part_count {engine.get_simulation_data().particles().size()};
//     std::cout << std::endl;
//     engine.get_simulation_data().print_particles_data();
//     std::cout << std::endl;
// }