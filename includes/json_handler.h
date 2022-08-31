#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H
#include <fstream>
#include <normal.h>
#include <vector>
#include <string>
#include "simulation_data.h"

class Simulation_properties;

class JSON_handler{
    private:
        std::fstream m_file;
        Simulation_properties read_header();
        std::vector<Normal> read_body();

    public:
        JSON_handler(std::string name);
        void save_to_json();
        Simulation_data load_simulation_data();
        ~JSON_handler();
};



#endif
