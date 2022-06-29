#define R7  10000
#define R8  5100

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int count=analogRead(A0);
  float voltage= map( count ,0,1023,0,9.7705)
  Serial.println(voltage);
  delay(250);
}
