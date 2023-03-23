#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H
#include "particle.h"
#include "normal.h"
#include "antigravity.h"
#include "antimater.h"
#include "positive.h"
#include "negative.h"
#include "split.h"
#include "simulation_properties.h"
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <typeinfo>
#include <QJsonDocument>
#include <QFile>
#include <QString>
#include <QJsonValue>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

class Simulation_data;
class Simulation_data_base;
// class Simulation_data_from_file;
// class Simulation_data_generator;

class JSON_handler{
    public:
        JSON_handler();
        Simulation_properties read_header(const char* file_path);
        std::vector<Particle_uptr> read_body(const char* file_path);
        void save_to_json(const Simulation_data& data, int iter, const char* file_path);
        ~JSON_handler();
};



#endif
