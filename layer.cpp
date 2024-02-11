#include "layer.h"
#include <cmath>
#include <iostream>
// #include <memory>
#include <vector>

// using std::shared_ptr;
using std::vector;

Layer::Layer()
    : vals(1, 0), size(1), bias(0), weights(1, std::vector<double>(1, 0)) {}
Layer::Layer(int s)
    : vals(s, 0), size(s), bias(0), weights(s, std::vector<double>(1, 0)) {}

Layer::Layer(int s, Layer *next)
    : vals(s, 0), size(s), bias(0),
      weights(s, std::vector<double>(next->size, 0)), nextLayer(next) {
  next->prevLayer = this;
}

Layer::Layer(int s, Layer *next, Layer *prev)
    : vals(s, 0), size(s), bias(0),
      weights(s, std::vector<double>(next->size, 0)), prevLayer(prev),
      nextLayer(next) {

  next->prevLayer = this;
  prev->nextLayer = this;

  // resize, this messes the number of columns
  for (auto &v : prev->weights)
    v.resize(s);
}

Layer::~Layer() { std::cout << this << " layer deleted" << std::endl; }

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
  switch (activationFunction) {
  case RELU:
    reluActivate();
    break;

  case TANH:
    tanhActivate();
    break;

  case LINEAR:
  default:
    break;
  }
}

void Layer::reluActivate() {
  for (auto i = vals.begin(); i < vals.end(); i++) {
    *i = *i > 0 ? *i : 0;
  }
}

// tanh
void Layer::tanhActivate() {
  for (auto i = vals.begin(); i < vals.end(); i++) {
    *i = tanh(*i);
  }
}
// 0 if negative
// void ReLULayer::activate() {
//   for (auto i = vals.begin(); i < vals.end(); i++) {
//     *i = *i > 0 ? *i : 0;
//   }
// }

// // tanh
// void TanhLayer::activate() {
//   for (auto i = vals.begin(); i < vals.end(); i++) {
//     *i = tanh(*i);
//   }
// }
