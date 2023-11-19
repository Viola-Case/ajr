#include <cmath>

#include <ajr/utils_11-8.hpp>

#ifndef _AJR_QUATERNION_
#define _AJR_QUATERNION_


namespace ajr {
	class quaternion {
	public:
		quaternion() : w(1.0), x(0.0), y(0.0), z(0.0) {}
		quaternion(double real, double imag_i, double imag_j, double imag_k) : w(real), x(imag_i), y(imag_j), z(imag_k) {};

		double getReal()	const { return w; }
		double getImagI()	const { return x; }
		double getImagJ()	const { return y; }
		double getImagK()	const { return z; }

#define get1 getReal
#define getI getImagI
#define getJ getImagJ
#define getK getImagK

		quaternion operator+(const quaternion& other) {
			return quaternion(w + other.w, x + other.x, y + other.y, z + other.z);
		}

		quaternion operator-(const quaternion& other) {
			return quaternion(w - other.w, x - other.x, y - other.y, z - other.z);
		}

		quaternion operator*(const quaternion& other) {
			return quaternion(
				w * other.w - x * other.x - y * other.y - z * other.z,
				w * other.x + x * other.w + y * other.z - z * other.y,
				w * other.y - x * other.z + y * other.w + z * other.x,
				w * other.z + x * other.y - y * other.x + z * other.w
			);
		}

		quaternion conjugate() const {
			return quaternion(w, -x, -y, -z);
		}

		double magnitude() const {
			return sqrt(w * w + x * x + y * y + z * z);
		}

#ifdef _IOSTREAM_
		// Overload the << operator to customize how a frac is displayed
		friend std::ostream& operator<<(std::ostream& os, const quaternion& f) {
			os << f.w << " + " << f.x << "i + " << f.y << "j + " << f.z << 'z';
			return os;
		}
#endif

	private:
		double w, x, y, z;

	};

}
#endif