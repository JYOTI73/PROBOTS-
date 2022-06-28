#ifndef _HAL_H_

        #define _HAL_H_               
        #define NUM_LED_SEGMENTS 17   // Do NOT change this

        // HAL: HAL stands for Hardware Abstraction Layer
        // If any hardware wiring etc is changed only this file is affected,
        // remaining software, remains same
        // This is how Embedded Software Engineers do!
        //
        // Also BSP means Board Support Package, which we will study .... some other time.
        // 

        // As per the circuit diagram :
        //                                      A2,A1, F, H,   E, J, M, N,    L,D2,D1,DP,    C,G1, B,G2,   K
        int picoPinNoGPIO[NUM_LED_SEGMENTS] = {  2, 3, 4, 5,   6, 7, 8, 9,   10,11,12,13,   14,15,16,17,  18 };
        //                                                                   NOTE     DP is not working the actual display

#endif  // _HAL_H_

//#include "font.h"
#ifndef _FONT_H_

            #define _FONT_H_               


            //#include "hal.h"


            #define NUMBER_OF_SYMBOLS  38 // (10 + 26 + 1 + 1 ) 0-9:numbers; 26 Alphabets; 1 Error Symbol, 1 Blank Space


            ////// Set up which segments have to be turned ON or OFF for each letter or symbol
            ////// you can identify the neccesary pattern using the font.png mapping file
            int fontSymbolBits[NUMBER_OF_SYMBOLS][NUM_LED_SEGMENTS] = { 
            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // 0
               { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1}, // 1
               { 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1}, // 2
               { 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1}, // 3 DIY: Do It Yourself
               { 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1}, // 4 DIY

            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K   
               { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1}, // 5 DIY
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1}, // 6 DIY
               { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1}, // 7 DIY
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1}, // 8 DIY
               { 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1}, // 9 DIY
               
            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K

               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1}, // A 
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0}, // B 
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1}, // C 
               { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // D 
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1}, // E DIY


            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1}, // F DIY
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1}, // G DIY
               { 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1}, // H DIY
               { 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1}, // I DIY
               { 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // J DIY

            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
               { 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0}, // K DIY
               { 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1}, // L DIY
               { 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0}, // M DIY
               { 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1}, // N DIY
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // O DIY

            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
               { 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1}, // P DIY
               { 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1}, // Q DIY
               { 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1}, // R DIY
               { 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1}, // S DIY
               { 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // T DIY


            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
               { 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}, // U DIY
               { 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // V DIY
               { 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1}, // W DIY
               { 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, // X DIY
               { 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, // Y DIY

            //  A2,A1, F, H, E, J, M, N, L,D2,D1,DP, C,G1, B,G2, K
               { 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0}, // Z 
               { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // CLEAR ALL
               { 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1}, // ERROR Indicator: A Sigma like symbol!
            };

#endif  // _FONT_H_

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
   digitalWrite(LED_BUILTIN,HIGH);
    static char charToDisplay='0';

//    Serial.print("\r\n  ");
//    Serial.print(serialNumber);
//    Serial.print("  What do you want to display? ");
//    Serial.print("\r\n  Enter anything from 0-9, A-Z :  ");

//    charToDisplay = easyReadCharFromSerial();

//    Serial.print("\r\n  Your wish is my command! \r\n  I will send "); 
//    Serial.print(charToDisplay); 
//    Serial.print(" to the Alpha-Numeric display.");
//    Serial.print("\r\n  -------------------------- \r\n");
    if(charToDisplay =='9')
    {
      charToDisplay ='A';
    }
    if(charToDisplay ==( 'Y'+1))
    {
      charToDisplay='0';
    }
    displayAlphaNum(charToDisplay++);
 
    delay(800);
//    displayAlphaNum(' ');  // CLEAR: Save Power and also increase the life of the Display !!!
//    serialNumber++;
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
          fontArrayRowNumber = 10 + 26 + 0; // Index of : BLANK: CLEAR ALL BITS       
       else
          fontArrayRowNumber = 10 + 26 + 1 + 0; // Error Indicator Symbol: if it is NOT 0-9, A-Z or space then error symbol is diaplayed


  for(int pinNoIndex =0; pinNoIndex < NUM_LED_SEGMENTS; pinNoIndex++)
    {
        digitalWrite( picoPinNoGPIO[pinNoIndex], fontSymbolBits[fontArrayRowNumber][pinNoIndex]);
  
    }

}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
