#ifndef SIMULATION_DATA_FROM_FILE
#define SIMULATION_DATA_FROM_FILE
#include "simulation_data_base.h"
#include <string>
#include <QJsonDocument>
#include <QFile>
#include <QString>
#include <QByteArray>
#include <QJsonObject>
#include <QJsonArray>

class Simulation_data_from_file: public Simulation_data_base{
    public:
        Simulation_data_from_file(const char* file_path);
        ~Simulation_data_from_file();
};

#endif