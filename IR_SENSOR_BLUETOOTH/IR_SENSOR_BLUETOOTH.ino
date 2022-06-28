#define IR_SENSOR_PIN 16
int status;
int counter = 0;
#define WHITE 0
#define BLACK 1
void setup() {
  pinMode(IR_SENSOR_PIN,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial1.begin(9600);
  Serial1.println("dETECTING darkness");

}

void loop() {
  //if(Serial1.available()){
//    command= Serial1.readStringUntil('\n');
//     command.trim();

    int voltage = analogRead(ADC0);
    Serial1.print("colour: ");
    if(voltage>=1000)
    {
      Serial1.println("BLACK\r\n");
      digitalWrite(LED_BUILTIN,HIGH);
    }
    else{
      Seriall.println("WHITE\r\n");
      digitalWrite(LED_BUILTIN,LOW);
    }
    Serial1.print(++counter);
    
 
    
    delay(250);
//}
  
}
