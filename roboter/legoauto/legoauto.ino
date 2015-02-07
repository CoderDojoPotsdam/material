
/****************
 * Das Programm *
 ****************

  Folgende Befehle koennen zum Fahren genutzt werden:
  
    fahre_vorwaerts();
    fahre_rueckwaerts();
    stoppe();
    fahre_weiter();
    
  Folgende Befehle koennen zum Lenken genutzt werden:
  
    lenke_gerade_aus();
    lenke_links();
    lenke_rechts();
    
*/
// loop() ist das Programm, das immer weiter ausgeführt wird.
// Wenn der letzte Befehl vor der }-Klammer ausgeführt wurde, 
// dann wird mit dem ersten Befehl nach der {-Klammer wieder angefangen.
void loop() {
  lenke_rechts();
  fahre_rueckwaerts();
  delay(1000);          // delay() mit einer Zahl zwischen den Klammern 
                        // wartet bis zum nächsten Befehl so viele 
                        // Millisekunden, wie zwischen den Klammern steht.
  lenke_links();
  fahre_vorwaerts();
  delay(1000);
}

/*****************
 * Programmstart *
 *****************/

// setup() wird einmal beim Start des Arduinos ausgeführt.
// Danach wird nur noch loop() aufgerufen.
void setup() {
  starte_motor();     // Am Anfang starten wir den Motor.
  starte_lenkung();   // Die Lenkung muss initialisiert werden.
                      // In den folgenden Zeilen kann dann 
                      // der eigene Code stehen.
}

/********************************
 * Einbindung von Bibiliotheken *
 ********************************/

// Die Datei Servo.h brauchen wir, da in ihr steht, wie wir Servomotoren 
// ansteuern können.
#include <Servo.h> 

/*****************
 * Einstellungen *
 *****************/

// Steuersteckplaetze fuer den Motor 
// Das sind die Zahlen für die Pins. 
// Sie führen auf Anschluss 1A und 2A der H-Brücke.
const int motor_pin_1 = 9;
const int motor_pin_2 = 10;

// Der Lenkungspin führe in den goldenen Anschluss 
// vom Servo für die Lenkung.
const int lenkungs_pin = 8;

// Man muss ein bisschen warten, bis man die Richtung wechseln darf. 
// Diese Konstante gibt die Zeit in Millisekunden an, 
// die beim Stoppen gewartet wird.
const int ausrollverzoegerung_in_millisekuden = 300;

/*****************************************
 * Deklarationen fuer die Motorsteuerung *
 *****************************************/
 
// Die verschiedenen Richtungen, in die gefahren werden kann.
enum Richtung {
  STOP = 0,
  NICHT = 0,
  VORWAERTS = 1,
  RUECKWAERTS = -1
};

// Wir müssen die Funktion fahre hier Deklarieren, 
// weil wir sonst das enum Richtung nicht verwenden können.
// Alle nichtdeklarierten funktionen werden von der Arduino-Software
// automatisch am Anfang der Datei deklariert und dort gibt es noch kein
// enum Richtung.
void fahre(Richtung in_richtung);

// Man kann in verschiedene Richungen fahren. 
// Die Variable "richtung" hat immer einen der Werte 
//   STOP
//   VORWAERTS 
//   RUECKWAERTS
Richtung richtung = STOP;

// Wenn man stoppt, kann man wieterfahren. 
// Dafür muss sich die Richtung in der Variablen gemerkt werden.
Richtung richtung_vor_dem_stoppen = STOP;

/**********************************
 * Deklarationen fuer die Lenkung *
 **********************************/

// In der Variable lenkung wird eine Servosteuerung gespeichert.
Servo lenkung;

/*******************************
 * Funktionen fuer die Lenkung *
 *******************************/

// lenke_gerade_aus() kann im Programm verwendet werden, 
// um den Roboter zu steuern. 
void lenke_gerade_aus() {
  lenkung.write(90); // 90° ist gerade aus.
  stoppe();          // Damit wir nicht zu viel Strom verbrauchen, 
                     // stoppen wir den anderen Motor während sich
                     // die Lenkung an die richtige Stelle bewegt.
  fahre_weiter();    // Motor wieder anschalten.
}

// lenke_links() kann im Programm verwendet werden, 
// um den Roboter zu steuern. 
void lenke_links() {
  lenkung.write(0);  // 0° ist links.
  stoppe();          // Damit wir nicht zu viel Strom verbrauchen, 
                     // stoppen wir den anderen Motor während sich
                     // die Lenkung an die richtige Stelle bewegt.
  fahre_weiter();    // Motor wieder anschalten.
}

// lenke_rechts() kann im Programm verwendet werden, 
// um den Roboter zu steuern. 
void lenke_rechts() {
  lenkung.write(179);// 179° rechts.
  stoppe();          // Damit wir nicht zu viel Strom verbrauchen, 
                     // stoppen wir den anderen Motor während sich
                     // die Lenkung an die richtige Stelle bewegt.
  fahre_weiter();    // Motor wieder anschalten.
}

