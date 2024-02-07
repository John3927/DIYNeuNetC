#ifndef LAYER_H
#define LAYER_H

#include "activation.h"
#include <memory>
#include <tuple>
#include <vector>

// struct Edge {
//   double weight;
//   double bias;
// };

class Layer {

protected:
  std::vector<double> vals;

private:
  int size;

  double bias;
  // both are coloumn major
  // columns represent what each val
  // contribute to each result
  // value in i col j row is the contribution of the
  // i th variable to the j th output
  //  [i][j] goes from ith input to jth output
  std::vector<std::vector<double>> weights;
  // std::vector<std::vector<double>> biases;

  std::shared_ptr<Layer> prevLayer;
  std::shared_ptr<Layer> nextLayer;

  virtual void activate();

  //=operator?

public:
  Layer();
  Layer(int s);
  Layer(int s, std::shared_ptr<Layer> next);
  Layer(int s, std::shared_ptr<Layer> next, std::shared_ptr<Layer> prev);
  void updateVal();
  std::vector<double> getVals() const { return vals; }
  ~Layer();

  friend class Network;
};

class ReLULayer : public Layer {
  using Layer::Layer;
  void activate() override;
};

class TanhLayer : public Layer {
  using Layer::Layer;
  void activate() override;
};

#endif // !NODE_H
