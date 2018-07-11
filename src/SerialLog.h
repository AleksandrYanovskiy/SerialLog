/*
 * SerialLog.h
 *
 *  Created on: 11 июля 2018 г.
 *      Author: Aleksandr Yanovskiy
 *
 *  Class for logged message in console
 *  Used Serial arduino class
 *  For enable logged in serial console, must be define DEBUG, in the production code Log recommended disable (not declare DEBUG), for release memory.
 *
 *  Log begin first command:
 *              LOG_BEGIN(baudrate);
 *
 *  Log ending command:
 *              LOG_END()
 *
 *  Logger has 3 level for logged message: Low, Normal, High
 *              Low message output only if set low level;
 *              Normal message output, if set low or normal level;
 *              High message output for all levels;
 *
 *  Level can set:
 *                 LV_LOW() - default
 *                 LV_NORMAL()
 *                 LV_HIGH()
 *
 *  Message output can send command:
 *                      LOG(messsage[, format]), LOG_L(messsage[, format]) - for send log message with Low level
 *                      LOG_N(messsage[, format]) - for send log message with Normal level
 *                      LOG_H(messsage[, format]) - for send log message with High level
 *
 */

#ifndef SERIALLOG_H_
#define SERIALLOG_H_

#define _VER "1.00"

#define LV_NONE 1
#define LV_LOW 2
#define LV_NORMAL 3
#define LV_HIGH 4

#define DEBUG LV_NORMAL
//library for show free memory  https://playground.arduino.cc/Code/AvailableMemory
#define DEBUG_MEMORY

#ifdef DEBUG
  #if ( (DEBUG != LV_NONE) && (DEBUG != LV_LOW) && (DEBUG != LV_NORMAL) && (DEBUG != LV_HIGH) )
  #error "DEBUG must be in LV_LOW or LV_NORMAL or LV_HIGH or LV_NONE!"
  #elif (DEBUG != LV_NONE)
    #warning "Comment #define DEBUG for disable debug messages and free memory!"
  #endif

  #if (DEBUG == LV_NONE)
    #undef DEBUG
  #endif
#endif


#ifdef DEBUG
  #include "Arduino.h"
  #include "Printable.h"

  #ifdef DEBUG_MEMORY
    #include "MemoryFree.h"
  #endif

  //macros set log level
  #if DEBUG == LV_LOW
    #define LOG(logMessage, ...)      graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_LN(logMessage, ...)   graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
    #define LOG_L(logMessage, ...)    graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_L_LN(logMessage, ...) graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
    #define LOG_N(logMessage, ...)    graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_N_LN(logMessage, ...) graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
    #define LOG_H(logMessage, ...)    graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_H_LN(logMessage, ...) graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
  #elif DEBUG == LV_NORMAL
    #define LOG(logMessage, ...)
    #define LOG_LN(logMessage, ...)
    #define LOG_L(logMessage, ...)
    #define LOG_L_LN(logMessage, ...)
    #define LOG_N(logMessage, ...)    graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_N_LN(logMessage, ...) graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
    #define LOG_H(logMessage, ...)    graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_H_LN(logMessage, ...) graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
  #elif DEBUG==LV_HIGH
    #define LOG(logMessage, ...)
    #define LOG_LN(logMessage, ...)
    #define LOG_L(logMessage, ...)
    #define LOG_L_LN(logMessage, ...)
    #define LOG_N(logMessage, ...)
    #define LOG_N_LN(logMessage, ...)
    #define LOG_H(logMessage, ...)    graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, false, ##__VA_ARGS__)
    #define LOG_H_LN(logMessage, ...) graf::SerialLog::LogPrint(logMessage, __FILENAME__, __LINE__, true, ##__VA_ARGS__)
  #endif

  //macros begin, end
  #define LOG_BEGIN(baudrate) graf::SerialLog::Begin(baudrate)
  #define LOG_END() graf::SerialLog::End()

  //macros get only file name without path
  #define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)


  namespace graf {

  class SerialLog {
  public:
    static const char* getVersion();

    static void Begin(unsigned long baud);
    static void End();

    static void LogPrint(int logMessage,                        const char* cFileName, const int iLine, const bool lineEnd, int format = DEC);
    static void LogPrint(unsigned int logMessage,               const char* cFileName, const int iLine, const bool lineEnd, int format = DEC);
    static void LogPrint(char logMessage,                       const char* cFileName, const int iLine, const bool lineEnd);
    static void LogPrint(unsigned char logMessage,              const char* cFileName, const int iLine, const bool lineEnd, int format = DEC);
    static void LogPrint(const char logMessage[],               const char* cFileName, const int iLine, const bool lineEnd);
    static void LogPrint(const Printable& logMessage,           const char* cFileName, const int iLine, const bool lineEnd);
    static void LogPrint(const String& logMessage,              const char* cFileName, const int iLine, const bool lineEnd);
    static void LogPrint(long logMessage,                       const char* cFileName, const int iLine, const bool lineEnd, int format = DEC);
    static void LogPrint(unsigned long logMessage,              const char* cFileName, const int iLine, const bool lineEnd, int format = DEC);
    static void LogPrint(double logMessage,                     const char* cFileName, const int iLine, const bool lineEnd, int format= 2);
    static void LogPrint(const __FlashStringHelper* logMessage, const char* cFileName, const int iLine, const bool lineEnd);

  private:
    static unsigned long baud_;
    static bool isInit_;
    static bool isHeadPrint_;
    static void Initialization();
    static void Finalization();
    static void LogFormat(const char* cFileName, const int iLine, const bool lineEnd);
  };

} /* namespace graf */

#else //not DEBUG

  //macros begin, end
  #define LOG_BEGIN(baudrate)
  #define LOG_END()

  #define LOG(logMessage, ...)
  #define LOG_LN(logMessage, ...)
  #define LOG_L(logMessage, ...)
  #define LOG_L_LN(logMessage, ...)
  #define LOG_N(logMessage, ...)
  #define LOG_N_LN(logMessage, ...)
  #define LOG_H(logMessage, ...)
  #define LOG_H_LN(logMessage, ...)


#endif

#endif /* SERIALLOG_H_ */
