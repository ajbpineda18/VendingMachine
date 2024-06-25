void CheckTotalDespense(char key){
  int totalProdDispense = 0;
  switch(key){
    case '6': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[0].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(0, 99);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      delay(2000);
    break;
    case '7': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[1].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(100, 199);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      delay(2000);
    break;
    case 'B': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[2].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(200, 299);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      delay(2000);
    break;
    case '8': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[3].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(300, 399);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      delay(2000);
    break;
    case '9': 
      lcd.clear();
      lcd.setCursor(1, 1);
      lcd.print(product[4].ProductName);
      lcd.setCursor(2, 2);
      totalProdDispense = checkLastEeprom(400,499);
      lcd.print((String)"Total Dispense: "+totalProdDispense);
      delay(2000);
    break;
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