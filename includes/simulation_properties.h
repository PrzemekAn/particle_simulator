#ifndef SIMULATION_PROPERTIES_H
#define SIMULATION_PROPERTIES_H

class Simulation_properties
{
public:
    int m_height{0};
    int m_width{0};
    int m_iterations_per_second{0};
    Simulation_properties(int height, int width, int iterations);
    ~Simulation_properties();
};

#endif