#include "simulation_data.h"

Simulation_data::Simulation_data(Simulation_properties& properties, std::vector<Normal>& particles): 
    m_properties{properties},
    m_particles{particles}{}

Simulation_data::~Simulation_data() = default;