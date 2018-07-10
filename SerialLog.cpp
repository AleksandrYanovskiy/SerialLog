/*
 * SerialLog.cpp
 *
 *  Created on: 02 июля 2017 г.
 *      Author: janovsky
 */


#include "SerialLog.h"

#ifdef DEBUG

namespace graf {

unsigned long SerialLog::baud_ = 9600; //default baud rate
bool SerialLog::isInit_ = false;
bool SerialLog::isHeadPrint_ = false;

/*
SerialLog::SerialLog() {
	Begin(SerialLog::baud_);
}

SerialLog::~SerialLog() {
	End();
}
*/

/**
 * version info
 */
const char* SerialLog::getVersion() {
	return _VER;
}

void SerialLog::Begin(unsigned long baud) {
	baud_ = baud;
	Finalization();
	Initialization();
}

void SerialLog::End() {
	Finalization();
}

void SerialLog::Initialization() {
	if (! isInit_) {
		#ifndef DEBUG_LINUX
			Serial.begin(baud_);
		#endif
		isInit_ = true;
	}
}

void SerialLog::Finalization() {
	#ifndef DEBUG_LINUX
		Serial.end();
	#endif
	isInit_ = false;
}



void SerialLog::LogFormat(const char* cFileName, const int iLine, const bool lineEnd) {
	unsigned long curTime = millis();

	if (!isHeadPrint_) {
		#ifndef DEBUG_LINUX
			Serial.print('[');
			Serial.print(F("T:"));
			Serial.print(curTime);
			Serial.print(F("ms]"));
			Serial.print(' ');

			#ifdef DEBUG_MEMORY
				Serial.print('[');
				Serial.print(F("M:"));
				Serial.print(freeMemory());
				Serial.print(F("B]"));
				Serial.print(' ');
			#endif

			Serial.print('[');
			Serial.print(cFileName);
			Serial.print(':');
			Serial.print(iLine);
			Serial.print(']');
			Serial.print(' ');
		#else
			std::cout << curTime << ' ' << '[' << cFileName << ':' << iLine << ']' << ' ';
		#endif
	}
	if (lineEnd)
		isHeadPrint_ = false;
	else
		isHeadPrint_ = true;
}

/**
 * log int
 */
void SerialLog::LogPrint(int logMessage, const char* cFileName, const int iLine, const bool lineEnd, int format) {
	if ( isInit_ ) {

		LogFormat(cFileName, iLine, lineEnd);

		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage, format);
			else
			  Serial.print(logMessage, format);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}

/**
 * log unsigned int
 */
void SerialLog::LogPrint(unsigned int logMessage, const char* cFileName, const int iLine, const bool lineEnd, int format) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage, format);
			else
			  Serial.print(logMessage, format);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}

/**
 * log char
 */
void SerialLog::LogPrint(char logMessage, const char* cFileName, const int iLine, const bool lineEnd) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage);
			else
			  Serial.print(logMessage);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}

/**
 * log unsigned char
 */
void SerialLog::LogPrint(unsigned char logMessage, const char* cFileName, const int iLine, const bool lineEnd, int format) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage, format);
			else
			  Serial.print(logMessage, format);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}



/**
 * log const char[]
 */
void SerialLog::LogPrint(const char logMessage[], const char* cFileName, const int iLine, const bool lineEnd) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage);
			else
			  Serial.print(logMessage);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}


/**
 * log object
 */
void SerialLog::LogPrint(const Printable& logMessage, const char* cFileName, const int iLine, const bool lineEnd) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage);
			else
			  Serial.print(logMessage);
		#else
			//std::cout << logMessage << std::endl;
		#endif
	}
}

/**
 * log object
 */
void SerialLog::LogPrint(const String& logMessage, const char* cFileName, const int iLine, const bool lineEnd) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage);
			else
			  Serial.print(logMessage);
		#else
			//std::cout << logMessage << std::endl;
		#endif
	}
}


/**
 * log long
 */
void SerialLog::LogPrint(long logMessage, const char* cFileName, const int iLine, const bool lineEnd, int format) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage, format);
			else
			  Serial.print(logMessage, format);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}


/**
 * log unsigned long
 */
void SerialLog::LogPrint(unsigned long logMessage, const char* cFileName, const int iLine, const bool lineEnd, int format) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage, format);
			else
			  Serial.print(logMessage, format);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}

/**
 * float
 */
void SerialLog::LogPrint(double logMessage, const char* cFileName, const int iLine, const bool lineEnd, int format) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage, format);
			else
			  Serial.print(logMessage, format);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}

void SerialLog::LogPrint(const __FlashStringHelper* logMessage, const char* cFileName, const int iLine, const bool lineEnd) {
	if ( isInit_  ) {
		LogFormat(cFileName, iLine, lineEnd);
		#ifndef DEBUG_LINUX
			if (lineEnd)
			  Serial.println(logMessage);
			else
			  Serial.print(logMessage);
		#else
			if (lineEnd)
				std::cout << logMessage << std::endl;
			else
				std::cout << logMessage << std::flush;
		#endif
	}
}


}

/* namespace graf */

#endif
