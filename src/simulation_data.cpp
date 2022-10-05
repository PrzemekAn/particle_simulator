#include "simulation_data.h"

Simulation_data::Simulation_data(Simulation_properties properties, std::vector<Particle_uptr> particles): 
    m_properties{properties},
    m_particles{std::move(particles)}{}

Simulation_data::Simulation_data(Simulation_data&& other): 
    m_particles{std::move(other.m_particles)},
    m_properties{other.m_properties}
{

}

Simulation_data::~Simulation_data() = default;