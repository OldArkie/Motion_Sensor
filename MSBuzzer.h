//--------------------------------------------------------------------
// Buzzer Control base class definition.  Play tune via Arduino Tone
// function.  Provide virtual functions for use of other methods to 
// play tune.
//--------------------------------------------------------------------
#ifndef MSBuzzer_h
#define MSBuzzer_h

#include <MSAlarmTypes.h>     // Alarm application suport structures

class MSBuzzer
{
  public:
    MSBuzzer();                               // constructor
    void PlayAlarm(int NumberNotes,           // top-level control for playing tune
                   const Music_Note* Notes);
                   
    // Virtual functions to provide implementation of other methods via sub-classes
    virtual char* MSBuzzerType();             // returns id for buzzer type
    virtual void Init(int pin);               // class initialization
    virtual void PlayNote(int buzzerPin,      // Play note of tune based on method
                          int note,
                          int duration);

  private:
    // processing variables
    int               _buzzerPin;
    const Music_Note* _noteAddress;
    Music_Note        _myNote;
	
  
};

#endif
