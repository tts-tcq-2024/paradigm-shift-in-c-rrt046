#include <stdio.h>
#include <assert.h>

int isTemperatureOk(float temperature) {
    return (temperature >= 0 && temperature <= 45);
}

int isSocOk(int soc) {
    return (soc > 20 && soc < 80);
}

int isChargeRateOk(float chargeRate) {
    return (chargeRate < 0.8);
}

void printTemperatureOutOfRange() {
    printf("Temperature out of range!\n");
}

void printStateOfChargeOutOfRange() {
    printf("State of Charge out of range!\n");
}

void printChargeRateOutOfRange() {
    printf("Charge Rate out of range!\n");
}

int batteryIsOk(float temperature, int soc, float chargeRate) {
    if (!isTemperatureOk(temperature)) {
        printTemperatureOutOfRange();
        return 0;
    }
    if (!isSocOk(soc)) {
        printStateOfChargeOutOfRange();
        return 0;
    }
    if (!isChargeRateOk(chargeRate)) {
        printChargeRateOutOfRange();
        return 0;
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
}
