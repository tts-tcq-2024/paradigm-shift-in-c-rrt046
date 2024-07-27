// battery_messages.h
#ifndef BATTERY_MESSAGES_H
#define BATTERY_MESSAGES_H

typedef enum {
    LANGUAGE_ENGLISH,
    LANGUAGE_GERMAN,
    // Add other languages here
    LANGUAGE_COUNT
} Language;

const char* getErrorMessage(Language lang, int index);
const char* getWarningMessage(Language lang, int index);

#endif // BATTERY_MESSAGES_H
