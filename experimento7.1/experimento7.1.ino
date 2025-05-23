#include <OneWire.h>
#include <DallasTemperature.h>

#define DADOS 2
#define LED_ALARME 12
#define TEMPERATURA_ALARME 30  // Temperatura do alarme em graus Celsius

// Pinos do display de 7 segmentos
int ledA = 22;
int ledB = 24;
int ledC = 26;
int ledD = 28;
int ledE = 30;
int ledF = 32;
int ledG = 34;
int jumper1 = 40;  // Display da dezena
int jumper2 = 42;  // Display da unidade

// Variáveis do display
int unidade, dezena, valor;
volatile byte pot_ts = 0;

OneWire oneWire(DADOS);
DallasTemperature sensors(&oneWire);

// Tabela de segmentos para os números 0-9
byte segmentos[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

void setup() {
  pinMode(LED_ALARME, OUTPUT);

  sensors.begin();

  // Segmentos
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(jumper1, OUTPUT);
  pinMode(jumper2, OUTPUT);

  // Timer para multiplexação
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << CS10);  // sem prescaler
  TCNT1 = 0xC180;         // preload para ~2ms
  TIMSK1 |= (1 << TOIE1);

  Serial.begin(9600);
}

void loop() {

  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  valor = constrain(int(temp), 0, 99);  //entre 0 e 99

  dezena = valor / 10;
  unidade = valor % 10;

  Serial.print("Temperatura: ");
  Serial.println(temp);

  if (valor >= TEMPERATURA_ALARME) {
    digitalWrite(LED_ALARME, HIGH);
  } else {
    digitalWrite(LED_ALARME, LOW);
  }

}

// Interrupção do TIMER1 para multiplexar os displays
ISR(TIMER1_OVF_vect) {
  TCNT1 = 0xC180;  // Reinicia TIMER para intervalo de ~2ms
  pot_ts++;

  if (pot_ts % 2 == 0) {
    // Mostra dezena
    digitalWrite(jumper1, HIGH);
    digitalWrite(jumper2, LOW);
    mostrarNumero(dezena);
  } else {
    // Mostra unidade
    digitalWrite(jumper1, LOW);
    digitalWrite(jumper2, HIGH);
    mostrarNumero(unidade);
  }
}

// Mostra um dígito no display
void mostrarNumero(int numero) {
  digitalWrite(ledA, segmentos[numero][0]);
  digitalWrite(ledB, segmentos[numero][1]);
  digitalWrite(ledC, segmentos[numero][2]);
  digitalWrite(ledD, segmentos[numero][3]);
  digitalWrite(ledE, segmentos[numero][4]);
  digitalWrite(ledF, segmentos[numero][5]);
  digitalWrite(ledG, segmentos[numero][6]);
}
