#include "SSD.hpp"
#include <iostream>

// Constructor
SSD::SSD(const std::string& name, int regions) : Disk(name), num_regions(regions) {}

// Read data from SSD
void SSD::readData() const {
    std::cout << "Reading data from SSD\n";
}

// Write data to SSD
void SSD::writeData() {
    std::cout << "Writing data to SSD\n";
}

// Display number of regions
void SSD::displayRegions() const {
    std::cout << "Number of Regions: " << num_regions << "\n";
}
