#include "simulation_properties.h"

Simulation_properties::Simulation_properties(): 
    m_height{900},
    m_width{1800},
    m_iterations_per_second{120}
    {}

Simulation_properties::Simulation_properties(int height, int width, int iterations):
    m_height{height}, 
    m_width{width},
    m_iterations_per_second{iterations}{}

Simulation_properties::Simulation_properties(const Simulation_properties & other):
    m_height{other.m_height},
    m_width{other.m_width},
    m_iterations_per_second{other.m_iterations_per_second}
{ 
}

Simulation_properties::Simulation_properties(Simulation_properties && other):
    m_height{other.m_height},
    m_width{other.m_width},
    m_iterations_per_second{other.m_iterations_per_second}
{
}


Simulation_properties::~Simulation_properties() = default;