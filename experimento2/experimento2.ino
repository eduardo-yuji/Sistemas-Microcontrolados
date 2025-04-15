/*int ledPin = 13;  // LED connected to digital pin 13
int inPin = 7;    // pushbutton connected to digital pin 7
int val = 0;      // variable to store the read value

void setup() {
  pinMode(ledPin, OUTPUT);       // sets the digital pin 13 as output
  pinMode(inPin, INPUT_PULLUP);  // sets the digital pin 7 as input
}

void loop() {
  //val = digitalRead(inPin);   // read the input pin
  if (!digitalRead(inPin)) {
    delay(200);
    val = !val;
  };

  digitalWrite(ledPin, val);  // sets the LED to the button's value
}

*/

// potentiometer wiper (middle terminal) 
// connected to analog pin 3
int analogPin = A3;

// outside leads to ground and +5V
int val = 0;  
// variable to store the value read

void setup() {
  Serial.begin(9600);    //setup serial
}

void loop() {
// read the input pin
val = analogRead(analogPin); 
	Serial.println(val);      // debug value
  delay(333);
}
