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

    std::cout << std::endl;

    for(const Particle_uptr& uptr: engine.get_simulation_data().particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    std::cout << std::endl;
}