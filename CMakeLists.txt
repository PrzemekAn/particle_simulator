cmake_minimum_required(VERSION 3.10)

project(particle_simulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(includes/)

set(SRC   
        src/antigravity.cpp
        src/antimater.cpp
        src/json_handler.cpp
        src/negative.cpp
        src/normal.cpp
        src/particle_generator.cpp
        src/particle_simulator.cpp
        src/particle.cpp
        src/physics_engine.cpp
        src/positive.cpp
        src/simulation_data.cpp
        src/simulation_properties.cpp
        src/split.cpp)




add_executable(particle_simulator ${SRC})
