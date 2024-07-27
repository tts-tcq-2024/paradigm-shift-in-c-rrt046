#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include <stddef.h>  // For size_t

// Define the Check structure
typedef struct {
    _Bool (*check)(float);      // Function pointer for the check function
    float value;                // Value to be checked
    const char* errorMessage;   // Error message for out-of-range conditions
    const char* warningMessage; // Warning message for approaching limits
} Check;

// Function declarations
int batteryIsOk(float temperature, float soc, float chargeRate);
int checkBatteryParameters(Check checks[], size_t size);

#endif // BATTERY_CHECK_H
