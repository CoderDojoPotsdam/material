Tonerkennung
============

![](bilder/mikrofone.jpg)

Der Beispielquelltext befindet sich in der Datei [wave_detection.ino](wave_detection/wave_detection.ino). Er muss verändert werden und in eine neue Datei abgespeichert werden.
Um sie mit einem Roboter zu kombinieren, darf es nur ein Mal die Funktion `setup()` und nur ein Mal die Funktion `loop()` geben.

Aufgaben
--------

- Finde mit dem Roboter den Lautsprecher. [mittel]
- Bestimme die Schallgeschwindigkeit. [schwer]


Mikrofon anschließen
--------------------

Nicht am [Elektretmikrofon](https://de.wikipedia.org/wiki/Elektretmikrofon) rumbiegen.

Das Mikrofon ist mit **G** beschriftet - Ground, Masse kommt an den Arduino Ground, GND.  
**+** oder **V** wie "Voltage" kommen an die 5V vom Arduino.  
Das **S**ignal ist mit **S** oder **A0** beschriftet und muss an A0 angeschlossen werden. 

Das rote Mikrofon hat noch einen D0-Ausgang. Der ist `LOW` oder `HIGH` je nach dem wie laut es ist. Ich denke, es kann Klatschen erkennnen.

Funktionen
----------

Eine Beschreibung der Funktionen befindet sich in der [wave_detection.ino](wave_detection/wave_detection.ino).

    setup_frequency_recognition(A0);

muss **ein Mal** ein `setup()` aufgerufen werden. Es sagt, dass das Mikrofon an pin A0 angeschlossen wird.

Mit 

    get_frequency()

kann man sich die erwartete [Frequenz](http://de.wikipedia.org/wiki/Frequenz) holen, auf deren Intensität gelauscht wird.

    get_intensity_squared()

nimmt vom Mikrofon auf und gibt die [Schallintensität](https://de.wikipedia.org/wiki/Schallintensit%C3%A4t) quadriert zurück.

    sqrt(get_intensity_squared())

gibt die Schallintensität zurück.

Aus den [Formeln über die Schallintensität](https://de.wikipedia.org/wiki/Schallintensit%C3%A4t) lässt sich ableiten, dass man eine zum Abstand proportionale Größe aus der Schallintensität mit √I berechnen kann:

    pow(get_intensity_squared(), 0.25)

Ton abspielen
-------------

Um den Ton zu hören, muss man ihn erst abspielen.
Für die Frequenz von 400Hz gibt es Dateien im Ordner [sound](sound). 

Mit 

    tone(8, 400)

kann man auf dem Arduino auf dem Pin 8 einen Ton von 400Hz erzeugen.

Digital Signal Processing (DSP) 
-------------------------------

Wer erfahren möchte, wie man eine Welle erkennt, kann sich dieses Buch durchlesen: [dspguide.com](http://www.dspguide.com/ch6.htm). Die Fast Fourier Transformation macht für viele Frequenzen, was hier nur mit einer gemacht wird.

Mikrofone
---------

Das blaue Mirofon ist ein [B86"New Electronic Brick Sound Sensor Microphone Mic Module for Arduino](http://www.aliexpress.com/snapshot/6363719284.html).

Das rote Mikrofon ist ein [High Sensitivity Sound Microphone Sensor Detection Module For Arduino AVR PIC](http://www.aliexpress.com/snapshot/6349001835.html). Es hat in dem blauen Kasten einen verstellbaren Widerstand, mit dem man die Spannung des A0-Pins bei Stille einstellen kann. Wenn das Mikrofon taub ist, sollte man sich mit `analogRead()` die Spannung ausgeben lassen und dran rum drehen, bis es besser wird. Durchaus auch 20 Umdrehungen, bis es um 512 ist. 

Thanks
------

Thanks go to Paul O'Dowd for the [blogpost on "Arduino, detect 38khz with a Bandpass software digital filter"](http://www.paulodowd.com/2013/06/arduino-38khz-bandpass-software-digital.html).


