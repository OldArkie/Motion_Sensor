//------------------------------------------------------------------------------
//  Macros to support Motion Sensor application processing
//------------------------------------------------------------------------------
#ifndef MSMacros_h
#define MSMacros_h

// blinks led at specified pin for specified number of
// times with specified delay between blinks
#define BLINKIT(numBlinks, pinNum, delayMs)       \
 for (int kk=0; kk<numBlinks; kk++)               \
 {                                                \
	 digitalWrite(pinNum, HIGH);                    \
	 delay(delayMs);                                \
	 digitalWrite(pinNum, LOW);                     \
	 delay(delayMs);                                \
 }
 
 // Macros which are only defined in "DEBUGGING" mode
#ifdef DEBUGGING                                 
 #define TEST_BLINK(numBlinks, pinNum, delayMs)   \
  for (int kk=0; kk<numBlinks; kk++)              \
  {                                               \
    digitalWrite(pinNum, HIGH);                   \
    delay(delayMs);                               \
    digitalWrite(pinNum, LOW);                    \
    delay(delayMs);                               \
  }                                 
  
 #define LEDWrite(ledPin, value) digitalWrite(ledPin, value) 
 #define PINMODE(ledPin, mode)   pinMode(ledPin, mode)
 #else
 #define TEST_BLINK(numBlinks, pinNum, delayMs)
 #define LEDWrite(ledPin, value)
 #define PINMODE(ledPin, mode)
#endif                            


// Use of Serial output depends on device type
#if defined(DEBUGGING) && (defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__))
#define SERIALPrintln(value) Serial.println(value)
#define SERIALBegin(value)   Serial.begin(value)
#else
#define SERIALPrintln(value)
#define SERIALBegin(value)
#endif

// Compare two "voltages" to see if within 10 of each other
#define VoltageCompare(cur, prev)  (abs(cur-prev)<=10 ? true : false)

#endif

