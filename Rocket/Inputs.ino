/**
 * Key Inputs
 * Handles setup & listening for keys
 */

#include <Button.h>

unsigned int octave = 5;
byte k1, k2, k3, k4, k5, k6, k7, k8;

Button b1 = Button(0, BUTTON_PULLUP_INTERNAL, true, 50);
Button b2 = Button(1, BUTTON_PULLUP_INTERNAL, true, 10);
Button b3 = Button(2, BUTTON_PULLUP_INTERNAL, true, 10);
Button b4 = Button(3, BUTTON_PULLUP_INTERNAL, true, 10);
Button b5 = Button(4, BUTTON_PULLUP_INTERNAL, true, 10);
Button b6 = Button(5, BUTTON_PULLUP_INTERNAL, true, 10);
Button b7 = Button(6, BUTTON_PULLUP_INTERNAL, true, 10);
Button b8 = Button(7, BUTTON_PULLUP_INTERNAL, true, 10);
Button f1 = Button(12, BUTTON_PULLUP_INTERNAL, true, 10);
Button f2 = Button(13, BUTTON_PULLUP_INTERNAL, true, 10);

void pressOne(Button& b) {
  Serial.println("Click");
  triggerNote(1, chooseChannel());
}

void pressTwo(Button& b) {
  triggerNote(2, chooseChannel());
}

void pressThree(Button& b) {
  triggerNote(3, chooseChannel());
}

void pressFour(Button& b) {
  triggerNote(4, chooseChannel());
}

void pressFive(Button& b) {
  triggerNote(5, chooseChannel());
}

void pressSix(Button& b) {
  triggerNote(6, chooseChannel());
}

void pressSeven(Button& b) {
  triggerNote(7, chooseChannel());
}

void pressEight(Button& b) {
  triggerNote(8, chooseChannel());
}

void pressNine(Button& b) {

}

void pressTen(Button& b) {
}

void setupInputs() {
  b1.pressHandler(pressOne);
  b2.pressHandler(pressTwo);
  b3.pressHandler(pressThree);
  b4.pressHandler(pressFour);
  b5.pressHandler(pressFive);
  b6.pressHandler(pressSix);
  b7.pressHandler(pressSeven);
  b8.pressHandler(pressEight);
  f1.pressHandler(pressNine);
  f2.pressHandler(pressTen);
}

/** 
 *  Set values of k[n] variables
 *  according to octave
 */
void updateNotes() {
  k1 = (octave * 12) + 0;
  k2 = (octave * 12) + 2;
  k3 = (octave * 12) + 4;
  k4 = (octave * 12) + 5;
  k5 = (octave * 12) + 7;
  k6 = (octave * 12) + 9;
  k7 = (octave * 12) + 11;
  k8 = (octave * 12) + 12;
}

/**
 * chooseChannel()
 * determine which channel to
 * trigger note on, if no
 * channels are free, just
 * play on last channel.
 */
int chooseChannel() {
  if (!noteOneEnvelope.playing()) {
    Serial.println("Chose 0");
    return 0;
  } else if (!noteTwoEnvelope.playing()) {
    Serial.println("Chose 1");
    return 1;
  } else if (!noteThreeEnvelope.playing()) {
    Serial.println("Chose 2");
    return 2;
  } else {
    Serial.println("Chose 2");
    return 2;
  }
}

void triggerNote(int key, int channel) {
  if (channel == 0) {
    if (key == 1) {
      noteOne.setFreq((int)mtof(k1));
      noteOneEnvelope.noteOn();
    } else if (key == 2) {
      noteOne.setFreq((int)mtof(k2));
      noteOneEnvelope.noteOn();
    } else if (key == 3) {
      noteOne.setFreq((int)mtof(k3));
      noteOneEnvelope.noteOn();
    } else if (key == 4) {
      noteOne.setFreq((int)mtof(k4));
      noteOneEnvelope.noteOn();
    } else if (key == 5) {
      noteOne.setFreq((int)mtof(k5));
      noteOneEnvelope.noteOn();
    } else if (key == 6) {
      noteOne.setFreq((int)mtof(k6));
      noteOneEnvelope.noteOn();
    } else if (key == 7) {
      noteOne.setFreq((int)mtof(k7));
      noteOneEnvelope.noteOn();
    } else if (key == 8) {
      noteOne.setFreq((int)mtof(k8));
      noteOneEnvelope.noteOn();
    }
  } else if (channel == 1) {
    if (key == 1) {
      noteTwo.setFreq(mtof(60));
      noteTwoEnvelope.noteOn();
    } else if (key == 2) {
      noteTwo.setFreq(mtof(62));
      noteTwoEnvelope.noteOn();
    } else if (key == 3) {
      noteTwo.setFreq(mtof(64));
      noteTwoEnvelope.noteOn();
    } else if (key == 4) {
      noteTwo.setFreq(mtof(65));
      noteTwoEnvelope.noteOn();
    } else if (key == 5) {
      noteTwo.setFreq(mtof(67));
      noteTwoEnvelope.noteOn();
    } else if (key == 6) {
      noteTwo.setFreq(mtof(69));
      noteTwoEnvelope.noteOn();
    } else if (key == 7) {
      noteTwo.setFreq(mtof(71));
      noteTwoEnvelope.noteOn();
    } else if (key == 8) {
      noteTwo.setFreq(mtof(72));
      noteTwoEnvelope.noteOn();
    }
  } else if (key == 2) {
    if (key == 1) {
      noteThree.setFreq(mtof(60));
      noteThreeEnvelope.noteOn();
    } else if (key == 2) {
      noteThree.setFreq(mtof(62));
      noteThreeEnvelope.noteOn();
    } else if (key == 3) {
      noteThree.setFreq(mtof(64));
      noteThreeEnvelope.noteOn();
    } else if (key == 4) {
      noteThree.setFreq(mtof(65));
      noteThreeEnvelope.noteOn();
    } else if (key == 5) {
      noteThree.setFreq(mtof(67));
      noteThreeEnvelope.noteOn();
    } else if (key == 6) {
      noteThree.setFreq(mtof(69));
      noteThreeEnvelope.noteOn();
    } else if (key == 7) {
      noteThree.setFreq(mtof(71));
      noteThreeEnvelope.noteOn();
    } else if (key == 8) {
      noteThree.setFreq(mtof(72));
      noteThreeEnvelope.noteOn();
    }
  }
}

void processInputs() {
  b1.process();
  b2.process();
  b3.process();
  b4.process();
  b5.process();
  b6.process();
  b7.process();
  b8.process();
  f1.process();
  f2.process();
}

