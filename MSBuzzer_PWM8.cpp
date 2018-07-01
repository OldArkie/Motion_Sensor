//********************************************************************************************
//  Derived class for implentation of Motion Sensor alarm using PWM Mode 8
//********************************************************************************************
#include <Arduino.h>
#include "MSBuzzer_PWM8.h"
#include <MSMacros.h>


//********************************************************************************************
//  Constructor
//********************************************************************************************
MSBuzzer_PWM8::MSBuzzer_PWM8()
{
  // PWM8 implemented for UNO and ATtiny84.  Pins used are device specific
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
  pinMode(9,  OUTPUT);  // OC1A
  pinMode(10, OUTPUT);  // OC1B
#elif defined(__AVR_ATtiny84__)   || defined(__AVR_ATtiny84A__)
  pinMode(6,  OUTPUT);  // OC1A
  pinMode(5, OUTPUT);  // OC1B
#else 
  #error Device not supported by application
#endif
}

//*****************************************************************************************************
//  Configure Timer1 for PWM mode 8
//*****************************************************************************************************
void MSBuzzer_PWM8::ConfigureTimer(int prescalerWgm)
{
  //                               TCCR1A
  //  --------------------------------------------------------------------------
  //  |  COM1A1 | COM1A0 | COM1B1| COM11B0 | UNUSED  | UNUSED |  WGM11 | WGM10 |
  // --------------------------------------------------------------------------
  //
  //                               TCCR1B
  //  --------------------------------------------------------------------------
  //  |  ICNC1  | ICES1  | UNUSED|  WGM13  |  WGM12  |  CS12  |   CS11 |  CS10 |
  //  --------------------------------------------------------------------------
  //       
  // local variables collect the Timer1 PWM configuration bits before 
  // assigning the completed value to the hardware registers  
  byte MYTCCR1A = 0;
  byte MYTCCR1B = 0;

  // waveform generator mode = "PWM Phase and Frequency Correct with ICR1=TOP" (mode 8)
  // both A and B channels are output; OCR1A
  //    WGM13        WGM12      WGM11     WGM10
  //      1            0          0         0
  MYTCCR1B |= (1<<WGM13);
  
   // Configure outputs A/B (OC1A/OC1B) as non-inverting (mode 2)
  //   COM1A1   COM1A0    COM1B1         COM1B0
  //     1         0        1             0
  MYTCCR1A |= ((1<<COM1B1) + (1<<COM1A1));
  MYTCCR1B |= prescalerWgm;

 // Set the actual TIMER1 hardware configuration registers
  TCCR1A = MYTCCR1A;
  TCCR1B = MYTCCR1B;
}


//*****************************************************************************************************
//  Generate note frequency on OC1A/OC1B output pins for PWM mode 8
//*****************************************************************************************************
void MSBuzzer_PWM8::GenerateFreq(unsigned int freqTop, unsigned int freqMax, unsigned int duration)
{
  // Define registers used to play note
  OCR1B = freqMax; 
  OCR1A = freqMax; 
  ICR1 = freqTop;
  
  // delay specified duration - set in definition of tune
  delay(duration);
  
  // stop playing of the note
  ICR1         = 0;
  OCR1A        = 0;
  OCR1B        = 0;

  // silence so that notes won't run together
  delay(.25*duration);
}
