#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include <memory>
#include <vector>

class Network {
private:
  int inputSize;
  int outputSize;
  // std::vector<int> hiddenLayerSizes;
  std::vector<Layer> layers;

public:
  Network();
  Network(int inSize, int outSize);
  // Network(int inSize, int outSize, int hiddenLayerSizes, ...);
  Network(int inSize, int outSize, int numHidden, int defaultHiddenLayerSize);

  // copy this sizes bro
  Network(int inSize, int outSize, std::vector<int> hiddenSizes);

  // void evaluate(const double &inputs, ...);
  // call and forget
  std::vector<double> foward(const std::vector<double> &inputs);

  ~Network();
};

#endif // !NETWORK_H
