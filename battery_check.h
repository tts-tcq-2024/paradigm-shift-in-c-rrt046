#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include "battery_common.h"

int isTemperatureInRange(float temperature);
int isSocInRange(float soc);
int isChargeRateInRange(float chargeRate);
int checkBatteryParameters(Check *checks, int numChecks);

#endif // BATTERY_CHECK_H
