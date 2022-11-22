#include "physics_engine.h"


void Physics_engine::interact(){}
void Physics_engine::hit(){}

Physics_engine::Physics_engine(std::unique_ptr<Simulation_data> data): 
    m_data{std::move(data)}{}

int Physics_engine::run(){
    return 2137; //placeholder
}
int Physics_engine::run_all(){
    return 2137; //placeholder
}

const Simulation_data& Physics_engine::get_simulation_data(){
    return *m_data.get();
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

std::string Physics_engine::type_info(int index){
    return typeid(*get_simulation_data().particles()[index].get()).name();
}

Physics_engine::~Physics_engine() = default;