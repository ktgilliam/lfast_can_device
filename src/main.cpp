///
///  @ Author: Kevin Gilliam
///  @ Create Time: 2022-09-06 09:36:04
///  @ Modified by: Kevin Gilliam
///  @ Modified time: 2022-09-08 12:13:45
///  @ Description:
///

#include <debug_util.h>
#include <Arduino.h>
#include <cctype>
#include <cmath>

// Message Handlers:

/**
 * @brief configure pins and test interfaces
 *
 */
void deviceSetup()
{
}

/**
 * @brief call init functions for the modules used
 *
 */
void setup(void)
{
    deviceSetup();
}

void loop(void)
{
    PRINT_GOT_HERE();
    delay(1000);
}
