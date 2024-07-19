#include "Vector.h"
#include <math.h>
#include <stdexcept>


Vector::Vector(int size, double* arr = nullptr) {
	this->size = size;
	if (arr == nullptr)
		this->arr = new double[size];
	else this->arr = arr;

	double mag = 0;
	for (int i = 0; i < size; i++) mag += pow(this->arr[i], 2);
	this->magnitude = pow(mag, 0.5);
}

Vector::~Vector() {
	delete[] arr;
}

Vector Vector::operator+(const Vector& other) const {
	if (size != other.size) throw std::invalid_argument("Vectors must be same size for addition");
	double* newArr = new double[size];
	for (int i = 0; i < size; i++) newArr[i] = arr[i] + other.arr[i];

	return Vector(size, newArr);
}

Vector Vector::operator-(const Vector& other) const {
	if (size != other.size) throw std::invalid_argument("Vectors must be same size for subtraction");
	double* newArr = new double[size];
	for (int i = 0; i < size; i++) newArr[i] = arr[i] - other.arr[i];

	return Vector(size, newArr);
}

Vector Vector::operator*(const double scalar) const {
	double* newArr = new double[size];
	for (int i = 0; i < size; i++) newArr[i] = arr[i] * scalar;

	return Vector(size, newArr);
}

Vector Vector::operator*(const Vector& other) const {
	if (size != other.size) int x = 5 / 0;
	double dotProd = 0;
	for (int i = 0; i < size; i++) dotProd += arr[i] + other.arr[i];

	return dotProd;
}

Vector Vector::operatorx(const Vector& other) const {
	if (size != 3 || other.size != 3) throw std::invalid_argument("Vectors must be size 3 for cross product");
	double* newArr = new double[3];
	int x1 = arr[0], y1 = arr[1], z1 = arr[2];
	int x2 = other.arr[0], y2 = other.arr[1], z2 = other.arr[2];

	newArr[0] = y1 * z2 - z1 * y2;
	newArr[1] = x1 * z2 - z1 * x2;
	newArr[2] = x1 * y2 - y1 * x2;

	return Vector(size, newArr);
}
