
#include <iostream>
#include <fstream>

#include <vector>
#include <string>
#include <exception>
#include <sstream>

/**
 * @class Vehicle
 * @brief Represents a vehicle with speed, temperature, and fuel.
 */
class Vehicle {
private:
    int id;
    int speed;
    int temperature;
    int fuel;
public:
    Vehicle(int id, int speed, int temperature, int fuel)
        : id(id), speed(speed), temperature(temperature), fuel(fuel) {}

    int getId() const { return id; }
    int getSpeed() const { return speed; }
    int getTemperature() const { return temperature; }
    int getFuel() const { return fuel; }
    void printStatus() const {
        std::cout << "Vehicle " << id << " Speed:" << speed << " Temp:" << temperature << " Fuel:" << fuel << std::endl;
        if (temperature > 110) std::cout << "Alert: Critical Overheating" << std::endl;
        if (fuel < 15) std::cout << "Warning: Low Fuel" << std::endl;
    }
};

/**
 * @class FleetManager
 * @brief Manages a fleet of vehicles and handles file input.
 */
class FleetManager {
private:
    std::vector<Vehicle> vehicles;
public:
    void loadFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Error: Cannot open file " + filename);
        }
        std::string line;
        int id = 0;
        while (std::getline(file, line)) {
            int speed, temp, fuel;
            char delim1 = 0, delim2 = 0;
            std::istringstream iss(line);
            // Accept either space or comma separated values
            if (!(iss >> speed)) throw std::runtime_error("Error: Invalid speed value");
            if (iss.peek() == ',' || iss.peek() == ' ') iss.get(delim1);
            if (!(iss >> temp)) throw std::runtime_error("Error: Invalid temperature value");
            if (iss.peek() == ',' || iss.peek() == ' ') iss.get(delim2);
            if (!(iss >> fuel)) throw std::runtime_error("Error: Invalid fuel value");
            vehicles.emplace_back(id++, speed, temp, fuel);
        }
        file.close();
    }

    void printFleetStatus() const {
        for (const auto& v : vehicles) {
            v.printStatus();
        }
    }
};

int main() {
    try {
        FleetManager manager;
        std::string filename;
        std::cout << "Enter input filename: ";
        std::getline(std::cin, filename);
        manager.loadFromFile(filename);
        manager.printFleetStatus();
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
    return 0;
}