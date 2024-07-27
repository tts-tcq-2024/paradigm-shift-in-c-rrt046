#include "battery_messages.h"

extern Language currentLanguage;

const char* getTemperatureOutOfRangeMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Temperatur außerhalb des Bereichs!\n";
    }
    return "Temperature out of range!\n";
}

const char* getSocOutOfRangeMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Ladezustand außerhalb des Bereichs!\n";
    }
    return "State of Charge out of range!\n";
}

const char* getChargeRateOutOfRangeMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Ladegeschwindigkeit außerhalb des Bereichs!\n";
    }
    return "Charge Rate out of range!\n";
}

const char* getTemperatureLowWarningMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Warnung: Nähern sich der niedrigen Temperaturgrenze!\n";
    }
    return "Warning: Approaching low temperature limit!\n";
}

const char* getTemperatureHighWarningMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Warnung: Nähern sich der hohen Temperaturgrenze!\n";
    }
    return "Warning: Approaching high temperature limit!\n";
}

const char* getSocLowWarningMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Warnung: Nähern sich der niedrigen SoC-Grenze!\n";
    }
    return "Warning: Approaching low SoC limit!\n";
}

const char* getSocHighWarningMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Warnung: Nähern sich der hohen SoC-Grenze!\n";
    }
    return "Warning: Approaching high SoC limit!\n";
}

const char* getChargeRateHighWarningMessage() {
    if (currentLanguage == LANG_GERMAN) {
        return "Warnung: Nähern sich der hohen Ladegeschwindigkeitsgrenze!\n";
    }
    return "Warning: Approaching high charge rate limit!\n";
}
