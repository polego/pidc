/*
 * crc_16.c
 *
 * All rights reserved, Copyright Ogelop AB
 *
 * Created on: Feb 11, 2021
 *     Author: Niclas Wahllöf
 *
 */

#include <stdlib.h>
#include "pidc.h"

static long double value_adjusted;
static long double prev_err = 0.0;
static long double Ts = 1.0 / 1.0; // Sample time = 1/period
static long double K = 0.2;
static long double Ti = 320.0;
static long double Td = 3.0;


int32_t pidc_adjust(int32_t value) {
  long double err = 0.0;
  long double integral_part = 0.0;
  long double derivative_part = 0.0;

  // Use a PID controller to adjust value
  err = value_adjusted - value;
  integral_part += Ts / Ti * err;
  derivative_part =  Td / Ts * (err - prev_err);
  value_adjusted = value + K * (err + integral_part + derivative_part);
  prev_err = err;
  return (int32_t)value_adjusted;
}
