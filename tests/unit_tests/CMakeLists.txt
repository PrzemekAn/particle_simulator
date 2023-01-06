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

target_link_libraries(${This} PUBLIC
    gtest_main
    particle_simulator_dlib
    # ${CMAKE_BINARY_DIR}/libparticle_simulator_dlib.so
)

gtest_discover_tests(UTests)

# message(${CMAKE_BINARY_DIR})
# foreach(item IN LISTS SRC)
#     message(${item}) 
# endforeach()



