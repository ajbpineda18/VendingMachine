float readTemp(){
  int speed = fanControl(dht.readTemperature());
  for (int i = 0; i < 4; i++) {
      analogWrite(externalFans[i].pwmPin, speed);
  }
  return dht.readTemperature();
}

int readHumid() {
  readHumiditySensor(int(dht.readHumidity()));
  return dht.readHumidity();
}

void readWaterSensor(){
  //Greater than 0 water detected
  if(analogRead(waterlevel) > 0){
    //Water Led on
    digitalWrite(waterLed, HIGH);
    //Buzzer On
    tone(buzzer1, 1000);
  } else {
    //Else <= 0 water led off
    digitalWrite(waterLed, LOW);
    //Buzzer off
    noTone(buzzer1);
  }
}

void readHumiditySensor(int humids){
  if(humids >= 30 && humids <= 60){
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