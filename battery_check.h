// battery_check.h
#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

typedef int (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    const char *errorMessage;
    const char *warningMessage;
} Check;

int checkBatteryParameters(Check checks[], int numChecks);
int checkBatteryWarnings(Check warnings[], int numWarnings);

#endif // BATTERY_CHECK_H
