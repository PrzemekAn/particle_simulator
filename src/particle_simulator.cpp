#include <iostream>
#include "normal.h"
#include "antigravity.h"
#include "positive.h"
#include "negative.h"
#include "split.h"
#include "antimater.h"

void particles_creation_tests()
{

    std::vector<float> position{10.3, 11.27};
    std::vector<float> speed{21.58, 41.44};

    Normal normal_test(10, 44.4, position, speed);
    std::cout << "Id: " << normal_test.get_id() << std::endl;
    std::cout << "Mass: " << normal_test.get_mass() << std::endl;
    std::cout << "Position: " << normal_test.get_position()[0] << ", " << normal_test.get_position()[1] << std::endl;
    std::cout << "Speed: " << normal_test.get_speed()[0] << ", " << normal_test.get_speed()[1] << std::endl;

    std::cout << std::endl
              << std::endl;

    Antigravity antigravity_test(10, 55.5, position, speed);
    std::cout << "Id: " << antigravity_test.get_id() << std::endl;
    std::cout << "Mass: " << antigravity_test.get_mass() << std::endl;
    std::cout << "Position: " << antigravity_test.get_position()[0] << ", " << antigravity_test.get_position()[1] << std::endl;
    std::cout << "Speed: " << antigravity_test.get_speed()[0] << ", " << antigravity_test.get_speed()[1] << std::endl;

    std::cout << std::endl
              << std::endl;

    Antimater antimater_test(11, 44.6, position, speed);
    std::cout << "Id: " << antimater_test.get_id() << std::endl;
    std::cout << "Mass: " << antimater_test.get_mass() << std::endl;
    std::cout << "Position: " << antimater_test.get_position()[0] << ", " << antimater_test.get_position()[1] << std::endl;
    std::cout << "Speed: " << antimater_test.get_speed()[0] << ", " << antimater_test.get_speed()[1] << std::endl;
}

int main(int argc, char **argv)
{

    particles_creation_tests();
    return 0;
}