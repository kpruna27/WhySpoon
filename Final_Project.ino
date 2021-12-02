//Assign the pins for each component
int trig1 = 2; // For Ultrasonic sensor #1
int echo1 = 3;
int trig2 = 6; // Ultrasonic Sensor #2
int echo2 = 7;
int buzzer = 9; //Piezoelectric buzzer
int servo = 13; // Servo Motor
int tperiod = 20000; // Total period of PWM for Motor
int OPEN = 1000; // Pulse when open
int CLOSED = 2000; // Pulse when closed
void setup() {
  delay(1000); // To avoid unwanted sensing
  // Set input and outputs for components
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(servo,OUTPUT);
  pinMode(trig2,OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // For the two sensors
  long duration1, distance1, duration2, distance2;

  
  // Ultrasonic Sensor #1
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig1,HIGH); //Send out ultrasonic sound pulses
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);

  //Receive ultasonic sound pulse
  duration1 = pulseIn(echo1,HIGH); //Listens for a reflected signal
  distance1 = (duration1 / 2) * 0.0343; // duration/2 is signal boucing back, 0.0343cm/microseconds is speed of sound

  // Servo Motor actuation
  if (distance1 <= 30){ // Sensor #1 sensing up to 30cm
    digitalWrite(servo,HIGH);       //Turn on servo
    delayMicroseconds(OPEN);        // Pulse ratio for motor open position
    digitalWrite(servo,LOW);        //Turn off 
    delayMicroseconds(tperiod-OPEN);//delay for the remaining of 20ms to set duty cycle
    delay(3000);                    //Keep open for 3 seconds 
  }
    
   else { // Sensor #1 doesn't detect under 30cm
    digitalWrite(servo,HIGH);       //Turn on servo
    delayMicroseconds(CLOSED);   // Pulse ratio for motor closed position
    digitalWrite(servo,LOW);        //Turn off 
    delayMicroseconds(tperiod-CLOSED); //dlay for the remaining of 20ms to set duty cycle
    delay(20);
    } 

    // Ultrasonic Sensor #2
    delay(500); // Delay to avoid unwanted sensing
    // Sends ultrasonic sound pulse   
    digitalWrite(trig2,LOW);
    delayMicroseconds(2);
    digitalWrite(trig2,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig2,LOW);
    duration2 = pulseIn(echo2,HIGH); //Listens for a reflected signal
    distance2 = (duration2 / 2) * 0.0343; // duration/2 is signal boucing back, 0.0343cm/microseconds is speed of sound
  
    Serial.println(distance2);

    // Piezoelectric buzzer
    if (distance2 <= 5){ //5cm means the trashcan is full
      for (int n=0; n<3; n++){ // Repeat 3 buzzing
      tone(buzzer,200); //Turn on buzzer at 200 Hz
      delay(50); // Duration of the buzz sound
      noTone(buzzer); // Turn off
      delay(50); // Delay before the next buzz
      }
    }
    
    
    
}
