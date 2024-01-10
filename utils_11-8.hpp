#pragma once
#include <cstring>

/**
* 
* Remember to always put the standard libraries above this header in your code!
* 
* 
*/


#ifndef _AJR_UTILS_
#define _AJR_UTILS_

#pragma region macros

#define COMMUTATIVE_OPERATOR_OVERLOAD(OP)                           \
    template <typename T, typename U>                               \
    auto operator OP(const T& lhs, const U& rhs)                    \
        -> decltype(lhs OP rhs)                                     \
    {                                                               \
        return lhs OP rhs;                                          \
    }                                                               \
                                                                    \
    template <typename T, typename U>                               \
    auto operator OP(const U& lhs, const T& rhs)					\
        -> decltype(lhs OP rhs)                                     \
    {                                                               \
        return lhs OP rhs;                                          \
    }

#ifdef _INCLUDE_SHORTHAND
#define FOR(i, j) for (int i = 0; i < j; ++i)														 // I always hated having to write out `for (int i = 0; i < j; i++)`, so I've defined a shorthand for it.
#define SWAP(a, b) { auto temp = a; a = b; b = temp; }												 // Let's be real, you've been wondering about this.
#define MIN(a, b) ((a) < (b) ? (a) : (b))															 // Returns the maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))															 // Returns the minimum of two values
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))												 // Returns the size 
#define PRINT_ARRAY(arr, size) { for (int i = 0; i < size; ++i) cout << arr[i] << '\t'; }			 // Prints the contents of array with known size
#define ROUND_UP(num, multiple) (((num) + (multiple) - 1) / (multiple) * (multiple))				 // Rounds up to the closest multiple
#define IS_EVEN(num) ((num) % 2 == 0)																 // Checks if a number is even (num mod 2 = 0)
#define MAX_IN_LIST(arr, size) ({ \
    int max_val = (size > 0) ? arr[0] : 0; \
    for (int i = 1; i < size; ++i) \
        if (arr[i] > max_val) \
            max_val = arr[i]; \
    max_val; \
})																									 // Returns the maximum value in a list
#define MIN_IN_LIST(arr, size) ({ \
    int min_val = (size > 0) ? arr[0] : 0; \
    for (int i = 1; i < size; ++i) \
        if (arr[i] < min_val) \
            max_val = arr[i]; \
    max_val; \
})																									 // Returns the minimum value in a list

#endif

#pragma endregion macros

namespace ajr {

	int cstrToInt(const char* line) {
		

		std::cout << sizeof(line);

		return 0;
	}


#ifdef _FSTREAM_
#ifdef _STRING_


	std::string fileToString(const char* source) {
		std::ifstream inputFile(source); 

		if (!inputFile) {
#ifdef _IOSTREAM_
			std::cerr << "Failed to open the file." << std::endl;
#endif
			return NULL;
		}

		// Read the file into a std::string
		std::string fileContents((std::istreambuf_iterator<char>(inputFile)),
			std::istreambuf_iterator<char>());

		// Close the file
		inputFile.close();

		// Now, you have the file contents in the 'fileContents' string.
		return fileContents;
		}

	void copyFile(const char* source, std::string &target) {

		std::ifstream inputFile(source);

		if (!inputFile) {
#ifdef _IOSTREAM_
			std::cerr << "Failed to open the file." << std::endl;
#endif
			target = {};
		}

		std::string fileContents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

		inputFile.close();

		target = fileContents;

		

	}
#endif
#endif

#pragma region PRINTING

#ifdef _IOSTREAM_

#ifdef _VECTOR_

	template <typename T>
	void printVec(const std::vector<T>& listObject) {
		for (const T& i : listObject)
			std::cout << i << '\t';
		std::cout << std::endl;
	}


#endif

#ifdef _DEQUE_

	template <typename T>
	void printDeque(const std::deque<T>& listObject) {
		for (const T& i : listObject)
			std::cout << i << '\t';
		std::cout << std::endl;
	}


#endif



#endif

#pragma endregion PRINTING


}

#endif