/**
 * Modes
 */

void resetMode() {
  // Reset to defaults
  HOOK_LFO = false;
  MONO_MODE = false;
  LFO.setTable(SIN2048_DATA);
  octave = 5;
  updateNotes();
}

void amMode() {
  resetMode();
  setEnv(200, 100, 500, 200, 1000, 800);
  noteOne.setTable(SIN2048_DATA);
  noteTwo.setTable(SIN2048_DATA);
  noteThree.setTable(SIN2048_DATA);
}

void sawMode() {
  resetMode();
  setEnv(200, 200, 100, 300, 200, 200);
  noteOne.setTable(SAW2048_DATA);
  noteTwo.setTable(SAW2048_DATA);
  noteThree.setTable(SAW2048_DATA);
}

void droneMode() {
  resetMode();
  HOOK_LFO = true;
  setEnv(200, 200, 500, 300, 500, 1000);
  noteOne.setTable(SIN2048_DATA);
  noteTwo.setTable(SIN2048_DATA);
  noteThree.setTable(SIN2048_DATA);
}

void bassMode() {
  resetMode();
  octave = 3;
  updateNotes();
  MONO_MODE = true;
  setEnv(200, 200, 10, 100, 10, 10);
  noteOne.setTable(SAW2048_DATA);
  noteTwo.setTable(SAW2048_DATA);
  noteThree.setTable(SAW2048_DATA);
}

void fmMode() {
  resetMode();
  MONO_MODE = true;
  setEnv(200, 200, 10, 20, 200, 400);
  noteOne.setTable(SAW2048_DATA);
  noteTwo.setTable(SIN2048_DATA);
  noteThree.setTable(SIN2048_DATA);
  LFO.setTable(SAW2048_DATA);
}

void activateArp() {
  MONO_MODE = true;
}

void deactivateArp() {
  updateMode();
}

void updateMode() {
  if (MODE == AM_MODE) {
    amMode();
  } else if (MODE == SAW_MODE) {
    sawMode();
  } else if (MODE == DRONE_MODE) {
    droneMode();
  } else if (MODE == BASS_MODE) {
    bassMode();
  } else if (MODE == FM_MODE) {
    fmMode();
  }
}
