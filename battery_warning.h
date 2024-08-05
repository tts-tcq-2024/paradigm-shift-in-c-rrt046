// battery_warning.h
#ifndef BATTERY_WARNING_H
#define BATTERY_WARNING_H

#include "battery_common.h"

// Warning functions
bool isTemperatureLowWarning(float temperature);
bool isTemperatureHighWarning(float temperature);
bool isSocLowWarning(float soc);
bool isSocHighWarning(float soc);
bool isChargeRateHighWarning(float chargeRate);

#endif // BATTERY_WARNING_H
