void insertCoin(){
  unsigned long currentpesoMillis = millis();
  if(digitalRead(counterPin) == LOW){
    TotalPeso++;
  }
  // if(currentpesoMillis - peso_millis >= 600){
  //   peso_millis = currentpesoMillis;
  //   if(TotalPeso != BeforePeso){
  //     currentPeso = TotalPeso - BeforePeso;
  //     BeforePeso = TotalPeso;
  //   }
  //   if(currentPeso == 4 || currentPeso == 9 || currentPeso == 19){
  //     TotalPeso++;
  //     BeforePeso = TotalPeso;
  //   }
  // }
}