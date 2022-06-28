#include "hal.h"
#include "font.h"
#define   DEMO_DELAY 10

//////////////////////////////////////////////////////////////////////////////
void setup()
{   
//For loop to declare all Alpha Numeric Segment pins as an output
 for (int i = 0; i < NUM_LED_SEGMENTS; i++) {
   pinMode(picoPinNoGPIOForALphaNum[i], OUTPUT);
 }
  
// All rows in KeyPad act as output pins
 for (int i = 0; i < KEYPAD_ROWS; i++) {
   pinMode(picoPinNoOutputsForKeyPad[i], OUTPUT);
 }

// All columns in KeyPad act as input pins
 for (int i = 0; i < KEYPAD_COLS; i++) {
   pinMode(picoPinNoInputsForKeyPad[i], INPUT_PULLUP);
 }


 displayAlphaNum(' ');  // CLEAR

 Serial.begin(9600);

 // wait for serial port to connect. Needed for native USB
// while (!Serial) {  ;   }
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
    Serial.print("\r\n  Press any key on KEYPAD :  ");

    ////// charToDisplay = easyReadCharFromSerial();
           charToDisplay = easyReadCharFromKeyPad();

    Serial.print("\r\n  On the KEYPAD you pressed: ");
    Serial.print(charToDisplay); 
    Serial.print("\r\n  I will send "); 
    Serial.print(charToDisplay); 
    Serial.print(" to the Alpha-Numeric display.");
    Serial.print("\r\n  -------------------------- \r\n");
    displayAlphaNum(charToDisplay); 

    //delay(1000); // IMPORTANT KEY BOUNCE DELAY
    ////////while(1); // HANG

    ////// displayAlphaNum(' ');  // CLEAR: Save Power and also increase the life of the Display !!!
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
  else if(ch >= 'A' && ch <= 'D')
          fontArrayRowNumber = 10 + (ch - 'A'); // After 0 to 9 there are Alphabets
//  else if(ch == ' ')
//          fontArrayRowNumber = 10 + 26; // Index of : BLANK: CLEAR ALL BITS       
  else if(ch == '*')
          fontArrayRowNumber = 10 + 4 + 1; // Index of : *
  else if(ch == '#')
          fontArrayRowNumber = 10 + 4 + 2; // Index of : #
//       else
//          fontArrayRowNumber = 10 + 26 + 1; // Error Indicator Symbol: if it is NOT 0-9, A-Z or space then error symbol is diaplayed


  for(int pinNoIndex =0; pinNoIndex < NUM_LED_SEGMENTS; pinNoIndex++)
    {
        digitalWrite( picoPinNoGPIOForALphaNum[pinNoIndex], fontSymbolBits[fontArrayRowNumber][pinNoIndex]);
  
    }

}
//////////////////////////////////////////////////////////////////////////////
//        int picoPinNoOutputsForKeyPad[KEYPAD_ROWS] = { 13, 19, 20, 21};
//        int picoPinNoInputsForKeyPad [KEYPAD_COLS] = { 22, 26, 27, 28};

//////////////////////////////////////////////////////////////////////////////
char easyReadCharFromKeyPad(void)
{
    const char keyFaceName[KEYPAD_ROWS][KEYPAD_COLS] = {
      {'1', '2', '3', 'A'},
      {'4', '5', '6', 'B'},
      {'7', '8', '9', 'C'},
      {'*', '0', '#', 'D'}
    };

    int r, c;
    int currentScanRow;
    int status;

    currentScanRow = 0;
    while(1)
    {

        Serial.print("\r\n ");
        Serial.print(" currentScanRow: "); Serial.print(currentScanRow); delay(DEMO_DELAY);

        for(r=0; r<KEYPAD_ROWS; r++) // Test one row at a time
        {
          if(r == currentScanRow)
              digitalWrite( picoPinNoOutputsForKeyPad[r], LOW);
          else
              digitalWrite( picoPinNoOutputsForKeyPad[r], HIGH);

          //Serial.print(" r: ");              Serial.print(r);              delay(DEMO_DELAY);
        }

        for(c=0; c<KEYPAD_COLS; c++) // for the current scan row, check each column
        {
          Serial.print(" c: ");              Serial.print(c);              delay(DEMO_DELAY);

          status = digitalRead( picoPinNoInputsForKeyPad[c] );
          if( status  == LOW) // Key Press event detected
            {
              Serial.print(" PRESSED: "); Serial.print(keyFaceName[currentScanRow][c]); delay(DEMO_DELAY);
              return keyFaceName[currentScanRow][c];
            }
          Serial.print(" status: ");              Serial.print(status);    delay(DEMO_DELAY);
        }

        currentScanRow++;
        if(currentScanRow == KEYPAD_ROWS)
           currentScanRow =  0;
    }

}
//////////////////////////////////////////////////////////////////////////////
