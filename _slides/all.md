# Introduzione


<!-- .slide: data-background-color="#fff" -->
![MIDI logo](images/MIDI_logo.jpg)<!-- .element: style="width:50%;" -->


<!-- .slide: data-background-size="contain" data-background-color="#000" data-background-image="images/moog.jpg" -->
<!-- 1964 - moog -->


<!-- .slide: data-background-color="#fff" -->
<svg width="100%" viewBox="0 0 1024 744.09">

  <svg class="fragment" data-fragment-index="4">
    <use xlink:href="images/MIDI_birthday.svg#others">
  </svg>

  <svg class="fragment" data-fragment-index="3">
    <use xlink:href="images/MIDI_birthday.svg#sci">
  </svg>

  <svg class="fragment" data-fragment-index="2">
    <use xlink:href="images/MIDI_birthday.svg#oberheim">
  </svg>

  <svg data-fragment-index="1">
    <use xlink:href="images/MIDI_birthday.svg#roland">
  </svg>

</svg>


![Roland Jupiter6](images/roland_jupiter6.jpg)


![Roland prophet600](images/prophet_600.jpg)


![Roland tr909](images/roland_tr909.jpg)



<!-- .slide: data-background-color="#fff" -->
![DIN 5 pin](images/DIN5pin.jpg)<!-- .element: style="width:50%;" -->


<!-- .slide: data-background-color="#fff" -->
<svg width="100%" viewBox="0 0 827.14 236.30">

  <svg class="fragment" data-fragment-index="4">
    <use xlink:href="images/bit_bytes.svg#byte2">
  </svg>

  <svg class="fragment" data-fragment-index="5">
    <use xlink:href="images/bit_bytes.svg#nibbles">
  </svg>

  <svg class="fragment" data-fragment-index="3">
    <use xlink:href="images/bit_bytes.svg#byte1">
  </svg>

  <svg class="fragment" data-fragment-index="2">
    <use xlink:href="images/bit_bytes.svg#bit2">
  </svg>

  <svg data-fragment-index="1">
    <use xlink:href="images/bit_bytes.svg#bit1">
  </svg>

</svg>



## Esperimento 1

### Obiettivi<!-- .element: class="fragment" -->

* connettere un dispositivo MIDI trasmittente ad Arduino;<!-- .element: class="fragment" -->
* connettere Arduino al PC per monitorare i messaggi in arrivo;<!-- .element: class="fragment" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-studio-in.png" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="resources/datasheets/Arduino_Uno_Rev3-schematic.jpg" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/UNO.jpg" -->


### Il circuito


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/wikipedia_MIDI_IN_OUT_schematic.jpg" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/perotti_schematics.jpg" -->


#### Optoaccoppiatore (optoisolatore)

<!-- .slide: data-background-size="contain" data-background-color="#fff"-->
![optoaccoppiatore](images/Optoisolator_Pinout.png)


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI_IN_bb_new.png" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff"-->
![optoaccoppiatore](images/6n138-overview.png)


### Il codice


**Software Serial**


<code>
    #include <SoftwareSerial.h>

    const byte rxPin = 11;
    const byte txPin = 10; // not used for the moment

    SoftwareSerial mySerial(rxPin, txPin);

    // SETUP ///////////////////////////////////////////
    void setup()
    {
      pinMode( rxPin, INPUT );
      pinMode( txPin, OUTPUT);
      mySerial.begin( 31250 );

      Serial.begin( 9600 );
    }

    // LOOP ////////////////////////////////////////////
    void loop()
    {
      while( mySerial.available() > 0 )
      {
        unsigned char c = mySerial.read();
        Serial.println( c, DEC );
      }
    }
</code>


### Analisi dei messaggi


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/serial-monitor-1.png" -->



<!-- .slide: data-background-color="#fff" -->
![status and data](images/status-and-data.png)<!-- .element: style="width:90%;" -->


<!-- .slide: data-background-color="#fff" -->
![status and data bits](images/status-and-data-bits.png)<!-- .element: style="width:50%;" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/note_numbers.png" -->


#### Osservazioni: Note ON & Note Off


<!-- .slide: data-background-color="#fff" -->
![note on bytes](images/note_on_bytes.png)<!-- .element: style="width:90%;" -->


<!-- .slide: data-background-color="#fff" -->
![note off bytes](images/note_off_bytes.png)<!-- .element: style="width:90%;" -->


#### Osservazioni: Running status



## Esperimento 2

### Obiettivi<!-- .element: class="fragment" -->

* connettere un dispositivo MIDI ricevente ad Arduino;<!-- .element: class="fragment" -->
* inviare messaggi al dispositivo programmaticamente;<!-- .element: class="fragment" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-studio-out.png" -->


### Il circuito


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/wikipedia_MIDI_IN_OUT_schematic.jpg" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/perotti_schematics.jpg" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI_OUT_bb_new.png" -->


### Il codice


<code>
    #include <SoftwareSerial.h>

    const byte rxPin = 11; // not used for the moment
    const byte txPin = 10;

    SoftwareSerial mySerial(rxPin, txPin);

    int dly = 100;
    int note, velocity;

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
     note = random(24)+60;
     velocity = 127;

     // note On
     mySerial.write(144);
     mySerial.write(note);
     mySerial.write(velocity);

     delay(dly);

     velocity = 0;

     // note Off
     mySerial.write(144);
     mySerial.write(note);
     mySerial.write(velocity);

     delay(dly);
    }
</code>


Non suona! perchè?


<!-- .slide: data-background-color="#fff" -->
![status and data bits](images/MIDI-channels.png)<!-- .element: style="width:90%;" -->


<!-- .slide: data-background-color="#fff" -->
![status and data bits](images/nibbles.png)<!-- .element: style="width:50%;" -->


* cambiare il canale sul ricevitore;
* cambiare il canale sul trasmettitore (Arduino);


<code>
    #include <SoftwareSerial.h>

    const byte rxPin = 11; // not used for the moment
    const byte txPin = 10;

    SoftwareSerial mySerial(rxPin, txPin);

    int dly = 100;
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
     note = random(24)+60;
     velocity = 127;

     // note On
     mySerial.write(144 + (ch-1));
     mySerial.write(note);
     mySerial.write(velocity);

     delay(dly);

     velocity = 0;

     // note Off
     mySerial.write(144 + (ch-1));
     mySerial.write(note);
     mySerial.write(velocity);

     delay(dly);
    }
</code>



## Esperimento 3: recap.

### Obiettivi<!-- .element: class="fragment" -->

* connettere un dispositivo MIDI trasmittente ad Arduino;<!-- .element: class="fragment" -->
* connettere un dispositivo MIDI ricevente ad Arduino;<!-- .element: class="fragment" -->
* usare Arduino come ripetitore/modificatore dei messaggi MIDI di passaggio;<!-- .element: class="fragment" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-studio-in-out.png" -->


### Il circuito


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI_IN_OUT_bb_new.png" -->


### Il cocice


Libreria **AltSerial**


<code>
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
</code>



## Ricapitolando


## Componenti necessarie

* un optoisoltaore [**6N138**](http://www.vishay.com/docs/83605/6n138.pdf) oppure [4n28](http://www.vishay.com/docs/83725/4n25.pdf);
* un diodi ad alta velocità [**1N4148**](https://en.wikipedia.org/wiki/1N4148);
* quattro resistori da **220 Ohm**;
* due connettori **5 pin DIN**;
* due **LED** rossi e due reistori da **220 Ohm** (opzionali);
* cavetti, breadboard, Arduino;
