// void passwordSetters(char key){
//   if(key != NULL){
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("Set New 4 Number"); 
//     lcd.setCursor(0, 1);
//     lcd.print("Password: "+setPass);
//     if(key){
//       if(key >= '0' && key <= '9'){
//           if(passwordSetter <= 3){
//           setPass += key;
//           Serial.println((String) "passwordSetter: "+passwordSetter);
//           passwordSetter++;
//         }
//       }
//       if(key == 'C'){
//         setPass.remove(passwordSetter);
//         passwordSetter--;
//         Serial.println((String) "passwordSetter: "+passwordSetter);
//       }
//       if(key == '*'){
//         if(passwordSetter >= 3){
//           password = setPass; 
//           setPass = "";
//           passwordSetter = 0;
//           lcd.clear();
//           lcd.setCursor(0, 0);
//           lcd.print("Set Successfully");
//         } else {
//           setPass = "";
//           passwordSetter = 0;
//           lcd.clear();
//           lcd.setCursor(0, 0);
//           lcd.print("Set Failed");
//           lcd.setCursor(0, 1);
//           lcd.print("Password Must Be");
//           lcd.setCursor(0, 2);
//           lcd.print("4 Numbers Long!");
//         }
//       }
//     }
//   }
//   key = NULL;
// }


void passwordChecker(char key){
  if(key != NULL){
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
        } else {
          passwordSetter = 0;
          setPass = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Log in Failed!");
        }
      }
    }
  }
  key = NULL;
}

// void passwordReset(char key){
//   if(key != NULL){
//     lcd.clear();
//     lcd.setCursor(0, 0);
//     lcd.print("Reset Password"); 
//     lcd.setCursor(0, 1);
//     lcd.print("Password: "+setPass);
//     if(key){
//       if(key >= '0' && key <= '9'){
//           if(passwordSetter <= 3){
//           setPass += key;
//           passwordSetter++;
//         }
//       }
//       if(key == 'C'){
//         setPass.remove(passwordSetter);
//         passwordSetter--;
//       }
//       if(key == '*'){
//         if(setPass == password){
//           password = "";
//           login = false;
//           passwordSetter = 0;
//           setPass = "";
//           lcd.clear();
//           lcd.setCursor(0, 0);
//           lcd.print("Reset success!");
//         } else {
//           passwordSetter = 0;
//           setPass = "";
//           lcd.clear();
//           lcd.setCursor(0, 0);
//           lcd.print("Log in Failed!");
//         }
//       }
//     }
//   }
//   key = NULL;
// }