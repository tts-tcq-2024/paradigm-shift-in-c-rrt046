#include <stdio.h>
#include <assert.h>
#include "battery_check.h"
#include "localization_utils.h"

int main() {
    // Set and test with English messages
    setPreferredLanguage(ENGLISH);
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9));

    // Set and test with German messages
    setPreferredLanguage(GERMAN);
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(!batteryIsOk(30, 85, 0));
    assert(!batteryIsOk(25, 70, 0.9));

    return 0;
}
