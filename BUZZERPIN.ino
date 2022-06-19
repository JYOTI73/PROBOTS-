#define MYBUZZERPIN 16

void setup() {
  // put your setup code here, to run once:
  pinMode(MYBUZZERPIN,OUTPUT);
}

void loop() {
  digitalWrite(MYBUZZERPIN,HIGH);
  delay(1000);
  digitalWrite(MYBUZZERPIN,LOW);
  delay(1000);
  // put your main code here, to run repeatedly:

}
