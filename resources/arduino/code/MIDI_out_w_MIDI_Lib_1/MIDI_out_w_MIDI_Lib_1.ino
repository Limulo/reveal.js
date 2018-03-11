#include <MIDI.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,10);
MIDI_CREATE_INSTANCE(SoftwareSerial, mySerial, midiSerial);

// -----------------------------------------------------------------------------

uint8_t note = 21;
uint8_t vel = 64;
const int bass = 9;
const int drum = 10;

// setup **********************************************************************/
void setup()
{
    midiSerial.begin();
    Serial.begin(9600);
    Serial.println("Arduino Ready");
    panic();
}


// Loop **********************************************************************/
void loop()
{
  playAllDrums();
  playAllBass();
  return;

  midiSerial.sendNoteOn(69, 127, 9);
  midiSerial.sendNoteOn(69, 127, 10);
  delay(1000);
  midiSerial.sendNoteOff(69, 0, 9);
  midiSerial.sendNoteOff(69, 127, 10);
  delay(1000);
}


// Custom *********************************************************************/
void playAllDrums()
{
  Serial.println("Drums");
  while(note<=108)
  {
    midiSerial.sendNoteOn( note, vel, drum);
    Serial.println( note );
    delay(250);
    midiSerial.sendNoteOff( note, vel, drum);
    note++;
  }
  note = 21;
}

void playAllBass()
{
  Serial.println("Bass");
  while(note<=108)
  {
    midiSerial.sendNoteOn( note, vel, bass);
    Serial.println( note );
    delay(250);
    midiSerial.sendNoteOff( note, vel, bass);
    note++;
  }
  note = 21;
}

// send MIDI note Off massages to all notes on every channels
void panic()
{
  for(int ch=0; ch<16; ch++)
  {
    for(int n=21; n<=108;n++)
    {
      midiSerial.sendNoteOff( n, 0, ch);
    }
  }
}
