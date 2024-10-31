#ifndef ZNSSSD_H
#define ZNSSSD_H

#include "Disk.hpp"

class ZNSSSD : public Disk {
public:
    // Constructor
    ZNSSSD(const std::string& name, int zones);

    // Override read and write functions
    void readData() const override;
    void writeData() override;

    // Display number of zones for this ZNS SSD
    void displayZones() const;

private:
    int num_zones;  // Specific to ZNS SSD
};

#endif // ZNSSSD_H
