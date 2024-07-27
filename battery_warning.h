#ifndef BATTERY_WARNING_H
#define BATTERY_WARNING_H

#include "battery_common.h"

int isTemperatureLowWarning(float temperature);
int isTemperatureHighWarning(float temperature);
int isSocLowWarning(float soc);
int isSocHighWarning(float soc);
int isChargeRateHighWarning(float chargeRate);
void checkBatteryWarnings(Check *warnings, int numWarnings);

#endif // BATTERY_WARNING_H
