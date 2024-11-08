#include "Disk.hpp"
#include <iostream>

// Constructor
Disk::Disk(const std::string& device) : name(device) {}

// Virtual destructor
Disk::~Disk() {}

// Virtual destructor
void Disk::display_info() const {}
