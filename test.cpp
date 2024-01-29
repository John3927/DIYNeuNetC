#include "activation.h"
#include "node.h"
#include <iostream>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {

  ReLU r;

  Node node1(3, r);
  Edge edge1 = {2, 1};
  pair<Edge, Node> n1F = std::make_pair(edge1, node1);

  Node node2(1, r);
  Edge edge2 = {4, 0};
  pair<Edge, Node> n2F = std::make_pair(edge2, node2);
  Node nodeF(0, r);

  nodeF.addParent(n1F);
  nodeF.addParent(n2F);

  nodeF.updateVal();

  cout << nodeF.getVale() << endl;

  return 0;
}
