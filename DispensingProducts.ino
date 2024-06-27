//Checking sum amount of money compared to Price
void checkPaid(){
  if(product[prodKey].ProductPrice <= TotalPeso){
    //Optional
    int TimeDelay = customDelay();
    myservo[prodKey].attach(servos[prodKey]);
    myservo[prodKey].write(255);
    delay(TimeDelay);
    myservo[prodKey].detach();
    calculateDrop();
    afterOrder();
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Insufficient Funds");
    delay(1000);
    showPeso = -1;
    showOnce = -1;
  }
}

//Optional Custom Delays For Each Servo
int customDelay(){
    int TimeDelay = 0;
    switch(prodKey){
      case 0:
        TimeDelay = 1600;
      break;
      case 1:
        TimeDelay = 1750;
      break;
      case 2:
        TimeDelay = 1600;
      break;
      case 3:
        TimeDelay = 1600;
      break;
      case 4:
        TimeDelay = 1600;
      break;
    }
    return TimeDelay;
}