#include "pid.h"

#include <stdio.h>

//testing driver
int main(){
  struct PID controller;
  controller.integral_sum = 0;
  controller.previous_error = 0;
  controller.kp = 2;
  controller.ki = 2;
  controller.kd = 2;

  double response = calculate_response(5, 1, &controller);
  response = calculate_response(6, 1, &controller);
  return 0;
}
