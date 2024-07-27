// battery_common.c
#include "battery_common.h"
#include "battery_messages.h"

Language currentLanguage = LANG_ENGLISH; // Default language

void printMessage(const char *message) {
    printf("%s", message);
}
