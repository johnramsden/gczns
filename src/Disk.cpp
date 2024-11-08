#include "Disk.hpp"
#include <iostream>

// Constructor
Disk::Disk(const std::string& device, const std::uint64_t block_size)
: device(device), block_size(block_size) {}

// Virtual destructor
Disk::~Disk() {}

// Virtual destructor
void Disk::display_info() const {}
