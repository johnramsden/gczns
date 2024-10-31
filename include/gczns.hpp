#ifndef GCZNS_H
#define GCZNS_H

// ./zbd report /dev/nvme0n2
#define ZONE_CAP_BYTES 1129316352

#define metric_printf(FD, M, ...)                                                                  \
    do {                                                                                           \
        if (FD != NULL)                                                                            \
            fprintf(FD, M, ##__VA_ARGS__);                                                         \
    } while (0)

#endif // GCZNS_H
