/**
 * Some nice envelopes
 */

void updateEnvelopes() {
  noteOneEnvelope.update();
  noteTwoEnvelope.update();
  noteThreeEnvelope.update();
  noteFourEnvelope.update();
  noteFiveEnvelope.update();
  noteSixEnvelope.update();
  noteSevenEnvelope.update();
  noteEightEnvelope.update();
}

void setupStandardEnv() {
  noteOneEnvelope.setADLevels(100, 100);
  noteOneEnvelope.setTimes(250, 500, 250, 500);

  noteTwoEnvelope.setADLevels(100, 100);
  noteTwoEnvelope.setTimes(250, 500, 250, 500);

  noteThreeEnvelope.setADLevels(100, 100);
  noteThreeEnvelope.setTimes(250, 500, 250, 500);

  noteFourEnvelope.setADLevels(100, 100);
  noteFourEnvelope.setTimes(250, 500, 250, 500);

  noteFiveEnvelope.setADLevels(100, 100);
  noteFiveEnvelope.setTimes(250, 500, 250, 500);

  noteSixEnvelope.setADLevels(100, 100);
  noteSixEnvelope.setTimes(250, 500, 250, 500);

  noteSevenEnvelope.setADLevels(100, 100);
  noteSevenEnvelope.setTimes(250, 500, 250, 500);

  noteEightEnvelope.setADLevels(100, 100);
  noteEightEnvelope.setTimes(250, 500, 250, 500);
}


