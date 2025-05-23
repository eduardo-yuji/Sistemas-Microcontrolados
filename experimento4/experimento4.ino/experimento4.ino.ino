int flag = 1;
int lum, i;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {

    if (flag == 1) {
      i++;
      if (i >= 300) {
        flag = 0;
      }
    } else {
      i--;
      if (i <= 0) {
        flag = 1;
      }
    }
  lum = map(i, 0, 300, 0, 255);
  analogWrite(13, lum);
  delay(1);
}