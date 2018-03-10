# Intro


<!-- .slide: data-background-size="contain" data-background-color="#000" data-background-image="images/moog.jpg" -->
<!-- 1964 - moog -->


modulare, control voltage


da monofonici a polifonici


generazione analogica del suono ma aggiunta di memorie per salvare le impostazioni dei controlli (ora digitali)


inizi anni '80 trasformazione digitale completa



## MIDI


1981 - Sequential Circuit propone una prima ipotesi di protocollo MIDI


1982 - in collaborazione con Korg, Yamaha, Roland, Kawai


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/general-midi-logo.png" -->


<!-- .slide: data-background-size="contain" data-background-color="#000" data-background-image="images/prophet_600.jpg" -->


dal 1984 indicativamente tutti i produttori che usino il MIDI sono tenuti ad attenersi alle specifiche per garantire compatibilità  



## Dati!


informazione digitale / analogica


unità base il bit, byte, nibble


comunicazione seriale/parallela ?


con 8 bit a disposizione si rappresentano da 0 a 255



## Esperimento 1


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-studio-in.png" -->


### Il circuito


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-IN_bb.png" -->


che cosa è un optoaccoppiatore.


### Il codice


La libreria **Software Serial**


### analisi dei messaggi


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/serial-monitor-1.png" -->



#### Status Byte / data Byte


<!-- .slide: data-background-color="#fff" -->
![status and data](images/status-and-data.png)<!-- .element: style="width:90%;" -->


<!-- .slide: data-background-color="#fff" -->
![status and data bits](images/status-and-data-bits.png)<!-- .element: style="width:50%;" -->


<!-- .slide: data-background-color="#fff" -->
![status and data bits](images/nibbles.png)<!-- .element: style="width:50%;" -->


<!-- .slide: data-background-color="#fff" -->
![status and data bits](images/MIDI-channels.png)<!-- .element: style="width:90%;" -->


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/note_numbers.png" -->


#### Osservazioni: Note ON & Note Off


#### Osservazioni: Running status



## Esperimento 2


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-studio-out.png" -->


### Il circuito


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-OUT_bb.png" -->


### Il codice



## Esperimento 3: recap.


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-studio-in-out.png" -->


### Il circuito


<!-- .slide: data-background-size="contain" data-background-color="#fff" data-background-image="images/MIDI-IN-OUT_bb.png" -->


### Il cocice


Libreria **AltSerial**
