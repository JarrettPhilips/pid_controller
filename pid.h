#ifndef PID_H
#define PID_H

struct PID {
  double integral_sum;
  double previous_error;
  double kp;
  double ki;
  double kd;
};

double calculate_response(double error, double dt, struct PID *controller);
double calculate_proportional(double error, double dt, struct PID *controller);
double calculate_integral(double error, double dt, struct PID *controller);
double calculate_derivative(double error, double dt, struct PID *controller);

#endif
