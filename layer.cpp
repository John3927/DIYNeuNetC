#include "layer.h"
#include "linalg.h"
#include <cmath>
#include <vector>

using std::vector;

// TODO dimensions
Layer::Layer()
    : size(1), vals(1, 0), weights(1, std::vector<double>(1, 0)),
      biases(1, std::vector<double>(1, 0)) {}
Layer::Layer(int s)
    : size(s), vals(s, 0), weights(s, std::vector<double>(1, 0)),
      biases(s, std::vector<double>(1, 0)) {}

Layer::Layer(int s, Layer *next)
    : size(s), vals(s, 0), weights(s, std::vector<double>(next->size, 0)),
      biases(s, std::vector<double>(next->size, 0)), nextLayer(next) {}
Layer::Layer(int s, Layer *next, Layer *prev)
    : size(s), vals(s, 0), weights(s, std::vector<double>(next->size, 0)),
      biases(s, std::vector<double>(next->size, 0)), prevLayer(prev),
      nextLayer(next) {}

Layer::~Layer() {}

void Layer::updateVal() {
  // weights times vals
  vals = matrixMult(prevLayer->weights, prevLayer->vals);
  // im not checking biases (im lazy)
  int prevS = prevLayer->size;

  for (int r = 0; r < size; ++r) {
    // i tracks A column vs B row
    for (int i = 0; i < prevS; ++i) {
      vals[r] += prevLayer->biases[i][r];
    }
  }

  activate();
}

void Layer::activate() {
  // base activate doesn't do anything
}

// 0 if negative
void ReLULayer::activate() {
  for (auto i = vals.begin(); i < vals.end(); i++) {
    *i = *i > 0 ? *i : 0;
  }
}

// tanh
void TanhLayer::activate() {
  for (auto i = vals.begin(); i < vals.end(); i++) {
    *i = tanh(*i);
  }
}
