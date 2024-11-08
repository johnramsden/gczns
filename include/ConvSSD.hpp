#ifndef SSD_H
#define SSD_H

#include "Disk.hpp"

class ConvSSD : public Disk {
public:
    // Constructor
    ConvSSD(const std::string& device, const std::uint64_t block_size, std::uint32_t nr_zones);
    ~ConvSSD();

    // Override read and write functions
    void read_data() const override;
    void write_data() override;
    void display_info() const override;
private:
    std::uint32_t nr_zones;
};

#endif // SSD_H
