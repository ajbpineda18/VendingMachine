void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(button1, LOW);
  pisoChecker();
  char key = keypad.getKey();

  if(currentState == 0){
    if (key){
      if(key >= '1' && key <= '5'){
        pickprods(key);
      } else if(key == '*'){
        currentState = 3;
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
    if (key){
      if (key == 'D'){
          currentState = 2;
      } else if (key == 'C') {
          afterOrder();
      }
    }
    unsigned long currentSelectedMillis = millis(); 
    if(currentSelectedMillis - selected_millis >= 1500){
      selected_millis = currentSelectedMillis;
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
    checkPaid(2000);
  }
  else if(currentState == 3){
    if(password == ""){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Set New 4 Number"); 
      lcd.setCursor(0, 1);
      lcd.print("Password: "+password);
      if(key){
        if(key >= '0' && key <= '9'){
          if(passwordSetter <= 3){
            newPassReg += key;
            passwordSetter++;
          }
        }
        if(key == '*'){
          password = newPassReg; 
          newPassReg = "";
          passwordSetter = 0;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Set Successfully");
        }
      }
    } else {
      if(newPassLog == ""){
        if(key){
          if(key >= '0' && key <= '9'){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Log in");
            lcd.setCursor(0, 1);
            lcd.print("Password: "+newPassReg);
            if(passwordSetter <= 3){
              newPassReg += key;
              passwordSetter++;
            }
          }
          else if(key == 'D'){
            newPassLog = newPassReg;
          }
        }
      } else{
        if(key){
          if((key >= '6' && key <= '9') ||  key == 'B'){
            if(password == newPassLog){
              CheckTotalDespense(key);
            }
          }
        }
      }
    }
  }
}

