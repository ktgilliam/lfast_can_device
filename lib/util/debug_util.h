/*******************************************************************************
Copyright 2021
Steward Observatory Engineering & Technical Services, University of Arizona

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
*******************************************************************************/

#include <Arduino.h>
#include <math.h>

#pragma once

// Add this line to platformio.ini to enable serial debug messages:
// build_flags = -D DEBUG_ENABLED
//
// To specify a baud rate other than 9600 you can also add the following:
// -D DEBUG_SERIAL_BAUD=<baud rate> 

// Display diagnostic messages on serial port if debugging is enabled
#ifdef DEBUG_ENABLED
#if defined(DEBUG_HW_SERIAL_NO)
  #if DEBUG_HW_SERIAL_NO==1
      #define DEBUG_SERIAL_RX_PIN 0
      #define DEBUG_SERIAL_TX_PIN 1
      #define DebugPrintln( msg )     Serial1.println( msg )
      #define DebugPrint( msg )       Serial1.print( msg )
      #define DebugPrintf( ... )      Serial1.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==2
      #define DEBUG_SERIAL_RX_PIN 7
      #define DEBUG_SERIAL_TX_PIN 8
      #define DebugPrintln( msg )     Serial2.println( msg )
      #define DebugPrint( msg )       Serial2.print( msg )
      #define DebugPrintf( ... )      Serial2.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==3
      #define DEBUG_SERIAL_RX_PIN 15
      #define DEBUG_SERIAL_TX_PIN 14
      #define DebugPrintln( msg )     Serial3.println( msg )
      #define DebugPrint( msg )       Serial3.print( msg )
      #define DebugPrintf( ... )      Serial3.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==4
      #define DEBUG_SERIAL_RX_PIN 16
      #define DEBUG_SERIAL_TX_PIN 17
      #define DebugPrintln( msg )     Serial4.println( msg )
      #define DebugPrint( msg )       Serial4.print( msg )
      #define DebugPrintf( ... )      Serial4.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==5
      #define DEBUG_SERIAL_RX_PIN 21
      #define DEBUG_SERIAL_TX_PIN 20
      #define DebugPrintln( msg )     Serial5.println( msg )
      #define DebugPrint( msg )       Serial5.print( msg )
      #define DebugPrintf( ... )      Serial5.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==6
      #define DEBUG_SERIAL_RX_PIN 25
      #define DEBUG_SERIAL_TX_PIN 24
      #define DebugPrintln( msg )     Serial6.println( msg )
      #define DebugPrint( msg )       Serial6.print( msg )
      #define DebugPrintf( ... )      Serial6.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==7
      #define DEBUG_SERIAL_RX_PIN 28
      #define DEBUG_SERIAL_TX_PIN 29
      #define DebugPrintln( msg )     Serial7.println( msg )
      #define DebugPrint( msg )       Serial7.print( msg )
      #define DebugPrintf( ... )      Serial7.printf(__VA_ARGS__)
  #elif  DEBUG_HW_SERIAL_NO==8
      #define DEBUG_SERIAL_RX_PIN 34
      #define DEBUG_SERIAL_TX_PIN 35
      #define DebugPrintln( msg )     Serial8.println( msg )
      #define DebugPrint( msg )       Serial8.print( msg )
      #define DebugPrintf( ... )      Serial8.printf(__VA_ARGS__)
  #endif
#else
  #define DebugPrintln( msg )     Serial.println( msg )
  #define DebugPrint( msg )       Serial.print( msg )
  #define DebugPrintf( ... )      Serial.printf(__VA_ARGS__)
#endif
#ifndef DEBUG_SERIAL_BAUD
#define DEBUG_SERIAL_BAUD 9600
#endif
#else
  #define DebugPrintln( msg )
  #define DebugPrint( msg )
  #define DebugPrintf( ... )
#endif


// #define DEBUG_PIN 32

#if defined DEBUG_PIN
  #define TOGGLE_DEBUG_PIN() digitalWrite(DEBUG_PIN, !digitalRead(DEBUG_PIN));
  #define SET_DEBUG_PIN() digitalWrite(DEBUG_PIN, 1);
  #define CLEAR_DEBUG_PIN() digitalWrite(DEBUG_PIN, 0);
#else
  #define TOGGLE_DEBUG_PIN()
  #define SET_DEBUG_PIN()
  #define CLEAR_DEBUG_PIN()
#endif

#define TOGGLE_LED_PIN() digitalWrite(LED_PIN, !digitalRead(LED_PIN));

#define PRINT_GOT_HERE() DebugPrintf("@ %s: %d\r\n", __FILE__, __LINE__)

#define TEENSY_VERSION ", Teensy 4.1"

#ifdef DEBUG_ENABLED
  #define DEBUG_VERSION ", DEBUG"
#else
  #define DEBUG_VERSION ""
#endif
