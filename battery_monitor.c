// battery_monitoring.c
#include <assert.h>
#include "battery_check.h"
#include "battery_warning.h"

int batteryIsOk(float temperature, float soc, float chargeRate, Language lang) {
    Check checks[] = {
        {isTemperatureInRange, temperature, 0, -1}, // No warning messages
        {isSocInRange, soc, 1, -1},
        {isChargeRateInRange, chargeRate, 2, -1}
    };

    if (!checkBatteryParameters(checks, sizeof(checks) / sizeof(checks[0]), lang)) {
        return 0;
    }

    Check warnings[] = {
        {isTemperatureLowWarning, temperature, -1, 0},
        {isTemperatureHighWarning, temperature, -1, 1},
        {isSocLowWarning, soc, -1, 2},
        {isSocHighWarning, soc, -1, 3},
        {isChargeRateHighWarning, chargeRate, -1, 4}
    };

    checkBatteryWarnings(warnings, sizeof(warnings) / sizeof(warnings[0]), lang);

    return 1;
}

int main() {
    Language lang = LANGUAGE_GERMAN; // Change to LANGUAGE_ENGLISH for English messages

    // Normal case
    assert(batteryIsOk(25, 70, 0.7, lang));   // Should pass without warnings or errors

    // Error cases
    assert(!batteryIsOk(50, 70, 0.1, lang));     // Temperature and SoC out of range
    assert(!batteryIsOk(30, 85, 0.1, lang));     // SoC out of range
    assert(!batteryIsOk(25, 70, 0.9, lang));   // Charge rate out of range

    // Warning cases
    assert(batteryIsOk(43, 70, 0.7, lang));   // Temperature approaching high limit
    assert(batteryIsOk(2, 70, 0.7, lang));    // Temperature approaching low limit
    assert(batteryIsOk(25, 78, 0.7, lang));   // SoC approaching high limit
    assert(batteryIsOk(25, 23, 0.7, lang));   // SoC approaching low limit
    assert(batteryIsOk(25, 70, 0.78, lang));  // Charge rate approaching high limit

    // Edge cases
    assert(batteryIsOk(2.24, 70, 0.7, lang));    // Temperature just outside low warning range (should be a warning now)
    assert(batteryIsOk(42.75, 70, 0.7, lang));   // Temperature just outside high warning range (should be a warning now)
    assert(batteryIsOk(20, 24, 0.7, lang));   // SoC just outside low warning range (should be a warning now)
    assert(batteryIsOk(25, 76, 0.7, lang));   // SoC exactly at high boundary (should not be a warning)
    assert(batteryIsOk(25, 70, 0.77, lang));  // Charge rate just outside high warning range (should be a warning)


    return 0;
}
