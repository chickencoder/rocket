/**
 * Key Inputs
 * Handles setup & listening for keys
 */

unsigned int octave = 5;
byte k1, k2, k3, k4, k5, k6, k7, k8;
int p1, p2;

byte arp[16];
byte arp2[16];
int ap, sp;

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
  triggerNote(k1, chooseChannel());
}

void pressTwo(Button& b) {
  triggerNote(k2, chooseChannel());
}

void pressThree(Button& b) {
  triggerNote(k3, chooseChannel());
}

void pressFour(Button& b) {
  triggerNote(k4, chooseChannel());
}

void pressFive(Button& b) {
  triggerNote(k5, chooseChannel());
}

void pressSix(Button& b) {
  triggerNote(k6, chooseChannel());
}

void pressSeven(Button& b) {
  triggerNote(k7, chooseChannel());
}

void pressEight(Button& b) {
  triggerNote(k8, chooseChannel());
}

/**
 * F1 currently wired to mode select
 */
void pressNine(Button& b) {
  // Pause Mozzi for 500ms to switch mode
  pauseMozzi();
  MODE = (MODE + 1) % 4;
  updateMode();
  unPauseMozzi();
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
    return 0;
  } else if (!noteTwoEnvelope.playing()) {
    return 1;
  } else if (!noteThreeEnvelope.playing()) {
    return 2;
  } else {
    return 2;
  }
}

void triggerNote(int note, int channel) {
  if (channel == 0) {
    noteOne.setFreq((int)mtof(note));
    noteOneEnvelope.noteOn();
  } else if (channel == 1) {
    noteTwo.setFreq((int)mtof(note));
    noteTwoEnvelope.noteOn();
  } else if (channel == 2) {
    noteThree.setFreq((int)mtof(note));
    noteThreeEnvelope.noteOn();
  }
}

void processInputs() {
  if (MODE != ARP_MODE) {
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
    p1 = mozziAnalogRead(A4);
    p2 = mozziAnalogRead(A5);
  }
}

void updateArp() {
  // Firstly, play note at arp pointer then
  // If key is being pressed, add to arp
  // (and add note from next octave as well)
  // inc ap by 2 each time
  // insert notes at ap-2, ap-1
  // if arp pointer gets to 15, set back to 0
  if (MODE == ARP_MODE) {
    if (digitalRead(0) == LOW) {
      arp[sp] = k1;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(0) == LOW) {
      arp[sp] = k1;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(1) == LOW) {
      arp[sp] = k2;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(2) == LOW) {
      arp[sp] = k3;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(3) == LOW) {
      arp[sp] = k4;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(4) == LOW) {
      arp[sp] = k5;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(5) == LOW) {
      arp[sp] = k6;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (digitalRead(6) == LOW) {
      arp[sp] = k7;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }
    
    if (digitalRead(7) == LOW) {
      arp[sp] = k8;
      sp++;
      arp2[sp] = k1 + 12;
      sp++;
    }

    if (sp > 16) {
      sp = 0;
    }

    if (digitalRead(0) + digitalRead(1) + digitalRead(2) + digitalRead(3) +
        digitalRead(4) + digitalRead(5) + digitalRead(6) + digitalRead(7) == 8) {
      for (int i = 0; i < 16; i++) {
        arp[i] = 0;
        ap = 0;
      }
    }

    // Play notes on each beat
    if (ap < 15) {
      triggerNote(arp[ap], 0);
      triggerNote(arp2[ap], 1);
      ap += 1;
    } else {
      triggerNote(arp[ap], 0);
      triggerNote(arp2[ap], 1);
      ap = 0;
    }
  }
}

void updateTempo() {
  if (metro.ready()) {
    updateArp();
  }
}

