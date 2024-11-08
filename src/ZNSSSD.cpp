#include "ZNSSSD.hpp"
#include <iostream>

// Constructor
ZNSSSD::ZNSSSD(const std::string& device, std::uint64_t block_size) : Disk(device, block_size) {
    struct zbd_info info;
    fd = zbd_open(device.c_str(), O_RDWR, &info);
    if (fd < 0) {
        throw std::runtime_error("Failed to open ZNS device " + device);
    }
    nr_zones = info.nr_zones;

    int ret = zbd_reset_zones(fd, 0, 0);
    if (ret < 0) {
        throw std::runtime_error("Failed to reset zones on ZNS device " + device);
    }
}

ZNSSSD::~ZNSSSD() {
    zbd_close(fd);
}

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
    std::cout << "Device: " << device << "\n";
    std::cout << "Type: ZNSSSD\n";
    std::cout << "NR Zones: " << nr_zones << "\n";
    std::cout << "Block Size: " << block_size << "\n";
}
