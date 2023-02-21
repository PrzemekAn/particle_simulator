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

TEST(ParticleCreation, FromFile){
    std::unique_ptr<Simulation_data> sim_data_file(new 
    Simulation_data_from_file("./Output_example.json"));

    std::cout << std::endl;
    std::cout << sim_data_file.get()->properties().m_width << std::endl;
    std::cout << sim_data_file.get()->properties().m_height << std::endl;
    std::cout << sim_data_file.get()->properties().m_iterations_per_second << std::endl;

    EXPECT_EQ(sim_data_file.get()->properties().m_width, 1800);
    EXPECT_EQ(sim_data_file.get()->properties().m_height, 900);
    EXPECT_EQ(sim_data_file.get()->properties().m_iterations_per_second, 120);
    std::cout << std::endl;


    for(const Particle_uptr& uptr: sim_data_file.get()->particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    std::cout << std::endl;

    EXPECT_EQ(sim_data_file.get()->particles()[0].get()->id(), 0);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[0].get()->mass(), 16.03);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[0].get()->position()[0], 127.27);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[0].get()->position()[1], 563.01);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[0].get()->speed()[0], 3.84);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[0].get()->speed()[1], -9.39);

    EXPECT_EQ(sim_data_file.get()->particles()[1].get()->id(), 1);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[1].get()->mass(), 10.45);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[1].get()->position()[0], 742.01);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[1].get()->position()[1], 255.67);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[1].get()->speed()[0], 0.01);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[1].get()->speed()[1], 10.44);

    EXPECT_EQ(sim_data_file.get()->particles()[2].get()->id(), 2);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[2].get()->mass(), 5.12);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[2].get()->position()[0], 888.72);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[2].get()->position()[1], 381.09);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[2].get()->speed()[0], -10.26);
    EXPECT_FLOAT_EQ(sim_data_file.get()->particles()[2].get()->speed()[1], 9.00);

}