void setup() {
  DDRB = DDRB |B10000000;  // sets Arduino pins 1 to 7 as outputs, pin 0 as input
  //DDRB = DDRB | B01111111;  // this is safer as it sets pins 2 to 7 as outputs
  // without changing the value of pins 0 & 1, which are RX & TX
  //DDRE |= B11111100;
}
void loop() {
  PORTB |= B10000000;  // Pin D2 to HIGH
  delay(50);
  PORTB &= B01111111;  // Pin D2 to LOW
  delay(50);
}