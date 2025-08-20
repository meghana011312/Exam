// FleetManager.cpp
#include "FleetManager.h"
#include <fstream>
#include <sstream>
#include <iostream>


bool FleetManager::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        int id;
        double speed, temperature, fuel;
        char comma;
        if (ss >> id >> comma >> speed >> comma >> temperature >> comma >> fuel) {
            std::lock_guard<std::mutex> lock(mtx);
            vehicles.emplace_back(id, speed, temperature, fuel);
        }
    }
    file.close();
    return true;
}

double FleetManager::getAverageSpeed() const {
    std::lock_guard<std::mutex> lock(mtx);
    if (vehicles.empty()) throw std::runtime_error("No vehicles in fleet.");
    double sum = 0.0;
    for (const auto& v : vehicles) sum += v.getSpeed();
    return sum / vehicles.size();
}

double FleetManager::getAverageTemperature() const {
    std::lock_guard<std::mutex> lock(mtx);
    if (vehicles.empty()) throw std::runtime_error("No vehicles in fleet.");
    double sum = 0.0;
    for (const auto& v : vehicles) sum += v.getTemperature();
    return sum / vehicles.size();
}

double FleetManager::getAverageFuel() const {
    std::lock_guard<std::mutex> lock(mtx);
    if (vehicles.empty()) throw std::runtime_error("No vehicles in fleet.");
    double sum = 0.0;
    for (const auto& v : vehicles) sum += v.getFuel();
    return sum / vehicles.size();
}

void FleetManager::printAlerts() const {
    std::lock_guard<std::mutex> lock(mtx);
    for (const auto& v : vehicles) {
        if (v.getTemperature() > 110.0) {
            std::cout << "Vehicle " << v.getId() << ": Critical Overheating" << std::endl;
        }
        if (v.getFuel() < 15.0) {
            std::cout << "Vehicle " << v.getId() << ": Low Fuel Warning" << std::endl;
        }
    }
}

const std::vector<Vehicle>& FleetManager::getVehicles() const {
    std::lock_guard<std::mutex> lock(mtx);
    return vehicles;
}

void FleetManager::addVehicle(const Vehicle& v) {
    std::lock_guard<std::mutex> lock(mtx);
    vehicles.push_back(v);
}
