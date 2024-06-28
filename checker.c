#include <stdio.h>
#include <assert.h>

void isTemperatureOutOfRange(float temperature) {
    if (temperature <= 0 || temperature >= 45) {
        printf("Temperature out of range!\n");
    }
}

void isSocOutOfRange(float soc) {
    if (soc < 20 || soc > 80) {
        printf("State of Charge out of range!\n");
    }
}

void isChargeRateOutOfRange(float chargeRate) {
    if (chargeRate > 0.8) {
        printf("Charge Rate out of range!\n");
    }
}

void batteryIsOk(float temperature, float soc, float chargeRate) {
    isTemperatureOutOfRange(temperature);
    isSocOutOfRange(soc);
    isChargeRateOutOfRange(chargeRate);
}

int main() {
    batteryIsOk(25, 70, 0.7);
    batteryIsOk(50, 85, 0);

    return 0;
}
