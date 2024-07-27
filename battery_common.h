// battery_common.h
#ifndef BATTERY_COMMON_H
#define BATTERY_COMMON_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "battery_messages.h"
#include "battery_check.h"
#include "battery_warning.h"

typedef enum {
    LANG_ENGLISH,
    LANG_GERMAN,
    // Add more languages here
} Language;

extern Language currentLanguage;

void printMessage(const char *message);

#endif // BATTERY_COMMON_H
