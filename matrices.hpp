#include <cmath>

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
		vec2 a = { ax, ay };
		vec2 b = { bx, by };
	};

	class mat3x3 {
	private:
		double
			ax, ay, az,
			bx, by, bz,
			cx, cy, cz;
	public:
		vec3 a = { ax, ay, az };
		vec3 b = { bx, by, bz };
		vec3 c = { cx, cy, cz };
	};

	class mat4x4 {
	private:
		double
			aw, ax, ay, az,
			bw, bx, by, bz,
			cw, cx, cy, cz,
			dw, dx, dy, dz;
	public:
		vec4 a = { aw, ax, ay, az };
		vec4 b = { bw, bx, by, bz };
		vec4 c = { cw, cx, cy, cz };
		vec4 d = { dw, dx, dy, dz };

		vec4 w = { aw, bw, cw, dw, };
		vec4 x = { ax, bx, cx, dx, };
		vec4 y = { ay, by, cy, dy, };
		vec4 z = { az, bz, cz, dz, };

	};




}

#endif