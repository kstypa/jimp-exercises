//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

int factorial(int value) {
  int k = 1;
  if (value >= 13)
    return 0;
  if (value == 0)
    return 1;
  if (value > 0) {
    for (int i = 1;i <= value;i++)
      k *= i;
  }
  if (value < 0) {
    for (int i = -1;i >= value;i--)
      k *= i;
  }
  return k;
}
