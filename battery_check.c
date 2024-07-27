// battery_check.c
#include "battery_check.h"

bool isTemperatureInRange(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

bool isSocInRange(float soc) {
    return (soc >= 20 && soc <= 80);
}

bool isChargeRateInRange(float chargeRate) {
    return (chargeRate <= 0.8);
}
