//-----------------------------------------------------------------
// Used in Random/Shuffle mode to randomly select the index of the
// tune to play for the alarm.
//-----------------------------------------------------------------
#include <Arduino.h>
#include <MSRandomAlarm.h>
#include <avr/sleep.h>
#include <MSMacros.h>

// constructor
MSRandomAlarm::MSRandomAlarm()
{
  _min       = 0;   // starting index for alarm tune is entry 0
}

// Called to start the random number generator; supplies max
// value for the generator.
void MSRandomAlarm::Start(int maxValue)
{
  _max = maxValue;
   unsigned long seed = seedOut(31);   // generate random seed value
   randomSeed(seed);
}

// External interface to obtain the index of alarm tune
unsigned long MSRandomAlarm::RandValue()
{
	return(random(_min, _max));
}

// generate seed for random number generator
unsigned long MSRandomAlarm::seedOut(unsigned int noOfBits)
{
  // return value with 'noOfBits' random bits set
  unsigned long seed=0;

  for (int i=0;i<noOfBits;++i)
  {
    seed = (seed<<1) | bitOut();
  }
  return seed;
}


unsigned int MSRandomAlarm::bitOut()
{
  static unsigned long firstTime=1, prev=0;
  unsigned long bit1=0, bit0=0, x=0, port=0, limit=99;
  if (firstTime)
  {
    firstTime=0;
    prev=analogRead(port);
  }
  while (limit--)
  {
    x=analogRead(port);
    bit1=(prev!=x?1:0);
    prev=x;
    x=analogRead(port);
    bit0=(prev!=x?1:0);
    prev=x;
    if (bit1!=bit0)
      break;
  }
  return bit1;
}