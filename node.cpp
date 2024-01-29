#include "node.h"
#include <tuple>

using std::pair;

void Node::updateVal() {
  double sum = 0;
  for (pair<Edge, Node> edgedNode : parents) {
    sum += edgedNode.second.val * edgedNode.first.weight + edgedNode.first.bias;
  }
  val = activationFunction(sum);
}

void Node::addParent(pair<Edge, Node> &edgedParent) {
  parents.push_back(edgedParent);
}
