# Motion_Sensor
This repository contains the files/classes for implementation of an "Alarm" system based on motion detection via a PIR and alarm tune selection via a DIP switch.  The possible tune snippets which can played for the alarm are contained in an alarm tune array.  The control flow is described below:

  . Upon startup, the processor is put to sleep in POWER_DOWN mode
  
  . When motion is detected by the PIR, a pin change interrupt is generated
  
  . The interrupt wakes up the processor
  
  . Alarm tune selection is based on the composite settings for a 4-unit DIP switch
  
    . an analogRead is issued to obtain the unique integer identifier for the DIP switch configuration
    
    . If the identifier indicates Random/Shuffle mode, a random number is generated and used
      as the tune list index for the tune to play as the alarm.
      
    . If the identifier is not for the random mode, the tune list is searched for a match.
      If a match is found, the index of the matching tune list entry is used for the tune to play as the alarm
      
    . If the index is less than or equal to the num tunes (actually num tunes - 1), the associated tune is played
    
  . The PIR stays on for a period of time based on the physical setting of an on-board potentiometer.  When the
    time period expires, the PIR turns off and generates a second interrupt. The PIR stays on as long as motion is detected
    AND until it times out.
    
  . The selected tune is played as long as the PIR is on
  
  . The processor is put back to sleep and the processing cycle repeats
  
  
  The following files/classes are used to implement the Motion Sensor Alarm processing:
  1. 
