#ifndef SSD_H
#define SSD_H

#include "Disk.hpp"

class SSD : public Disk {
public:
    // Constructor
    SSD(const std::string& name, int regions);

    // Override read and write functions
    void readData() const override;
    void writeData() override;

    // Display number of regions for this SSD
    void displayRegions() const;

private:
    int num_regions;  // Specific to SSD
};

#endif // SSD_H
