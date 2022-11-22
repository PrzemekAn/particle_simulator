#include "simulation_data_generator.h"

int give_id();

Simulation_data_generator::Simulation_data_generator(int quantity){
    enum particles_names{normal, antigravity, antimater, negetive, positive, split};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 5);
    for(int i = 0; i < quantity; i++){
        switch (distr(gen))
        {
        case 0:
            m_particles.emplace_back(new Normal(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));    
            break;
        case 1:
            m_particles.emplace_back(new Antigravity(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));
            break;
        case 2:
            m_particles.emplace_back(new Antimater(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));
            break;
        case 3:
            m_particles.emplace_back(new Negative(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));
            break;
        case 4:
            m_particles.emplace_back(new Positive(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));
            break;
        case 5:
            m_particles.emplace_back(new Split(give_id(), 20, {10.3, 11.27}, {21.58, 41.44}));
            break;
        default:
            break;
        }
    }
}

Simulation_data_generator::~Simulation_data_generator() = default;