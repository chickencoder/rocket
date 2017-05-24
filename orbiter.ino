/**
 * Orbiter-1
 * Portable polyphonic instrument
 * Written By Jesse Sibley 
 * http://chickencoder.github.io/orbiter
 * 
 * Pin          Connection
 * DIGTIAL PINS ==========================
 * 0            Key 1 (momentary switch)
 * 1            Key 2 (momentary switch)
 * 2            Key 3 (momentary switch)
 * 3            Key 4 (momentary switch)
 * 4            Key 5 (momentary switch)
 * 5            Key 6 (momentary switch)
 * 6            Key 7 (momentary switch)            
 * 7            FREE
 * 8            FREE
 * 9            Audio Out 1
 * 10           Audio Out 2
 * 11           LED 1
 * 12           Meta Key (momentary switch)
 * 13           FREE
 * ANALOG PINS ===========================
 * 0            FREE
 * 1            FREE
 * 2            Rotary Encoder Receive 1
 * 3            Rotary Encoder Receive 2
 * 4            Potentiometer 1
 * 5            Potentiometer 2
 */


#include <MozziGuts.h>
#include <Oscil.h>
#include <tables/saw_analogue512_int8.h>

// use: Oscil <table_size, update_rate> oscilName (wavetable), look in .h file of table #included above
Oscil <SAW_ANALOGUE512_NUM_CELLS, AUDIO_RATE> aSaw(SAW_ANALOGUE512_DATA);

#define CONTROL_RATE 64

void setup(){
  startMozzi(CONTROL_RATE); // set a control rate of 64 (powers of 2 please)
  aSaw.setFreq(440); // set the frequency
}


void updateControl(){
  // put changing controls in here
}


int updateAudio(){
  return aSaw.next(); // return an int signal centred around 0
}


void loop(){
  audioHook(); // required here
}

