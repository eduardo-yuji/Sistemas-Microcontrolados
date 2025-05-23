#define ledPin 13
#define ledPin2 44
int analogPin = A1;
int ledA = 22;
int ledB = 24;
int ledC = 26;
int ledD = 28;
int ledE = 30;
int ledF = 32;
int ledG = 34;
int jumper1 = 40;
int jumper2 = 42;
int count, led_pisca, val, pot_ts, dezena, unidade, valor, comunicacao_ts, relogio_ts, horas, minutos, segundos;

byte segmentos[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  //DIGITO 0
  { 0, 1, 1, 0, 0, 0, 0 },  //DIGITO 1
  { 1, 1, 0, 1, 1, 0, 1 },  //DIGITO 2
  { 1, 1, 1, 1, 0, 0, 1 },  //DIGITO 3
  { 0, 1, 1, 0, 0, 1, 1 },  //DIGITO 4
  { 1, 0, 1, 1, 0, 1, 1 },  //DIGITO 5
  { 1, 0, 1, 1, 1, 1, 1 },  //DIGITO 6
  { 1, 1, 1, 0, 0, 0, 0 },  //DIGITO 7
  { 1, 1, 1, 1, 1, 1, 1 },  //DIGITO 8
  { 1, 1, 1, 1, 0, 1, 1 }   //DIGITO 9
};

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(jumper1, OUTPUT);
  pinMode(jumper2, OUTPUT);
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

  if (pot_ts > 10) {
    pot_ts = 0;
    val = analogRead(analogPin);
    valor = map(analogRead(analogPin), 0, 1023, 0, 99);
    dezena = valor / 10;
    unidade = valor % 10;
  }
  if (pot_ts > 0 && pot_ts <= 5) {
    digitalWrite(ledA, segmentos[dezena][0]);
    digitalWrite(ledB, segmentos[dezena][1]);
    digitalWrite(ledC, segmentos[dezena][2]);
    digitalWrite(ledD, segmentos[dezena][3]);
    digitalWrite(ledE, segmentos[dezena][4]);
    digitalWrite(ledF, segmentos[dezena][5]);
    digitalWrite(ledG, segmentos[dezena][6]);
    digitalWrite(jumper1, HIGH);
    digitalWrite(jumper2, LOW);
  } else {
    digitalWrite(ledA, segmentos[unidade][0]);
    digitalWrite(ledB, segmentos[unidade][1]);
    digitalWrite(ledC, segmentos[unidade][2]);
    digitalWrite(ledD, segmentos[unidade][3]);
    digitalWrite(ledE, segmentos[unidade][4]);
    digitalWrite(ledF, segmentos[unidade][5]);
    digitalWrite(ledG, segmentos[unidade][6]);
    digitalWrite(jumper1, LOW);
    digitalWrite(jumper2, HIGH);
  }
  analogWrite(ledPin2, map(analogRead(analogPin), 0, 1023, 0, 255));

  if(relogio_ts> 1000){
    relogio_ts = 0;
    segundos++;
    if (segundos >59){
      segundos = 0;
      minutos++;
      if(minutos > 59){
        minutos = 0;
        horas++;
      }
    }
  }
  if(comunicacao_ts > 100){
    comunicacao_ts=0;
    Serial.print("Potenciometro:");
    Serial.println(val);
    Serial.print("Horas:");
    Serial.println(horas);
    Serial.print("Minutos:");
    Serial.println(minutos);
    Serial.print("Segundos:");
    Serial.println(segundos);
    /*
    Serial.print("Tempo:");
    Serial.print(horas);
    Serial.print(":");
    Serial.print(minutos);
    Serial.print(":");
    Serial.println(segundos);
    */
  }
}

ISR(TIMER1_OVF_vect)  //interrupção do TIMER1
{
  TCNT1 = 0xC180;  // Renicia TIMER
  count++;
  pot_ts++;
  relogio_ts++;
  comunicacao_ts++;
}
