#include "network.h"
#include "node.h"
#include <memory>
#include <vector>

using std::make_unique;
using std::unique_ptr;
using std::vector;

Network::Network()
    : inputSize(1), outputSize(1), numHiddenLayers(0), inputs(1), outputs(1),
      defaultActivation() {
  inputs[0] = make_unique<Node>(defaultActivation);
}

Network::Network(int inSize, int outSize)
    : inputSize(inSize), outputSize(outSize), numHiddenLayers(0) {}

Network::Network(int inSize, int outSize, std::vector<int> hiddenSizes)
    : inputSize(inSize), outputSize(outSize),
      numHiddenLayers(hiddenSizes.size()), hiddenLayerSizes(hiddenSizes) {}

vector<double> Network::evaluate(const std::vector<double> &inputs) {

  // load outputs
  vector<double> results;
  for (auto &o : outputs) {
    results.push_back(o->getVal());
  }
  return results;
}