// Diese Funktion muss einmal beim Start des Arduinos aufgerufen werden.
// Sie initialisiert die Lenkung auf dem Lenkungspin. 
void starte_lenkung() {
  lenkung.attach(lenkungs_pin);
}

/******************************
 * Funktionen fuer das Fahren *
 ******************************/

 
// stoppe() hält den Roboter an.
// stoppe() kann im Programm verwendet werden, um den Roboter zu steuern.
void stoppe() {
  if (richtung == STOP) return;                 // Wenn wir schon angehalten  
                                                // haben, müssen wir nichts 
                                                // tun. Deswegen wird die 
                                                // Funktion dann verlassen.
  richtung_vor_dem_stoppen = richtung;          // Wir merken uns die 
                                                // Richtung, um später 
                                                // weiter fahren zu können.
  richtung = STOP;                              // Merken: Wir fahren jetzt
                                                // in keine Richtung.
  digitalWrite(motor_pin_1, LOW);               // Beide Pins werden aus-
  digitalWrite(motor_pin_2, LOW);               // geschaltet. Dadurch 
                                                // bekommt der Motor keinen
                                                // Strom.
  delay(ausrollverzoegerung_in_millisekuden);   // Jetzt müssen wir noch
                                                // warten, bis der Roboter 
                                                // auch anhält.
}

// fahre_vorwaerts() lässt den Roboter mit voller Kraft nach vorne fahren.
// fahre_vorwaerts() kann im Programm verwendet werden, 
// um den Roboter zu steuern.
void fahre_vorwaerts() {
  if (richtung == VORWAERTS) return;   // Wenn wir vorwärts fahren, müssen
                                       // wir keinen neuen Einstellungen
                                       // vornehmen. Deswegen wird die 
                                       // Funktion dann verlassen.
  stoppe();                            // Wir müssen erstmal stoppen, 
                                       // Da wir sonst volle Kraft dagegen 
                                       // halten würden. Das könnte zu 
                                       // anstrengend sein und wäre total 
                                       // unnötig.
  richtung = VORWAERTS;                // Merken: Wir fahren vorwärts!
  digitalWrite(motor_pin_1, HIGH);     // Einen Pin aus, den anderen an, 
  digitalWrite(motor_pin_2, LOW);      // damit der Strom schön fließen kann.
}

void fahre_rueckwaerts() {
  if (richtung == RUECKWAERTS) return; // Wenn wir rückwärts fahren, müssen
                                       // wir keinen neuen Einstellungen
                                       // vornehmen. Deswegen wird die 
                                       // Funktion dann verlassen.
  stoppe();                            // Wir müssen erstmal stoppen, 
                                       // Da wir sonst volle Kraft dagegen 
                                       // halten würden. Das könnte zu 
                                       // anstrengend sein und wäre total 
                                       // unnötig.
  richtung = RUECKWAERTS;              // Merken: Wir fahren rückwärts!
  digitalWrite(motor_pin_1, LOW);      // Einen Pin aus, den anderen an, 
  digitalWrite(motor_pin_2, HIGH);     // damit der Strom schön fließen kann.
                                       // Die Pins müssen genau entgegen der
                                       // Pins von fahre_vorwaerts() 
                                       // geschaltet werden.
}

// fahre(VORWAERTS)
// fahre(RUECKWAERTS)
// fahre(NICHT)
void fahre(Richtung in_richtung) {
  if (in_richtung == VORWAERTS) fahre_vorwaerts();
  if (in_richtung == RUECKWAERTS) fahre_rueckwaerts();
  if (in_richtung == STOP) stoppe();
}

// fahre_weiter() kann man verwenden, wenn man gestoppt hat.
// Dann fährt der Roboter weiter in die Richtung, 
// in die er vor dem Stoppen gefahren ist.
void fahre_weiter() {
  if (richtung != STOP) return;       // Wenn wir schon fahren, wollen wir
                                      // einfach weiter fahren.
                                      // Wenn wir gerade halten, dann ist
                                      // interessant, in welche Richtung es
                                      // weiter geht.
  fahre(richtung_vor_dem_stoppen);
}

// starte_motor() muss einmal am Anfang des Programmes augerufen werden.
// Es setzt alle Einstellungen, um richtig losfahren zu können.
void starte_motor() {
  pinMode(motor_pin_1, OUTPUT);   // Wir bestimmen aus dem Arduino heraus, 
  pinMode(motor_pin_2, OUTPUT);   // in welche Richtung der Motor sich drehen
                                  // soll. Das machen wir über die Pins.
                                  // Diese müssen also auf Ausgabe geschalten 
                                  // werden.
  lenke_gerade_aus();             // Damit wir die Lenkung neu Einstallen 
                                  // können.
  stoppe();                       // Wir wollen nicht fahren!
}


