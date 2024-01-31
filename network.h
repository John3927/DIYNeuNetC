#ifndef NETWORK_H
#define NETWORK_H

#include "node.h"
#include <vector>

class Network {
private:
  int inputSize;
  int outputSize;
  int numHiddenLayers;
  std::vector<int> hiddenLayerSizes; // length must be at least 2
  std::vector<Node> outputs;

public:
  Network();
  Network(int inSize, int outSize);
  Network(int inSize, int outSize, int hiddenLayerSizes...);

  void evaluate(const double &inputs...);
};

#endif // !NETWORK_H
