#include "simulation_data_generator.h"

int give_id();

Simulation_data_generator::Simulation_data_generator(int quantity){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr_type(0, 5);
    std::uniform_real_distribution<> distr_mass(1.0, 20.0);
    std::uniform_real_distribution<> distr_position_x(1.0, 1780.0);
    std::uniform_real_distribution<> distr_position_y(1.0, 880.0);
    std::uniform_real_distribution<> distr_velocity(-10.0, 10.0);
    

    for(int i = 0; i < quantity; i++){
        switch (distr_type(gen))
        {
        case 0:
            m_particles.emplace_back(new Normal(give_id(), distr_mass(gen), {static_cast<float>(distr_position_x(gen)), static_cast<float>(distr_position_y(gen))}, {static_cast<float>(distr_velocity(gen)), static_cast<float>(distr_velocity (gen))}));    
            break;
        case 1:
            m_particles.emplace_back(new Antigravity(give_id(), distr_mass(gen), {static_cast<float>(distr_position_x(gen)), static_cast<float>(distr_position_y(gen))}, {static_cast<float>(distr_velocity(gen)), static_cast<float>(distr_velocity (gen))}));
            break;
        case 2:
            m_particles.emplace_back(new Antimater(give_id(), distr_mass(gen), {static_cast<float>(distr_position_x(gen)), static_cast<float>(distr_position_y(gen))}, {static_cast<float>(distr_velocity(gen)), static_cast<float>(distr_velocity (gen))}));
            break;
        case 3:
            m_particles.emplace_back(new Negative(give_id(), distr_mass(gen), {static_cast<float>(distr_position_x(gen)), static_cast<float>(distr_position_y(gen))}, {static_cast<float>(distr_velocity(gen)), static_cast<float>(distr_velocity (gen))}));
            break;
        case 4:
            m_particles.emplace_back(new Positive(give_id(), distr_mass(gen), {static_cast<float>(distr_position_x(gen)), static_cast<float>(distr_position_y(gen))}, {static_cast<float>(distr_velocity(gen)), static_cast<float>(distr_velocity (gen))}));
            break;
        case 5:
            m_particles.emplace_back(new Split(give_id(), distr_mass(gen), {static_cast<float>(distr_position_x(gen)), static_cast<float>(distr_position_y(gen))}, {static_cast<float>(distr_velocity(gen)), static_cast<float>(distr_velocity (gen))}));
            break;
        default:
            break;
        }
    }
}

Simulation_data_generator::~Simulation_data_generator() = default;