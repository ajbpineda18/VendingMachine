void CheckTotalDespense(char key){
  int totalProdDispense = 0;
  switch(key){
    case '1': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[0].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(0, 99);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      deleteKey = 0;
      delay(1000);
    break;
    case '2': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[1].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(100, 199);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      deleteKey = 1;
      delay(1000);
    break;
    case '3': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[2].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(200, 299);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      deleteKey = 2;
      delay(1000);
    break;
    case '4': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[3].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(300, 399);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      deleteKey = 3;
      delay(1000);
    break;
    case '5': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[4].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(400,499);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      deleteKey = 4;
      delay(1000);
    break;
  }
}

void ResetDispense(char key){
  if(key){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(product[deleteKey].ProductName);
    lcd.setCursor(0, 1);
    lcd.print("Press C to Clear!");
    lcd.setCursor(0, 2);
    lcd.print("Press B to Back!");
    Serial.println(key);
    if(key == 'C'){
      deleteProm();
      deleteKey = -1;
    }
    else if(key == 'B'){
      deleteKey = -1;
    }
  }
}

void calculateDrop(){
  switch(prodKey){
    case 0: 
      addeeprom(0, 99);
    break;
    case 1:
      addeeprom(100, 199);
    break;
    case 2: 
      addeeprom(200, 299);
    break;
    case 3: 
      addeeprom(300, 399);
    break;
    case 4: 
      addeeprom(400, 499);
    break;
  }
}

int checkLastEeprom(int min, int max){
  //208845
  int total = 0;
  total = EEPROM.read(max)*25245;
  for(int i = min; i < max; i++){
    total += EEPROM.read(i);
  }
  return total;
}

void addeeprom(int min, int max){
  if(EEPROM.read(max-1) == 255){
    int alt = EEPROM.read(max)+1;
    EEPROM.update(max, alt);
    for(int i = min; i<max; i++){
      EEPROM.update(i, 0);
    }
  }

  for(int i = min; i<max; i++){
    if(EEPROM.read(i) == 255){
      continue;
    } else {
      int alt = EEPROM.read(i)+1;
      EEPROM.update(i, alt);
      break;
    }
  }
}

void deleteProm(){
  Serial.println(deleteKey);
  switch(deleteKey){
      case 0: 
        //0, 99
        for(int i = 0; i < 100; i++){
          EEPROM.update(i, 0);
        }
      break;
      case 1:
        //100, 199
        for(int i = 100; i < 200; i++){
          EEPROM.update(i, 0);
        }
      break;
      case 2:
        //200, 299
        for(int i = 200; i < 300; i++){
          EEPROM.update(i, 0);
        }
      break;
      case 3:
        //300, 399
        for(int i = 300; i < 400; i++){
          EEPROM.update(i, 0);
        }
      break;
      case 4:
        //400, 499
        for(int i = 400; i < 500; i++){
          EEPROM.update(i, 0);
        }
      break;
    }
}

