#include "normal.h"
#include <cstdlib>

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

void Normal::change_attributes(){
    
}

const int Normal::id(){
    return m_id;
}

// const int Normal::id() const{
//     return m_id;
// }

const float Normal::mass(){
    return m_mass;
}

// const float Normal::mass() const{
//     return m_mass;
// }

const std::vector<float> Normal::position(){
    return m_position;
}

// const std::vector<float> Normal::position() const{
//     return m_position;
// }

const std::vector<float> Normal::speed(){
    return m_speed;
}

// const std::vector<float> Normal::speed() const{
//     return m_speed;
// }

Normal::~Normal() = default;
