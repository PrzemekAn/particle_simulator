#include "json_handler.h"
#include "simulation_properties.h"
#include <gtest/gtest.h>

TEST(JSON_handler, read_header){
    JSON_handler test_obj;
    Simulation_properties props{test_obj.read_header("./Output_example.json")};
    std::cout << std::endl;
    std::cout << props.m_width << std::endl;
    std::cout << props.m_height << std::endl;
    std::cout << props.m_iterations_per_second << std::endl;

    EXPECT_EQ(props.m_width, 1800);
    EXPECT_EQ(props.m_height, 900);
    EXPECT_EQ(props.m_iterations_per_second, 120);
    std::cout << std::endl;

}

TEST(JSON_handler, read_body){
    JSON_handler test_obj;
    std::vector<Particle_uptr> particles_uptr_vector{test_obj.read_body("./Output_example.json")};

    std::cout << std::endl;
    for(const Particle_uptr& uptr: particles_uptr_vector){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    std::cout << std::endl;

    EXPECT_EQ(particles_uptr_vector[0].get()->id(), 0);
    EXPECT_FLOAT_EQ(particles_uptr_vector[0].get()->mass(), 16.03);
    EXPECT_FLOAT_EQ(particles_uptr_vector[0].get()->position()[0], 127.27);
    EXPECT_FLOAT_EQ(particles_uptr_vector[0].get()->position()[1], 563.01);
    EXPECT_FLOAT_EQ(particles_uptr_vector[0].get()->speed()[0], 3.84);
    EXPECT_FLOAT_EQ(particles_uptr_vector[0].get()->speed()[1], -9.39);

    EXPECT_EQ(particles_uptr_vector[1].get()->id(), 1);
    EXPECT_FLOAT_EQ(particles_uptr_vector[1].get()->mass(), 10.45);
    EXPECT_FLOAT_EQ(particles_uptr_vector[1].get()->position()[0], 742.01);
    EXPECT_FLOAT_EQ(particles_uptr_vector[1].get()->position()[1], 255.67);
    EXPECT_FLOAT_EQ(particles_uptr_vector[1].get()->speed()[0], 0.01);
    EXPECT_FLOAT_EQ(particles_uptr_vector[1].get()->speed()[1], 10.44);

    EXPECT_EQ(particles_uptr_vector[2].get()->id(), 2);
    EXPECT_FLOAT_EQ(particles_uptr_vector[2].get()->mass(), 5.12);
    EXPECT_FLOAT_EQ(particles_uptr_vector[2].get()->position()[0], 888.72);
    EXPECT_FLOAT_EQ(particles_uptr_vector[2].get()->position()[1], 381.09);
    EXPECT_FLOAT_EQ(particles_uptr_vector[2].get()->speed()[0], -10.26);
    EXPECT_FLOAT_EQ(particles_uptr_vector[2].get()->speed()[1], 9.00);

}