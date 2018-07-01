//-------------------------------------------------------------------------------------
// Assign the alarm tune based on the current DIP switch settings.  If current setting
// found in the list of possible alarms, return the associated list entry number.  If
// DIP setting indicates random assignment, return a random number between 0 and the
// number of tunes.
//-------------------------------------------------------------------------------------
#include <Arduino.h>          // allows access to arduino environment
#include <MSAssignAlarm.h>    // Alarm detection, activation control
#include <MSRandomAlarm.h>    // Random number between min,max specified at instantiation
#include <MSMacros.h>         // collection of support macros for Motion Sensor Alarm application

#define RandomVoltage  668    // DIP voltage reading associated with random/shuffle mode -
                              // All DIP switches turned on.

// instantiate random number generator for alarm assignment
MSRandomAlarm _randomAlarm;  


//-------------------------------------------------------------------------------------
// constructor
//-------------------------------------------------------------------------------------
MSAssignAlarm::MSAssignAlarm(Alarm_Parms* alarms, int numAlarms) : _alarmList(alarms),
                                                                   _numAlarms(numAlarms)
{
  // initialize internal processing variables
  assignedAlarm = 0;
  prevAlarm     = 0;
  
  // Initialize random number sequence max (min is 0)
  _randomAlarm.Start(numAlarms);
}


//-------------------------------------------------------------------------
//  Find alarm list entry associated with specified DIP voltage.  If
//  the DIP setting indicates RANDOM, assign a tune entry at random.
//-------------------------------------------------------------------------
int MSAssignAlarm::AssignAlarm(int dipVoltage)
{
  // Assign the alarm melody based on the DIP switch settings  
  if(VoltageCompare(dipVoltage, RandomVoltage))
  {
    assignedAlarm = assignRandomAlarm();
  }
  else
  {
    assignedAlarm = assignAlarmBasedOnDIP(dipVoltage);
  }
  
  return(assignedAlarm);
}

//-------------------------------------------------------------------------
// Search tune list for entry associated with dip setting.  If no entry
// is found the value returned is NumAlarms.
//-------------------------------------------------------------------------
int MSAssignAlarm::assignAlarmBasedOnDIP(int dipVoltage)
{
  int alrm = 0;
  
  // search tune list for entry associated with dip setting
  for (alrm = 0; alrm < _numAlarms; alrm++)
  {
    if (VoltageCompare(dipVoltage, _alarmList[alrm].voltage))
    {
      break;
    }
  }
  
  return(alrm);
}

//-------------------------------------------------------------------------
// Choose an alarm melody at random from list of available tunes
//-------------------------------------------------------------------------
int MSAssignAlarm::assignRandomAlarm()
{
   // assign an alarm melody making sure that don't play the previous one
   int alrm = _randomAlarm.RandValue();  // get next number in pseudo-random sequence
   while(alrm == prevAlarm)
   {
     alrm = _randomAlarm.RandValue();    // get next number in pseudo-random sequence
   }
   
   prevAlarm = alrm;                     // keep up with assigned alarm so don't assign
                                         // the same tune twice in a row
   
   return(alrm);
}

