Rödel
=====

![](roedel.jpg)


Der Beispielquelltext befindet sich in der Datei [roedel.ino](roedel.ino). Er muss verändert werden und in eine neue Datei abgespeichert werden.

Der Roboter robbt auf dem Boden lang. Wichtig zu wissen ist, wie man dem Servo sagt, an welche Position er sich stellen soll. Das Stellen des Servos bewegt den Roboter.

Dieses Programm stellt den Roboter abwechselnd auf die Positionen 80° und 100° und wartet dazwischen 200 Millisekunden, damit sich der Servo bewegen kann.

    void loop() 
    { 
      myservo.write(80);
      delay(200);
      myservo.write(100);
      delay(200);
    } 

Der Arduino weiß nicht, wann der Servo sein Ziel erreicht hat. Er sagt dem Servo nur, wohin er soll. 

Wenn der Servo mal ab geht: 

- das braune Kabel kommt an Masse also ground oder GND
- das rote, mittlere Kabel kommt an 5V
- das güldene Kabel ist das Steuerkabel, das an den Pin kommt, an dem der Servo gesteuert wird. Wenn es an Pin 9 kommt, sieht der Quelltext so aus:

        void setup() 
        { 
          myservo.attach(9);  
        } 

	Wenn in den Klammern was anderes als eine 9 steht, muss das güldene Kabel daran.

Repository
----------

Rödel ist ein ein lasergeschnittener Roboter und wird in einem [anderen Repository](https://github.com/niccokunzmann/rustyrobots) verwaltet.



