#include "network.h"
#include "layer.h"
#include <cmath>
// #include <memory>
#include <random>
#include <stdexcept>
#include <vector>

// using std::make_shared;
using std::vector;

Network::Network() : inputSize(1), outputSize(1), layers(2) {
  // out layer
  layers[1] = new Layer(1);
  layers[0] = new Layer(1, layers[1]);
}

Network::Network(int inSize, int outSize)
    : inputSize(inSize), outputSize(outSize), layers(2) {
  layers[1] = new Layer(outSize);
  layers[0] = new Layer(inSize, layers[1]);
}

// constructor given number of
Network::Network(int inSize, int outSize, int numHidden,
                 int defaultHiddenLayerSize)
    : inputSize(inSize), outputSize(outSize), layers(2 + numHidden) {

  // output
  layers[numHidden + 1] = new Layer(outSize);

  // middle
  for (int i = numHidden; i >= 1; i--) {
    layers[i] = new Layer(defaultHiddenLayerSize, layers[i + 1]);
  }

  // input
  layers[0] = new Layer(inSize, layers[1]);
}

// construtor given arbitrary hidden layer sizes
Network::Network(int inSize, int outSize, std::vector<int> hiddenSizes)
    : inputSize(inSize), outputSize(outSize), layers(2 + hiddenSizes.size()) {
  int numHiddenLayers = hiddenSizes.size();
  layers[numHiddenLayers + 1] = new Layer(outSize);

  // middle
  for (int i = numHiddenLayers; i >= 0; i--) {
    layers[i] = new Layer(hiddenSizes[i - 1], layers[i + 1]);
  }

  // inpt
  layers[0] = new Layer(inSize, layers[1]);
}

vector<double> Network::forward(const std::vector<double> &inputs) {

  if (layers[0]->vals.size() != inputs.size()) {
    throw std::runtime_error("Wrong size of inputs");
  }
  layers[0]->vals = inputs;
  for (int i = 1; i < (int)layers.size(); ++i) {
    layers[i]->updateVal();
  }
  return layers.back()->vals;
}

// initialize parameters using Xavier Normal
void Network::initParam() {
  std::random_device device;
  std::default_random_engine generator(device());
  std::normal_distribution<double> normal;

  // skip last
  for (int i = 0; i < (int)layers.size() - 1; i++) {
    const auto &l = layers[i];
    l->bias = 0;
    // xavier normal
    normal = std::normal_distribution<double>(
        0, std::sqrt((double)2 / (l->size + layers[i + 1]->size)));

    // intialize weights
    for (auto &v : l->weights) {
      for (auto &w : v) {
        w = normal(generator);
      }
    }
  }
}

void Network::setActivation(ActivationType a) {
  for (auto &l : layers) {
    l->activationFunction = a;
  }
}
void Network::setActivation(int layerIndex, ActivationType a) {
  layers[layerIndex]->activationFunction = a;
}

void setActivation(int layerIndex, ActivationType a);

Network::~Network() {
  for (auto &l : layers) {
    delete l;
  }
}
