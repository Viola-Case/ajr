#ifndef _AJR_COMPNUM_
#define _AJR_COMPNUM_

#include <cmath>


#include <ajr/utils_11-8.hpp>

namespace ajr {
	class complex {
	public:

		complex() : x(0.0), y(0.0) {}
		complex(double real, double imag) : x((double)real), y((double)imag) {}

		double getReal() { return x; }
		double getImag() { return y; }

		complex conjugate() const {
			complex(x, -1. * y);
		}

#pragma region complex_operators

		complex operator+(const complex& other) const {
			return complex(x + other.x, y + other.y);
		}

		complex operator+(const double other) {
			return complex(x + other, y);
		}

		complex operator-(const complex& other) const {
			return complex(x - other.x, y - other.y);
		}

		complex operator-(const double other) {
			return complex(x - other, y);
		}

		complex operator*(const complex& other) {
			return complex(x * other.x - y * other.y, y * other.x + x * other.y);
		}

		complex operator*(const double other) {
			return complex(x * other, y * other);
		}

		complex operator/(const complex& other) {
			return complex();
		}

		complex operator/(const double other) {
			return complex(x / other, y / other);
		}

		friend const complex operator+(double a, complex b), operator+(complex a, double b), operator-(double a, complex b), operator-(complex a, double b);

#pragma endregion complex_operators

	private:
		double x, y;
	};



	const complex operator+(double a, complex b) {
		return complex(a + b.x, b.y);
	}

	const complex operator-(double a, complex b) {
		return complex(a - b.x, 0. - b.y);
	}


	const complex i = const complex(0., 1.);

#define AJR_I ajr::i

}

#endif