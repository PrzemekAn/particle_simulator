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


TEST(ParticleCreation, Generator){
    int part_count_for_generator{5};
    std::unique_ptr<Simulation_data> sim_data(new Simulation_data_generator(part_count_for_generator));
    Physics_engine engine(std::move(sim_data));
    long unsigned int part_count {engine.get_simulation_data().particles().size()};
    for(int i = 0; i < part_count; ++i){
        std::cout << engine.type_info(i) << std::endl << std::endl;   
    }
    std::cout << std::endl;
}

TEST(ParticleCreation, FromFile){
    std::unique_ptr<Simulation_data> sim_data_file(new 
    Simulation_data_from_file("./Output_example.json"));
    Physics_engine engine(std::move(sim_data_file));
    long unsigned int part_count {engine.get_simulation_data().particles().size()};
    for(int i = 0; i < part_count; ++i){
        std::cout << engine.type_info(i) << std::endl << std::endl;
    }
    std::cout << std::endl;
}