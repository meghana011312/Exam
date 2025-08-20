
#include <iostream>
#include <string>
#include <exception>
#include "FleetManager.h"


/**
 * @file main.cpp
 * @brief Entry point for Fleet Management System.
 *
 * Loads vehicle data from a CSV file, computes and prints average statistics,
 * and prints alerts for critical vehicle conditions.
 */

int main() {
    /**
     * @brief Prompt user for CSV filename and load vehicle data.
     */
    std::string filename;
    std::cout << "Enter CSV filename: ";
    std::getline(std::cin, filename);

    FleetManager manager;
    if (!manager.loadFromCSV(filename)) {
        std::cerr << "Failed to load vehicles from file: " << filename << std::endl;
        return 1;
    }

    try {
        /**
         * @brief Compute and print average speed, temperature, and fuel.
         */
        std::cout << "Average Speed: " << manager.getAverageSpeed() << " km/h" << std::endl;
        std::cout << "Average Temperature: " << manager.getAverageTemperature() << " \u00B0C" << std::endl;
        std::cout << "Average Fuel: " << manager.getAverageFuel() << "%" << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    /**
     * @brief Print alerts for vehicles with critical status.
     */
    manager.printAlerts();

    return 0;
}
