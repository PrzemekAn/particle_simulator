#include "normal.h"
#include <cstdlib>

int Normal::give_the_id(){
    static int tmp_id{0};
    tmp_id++;
    int id = tmp_id;
    return id;
}

Normal::Normal(int id, float mass, std::vector<float> position, std::vector<float> speed):
    m_id{give_the_id()},
    m_mass{mass}, 
    m_position{position}, 
    m_speed{speed} 
    {
        if(id){
            m_id = id;
        }
    }

void Normal::change_attributes_after_hit(Particle& particle){
}

void Normal::change_attributes_after_hit(Positive& positive){
}

void Normal::change_attributes_after_hit(Negative& negative){
}

const int Normal::get_id(){
    return m_id;
}

const float Normal::get_mass(){
    return m_mass;
}

const std::vector<float> Normal::get_position(){
    return m_position;
}

const std::vector<float> Normal::get_speed(){
    return m_speed;
}

Normal::~Normal() = default;
