#define SEVENSEGMENTLED1 13//
#define SEVENSEGMENTLED2 14//
#define SEVENSEGMENTLED3 12//
#define SEVENSEGMENTLED4 15//
#define SEVENSEGMENTLED5 16//
#define SEVENSEGMENTLED6 18//
#define SEVENSEGMENTLED7 17//
#define SEVENSEGMENTDOT 19



void setup() {
 pinMode(SEVENSEGMENTLED1,OUTPUT);
 pinMode(SEVENSEGMENTLED2,OUTPUT);
 pinMode(SEVENSEGMENTLED3,OUTPUT);
 pinMode(SEVENSEGMENTLED4,OUTPUT);
 pinMode(SEVENSEGMENTLED5,OUTPUT);
 pinMode(SEVENSEGMENTLED6,OUTPUT);
 pinMode(SEVENSEGMENTLED7,OUTPUT);
 pinMode(SEVENSEGMENTDOT,OUTPUT);
  // put your setup code here, to run once:

}
void display(int n)
{
  if(n<0 ||n>9)
  {
      digitalWrite(SEVENSEGMENTLED1,LOW);
      digitalWrite(SEVENSEGMENTLED2,LOW);
      digitalWrite(SEVENSEGMENTLED3,LOW);
      digitalWrite(SEVENSEGMENTLED4,LOW);
      digitalWrite(SEVENSEGMENTLED5,LOW);
      digitalWrite(SEVENSEGMENTLED6,LOW);
      digitalWrite(SEVENSEGMENTLED7,LOW);
      digitalWrite(SEVENSEGMENTDOT,HIGH);
  }
  else
  {
    switch(n)
    {
      case 0:
         digitalWrite(SEVENSEGMENTLED1,HIGH);
         digitalWrite(SEVENSEGMENTLED2,HIGH);
         digitalWrite(SEVENSEGMENTLED3,HIGH);
         digitalWrite(SEVENSEGMENTLED4,LOW);
         digitalWrite(SEVENSEGMENTLED5,HIGH);
         digitalWrite(SEVENSEGMENTLED6,HIGH);
         digitalWrite(SEVENSEGMENTLED7,HIGH);
         digitalWrite(SEVENSEGMENTDOT,LOW);
      
      break;
       case 1:
         digitalWrite(SEVENSEGMENTLED1,LOW);
         digitalWrite(SEVENSEGMENTLED2,LOW);
         digitalWrite(SEVENSEGMENTLED3,HIGH);
         digitalWrite(SEVENSEGMENTLED4,LOW);
         digitalWrite(SEVENSEGMENTLED5,LOW);
         digitalWrite(SEVENSEGMENTLED6,HIGH);
         digitalWrite(SEVENSEGMENTLED7,LOW);
         digitalWrite(SEVENSEGMENTDOT,LOW);
      
            
       break;
        case 2:
         digitalWrite(SEVENSEGMENTLED1,HIGH);
         digitalWrite(SEVENSEGMENTLED2,LOW);
         digitalWrite(SEVENSEGMENTLED3,HIGH);
         digitalWrite(SEVENSEGMENTLED4,HIGH);
         digitalWrite(SEVENSEGMENTLED5,HIGH);
         digitalWrite(SEVENSEGMENTLED6,LOW);
         digitalWrite(SEVENSEGMENTLED7,HIGH);
         digitalWrite(SEVENSEGMENTDOT,LOW);
     
        break;
         case 3:
          digitalWrite(SEVENSEGMENTLED1,HIGH);
          digitalWrite(SEVENSEGMENTLED2,LOW);
          digitalWrite(SEVENSEGMENTLED3,HIGH);
          digitalWrite(SEVENSEGMENTLED4,HIGH);
          digitalWrite(SEVENSEGMENTLED5,LOW);
          digitalWrite(SEVENSEGMENTLED6,HIGH);
          digitalWrite(SEVENSEGMENTLED7,HIGH);
          digitalWrite(SEVENSEGMENTDOT,LOW);
      
         break;
          case 4:
            digitalWrite(SEVENSEGMENTLED1,LOW);
            digitalWrite(SEVENSEGMENTLED2,HIGH);
            digitalWrite(SEVENSEGMENTLED3,HIGH);
            digitalWrite(SEVENSEGMENTLED4,HIGH);
            digitalWrite(SEVENSEGMENTLED5,LOW);
            digitalWrite(SEVENSEGMENTLED6,HIGH);
            digitalWrite(SEVENSEGMENTLED7,LOW);
            digitalWrite(SEVENSEGMENTDOT,LOW);
      
         break;
           case 5:
              digitalWrite(SEVENSEGMENTLED1,HIGH);
              digitalWrite(SEVENSEGMENTLED2,HIGH);
              digitalWrite(SEVENSEGMENTLED3,LOW);
              digitalWrite(SEVENSEGMENTLED4,HIGH);
              digitalWrite(SEVENSEGMENTLED5,LOW);
              digitalWrite(SEVENSEGMENTLED6,HIGH);
              digitalWrite(SEVENSEGMENTLED7,HIGH);
              digitalWrite(SEVENSEGMENTDOT,LOW);
      
         break;
            case 6:
               digitalWrite(SEVENSEGMENTLED1,HIGH);
               digitalWrite(SEVENSEGMENTLED2,HIGH);
               digitalWrite(SEVENSEGMENTLED3,LOW);
               digitalWrite(SEVENSEGMENTLED4,HIGH);
               digitalWrite(SEVENSEGMENTLED5,HIGH);
               digitalWrite(SEVENSEGMENTLED6,HIGH);
               digitalWrite(SEVENSEGMENTLED7,HIGH);
               digitalWrite(SEVENSEGMENTDOT,LOW);
      
         break;
             case 7:
                digitalWrite(SEVENSEGMENTLED1,HIGH);
                digitalWrite(SEVENSEGMENTLED2,LOW);
                digitalWrite(SEVENSEGMENTLED3,HIGH);
                digitalWrite(SEVENSEGMENTLED4,LOW);
                digitalWrite(SEVENSEGMENTLED5,LOW);
                digitalWrite(SEVENSEGMENTLED6,HIGH);
                digitalWrite(SEVENSEGMENTLED7,LOW);
                digitalWrite(SEVENSEGMENTDOT,LOW);
       
         break;
              case 8:
                digitalWrite(SEVENSEGMENTLED1,HIGH);
                digitalWrite(SEVENSEGMENTLED2,HIGH);
                digitalWrite(SEVENSEGMENTLED3,HIGH);
                digitalWrite(SEVENSEGMENTLED4,HIGH);
                digitalWrite(SEVENSEGMENTLED5,HIGH);
                digitalWrite(SEVENSEGMENTLED6,HIGH);
                digitalWrite(SEVENSEGMENTLED7,HIGH);
                digitalWrite(SEVENSEGMENTDOT,LOW);
         break;
               case 9:
                digitalWrite(SEVENSEGMENTLED1,HIGH);
                digitalWrite(SEVENSEGMENTLED2,HIGH);
                digitalWrite(SEVENSEGMENTLED3,HIGH);
                digitalWrite(SEVENSEGMENTLED4,LOW);
                digitalWrite(SEVENSEGMENTLED5,LOW);
                digitalWrite(SEVENSEGMENTLED6,HIGH);
                digitalWrite(SEVENSEGMENTLED7,HIGH);
                digitalWrite(SEVENSEGMENTDOT,LOW);
                break;
    }
  }
}
/*hello*/

void loop() {
  // put your main code here, to run repeatedly:
  int a =3,b=4;
  int c = a+b;
  display(c);
  delay(2000);
}
