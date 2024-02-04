#include "linalg.h"

#include <stdexcept>
#include <vector>

typedef std::vector<std::vector<double>> matrix;
using std::vector;

std::vector<double> matrixMult(const std::vector<std::vector<double>> &A,
                               const std::vector<double> &B) {
  int Acols = A.size();
  int Bcols = 1;

  if (Acols == 0)
    throw std::runtime_error("Empty matrix");

  int Arows = A[0].size();
  int Brows = B.size();

  if (Arows == 0 || Brows == 0)
    throw std::runtime_error("Empty matrix");

  if (Acols != Brows)
    throw std::runtime_error("Matrix dimensions do not match");

  vector<double> result(Arows, 0);

  // r tracks output rows
  for (int r = 0; r < Brows; ++r) {
    // i tracks A column vs B row
    for (int i = 0; i < Acols; ++i) {
      result[r] += A[i][r] * B[i];
    }
  }

  return result;
}

// std::vector<std::vector<double>>
// matrixMult(const std::vector<std::vector<int>> &A,
//            const std::vector<std::vector<int>> &B) {

//   int Acols = A.size();
//   int Bcols = B.size();

//   if (Acols == 0 || Bcols == 0)
//     throw std::runtime_error("Empty matrix");

//   int Arows = A[0].size();
//   int Brows = B[0].size();

//   if (Arows == 0 || Brows == 0)
//     throw std::runtime_error("Empty matrix");

//   // matrices are column major
//   if (Acols != Brows)
//     throw std::runtime_error("Matrix dimensions do not match");

//   matrix result(Bcols, vector<double>(Arows, 0));

//   return result;
// }
