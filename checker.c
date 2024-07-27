// main.c
#include <assert.h>
#include "battery_check.h"
#include "battery_messages.h"

int main() {
    currentLanguage = LANG_ENGLISH; // Set to English
    assert(batteryIsOk(25, 70, 0.7)); // Normal case in English

    currentLanguage = LANG_GERMAN; // Set to German
    assert(batteryIsOk(25, 70, 0.7)); // Normal case in German

    return 0;
}
