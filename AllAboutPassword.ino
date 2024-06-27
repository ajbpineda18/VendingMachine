void passwordChecker(char key){
  if(key != NULL){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LogIn Owner"); 
    if(key){
      if(key >= '0' && key <= '9'){
          if(passwordSetter <= 3){
          setPass += key;
          passwordSetter++;
          lcd.setCursor(0, 1);
          lcd.print("Password: ");
          for(int i = 0; i < setPass.length(); i++){
            lcd.print("*");
          }
          key = NULL;
        }
      }
      if(key == 'C'){
        setPass.remove(passwordSetter);
        passwordSetter--;
        key = NULL;
      }
      if(key == '*'){
        if(setPass == password){
          login = true;
          passwordSetter = 0;
          setPass = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Log in success!");
          key = NULL;
        } else {
          passwordSetter = 0;
          setPass = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Log in Failed!");
          key = ' ';
        }
      }
    }
  }
  
}
