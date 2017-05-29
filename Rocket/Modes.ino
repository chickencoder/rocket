/**
 * Modes
 */

void sineMode() {
  setEnv(200, 100, 500, 200, 600, 400);
  noteOne.setTable(SIN2048_DATA);
  noteTwo.setTable(SIN2048_DATA);
  noteThree.setTable(SIN2048_DATA);
}

void sawMode() {
  setEnv(200, 200, 100, 300, 200, 200);
  noteOne.setTable(SAW2048_DATA);
  noteTwo.setTable(SAW2048_DATA);
  noteThree.setTable(SAW2048_DATA);
}

void droneMode() {
  setEnv(200, 200, 100, 300, 200, 200);
  noteOne.setTable(SIN2048_DATA);
  noteTwo.setTable(SIN2048_DATA);
  noteThree.setTable(SIN2048_DATA);
}

void updateMode() {
  if (MODE == SINE_MODE) {
    sineMode();
  } else if (MODE == SAW_MODE) {
    sawMode();
  } else if (MODE == PING_MODE) {
    droneMode();
  }
}
