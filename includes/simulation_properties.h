#ifndef SIMULATION_PROPERTIES_H
#define SIMULATION_PROPERTIES_H

class Simulation_properties
{
public:
    int m_height;
    int m_width;
    int m_iterations_per_second;
    Simulation_properties(int height, int width, int iterations);
    // Simulation_properties(Simulation_properties & other);
    ~Simulation_properties();
};

#endif