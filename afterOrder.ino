void afterOrder(){
  checkQuantity();
  prodKey = -1;
  TotalPeso = 0;
  currentState = 0;
  showOnce = -1;
  showPeso = -1;
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
  if(prodKey != -1){
    product[prodKey].ProductQuantity--;
  }
  for (int j = 0; j < 5; j++) {
      if (product[j].ProductQuantity <= 2) {
          digitalWrite(leds[j], HIGH);
          tone(buzzer2, 1000, 3000);
      }
  }
}