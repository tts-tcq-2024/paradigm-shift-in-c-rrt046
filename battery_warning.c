#include <stdio.h>  // For printf
#include "battery_common.h"

void checkBatteryWarnings(Check warnings[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (warnings[i].check(warnings[i].value)) {
            printf("%s", warnings[i].warningMessage);
        }
    }
}
