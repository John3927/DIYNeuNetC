#ifndef LAYER_H
#define LAYER_H

#include "activation.h"
#include <tuple>
#include <vector>

struct Edge {
  double weight;
  double bias;
};

class Layer {
private:
  int size;
  double *vals;
  double **weights;
  double **biases;

  Layer *prevLayer;
  Layer *nextLayer;

  virtual void activate();

  //=operator?

public:
  Layer();
  Layer(int s);
  Layer(int s, Layer *prev);
  Layer(int s, Layer *prev, Layer *next);
  void updateVal();
  ~Layer();
};

class ReLULayer : public Layer {
  void activate() override;
};

class TanH : public Layer {
  void activate() override;
};

#endif // !NODE_H
