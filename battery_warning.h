#ifndef BATTERY_WARNING_H
#define BATTERY_WARNING_H

#include <stdbool.h>
#include <stddef.h>

// Structure for warning checks
typedef struct {
    bool (*check)(float value);
    float value;
    const char* warningMessage;
} Check;

// Function prototypes
void checkBatteryWarnings(Check warnings[], size_t size);

// Warning functions
bool isTemperatureLowWarning(float temperature);
bool isTemperatureHighWarning(float temperature);
bool isSocLowWarning(float soc);
bool isSocHighWarning(float soc);
bool isChargeRateHighWarning(float chargeRate);

#endif // BATTERY_WARNING_H
