#define LED 11

void setup() {
  pinMode(LED,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(LED,HIGH);
  delay(250);
  digitalWrite(LED,LOW);
  delay(250);
}
