//-------------------------------------------------------------------------
// Buzzer control parent class.  Implements playing of alarm tune via the
// Arduino Tone function.  Provides virtual functions for implementation
// of derived sub-classes.
//-------------------------------------------------------------------------
#include <Arduino.h>          // allows access to arduino environment
#include <MSBuzzer.h>         // Buzzer base class; framework for playing tune
#include <MSPitches.h>        // Note frequency definitions

static char _id[] = "REGULAR BUZZER";  // id used for display/debug

//-------------------------------------------------------------------------
// Constructor
//-------------------------------------------------------------------------
MSBuzzer::MSBuzzer()
{
}

//-------------------------------------------------------------------------
// Initialization routine used to set pin used for output to buzzer.
// Must be called before buzzer object is used.
//-------------------------------------------------------------------------
void MSBuzzer::Init(int buzzerPin)
{
  pinMode(buzzerPin, OUTPUT);
  _buzzerPin = buzzerPin;
}

//-------------------------------------------------------------------------
// return buzzer type id for display
//-------------------------------------------------------------------------
char* MSBuzzer::MSBuzzerType()
{
	return(_id);
}

//-------------------------------------------------------------------------
// top-level control routine for playing of tune.  Provides
// common processing and calls virtual routine for playing
// of tune notes.
//-------------------------------------------------------------------------
void MSBuzzer::PlayAlarm(int NumberNotes, const Music_Note* Notes)
{
  int noteDuration = 0;        // 1==whole note; 2=half note; 4=quarter note; etc
  int Tempo        = 120;      // default tempo to 120 beats/minute
  int volume       = 50;       // default volume to 1/2 range
  
  // Loop through notes in tune definition.  Handle special cases
  // and call virtual routine to play the note(s).
  for (int thisNote = 0; thisNote < NumberNotes; thisNote++)
  {
    // Retrieve next note in the melody from flash
    _noteAddress = &Notes[thisNote];
    memcpy_P(&_myNote, _noteAddress, sizeof(Music_Note));

    if (_myNote.note == NOTE_TEMPO)
    {
      Tempo = _myNote.duration;
    }
    else if (_myNote.note == NOTE_POWER)
    {
      volume = _myNote.duration;
    }
    else
    {
		  // Play the retrieved note for the duration based on a 1 second max 
		  // Duration is based on the note type and the current Tempo
		  //  Note type is standard musical notation e.g. 4=quarter note, 8=eighth note
		  //  Tempo is implemented as a ratio of the specified tempo to the standard 120 beat tempo.
		  //    note duration = (one second*(tempo/120))/note type
		  noteDuration = ((1000.0/float(Tempo))*120.0)/float(_myNote.duration) + 1;
		  PlayNote(_myNote.note, volume, noteDuration);
    }
  }
}

//-------------------------------------------------------------------------
// Implement playing of note using Arduino Tone function.  This is a
// virtual routine implemented by sub-classes to provide required
// processing for playing a note.
//-------------------------------------------------------------------------
void MSBuzzer::PlayNote(int note, int volume, int duration)
{
    tone(_buzzerPin, note, duration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    delay(duration * 1.25);

    // stop the tone playing
    noTone(_buzzerPin);
}
