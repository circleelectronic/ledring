int leds[] = {14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, A5, A4, A3, A2, A1, A0, 2};
int buton = A6;
int butonstate;
int butoninit = 0;
static int i = 0;
int num_pins = 20;

void setup()
{
  pinMode(buton, INPUT);
  for (int z = 0; z < 20; z++) {
    pinMode(leds[z], OUTPUT);
  }
  digitalWrite(0, LOW);
}
void loop()
{
  butonstate = analogRead(buton);
  if (butonstate == 0) {
    butoninit = 1;
  }
  if (butonstate == 1) {
    butoninit = 0;
  }
  if (butoninit == 1 && i == 19) {
    digitalWrite(leds[19], HIGH);
    delay(200);
    digitalWrite(leds[19], LOW);
    delay(200);
    digitalWrite(leds[19], HIGH);
    delay(200);
    digitalWrite(leds[19], LOW);
    delay(200);
    digitalWrite(leds[19], HIGH);
    delay(200);
    digitalWrite(leds[19], LOW);
    delay(200);
    digitalWrite(leds[19], HIGH);
    delay(200);
    digitalWrite(leds[19], LOW);
    delay(200);
    digitalWrite(leds[19], HIGH);
    delay(200);
    digitalWrite(leds[19], LOW);
    delay(200);
    butoninit = 0;
    i = 0;
  }
  if (butoninit == 1 && i != 19) {
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
    delay(300);
    digitalWrite(leds[i], HIGH);
    delay(300);
    digitalWrite(leds[i], LOW);
    butoninit = 0;
    i = 0;
  }
  ledaction();
}

void ledaction() {
  static unsigned long time = millis();
  if (millis() - time >= 80) //80 easy 40 normal 10 hard
    {
    time = millis();
    i++;
    digitalWrite(leds[i], HIGH);
    delay(15);
    if (i == 20) {
      i = 0;
    }
    digitalWrite(leds[i], LOW);
  }
}
