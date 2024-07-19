#include <math.h>
#include <stdexcept>

class Vector {
public:
	int size;
	double* arr;
	double magnitude;

	Vector(int size, double* arr = nullptr);

	~Vector();

	Vector operator+(const Vector& other) const;

	Vector operator-(const Vector& other) const;

	Vector operator*(const double scalar) const;

	Vector operator*(const Vector& other) const;

	Vector operatorx(const Vector& other) const;

};
