#ifndef SIMULATION_DATA_H
#define SIMULATION_DATA_H
#include "particle.h"
#include "normal.h"
#include "antigravity.h"
#include "antimater.h"
#include "positive.h"
#include "negative.h"
#include "split.h"
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
        virtual void save_data(const char* file_path) = 0;
        virtual ~Simulation_data();
};

#endif