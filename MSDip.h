//------------------------------------------------------------------------
// Class definition for DIP processing within the Motion Sensor application.
// The DIP switch is used to supply a unique representation of the current
// 4 pole DIP switch settings.
//-------------------------------------------------------------------------
#ifndef MSDip_h
#define MSDip_h

class MSDip
{
  public:
    MSDip();                // constructor
	int ReadDip();            // read current DIP switch setting
	void Init(int dipPin);    // Initialization function to supply input pin
 
  private:
    int _dipPin;
	long _curVoltage;
};

#endif
