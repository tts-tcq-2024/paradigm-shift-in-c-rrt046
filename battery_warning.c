// battery_warning.c
#include <stdio.h>
#include "battery_warning.h"

int isTemperatureLowWarning(float temperature) {
    return (temperature >= 0 && temperature < 4);
}

int isTemperatureHighWarning(float temperature) {
    return (temperature > 41 && temperature < 45);
}

int isSocLowWarning(float soc) {
    return (soc >= 20 && soc < 24);
}

int isSocHighWarning(float soc) {
    return (soc > 76 && soc < 80);
}

int isChargeRateHighWarning(float chargeRate) {
    return (chargeRate > 0.76 && chargeRate <= 0.8);
}

void checkBatteryWarnings(Check *warnings, int numWarnings) {
    for (int i = 0; i < numWarnings; ++i) {
        if (warnings[i].check(warnings[i].value)) {
            printMessage(warnings[i].warningMessage);
        }
    }
}
