// #define _GNU_SOURCE
// Needed for O_DIRECT

#include "gczns.hpp"
#include "util.hpp"
#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include <string>
#include <memory>

extern "C" {
    #include <libzbd/zbd.h>
}

#include "Disk.hpp"
#include "ConvSSD.hpp"
#include "ZNSSSD.hpp"

struct ParsedArgs {
    std::string device;
    std::string type;
    std::uint32_t num_zones = 0;
    std::uint64_t block_size = 0;  // New member for block size
};

bool parse_arguments(int argc, char* argv[], ParsedArgs &args) {
    // Define the option structure for long options
    const struct option long_options[] = {
        {"type", required_argument, 0, 't'},
        {"num-zones", required_argument, 0, 'n'},
        {"block-size", required_argument, 0, 'b'},
        {0, 0, 0, 0}  // End of options
    };

    int opt;
    int long_index = 0;
    bool block_size_provided = false;

    // Parse options
    while ((opt = getopt_long(argc, argv, "t:n:b:", long_options, &long_index)) != -1) {
        switch (opt) {
            case 't':
                args.type = optarg;
                if (args.type != "SSD" && args.type != "ZNS") {
                    std::cerr << "Error: Type must be 'SSD' or 'ZNS'.\n";
                    return false;
                }
                break;
            case 'n':
                if (args.type == "SSD") {
                    args.num_zones = atoi(optarg);
                } else {
                    std::cerr << "Error: --num-zones is only valid with type 'SSD'.\n";
                    return false;
                }
                break;
            case 'b':  // Handle block size
                args.block_size = std::stoull(optarg);
                if (args.block_size <= 0) {
                    std::cerr << "Error: Block size must be a positive integer.\n";
                    return false;
                }
                block_size_provided = true;
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " DEVICE --type SSD|ZNS [--num-zones NUM] --block-size SIZE\n";
                return false;
        }
    }

    // Get DEVICE as positional argument
    if (optind < argc) {
        args.device = argv[optind];
    } else {
        std::cerr << "Error: DEVICE is a required argument.\n";
        std::cerr << "Usage: " << argv[0]
                  << " DEVICE --type SSD|ZNS [--num-zones NUM] --block-size SIZE\n";
        return false;
    }

    // Check if block size was provided
    if (!block_size_provided) {
        std::cerr << "Error: --block-size is a required argument.\n";
        std::cerr << "Usage: " << argv[0]
                  << " DEVICE --type SSD|ZNS [--num-zones NUM] --block-size SIZE\n";
        return false;
    }

    return true;
}


int main(int argc, char* argv[]) {
    ParsedArgs args;

    if (!parse_arguments(argc, argv, args)) {
        return 1;  // Exit if argument parsing fails
    }

    // Create a Disk object
    std::unique_ptr<Disk> disk;

    if (args.type == "SSD") {
        disk = std::make_unique<ConvSSD>(args.device, args.block_size, args.num_zones);
    } else {
        disk = std::make_unique<ZNSSSD>(args.device, args.block_size);
    }

    disk->display_info();

    return 0;
}
