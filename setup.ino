void setup() {
  Serial.begin(9600);
  productDetails();
  pinMode(counterPin, OUTPUT);
  pinMode(coinPin, OUTPUT);
  lcd.init();
  lcd.backlight();
  for (int i = 0; i < 4; i++) {
        pinMode(externalFans[i].pwmPin, OUTPUT);
        pinMode(externalFans[i].signalPin, OUTPUT);
  }
  pinMode(relays, OUTPUT);
  pinMode(waterLed, OUTPUT);
  digitalWrite(relays, LOW);
  for (int i = 0; i < 5; i++) {
      pinMode(leds[i], OUTPUT);
  }
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(waterlevel, OUTPUT);
  pinMode(button1, INPUT);
  dht.begin();
  Serial.println("Ready up!");
}