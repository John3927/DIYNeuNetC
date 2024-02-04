#include "layer.h"

Layer::Layer()
    : size(1), vals(new double[1]), weights(new double *[1]),
      biases(new double *[1]) {}
Layer::Layer(int s)
    : size(s), vals(new double[s]), weights(new double *[s]),
      biases(new double *[s]) {}
Layer::Layer(int s, Layer *prev)
    : size(s), vals(new double[s]), weights(new double *[s]),
      biases(new double *[s]), prevLayer(prev) {}
Layer::Layer(int s, Layer *prev, Layer *next)
    : size(s), vals(new double[s]), weights(new double *[s]),
      biases(new double *[s]), prevLayer(prev), nextLayer(next) {}

Layer::~Layer() {
  delete[] vals;
  delete[] weights;
  delete[] biases;
}
