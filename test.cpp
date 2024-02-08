#include "layer.h"
#include "network.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

// void testMatVecMult() {
//   cout << "Testing mat vec multi..." << endl;
//   vector<vector<double>> A = {{1, 2}, {3, 4}};
//   vector<double> B = {-2, 7};

//   vector<double> result = matrixMult(A, B);
//   assert(result[0] == 19);
//   assert(result[1] == 24);
// }
//
//
void testLayer() {
  auto l1 = make_shared<Layer>(2);
  auto l2 = make_shared<Layer>(2, l1);
}

void testLotsOfThings() {

  Network net(2, 1, 2, 2);
  net.initParam();
  auto result = net.foward(vector<double>{5, 6});
  cout << result[0] << endl;
}

int main(int argc, char *argv[]) {

  // testMatVecMult();
  testLayer();
  // testLotsOfThings();
  cout << "All tests passed!" << endl;

  return 0;
}
