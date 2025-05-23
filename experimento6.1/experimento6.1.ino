#define ledPin 13
int count, led_pisca;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
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
}

ISR(TIMER1_OVF_vect)  //interrupção do TIMER1
{
  TCNT1 = 0xC180;  // Renicia TIMER
  count++;
}
