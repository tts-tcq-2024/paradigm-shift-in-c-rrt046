// battery_warning.c
#include "battery_warning.h"

#define TEMP_LOW_WARNING 2.25
#define TEMP_HIGH_WARNING 42.75
#define SOC_LOW_WARNING 24
#define SOC_HIGH_WARNING 76
#define CHARGE_RATE_HIGH_WARNING 0.76

bool isTemperatureLowWarning(float temperature) {
    return (temperature >= 0 && temperature <= TEMP_LOW_WARNING);
}

bool isTemperatureHighWarning(float temperature) {
    return (temperature >= TEMP_HIGH_WARNING && temperature <= 45);
}

bool isSocLowWarning(float soc) {
    return (soc >= 20 && soc <= SOC_LOW_WARNING);
}

bool isSocHighWarning(float soc) {
    return (soc >= SOC_HIGH_WARNING && soc <= 80);
}

bool isChargeRateHighWarning(float chargeRate) {
    return (chargeRate >= CHARGE_RATE_HIGH_WARNING && chargeRate <= 0.8);
}
