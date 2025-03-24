#pragma once

#ifndef _AJR_TIME_
#define _AJR_TIME_

#include <chrono>
#include <thread>
#include <string>

namespace ajr {

	void sleep(int milliseconds, bool log = false) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));

		if (log) {
#ifdef _IOSTREAM_
			std::cout << "Thread " << std::this_thread::get_id << " slept for " << milliseconds << "ms" << std::endl;
#endif 

		}
	}


#ifdef _STRING_
	typedef int timeFormat;

#define HHmmss 0
#define HHmm 1
#define MM

	std::string curtime(int timeZone, timeFormat format) {

	}

	std::string dateTime(int timeZone, timeFormat format) {

	}

#endif


}

#endif