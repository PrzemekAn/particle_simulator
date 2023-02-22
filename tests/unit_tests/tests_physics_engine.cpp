#include "physics_engine.h"
#include "simulation_data_from_file.h"
#include "simulation_data_generator.h"
#include <gtest/gtest.h>


TEST(Physics_engine_Constructor, data_from_file){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));

std::cout << std::endl;
    std::cout << engine.get_simulation_data().properties().m_width << std::endl;
    std::cout << engine.get_simulation_data().properties().m_height << std::endl;
    std::cout << engine.get_simulation_data().properties().m_iterations_per_second << std::endl;

    EXPECT_EQ(engine.get_simulation_data().properties().m_width, 1800);
    EXPECT_EQ(engine.get_simulation_data().properties().m_height, 900);
    EXPECT_EQ(engine.get_simulation_data().properties().m_iterations_per_second, 120);


    std::cout << std::endl;
    for(const Particle_uptr& uptr: engine.get_simulation_data().particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    std::cout << std::endl;

    EXPECT_EQ(engine.get_simulation_data().particles()[0].get()->id(), 0);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->mass(), 16.03);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[0], 127.27);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[1], 563.01);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[0], 3.84);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[1], -9.39);

    EXPECT_EQ(engine.get_simulation_data().particles()[1].get()->id(), 1);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[1].get()->mass(), 10.45);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[1].get()->position()[0], 742.01);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[1].get()->position()[1], 255.67);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[1].get()->speed()[0], 0.01);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[1].get()->speed()[1], 10.44);

    EXPECT_EQ(engine.get_simulation_data().particles()[2].get()->id(), 2);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[2].get()->mass(), 5.12);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[2].get()->position()[0], 888.72);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[2].get()->position()[1], 381.09);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[2].get()->speed()[0], -10.26);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[2].get()->speed()[1], 9.00);
}

TEST(Physics_engine_Constructor, data_generated){
    Physics_engine engine(std::make_unique<Simulation_data_generator>(5));
    std::cout << std::endl;

    std::cout << engine.get_simulation_data().properties().m_width << std::endl;
    std::cout << engine.get_simulation_data().properties().m_height << std::endl;
    std::cout << engine.get_simulation_data().properties().m_iterations_per_second << std::endl;

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

TEST(Physics_engine, run_method){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));

    std::cout << std::endl << "Before run method: " << std::endl;
    for(const Particle_uptr& uptr: engine.get_simulation_data().particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    
    engine.run(0);

    std::cout << std::endl << "After run method: " << std::endl;
    for(const Particle_uptr& uptr: engine.get_simulation_data().particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    std::cout << std::endl;
}

TEST(Physics_engine, run_all_method){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));

    std::cout << std::endl << "Before run_all method: " << std::endl;
    for(const Particle_uptr& uptr: engine.get_simulation_data().particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }

    engine.run_all();

    std::cout << std::endl << "After run_all method: " << std::endl;
    for(const Particle_uptr& uptr: engine.get_simulation_data().particles()){
        std::cout << "Type: " << typeid(*uptr.get()).name() << std::endl;
        std::cout << "ID: " << uptr.get()->id() << std::endl;
        std::cout << "Mass: " << uptr.get()->mass() << std::endl;
        std::cout << "Position: " << uptr.get()->position()[0] << ", " << uptr.get()->position()[1] << std::endl;
        std::cout << "Speed: " << uptr.get()->speed()[0] << ", " << uptr.get()->speed()[1] << std::endl << std::endl;
    }
    std::cout << std::endl;
    
    //even more math to do here

    // EXPECT_EQ(engine.get_simulation_data().particles()[0].get()->id(), ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->mass(), ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[0], ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[1], ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[0], ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[1], ?);
}

TEST(Physics_engine, start_simulation_method){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));

    std::cout << "Iterations before simulation: " << engine.get_iteration() << std::endl;
    engine.start_simulation();
    std::cout << "Iterations after simulation: " << engine.get_iteration()<< std::endl;
    
    // EXPECT_EQ(engine.get_simulation_data().particles()[0].get()->id(), ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->mass(), ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[0], ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[1], ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[0], ?);
    // EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[1], ?);
}

TEST(Physics_engine, get_simulation_data_method){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));
   
    EXPECT_EQ(typeid(engine.get_simulation_data()).name(), typeid(Simulation_data_from_file).name());

    EXPECT_EQ(engine.get_simulation_data().particles()[0].get()->id(), 0);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->mass(), 16.03);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[0], 127.27);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->position()[1], 563.01);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[0], 3.84);
    EXPECT_FLOAT_EQ(engine.get_simulation_data().particles()[0].get()->speed()[1], -9.39);
}

TEST(Physics_engine, get_iteration_method){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));

    EXPECT_EQ(typeid(engine.get_iteration()).name(), typeid(int).name());
    EXPECT_EQ(engine.get_iteration(), 0);
}

TEST(Physics_engine, set_iteration_method){
    Physics_engine engine(std::make_unique<Simulation_data_from_file>("./Output_example.json"));

    EXPECT_EQ(engine.get_iteration(), 0);
    engine.set_iteration(20);
    EXPECT_EQ(engine.get_iteration(), 20);
}
