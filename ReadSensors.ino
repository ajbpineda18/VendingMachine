float readTemp(){
  int speed = fanControl(dht.readTemperature());
  for (int i = 0; i < 4; i++) {
      analogWrite(externalFans[i].pwmPin, speed);
  }
  return dht.readTemperature();
}

int readHumid() {
  return dht.readHumidity();
}

void readWaterSensor(){
  if(map(analogRead(waterlevel), 0, 1008, 0, 100) >= 95){
    digitalWrite(relays, HIGH);
  } else  {
    digitalWrite(relays, LOW);
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