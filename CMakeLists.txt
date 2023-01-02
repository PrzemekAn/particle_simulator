cmake_minimum_required(VERSION 3.10)

project(particle_simulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(includes/)


set(SRC   
        src/antigravity.cpp
        src/antimater.cpp
        src/json_handler.cpp
        src/negative.cpp
        src/normal.cpp
        src/particle_simulator.cpp
        src/particle.cpp
        src/physics_engine.cpp
        src/positive.cpp
        src/simulation_data.cpp
        src/simulation_data_base.cpp
        src/simulation_data_from_file.cpp
        src/simulation_data_generator.cpp
        src/simulation_properties.cpp
        src/split.cpp)



find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(particle_simulator_dlib SHARED  ${SRC})
target_link_libraries(particle_simulator_dlib PRIVATE Qt6::Core)

add_library(particle_simulator_slib  ${SRC})
target_link_libraries(particle_simulator_slib PRIVATE Qt6::Core)

# add_executable(particle_simulator  ${SRC})
# target_link_libraries(particle_simulator PRIVATE Qt6::Core)

find_package(GTest REQUIRED)
add_subdirectory(tests/unit_tests) 
include(CTest)

configure_file(./data/Output_example.json ${CMAKE_BINARY_DIR}/Output_example.json)
configure_file(./data/Output_example.json ${CMAKE_BINARY_DIR}/tests/unit_tests/Output_example.json)