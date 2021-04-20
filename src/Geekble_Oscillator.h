/*
    Geekble_Oscillator.h - Library for generate high frequency pulses.
    Created by SooDragon @ Geekble Circuit Maker, April 19, 2021.
    Released into the public domain.
*/

#ifndef Geekble_Oscillator_h
    #define Geekble_Oscillator_h

    #include "Arduino.h"

    class Geekble_Oscillator
    {
        public:
        Geekble_Oscillator(uint16_t Divide_Variable);
        void Run(uint8_t On_Off);

        private:
    };

void OSC_Setup();
void OSC_Run();

#endif