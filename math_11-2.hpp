#pragma once
/**
*
* Remember to always put the standard libraries above this header in your code!
*
*
*/


#ifndef _AJR_MATH
#define _AJR_MATH

#define _INCLUDE_SHORTHAND
#include <ajr/utils_11-8.hpp>

#ifndef _CMATH_
#include <cmath>
#endif

#include <ajr/vectors.hpp>
#include <ajr/matrices.hpp>
#include <ajr/fracs.hpp>
#include <ajr/compnum.hpp>



namespace ajr {


	COMMUTATIVE_OPERATOR_OVERLOAD(+);
	COMMUTATIVE_OPERATOR_OVERLOAD(*);

}

#endif