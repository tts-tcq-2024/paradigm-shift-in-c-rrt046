// battery_messages.c
#include "battery_messages.h"

// Messages for each language
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

// Utility function to check index validity
static const char* getMessage(const char* messages[], int index, int count) {
    return (index >= 0 && index < count) ? messages[index] : "Unknown message!\n";
}

const char* getErrorMessage(Language lang, int index) {
    return getMessage(errorMessages[lang], index, 3);
}

const char* getWarningMessage(Language lang, int index) {
    return getMessage(warningMessages[lang], index, 5);
}
