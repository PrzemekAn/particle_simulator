cmake_minimum_required(VERSION 3.10)

set(This UTests)

set(SRC 
    UTests.cpp)

add_executable(${This} ${SRC})

target_link_libraries(UTests PRIVATE Qt6::Core)

target_link_libraries(${This} PUBLIC
    gtest_main
    ${CMAKE_BINARY_DIR}/libparticle_simulator_dlib.so
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
# message(${CMAKE_BINARY_DIR})