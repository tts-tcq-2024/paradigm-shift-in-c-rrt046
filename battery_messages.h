// battery_messages.h
#ifndef BATTERY_MESSAGES_H
#define BATTERY_MESSAGES_H

#include "battery_common.h"

const char* getTemperatureOutOfRangeMessage();
const char* getSocOutOfRangeMessage();
const char* getChargeRateOutOfRangeMessage();
const char* getTemperatureLowWarningMessage();
const char* getTemperatureHighWarningMessage();
const char* getSocLowWarningMessage();
const char* getSocHighWarningMessage();
const char* getChargeRateHighWarningMessage();

#endif // BATTERY_MESSAGES_H
