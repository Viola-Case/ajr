#ifndef _AJR_MATRIX_
#define _AJR_MATRIX_

#include <ajr/vectors.hpp>

namespace ajr {

	class mat2x2 {
	private:
		double
			ax, ay,
			bx, by;

	public:
		mat2x2() : ax(0.), ay(0.), bx(0.), by(0.) {};
		mat2x2(
			double w, double x,
			double y, double z
		) :
			ax(w), ay(x),
			bx(y), by(z)
		{};
		mat2x2(vec2 a, vec2 b) : ax(a.getX()), ay(a.getY()), bx(b.getX()), by(b.getY()) {};

		vec2 a() { return vec2(ax, ay); }
		vec2 b() { return vec2(bx, by); }
		vec2 x() { return vec2(ax, bx); }
		vec2 y() { return vec2(ay, by); }

#ifdef _IOSTREAM_
		friend std::ostream& operator<<(std::ostream& os, const mat2x2 m) {
			os << '(' << m.ax << ", " << m.ay << '\n' << m.bx << ", " << m.by << ')';
			return os;
		}
#endif
		vec2 operator[](int arg) {
			switch (arg) {
			default:
			{
				vec2* p = NULL;
				return *p;
			}
			case 0:
				return a();
			case 1:
				return b();
			}
		}

		mat2x2 operator*(mat2x2& other) {
			return mat2x2(
				dotProduct(a(), other.x()), dotProduct(a(), other.y()),
				dotProduct(b(), other.x()), dotProduct(b(), other.y())
			);
		}

		mat2x2 operator*(double& other) {
			return mat2x2(
				ax * other, ay * other,
				bx * other, by * other
			);
		}

		mat2x2 operator+(mat2x2& other) {
			return mat2x2(
				ax + other.ax, ay + other.ay,
				bx + other.bx, by + other.by
			);
		}

		mat2x2 operator-(mat2x2& other) {
			return mat2x2(
				ax - other.ax, ay - other.ay,
				bx - other.bx, by - other.by
			);
		}

		double determinant() {
			return ax * by - ay * bx;
		}

	};

	class mat3x3 {
	private:
		double
			ax, ay, az,
			bx, by, bz,
			cx, cy, cz;
	public:
		mat3x3(
			double a, double b, double c,
			double d, double e, double f,
			double g, double h, double i
		
		) : 
			ax(a), ay(b), az(c),
			bx(d), by(e), bz(f),
			cx(g), cy(h), cz(i)
		{};

		mat3x3(vec3 a, vec3 b, vec3 c) :
			ax(a.getX()), ay(a.getY()), az(a.getZ()),
			bx(b.getX()), by(b.getY()), bz(b.getZ()),
			cx(c.getX()), cy(c.getY()), cz(c.getZ())
		{};

		vec3 a() { return vec3(ax, ay, az); }
		vec3 b() { return vec3(bx, by, bz); }
		vec3 c() { return vec3(cx, cy, cz); }
		vec3 x() { return vec3(ax, bx, cx); }
		vec3 y() { return vec3(ay, by, cy); }
		vec3 z() { return vec3(az, bz, cz); }

		mat3x3 operator*(mat3x3& other) {
			return mat3x3(
				dotProduct(a(), other.x()), dotProduct(a(), other.y()), dotProduct(a(), other.z()),
				dotProduct(b(), other.x()), dotProduct(b(), other.y()), dotProduct(b(), other.z()),
				dotProduct(c(), other.x()), dotProduct(c(), other.y()), dotProduct(c(), other.z())
			);
		}

		mat3x3 operator+(mat3x3& other) {
			return mat3x3(
				ax + other.ax, ay + other.ay, az + other.az,
				bx + other.bx, by + other.by, bz + other.bz,
				cx + other.cx, cy + other.cy, cz + other.cz
			);
		}

		mat3x3 operator-(mat3x3& other) {
			return mat3x3(
				ax - other.ax, ay - other.ay, az - other.az,
				bx - other.bx, by - other.by, bz - other.bz,
				cx - other.cx, cy - other.cy, cz - other.cz
			);
		}

