//--------------------------------------------------------------------------
// class definition for generation of tune to play for an alarm at "random"
//--------------------------------------------------------------------------
#ifndef MSRandomAlarm_h
#define MSRandomAlarm_h

class MSRandomAlarm
{
  public:
    MSRandomAlarm();
    void Start(int maxValue);
    unsigned long RandValue();
	
 
  private:
    unsigned long   _min;
    unsigned long   _max;
    
    unsigned long seedOut(unsigned int noOfBits);
    unsigned int bitOut();
};

#endif
