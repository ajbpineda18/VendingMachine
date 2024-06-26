void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(button1, LOW);
  pisoChecker();
  if(currentState == 0){
    char idle_key = keypad.getKey();
    if (idle_key){
      if(idle_key >= '1' && idle_key <= '5'){
        pickprods(idle_key);
      } else if(idle_key == '#'){
        currentState = 3;
      }
    }
    unsigned long currentidleMillis = millis();
    if(currentidleMillis - idle_millis >= 5000){
      idle_millis = currentidleMillis;
      availableProducts();
      TotalPeso = 0;
      Serial.print("Total Peso: ");
      Serial.println(TotalPeso);
    }
    if(digitalRead(button1) == HIGH){
      for(int i = 0; i<5; i++){
        digitalWrite(leds[i], LOW);
        product[i].ProductQuantity = 5;
      }
    }
  }
  else if(currentState == 1){
    char picked_key = keypad.getKey();
    if (picked_key){
      if (picked_key == 'D'){
          currentState = 2;
      } else if (picked_key == 'C') {
          afterOrder();
      }
    }
    unsigned long currentSelectedMillis = millis(); 
    pickedProdsDetails(currentSelectedMillis);
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
    checkPaid(2000);
  }
  else if(currentState == 3){
    char pass_key = keypad.getKey();
    if(pass_key){
      Serial.println(pass_key);
      // if(pass_key == 'A'){
      //   resetPass = true;
      // }
      // if(resetPass == true && password != "") {
      //   passwordReset(pass_key);
      // }
      // if(login == false && password == ""){
      //   passwordSetters(pass_key);
      // }
      if(login == false && password != ""){
        passwordChecker(pass_key);
      }
      if(login == true){
        if(pass_key >= '1' && pass_key <= '5'){
          Serial.println("Wait..");
          CheckTotalDespense(pass_key);
        }
        if(pass_key == 'D'){
          login = false;
          currentState = 0;
        }
      }
    }
  }
}

