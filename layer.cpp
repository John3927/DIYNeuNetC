#include "layer.h"
#include <cmath>
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

Layer::Layer()
    : size(1), vals(1, 0), bias(0), weights(1, std::vector<double>(1, 0)) {}
Layer::Layer(int s)
    : size(s), vals(s, 0), bias(0), weights(s, std::vector<double>(1, 0)) {}

Layer::Layer(int s, shared_ptr<Layer> next)
    : size(s), vals(s, 0), bias(0),
      weights(s, std::vector<double>(next->size, 0)), nextLayer(next) {
  next->prevLayer = shared_ptr<Layer>(this);
}

Layer::Layer(int s, shared_ptr<Layer> next, shared_ptr<Layer> prev)
    : size(s), vals(s, 0), bias(0),
      weights(s, std::vector<double>(next->size, 0)), prevLayer(prev),
      nextLayer(next) {

  next->prevLayer = shared_ptr<Layer>(this);
  prev->nextLayer = shared_ptr<Layer>(this);

  // resize, this messes the number of columns
  for (auto &v : prev->weights)
    v.resize(s);
}

Layer::~Layer() {}

void Layer::updateVal() {
  // weights times vals
  // TODO why dont i do it in one go
  // im not checking biases (im lazy)
  int prevS = prevLayer->size;

  // weights.size() columns = prevS =
  // vals.size = prevS
  // weights[0].size (roww) = r = current size
  for (int r = 0; r < size; ++r) {
    // i tracks A column vs B row
    for (int i = 0; i < prevS; ++i) {
      vals[r] += prevLayer->weights[i][r] * prevLayer->vals[i];
    }
    vals[r] += prevLayer->bias;
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
