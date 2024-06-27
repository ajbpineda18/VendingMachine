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

void checkProdAvailability(){
  if(product[prodKey].ProductQuantity > 0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Product Available!");
    currentState = 1;
  } else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Product Out of Stock!");
    currentState = 0;
    prodKey = -1;
  }
}

//Printing Details of the order
void printToLcd(int changeprod){
  if(product[changeprod].ProductQuantity > 2){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print((String)readHumid()+"%    "+readTemp()+" C");
    lcd.setCursor(0,1);
    lcd.print(product[changeprod].ProductName);
    lcd.setCursor(0,2);
    lcd.print((String)"Price: "+int(product[changeprod].ProductPrice));
    lcd.setCursor(0,3);
    lcd.print("Available");
  } else if(product[changeprod].ProductQuantity < 3 && product[changeprod].ProductQuantity > 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print((String)readHumid()+"%    "+readTemp()+" C");
    lcd.setCursor(0,1);
    lcd.print(product[changeprod].ProductName);
    lcd.setCursor(0,2);
    lcd.print((String)"Price: "+int(product[changeprod].ProductPrice));
    lcd.setCursor(0,3);
    lcd.print("Low On Stock");
  } else if(product[changeprod].ProductQuantity == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print((String)readHumid()+"%    "+readTemp()+" C");
    lcd.setCursor(0,1);
    lcd.print(product[changeprod].ProductName);
    lcd.setCursor(0,2);
    lcd.print((String)"Price: "+int(product[changeprod].ProductPrice));
    lcd.setCursor(0,3);
    lcd.print("Out of Stock");
  }
  readWaterSensor();
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

void pickedProdsDetails(unsigned long currentSelectedMillis){

  if(showOnce == 0){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(product[prodKey].ProductName);
    lcd.setCursor(0,1);
    lcd.print(product[prodKey].ProductPrice);
    showOnce++;
  }
  
  if(showPeso != TotalPeso){
    lcd.setCursor(0,2);
    lcd.print("             ");
    lcd.setCursor(0,2);
    lcd.print("Coin/s: ");
    lcd.print(TotalPeso);
    showPeso = TotalPeso;
  }
  
  if(currentSelectedMillis - selected_millis >= 5000){
    selected_millis = currentSelectedMillis;
    if(changingInstruction == 0){
      lcd.setCursor(0,3);
      lcd.print("               ");
      lcd.setCursor(0,3);
      lcd.print("Press D to Drop");
      changingInstruction++;
    } else {
      lcd.setCursor(0,3);
      lcd.print("                 ");
      lcd.setCursor(0,3);
      lcd.print("Press C to Cancel");
      changingInstruction = 0;
    }
  }

}