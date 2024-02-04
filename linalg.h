#ifndef LINALG_H
#define LINALG_H

#include <vector>

// mat-vec
std::vector<double> matrixMult(const std::vector<std::vector<double>> &A,
                               const std::vector<double> &B);

// std::vector<std::vector<double>>
// matrixMult(const std::vector<std::vector<int>> &A,
//            const std::vector<std::vector<int>> &B);

#endif // !DEBUG
