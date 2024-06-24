//Printing Available Products
void availableProducts(){
  if(change_products >= 0 && change_products <= 4){
    if(product[change_products].ProductQuantity > 0){
      printToLcd(change_products);
    }
  }
  change_products++;
  if(change_products == 4){
    change_products = 0;
  }
}

//Printing Details of the order
void printToLcd(int changeprod){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print((String)readHumid()+"%    "+readTemp()+" C");
  lcd.setCursor(0,1);
  lcd.print(product[changeprod].ProductName);
  lcd.setCursor(0,2);
  lcd.print((String)"Price: "+int(product[changeprod].ProductPrice));
  lcd.setCursor(0,3);
  lcd.print("Available");
}

//Checking sum amount of money compared to Price
void checkPaid(int TimeDelay){
  if(product[prodKey].ProductPrice <= TotalPeso){
    //Optional
    //int TimeDelay = customDelay();
    myservo[prodKey].attach(servos[prodKey]);
    myservo[prodKey].write(255);
    delay(TimeDelay);
    myservo[prodKey].detach();
    calculateDrop();
    afterOrder();
  } else {
    currentState = 1;
  }
}

//Optional Custom Delays For Each Servo
int customDelay(){
    int TimeDelay = 0;
    switch(prodKey){
      case 0:
        TimeDelay = 2000;
      break;
      case 1:
        TimeDelay = 2000;
      break;
      case 2:
        TimeDelay = 2000;
      break;
      case 3:
        TimeDelay = 2000;
      break;
      case 4:
        TimeDelay = 2000;
      break;
    }
    return TimeDelay;
}

//Setting Product Details
void productDetails() {
  product[0].ProductName = "Wash Sugar";
  product[0].ProductPrice = 5.0;

  product[1].ProductName = "Rock Salt";
  product[1].ProductPrice = 5.0;

  product[2].ProductName = "Powdered Coffee";
  product[2].ProductPrice = 20.0;

  product[3].ProductName = "Powdered Creamer";
  product[3].ProductPrice = 15.0;

  product[4].ProductName = "Ground Black Pepper";
  product[4].ProductPrice = 20.0;

  for(int i = 0; i<5; i++){
      product[i].ProductQuantity = 5;
  }
}

//Picking Products
void pickprods(char key){
  prodKey = key - '1';
  currentState = 1;
  Serial.println("Product Picked: "+String(prodKey+1));
}

void pickedProdsDetails(){
  Serial.println(TotalPeso);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(product[prodKey].ProductName);
  lcd.setCursor(0,1);
  lcd.print(product[prodKey].ProductPrice);
  lcd.setCursor(0,2);
  lcd.print("Coin/s: ");
  lcd.print(TotalPeso);
  if(changingInstruction == 0){
    lcd.setCursor(0,3);
    lcd.print("Press D to Drop");
    changingInstruction++;
  } else {
    lcd.setCursor(0,3);
    lcd.print("Press C to Cancel");
    changingInstruction = 0;
  }
  
}