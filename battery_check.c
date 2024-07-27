#include "battery_check.h"
#include "battery_messages.h"

// Dummy implementations for demonstration
_Bool isTemperatureInRange(float temp) { return temp >= 0 && temp <= 100; }
_Bool isSocInRange(float soc) { return soc >= 0 && soc <= 100; }
_Bool isChargeRateInRange(float rate) { return rate >= 0 && rate <= 1; }
_Bool isTemperatureLowWarning(float temp) { return temp < 5; }
_Bool isTemperatureHighWarning(float temp) { return temp > 95; }
_Bool isSocLowWarning(float soc) { return soc < 5; }
_Bool isSocHighWarning(float soc) { return soc > 95; }
_Bool isChargeRateHighWarning(float rate) { return rate > 0.9; }

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
