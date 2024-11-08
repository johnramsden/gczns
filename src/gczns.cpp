// #define _GNU_SOURCE
// Needed for O_DIRECT

#include "gczns.hpp"
#include "util.hpp"
#include <iostream>
#include <getopt.h>
#include <cstdlib>
#include <string>

extern "C" {
    #include <libzbd/zbd.h>
}

#include "Disk.hpp"
#include "ConvSSD.hpp"
#include "ZNSSSD.hpp"

struct ParsedArgs {
    std::string device;
    std::string type;
    int num_zones = 0;
};

bool parse_arguments(int argc, char* argv[], ParsedArgs &args) {
    // Define the option structure for long options
    const struct option long_options[] = {
        {"type", required_argument, 0, 't'},
        {"num-zones", required_argument, 0, 'n'},
        {0, 0, 0, 0}  // End of options
    };

    int opt;
    int long_index = 0;

    // Parse options
    while ((opt = getopt_long(argc, argv, "t:n:", long_options, &long_index)) != -1) {
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
            default:
                std::cerr << "Usage: " << argv[0] << " DEVICE --type SSD|ZNS [--num-zones NUM]\n";
                return false;
        }
    }

    // Get DEVICE as positional argument
    if (optind < argc) {
        args.device = argv[optind];
    } else {
        std::cerr << "Error: DEVICE is a required argument.\n";
        std::cerr << "Usage: " << argv[0]
                  << " DEVICE --type SSD|ZNS [--num-zones NUM]\n";
        return false;
    }

    return true;
}


int main(int argc, char* argv[]) {
    ParsedArgs args;

    if (!parse_arguments(argc, argv, args)) {
        return 1;  // Exit if argument parsing fails
    }

    // Print out parsed values for confirmation
    std::cout << "Device: " << args.device << std::endl;
    std::cout << "Type: " << args.type << std::endl;
    if (args.type == "SSD") {
        std::cout << "Number of Zones: " << args.num_zones << std::endl;
    }

    // Create an SSD object
    ConvSSD ssd(args.device, 8);

    std::cout << "--------------------------\n";

    // Create a ZNSSSD object
    ZNSSSD znssd(args.device);

    return 0;
}
