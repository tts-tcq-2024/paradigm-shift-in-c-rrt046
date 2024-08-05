#ifndef BATTERY_COMMON_H
#define BATTERY_COMMON_H

#include <stdbool.h> 
#include "battery_messages.h"

typedef bool (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    int errorIndex;    // Changed to index
    int warningIndex;  // Changed to index
} Check;

// Function prototypes
void printMessage(const char *message);
int checkBatteryParameters(Check checks[], int numChecks);
int checkBatteryWarnings(Check warnings[], int numWarnings);

#endif // BATTERY_COMMON_H
