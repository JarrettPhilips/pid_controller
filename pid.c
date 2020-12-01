#include "pid.h"

#include <stdio.h>

double calculate_response(double error, double dt, struct PID *controller){
  double response =   calculate_proportional(error, dt, controller)
                    + calculate_integral(error, dt, controller)
                    + calculate_derivative(error, dt, controller);
  printf("PID: %f \n", response);
  return response;
}

double calculate_proportional(double error, double dt, struct PID *controller){
  double proportional_response = error * dt * controller->kp;
  printf("P: %f \n", proportional_response);
  return proportional_response;
}

double calculate_integral(double error, double dt, struct PID *controller){
  controller->integral_sum = controller->integral_sum + (error*dt);
  double integral_response = controller->ki*controller->integral_sum;
  printf("I: %f \n", integral_response);
  return integral_response;
}

double calculate_derivative(double error, double dt, struct PID *controller){
  double derivative_response = (error - controller->previous_error)/dt;
  controller->previous_error = error;
  printf("D: %f \n", derivative_response);
  return derivative_response;
}
