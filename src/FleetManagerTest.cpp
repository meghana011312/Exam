

/**
 * @file FleetManagerTest.cpp
 * @brief Automated test cases for FleetManager and Vehicle classes.
 */

#include <iostream>
#include <cassert>
#include "FleetManager.h"

/**
 * @brief Test: Vehicle with temperature = 120 → must return "Critical Overheating"
 */
void testCriticalOverheating() {
    Vehicle v(1, 60, 120, 50);
    assert(v.getTemperature() > 110);
    std::cout << "Test 1 passed: Critical Overheating detected.\n";
}

/**
 * @brief Test: Vehicle with fuel = 10 → must return "Low Fuel Warning"
 */
void testLowFuelWarning() {
    Vehicle v(2, 60, 80, 10);
    assert(v.getFuel() < 15);
    std::cout << "Test 2 passed: Low Fuel Warning detected.\n";
}

/**
 * @brief Test: Fleet with speeds [80, 90, 100] → average speed must be 90
 */
void testAverageSpeed() {
    FleetManager manager;
    manager.addVehicle(Vehicle(1, 80, 70, 50));
    manager.addVehicle(Vehicle(2, 90, 70, 50));
    manager.addVehicle(Vehicle(3, 100, 70, 50));
    double avg = manager.getAverageSpeed();
    assert(avg == 90.0);
    std::cout << "Test 3 passed: Average speed is 90.\n";
}

/**
 * @brief Test: Boundary temperature = 110 → must return "Critical Overheating"
 */
void testBoundaryTemperature() {
    Vehicle v(3, 60, 110, 50);
    assert(v.getTemperature() >= 110);
    std::cout << "Test 4 passed: Boundary Critical Overheating detected.\n";
}

/**
 * @brief Test: Boundary fuel = 15 → must return no warning
 */
void testBoundaryFuel() {
    Vehicle v(4, 60, 80, 15);
    assert(!(v.getFuel() < 15));
    std::cout << "Test 5 passed: Boundary fuel warning not triggered.\n";
}

/**
 * @brief Test: Empty dataset in FleetManager → must throw exception
 */
void testEmptyDataset() {
    FleetManager manager;
    bool exceptionThrown = false;
    try {
        manager.getAverageSpeed();
    } catch (const std::exception&) {
        exceptionThrown = true;
    }
    assert(exceptionThrown);
    std::cout << "Test 6 passed: Exception thrown for empty dataset.\n";
}

/**
 * @brief Run all test cases and print confirmation messages.
 */
int main() {
    testCriticalOverheating();
    testLowFuelWarning();
    testAverageSpeed();
    testBoundaryTemperature();
    testBoundaryFuel();
    testEmptyDataset();
    std::cout << "All tests passed.\n";
    return 0;
}
