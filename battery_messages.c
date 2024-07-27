#include "battery_messages.h"
#include <string.h>

extern Language currentLanguage;

// Define the structure for storing messages
typedef struct {
    Language language;
    const char* key;
    const char* message;
} MessageEntry;

// Define the message table
static const MessageEntry messageTable[] = {
    {LANG_ENGLISH, "TEMP_OUT_OF_RANGE", "Temperature out of range!\n"},
    {LANG_GERMAN, "TEMP_OUT_OF_RANGE", "Temperatur außerhalb des Bereichs!\n"},
    
    {LANG_ENGLISH, "SOC_OUT_OF_RANGE", "State of Charge out of range!\n"},
    {LANG_GERMAN, "SOC_OUT_OF_RANGE", "Ladezustand außerhalb des Bereichs!\n"},
    
    {LANG_ENGLISH, "CHARGE_RATE_OUT_OF_RANGE", "Charge Rate out of range!\n"},
    {LANG_GERMAN, "CHARGE_RATE_OUT_OF_RANGE", "Ladegeschwindigkeit außerhalb des Bereichs!\n"},
    
    {LANG_ENGLISH, "TEMP_LOW_WARNING", "Warning: Approaching low temperature limit!\n"},
    {LANG_GERMAN, "TEMP_LOW_WARNING", "Warnung: Nähern sich der niedrigen Temperaturgrenze!\n"},
    
    {LANG_ENGLISH, "TEMP_HIGH_WARNING", "Warning: Approaching high temperature limit!\n"},
    {LANG_GERMAN, "TEMP_HIGH_WARNING", "Warnung: Nähern sich der hohen Temperaturgrenze!\n"},
    
    {LANG_ENGLISH, "SOC_LOW_WARNING", "Warning: Approaching low SoC limit!\n"},
    {LANG_GERMAN, "SOC_LOW_WARNING", "Warnung: Nähern sich der niedrigen SoC-Grenze!\n"},
    
    {LANG_ENGLISH, "SOC_HIGH_WARNING", "Warning: Approaching high SoC limit!\n"},
    {LANG_GERMAN, "SOC_HIGH_WARNING", "Warnung: Nähern sich der hohen SoC-Grenze!\n"},
    
    {LANG_ENGLISH, "CHARGE_RATE_HIGH_WARNING", "Warning: Approaching high charge rate limit!\n"},
    {LANG_GERMAN, "CHARGE_RATE_HIGH_WARNING", "Warnung: Nähern sich der hohen Ladegeschwindigkeitsgrenze!\n"}
};

// Function to get the localized message
const char* getMessage(const char* key) {
    for (size_t i = 0; i < sizeof(messageTable) / sizeof(messageTable[0]); ++i) {
        if (messageTable[i].language == currentLanguage && strcmp(messageTable[i].key, key) == 0) {
            return messageTable[i].message;
        }
    }
    return ""; // Return empty string if message not found
}
