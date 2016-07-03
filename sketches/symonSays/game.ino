/*#define led_dataPin 4
  #define led_LATCH_HIGH sbi(PORTD, led_latchPin)
  #define led_LATCH_LOW cbi(PORTD, led_latchPin)

*/

bool isPlayerPlaying = false;
Move * gameMoves = NULL;

void setupGame() {
  pinMode(6, OUTPUT);

  newGame();
}

struct Move * createGameMove() {
  Move * newMove = (Move *)malloc(sizeof(Move));
  newMove->next = NULL;
  newMove->color = colors[random(4)];
  return newMove;
}

void freeGameMoves(Move * currentMove) {
  if (currentMove == NULL)
    return;
  freeGameMoves(currentMove->next);
  free(currentMove);
}

void addNewGameMove() {
  Move * currentMove = gameMoves;
  while (currentMove->next != NULL) {
    currentMove = currentMove->next;
  }
  currentMove->next = createGameMove();
}

void newGame() {
  freeGameMoves(gameMoves);
  gameMoves = createGameMove();
}

void showCurrentGame() {
  Move * currentMove = gameMoves;
  do {
    showColor(currentMove->color);    
    currentMove = currentMove->next;
  } while (currentMove != NULL);
}

void gameLoop() {
  if (!isPlayerPlaying) {
    showCurrentGame();
    isPlayerPlaying = true;
    return;
  }

  tryReadButtons();

  sleepNow();     // sleep function called here
}

