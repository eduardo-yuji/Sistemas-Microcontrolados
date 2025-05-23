
int led = 13;
int count = 0;
int flag = 1;
int i = 0;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  count++;
  if (count > 3) {
    count = 0;
    if (flag == 1) {
      i++;
      if (i >= 10) {
        flag = 0;
      }
    } else {
      i--;
      if (i <= 0) {
        flag = 1;
      }
    }
  }
  digitalWrite(led, HIGH);
  delay(i);
  digitalWrite(led, LOW);
  delay(10 - i);
}