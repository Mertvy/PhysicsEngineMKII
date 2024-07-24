#include <math.h>
#include <vector>
#include "Vector.h"

using std::vector;

class Matrix {
public:
	vector<int> dimension;
  vector<Vector> matrix;

  Matrix(vector<vector<double>> matrix);

  Vector operator[](const int i) const;

  Matrix operator+(const Matrix other) const;

  Matrix operator-(const Matrix other) const;

  Matrix operator*(const double scalar) const

  Matrix operator*(const Matrix other) const;

  Vector operator*(const Vector vec) const;

  Matrix rref() const;

  double det() const;

}
