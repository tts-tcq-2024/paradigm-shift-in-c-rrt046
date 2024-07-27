#ifndef BATTERY_WARNING_H
#define BATTERY_WARNING_H

#include <stddef.h>  // For size_t
#include "battery_check.h" // Include this to recognize Check type

// Function declarations
void checkBatteryWarnings(Check warnings[], size_t size);

#endif // BATTERY_WARNING_H
