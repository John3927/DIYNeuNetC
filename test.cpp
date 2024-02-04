#include "activation.h"
#include "linalg.h"
#include "node.h"
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

void testMatVecMult() {
  cout << "Testing mat vec multi..." << endl;
  vector<vector<double>> A = {{1, 2}, {3, 4}};
  vector<double> B = {-2, 7};

  vector<double> result = matrixMult(A, B);
  assert(result[0] == 19);
  assert(result[1] == 24);
}

int main(int argc, char *argv[]) {

  testMatVecMult();
  cout << "All tests passed!" << endl;

  return 0;
}
