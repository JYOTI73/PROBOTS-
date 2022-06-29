#define LED 11
#define BUZZER 26
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   digitalWrite(LED_BUILTIN,HIGH);
  digitalWrite(LED,HIGH);
  delay(250);
  digitalWrite(LED,LOW);
  delay(250);
  digitalWrite(BUZZER,HIGH);
  delay(250);
  digitalWrite(BUZZER,LOW);
  delay(250);
}
