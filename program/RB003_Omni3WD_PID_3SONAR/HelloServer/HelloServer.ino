void setup(void) {
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(1, 0);
  digitalWrite(2, 0);
  digitalWrite(3, 0);
  digitalWrite(4, 0);


}


void loop(void) {
  int command = 1;

  switch (command){
  case 1: // Advance
    digitalWrite(1, 1);
    digitalWrite(2, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    break;
  case 2: // Backoff
    digitalWrite(1, 0);
    digitalWrite(2, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    break;
  case 3: // Left
    digitalWrite(1, 1);
    digitalWrite(2, 1);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    break;
  case 4: // Right
    digitalWrite(1, 0);
    digitalWrite(2, 0);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    break;
  case 5: // UpperLeft
    digitalWrite(1, 1);
    digitalWrite(2, 0);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    break;
  case 6: // LowerRight
    digitalWrite(1, 0);
    digitalWrite(2, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    break;
  case 7: // LowerLeft
    digitalWrite(1, 1);
    digitalWrite(2, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 0);
    break;
  case 8: // UpperRight
    digitalWrite(1, 0);
    digitalWrite(2, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    break;
  case 9: // RotateLeft
    digitalWrite(1, 1);
    digitalWrite(2, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 1);
    break;
  case 10: // RotateRight
    digitalWrite(1, 1);
    digitalWrite(2, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);
    break;
  default:
    digitalWrite(1, 0);
    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    break;
}
command++;
}
