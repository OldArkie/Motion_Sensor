//******************************************************************
//  Class definition for base class PWM processing.  Provides common
//  PWM processing and defines pure virtual interface that must be
//  implemented by derived classes for processing specific PWM modes.
//******************************************************************
#ifndef MSBuzzer_PWM_h
#define MSBuzzer_PWM_h

#include <MSBuzzer.h>
#include <MSPitches.h>

class MSBuzzer_PWM : public MSBuzzer
{
  public:
    MSBuzzer_PWM();                                           // constructor
    unsigned int determinePrescaler(int desiredFreq);         // determine PWM prescaler
    void PlayNote(int  freq, int  power, int  freqDuration);  // framework for playing a tune note
    void Init(int pin);                                       // initialization for PWM processing
    
    // Pure virtual interface which must be implemented by derived classes to
    // implement specific PWM mode processing.
    virtual void GenerateFreq(unsigned int top, unsigned int max, unsigned int duration) = 0;
    virtual void ConfigureTimer(int prescaler) = 0;

  private:
	  int _smallestFreq    = NOTE_C3;
    int _prescaler       = 0;
    int _prescalerIndex  = 0;



};

#endif
