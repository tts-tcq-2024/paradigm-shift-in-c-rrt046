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

void printOutOfRange(const char *parameter) {
    printf("%s out of range!\n", parameter);
}

int batteryIsOk(float temperature, int soc, float chargeRate) {
    if (!isTemperatureOk(temperature)) {
        printOutOfRange("Temperature");
        return 0;
    }
    if (!isSocOk(soc)) {
        printOutOfRange("State of Charge");
        return 0;
    }
    if (!isChargeRateOk(chargeRate)) {
        printOutOfRange("Charge Rate");
        return 0;
    }
    return 1;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
  
    return 0;
}
