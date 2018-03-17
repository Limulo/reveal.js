#include <AltSoftSerial.h>
AltSoftSerial midiSerial;

// #define RXPIN 8
// #define TXPIN 9

// SETUP ///////////////////////////////////////////
void setup()
{
  Serial.begin( 9600 );
  midiSerial.begin(31250);
}

// LOOP ////////////////////////////////////////////
void loop()
{  
  while( midiSerial.available() > 0 )
  {
    int incomingByte = midiSerial.read();
    midiSerial.write( incomingByte );
    Serial.println( incomingByte, DEC );
  }
}
