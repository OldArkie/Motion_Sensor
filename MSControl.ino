//--------------------------------------------------------------------------------
// Top-level control for an "alarm" application based on motion detection by a 
// Passive Infrared Sensor (PIR).  The processor is put to sleep in POWER-DOWN
// sleep mode until motion is detected.  When motion occurs the PIR generates an
// interrupt when wakes up the processor.  An alarm tune is then played based on
// the setting configuration for a 4-pole DIP switch.  The alarm is played until
// motion ceases.  At that time, the processor is put back to sleep waiting on
// the next occurrence of motion.
//
// The application consists of this arduino (ino) program which provides control
// and several "helper" classes which implement details for the required functions.
// The support classes are placed in an arduino "library"; that is, a sub-folder
// within the user libraries folder.  The application runs on the UNO, ATtiny84,
// and ATtiny85 processors.
//--------------------------------------------------------------------------------
#include <MSPir.h>              // implements PIR functionality
#include <MSSleep.h>            // implements sleep functionality
#include <MSAssignAlarm.h>      // implements assignment of alarm tune
#include <MSDip.h>              // reads current DIP switch setting
#include <MSAlarms.h>           // contains definition of tune snippets for
                                // all possible alarms

// Define buzzer control based on tone generation type.
// The Buzzer class plays the selected alarm tune using the Arduino
// Tone function, PWM mode 8, or PWM mode 9.  Choice is determined
// by defines with default = Tone function.
#if defined(USE_PWM9)
  #include <MSBuzzer_PWM9.h>
  MSBuzzer_PWM9 myBuzzer;      // buzzer control using PWM mode 9 
#elif defined(USE_PWM8)
  #include <MSBuzzer_PWM8.h>
  MSBuzzer_PWM8 myBuzzer;
#else
  #include <MSBuzzer.h>
  MSBuzzer myBuzzer;     // buzzer/speaker control using TONE function 
#endif

//------------------------------------------------------------------------------------------
//  Pin assignment/definition is device specific.  Defined here for UNO (ATmega328P)
//  ATtiny84, and ATtiny45 (and their smaller ram equivalents)
//------------------------------------------------------------------------------------------
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
const unsigned int  PirInterruptPin   = 13;  // PIR state change input
const unsigned int  BuzzerPin         = 10;  // Alarm melody output pin (to piezo buzzer)
const unsigned int  DipPin            = A1;  // DIP switch combined voltage input
const unsigned int  txPin             =  7;  // Transmit pin for SendOnlySoftwareSerial support
#elif defined(__AVR_ATtiny84__)   || defined(__AVR_ATtiny84A__)
const unsigned int  PirInterruptPin   =   3;  // PIR state change input
const unsigned int  BuzzerPin         =   5;  // Alarm melody output pin (OC1B)
const unsigned int  DipPin            =   7;  // DIP switch combined voltage input
const unsigned int  txPin             =  10;  // Transmit pin for SendOnlySoftwareSerial support
#else
  #error DEVICE NOT SUPPORTED BY APPLICATION
#endif

// List of possible alarm tune snippets along with processing parameters.
// The tunes are defined as an array of notes in the Alarms.h header file.
Alarm_Parms Alarms[] = {
// Active?  Identifier    Melody Name     Number of notes in melody           DIP switch setting
    {511, Amazing,          sizeof(Amazing)/sizeof(Music_Note)},           // 0001
    {341, Nobody,           sizeof(Nobody)/sizeof(Music_Note)},            // 0010
    {202, LittleBear,       sizeof(LittleBear)/sizeof(Music_Note)},        // 0100
    {111, DannyBoy,         sizeof(DannyBoy)/sizeof(Music_Note)},          // 1000
    {540, BlankSpace,       sizeof(BlankSpace)/sizeof(Music_Note)},        // 1001
    {632, MockingbirdHill,  sizeof(MockingbirdHill)/sizeof(Music_Note)},   // 1011
    {276, Lion,             sizeof(Lion)/sizeof(Music_Note)},              // 1100
  };

#define NumAlarms      sizeof(Alarms)/sizeof(Alarm_Parms) // number alarm tunes available
#define RandomVoltage  668                                // Identifier for random mode

// Serial output/debugging 
#include <SendOnlySoftwareSerial.h>

// Create objects used for top-level control
MSAssignAlarm alarm(Alarms, NumAlarms);   // Determine which alarm tune has been selected
MSPir   pir(PirInterruptPin);             // PIR input/interrupt control
MSSleep msSleep(SLEEP_MODE_PWR_DOWN);     // Processor sleep control for specified mode
MSDip   dip;                              // DIP switch read of current setting configuration
SendOnlySoftwareSerial mySerial(txPin);   // Arduino transmit only software serial class.
                                          // Example of how to define and use.

// processing variables
int dipVoltage = 0;
int alrm = 0;

//-----------------------------------------------------------------------------------------------
//  Setup for Alarm application.  Initialize control objects.
//-----------------------------------------------------------------------------------------------
void setup()
{
  mySerial.begin(9600);       // Start serial processing; give time for connection to associated COM
  delay(1000);

  pir.Enable(CHANGE);         // Enable PIR interrupt in CHANGE mode
  dip.Init(DipPin);           // Supply input pin for DIP control object initialization
  myBuzzer.Init(BuzzerPin);   // Supply output pin for Buzzer control object initialization
}

//-----------------------------------------------------------------------------------------------
// Processing control loop.
//-----------------------------------------------------------------------------------------------
void loop()
{ 
   // sleep until motion detected; include serial output examples
   mySerial.println("Go To Sleep ");
   msSleep.GoToSleep();                             
   mySerial.println(" woke up");

   // play alarm until no more motion
   while(pir.IsActive())                            
   {  
     // read voltage associated with current DIP settings
     mySerial.print(" sound alarm:  DIP voltage - ");
     dipVoltage = dip.ReadDip();                
     mySerial.print(dipVoltage);

     // find tune associated with voltage
     alrm = alarm.AssignAlarm(dipVoltage);      
     mySerial.print("  Tune - ");
     mySerial.println(alrm);

     // Play alarm tune, if valid
     if(alrm < NumAlarms)                           
     {
        myBuzzer.PlayAlarm(Alarms[alrm].numNotes, Alarms[alrm].alarmMusic);  // play alarm tune via Buzzer
     }

     mySerial.println();   // blank line
   }
}


