//*****************************************************************************************************
//  Base class for PWM tune processing; derived from Buzzer class.  Provides common PWM processing 
//  functions.  Provides control framework for playing the tune notes which calls virtual function
//   implemented by the derived classes to generate note frequencies.
//*****************************************************************************************************
#include <Arduino.h>
#include <MSBuzzer_PWM.h>
#include <MSMacros.h>

// List of possible pre-scalers for supported PWM types
static Prescale_Config PrescalerList[] = { {1,0b001}, {8,0b010}, {64,0b011}, {256,0b100}, {1024,0b101}};

// class identifier for debugging
static char _id[] = "PWM BUZZER";

// constructor
MSBuzzer_PWM::MSBuzzer_PWM() 
{
}

// Initialization.  Called with buzzer input pin number. Determines the
// required PWM pre-scaler.  Calls pure virtual function to configure 
// timer 1 for the PWM mode.
void MSBuzzer_PWM::Init(int pin)
{
    pinMode(pin, OUTPUT);
	
    // Determine which PWM prescaler to use based on the desired frequency 
    // Set clock source based on the prescaler value
    //     CS12     CS11      CS10       CLOCK
    //      0        0         0          NONE
    //      0        0         1          F_CPU
    //      0        1         0          F_CPU/8
    //      0        1         1          F_CPU/64
    //      1        0         0          F_CPU/256
    //      1        0         1          F_CPU/1024
    _prescalerIndex = determinePrescaler(_smallestFreq);    // find index of prescaler for smallest required frequency
    _prescaler      = PrescalerList[_prescalerIndex].wgm;   // assign prescaler from list of possible values
  
    ConfigureTimer(_prescaler);
}

//*****************************************************************************************************
//  Determine which PWM prescaler should be applied based the specified frequency
//*****************************************************************************************************
unsigned int MSBuzzer_PWM::determinePrescaler(int desiredFreq)
{
  // Determine prescaler required to generate the specified frequency.
  // Loop through the possible prescaler list until the TOP value
  // associated with the frequency and prescaler is within the 
  // 16-bit size of the configuration register ( <= 65535). The prescaler
  // is defaulted to the largest value if no prescaler meeting requirements
  // is found during the search.
  unsigned int curPrescaler = 0;      // prescaler associated with current prescaler array entry
  long         freqTop      = 65536;  // initial TOP value to assure that enter search loop
  int          listNdx      = -1;     // entry for the required prescaler for the frequency
  int          loopCnt      = 0;
  while( (loopCnt < sizeof(PrescalerList)/sizeof(Prescale_Config)) && (freqTop > 65535))
  {
    curPrescaler = PrescalerList[loopCnt].value;
    freqTop =   long(long(F_CPU)/long(2*curPrescaler*desiredFreq));

    listNdx++;
    loopCnt++;
  }
  
  return(listNdx);
}



//*****************************************************************************************************
//  Common control for playing a tune note.  Calls pure virtual function to actually generate the note
//  frequency.
//*****************************************************************************************************
void MSBuzzer_PWM::PlayNote(int  freq,   // desired frequency to generate
						  int  power,                // desired power level on output channel B (0-100)
						  int  freqDuration)         // duration of the output signal(s) in milliseconds
{
  float        dutyCycle;  
  unsigned int freqMax;
  unsigned int duration;
  unsigned int freqTop;

  // determine the TOP and MAX values for the current note frequency
  if (freq == 0)
  {
    // 0 note represents a REST
    freqTop  = 0;
    freqMax  = 0; 
  }
  else 
  {
    // calculate required TOP value for the frequency
    freqTop = float(float(F_CPU)/(2.0*float(_prescaler)*float(freq)));

    // calculate MAX/power for the A channel
    dutyCycle = float(power)/100.0;
    freqMax  = float(freqTop)*dutyCycle; 
  }

  // call pure virtual function to play the note
  GenerateFreq(freqTop, freqMax, freqDuration);
}

