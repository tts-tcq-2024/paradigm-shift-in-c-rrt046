// battery_check.h
#ifndef BATTERY_CHECK_H
#define BATTERY_CHECK_H

#include "battery_common.h"

// Check functions
bool isTemperatureInRange(float temperature);
bool isSocInRange(float soc);
bool isChargeRateInRange(float chargeRate);

#endif // BATTERY_CHECK_H
