#include "battery_check.h"
#include "localization_utils.h"

int isTemperatureOk(float temperature) {
    if (temperature < 0 || temperature > 45) {
        printf("%s\n", getTemperatureOutOfRangeMessage());
        return 0; // Not okay
    }
    return 1; // Okay
}

int isSocOk(float soc) {
    if (soc < 20 || soc > 80) {
        printf("%s\n", getSocOutOfRangeMessage());
        return 0; // Not okay
    }
    return 1; // Okay
}

int isChargeRateOk(float chargeRate) {
    if (chargeRate > 0.8) {
        printf("%s\n", getChargeRateOutOfRangeMessage());
        return 0; // Not okay
    }
    return 1; // Okay
}

// Main battery check function
int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) &&
           isSocOk(soc) &&
           isChargeRateOk(chargeRate);
}
