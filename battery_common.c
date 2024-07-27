// battery_common.c
#include "battery_common.h"
#include <stdio.h>

void printMessage(Language lang, const char *message) {
    printf("%s", message);
}

int checkBatteryParameters(Check checks[], int numChecks, Language lang) {
    for (int i = 0; i < numChecks; ++i) {
        if (!checks[i].check(checks[i].value)) {
            printMessage(lang, getErrorMessage(lang, checks[i].errorIndex));
            return 0;
        }
    }
    return 1;
}

int checkBatteryWarnings(Check warnings[], int numWarnings, Language lang) {
    for (int i = 0; i < numWarnings; ++i) {
        if (warnings[i].check(warnings[i].value)) {
            printMessage(lang, getWarningMessage(lang, warnings[i].warningIndex));
        }
    }
    return 1;
}
