#include "battery_warning.h"
#include "messages.h"
#include <stdio.h>

// Check if the temperature is approaching the low warning limit
bool isTemperatureLowWarning(float temperature) {
    return temperature < 5.0; // Example low warning threshold
}

// Check if the temperature is approaching the high warning limit
bool isTemperatureHighWarning(float temperature) {
    return temperature > 35.0; // Example high warning threshold
}

// Check if the SoC is approaching the low warning limit
bool isSocLowWarning(float soc) {
    return soc < 25.0; // Example low warning threshold
}

// Check if the SoC is approaching the high warning limit
bool isSocHighWarning(float soc) {
    return soc > 75.0; // Example high warning threshold
}

// Check if the charge rate is approaching the high warning limit
bool isChargeRateHighWarning(float chargeRate) {
    return chargeRate > 0.9; // Example high warning threshold
}

// Implement the function to check battery warnings
void checkBatteryWarnings(Check warnings[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (warnings[i].check(warnings[i].value)) {
            printf("%s\n", warnings[i].warningMessage);
        }
    }
}
