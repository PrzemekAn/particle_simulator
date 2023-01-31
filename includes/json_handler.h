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
        Simulation_properties read_header(const char* file_path);
        std::vector<Particle_uptr> read_body(const char* file_path);

    public:
        JSON_handler();
        void save_to_json();
        ~JSON_handler();
};



#endif
