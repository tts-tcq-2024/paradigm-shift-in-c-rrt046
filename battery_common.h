// battery_common.h
#ifndef BATTERY_COMMON_H
#define BATTERY_COMMON_H

typedef int (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    const char *errorMessage;
    const char *warningMessage;
} Check;

// Function prototypes
void printMessage(const char *message);
int checkBatteryParameters(Check checks[], int numChecks);
int checkBatteryWarnings(Check warnings[], int numWarnings);

#endif // BATTERY_COMMON_H
