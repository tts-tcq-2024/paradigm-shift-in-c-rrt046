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
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9));
    return 0;
}
