int A=0;
int B=0;
int C=0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(2000000);
}

void loop() {

  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.print("A:");
  Serial.print(A);
  Serial.print("; B:");
  Serial.print(B);
  Serial.print("; C:");
  Serial.println(C);
  A += 1;
  B += 2;
  C -= 1;
}
