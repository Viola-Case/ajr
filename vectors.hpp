#ifndef _AJR_VECTOR_
#define _AJR_VECTOR_

#include <ajr/utils_11-8.hpp>

#define CARTESIAN_FORM 0x1000
#define CYLINDRICAL 0x1001
#define SPHERICAL 0x1002

namespace ajr {

#pragma region vectors

	class vec2 {

	public:
		vec2() : x(0.0), y(0.0) {};
		vec2(double a, double b) : x(a), y(b) {};
		vec2(double a[]) : x(a[0]), y(a[1]) {};
		vec2(double a) : x(a), y(a) {};

		double getX() {
			return x;
		}

		double getY() {
			return y;
		}

		double operator*(vec2& other) {
			return x * other.x + y * other.y;
		}

		double operator[](int other) {
			switch (other) {
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			default:
			{
				int* p = NULL;
				return *p;
			}
				break;
			}
		}

		double magnitude() {
			return sqrt(x * x + y * y);
		}

#ifdef _IOSTREAM_
		friend std::ostream& operator<<(std::ostream& os, const vec2 v) {
			os << '(' << v.x << ", " << v.y << ')';
			return os;
	}
#endif

#ifdef _VECTOR_

		vec2(std::vector<double> a) : x(a[0]), y(a[1]) {};

#endif

	private:
		double x, y;
	};

	class vec3 {
	public:
		vec3() : x(0.0), y(0.0), z(0.0) {};
		vec3(double a, double b, double c) : x(a), y(b), z(c) {};
		vec3(double a, double b, double c, int mode) {
			switch (mode) {
			default:
				x = a;
				y = b;
				z = c;
			case NULL:
				x = a;
				y = b;
				z = c;
			case CARTESIAN_FORM:
				x = a;
				y = b;
				z = c;
			case SPHERICAL:
				x = a * sin(c) * cos(b);
				y = a * sin(c) * sin(b);
				z = a * cos(c);

			case CYLINDRICAL:
				x = a * cos(b);
				y = a * sin(b);
				z = c;
			}
		}

		vec2 xy() { return vec2(x, y);}
		vec2 xz() { return vec2(x, z);}
		vec2 yz() { return vec2(y, z);}

		double getX() { return x; }
		double getY() { return y; }
		double getZ() { return z; }

		double operator*(vec3& other) {
			return x * other.x + y * other.y + z * other.z;
		}

		vec3 operator%(vec3& other) {
			return vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
		}

		double operator[](int other) {
			switch (other) {
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
			{
				int* p = NULL;
				return *p;
			}
				break;
			}
		}

		double magnitude() {
			return sqrt(x * x + y * y + z * z);
		}


#ifdef _IOSTREAM_
		friend std::ostream& operator<<(std::ostream& os, const vec3 v) {
			os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
			return os;
		}
#endif

	private:
		double x, y, z;
	};

	class vec4 {
	public:
		vec4() : w(0.0), x(0.0), y(0.0), z(0.0) {};
		vec4(double a, double b, double c, double d) : w(a), x(b), y(c), z(d) {};

		double getW() { return w; }
		double getX() { return x; }
		double getY() { return y; }
		double getZ() { return z; }

		vec2 wx() { return vec2(w, x); }
		vec2 wy() { return vec2(w, y); }
		vec2 wz() { return vec2(w, z); }
		vec2 xy() { return vec2(x, y); }
		vec2 xz() { return vec2(x, z); }
		vec2 yz() { return vec2(y, z); }

		vec3 wxy() { return vec3(w, x, y);}
		vec3 wxz() { return vec3(w, x, z);}
		vec3 wyz() { return vec3(w, y, z);}
		vec3 xyz() { return vec3(x, y, z);}

		double operator*(vec4& other) {
			return w * other.w + x * other.x + y * other.y + z * other.z;
		}

		double operator[](int other) {
			switch (other) {
			case 0:
				return w;
				break;
			case 1:
				return x;
				break;
			case 2:
				return y;
				break;
			case 3:
				return z;
				break;
			default:
			{
				int* p = NULL;
				return *p;
			}
				break;
			}
		}

		double magnitude() {
			return sqrt(w * w + x * x + y * y + z * z);
		}

#ifdef _IOSTREAM_
		friend std::ostream& operator<<(std::ostream& os, const vec4 v) {
			os << '(' << v.w << ", " << v.x << ", " << v.y << ", " << v.z << ')';
			return os;
		}
#endif

	private:
		double w, x, y, z;
	};

#pragma endregion vectors

#pragma region dotProduct


	double dotProduct(vec2 a, vec2 b) {
		return a * b;
	}

	double dotProduct(vec3 a, vec3 b) {
		return a * b;
	}

	double dotProduct(vec4 a, vec4 b) {
		return a * b;
	}

	vec3 crossProduct(vec3 a, vec3 b) {
		return a % b;
	}




#pragma endregion dotProduct


}

#endif