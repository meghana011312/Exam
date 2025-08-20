
#ifndef VEHICLE_H
#define VEHICLE_H


/**
 * @class Vehicle
 * @brief Represents a vehicle in the fleet.
 *
 * Stores vehicle ID, speed, engine temperature, and fuel percentage.
 */
class Vehicle {
private:
    /**
     * @brief Unique identifier for the vehicle.
     */
    int id;

    /**
     * @brief Current speed of the vehicle.
     */
    double speed;

    /**
     * @brief Engine temperature in degrees Celsius.
     */
    double temperature;

    /**
     * @brief Fuel level as a percentage (0 to 100).
     */
    double fuel;

public:
    /**
     * @brief Default constructor.
     */
    Vehicle();

    /**
     * @brief Parameterized constructor.
     * @param id Vehicle ID
     * @param speed Vehicle speed
     * @param temperature Engine temperature
     * @param fuel Fuel percentage
     */
    Vehicle(int id, double speed, double temperature, double fuel);

    /**
     * @brief Get the vehicle ID.
     * @return Vehicle ID
     */
    int getId() const;

    /**
     * @brief Get the vehicle speed.
     * @return Vehicle speed
     */
    double getSpeed() const;

    /**
     * @brief Get the engine temperature.
     * @return Engine temperature in °C
     */
    double getTemperature() const;

    /**
     * @brief Get the fuel percentage.
     * @return Fuel percentage (0 to 100)
     */
    double getFuel() const;

    /**
     * @brief Set the vehicle ID.
     * @param id Vehicle ID
     */
    void setId(int id);

    /**
     * @brief Set the vehicle speed.
     * @param speed Vehicle speed
     */
    void setSpeed(double speed);

    /**
     * @brief Set the engine temperature.
     * @param temperature Engine temperature in °C
     */
    void setTemperature(double temperature);

    /**
     * @brief Set the fuel percentage.
     * @param fuel Fuel percentage (0 to 100)
     */
    void setFuel(double fuel);
};

#endif // VEHICLE_H
