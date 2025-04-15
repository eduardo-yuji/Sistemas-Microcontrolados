int ledA = 22;
int ledB = 24;
int ledC = 26;
int ledD = 28;
int ledE = 30;
int ledF = 32;
int ledG = 34;
int jumper1 = 40;
int jumper2 = 42;
int contador, valor, dezena, unidade;
int analogPin = A1;

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
  Serial.begin(9600);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(jumper1, OUTPUT);
  pinMode(jumper2, OUTPUT);
}

void loop() {
  valor = map(analogRead(analogPin), 0, 1023, 0, 99);
  Serial.println(valor);

  //contador++;
  //if (contador > 50) {
    //contador = 0;
    //valor++;
    dezena = valor / 10;
    unidade = valor % 10;
    //if (valor > 99) {
      //valor = 0;
    //}
  //}

  digitalWrite(ledA, segmentos[dezena][0]);
  digitalWrite(ledB, segmentos[dezena][1]);
  digitalWrite(ledC, segmentos[dezena][2]);
  digitalWrite(ledD, segmentos[dezena][3]);
  digitalWrite(ledE, segmentos[dezena][4]);
  digitalWrite(ledF, segmentos[dezena][5]);
  digitalWrite(ledG, segmentos[dezena][6]);
  digitalWrite(jumper1, HIGH);
  digitalWrite(jumper2, LOW);
  delay(5);
  digitalWrite(ledA, segmentos[unidade][0]);
  digitalWrite(ledB, segmentos[unidade][1]);
  digitalWrite(ledC, segmentos[unidade][2]);
  digitalWrite(ledD, segmentos[unidade][3]);
  digitalWrite(ledE, segmentos[unidade][4]);
  digitalWrite(ledF, segmentos[unidade][5]);
  digitalWrite(ledG, segmentos[unidade][6]);
  digitalWrite(jumper1, LOW);
  digitalWrite(jumper2, HIGH);
  delay(5);
}
