#ifndef SIMULATION_DATA_GENERATOR
#define SIMULATION_DATA_GENERATOR

#include <simulation_data_base.h>

class Simulation_data_generator: public Simulation_data_base{
    public:
        Simulation_data_generator(int quantity);
        ~Simulation_data_generator();
};

#endif