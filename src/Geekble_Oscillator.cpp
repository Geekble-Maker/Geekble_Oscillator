/*
    Geekble_Oscillator.cpp - Library for generate high frequency pulses.
    Created by SooDragon @ Geekble Circuit Maker, April 19, 2021.
    Released into the public domain.
*/
#include <Arduino.h>
#include "Geekble_Oscillator.h"

Geekble_Oscillator::Geekble_Oscillator(uint16_t Divide_Variable)
{
  // Set Timer Counter 2 to default
  TCCR2A = 0;
  TCCR2B = 0;
  TCNT2 = 0;
  TIMSK2 = 0;

  // Waveform Generation Mode 7, Fast PWM, Top = OCRA
  TCCR2A |= (3 << WGM20);
  TCCR2B |= (1 << WGM22);

  // Output Frequency = 8MHz / Divide_Variable
  // Divide_Variable 1 ~ 256
  if (Divide_Variable < 1)
  {
    Divide_Variable = 1;
  }
  if (256 < Divide_Variable)
  {
    Divide_Variable = 256;
  }  

  OCR2A = (Divide_Variable - 1);
}

void Geekble_Oscillator::Run(uint8_t On_Off)
{
  if (On_Off == 1)
  {
    DDRB |= (1 << PINB3);
    TCCR2A |= (1 << COM2A0);  // Clear OC2A on compare match when up-counting. Set OC2A on compare match when down-counting.
    TCCR2B |= (1 << CS20);
  }
  else
  {
    TCCR2A &= ~(3 << COM2A0); // Normal port operation, OC2A disconnected.
    TCCR2B &= ~(7 << CS20);
  }
}