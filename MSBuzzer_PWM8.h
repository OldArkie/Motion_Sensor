//*************************************************************************
//  Derived class from MSBuzzer_PWM; implements specifics of setup and playing
//  tune note for PWM mode 8.
//*************************************************************************
#ifndef MSBuzzer_PWM8_h
#define MSBuzzer_PWM8_h

#include <MSBuzzer_PWM.h>

class MSBuzzer_PWM8 : public MSBuzzer_PWM
{
  public:
    // constructor
    MSBuzzer_PWM8();
    
    // Required pure virtual interface for setup and note generation
  	virtual void GenerateFreq(unsigned int freqTop, unsigned int freqMax, unsigned int duration);
    virtual void ConfigureTimer(int prescaler);
};

#endif
