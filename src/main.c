/*
 * main.c
 *
 * All rights reserved, Copyright Ogelop AB
 *
 * Created on: Jun 21, 2022
 *     Author: Niclas Wahllöf
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pidc.h"

int main(int argc, char** argv) {
  int32_t value;  
  int32_t value_adjusted;

  while (scanf("%i", &value)) {
    value_adjusted = pidc_adjust(value);
    printf("%i\n", value_adjusted);
  }

  return 0;
}

