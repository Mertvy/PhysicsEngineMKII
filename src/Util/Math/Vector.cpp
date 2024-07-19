#include "Vector.h"
#include <math.h>
#include <stdexcept>
#include <vector>

using std::vector;

Vector::Vector(vector<double> vec) {
	this->size = vec.size();
	this->vec = vec;

	double mag = 0;
	for (int i = 0; i < size; i++) mag += pow(vec[i], 2);
	this->magnitude = pow(mag, 0.5);
}

double Vector::operator[](int i) const {
	return vec[i];
}


Vector Vector::operator+(const Vector other) const {
	if (size != other.size) throw std::invalid_argument("Vectors must be same dimension for addition");

	vector<double> newVec = vector<double>(size);
	for (int i = 0; i < size; i++) newVec[i] = vec[i] + other.vec[i];

	return Vector(newVec);
}

Vector Vector::operator-(const Vector other) const {
	if (size != other.size) throw std::invalid_argument("Vectors must be same dimension for subtraction");
	vector<double> newVec = vector<double>(size);
	for (int i = 0; i < size; i++) newVec[i] = vec[i] - other.vec[i];

	return Vector(newVec);
}

Vector Vector::operator*(const double scalar) const {
	vector<double> newVec = vector<double>(size);
	for (int i = 0; i < size; i++) newVec[i] = vec[i] * scalar;

	return Vector(newVec);
}

double Vector::operator*(const Vector other) const {
	if (size != other.size) throw std::invalid_argument("Vectors must be same dimension for dot product");
	double dotProd = 0;
	for (int i = 0; i < size; i++) dotProd += vec[i] * other.vec[i];

	return dotProd;
}

Vector Vector::operator&(const Vector other) const {
	if (size != 3 || other.size != 3) throw std::invalid_argument("Vectors must be dimension 3 for cross product");
	vector<double> newVec = vector<double>(size);
	double x1 = vec[0], y1 = vec[1], z1 = vec[2];
	double x2 = other.vec[0], y2 = other.vec[1], z2 = other.vec[2];

	newVec[0] = y1 * z2 - z1 * y2;
	newVec[1] = -x1 * z2 + z1 * x2;
	newVec[2] = x1 * y2 - y1 * x2;

	return Vector(newVec);
}

Vector Vector::proj(const Vector v) const {
	if (size != v.size) throw std::invalid_argument("Vectors must be same dimension for projection");
	double scalar = ((*this) * v) / pow((*this).magnitude, 2);
	return (*this) * scalar;
}
