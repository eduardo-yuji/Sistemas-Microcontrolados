#define ledPin 13
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  // Configuração do timer1
  TCCR1A = 0;  //confira timer para operação
               //normal pinos OC1A e OC1B desconectados
  TCCR1B = 0;  //limpa registrador
               // configura prescaler para 1:  CS10 = 1
  TCCR1B |= (1 << CS12);
  // incia timer com valor para que estouro ocorra em 1 segundo
  // 65536-(16MHz/256/1000) = 3036 = 0x0BDC
  TCNT1 = 0x0BDC;
  TIMSK1 |= (1 << TOIE1);  // habilita a interrupção do TIMER1
}
int count;
void loop() {
  /*
  if (count) {
    count = 0;
    Serial.println(millis());
    digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
    //inverte estado do led
    //a manipulação do led é feita na ISR
  }
  */
}

ISR(TIMER1_OVF_vect)  //interrupção do TIMER1
{
  TCNT1 = 0x0BDC;  // Renicia TIMER
  //count++;
  
  //Serial.println(millis());
  //digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
}
