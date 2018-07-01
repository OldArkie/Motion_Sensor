//----------------------------------------------------------------------------------------
// Support class for putting processor to sleep.  Sleep mode is constructor parameter.
//----------------------------------------------------------------------------------------
#include <Arduino.h>
#include <MSSleep.h>
#include <avr/sleep.h>

//----------------------------------------------------------------------------------------
// Constructor
//   . input parameter: sleep mode
//   . mode saved and serial (singleton) class reference defined in initializer list
//----------------------------------------------------------------------------------------
MSSleep::MSSleep(int mode) : _mode(mode) //,                         // Save sleep mode
                             //mySerial(MSSerial::getInstance())    // define serial singleton reference
{
}

//----------------------------------------------------------------------------------------
// Put the processor to sleep.  Wakes up when external interrupt occurs.
//-----------------------------------------------------------------------------------------
void MSSleep::GoToSleep()
{
  //mySerial.println(" MSSLEEP: sleep");   // example of serial output within a support class
   
  // Put processor to sleep in pre-specified mode
  sleep_enable();           // enable the sleep mode
  set_sleep_mode(_mode);    // set the  sleep type to mode specified during construction
  sleep_cpu();              // enter sleep mode. (Next code executed - ISR when interrupt wakes processor)
  sleep_disable();          // returns here after interrupt; disable sleep mode
  
  //mySerial.println(" MSSLEEP: wake up");   // example of serial output within a support class
}