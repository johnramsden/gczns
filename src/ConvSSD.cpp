#include "ConvSSD.hpp"
#include <iostream>

// Constructor
ConvSSD::ConvSSD(const std::string& device, std::uint64_t block_size, std::uint32_t nr_zones)
: Disk(device, block_size), nr_zones(nr_zones) {}

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
    std::cout << "Device: " << device << "\n";
    std::cout << "Type: ConvSSD\n";
    std::cout << "NR Zones: " << nr_zones << "\n";
    std::cout << "Block Size: " << block_size << "\n";
}
