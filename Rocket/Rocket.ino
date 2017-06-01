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
#include <AudioDelayFeedback.h>
#include <Metronome.h>
#include <mozzi_midi.h>
#include <tables/sin2048_int8.h>
#include <tables/saw2048_int8.h>
#include <tables/triangle2048_int8.h>
#include <Button.h>

/** Constants **/
#define CONTROL_RATE 64
#define DRONE_MODE 0
#define AM_MODE 1
#define SAW_MODE 2
#define BASS_MODE 3
#define FM_MODE 4

/** Globals **/
byte MODE = 0;
bool MONO_MODE = false;
int ARP_MODE = -1;
bool HOOK_LFO = false;
unsigned int bpm = 240;

/** Osciallators **/
Oscil <2048, AUDIO_RATE> noteOne(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> noteTwo(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> noteThree(SIN2048_DATA);
Oscil <2048, AUDIO_RATE> LFO(SIN2048_DATA);

/** Envelopes **/
ADSR <CONTROL_RATE, AUDIO_RATE> noteOneEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteTwoEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> noteThreeEnvelope;
ADSR <CONTROL_RATE, AUDIO_RATE> LFOEnvelope;

/** Event Delays **/
EventDelay tempo;
Metronome metro;

/** Filters **/
//LowPassFilter lpf;

void setup() {
  Serial.begin(115200);
  startMozzi(CONTROL_RATE);
  setupInputs();
  updateNotes();
  updateMode();
  metro.setBPM(bpm);
  metro.start();
}

void updateControl() {
  processInputs();
  updateEnvelopes();
  updateTempo();
}

int updateAudio() {
  if (MODE == AM_MODE) {
    int chanA = ((int)noteOne.next() * LFO.next() * (long)noteOneEnvelope.next()) >> 16;
    int chanB = ((int)noteTwo.next() * LFO.next() * (long)noteTwoEnvelope.next()) >> 16;
    int chanC = ((int)noteThree.next() * LFO.next() * (long)noteThreeEnvelope.next()) >> 16;
    return (chanA + chanB + chanC) / 2;
  } else if (HOOK_LFO) {
    int chanA = ((int)noteOne.next() * (long)noteOneEnvelope.next()) >> 8;
    int chanB = ((int)noteTwo.next() * (long)noteTwoEnvelope.next()) >> 8;
    int chanC = ((int)noteThree.next() * (long)noteThreeEnvelope.next()) >> 8;
    int chanD = ((int)LFO.next() * (long)LFOEnvelope.next()) >> 8;
    return (chanA + chanB + chanC + chanD) / 4;
  } else if (MODE == FM_MODE) {
    int chanA = ((int)noteOne.phMod(LFO.next()) * (long)noteOneEnvelope.next()) >> 8;
    int chanB = ((int)noteTwo.phMod(LFO.next()) * (long)noteTwoEnvelope.next()) >> 8;
    int chanC = ((int)noteThree.phMod(LFO.next()) * (long)noteThreeEnvelope.next()) >> 8;
    return (chanA + chanB + chanC) / 3;
  } else {
    int chanA = ((int)noteOne.next() * (long)noteOneEnvelope.next()) >> 8;
    int chanB = ((int)noteTwo.next() * (long)noteTwoEnvelope.next()) >> 8;
    int chanC = ((int)noteThree.next() * (long)noteThreeEnvelope.next()) >> 8;
    return (chanA + chanB + chanC) / 3;
  }
}

void loop() {
  audioHook();
}


