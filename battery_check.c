#include "battery_check.h"
#include "messages.h"
#include <stdio.h>

// Example tolerance values (in percentage) for warning thresholds
float warningTolerances[NUM_TOLERANCES] = {5.0, 5.0, 5.0};

// Function to get localized messages (for simplicity, just returning hardcoded messages)
const char* getMessage(const char* key) {
    // In a real application, you'd look up translations based on the key and current language
    if (strcmp(key, "TEMP_OUT_OF_RANGE") == 0) return "Temperature out of range!";
    if (strcmp(key, "SOC_OUT_OF_RANGE") == 0) return "State of Charge out of range!";
    if (strcmp(key, "CHARGE_RATE_OUT_OF_RANGE") == 0) return "Charge Rate out of range!";
    return "";
}

// Check if the temperature is within range
bool isTemperatureInRange(float temperature) {
    return temperature >= 0 && temperature <= 40; // Example range
}

// Check if the SoC is within range
bool isSocInRange(float soc) {
    return soc >= 20 && soc <= 80; // Example range
}

// Check if the charge rate is within range
bool isChargeRateInRange(float chargeRate) {
    return chargeRate >= 0 && chargeRate <= 1; // Example range
}

// Check all battery parameters and print appropriate messages
bool checkBatteryParameters(Check checks[], size_t size) {
    bool allOk = true;
    for (size_t i = 0; i < size; ++i) {
        if (!checks[i].check(checks[i].value)) {
            printf("%s\n", checks[i].errorMessage);
            allOk = false;
        }
    }
    return allOk;
}

// Main function to check if battery parameters are ok
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, getMessage("TEMP_OUT_OF_RANGE")},
        {isSocInRange, soc, getMessage("SOC_OUT_OF_RANGE")},
        {isChargeRateInRange, chargeRate, getMessage("CHARGE_RATE_OUT_OF_RANGE")}
    };

    Check warnings[] = {
        {isTemperatureLowWarning, temperature, "", getMessage("TEMP_LOW_WARNING")},
        {isTemperatureHighWarning, temperature, "", getMessage("TEMP_HIGH_WARNING")},
        {isSocLowWarning, soc, "", getMessage("SOC_LOW_WARNING")},
        {isSocHighWarning, soc, "", getMessage("SOC_HIGH_WARNING")},
        {isChargeRateHighWarning, chargeRate, "", getMessage("CHARGE_RATE_HIGH_WARNING")}
    };

    // Check if all parameters are within range
    bool parametersOk = checkBatteryParameters(checks, sizeof(checks) / sizeof(checks[0]));

    // Check if there are any warnings
    bool warningsOk = checkBatteryWarnings(warnings, sizeof(warnings) / sizeof(warnings[0]));

    return parametersOk && warningsOk;
}
