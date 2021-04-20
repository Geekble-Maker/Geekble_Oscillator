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
        // Construct Class, Initialize function.
        Geekble_Oscillator();

        // Set output frequency, from 8MHz to 31.25KHz                                  // 8MHz부터 31.25KHz 까지의 출력주파수를 설정합니다.
        // Output Frequency = 8MHz / Divide_Variable                                    // 출력주파수 = 8MHz / Divide_Variable
        // ex: Geekble_Oscillator OSC (1); -> 8MHz                                      // 예시: Geekble_Oscillator OSC (1); -> 8MHz
        // ex: Geekble_Oscillator OSC (10); -> 800KHz                                   // 예시: Geekble_Oscillator OSC (10); -> 800KHz
        void Divide_8MHz_by(uint16_t Divide_Variable);

        // Set Oscilltor On or Off                                                      // Oscillator를 켜거나 끌지를 선택합니다.
        // If On_Off = 1, Output Frequency will generated on Digital pin 11             // On_Off = 1인 경우, Digital pin 11에서 출력주파수가 발생합니다.
        // If On_Off = 0, Timer Counter Stop, Digital pin 11 return to normal operation // On_Off = 0인 경우, 타이머카운터가 정지합니다. Digital pin 11은 기본 pin으로 동작합니다.
        void Run(uint8_t On_Off);
        private:
    };


#endif