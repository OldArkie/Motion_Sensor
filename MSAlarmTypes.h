//------------------------------------------------------------------------------------------
// Support structures for processing of alarms
//------------------------------------------------------------------------------------------
#ifndef MSAlarmTypes_h
#define MSAlarmTypes_h

// Musical Note parameter definition 
typedef struct Music_Note 
{
    int note;         // note frequency
    int duration;     // note duration
} Music_Note;

// PWM prescaler parameters
typedef struct Prescale_Config
{
	int           value;     // prescaler value (1,8,64,etc.)
	unsigned char wgm;       // associated control register WGM bits configuration for the prescaler
} Prescale_Config;

// Processing parameter structure for alarm tune
typedef struct Alarm_Parms
{
  long                voltage;      // value from voltage divider associated with the switch position
  const Music_Note*   alarmMusic;   // pointer to the array of alarm notes
  int                 numNotes;     // number of notes in the alarm
} Alarm_Parms;


#endif