#include "hal.h"
#include "font.h"


//////////////////////////////////////////////////////////////////////////////
void setup()
{   
//For loop to declare all pins as an output
 for (int i = 0; i < NUM_LED_SEGMENTS; i++) {
   pinMode(picoPinNoGPIO[i], OUTPUT);
 }

 displayAlphaNum(' ');  // CLEAR

 Serial.begin(9600);
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int serialNumber = 1;
void loop()
{

    char charToDisplay;

    Serial.print("\r\n  ");
    Serial.print(serialNumber);
    Serial.print("  What do you want to display? ");
    Serial.print("\r\n  Enter anything from 0-9, A-Z :  ");

    charToDisplay = easyReadCharFromSerial();

    Serial.print("\r\n  Your wish is my command! \r\n  I will send "); 
    Serial.print(charToDisplay); 
    Serial.print(" to the Alpha-Numeric display.");
    Serial.print("\r\n  -------------------------- \r\n");
    displayAlphaNum(charToDisplay); 

    delay(4000);
    displayAlphaNum(' ');  // CLEAR: Save Power and also increase the life of the Display !!!
    serialNumber++;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
char easyReadCharFromSerial(void)
{
    char received;

    while(Serial.available() <= 0)
    {
        ;  // wait in-definately, until someone send atleast a char
    }

    received = Serial.read();

    flushSerialPortBuffer(); // Clean any char


   return received;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void flushSerialPortBuffer(void)
{

    char dummyUselessCharVariable;

    while(Serial.available() > 0)
    {
        dummyUselessCharVariable =  Serial.read(); // gobble1 (eat up) all chars stored in serial buffer
    }


}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void displayAlphaNumString(char s[], int inBetweenDelay)
{
    for(int i=0; i< strlen(s); i++)
    {
        displayAlphaNum(s[i]);
        delay(inBetweenDelay);
    }
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
void displayAlphaNum(char ch)
{
  int fontArrayRowNumber;

       if(ch >= '0' && ch <= '9')
          fontArrayRowNumber = ch - '0'; // or ch -48 or ch - "ASCII OF ZERO" all are same
  else if(ch >= 'A' && ch <= 'Z')
          fontArrayRowNumber = 10 + (ch - 'A'); // After 0 to 9 there are Alphabets
  else if(ch == ' ')
          fontArrayRowNumber = 10 + 26; // Index of : BLANK: CLEAR ALL BITS       
  else if(ch == '*')
          fontArrayRowNumber = 10 + 26 + 2; // Index of : *
  else if(ch == '#')
          fontArrayRowNumber = 10 + 26 + 3; // Index of : #
       else
          fontArrayRowNumber = 10 + 26 + 1; // Error Indicator Symbol: if it is NOT 0-9, A-Z or space then error symbol is diaplayed


  for(int pinNoIndex =0; pinNoIndex < NUM_LED_SEGMENTS; pinNoIndex++)
    {
        digitalWrite( picoPinNoGPIO[pinNoIndex], fontSymbolBits[fontArrayRowNumber][pinNoIndex]);
  
    }

}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////