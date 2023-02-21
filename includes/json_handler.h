#ifndef JSON_HANDLER_H
#define JSON_HANDLER_H
#include "particle.h"
#include "simulation_data.h"
#include "simulation_properties.h"
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <QJsonDocument>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>


class JSON_handler{
    public:
        JSON_handler();
        Simulation_properties read_header(const char* file_path);
        std::vector<Particle_uptr> read_body(const char* file_path);
        void save_to_json();
        ~JSON_handler();
};



#endif
