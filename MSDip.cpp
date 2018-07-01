//------------------------------------------------------------------------
// Class definition for DIP processing within the Motion Sensor application.
// The DIP switch is used to supply a unique representation of the current
// 4 pole DIP switch setting.
//-------------------------------------------------------------------------
#include <Arduino.h>
#include <MSDip.h>

// constructor
MSDip::MSDip()
{
}

// initialization function to supply the device pin used to read the DIP switch
// The pin must support analog read functionality.
void MSDip::Init(int pin) 
{
  _dipPin = pin;  
  pinMode(_dipPin, INPUT);
}

// read and return the current voltage output of the DIP switch.  
int MSDip::ReadDip()
{
  _curVoltage = analogRead(_dipPin);  
  return(_curVoltage);
}

