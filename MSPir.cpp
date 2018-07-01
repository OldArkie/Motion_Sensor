//------------------------------------------------------------------------------------------------
// Control and ISR for the PIR used in the Motion Sensor application.
// The PIR generates an interrupt when motion is detected and then
// stays active for a period of time controlled by it's potentiometer settings.
// A second interrupt is generated when the PIR times out.
//------------------------------------------------------------------------------------------------
#include <Arduino.h>
#include <MSPir.h>
#include <EnableInterrupt.h>
#include <MSMacros.h>

// Constructor. supplies pin used for PIR interrupt when motion detected
MSPir::MSPir(int interruptPin) : _interruptPin(interruptPin)
{
   pinMode(interruptPin, INPUT);
}

// Enable/Init function which supplies the interrupt mode.  The ISR is
// enabled for this mode.
void MSPir::Enable(int mode)
{
  // Enable Pin Change interrupts on PIR input pin
  enableInterrupt(_interruptPin, PIRchangeISR, mode);
}

// Returns a PIR Active/not Active indicator
bool MSPir::IsActive()
{
	return(digitalRead(_interruptPin));
}

//----------------------------------------------------------------------------------------------------
//  ISR invoked when PIR state changes i.e. it turns on or off
//----------------------------------------------------------------------------------------------------
static void MSPir::PIRchangeISR()
{
}