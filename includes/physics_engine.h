#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H
#include "simulation_data_base.h"
#include <memory>

class Physics_engine{
    std::unique_ptr<Simulation_data> m_data;
    int m_current_iteration{0};

    void interact(Particle& p1, Particle& p2);
    void hit();
    public:
        Physics_engine(std::unique_ptr<Simulation_data> data);
        int run(int start);
        int run_all();
        void start_simulation();
        const Simulation_data& get_simulation_data();
        const int get_iteration();
        void set_iteration(int iteration);
        bool finished();
        std::string type_info(int index);
        ~Physics_engine();
};

#endif