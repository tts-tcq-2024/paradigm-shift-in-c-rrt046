#include "localization_utils.h"

// Global variable for storing the preferred language
static Language currentLanguage = ENGLISH;

// Function to set the preferred language
void setPreferredLanguage(Language lang) {
    currentLanguage = lang;
}

// Message arrays for each language
const char* messages[COUNT][3] = {
    [ENGLISH] = {
        "Temperature out of range!",
        "State of Charge out of range!",
        "Charge Rate out of range!"
    },
    [GERMAN] = {
        "Temperatur außerhalb des Bereichs!",
        "Ladezustand außerhalb des Bereichs!",
        "Laderate außerhalb des zulässigen Bereichs!"
    }
    // Add more languages here
};

// Message retrieval functions
const char* getTemperatureOutOfRangeMessage() {
    return messages[currentLanguage][0];
}

const char* getSocOutOfRangeMessage() {
    return messages[currentLanguage][1];
}

const char* getChargeRateOutOfRangeMessage() {
    return messages[currentLanguage][2];
}
