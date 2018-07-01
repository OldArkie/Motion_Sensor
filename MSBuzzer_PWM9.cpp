//********************************************************************************************
//  Derived class for implentation of Motion Sensor alarm using PWM Mode 8
//********************************************************************************************
#include <Arduino.h>
#include "MSBuzzer_PWM9.h"
#include <MSMacros.h>

//********************************************************************************************
//  Constructor
//********************************************************************************************
MSBuzzer_PWM9::MSBuzzer_PWM9()
{
  // PWM9 implemented for UNO and ATtiny84.  Pins used are device specific
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
  pinMode(10, OUTPUT);  // OC1B
#elif defined(__AVR_ATtiny84__)   || defined(__AVR_ATtiny84A__)
  pinMode(5, OUTPUT);  // OC1B
#else 
    #error Device not supported by application
#endif
}

//*****************************************************************************************************
//  Configure Timer1 for PWM
//*****************************************************************************************************
void MSBuzzer_PWM9::ConfigureTimer(int prescalerWgm)
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

  // waveform generator mode = "PWM Phase and Frequency Correct with OCR1A=TOP" (mode 9)
  // B channel is output; OCR1A holds TOP value
  //    WGM13        WGM12      WGM11     WGM10
  //      1            0          0         1
  MYTCCR1A |= (1<<WGM10);
  MYTCCR1B |= (1<<WGM13);
  
  // Configure output B (OC1B) as non-inverting (mode 2)
  // Output channel A is disabled  (mode 0)
  //   COM1A1   COM1A0    COM1B1         COM1B0
  //     0         0        1             0
  MYTCCR1A |= (1<<COM1B1);
  MYTCCR1B |= prescalerWgm;

  // Set the actual TIMER1 hardware configuration registers
  TCCR1A = MYTCCR1A;
  TCCR1B = MYTCCR1B;
}


//*****************************************************************************************************
//  Generate note frequency on OC1B output pin for PWM mode 9
//*****************************************************************************************************
void MSBuzzer_PWM9::GenerateFreq(unsigned int freqTop, unsigned int freqMax, unsigned int duration)
{
  // configure registers for specific PWM mode and play the specified note
  OCR1A = freqTop;
  OCR1B = freqMax;

  // delay specified duration - set in definition of tune
  delay(duration);
  
  // stop playing of the note
  OCR1A = 0;
  OCR1B = 0;

  // silence so that notes won't run together
  delay(.25*duration);
}
