#include "physics_engine.h"


void Physics_engine::interact(){}
void Physics_engine::hit(){}

Physics_engine::Physics_engine(Simulation_data& data): 
    m_data{data}{}

int Physics_engine::run(){
    return 1; //placeholder
}
int Physics_engine::run_all(){
    return 1; //placeholder
}

const Simulation_data Physics_engine::get_simulation_data(){
    return m_data;
}

const int Physics_engine::get_iteration(){
    return m_current_iteration;
}

void Physics_engine::set_iteration(int iteration){
    m_current_iteration = iteration;
}

bool Physics_engine::finished(){
    return true;
}

Physics_engine::~Physics_engine() = default;