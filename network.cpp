#include "network.h"
#include "layer.h"
#include <cmath>
#include <memory>
#include <random>
#include <vector>

using std::make_shared;
using std::vector;

Network::Network() : inputSize(1), outputSize(1), layers(2) {
  // out layer
  layers[1] = make_shared<Layer>(1);
  layers[0] = make_shared<Layer>(1, layers[1]);
}

Network::Network(int inSize, int outSize)
    : inputSize(inSize), outputSize(outSize), layers(2) {
  layers[1] = make_shared<Layer>(outSize);
  layers[0] = make_shared<Layer>(inSize, &layers[1]);
}

// constructor given number of
Network::Network(int inSize, int outSize, int numHidden,
                 int defaultHiddenLayerSize)
    : inputSize(inSize), outputSize(outSize), layers(2 + numHidden) {

  // output
  layers[numHidden + 1] = make_shared<Layer>(outSize);

  // middle
  for (int i = numHidden; i >= 1; i--) {
    layers[i] = make_shared<Layer>(defaultHiddenLayerSize, &layers[i]);
  }

  // input
  layers[0] = make_shared<Layer>(inSize, &layers[1]);
}

// construtor given arbitrary hidden layer sizes
Network::Network(int inSize, int outSize, std::vector<int> hiddenSizes)
    : inputSize(inSize), outputSize(outSize), layers(2 + hiddenSizes.size()) {
  int numHiddenLayers = hiddenSizes.size();
  layers[numHiddenLayers + 1] = make_shared<Layer>(outSize);

  // middle
  for (int i = numHiddenLayers; i >= 0; i--) {
    layers[i] = make_shared<Layer>(hiddenSizes[i - 1], &layers[i]);
  }

  // inpt
  layers[0] = make_shared<Layer>(inSize, &layers[1]);
}

vector<double> Network::foward(const std::vector<double> &inputs) {

  layers[0]->vals = inputs;
  for (int i = 1; i < layers.size(); ++i) {
    layers[i]->updateVal();
  }
  return layers.back()->vals;
}

void Network::initParam() {
  std::default_random_engine generator;
  std::normal_distribution<double> normal;

  // skip last
  for (int i = 0; i < layers.size() - 1; i++) {
    const auto &l = layers[i];
    l->bias = 0;
    // xavier normal
    normal = std::normal_distribution<double>(
        0, std::sqrt(2 / (l->size + l->nextLayer->size)));

    // intialize weights
    for (auto &v : l->weights) {
      for (auto &w : v) {
        w = normal(generator);
      }
    }
  }
}
