#ifndef CALCULATE_FORCE_H
#define CALCULATE_FORCE_H
#include "particle.h"

double calculate_force(Particle& p1, Particle& p2){
    // const double G = 6.67*10e-11;

    float tmp_x{p1.position()[0] - p2.position()[0]};
    if(tmp_x < 0) tmp_x *= -1;

    float tmp_y{p1.position()[1] - p2.position()[1]};
    if(tmp_y < 0) tmp_x *= -1;

    // float distance{std::sqrt(tmp_x*tmp_x - tmp_y*tmp_y)};
    float distance_squared{tmp_x*tmp_x + tmp_y*tmp_y};

    double F = (p1.mass()*p2.mass()/distance_squared);
    return F;
}

#endif