#include <SoftwareSerial.h>

const byte txPin = 10;
const byte rxPin = 11; // not used for the moment

SoftwareSerial mySerial(rxPin, txPin);

int dly = 1000;
int note, velocity;
int ch = 9;

// SETUP ///////////////////////////////////////////
void setup()
{
 pinMode( rxPin, INPUT );
 pinMode( txPin, OUTPUT);
 mySerial.begin( 31250 );
}

// LOOP ////////////////////////////////////////////
void loop()
{
 note = random(24)+34;
 velocity = 127;

 // note On
 mySerial.write(144 + (ch-1) );
 mySerial.write(note);
 mySerial.write( velocity );

 delay(dly);

 velocity = 0;

 // note Off
 mySerial.write(144 + (ch-1));
 mySerial.write(note);
 mySerial.write( velocity );

 delay(dly);
}
