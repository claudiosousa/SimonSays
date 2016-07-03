int buttons[4] = {0, 1, 3, 4};

void setupButons() {
  for (int i = 0; i < 4; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

int tryReadButtons() {
  //  if (keyPressed){
  //    keyPressed = false;
  for (int i = 0; i < 4; i++) {
    if (!digitalRead(buttons[i]))
      return colors[i];
  }
  //  }
  return -1;
}

