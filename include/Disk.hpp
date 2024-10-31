#ifndef DISK_H
#define DISK_H

#include <string>

class Disk {
public:
    // Constructor with disk name
    Disk(const std::string& name);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Disk();

    // Pure virtual functions (to be implemented by derived classes)
    virtual void readData() const = 0;
    virtual void writeData() = 0;

    // Common function for all disks
    void displayInfo() const;

protected:
    std::string name;  // Name of the disk
};

#endif // DISK_H
