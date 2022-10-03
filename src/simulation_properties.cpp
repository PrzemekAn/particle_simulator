#include "simulation_properties.h"

Simulation_properties::Simulation_properties(int height, int width, int iterations):
    m_height{height}, 
    m_width{width},
    m_iterations_per_second{iterations}{}

Simulation_properties::~Simulation_properties() = default;