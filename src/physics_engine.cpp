#include "physics_engine.h"


void Physics_engine::interact(Particle& p1, Particle& p2){
    //influence particle2 on particle1
    p1.change_attributes(p2, m_data.get()->properties());
}
void Physics_engine::hit(){}

Physics_engine::Physics_engine(std::unique_ptr<Simulation_data> data): 
    m_data{std::move(data)}{}

int Physics_engine::run(int start){
    //interact one particle with all
    int vector_size = m_data.get()->particles().size();
    if(start >= 0 && start < vector_size){
        for(int i = 0; i < vector_size; ++i){
            if(i == start) continue;
            interact(*m_data.get()->particles()[start].get(), *m_data.get()->particles()[i].get());
        }
    }
    return 0;
}
int Physics_engine::run_all(){
    //interact all particles with all
    int vector_size = m_data.get()->particles().size();
    for(int i = 0; i < vector_size; ++i){
        run(i);
    }
    return 0; 
}

void Physics_engine::start_simulation(){
    //TODO: fix the problem of particles going out of the board
    int iterations{m_data.get()->properties().m_iterations_per_second};
    for(int i = 0; i < iterations; ++i){
        run_all();
        m_current_iteration++;
    }
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