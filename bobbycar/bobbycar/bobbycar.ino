/*

  Pins for digital output: 13, 12, 14, 27, 26, 25, 33, 32
*/

// OUTPUT
#define LED_RECHTS_VORN_ROT   32
#define LED_LINKS_VORN_ROT    33
#define LED_RECHTS_VORN_GRUEN 25
#define LED_LINKS_VORN_GRUEN  36
#define LAUTSPRECHER          27

// INPUT
#define DRUCKKNOPF            14
#define KIPPSCHALTER          12
#define LENKER                13

void setup() {
  // OUTPUT
  pinMode(LED_RECHTS_VORN_ROT,   OUTPUT);
  pinMode(LED_LINKS_VORN_ROT,    OUTPUT);
  pinMode(LED_RECHTS_VORN_GRUEN, OUTPUT);
  pinMode(LED_LINKS_VORN_GRUEN , OUTPUT);
  pinMode(LAUTSPRECHER,          OUTPUT);
  // INPUT
  pinMode(DRUCKKNOPF,   INPUT);
  pinMode(KIPPSCHALTER, INPUT);
  pinMode(LENKER,       INPUT);

  Serial.begin(9600);
}

void blink(int LED) {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  Serial.print(LED);
  Serial.println(" An");
  delay(555);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  Serial.print(LED);
  Serial.println(" Aus");
  delay(555);                       // wait for a second
}

// the loop function runs over and over again forever
void loop() {
  Serial.print("Port ");
  Serial.print(DRUCKKNOPF);
  Serial.print(" = ");
  Serial.println(analogRead(DRUCKKNOPF));
  delay(200);
}
