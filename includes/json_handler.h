#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H
#include "particle.h"
#include "simulation_data.h"
#include "simulation_properties.h"
#include <fstream>
#include <vector>
#include <string>


class JSON_handler{
    private:
        Simulation_properties read_header();
        std::vector<Particle_uptr> read_body();

    public:
        JSON_handler(std::string name);
        void save_to_json();
        Simulation_data load_simulation_data();
        ~JSON_handler();
};



#endif
