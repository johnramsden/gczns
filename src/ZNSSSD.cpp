#include "ZNSSSD.hpp"
#include <iostream>

// Constructor
ZNSSSD::ZNSSSD(const std::string& device) : Disk(device) {}

ZNSSSD::~ZNSSSD() {}

// Read data from ZNS SSD
void ZNSSSD::read_data() const {
    std::cout << "Reading data from ZNS SSD\n";
}

// Write data to ZNS SSD
void ZNSSSD::write_data() {
    std::cout << "Writing data to ZNS SSD\n";
}

// Display disk information
void ZNSSSD::display_info() const {
    std::cout << "Disk Name: " << name << "\n";
    std::cout << "NR Zones: " << nr_zones << "\n";
}
