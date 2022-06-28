#define joyX A0
#define joyY A1

void setup() {
  Serial.begin(9600);

}

void loop() {
  int x,y;
  x = analogRead(A0);
  y = analogRead(A1);
  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print("\r\n");
  delay(250);
  

}
