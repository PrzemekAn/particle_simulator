#include "json_handler.h"

JSON_handler::JSON_handler(){}

Simulation_properties JSON_handler::read_header(const char* file_path){
    QFile file(file_path);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument json_doc = QJsonDocument::fromJson(data);
    QJsonObject json_obj = json_doc.object();

    Simulation_properties properties;

    properties.m_width = json_obj.value("width").toInt();
    properties.m_height = json_obj.value("height").toInt();
    properties.m_iterations_per_second = json_obj.value("iterations_per_second").toInt();

    return properties;
}


std::vector<Particle_uptr> JSON_handler::read_body(const char* file_path){
    QFile file(file_path);
    file.open(QIODevice::ReadOnly);
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument json_doc = QJsonDocument::fromJson(data);
    QJsonObject json_obj = json_doc.object();

    QJsonArray simulation_arr = json_obj.value("simulation").toArray();

    long int iterations = simulation_arr.size();
    QJsonArray particles = simulation_arr[iterations-1].toObject().value("particles").toArray();

    std::vector<std::string> part_types{"normal", "antigravity", "antimater", "negative", "positive", "split"};
    long int particles_arr_size{particles.size()};

    std::vector<Particle_uptr> particles_uptr_vector;

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
            particles_uptr_vector.emplace_back(new Normal(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 1:
            particles_uptr_vector.emplace_back(new Antigravity(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 2:
            particles_uptr_vector.emplace_back(new Antimater(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 3:
            particles_uptr_vector.emplace_back(new Negative(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 4:
            particles_uptr_vector.emplace_back(new Positive(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
            case 5:
            particles_uptr_vector.emplace_back(new Split(tmp_obj.value("id").toInt(), tmp_obj.value("weight").toDouble(), {static_cast<float>(tmp_obj.value("position_x").toDouble()), static_cast<float>(tmp_obj.value("position_y").toDouble())}, {static_cast<float>(tmp_obj.value("velocity_x").toDouble()), static_cast<float>(tmp_obj.value("velocity_y").toDouble())}));    
            break;
        default:
            break;
        }
    }
return particles_uptr_vector;
}

void JSON_handler::save_to_json(const Simulation_properties& props, const std::vector<Particle_uptr>& parts, const char* file_path){
    QJsonObject core_obj;
    core_obj["width"] = props.m_width;
    core_obj["height"] = props.m_height;
    core_obj["iterations_per_second"] = props.m_iterations_per_second;

    QJsonObject simulation_obj;
    simulation_obj["iteration"] = 0;

    QJsonObject particle_obj;
    particle_obj["id"] = parts[0].get()->id();
    particle_obj["type"] = typeid(*parts[0].get()).name();
    particle_obj["weight"] = parts[0].get()->mass();
    particle_obj["position_x"] = parts[0].get()->position()[0];
    particle_obj["position_y"] = parts[0].get()->position()[1];
    particle_obj["velocity_x"] = parts[0].get()->speed()[0];
    particle_obj["velocity_y"] = parts[0].get()->speed()[1];
    simulation_obj["particles"] = QJsonArray{particle_obj};
    core_obj["simulation"] = QJsonArray{simulation_obj};
    
    QJsonDocument Json_document;
    Json_document.setObject(core_obj);

    QFile file(file_path);
    file.open(QIODevice::ReadWrite);
    file.write(Json_document.toJson());
    file.close();
}

JSON_handler::~JSON_handler() = default;