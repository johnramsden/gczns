#include "ConvSSD.hpp"
#include <iostream>

// Constructor
ConvSSD::ConvSSD(const std::string& device, int nr_zones) : Disk(device), nr_zones(nr_zones) {}

ConvSSD::~ConvSSD() {}

// Read data from SSD
void ConvSSD::read_data() const {
    std::cout << "Reading data from SSD\n";
}

// Write data to SSD
void ConvSSD::write_data() {
    std::cout << "Writing data to SSD\n";
}

// Display disk information
void ConvSSD::display_info() const {
    std::cout << "Disk Name: " << name << "\n";
    std::cout << "NR Zones: " << nr_zones << "\n";
}
