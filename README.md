
# FleetManager C++ Project

## Introduction
FleetManager is a C++ application designed to help manage and monitor a fleet of vehicles. It loads vehicle data from a CSV file, computes fleet statistics, and prints alerts for critical conditions such as overheating and low fuel. The project also includes automated test cases to ensure reliability.

## System Requirements
- **C++ Compiler:** g++ or MSVC supporting C++11 or later
- **Standard Library:** Requires `<cassert>`, `<vector>`, `<string>`, `<fstream>`, `<sstream>`, `<iostream>`
- **VS Code Extensions:**
  - C/C++ (ms-vscode.cpptools)
  - CMake Tools (ms-vscode.cmake-tools) (optional, for CMake projects)
  - Code Runner (formulahendry.code-runner) (optional, for running code)


## Overview
FleetManager is a multi-file C++ project for managing a fleet of vehicles. It allows you to:
- Load vehicle data from a CSV file
- Compute and display average speed, temperature, and fuel level
- Print alerts for critical overheating and low fuel
- Run automated test cases to validate functionality

## Class and Function Details

### Vehicle
Defined in `Vehicle.h` and implemented in `Vehicle.cpp`.

**Members:**
- `int id` — Unique identifier for the vehicle
- `double speed` — Current speed of the vehicle
- `double temperature` — Engine temperature in °C
- `double fuel` — Fuel level as a percentage (0 to 100)

**Functions:**
- Constructors: Default and parameterized
- Getters: `getId()`, `getSpeed()`, `getTemperature()`, `getFuel()`
- Setters: `setId()`, `setSpeed()`, `setTemperature()`, `setFuel()`

### FleetManager
Defined in `FleetManager.h` and implemented in `FleetManager.cpp`.

**Members:**
- `std::vector<Vehicle> vehicles` — List of managed vehicles

**Functions:**
- `bool loadFromCSV(const std::string& filename)` — Loads vehicles from a CSV file
- `double getAverageSpeed() const` — Returns average speed of all vehicles
- `double getAverageTemperature() const` — Returns average temperature
- `double getAverageFuel() const` — Returns average fuel level
- `void printAlerts() const` — Prints alerts for vehicles:
  - If temperature > 110°C: "Vehicle [id]: Critical Overheating"
  - If fuel < 15%: "Vehicle [id]: Low Fuel Warning"
- `void addVehicle(const Vehicle&)` — Adds a vehicle (used in tests)
- `const std::vector<Vehicle>& getVehicles() const` — Returns the vehicle list

### Test Cases
Defined in `FleetManagerTest.cpp`.
- Validates overheating and low fuel detection
- Checks average speed calculation
- Tests boundary conditions
- Ensures exception handling for empty datasets

## File Structure
```
src/
  Vehicle.h/.cpp         # Vehicle class definition and implementation
  FleetManager.h/.cpp    # FleetManager class definition and implementation
  main.cpp               # Main application (loads CSV, prints stats and alerts)
  FleetManagerTest.cpp   # Automated test cases
  vehicles.csv           # Sample vehicle data (CSV format)
```

## How to Build
Make sure you have g++ installed. Open PowerShell in your project directory and run:

To build the main application:
```powershell
g++ src\main.cpp src\FleetManager.cpp src\Vehicle.cpp -o fleet_manager.exe
```

To build and run the test cases:
```powershell
g++ src\FleetManagerTest.cpp src\FleetManager.cpp src\Vehicle.cpp -o fleet_manager_test.exe
./fleet_manager_test.exe
```

## Usage
1. Run `fleet_manager.exe`.
2. Enter the CSV filename (e.g., `src/vehicles.csv`).
3. View average statistics and alerts for your fleet.

## CSV Format
Each line should be:
```
id,speed,temperature,fuel
1,60.5,75.0,80
2,45.0,68.2,55
...etc
```

## Sample Input
Example `vehicles.csv`:
```
id,speed,temperature,fuel
1,80,95,60
2,120,115,10
3,60,85,50
4,90,112,8
5,70,100,80
```

## Sample Output
```
Enter CSV filename: src/vehicles.csv
Average Speed: 84 km/h
Average Temperature: 101.4 °C
Average Fuel: 41.6%
Vehicle 2: Critical Overheating
Vehicle 2: Low Fuel Warning
Vehicle 4: Critical Overheating
Vehicle 4: Low Fuel Warning
```

## Test Cases
`FleetManagerTest.cpp` includes:
- Overheating and low fuel detection
- Average speed calculation
- Boundary condition checks
- Exception handling for empty datasets

## License
This project is provided for educational purposes.
