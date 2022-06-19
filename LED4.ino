#define REDLEDPIN 10
#define YELLOWLEDPIN 11
#define GREENLEDPIN 12
#define WHITELEDPIN 13


void setup() {
  // put your setup code here, to run once:
  pinMode(REDLEDPIN,OUTPUT);
   pinMode(YELLOWLEDPIN,OUTPUT);
    pinMode(GREENLEDPIN,OUTPUT);
     pinMode(WHITELEDPIN,OUTPUT);
    
}


void loop() {
  digitalWrite(REDLEDPIN,LOW);
    digitalWrite(YELLOWLEDPIN,LOW);
      digitalWrite(GREENLEDPIN,LOW);
        digitalWrite(WHITELEDPIN,HIGH);
  delay(1000);
   digitalWrite(REDLEDPIN,LOW);
    digitalWrite(YELLOWLEDPIN,LOW);
      digitalWrite(GREENLEDPIN,HIGH);
        digitalWrite(WHITELEDPIN,LOW);
  delay(1000);
   digitalWrite(REDLEDPIN,LOW);
    digitalWrite(YELLOWLEDPIN,HIGH);
      digitalWrite(GREENLEDPIN,LOW);
        digitalWrite(WHITELEDPIN,LOW);
        delay(1000);
         digitalWrite(REDLEDPIN,HIGH);
    digitalWrite(YELLOWLEDPIN,LOW);
      digitalWrite(GREENLEDPIN,LOW);
        digitalWrite(WHITELEDPIN,LOW);
        delay(1000);
  // put your main code here, to run repeatedly:

}
