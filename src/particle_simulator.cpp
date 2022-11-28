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

int give_id(){
    static int id{0};
    return id++;
}

int main(int argc, char **argv)
{
    std::unique_ptr<Simulation_data> sim_data(new Simulation_data_generator(10));
    Physics_engine engine(std::move(sim_data));
    engine.get_simulation_data().print_properties();
    engine.get_simulation_data().print_particles_data();
    // for(int i = 0; i < 10; ++i){
    //     std::cout << engine.type_info(i) << std::endl << std::endl;   
    // }

    return 0;
}