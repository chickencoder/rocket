/**
 * Key Inputs
 * Handles setup & listening for keys
 */

unsigned int octave = 5;
unsigned int k1, k2, k3, k4, k5, k6, k7, k8;

void setupInputs() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}

/** 
 *  Set values of k[n] variables
 *  according to octave
 */
void updateNotes() {
  k1 = (octave * 12) + 0u;
  k2 = (octave * 12) + 2u;
  k3 = (octave * 12) + 4u;
  k4 = (octave * 12) + 5u;
  k5 = (octave * 12) + 7u;
  k6 = (octave * 12) + 9u;
  k7 = (octave * 12) + 11u;
  k8 = (octave * 12) + 12u;
}

void triggerNote(int key) {
  if (key == 1) {
    if (!noteOneEnvelope.playing()) {
      Serial.println("TRIGGER ENV");
      noteOne.setFreq(mtof(60));
      noteOneEnvelope.noteOn();
    }
    
  } else if (key == 2) {
    if (!noteTwoEnvelope.playing()) {
      noteTwo.setFreq(mtof(62));
      noteTwoEnvelope.noteOn();
    }
  } else if (key == 3) {
    if (!noteThreeEnvelope.playing()) {
      noteThree.setFreq(mtof(64));
      noteThreeEnvelope.noteOn();
    }
  } else if (key == 4) {
    if (!noteFourEnvelope.playing()) {
      noteFour.setFreq(mtof(65));
      noteFourEnvelope.noteOn();
    }
  } else if (key == 5) {
    if (!noteFiveEnvelope.playing()) {
      noteFive.setFreq(mtof(67));
      noteFiveEnvelope.noteOn();
    }
  } else if (key == 6) {
    if (!noteSixEnvelope.playing()) {
      noteSix.setFreq(mtof(69));
      noteSixEnvelope.noteOn();
    }
  } else if (key == 7) {
    if (!noteSevenEnvelope.playing()) {
      noteSeven.setFreq(mtof(71));
      noteSevenEnvelope.noteOn();
    }
  } else if (key == 8) {
    if (!noteEightEnvelope.playing()) {
      noteEight.setFreq(mtof(72));
      noteEightEnvelope.noteOn();
    }
  }     
}

void handleKeyInputs() {
  if (digitalRead(0) == LOW) {
    triggerNote(1);
  }
  
  if (digitalRead(1) == LOW) {
    triggerNote(2);
  }
  
  if (digitalRead(2) == LOW) {
    triggerNote(3);
  }
  
  if (digitalRead(3) == LOW) {
    triggerNote(4);
  }
  
  if (digitalRead(4) == LOW) {
    triggerNote(5);
  } 
  
  if (digitalRead(5) == LOW) {
    triggerNote(6);
  }
  
  if (digitalRead(6) == LOW) {
    triggerNote(7);
  } 
  
  if (digitalRead(7) == LOW) {
    triggerNote(8);
  }
}



