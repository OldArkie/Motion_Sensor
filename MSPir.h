//----------------------------------------------------------------------------
// Class definition for PIR interrupt control for Motion Sensor application.
//----------------------------------------------------------------------------
#ifndef MSPir_h
#define MSPir_h

class MSPir
{
  public:
    MSPir(int interruptPin);
    void Enable(int mode);
    bool IsActive();
	
  private:
    int					_interruptPin; 
    uint8_t 		_ledPort;	
    static void PIRchangeISR();
};

#endif
