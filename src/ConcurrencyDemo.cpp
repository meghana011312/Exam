

/**
 * @file ConcurrencyDemo.cpp
 * @brief Demonstrates concurrency in FleetManager using std::thread and std::mutex.
 *
 * Compares single-threaded and multi-threaded updates of Vehicle objects,
 * measuring execution time and speedup.
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>
#include "FleetManager.h"

constexpr int numThreads = 4;
std::mutex fleet_mutex;

/**
 * @brief Simulate updating a vehicle's data with random values.
 * @param v Vehicle to update
 */
void updateVehicle(Vehicle& v) {
    static thread_local std::random_device rd;
    static thread_local std::mt19937 gen(rd());
    std::uniform_real_distribution<> speed_dist(40, 120);
    std::uniform_real_distribution<> temp_dist(60, 130);
    std::uniform_real_distribution<> fuel_dist(5, 100);
    v.setSpeed(speed_dist(gen));
    v.setTemperature(temp_dist(gen));
    v.setFuel(fuel_dist(gen));
}

/**
 * @brief Thread worker to update a range of vehicles and add to FleetManager.
 * @param vehicles Vector of vehicles
 * @param manager FleetManager instance
 * @param start Start index
 * @param end End index
 */
void updateVehiclesThread(std::vector<Vehicle>& vehicles, FleetManager& manager, int start, int end) {
    for (int i = start; i < end; ++i) {
        updateVehicle(vehicles[i]);
        std::lock_guard<std::mutex> lock(fleet_mutex);
        manager.addVehicle(vehicles[i]);
    }
}

/**
 * @brief Main function to run concurrency demo and print results.
 */
int main() {
    const int numVehicles = 100;
    std::vector<Vehicle> vehicles;
    vehicles.reserve(numVehicles);
    for (int i = 0; i < numVehicles; ++i) {
        vehicles.emplace_back(i+1, 0, 0, 0);
    }

    // Single-threaded update
    FleetManager singleManager;
    auto start_single = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numVehicles; ++i) {
        updateVehicle(vehicles[i]);
        singleManager.addVehicle(vehicles[i]);
    }
    double avgSpeedSingle = singleManager.getAverageSpeed();
    auto end_single = std::chrono::high_resolution_clock::now();
    auto duration_single = std::chrono::duration_cast<std::chrono::milliseconds>(end_single - start_single).count();

    // Multi-threaded update
    FleetManager multiManager;
    std::vector<std::thread> threads;
    int vehiclesPerThread = numVehicles / numThreads;
    auto start_multi = std::chrono::high_resolution_clock::now();
    for (int t = 0; t < numThreads; ++t) {
        int startIdx = t * vehiclesPerThread;
        int endIdx = (t == numThreads - 1) ? numVehicles : startIdx + vehiclesPerThread;
        threads.emplace_back(updateVehiclesThread, std::ref(vehicles), std::ref(multiManager), startIdx, endIdx);
    }
    for (auto& th : threads) th.join();
    double avgSpeedMulti = multiManager.getAverageSpeed();
    auto end_multi = std::chrono::high_resolution_clock::now();
    auto duration_multi = std::chrono::duration_cast<std::chrono::milliseconds>(end_multi - start_multi).count();

    // Print results
    std::cout << "Single-threaded: Average Speed = " << avgSpeedSingle << ", Time = " << duration_single << " ms\n";
    std::cout << "Multi-threaded:  Average Speed = " << avgSpeedMulti << ", Time = " << duration_multi << " ms\n";
    if (duration_multi > 0)
        std::cout << "Speedup: " << (double)duration_single / duration_multi << "x\n";
    else
        std::cout << "Speedup: N/A (multi-threaded time too fast to measure)\n";
    return 0;
}
