#include "battery_messages.h"
#include <stdio.h>  // For printf (for demo purposes)
#include <string.h> // For strcmp

// Example message retrieval
const char* getMessage(const char* key) {
    // Simple implementation for demonstration; replace with actual localization logic
    if (strcmp(key, "TEMP_OUT_OF_RANGE") == 0) return "Temperature out of range!\n";
    if (strcmp(key, "SOC_OUT_OF_RANGE") == 0) return "State of Charge out of range!\n";
    if (strcmp(key, "CHARGE_RATE_OUT_OF_RANGE") == 0) return "Charge Rate out of range!\n";
    if (strcmp(key, "TEMP_LOW_WARNING") == 0) return "Warning: Approaching low temperature limit!\n";
    if (strcmp(key, "TEMP_HIGH_WARNING") == 0) return "Warning: Approaching high temperature limit!\n";
    if (strcmp(key, "SOC_LOW_WARNING") == 0) return "Warning: Approaching low SoC limit!\n";
    if (strcmp(key, "SOC_HIGH_WARNING") == 0) return "Warning: Approaching high SoC limit!\n";
    if (strcmp(key, "CHARGE_RATE_HIGH_WARNING") == 0) return "Warning: Approaching high charge rate limit!\n";
    return "Unknown message key!\n";
}
