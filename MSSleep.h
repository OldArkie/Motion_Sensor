//----------------------------------------------------------------------------
// Class definition for object used to encapsulate sleep processing for
// Motion Sensor object.  Puts processor to sleep in specified mode.
//----------------------------------------------------------------------------
#ifndef MSSleep_h
#define MSSleep_h

class MSSleep
{
  public:
    MSSleep(int mode);
    void GoToSleep();
	
  private:
    int _mode; 
    int	_sleepPin;
};

#endif
