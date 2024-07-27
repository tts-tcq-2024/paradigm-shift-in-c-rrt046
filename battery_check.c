// battery_check.c
#include <stdio.h>
#include "battery_check.h"
#include "battery_warning.h"

void printMessage(const char *message) {
    printf("%s", message);
}

int checkBatteryParameters(Check checks[], int numChecks) {
    for (int i = 0; i < numChecks; ++i) {
        if (!checks[i].check(checks[i].value)) {
            printMessage(checks[i].errorMessage);
            return 0;
        }
    }
    return 1;
}

int checkBatteryWarnings(Check warnings[], int numWarnings) {
    for (int i = 0; i < numWarnings; ++i) {
        if (warnings[i].check(warnings[i].value)) {
            printMessage(warnings[i].warningMessage);
        }
    }
    return 1;
}
