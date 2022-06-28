void setup() {
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  float taken = analogRead(A0);
  float value= 6.1268596;
  float voltage = value * taken*0.003225806;
  Serial.print(voltage);
  Serial.print("\r\n");
  delay(1000);
}
