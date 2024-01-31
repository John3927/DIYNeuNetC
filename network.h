#ifndef NETWORK_H
#define NETWORK_H

#include "node.h"
#include <vector>

class Network {
private:
  std::vector<Node> outputs;

public:
  void evaluate();
};

#endif // !NETWORK_H
