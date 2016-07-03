int buttons[4] = {0, 1, 3, 4};

void setupButons() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

bool isButtonsPressed(int button) {
  return !digitalRead(buttons[button]);
}

void loopWhileButtonPressed(int button) {
  while (isButtonsPressed(button)) {
    delay(50);
  }
}

int readButtons() {
  //  if (keyPressed){
  //    keyPressed = false;
  for (int i = 0; i < 4; i++) {
    if (isButtonsPressed(i))
      return colors[i];
  }
  //  }
  return -1;
}

