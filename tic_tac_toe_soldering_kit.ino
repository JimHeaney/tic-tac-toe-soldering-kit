//Tic Tac Toe Soldering Kit
//By: Jim Heaney
//www.jim-heaney.com
//CC-BY-SA-NC 4.0

const int C1 = A0;
const int C2 = A1;
const int C3 = A2;
const int R1X = A3;
const int R1O = A4;
const int R2X = A5;
const int R2O = 2;
const int R3X = 3;
const int R3O = 4;
const int C1B = 5;
const int C2B = 6;
const int C3B = 7;
const int R1B = 8;
const int R2B = 9;
const int R3B = 10;

int turn = 1;

int state[9] = {1,2,1,2,1,2,1,2,1};

int i;

long startuptime = 0;

int startuplevel = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(R1X, OUTPUT);
  pinMode(R1O, OUTPUT);
  pinMode(R2X, OUTPUT);
  pinMode(R2O, OUTPUT);
  pinMode(R3X, OUTPUT);
  pinMode(R3O, OUTPUT);
  pinMode(C1B, OUTPUT);
  pinMode(C2B, OUTPUT);
  pinMode(C3B, OUTPUT);

  pinMode(R1B, INPUT);
  pinMode(R2B, INPUT);
  pinMode(R3B, INPUT);

  startuptime = millis() + 1000;

}

void loop() {
  // put your main code here, to run repeatedly:

  //Startup lights
  if ((millis() >= startuptime) && startuplevel == 0){
    for (i = 0; i <=9; i++){
      if (state[i] == 1){
        state[i] = 2;
      }
      else{
        state[i] = 1;
      }
      startuplevel = 1;
      startuptime = millis() + 1000;
    }
  }
   if ((millis() >= startuptime) && startuplevel == 1){
    for (i = 0; i <=9; i++){
      state[i] = 0;
      startuplevel = 2;
      startuptime = millis() + 1000;
    }
  }
    

  //Check for button presses. If there is a press on an unoccupied space, set the space color and change turns.
  digitalWrite(C1B, HIGH);
  if((digitalRead(R1B) == 1) && (state[0] == 0)){
    state[0] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  if((digitalRead(R2B) == 1) && (state[3] == 0)){
    state[3] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  if((digitalRead(R3B) == 1) && (state[6] == 0)){
    state[6] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  digitalWrite(C1B, LOW);
  digitalWrite(C2B, HIGH);
  if((digitalRead(R1B) == 1) && (state[1] == 0)){
    state[1] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  if((digitalRead(R2B) == 1) && (state[4] == 0)){
    state[4] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  if((digitalRead(R3B) == 1) && (state[7] == 0)){
    state[7] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  digitalWrite(C2B, LOW);
  digitalWrite(C3B, HIGH);
  if((digitalRead(R1B) == 1) && (state[2] == 0)){
    state[2] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  if((digitalRead(R2B) == 1) && (state[5] == 0)){
    state[5] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  if((digitalRead(R3B) == 1) && (state[8] == 0)){
    state[8] = turn;
    if (turn == 1){
      turn = 2;
    }
    else{
      turn = 1;
    }
  }
  digitalWrite(C3B, LOW);

  //Project the current states onto the LEDs. X = 1, O = 2.
  digitalWrite(C1, HIGH);
  if (state[0] == 0){
  }
  if (state[0] == 1){
    digitalWrite(R1X, LOW);
  }
  if(state[0] == 2){
    digitalWrite(R1O, LOW);
  }
  digitalWrite(R1X, HIGH);
  digitalWrite(R1O, HIGH);
  digitalWrite(C1, LOW);
  digitalWrite(C2, HIGH);
  if (state[1] == 0){
  }
  if (state[1] == 1){
    digitalWrite(R1X, LOW);
  }
  if(state[1] == 2){
    digitalWrite(R1O, LOW);
  }
  digitalWrite(R1X, HIGH);
  digitalWrite(R1O, HIGH);
  digitalWrite(C2, LOW);
  digitalWrite(C3, HIGH);
    if (state[2] == 0){
  }
  if (state[2] == 1){
    digitalWrite(R1X, LOW);
  }
  if(state[2] == 2){
    digitalWrite(R1O, LOW);
  }
  digitalWrite(R1X, HIGH);
  digitalWrite(R1O, HIGH);
  digitalWrite(C3, LOW);

  digitalWrite(C1, HIGH);
  if (state[3] == 0){
  }
  if (state[3] == 1){
    digitalWrite(R2X, LOW);
  }
  if(state[3] == 2){
    digitalWrite(R2O, LOW);
  }
  digitalWrite(R2X, HIGH);
  digitalWrite(R2O, HIGH);
  digitalWrite(C1, LOW);
  digitalWrite(C2, HIGH);
  if (state[4] == 0){
  }
  if (state[4] == 1){
    digitalWrite(R2X, LOW);
  }
  if(state[4] == 2){
    digitalWrite(R2O, LOW);
  }
  digitalWrite(R2X, HIGH);
  digitalWrite(R2O, HIGH);
  digitalWrite(C2, LOW);
  digitalWrite(C3, HIGH);
    if (state[5] == 0){
  }
  if (state[5] == 1){
    digitalWrite(R2X, LOW);
  }
  if(state[5] == 2){
    digitalWrite(R2O, LOW);
  }
  digitalWrite(R2X, HIGH);
  digitalWrite(R2O, HIGH);
  digitalWrite(C3, LOW);

  digitalWrite(C1, HIGH);
  if (state[6] == 0){
  }
  if (state[6] == 1){
    digitalWrite(R3X, LOW);
  }
  if(state[6] == 2){
    digitalWrite(R3O, LOW);
  }
  digitalWrite(R3X, HIGH);
  digitalWrite(R3O, HIGH);
  digitalWrite(C1, LOW);
  digitalWrite(C2, HIGH);
  if (state[7] == 0){
  }
  if (state[7] == 1){
    digitalWrite(R3X, LOW);
  }
  if(state[7] == 2){
    digitalWrite(R3O, LOW);
  }
  digitalWrite(R3X, HIGH);
  digitalWrite(R3O, HIGH);
  digitalWrite(C2, LOW);
  digitalWrite(C3, HIGH);
    if (state[8] == 0){
  }
  if (state[8] == 1){
    digitalWrite(R3X, LOW);
  }
  if(state[8] == 2){
    digitalWrite(R3O, LOW);
  }
  digitalWrite(R3X, HIGH);
  digitalWrite(R3O, HIGH);
  digitalWrite(C3, LOW);
}
