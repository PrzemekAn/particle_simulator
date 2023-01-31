cmake_minimum_required(VERSION 3.10)

set(This UTests)
enable_testing()

set(SRC 
    tests_antigravity.cpp
    tests_antimater.cpp
    tests_json_handler.cpp
    tests_negative.cpp
    tests_normal.cpp
    tests_physics_engine.cpp
    tests_positive.cpp
    tests_simulation_data_base.cpp
    tests_simulation_data_from_file.cpp
    tests_simulation_data_generator.cpp
    tests_simulation_properties.cpp
    tests_split.cpp
    )
add_executable(${This} ${SRC})


find_library(particle_simulator_dlib libparticle_simulator_dlib ${CMAKE_BINARY_DIR})

find_package(GTest REQUIRED)

target_link_libraries(${This} PUBLIC
    gtest
    gtest_main
    particle_simulator_dlib
)

include(CTest)
gtest_discover_tests(UTests)

configure_file(${PROJECT_SOURCE_DIR}/data/Output_example.json ${CMAKE_BINARY_DIR}/tests/unit_tests/Output_example.json)




