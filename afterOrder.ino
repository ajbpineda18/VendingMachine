void afterOrder(){
  if(currentState == 2){
    checkQuantity();
  }
  prodKey = -1;
  TotalPeso = 0;
  currentState = 0;
}

void pisoChecker(){
  if(checkStartPeso == 0){
    if(TotalPeso == 1){
      TotalPeso = 0;
    }
    Serial.println(TotalPeso);
    checkStartPeso++;
  }
}

void checkQuantity() {
  product[prodKey].ProductQuantity--;
  for (int j = 0; j < 5; j++) {
      if (product[j].ProductQuantity <= 2) {
          digitalWrite(leds[j], HIGH);
          tone(buzzer2, 1000, 3000);
      }
  }
}