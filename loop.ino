void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(button1, LOW);
  digitalWrite(counterPin, HIGH);
  insertCoin();

  char key = keypad.getKey();
  if(currentState == 0){
    if (key){
      if((key >= '6' && key <= '9') ||  key == 'B'){
        CheckTotalDespense(key);
      }
      if(key >= '1' && key <= '5'){
        pickprods(key);
      }
    }
    unsigned long currentidleMillis = millis(); 
    if(currentidleMillis - idle_millis >= 5000){
      idle_millis = currentidleMillis;
      availableProducts();
    }
    if(digitalRead(button1) == HIGH){
      for(int i = 0; i<5; i++){
        digitalWrite(leds[i], LOW);
        product[i].ProductQuantity = 5;
      }
    }
  }
  else if(currentState == 1){
    if (key) {
      if (key == 'D') {
          currentState = 2;
      } else if (key == 'C') {
          afterOrder();
      }
    }

    unsigned long currentSelectedMillis = millis(); 
    
    if(currentSelectedMillis - selected_millis >= 1000){
      selected_millis = currentSelectedMillis;
      Serial.println("Print Details");
      pickedProdsDetails();
    }

    if(currentSelectedMillis - selected_millis >= 60000){
      selected_millis = currentSelectedMillis;
      if(restartPicking == TotalPeso){
        afterOrder();
      } else{
        restartPicking = TotalPeso;
      }
    }
    if(digitalRead(button1) == HIGH){
      for(int i = 0; i<5; i++){
        digitalWrite(leds[i], LOW);
        product[i].ProductQuantity = 5;
      }
    }
  }
  else if(currentState == 2){
    if(key){
      if(key == 'D'){
        checkPaid(2000);
      }
    }
  }
}
