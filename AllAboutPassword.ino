void passwordSetters(char key){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set New 4 Number"); 
  lcd.setCursor(0, 1);
  lcd.print("Password: "+setPass);
  if(key){
    if(key >= '0' && key <= '9'){
        if(passwordSetter <= 3){
        setPass += key;
        passwordSetter++;
      }
    }
    if(key == 'C'){
      setPass.remove(passwordSetter);
      passwordSetter--;
    }
    if(key == '*'){
      if(passwordSetter == 3){
        password = setPass; 
        setPass = "";
        passwordSetter = 0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set Successfully");
        delay(3000);
      } else {
        setPass = "";
        passwordSetter = 0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Set Failed");
        lcd.setCursor(0, 1);
        lcd.print("Password Must Be");
        lcd.setCursor(0, 2);
        lcd.print("4 Numbers Long!");
        delay(3000);
      }
    }
  }
  delay(1500);
}


void passwordChecker(char key){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("LogIn Owner"); 
  lcd.setCursor(0, 1);
  lcd.print("Password: "+setPass);
  if(key){
    if(key >= '0' && key <= '9'){
        if(passwordSetter <= 3){
        setPass += key;
        passwordSetter++;
      }
    }
    if(key == 'C'){
      setPass.remove(passwordSetter);
      passwordSetter--;
    }
    if(key == '*'){
      if(setPass == password){
        login = true;
        passwordSetter = 0;
        setPass = "";
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Log in success!");
        delay(3000);
      } else {
        passwordSetter = 0;
        setPass = "";
         lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Log in Failed!");
        delay(3000);
      }
    }
  }
  delay(1500);
}