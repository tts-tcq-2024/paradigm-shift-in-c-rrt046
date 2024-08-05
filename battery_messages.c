// battery_messages.c
#include "battery_messages.h"

Language currentLanguage = LANGUAGE_ENGLISH;

void setLanguage(Language lang) {
    if (lang < LANGUAGE_COUNT) {
        currentLanguage = lang;
    }
}

Language getLanguage(void) {
    return currentLanguage;
}

// Existing message arrays and functions
// ...
