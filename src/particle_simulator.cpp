#include <iostream>
#include "normal.h"
#include "antigravity.h"
#include "positive.h"
#include "negative.h"
#include "split.h"
#include "antimater.h"
#include "physics_engine.h"
#include "simulation_data.h"

int give_id(){
    static int id{0};
    return id++;
}

void particles_creation_tests()
{

    std::vector<float> position{10.3, 11.27};
    std::vector<float> speed{21.58, 41.44};

    Normal normal_test(give_id(), 44.4, position, speed);
    std::cout << "Id: " << normal_test.id() << std::endl;
    std::cout << "Mass: " << normal_test.mass() << std::endl;
    std::cout << "Position: " << normal_test.position()[0] << ", " << normal_test.position()[1] << std::endl;
    std::cout << "Speed: " << normal_test.speed()[0] << ", " << normal_test.speed()[1] << std::endl;

    std::cout << std::endl
              << std::endl;

    Antigravity antigravity_test(give_id(), 55.5, position, speed);
    std::cout << "Id: " << antigravity_test.id() << std::endl;
    std::cout << "Mass: " << antigravity_test.mass() << std::endl;
    std::cout << "Position: " << antigravity_test.position()[0] << ", " << antigravity_test.position()[1] << std::endl;
    std::cout << "Speed: " << antigravity_test.speed()[0] << ", " << antigravity_test.speed()[1] << std::endl;

    std::cout << std::endl
              << std::endl;

    Antimater antimater_test(give_id(), 44.6, position, speed);
    std::cout << "Id: " << antimater_test.id() << std::endl;
    std::cout << "Mass: " << antimater_test.mass() << std::endl;
    std::cout << "Position: " << antimater_test.position()[0] << ", " << antimater_test.position()[1] << std::endl;
    std::cout << "Speed: " << antimater_test.speed()[0] << ", " << antimater_test.speed()[1] << std::endl;
}

int main(int argc, char **argv)
{
    std::unique_ptr<Simulation_data> sim_data(new Simulation_data_base(10));
    // sim_data.get()->print_properties();
    // sim_data.get()->print_particles_data();
    Physics_engine engine(std::move(sim_data));
    engine.get_simulation_data().print_properties();
    engine.get_simulation_data().print_particles_data();
    // particles_creation_tests();
    return 0;
}