cmake_minimum_required(VERSION 3.10)

project(particle_simulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(includes/)
option(BUILD_TESTS              "Builds all tests (gtest required)"         ON)
option(BUILD_UNIT_TESTS         "Builds unit tests (gtest required)"        ON)
option(BUILD_FUNCTIONAL_TESTS   "Builds funtional tests"                    OFF)

set(SRC   
        src/antigravity.cpp
        src/antimater.cpp
        src/json_handler.cpp
        src/negative.cpp
        src/normal.cpp
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
target_link_libraries(particle_simulator_dlib PUBLIC Qt6::Core)

add_library(particle_simulator_slib  ${SRC})
target_link_libraries(particle_simulator_slib PUBLIC Qt6::Core)

if (${BUILD_TESTS})
    enable_testing()
     
    if (${BUILD_UNIT_TESTS})
        add_subdirectory("tests/unit_tests")
    endif()

    if (${BUILD_FUNCTIONAL_TESTS})
        add_subdirectory("tests/functional_tests")
    endif()
endif()

# configure_file(./data/Output_example.json ${CMAKE_BINARY_DIR}/Output_example.json)