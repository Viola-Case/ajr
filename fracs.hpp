#pragma once

#ifndef _AJR_FRAC_
#define _AJR_FRAC_

#include <cmath>

#define _INCLUDE_SHORTHAND
#include <ajr/utils_11-8.hpp>


#define FRAC_BINARY 0x1000
#define FRAC_DECIMAL 0x1001


namespace ajr {

	class frac {
	private:
		long long int numerator = 0;
		long long int denominator = 1;

	public:
		frac(long long int num, long long int den) : numerator(num), denominator(den) {
			// Ensure the denominator is not zero
			if (denominator == 0) {
#ifdef _IOSTREAM_
				std::cerr << "Denominator cannot be zero." << std::endl;
#endif
				return;
			}

			// Simplify the fraction
			simplify();
		}

		// Function to simplify the fraction
		void simplify() {
			int gcd = computeGCD(numerator, denominator);
			numerator /= gcd;
			denominator /= gcd;

			// Make sure the denominator is positive
			if (denominator < 0) {
				numerator = -numerator;
				denominator = -denominator;
			}
		}

		// Conversion constructor for casting from float
		frac(float value, int PrecisionLevel, int mode) {
			int precision = 1;
			switch (mode) {
			case FRAC_BINARY:
				precision = 1 << PrecisionLevel; // Compute 2^PrecisionLevel
				break;
			case FRAC_DECIMAL:
				for (int i = 0; i < PrecisionLevel; i++) {
					precision *= 10;
				}
				break;
			}

			numerator = static_cast<long long int>(round(value * precision));
			denominator = precision;

			simplify();
		}

		// Conversion constructor for casting from double
		frac(double value, int PrecisionLevel, int mode) {
			int precision = 1;
			switch (mode) {
			case FRAC_BINARY:
				precision = 1 << PrecisionLevel; // Compute 2^PrecisionLevel
				break;
			case FRAC_DECIMAL:
				FOR(i, PrecisionLevel) {
					precision *= 10;
				}
				break;
			}
			numerator = static_cast<long long int>(round(value * precision));
			denominator = precision;

			simplify();
		}

		// Function to compute the greatest common divisor (GCD)
		int computeGCD(long long int a, long long int b) {
			if (b == 0)
				return a;
			return computeGCD(b, a % b);
		}

		// Overload the addition operator
		frac operator+(const frac& other) {
			long long int new_num = numerator * other.denominator + other.numerator * denominator;
			long long int new_den = denominator * other.denominator;
			return frac(new_num, new_den);
		}

		frac operator+(const int other) {
			return frac(numerator + other * denominator, denominator);
		}

		// Overload the subtraction operator
		frac operator-(const frac& other) {
			long long int new_num = numerator * other.denominator - other.numerator * denominator;
			long long int new_den = denominator * other.denominator;
			return frac(new_num, new_den);
		}

		frac operator-(const int other) {
			return operator+(-other);
		}

		// Overload the multiplication operator
		frac operator*(const frac& other) {
			long long int new_num = numerator * other.numerator;
			long long int new_den = denominator * other.denominator;
			return frac(new_num, new_den);
		}

		frac operator*(const int other) {
			return frac(numerator * other, denominator);
		}

		// Overload the division operator
		frac operator/(const frac& other) {
			long long int new_num = numerator * other.denominator;
			long long int new_den = denominator * other.numerator;
			return frac(new_num, new_den);
		}

		frac operator/(const int other) {
			return frac(numerator, denominator * other);
		}

		operator frac() {
			return frac(numerator, denominator);
		}


		long long int getNumerator() const {
			return numerator;
		}

		long long int getDenominator() const {
			return denominator;
		}

#ifdef _IOSTREAM_
		// Overload the << operator to customize how a frac is displayed
		friend std::ostream& operator<<(std::ostream& os, const frac& f) {
			os << f.numerator << " / " << f.denominator;
			return os;
		}
#endif

	};




	const frac ajrFraction_e = frac(637069925, 234364928); // Approximation for e to 11 digits
	const frac ajrFraction_pi = frac(5890233089, 1874919424); // Approximation for pi to 10 digits



}


#endif


