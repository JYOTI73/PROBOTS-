#define RED_PIN_NO 2
#define GREEN_PIN_NO 3
#define BLUE_PIN_NO 4
enum COLOR_VAL{BLACK,BLUE,GREEN,CYAN,RED,MEG,YELLOW,WHITE};
void setup() {
  pinMode(RED_PIN_NO,OUTPUT);
  pinMode(GREEN_PIN_NO,OUTPUT);
  pinMode(BLUE_PIN_NO,OUTPUT);
//  Serial.begin(9600);  
}
int color[8][3]{
// R G B
  {1,1,1},
  {1,1,0},
  {1,0,1},
  {1,0,0},
  {0,1,1},
  {0,1,0},
  {0,0,1},
  {0,0,0}
};
void displayCol(int line_no)
{
  
    digitalWrite(RED_PIN_NO,color[line_no][0]);
    digitalWrite(GREEN_PIN_NO,color[line_no][1]);
    digitalWrite(BLUE_PIN_NO,color[line_no][2]);
    delay(1000);
}

void loop() {
  
  for(int i = 0;i<=7;i++)
  {
    displayCol(i);
  }
  

}
