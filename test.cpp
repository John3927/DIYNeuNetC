#include "layer.h"
#include "network.h"
#include <iostream>
// #include <memory>
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
class Test {
public:
  static void testLayer() {
    auto l1 = new Layer(2);
    auto l2 = new Layer(2);
    // auto l2 = make_shared<Layer>(2, l1);

    l2->nextLayer = l1;

    cout << "so far so good \n";

    auto l3 = new Layer(2, l2);

    delete l1;
    delete l2;
    delete l3;
  }

  static void testLotsOfThings() {

    cout << "testing a lot of things" << endl;
    Network net(8, 1, 4, 8);
    cout << "constructed" << endl;
    net.initParam();
    cout << "param-ed" << endl;
    auto result = net.foward(vector<double>{5, 6, 7, 8, 9, 10, -2, -4});
    cout << "fowarded-ed" << endl;
    cout << result[0] << endl;
  }
};

int main(int argc, char *argv[]) {

  // testMatVecMult();
  Test::testLayer();
  Test::testLotsOfThings();
  cout << "All tests passed!" << endl;

  return 0;
}
