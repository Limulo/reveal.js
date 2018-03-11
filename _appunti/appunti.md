# Intro

Che cos'è il MIDI?

Si tratta di uno standard tecnico che descrive un protocolllo di comunicazione, una interfaccia digitale e connettori elettrici e permette ad una grande varietà di strumenti musicali elettronici, computer ed altri apparati, di comunicare tra loro.

Il MIDI si è standardizzato negli anni '80 ma certo non è stato il primo sistema di comunicazione tra dispositivi elettronici associati alla musica.

Già dal momento della sua nascita (1964 circa), il sintetizzatore, uno strumento musicale elettronico in grado di generare sonorità particolari, era un dispositivo modulare. Costituito cioè da diversi componenti indipendenti, ognuno predisposto per apportare una particolare lavorazione al segnale elettrico.

Per ottenere un suono i diversi componenti dovevano essere connessi tra loro utilizzando appositi cavi chiamati pathcords.

Il sistema di controllo allora era basato sul voltaggio (control voltage): variazioni di tenzione, propagate lungo i patchcords, permettevano ad un modulo di controllare il modulo successivo e indurre una particolare modificazione al segnale audio di passaggio.

Con il passare del tempo i sintetizzatori, da monofonici, divennero polifoni e in seguito, con l'avvento dell'era digitale, si arricchirono della capacità di memorizzare le impostazioni per i propri controlli: se la sintesi del suono rimaneva analogica, i controlli, ora digitali, potevano essere letti e immagazzinati sulle memorie RAM, da poco entrate sul mercato.

Agli inizi degli anni '80 la trasformazione digitale è ormai completa ma resta ancora una difficoltà mai completamente risolta: come permettere la comunicazione tra strumenti musicali di marche differenti?

Ogni costruttore adottava un standard proprietario, coerente su tutti i prodotti della proprio catalogo, ma incompatibile spesso con i prodotti di altri costruttori.

Nel Giugno del 1981 il fondatore di Roland propone una standardizzazione al fondatore di Oberheim, il quale a sua volta ne discute con il presidende della Sequential Circuit Inc. Nell'ottobre dello stesso anno se ne parla poi con i rappresentati di Yamaha, Korg e Kawai.

Fu così che nel 1982 lo standard entro sul mercato con i primi due sintetizzatori il Roland Jupiter-6 e il Roland Prophet 600. Seguirono a ruota la prima drum machine come la Roland TR-909, sequencer, e computer in grado di supportare lo standard.

Con l'ingresso del MIDI, produrre musica diventò più semplice. Nascevano gli home studio. Si poteva scrivere musica usando il PC (nascono inotation scoring software). Anche il mondo dei videogames si appropriò della tecnica MIDI.


## Dati!


informazione digitale / analogica


unità base il bit, byte, nibble


comunicazione seriale/parallela ?


con 8 bit a disposizione si rappresentano da 0 a 255


<!-- .slide: data-background-color="#fff" -->
![DIN 5 pin](images/DIN5pin.jpg)<!-- .element: style="width:50%;" -->


## Esperimento 1

### Optoaccoppiatore (optoisolatore)

Gli optoaccoppiatori permettono di mantenere i device MIDI elettricamente disaccoppiati dai connettori in modo da prevenire "ground loops" e proteggerli da "voltage spikes".

### Diodo

impedisce il flusso di corrente nel senso opposto

### Il codice

L'hardware di Arduino possiede un supporto integrato per la comunicazione seriale sui pin 0 e 1, quelli che utilizziamo abitualmente per inviare e ricevere dati attraverso il cavo USB al computer.

Sulla board è presente un componente hardware chiamato UART (Universal Asynchronous Receiver Trasmitter) - vedi il microcontrollore ATmega8U2 in prossimità del connettore USB.

Questo componente permette all'Arduino di ricevere una comincazione seriale anche se sta solgendo altri task (la UART ha un buffer di 64 bytes).

La libreria **Software Serial** è stat sviluppata appositamente per permette la comunicazione seriale anche su altri pin di Arduino, usando il software per emulare il comportamento della UART.

Usando SoftwareSerial è così possibile utilizzare più di una porta di comunicazione seriale su diversi pin. Tuttavia la libreria presenta una serie di limitazioni che vedremo tra breve.

### analisi dei messaggi

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

Da notare che non sembra di individuare messaggi di Note Off, perchè?
Evidentemente la tastiera MIDI che stiamo utilizzando non è stata progettata per inviarli.
Infatti è diventata prasso quella di utilizzare messaggi di Note On con velocity 0 al posto di messaggi di Note Off (questo permentte di risparmiare un byte).

#### Osservazioni: Running status

Se esaminiamo meglio la lista di valori sul monitor seriale ci accorgiamo che talvolta, dopo la comparsa di primo messaggio di stato (144), sono elencati molti data bytes senza che lo status si ripresenti come ci si potrebbe aspettare.

Si tratta del così detto Running Status. Lo standard infatti stabilisce che lo status byte sia inviato solo se questo cambia rispetto al precedente.

Anche in questo caso si risparmiano byte preziosi.

## Esperimento 2

### Il circuito

### Il codice

## Esperimento 3: recap.

### Il cocice

Come dicevamo la libreria SoftwareSerial ha alcune limitazioni. Pur potendo essere utilizzata praticamente sulla maggiorparte di pin dell'arduino UNO, non è in grado tuttavia di gestire 2 flussi di informazioni simultanei (ricezione ed invio).

Per risolvere il problema possiamo usare la libreria AltSoftwareSerial, la quale ha però alcune limitazioni intrinseche come la necessità di usare 2 soli pin specifici: il 9 per la trasmissione e l'8 per la ricezione.
