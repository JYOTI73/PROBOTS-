#ifndef _HAL_H_

        #define _HAL_H_               
        #define NUM_LED_SEGMENTS 16   // Do NOT change this
        #define KEYPAD_ROWS 4
        #define KEYPAD_COLS 4

        // HAL: HAL stands for Hardware Abstraction Layer
        // If any hardware wiring etc is changed only this file is affected,
        // remaining software, remains same
        // This is how Embedded Software Engineers do!
        //
        // Also BSP means Board Support Package, which we will study .... some other time.
        // 

        // As per the circuit diagram :
        //                                                 A2,A1, F, H,   E, J, M, N,    L,D2,D1,    C,G1, B,G2,   K
        int picoPinNoGPIOForALphaNum[NUM_LED_SEGMENTS] = {  2, 3, 4, 5,   6, 7, 8, 9,   10,11,12,   14,15,16,17,  18 };
        int picoPinNoOutputsForKeyPad[KEYPAD_ROWS] = { 13, 19, 20, 21};
        int picoPinNoInputsForKeyPad [KEYPAD_COLS] = { 22, 26, 27, 28};

#endif  // _HAL_H_
