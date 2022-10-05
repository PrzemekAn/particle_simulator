#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H
#include "simulation_data.h"

class Physics_engine{
    Simulation_data m_data;
    int m_current_iteration{0};

    void interact();
    void hit();
    public:
        Physics_engine(Simulation_data && data);
        int run();
        int run_all();
        const Simulation_data & get_simulation_data();
        const int get_iteration();
        void set_iteration(int iteration);
        bool finished();
        ~Physics_engine();
};

#endif