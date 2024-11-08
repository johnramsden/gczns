#ifndef ZNSSSD_H
#define ZNSSSD_H

#include "Disk.hpp"
#include <fcntl.h>

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
    int fd;
    
};

#endif // ZNSSSD_H
