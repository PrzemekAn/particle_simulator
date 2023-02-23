#include "simulation_data_base.h"

int give_id();


Simulation_data_base::Simulation_data_base(){}

// ?????????????
Simulation_data_base::Simulation_data_base(const char* file_path){}

// ?????????????
Simulation_data_base::Simulation_data_base(int quantity){
    for(int i = 0; i < quantity; i++){
        m_particles.emplace_back(new Normal(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));
    }
}

Simulation_data_base::Simulation_data_base(Simulation_properties properties, std::vector<Particle_uptr>&& particles): 
    m_properties{properties},
    m_particles{std::move(particles)}{}

Simulation_data_base::Simulation_data_base(Simulation_data_base&& other): 
    m_particles{std::move(other.m_particles)},
    m_properties{std::move(other.m_properties)}
{
}

std::vector<Particle_uptr>& Simulation_data_base:: particles(){
    return m_particles;
}

const std::vector<Particle_uptr>& Simulation_data_base:: particles() const{
    return m_particles;
}

Simulation_properties& Simulation_data_base:: properties(){
    return m_properties;
}

const Simulation_properties& Simulation_data_base:: properties() const{
    return m_properties;
}

void Simulation_data_base::save_data(const char* file_path){
    //todo
    JSON_handler json_handler;
}


Simulation_data_base::~Simulation_data_base() = default;