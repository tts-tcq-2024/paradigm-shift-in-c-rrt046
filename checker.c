#include <assert.h>
#include "battery_check.h"
#include "battery_warning.h"

// Function to perform battery checks and warnings
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
    // Normal case, should pass without any warning messages
    assert(batteryIsOk(25, 70, 0.7));

    // Parameter breaches, should fail with respective error messages
    assert(!batteryIsOk(50, 85, 0));   // Temperature and SoC out of range
    assert(!batteryIsOk(30, 85, 0));   // SoC out of range
    assert(!batteryIsOk(25, 70, 0.9)); // Charge rate out of range

    // Warning cases
    // Temperature approaching high limit (43 is within high warning range)
    assert(batteryIsOk(43, 70, 0.7)); 

    // Temperature approaching low limit (3 is within low warning range)
    assert(batteryIsOk(3, 70, 0.7));

    // SoC approaching high limit (78 is within high warning range)
    assert(batteryIsOk(25, 78, 0.7));

    // SoC approaching low limit (23 is within low warning range)
    assert(batteryIsOk(25, 23, 0.7));

    // Charge rate approaching high limit (0.78 is within high warning range)
    assert(batteryIsOk(25, 70, 0.78));

    // Edge cases just outside the warning limits
    assert(!batteryIsOk(4, 70, 0.7));  // Temperature just outside low warning range
    assert(!batteryIsOk(41, 70, 0.7)); // Temperature just outside high warning range
    assert(!batteryIsOk(20, 24, 0.7)); // SoC just outside low warning range
    assert(!batteryIsOk(80, 76, 0.7)); // SoC just outside high warning range
    assert(!batteryIsOk(25, 70, 0.76)); // Charge rate just outside high warning range

    return 0;
}
