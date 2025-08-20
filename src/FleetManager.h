
#ifndef FLEETMANAGER_H
#define FLEETMANAGER_H

#include <vector>
#include <string>
#include <mutex>
#include "Vehicle.h"


/**
 * @class FleetManager
 * @brief Manages a fleet of Vehicle objects.
 *
 * This class provides methods to load vehicles from a CSV file, add vehicles,
 * compute average statistics, and print alerts for critical vehicle conditions.
 * All public methods are thread-safe.
 */
class FleetManager {
private:
    /**
     * @brief List of managed vehicles.
     */
    std::vector<Vehicle> vehicles;

    /**
     * @brief Mutex to protect vehicles for thread safety.
     */
    mutable std::mutex mtx;

public:
    /**
     * @brief Default constructor.
     */
    FleetManager() = default;

    /**
     * @brief Load vehicles from a CSV file.
     * @param filename Path to CSV file.
     * @return true if successful, false otherwise.
     *
     * Each line in the CSV should be formatted as: id,speed,temperature,fuel
     */
    bool loadFromCSV(const std::string& filename);

    /**
     * @brief Add a vehicle to the fleet (thread-safe).
     * @param v Vehicle to add.
     */
    void addVehicle(const Vehicle& v);

    /**
     * @brief Get average speed of all vehicles.
     * @return Average speed.
     * @throws std::runtime_error if the fleet is empty.
     */
    double getAverageSpeed() const;

    /**
     * @brief Get average temperature of all vehicles.
     * @return Average temperature.
     * @throws std::runtime_error if the fleet is empty.
     */
    double getAverageTemperature() const;

    /**
     * @brief Get average fuel level of all vehicles.
     * @return Average fuel level.
     * @throws std::runtime_error if the fleet is empty.
     */
    double getAverageFuel() const;

    /**
     * @brief Print alerts for vehicles with critical status.
     *
     * Alerts:
     * - If temperature > 110°C: "Vehicle [id]: Critical Overheating"
     * - If fuel < 15%: "Vehicle [id]: Low Fuel Warning"
     */
    void printAlerts() const;

    /**
     * @brief Get the list of vehicles.
     * @return const reference to vehicles vector.
     */
    const std::vector<Vehicle>& getVehicles() const;
};

#endif // FLEETMANAGER_H
