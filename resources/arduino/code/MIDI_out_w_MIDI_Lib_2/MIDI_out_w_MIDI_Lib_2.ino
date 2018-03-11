#include <MIDI.h>
#include "midinotes.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,10);
MIDI_CREATE_INSTANCE(SoftwareSerial, mySerial, midiSerial);

// -----------------------------------------------------------------------------

uint8_t note;
uint8_t vel;
#define BOTTOMNOTE 21
#define TOPNOTE 108
#define BASS 9
#define DRUMS 10
#define KICK  36
#define SNARE 38
#define HIHAT 42
bool drums = true;
bool bass = false;

// setup **********************************************************************/
void setup()
{
    midiSerial.begin();
    Serial.begin(9600);
    Serial.println("Arduino Ready");
    for(int ch=0; ch<16; ch++)
    {
      panic((uint8_t)ch);
    }

    note = NOTE_C2;
    vel = 64;
}


// Loop **********************************************************************/
void loop()
{
  if(drums) midiSerial.sendNoteOn(KICK, vel, DRUMS);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(SNARE, vel, DRUMS);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(KICK, vel, DRUMS);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(KICK, vel, DRUMS);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(SNARE, vel, DRUMS);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
  if(drums) midiSerial.sendNoteOn(HIHAT, vel, DRUMS);
  if(bass)  midiSerial.sendNoteOn(note, vel, BASS);
  delay(250);
}


// Custom *********************************************************************/
// send MIDI note Off massages to all notes on a specific channel
void panic(uint8_t channel)
{
  for(int n=BOTTOMNOTE; n<=TOPNOTE;n++)
  {
    midiSerial.sendNoteOff( n, 0, channel);
  }
}

void serialEvent()
{
  char c = Serial.read();
  if(c == ' ')
  {
    for(int ch=0; ch<16; ch++)
    {
      panic((uint8_t)ch);
    }
    drums=false;
    bass=false;
  }
  else if(c == '1')
  { 
    drums = !drums;
    //if(!drums) panic( DRUMS );
  }
  else if(c == '2')
  { 
    bass = !bass;
    //if(!bass) panic( BASS );
  } 
  else if(c == 'c')
    note = NOTE_C2;
  else if(c == 'd')
    note = NOTE_D2;
  else if(c == 'e')
    note = NOTE_E2;
  else if(c == 'f')
    note = NOTE_F2;
  else if(c == 'g')
    note = NOTE_G2;
  else if(c == 'a')
    note = NOTE_A2;
  else if(c == 'b')
    note = NOTE_B2;
}

