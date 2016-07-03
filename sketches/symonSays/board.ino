#include <toneAC.h>

typedef enum Color{
  Green,
  Red,
  Yellow,
  Blue
} Color;

Color colors[4] = {Green, Red, Yellow, Blue};
byte colorPin[4] = {6, 5, 8, 7};
float colorSound[4] = {note_E3, note_A4, note_Db4, note_E4}; 

typedef struct Move{
  Color color;
  struct Move * next;
} Move ;

void setupBoard() {
  for (int i = 0; i < 4; i++) {
    pinMode(colorPin[colors[i]], OUTPUT);
    digitalWrite(colorPin[colors[i]], LOW);
  }
  /*
  showColor(Green);
  showColor(Red);
  showColor(Yellow);
  showColor(Blue);
  */
}

void showColor(int color) {
  delay(200);
  toneAC(colorSound[color]);
  digitalWrite(colorPin[color], HIGH);
  delay(400);
  toneAC(0);
  digitalWrite(colorPin[color], LOW);
}

void showColorWhileButton(int color){

}

void showWrongColor(int color){
  delay(200);
  toneAC(note_C3);
  digitalWrite(colorPin[color], HIGH);
  delay(1500);
  toneAC(0);
  digitalWrite(colorPin[color], LOW);
  delay(1500);
}

