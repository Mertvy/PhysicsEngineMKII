#include <math.h>
#include <stdexcept>
#include <vector>

using std::vector;

class Vector {
public:
	int size;
	vector<double> vec;
	double magnitude;

	Vector(vector<double> vec);

	double operator[](int i) const;

	Vector operator+(const Vector other) const;

	Vector operator-(const Vector other) const;

	Vector operator*(const double scalar) const;

	double operator*(const Vector other) const;

	Vector operator&(const Vector other) const;

	Vector proj(const Vector v) const;

};
