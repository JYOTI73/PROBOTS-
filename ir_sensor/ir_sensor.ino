#define IR_SENSOR_PIN 16
int status;
int counter = 0;
#define WHITE 1
#define BLACK 0
void setup() {
  pinMode(IR_SENSOR_PIN,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  status = digitalRead(IR_SENSOR_PIN);
  Serial.print(++counter);
  if(status == WHITE)
  {
    Serial.print("WHITE");
    
  }
  else
  {
    Serial.print("BLACK");
  }
  digitalWrite(LED_BUILTIN,status);
  Serial.print("\r\n");
  delay(250);

}
