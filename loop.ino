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
    unsigned long currentidleMillis = millis();
    char idle_key = keypad.getKey();
    //Idle Key Reciever
    if (idle_key){
      if(idle_key >= '1' && idle_key <= '5'){
        prodKey = idle_key - '1';
        checkProdAvailability();
      } else if(idle_key == '#'){
        currentState = 2;
      }
      idle_key = NULL;
    }
    //Total Peso Reset and Available Products 
    if(currentidleMillis - idle_millis >= 3000){
      idle_millis = currentidleMillis;
      availableProducts();
    }
    TotalPeso = 0;
  }

  //The program will only go here if the currentState is 1
  //Product and payment show
  else if(currentState == 1){
    unsigned long currentSelectedMillis = millis(); 
    char picked_key = keypad.getKey();
    if (picked_key){
      if (picked_key == 'D'){
          checkPaid();
      } else if (picked_key == 'C') {
          prodKey = -1;
          afterOrder();
      }
    }
    Serial.println(reset_millis);
    if(currentSelectedMillis - reset_millis >= 30000){
      reset_millis = currentSelectedMillis;
      Serial.println("I'm Here reset");
      if(restartPicking == TotalPeso){
        Serial.println("Restart!");
        prodKey = -1;
        afterOrder();
      } else{
        Serial.println("Restart == TOTAL PESO");
        restartPicking = TotalPeso;
      }
    }

    pickedProdsDetails(currentSelectedMillis);
    
  }
  //The program will only go here if the currentState is 2
  //Database part of the code
  else if(currentState == 2){
    char pass_key = keypad.getKey();
    if(deleteKey != -1){
      if(pass_key){
        ResetDispense(pass_key);
      }
    }
    else{
      if(pass_key){
        if(login == false){
          passwordChecker(pass_key);
        }
        if(login == true){
          lcd.clear();
          lcd.setCursor(3,0);
          lcd.print("Admin Mode: ON");
          lcd.setCursor(3,2);
          lcd.print("D - Log Out");
          if(pass_key >= '1' && pass_key <= '5'){
            CheckTotalDespense(pass_key);
          }
          if(pass_key == 'D'){
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("Admin Mode: OFF");
            login = false;
            deleteKey = -1;
            currentState = 0;
            delay(500);
          }
        }
      }
    }
  }
}

