
void loop () {
  fahre_vor();
  delay(2000);
  fahre_zurueck();
  delay(1000);
}

int motor_pin_1 = 4;
int motor_pin_2 = 5;
int pwm_pin = 3;


void setup() {
  pinMode(motor_pin_1, OUTPUT);
  pinMode(motor_pin_2, OUTPUT);
  pinMode(pwm_pin,     OUTPUT);
}

void anhalten() {
  analogWrite(pwm_pin, geschwindigkeit);
  digitalWrite(motor_pin_1, LOW);
  digitalWrite(motor_pin_2, LOW);
  delay(300);
}

void fahre_vor() {
  anhalten();
  analogWrite(pwm_pin, geschwindigkeit);
  digitalWrite(motor_pin_1, LOW);
  digitalWrite(motor_pin_2, HIGH);
}

void fahre_zurueck() {
  anhalten();
  analogWrite(pwm_pin, geschwindigkeit);
  digitalWrite(motor_pin_1, HIGH);
  digitalWrite(motor_pin_2, LOW);
}


