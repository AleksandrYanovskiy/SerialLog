/*
 * Common.h
 *
 *  Created on: 07 июля 2017 г.
 *      Author: janovsky
 *
 *  For enable output debug info to serial channel:
 *  	#define DEBIG LV_NONE
 *  	or
 *  	#define DEBIG LV_LOW
 *  	or
 *  	#define DEBIG LV_NORMAL
 *  	or
 *  	#define DEBIG LV_HIGH
 */


#ifndef COMMON_H_
#define COMMON_H_
//#########################################################

#define LV_NONE 1
#define LV_LOW 2
#define LV_NORMAL 3
#define LV_HIGH 4

#define DEBUG LV_NORMAL

//for debug in linux, uncomment next row, for debug in LINUX platform
//#define DEBUG_LINUX //adding in #SYMBOLS ECLIPSE

//library for show free memory  https://playground.arduino.cc/Code/AvailableMemory
//#define DEBUG_MEMORY

#ifdef DEBUG
  #if ( (DEBUG != LV_NONE) && (DEBUG != LV_LOW) && (DEBUG != LV_NORMAL) && (DEBUG != LV_HIGH) )
	#error "DEBUG must be in LV_LOW or LV_NORMAL or LV_HIGH or LV_NONE!"
  #elif (DEBUG != LV_NONE)
    #warning "Comment #define DEBUG for disable debug messages and free memory!"
  #endif

  #if (DEBUG == LV_NONE)
    #undef DEBUG
  #endif

#else
  #undef DEBUG_LINUX
#endif

#include "Arduino.h"

/*
#ifndef DEBUG_LINUX
	#include "new.h"
#endif
*/

#include "SerialLog.h"

//#########################################################
#endif /* COMMON_H_ */
