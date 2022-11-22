#ifndef PHYSICS_ENGINE_H
#define PHYSICS_ENGINE_H
#include "simulation_data_base.h"
#include <memory>

class Physics_engine{
    std::unique_ptr<Simulation_data> m_data;
    int m_current_iteration{0};

    void interact();
    void hit();
    public:
        Physics_engine(std::unique_ptr<Simulation_data> data);
        int run();
        int run_all();
        const Simulation_data& get_simulation_data();
        const int get_iteration();
        void set_iteration(int iteration); // czy potrzebuję tu przyjmować iteracje jako agument?
        bool finished();
        std::string type_info(int index);
        ~Physics_engine();
};

#endif