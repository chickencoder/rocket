/**
 * Some nice envelopes
 */

void updateEnvelopes() {
  noteOneEnvelope.update();
  noteTwoEnvelope.update();
  noteThreeEnvelope.update();
}

void setEnv(int attack_level, int decay_level, int attack, int decay, int sustain, int releaset) {
  noteOneEnvelope.setADLevels(attack_level, decay_level);
  noteOneEnvelope.setTimes(attack, decay, sustain, releaset);

  noteTwoEnvelope.setADLevels(attack_level, decay_level);
  noteTwoEnvelope.setTimes(attack, decay, sustain, releaset);

  noteThreeEnvelope.setADLevels(attack_level, decay_level);
  noteThreeEnvelope.setTimes(attack, decay, sustain, releaset);
}



