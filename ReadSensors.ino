float readTemp(){
  int speed = fanControl(dht.readTemperature());
  Serial.println((String)"Temp: "+dht.readTemperature());
  for (int i = 0; i < 4; i++) {
      analogWrite(externalFans[i].pwmPin, speed);
  }
  return dht.readTemperature();
}

int readHumid() {
  Serial.println((String)"Humid: "+dht.readHumidity());
  readHumiditySensor(int(dht.readHumidity()));
  return dht.readHumidity();
}

void readWaterSensor(){
  if(map(analogRead(waterlevel), 0, 1008, 0, 100) >= 95){
    digitalWrite(waterLed, HIGH);
    
  } else  {
    digitalWrite(waterLed, LOW);
  }
}

void readHumiditySensor(int humids){
  if(humids >= 30 && humids <= 60){
    digitalWrite(relays, HIGH);
    Serial.println(digitalRead(relays));
  } else  {
    digitalWrite(relays, LOW);
    Serial.println(digitalRead(relays));

  }
}

int fanControl(float temp){
  if (temp >= 40) {
    return 255;
  } else if (temp >= 30) {
    return 126;
  } else if (temp < 30) {
    return 0;
  }
}