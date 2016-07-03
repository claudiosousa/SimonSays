Move * gameMoves = NULL;
Move * currentMove2find = NULL;

void setupGame() {
  newGame();
  showCurrentGame();
  resetMove2Find();
}

struct Move * createGameMove() {
  Move * newMove = (Move *)malloc(sizeof(Move));
  newMove->next = NULL;
  newMove->color = colors[random(4)];
  return newMove;
}

void resetMove2Find() {
  currentMove2find = gameMoves;
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

void handleColorPress(int color) {
  if (color == currentMove2find->color) {
    showColorWhileButton(color);
    currentMove2find = currentMove2find->next;
    if (currentMove2find == NULL){
      delay(300);
      addNewGameMove();
    }
  } else {
    showWrongColor(color);
    newGame();
    currentMove2find = NULL;
  }

  if (currentMove2find == NULL) {
    showCurrentGame();
    resetMove2Find();
  }
}

void gameLoop() {

  int color = readButtons();
  if (color != -1) {
    handleColorPress(color);
    return;
  }
  sleepNow();
}

