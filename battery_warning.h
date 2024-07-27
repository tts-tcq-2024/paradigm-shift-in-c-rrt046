// battery_warning.h
#ifndef BATTERY_WARNING_H
#define BATTERY_WARNING_H

#include <stdbool.h>

bool isTemperatureLowWarning(float temperature);
bool isTemperatureHighWarning(float temperature);
bool isSocLowWarning(float soc);
bool isSocHighWarning(float soc);
bool isChargeRateHighWarning(float chargeRate);

#endif // BATTERY_WARNING_H
