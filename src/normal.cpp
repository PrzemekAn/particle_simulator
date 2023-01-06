#include "normal.h"
#include "calculate_force.h"


Normal::Normal(int id, float mass, std::vector<float> position, std::vector<float> speed):
    m_id{id},
    m_mass{mass}, 
    m_position{position}, 
    m_speed{speed} 
    {}

void Normal::change_attributes_after_hit(Particle& particle){
}

void Normal::change_attributes_after_hit(Positive& positive){
}

void Normal::change_attributes_after_hit(Negative& negative){
}

void Normal::change_attributes(Particle& particle){
}

//change_attributes method takes properties argument so that particles don't go outside the simulation field - conditional statemensts have to be reconsidered due to negative positions at the end of simulations
void Normal::change_attributes(Particle& particle, Simulation_properties& properties){
    // a = F/m - speed changes depending on the applied force

    if(m_position[0] < properties.m_width && m_position[0] > 0) m_position[0] += m_speed[0];
    if(m_position[1] < properties.m_height && m_position[1] > 0) m_position[1] += m_speed[1];
    double F = calculate_force(*this, particle);
    m_speed[0] += F/m_mass;
    m_speed[1] += F/m_mass;
}

void Normal::change_attributes(Positive& positive){
}

void Normal::change_attributes(Negative& negative){
}

const int Normal::id(){
    return m_id;
}

const float Normal::mass(){
    return m_mass;
}

const std::vector<float> Normal::position(){
    return m_position;
}

const std::vector<float> Normal::speed(){
    return m_speed;
}

Normal::~Normal() = default;
