
void setup() {
  Serial.begin(9600);

}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  int count = analogRead(A2);
  Serial.println(count);
  delay(250);
}
