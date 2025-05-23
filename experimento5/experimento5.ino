const byte ledPin = 13;
const byte interruptPin = 2;
volatile byte state = LOW;
unsigned long tempo;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {
  
  digitalWrite(ledPin, state);
}

void blink() {
  if ((millis()-tempo) > 50 ) {
    state = !state;
    tempo = millis();
  }
}
