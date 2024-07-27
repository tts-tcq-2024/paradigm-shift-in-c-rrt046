// battery_common.h
#ifndef BATTERY_COMMON_H
#define BATTERY_COMMON_H

#include <stdbool.h> 
#include "battery_messages.h"

typedef bool (*CheckFunc)(float); // Change CheckFunc to return bool

typedef struct {
    CheckFunc check;
    float value;
    int errorIndex;    // Changed to index
    int warningIndex;  // Changed to index
} Check;

// Function prototypes
void printMessage(Language lang, const char *message);
int checkBatteryParameters(Check checks[], int numChecks, Language lang);
int checkBatteryWarnings(Check warnings[], int numWarnings, Language lang);

#endif // BATTERY_COMMON_H
