#ifndef SPLIT_H
#define SPLIT_H
#include "normal.h"
#include <vector>
#include <memory>

class Split: public Normal{
    private:
        std::unique_ptr<Particle> split();

    public:
        Split(int id, float mass, std::vector<float> position, std::vector<float> speed);
        ~Split();
        void change_attributes_after_hit(Particle & particle) override;
        void change_attributes(Particle& particle) override;
};


#endif