
void setup()
{
  randomSeed(analogRead(0));

  setupSleep();
  setupBoard();
  setupButons();
  setupGame();
}

void loop()
{
  gameLoop();
}


