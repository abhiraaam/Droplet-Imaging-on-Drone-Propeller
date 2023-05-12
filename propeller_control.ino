// Motor A connections
int enA = 9; //pin 1 of the IC
int in1 = 12; // pin 2 of the IC
int in2 = 13; //pin7 of IC


void setup() {
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  onerotation();
}

void loop() {
}


void onerotation(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  delay(26); // the time period for one rotaton of the motor is found out to be 26ms
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
