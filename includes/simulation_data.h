#ifndef SIMULATION_DATA_H
#define SIMULATION_DATA_H
#include <utility>
#include <vector>
#include "simulation_properties.h"
#include "normal.h"

class Simulation_data{
    public:
    Simulation_properties m_properties;
    std::vector<Normal> m_particles;
    Simulation_data(Simulation_properties& properties, std::vector<Normal>& particles);
    ~Simulation_data();
};

#endif