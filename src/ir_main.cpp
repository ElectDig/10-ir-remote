/*
 *  Project: 10-ir-remote
 *  main file: ir_main.cpp
 *
 *  Electronica Digital - Austral 2023 - EAM
 *
 *  Uses IRremoteESP8266 library (extended to ESP32)
 */

//  System include files

#include <Arduino.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>

//  Project include files

#include "ir_convert.h"

//  Object instantation

IRrecv irrecv(IR_RCV);

//  Global private variables

static decode_results results;

//  Private functions

static void
process_remote(void)
{
    int key;

#if IN_TEST         // For testing codes
    Serial.printf("%6lX\n", results.value);
#else               // For converting and using remote
    key = ir_convert( results.value );
    if( key != DEL && key != NUL )
        Serial.printf("%c", key);
#endif
}

//  Public functions
 
void
setup()
{
    Serial.begin(115200);
    while (!Serial)      // Wait for the serial connection to be establised.
        delay(50);
    irrecv.enableIRIn(); // Start the receiver
    Serial.printf("\nIRrecvDemo is now running and waiting for IR message on Pin %d\n", IR_RCV);
}

void
loop()
{
    if (irrecv.decode(&results))
    {
        process_remote();
        irrecv.resume(); // Receive the next value
    }
    delay(20);
}
