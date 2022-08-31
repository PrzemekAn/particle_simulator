#include <iostream>
#include "normal.h"
#include "antigravity.h"
#include "positive.h"
#include "negative.h"
#include "split.h"
#include "antimater.h"

void particles_creation_tests(){

    std::pair<float,float> position {10.3, 11.27};
    std::pair<float,float> speed {21.58, 41.44};

    Normal normal_test(10, 44.4, position, speed);
    std::cout << normal_test.get_id() << std::endl;
    std::cout << normal_test.get_mass() << std::endl;
    std::cout << normal_test.get_position().first << std::endl;
    std::cout << normal_test.get_position().second << std::endl;
    std::cout << normal_test.get_speed().first << std::endl;
    std::cout << normal_test.get_speed().second << std::endl;

    std::cout << std::endl << std::endl;

    Antigravity antigravity_test(10, 55.5, position, speed);
    std::cout << antigravity_test.get_id() << std::endl;
    std::cout << antigravity_test.get_mass() << std::endl;
    std::cout << antigravity_test.get_position().first << std::endl;
    std::cout << antigravity_test.get_position().second << std::endl;
    std::cout << antigravity_test.get_speed().first << std::endl;
    std::cout << antigravity_test.get_speed().second << std::endl;

}


int main(int argc, char **argv){
    
    particles_creation_tests();
    return 0;
}