void coinInserted() {
  // Debounce the coin insertion
  unsigned long currentTime = millis();
  if ((currentTime - lastDebounceTime) > debounceDelay) {
    TotalPeso++;
    Serial.print("Total Peso: ");
    Serial.println(TotalPeso);
    lastDebounceTime = currentTime;
  }
}