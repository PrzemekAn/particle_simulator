#include "simulation_data_from_file.h"


Simulation_data_from_file::Simulation_data_from_file(const char* file_path): Simulation_data_base(file_path){
    QFile file(file_path);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument json_doc = QJsonDocument::fromJson(data);
    QJsonObject json_obj = json_doc.object();

    m_properties.m_width = json_obj.value("width").toInt();
    m_properties.m_height = json_obj.value("height").toInt();
    m_properties.m_iterations_per_second = json_obj.value("iterations_per_second").toInt();

    QJsonArray simulation_arr = json_obj.value("simulation").toArray();

    long int iterations = simulation_arr.size();
    QJsonArray particles = simulation_arr[iterations-1].toObject().value("particles").toArray();

    std::vector<std::string> part_types{"normal", "antigravity", "antimater", "negative", "positive", "split"};
    long int particles_arr_size{particles.size()};

    for(int i = 0; i < particles_arr_size; ++i){
        int flag{};
        for(int j = 0; j < part_types.size(); ++j){
            if(!part_types[j].compare(particles[i].toObject().value("type").toString().toStdString())){
                flag = j;
                break;
            }
        }
        QJsonObject tmp_obj = particles[i].toObject();
        switch(flag){
            case 0:
            m_particles.emplace_back(new Normal(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 1:
            m_particles.emplace_back(new Antigravity(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 2:
            m_particles.emplace_back(new Antimater(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 3:
            m_particles.emplace_back(new Negative(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 4:
            m_particles.emplace_back(new Positive(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 5:
            m_particles.emplace_back(new Split(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
        default:
            break;
        }
    }
};

Simulation_data_from_file::~Simulation_data_from_file() = default;