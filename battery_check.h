#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include <stdbool.h>
#include <stddef.h>

// Function prototypes
bool isTemperatureInRange(float temperature);
bool isSocInRange(float soc);
bool isChargeRateInRange(float chargeRate);

bool batteryIsOk(float temperature, float soc, float chargeRate);

// Define the size of the warning tolerance array
#define NUM_TOLERANCES 3

extern float warningTolerances[NUM_TOLERANCES];

#endif // BATTERY_CHECK_H
