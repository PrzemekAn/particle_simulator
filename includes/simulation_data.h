#ifndef SIMULATION_DATA_H
#define SIMULATION_DATA_H

#include "simulation_properties.h"
#include "particle.h"
#include <vector>
#include <utility>


class Simulation_data{
    private:
    std::vector<Particle_uptr> m_particles;
    Simulation_properties m_properties;

    public:
    Simulation_data(Simulation_properties properties, std::vector<Particle_uptr> particles);
    Simulation_data(Simulation_data&& other);
    ~Simulation_data();
};

#endif