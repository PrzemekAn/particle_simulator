#ifndef SIMULATION_DATA_H
#define SIMULATION_DATA_H
#include "particle.h"
#include "normal.h"
#include "simulation_properties.h"
#include "json_handler.h"
#include <vector>
#include <string>

class Simulation_data{
    public:
        virtual std::vector<Particle_uptr>& particles() = 0;
        virtual const std::vector<Particle_uptr>& particles() const = 0;
        virtual Simulation_properties& properties() = 0;
        virtual const Simulation_properties& properties() const = 0;
        virtual void save_data(std::string file_path) = 0;
        virtual void print_properties() = 0;
        virtual void print_particles_data() = 0;
        virtual ~Simulation_data();
};

#endif