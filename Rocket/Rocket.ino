/**
 * Rocket Software for the Orbiter-1
 * Portable polyphonic instrument
 * Written By Jesse Sibley 
 * http://chickencoder.github.io/orbiter
 * http://github.com/chickencoder/rocket
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
 * 7            Key 8 (momentary switch)   
 * 8            FREE
 * 9            Audio Out 1
 * 10           Audio Out 2
 * 11           LED 1
 * 12           F1 Key (momentary switch)
 * 13           F2 Key (momentary switch)
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
#include <ADSR.h>
#include <LowPassFilter.h>
#include <EventDelay.h>
#include <mozzi_midi.h>
#include <tables/sin2048_int8.h>
#include <tables/saw2048_int8.h>
#include <samples/bamboo/bamboo_00_2048_int8.h>
#include <Button.h>

#define CONTROL_RATE 64
#define SINE_MODE 0
#define SAW_MODE 1
#define PING_MODE 2
byte MODE = 0;

/** Osciallators **/
Oscil <2048, AUDIO_RATE> noteOne(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> noteTwo(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> noteThree(SIN2048_DATA);

/** Envelopes **/
ADSR <CONTROL_RATE, AUDIO_RATE> noteOneEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteTwoEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteThreeEnvelope;

/** Filters **/
//LowPassFilter lpf;

void setup() {
  Serial.begin(115200);
  startMozzi(CONTROL_RATE);  
  setupInputs();
  updateNotes();
  updateMode();
}

void updateControl() {
  processInputs();
  updateEnvelopes();
}

int updateAudio() {
  int chanA = ((int)noteOne.next() * (long)noteOneEnvelope.next()) >> 8;
  int chanB = ((int)noteTwo.next() * (long)noteTwoEnvelope.next()) >> 8;
  int chanC = ((int)noteThree.next() * (long)noteThreeEnvelope.next()) >> 8;
  return chanA + chanB + chanC / 3;
}

void loop() {
  audioHook();
}


