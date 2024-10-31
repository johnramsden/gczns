#include "ZNSSSD.hpp"
#include <iostream>

// Constructor
ZNSSSD::ZNSSSD(const std::string& name, int zones) : Disk(name), num_zones(zones) {}

// Read data from ZNS SSD
void ZNSSSD::readData() const {
    std::cout << "Reading data from ZNS SSD\n";
}

// Write data to ZNS SSD
void ZNSSSD::writeData() {
    std::cout << "Writing data to ZNS SSD\n";
}

// Display number of zones
void ZNSSSD::displayZones() const {
    std::cout << "Number of Zones: " << num_zones << "\n";
}