		double determinant() {
			return (
				(
					ax * by * cz +
					bx * cy * az +
					cx * ay * bz
					) - (
					az * by * cx +
					bz * cy * ax +
					cz * ay * bx
					));
		}
	};

	class mat4x4 {
	private:
		double
			aw, ax, ay, az,
			bw, bx, by, bz,
			cw, cx, cy, cz,
			dw, dx, dy, dz;
	public:
		mat4x4(
			double a, double b, double c, double d,
			double e, double f, double g, double h,
			double i, double j, double k, double l,
			double m, double n, double o, double p
		) : 
			aw(a), ax(b), ay(c), az(d),
			bw(e), bx(f), by(g), bz(h),
			cw(i), cx(j), cy(k), cz(l),
			dw(m), dx(n), dy(o), dz(p)
		{};

		mat4x4(vec4 a, vec4 b, vec4 c, vec4 d) :
			aw(a.getW()), ax(a.getX()), ay(a.getY()), az(a.getZ()),
			bw(b.getW()), bx(b.getX()), by(b.getY()), bz(b.getZ()),
			cw(c.getW()), cx(c.getX()), cy(c.getY()), cz(c.getZ()),
			dw(d.getW()), dx(d.getX()), dy(d.getY()), dz(d.getZ())
		{};

		vec4 a() { return vec4( aw, ax, ay, az ) ; }
		vec4 b() { return vec4( bw, bx, by, bz ) ; }
		vec4 c() { return vec4( cw, cx, cy, cz ) ; }
		vec4 d() { return vec4( dw, dx, dy, dz ) ; }

 		vec4 w() { return vec4( aw, bw, cw, dw ) ; }
		vec4 x() { return vec4( ax, bx, cx, dx ) ; }
		vec4 y() { return vec4( ay, by, cy, dy ) ; }
		vec4 z() { return vec4( az, bz, cz, dz ) ; }

		mat4x4 operator*(mat4x4& other) {
			return mat4x4(
				dotProduct(a(), other.w()), dotProduct(a(), other.x()), dotProduct(a(), other.y()), dotProduct(a(), other.z()),
				dotProduct(b(), other.w()), dotProduct(b(), other.x()), dotProduct(b(), other.y()), dotProduct(b(), other.z()),
				dotProduct(c(), other.w()), dotProduct(c(), other.x()), dotProduct(c(), other.y()), dotProduct(c(), other.z()),
				dotProduct(d(), other.w()), dotProduct(d(), other.x()), dotProduct(d(), other.y()), dotProduct(d(), other.z())
			);
		}

		mat4x4 operator+(mat4x4& other) {
			return mat4x4(
			aw+other.aw, ax+other.ax, ay+other.ay, az+other.az,
			bw+other.bw, bx+other.bx, by+other.by, bz+other.bz,
			cw+other.cw, cx+other.cx, cy+other.cy, cz+other.cz,
			dw+other.dw, dx+other.dx, dy+other.dy, dz+other.dz);
		}

		mat4x4 operator-(mat4x4& other) {
			return mat4x4(
				aw - other.aw, ax - other.ax, ay - other.ay, az - other.az,
				bw - other.bw, bx - other.bx, by - other.by, bz - other.bz,
				cw - other.cw, cx - other.cx, cy - other.cy, cz - other.cz,
				dw - other.dw, dx - other.dx, dy - other.dy, dz - other.dz);
		}

		double determinant() {

		}

		friend double determinant(mat4x4 A);

	};

	const mat2x2 idenMat_2x2 = mat2x2(
		1., 0., 
		0., 1.
	);

	const mat3x3 idenMat_3x3 = mat3x3(
		1., 0., 0.,
		0., 1., 0.,
		0., 0., 1.
	);

	const mat4x4 idenMat_4x4 = mat4x4(
		1., 0., 0., 0.,
		0., 1., 0., 0.,
		0., 0., 1., 0.,
		0., 0., 0., 1.
	);

	double determinant(mat2x2 A) {

	}

	double determinant(mat3x3 A) {

	}

	double determinant(mat4x4 A) {
		
	}

}

#endif