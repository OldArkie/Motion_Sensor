//----------------------------------------------------------------
//  Definition of class used to assign the tune to be played
//  as an "alarm" based on the current DIP settings.
//----------------------------------------------------------------
#ifndef MSAssignAlarm_h
#define MSAssignAlarm_h

#include <MSAlarmTypes.h>     // Alarm processing support structures

class MSAssignAlarm
{
  public:
    MSAssignAlarm(Alarm_Parms* alarms, int numAlarms);    // constructor
    int AssignAlarm(int dipVoltage);                      // Assign alarm tune
 
  private:
    long 	assignedAlarm;            // alarm tune list entry number
    long 	prevAlarm;                // previously assigned tune number
    Alarm_Parms*  _alarmList;       // pointer to list of available alarm tunes
    int   _numAlarms;               // number of available alarm tunes
	
    int assignAlarmBasedOnDIP(int dipVoltage);    // look for tune in available melody list
    int assignRandomAlarm();                      // assign tune at random
};

#endif
