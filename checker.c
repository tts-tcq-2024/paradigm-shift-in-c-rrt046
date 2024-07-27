#include "battery_check.h"
#include <assert.h>

int main() {
    // Normal case
    assert(batteryIsOk(25, 70, 0.7)); // Should pass without warnings or errors

    // Out of range cases
    assert(!batteryIsOk(50, 85, 0)); // Temperature and SoC out of range
    assert(!batteryIsOk(30, 85, 0)); // SoC out of range
    assert(!batteryIsOk(25, 70, 0.9)); // Charge rate out of range

    // Warning cases
    assert(batteryIsOk(43, 70, 0.7)); // Temperature approaching high limit
    assert(batteryIsOk(3, 70, 0.7)); // Temperature approaching low limit
    assert(batteryIsOk(25, 78, 0.7)); // SoC approaching high limit
    assert(batteryIsOk(25, 23, 0.7)); // SoC approaching low limit
    assert(batteryIsOk(25, 70, 0.78)); // Charge rate approaching high limit

    // Edge cases
    assert(!batteryIsOk(4, 70, 0.7)); // Temperature just outside low warning range
    assert(!batteryIsOk(41, 70, 0.7)); // Temperature just outside high warning range
    assert(!batteryIsOk(20, 24, 0.7)); // SoC just outside low warning range
    assert(batteryIsOk(25, 76, 0.7)); // SoC exactly at high boundary
    assert(!batteryIsOk(25, 70, 0.76)); // Charge rate just outside high warning range

    return 0;
}
