# SerialLog
SerialLog - library for debugging arduino.
The library is designed to output debug information via a standard Serial console.
> Many thanks to my best friend Sobyanin Victor from Krasnodar for moral support and testing!

## Description
To output debug information you need to declare in SerialLog.h necessary debug level:  
`#define DEBUG LV_LOW`  
where LV_LOW is the level of output messages.  

There are 3 levels:
- LV_LOW
- LV_NORMAL
- LV_HIGH  
Messages with LV_LOW level will not be output in LV_NORMAL and LV_HIGH levels.  
Messages with level LV_NORMAL will not be output in LV_HIGH levels.  
Thus, you can display messages with low priority on the initial debugging, and then only important ones.  

To output messages, you must initialize the required transmission rate:  
`LOG_BEGIN (57600);`  

The output of messages is made by commands, similar to the output of Serial.print() and Serial.println():  
for LV_LOW:  
`LOG(logMessage)` - no new line  
`LOG_LN(logMessage)` - with new line  
`LOG_L(logMessage)` - no new line  
`LOG_L_LN(logMessage)` - with new line  

for LV_NORMAL:  
`LOG_N(logMessage)` - no new line  
`LOG_N_LN(logMessage)` - with new line  

for LV_HIGH:  
`LOG_H(logMessage)` - no new line  
`LOG_H_LN(logMessage)` - with new line  
  
  
To save memory, you can store string messages in FLASH, for example:  
`LOG_N_LN(F("DEBUG MESSAGE"));`  

When debugging is no longer needed, to free memory from SerialLog, you must comment out  
`//#define DEBUG LV_XXX`  
in SerialLog.h or specify LV_NONE:  
`#define DEBUG LV_NONE`  

In a project using a library, you need to add the following to enable debugging:  
`#include "SerialLog.h"`  

## Install
Put library folder in to Arduino library path "Scetchbook location", example:  
- C:\Users\USER_NAME\Documents\Arduino\libraries\SerialLog

## Memory free information
For show available memory in log output, install [MemoryFree Library](https://playground.arduino.cc/Code/AvailableMemory) and uncomment:  
`#define DEBUG_MEMORY`  
in SerialLog.h

## Example of use:
```
#include "SerialLog.h"

// the setup function runs once when you press reset or power the board
void setup () {
    //init logger
    LOG_BEGIN(57600);
    
    //print strin message
    LOG_LN("SETUP ...");

    //print variable value
    LOG("LED_BUILDIN:");
    LOG_LN(LED_BUILTIN);

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);    
}

// the loop function runs over and over again again forever
void loop () {
    LOG_LN("LOOP");

    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(1000); // wait for a second
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off by making the voltage LOW
    delay(1000); // wait for a second

}
```
