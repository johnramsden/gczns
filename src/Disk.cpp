#include "Disk.hpp"
#include <iostream>

// Constructor
Disk::Disk(const std::string& name) : name(name) {}

// Virtual destructor
Disk::~Disk() {}

// Display disk information
void Disk::displayInfo() const {
    std::cout << "Disk Name: " << name << "\n";
}
