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
#include <EventDelay.h>
#include <mozzi_midi.h>
#include <tables/smoothsquare8192_int8.h>

#define CONTROL_RATE 128

/** Osciallators **/
Oscil <1024, AUDIO_RATE> noteOne(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteTwo(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteThree(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteFour(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteFive(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteSix(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteSeven(SMOOTHSQUARE8192_DATA);
Oscil <1024, AUDIO_RATE> noteEight(SMOOTHSQUARE8192_DATA);

/** Envelopes **/
ADSR <CONTROL_RATE, AUDIO_RATE> noteOneEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteTwoEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteThreeEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteFourEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteFiveEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteSixEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteSevenEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteEightEnvelope;

int MASTER_VOLUME = 1;

void setup() {
  Serial.begin(115200);
  startMozzi(CONTROL_RATE);  
  setupInputs();
  setupStandardEnv();
  updateNotes();
}

void updateControl() {
  handleKeyInputs();
  updateEnvelopes();
}

int updateAudio() {
  int chanA = ((int) noteOne.next() * (long) noteOneEnvelope.next()) >> 8;
  int chanB = ((int) noteTwo.next() * (long) noteTwoEnvelope.next()) >> 9;
  int chanC = ((int) noteThree.next() * (long) noteThreeEnvelope.next()) >> 9;
  int chanD = ((int) noteFour.next() * (long) noteFourEnvelope.next()) >> 9;
  int chanE = ((int) noteFive.next() * (long) noteFiveEnvelope.next()) >> 9;
  int chanF = ((int) noteSix.next() * (long) noteSixEnvelope.next()) >> 9;
  int chanG = ((int) noteSeven.next() * (long) noteSevenEnvelope.next()) >> 9;
  int chanH = ((int) noteEight.next() * (long) noteEightEnvelope.next()) >> 9;
  int master = (chanA + chanB + chanC + chanD + chanE + chanF + chanG + chanH);
  return (master * MASTER_VOLUME);
}

void loop() {
  audioHook();
}


