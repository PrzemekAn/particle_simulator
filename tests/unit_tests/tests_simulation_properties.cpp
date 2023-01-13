#include "simulation_properties.h"
#include <gtest/gtest.h>


TEST(Simulation_properties_Constructor, default_constructor){
    Simulation_properties test;
    EXPECT_EQ(test.m_height, 900);
    EXPECT_EQ(test.m_width, 1800);
    EXPECT_EQ(test.m_iterations_per_second, 120);
}

TEST(Simulation_properties_Constructor, value_constructor){
    Simulation_properties test {1,2,3};
    EXPECT_EQ(test.m_height, 1);
    EXPECT_EQ(test.m_width, 2);
    EXPECT_EQ(test.m_iterations_per_second, 3);
}

TEST(Simulation_properties_Constructor, copy_constructor){
    Simulation_properties test1 {1,2,3};
    Simulation_properties test2(test1);
    EXPECT_EQ(test2.m_height, 1);
    EXPECT_EQ(test2.m_width, 2);
    EXPECT_EQ(test2.m_iterations_per_second, 3);
}

TEST(Simulation_properties_Constructor, move_constructor){
    Simulation_properties test1 {1,2,3};
    Simulation_properties test2(std::move(test1));
    EXPECT_EQ(test2.m_height, 1);
    EXPECT_EQ(test2.m_width, 2);
    EXPECT_EQ(test2.m_iterations_per_second, 3);
}