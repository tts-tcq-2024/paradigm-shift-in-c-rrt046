#include "battery_warning.h"
#include "battery_check.h"
#include <stdio.h>  // For printf

void checkBatteryWarnings(Check warnings[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (warnings[i].check(warnings[i].value)) {
            printf("%s", warnings[i].warningMessage);
        }
    }
}
