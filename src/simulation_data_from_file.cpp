#include "simulation_data_from_file.h"


Simulation_data_from_file::Simulation_data_from_file(const char* file_path){
    JSON_handler json_handler;
    m_properties = json_handler.read_header(file_path);
    m_particles = json_handler.read_body(file_path);
};

Simulation_data_from_file::~Simulation_data_from_file() = default;