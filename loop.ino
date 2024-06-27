void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(button1, LOW);
  pisoChecker();

  if(digitalRead(button1) == HIGH){
    for(int i = 0; i<5; i++){
      digitalWrite(leds[i], LOW);
      product[i].ProductQuantity = 5;
    }
  }

  //The program will only go here if the currentState is 0
  //Showing all roducts and a way to go to database
  if(currentState == 0){
    char idle_key = keypad.getKey();
    //Idle Key Reciever
    if (idle_key){
      if(idle_key >= '1' && idle_key <= '5'){
        prodKey = idle_key - '1';
        Serial.print(prodKey);
        checkProdAvailability();
      } else if(idle_key == '#'){
        currentState = 2;
      }
      idle_key = NULL;
    }
    //Total Peso Reset and Available Products 
    unsigned long currentidleMillis = millis();
    if(currentidleMillis - idle_millis >= 5000){
      idle_millis = currentidleMillis;
      availableProducts();
    }
    TotalPeso = 0;
  }

  //The program will only go here if the currentState is 1
  //Product and payment show
  else if(currentState == 1){
    char picked_key = keypad.getKey();
    if (picked_key){
      if (picked_key == 'D'){
          checkPaid();
      } else if (picked_key == 'C') {
          prodKey = -1;
          afterOrder();
      }
    }
    unsigned long currentSelectedMillis = millis(); 
    pickedProdsDetails(currentSelectedMillis);
    if(currentSelectedMillis - selected_millis >= 60000){
      selected_millis = currentSelectedMillis;
      if(restartPicking == TotalPeso){
        prodKey = -1;
        afterOrder();
      } else{
        restartPicking = TotalPeso;
      }
    }
  }

  //The program will only go here if the currentState is 2
  //Database part of the code
  else if(currentState == 2){
    char pass_key = keypad.getKey();
    if(pass_key){
      Serial.println(pass_key);
      if(login == false){
        passwordChecker(pass_key);
      }
      if(login == true){
        if(pass_key >= '0' && pass_key <= '9'){
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Admin Mode: ON");
          CheckTotalDespense(pass_key);
          ResetDispense(pass_key);
        }
        if(pass_key == 'D'){
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Admin Mode: OFF");
          login = false;
          currentState = 0;
          delay(500);
        }
      }
    }
  }
}

