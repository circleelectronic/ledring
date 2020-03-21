//gecikme var led yansa bile saymıyo
int leds[] = {14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, A5, A4, A3, A2, A1, A0, 2};
int buton = A6;
int butonstate;
int butoninit = 0;
static int i = 0;
static int tourtime = 120; 
static int lednumber = 18; 
static int lednumber1 = 19;
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
  ledaction();
}

void ledaction() {
  static unsigned long time = millis();
  if (millis() - time >= tourtime) {
    time = millis();
    i++;
    digitalWrite(leds[i], HIGH);
    delay(15);
    digitalWrite(leds[i], LOW);
    if (i == lednumber1) {
      ledsoff();
      tourtime = 120; 
      lednumber = 18; 
      lednumber1 = 19;
      butoninit = 0;
      i = 0;
    }
    if (butoninit == 1 && i == lednumber) {
      digitalWrite(leds[lednumber], HIGH);
      tourtime - 20;
      lednumber--;
      lednumber1--;
      butoninit = 0;
      i = 0;
      delay(150);
    }
    if (butoninit == 1 && i != lednumber) {
      ledsoff();
      tourtime = 120; 
      lednumber = 18; 
      lednumber1 = 19;
      butoninit = 0;
      i = 0;
    }
  }
}
void ledsoff() {
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  digitalWrite(leds[4], LOW);
  digitalWrite(leds[5], LOW);
  digitalWrite(leds[6], LOW);
  digitalWrite(leds[7], LOW);
  digitalWrite(leds[8], LOW);
  digitalWrite(leds[9], LOW);
  digitalWrite(leds[10], LOW);
  digitalWrite(leds[11], LOW);
  digitalWrite(leds[12], LOW);
  digitalWrite(leds[13], LOW);
  digitalWrite(leds[14], LOW);
  digitalWrite(leds[15], LOW);
  digitalWrite(leds[16], LOW);
  digitalWrite(leds[17], LOW);
  digitalWrite(leds[18], LOW);
  digitalWrite(leds[19], LOW);
  digitalWrite(leds[20], LOW);
}
