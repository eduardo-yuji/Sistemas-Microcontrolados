int LED1 = 11;
int LED2 = 12;
int LED3 = 13;
unsigned long tempo1, tempo2, tempo3;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  tempo1 = (millis() % 600);
  tempo2 = ((millis() - 200) % 600);
  tempo3 = ((millis() - 4 00) % 600);
  controleLED1();
  controleLED2();
  controleLED3();
}

void controleLED1() {
  if (tempo1 < 300) {
    analogWrite(LED1, map(tempo1, 0, 300, 0, 255));
  } else {
    analogWrite(LED1, map(tempo1, 300, 600, 255, 0));
  }
}

void controleLED2() {
  if (tempo2 < 300) {
    analogWrite(LED2, map(tempo2, 0, 300, 0, 255));
  } else {
    analogWrite(LED2, map(tempo2, 300, 600, 255, 0));
  }
}

void controleLED3() {
  if (tempo3 < 300) {
    analogWrite(LED3, map(tempo3, 0, 300, 0, 255));
  } else {
    analogWrite(LED3, map(tempo3, 300, 600, 255, 0));
  }
}
