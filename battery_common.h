#ifndef BATTERY_COMMON_H
#define BATTERY_COMMON_H

typedef int (*CheckFunc)(float);

typedef struct {
    CheckFunc check;
    float value;
    const char *message;
    const char *warningMessage;
} Check;

void printMessage(const char *message);

#endif // BATTERY_COMMON_H
