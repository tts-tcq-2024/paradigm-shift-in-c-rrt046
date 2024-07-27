// battery_messages.c
#include "battery_messages.h"

static const char* errorMessages[LANGUAGE_COUNT][3] = {
    [LANGUAGE_ENGLISH] = {
        "Temperature out of range!\n",
        "State of Charge out of range!\n",
        "Charge Rate out of range!\n"
    },
    [LANGUAGE_GERMAN] = {
        "Temperatur außerhalb des Bereichs!\n",
        "Ladezustand außerhalb des Bereichs!\n",
        "Ladungsrate außerhalb des Bereichs!\n"
    }
};

static const char* warningMessages[LANGUAGE_COUNT][5] = {
    [LANGUAGE_ENGLISH] = {
        "Warning: Approaching low temperature limit!\n",
        "Warning: Approaching high temperature limit!\n",
        "Warning: Approaching low SoC limit!\n",
        "Warning: Approaching high SoC limit!\n",
        "Warning: Approaching high charge rate limit!\n"
    },
    [LANGUAGE_GERMAN] = {
        "Warnung: Annäherung an die niedrige Temperaturgrenze!\n",
        "Warnung: Annäherung an die hohe Temperaturgrenze!\n",
        "Warnung: Annäherung an die niedrige SoC-Grenze!\n",
        "Warnung: Annäherung an die hohe SoC-Grenze!\n",
        "Warnung: Annäherung an die hohe Ladegrenzrate!\n"
    }
};

const char* getErrorMessage(Language lang, int index) {
    if (lang < LANGUAGE_COUNT && index >= 0 && index < 3) {
        return errorMessages[lang][index];
    }
    return "Unknown error message!\n";
}

const char* getWarningMessage(Language lang, int index) {
    if (lang < LANGUAGE_COUNT && index >= 0 && index < 5) {
        return warningMessages[lang][index];
    }
    return "Unknown warning message!\n";
}
