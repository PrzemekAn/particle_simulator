#ifndef SIMULATION_DATA_BASE_H
#define SIMULATION_DATA_BASE_H

// #include "simulation_properties.h"
// #include "particle.h"
#include "simulation_data.h"
#include "JSON_handler.h"
#include <vector>
#include <utility>


class Simulation_data_base: public Simulation_data{
    protected:
    std::vector<Particle_uptr> m_particles;
    Simulation_properties m_properties;

    public:
    Simulation_data_base();
    Simulation_data_base(const char* file_path);
    Simulation_data_base(int quantity);
    Simulation_data_base(Simulation_properties properties, std::vector<Particle_uptr>&& particles);
    Simulation_data_base(Simulation_data_base&& other);
    std::vector<Particle_uptr>& particles();
    const std::vector<Particle_uptr>& particles() const;
    Simulation_properties& properties();
    const Simulation_properties& properties() const;
    void save_data(std::string file_path);
    virtual ~Simulation_data_base();
};

#endif