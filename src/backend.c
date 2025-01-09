#include "backend.h"
#include <stdlib.h>
#include <time.h>

// Simulate fetching network speeds
void fetch_network_speeds(double *download, double *upload) {
    *download = (double)(rand() % 1000) / 10.0; // Random download speed (0-100 Mbps)
    *upload = (double)(rand() % 500) / 10.0;    // Random upload speed (0-50 Mbps)
}