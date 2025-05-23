#define ledPin 13
#define ledPin2 12
int analogPin = A1;
int count, led_pisca, val, pot_ts;


void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(2000000);
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS10);
  TCNT1 = 0xC180;
  TIMSK1 |= (1 << TOIE1);  // habilita a interrupção do TIMER1
}

void loop() {
  if (count) {
    count = 0;
    led_pisca++;
    if (led_pisca > 600) {
      led_pisca = 0;
    }
    if (led_pisca < 300) {
      analogWrite(ledPin, map(led_pisca, 0, 300, 0, 255));
    } else {
      analogWrite(ledPin, map(led_pisca, 300, 600, 255, 0));
    }
  }

  if(pot_ts>10){
    pot_ts=0;
    val = analogRead(analogPin);
    Serial.println(val);
    analogWrite(ledPin2, map(val, 0, 1023, 0, 255));
  }
}

ISR(TIMER1_OVF_vect)  //interrupção do TIMER1
{
  TCNT1 = 0xC180;  // Renicia TIMER
  count++;
  pot_ts++;
}
