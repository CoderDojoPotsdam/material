Bobbycar
========

Dies ist die Beschreibung, wie man das Bobbycar programmieren kann.

Umgebung aufsetzten
-------------------

Das Bobbycar wird mit der Arduino IDE programmiert.
Diese kannst du [hier runterladen][download-arduino].

Du musst dazu [arduino-esp32][arduino-esp32] installieren.
Dann kannst du die Software hochladen, wie [in diesem Tutorial beschrieben][esp-install].

Hinweise
--------

Im [bobbycar Ordner](bobbycar) gibt es eine Programmiergrundlage, die
du verwenden solltest, damit alle Projekte die selben Pins benutzen und
man sie besser ausprobieren kann.
Bitte speicher die Ergebnisse in die [projects][projects].

Hier siehst du die Pinbelegung für den Chip:
![](https://github.com/espressif/arduino-esp32/raw/master/docs/esp32_pinmap.png)


Zusätzliche Links:
------------------

- [Datenblatt](http://akizukidenshi.com/download/ds/espressifsystems/esp_wroom_32_datasheet_en.pdf)
- [Pin Map & arduino-esp32][arduino-esp32]

[download-arduino]: https://www.arduino.cc/en/Main/Software
[esp-install]: https://techtutorialsx.com/2017/06/05/esp-wroom-32-uploading-a-program-with-arduino-ide/
[projects]: https://github.com/CoderDojoPotsdam/projects/tree/master/Arduino/bobbycar
[arduino-esp32]: https://github.com/espressif/arduino-esp32#readme
