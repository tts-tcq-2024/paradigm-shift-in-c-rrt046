// main.c
#include <assert.h>
#include "battery_check.h"
#include "battery_warning.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, "Temperature out of range!\n", ""},
        {isSocInRange, soc, "State of Charge out of range!\n", ""},
        {isChargeRateInRange, chargeRate, "Charge Rate out of range!\n", ""}
    };

    if (!checkBatteryParameters(checks, sizeof(checks) / sizeof(checks[0]))) {
        return 0;
    }

    Check warnings[] = {
        {isTemperatureLowWarning, temperature, "", "Warning: Approaching low temperature limit!\n"},
        {isTemperatureHighWarning, temperature, "", "Warning: Approaching high temperature limit!\n"},
        {isSocLowWarning, soc, "", "Warning: Approaching low SoC limit!\n"},
        {isSocHighWarning, soc, "", "Warning: Approaching high SoC limit!\n"},
        {isChargeRateHighWarning, chargeRate, "", "Warning: Approaching high charge rate limit!\n"}
    };

    checkBatteryWarnings(warnings, sizeof(warnings) / sizeof(warnings[0]));

    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));   // Should pass without warnings or errors
    assert(!batteryIsOk(50, 85, 0));     // Temperature and SoC out of range
    assert(!batteryIsOk(30, 85, 0));     // SoC out of range
    assert(!batteryIsOk(25, 70, 0.9));   // Charge rate out of range

    // Warning cases
    assert(batteryIsOk(43, 70, 0.7));   // Temperature approaching high limit
    assert(batteryIsOk(3, 70, 0.7));    // Temperature approaching low limit
    assert(batteryIsOk(25, 78, 0.7));   // SoC approaching high limit
    assert(batteryIsOk(25, 23, 0.7));   // SoC approaching low limit
    assert(batteryIsOk(25, 70, 0.78));  // Charge rate approaching high limit

    // Edge cases
    assert(batteryIsOk(4, 70, 0.7));    // Temperature just outside low warning range (now should be a warning)
    assert(batteryIsOk(41, 70, 0.7));   // Temperature just outside high warning range (now should be a warning)
    assert(batteryIsOk(20, 24, 0.7));   // SoC just outside low warning range (now should be a warning)
    assert(batteryIsOk(80, 76, 0.7));   // SoC just outside high warning range (now should be a warning)
    assert(batteryIsOk(25, 70, 0.76));  // Charge rate just outside high warning range (now should be a warning)

    return 0;
}
