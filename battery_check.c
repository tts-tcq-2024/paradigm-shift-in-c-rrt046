// battery_check.c
#include "battery_check.h"
#include "battery_messages.h"

int batteryIsOk(float temperature, float soc, float chargeRate) {
    Check checks[] = {
        {isTemperatureInRange, temperature, getMessage("TEMP_OUT_OF_RANGE"), ""},
        {isSocInRange, soc, getMessage("SOC_OUT_OF_RANGE"), ""},
        {isChargeRateInRange, chargeRate, getMessage("CHARGE_RATE_OUT_OF_RANGE"), ""}
    };

    if (!checkBatteryParameters(checks, sizeof(checks) / sizeof(checks[0]))) {
        return 0;
    }

    Check warnings[] = {
        {isTemperatureLowWarning, temperature, "", getMessage("TEMP_LOW_WARNING")},
        {isTemperatureHighWarning, temperature, "", getMessage("TEMP_HIGH_WARNING")},
        {isSocLowWarning, soc, "", getMessage("SOC_LOW_WARNING")},
        {isSocHighWarning, soc, "", getMessage("SOC_HIGH_WARNING")},
        {isChargeRateHighWarning, chargeRate, "", getMessage("CHARGE_RATE_HIGH_WARNING")}
    };

    checkBatteryWarnings(warnings, sizeof(warnings) / sizeof(warnings[0]));

    return 1;
}
