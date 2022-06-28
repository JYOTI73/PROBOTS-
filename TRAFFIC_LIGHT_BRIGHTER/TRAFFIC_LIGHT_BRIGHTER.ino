#define RED_LIGHT 13
#define YELLOW_LIGHT 12
#define GREEN_LIGHT 11
void setup() {
  pinMode(RED_LIGHT,OUTPUT);
  pinMode(YELLOW_LIGHT,OUTPUT);
  pinMode(GREEN_LIGHT,OUTPUT);

}

void loop() {
  for(int i = 0;i<=255;i++)
  {
    analogWrite(RED_LIGHT,i);
    delay(10);
  }
  for(int i = 255;i>=0;i--)
  {
    analogWrite(RED_LIGHT,i);
    delay(10);
  }
  for(int i = 0;i<=255;i++)
  {
    analogWrite(YELLOW_LIGHT,i);
     delay(10);
  }
  for(int i = 255;i>=0;i--)
  {
    analogWrite(YELLOW_LIGHT,i);
    delay(10);
  }
  for(int i = 0;i<=255;i++)
  {
    analogWrite(GREEN_LIGHT,i);
     delay(10);
  }
  for(int i = 255;i>=0;i--)
  {
    analogWrite(GREEN_LIGHT,i);
    delay(10);
  }
}
