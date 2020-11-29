#include "pid.h"

#include <stdio.h>

//double integral_sum = 0;

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
  double derivative_response = 0.0;
  printf("D: %f \n", derivative_response);
  return derivative_response;
}

//testing driver
int main(){
  struct PID controller;
  controller.integral_sum = 0;
  controller.kp = 2;
  controller.ki = 2;
  controller.kd = 2;


  double response = calculate_response(5, 1, &controller);
  response = calculate_response(5, 1, &controller);
  return 0;
}
