#ifndef BATTERY_MESSAGES_H
#define BATTERY_MESSAGES_H

typedef enum {
    LANGUAGE_ENGLISH,
    LANGUAGE_GERMAN,
    // Add other languages here
    LANGUAGE_COUNT
} Language;

void setLanguage(Language lang);
Language getLanguage(void);

const char* getErrorMessage(Language lang, int index);
const char* getWarningMessage(Language lang, int index);

// Messages for each language
extern const char* errorMessages[LANGUAGE_COUNT][3];
extern const char* warningMessages[LANGUAGE_COUNT][5];

#endif // BATTERY_MESSAGES_H
