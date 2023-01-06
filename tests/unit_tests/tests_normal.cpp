#include "normal.h"
#include "calculate_force.h"
#include <gtest/gtest.h>

TEST(Normal_Constructor, correct_args){
    Normal test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    EXPECT_EQ(test.id(),0);
    EXPECT_EQ(test.mass(),24.5);
    EXPECT_FLOAT_EQ(test.position()[0],14.33);
    EXPECT_FLOAT_EQ(test.position()[1],37.55);
    EXPECT_FLOAT_EQ(test.speed()[0],25.43);
    EXPECT_FLOAT_EQ(test.speed()[1],16.11);
}

TEST(Normal_change_attributes, correct_args){
    Normal test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    Particle_uptr particle(new Normal(1, 14.5, {17.33,27.55}, {15.43,56.11}));
    Simulation_properties properties;

    test.change_attributes(*particle.get(), properties);
    double F = calculate_force(test,*particle.get());

    EXPECT_FLOAT_EQ(test.position()[0],14.33+25.43);
    EXPECT_FLOAT_EQ(test.position()[1],37.55+16.11);
    EXPECT_FLOAT_EQ(test.speed()[0],25.43+(F/test.mass()));
    EXPECT_FLOAT_EQ(test.speed()[1],16.11+(F/test.mass()));
}

TEST(Normal_id, get_id){
    Normal test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    EXPECT_EQ(test.id(), 0);
}

TEST(Normal_mass, get_mass){
    Normal test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    EXPECT_EQ(test.mass(), 24.5);
}

TEST(Normal_position, get_position){
    Normal test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    EXPECT_FLOAT_EQ(test.position()[0], 14.33);
    EXPECT_FLOAT_EQ(test.position()[1], 37.55);
}

TEST(Normal_speed, get_speed){
    Normal test(0, 24.5, {14.33,37.55}, {25.43,16.11});
    EXPECT_FLOAT_EQ(test.speed()[0], 25.43);
    EXPECT_FLOAT_EQ(test.speed()[1], 16.11);
}