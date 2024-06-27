void coinInserted() {
  // Debounce the coin insertion
  unsigned long currentTime = millis();
  if ((currentTime - lastDebounceTime) > debounceDelay) {
    TotalPeso++;
    lastDebounceTime = currentTime;
  }
}