#ifndef NODE_H
#define NODE_H

#include "activation.h"
#include <tuple>
#include <vector>

struct Edge {
  double weight;
  double bias;
};

class Node {
private:
  double val;
  Activation activationFunction;

  std::vector<std::pair<Edge, Node>> parents;

public:
  Node(double d, Activation &a) : val(d), activationFunction(a) {}
  Node(Activation &a) : val(0), activationFunction(a) {}

  void addParent(std::pair<Edge, Node> &edgedParent);
  void updateVal();
  double getVal() const { return val; }

  ~Node();
};

#endif // !NODE_H
