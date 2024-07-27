#include "battery_check.h"
#include "battery_messages.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, getTemperatureOutOfRangeMessage(), ""},
        {isSocInRange, soc, getSocOutOfRangeMessage(), ""},
        {isChargeRateInRange, chargeRate, getChargeRateOutOfRangeMessage(), ""}
    };

    if (!checkBatteryParameters(checks, sizeof(checks) / sizeof(checks[0]))) {
        return 0;
    }

    Check warnings[] = {
        {isTemperatureLowWarning, temperature, "", getTemperatureLowWarningMessage()},
        {isTemperatureHighWarning, temperature, "", getTemperatureHighWarningMessage()},
        {isSocLowWarning, soc, "", getSocLowWarningMessage()},
        {isSocHighWarning, soc, "", getSocHighWarningMessage()},
        {isChargeRateHighWarning, chargeRate, "", getChargeRateHighWarningMessage()}
    };

    checkBatteryWarnings(warnings, sizeof(warnings) / sizeof(warnings[0]));

    return 1;
}
