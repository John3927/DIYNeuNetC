#ifndef NETWORK_H
#define NETWORK_H

#include <memory>
#include <vector>

class Network {
private:
  int inputSize;
  int outputSize;
  int numHiddenLayers;
  std::vector<std::unique_ptr<Node>> inputs;
  std::vector<int> hiddenLayerSizes; // length must be at least 2
  std::vector<std::unique_ptr<Node>> outputs;

  Activation defaultActivation;

public:
  Network();
  Network(int inSize, int outSize);
  // Network(int inSize, int outSize, int hiddenLayerSizes, ...);

  // copy this sizes bro
  Network(int inSize, int outSize, std::vector<int> hiddenSizes);

  // void evaluate(const double &inputs, ...);
  // call and forget
  std::vector<double> evaluate(const std::vector<double> &inputs);

  ~Network();
};

#endif // !NETWORK_H
