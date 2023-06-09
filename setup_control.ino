// In this code, we have merged the propeller control code into the code that controls the experimental setup

#define STATE_IDLE 0
#define STATE_READY 1
#define STATE_DISPENSE 2


#define flashPin 3      // the number of Flash pin to Optocoupler
#define ledPin 13      // the number of the LED pin
#define laser 7
#define lasersensor 8
#define enA  9//pin 1 of the IC
#define in1  12 // pin 2 of the IC
#define in2  13 //pin7 of IC

bool laser_val;
int fsm_state;


void setup() {
 Serial.begin(9600); // start serial communication at 9600 bps:
 fsm_state = STATE_IDLE; // state variable initialization


  pinMode(ledPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(lasersensor, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  digitalWrite(laser, HIGH);

  
}

void loop(){
  laser_val= digitalRead(lasersensor);
  //delay(100);
  //Serial.println(laser_val);
  
  switch (fsm_state){
  case STATE_IDLE:
    Serial.println("idle");
    laser_val= digitalRead(lasersensor);
    
    if (laser_val==0){
      
      fsm_state=STATE_IDLE;
    }
    else{
      
      fsm_state=STATE_READY;
    }
    delay(5);
    break;

  case STATE_READY:
  
    Serial.println("ready");
    laser_val= digitalRead(lasersensor);
    
    if (laser_val==0){
      
      fsm_state=STATE_DISPENSE;
    }
    else{
      
      fsm_state=STATE_READY;
    }
    delay(5);
    
    break;
 

  case STATE_DISPENSE:
  
    
    
    Serial.println("dispensed");
    
    laser_val= digitalRead(lasersensor);
    
    /*
    if (laser_val==0){
      
      fsm_state=STATE_IDLE;
    }
    else{
      
      fsm_state=STATE_DISPENSE;
    }
    */

    fsm_state=STATE_IDLE;
    delay(5);

    delay(211);

    
    digitalWrite(flashPin, HIGH); // fire flash
    delay(10);
    digitalWrite(flashPin,LOW);
    /*
    delay(40);
    
    digitalWrite(flashPin, HIGH); // fire flash
    delay(10);
    digitalWrite(flashPin,LOW);

    delay(40);
    
    digitalWrite(flashPin, HIGH); // fire flash
    delay(10);
    digitalWrite(flashPin,LOW);
    */
    onerotation(); 
    break;
    
}
    //extra delay to flash at the exact moment the droplet touches the surface
    //delay(100);
}


void onerotation(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
  delay(26);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
