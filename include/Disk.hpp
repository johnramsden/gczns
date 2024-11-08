#ifndef DISK_H
#define DISK_H

extern "C" {
    #include <libzbd/zbd.h>
}

#include <string>

class Disk {
public:
    // Constructor with disk device
    Disk(const std::string& device);

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Disk();

    // Pure virtual functions (to be implemented by derived classes)
    virtual void read_data() const = 0;
    virtual void write_data() = 0;

    // Common function for all disks
    virtual void display_info() const = 0;

protected:
    std::string name;  // Name of the disk
};

#endif // DISK_H
