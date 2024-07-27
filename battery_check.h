// battery_check.h
#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include "battery_common.h"

// Check functions
int isTemperatureInRange(float temperature);
int isSocInRange(float soc);
int isChargeRateInRange(float chargeRate);

#endif // BATTERY_CHECK_H
