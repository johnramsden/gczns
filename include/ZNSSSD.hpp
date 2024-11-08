#ifndef ZNSSSD_H
#define ZNSSSD_H

#include "Disk.hpp"

class ZNSSSD : public Disk {
public:
    // Constructor
    ZNSSSD(const std::string& device);

    ~ZNSSSD();

    // Override read and write functions
    void read_data() const override;
    void write_data() override;
    void display_info() const override;

private:
    unsigned int nr_zones;
};

#endif // ZNSSSD_H
