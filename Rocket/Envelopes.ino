/**
 * Some nice envelopes
 */

void updateEnvelopes() {
  noteOneEnvelope.update();
  noteTwoEnvelope.update();
  noteThreeEnvelope.update();
}

void setupStandardEnv() {
  noteOneEnvelope.setADLevels(100, 100);
  noteOneEnvelope.setTimes(250, 500, 250, 500);

  noteTwoEnvelope.setADLevels(100, 100);
  noteTwoEnvelope.setTimes(250, 500, 250, 500);

  noteThreeEnvelope.setADLevels(100, 100);
  noteThreeEnvelope.setTimes(250, 500, 250, 500);
}


