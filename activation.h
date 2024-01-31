#ifndef ACTIVATION_H
#define ACTIVATION_H

#include <math.h>

class Activation {
public:
  virtual double operator()(double d) { return d; };
};

class ReLU : public Activation {
public:
  double operator()(double d) override { return d > 0 ? d : 0; }
};

class Tanh : public Activation {
public:
  double operator()(double d) override { return tanh(d); }
};
#endif // !ACTIVATION_H
