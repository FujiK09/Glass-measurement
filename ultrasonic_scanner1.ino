#include <Servo.h> 

const int TRIG_PIN = 10;
const int ECHO_PIN = 11;
const int SERV_PIN = 12;

unsigned long duration;
unsigned int distance;

//float duration;
//float distance;
int input;

Servo myServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  myServo.attach(SERV_PIN);
  Serial.begin(9600);
}

void loop() {
  input = Serial.read();
  if(input == -1) 
  {
    return;
  }
  Serial.print("\n+:");
  for(int i=0;i<=180;i+=2){  
    myServo.write(i);
    delay(200);
    distance = calculateDistance();
  
    Serial.print(distance);
    Serial.print(",");
  }
  Serial.print("0");

  input = Serial.read();
  if(input == -1) {
    return;
  }
  Serial.print("\n-:");
  for(int i=180;i>0;i-=2){  
    myServo.write(i);
    delay(200);
    distance = calculateDistance();
    Serial.print(distance);
    Serial.print(",");
  }
  Serial.print("0");
}

// [mm]
int calculateDistance(){ 
  float temp;
  float sound;
  float analog, vout;
  analog = analogRead(0);
  vout = (analog*5*1000)/1023;
  temp = (vout - 600) / 10;
  
  digitalWrite(TRIG_PIN, LOW); 
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration*0.34/2.0;
//  sound = 331 + 0.6 * temp;
//  duration = duration/2.0;
//  distance = duration*sound*100;
//  Serial.print("ondo");
//  Serial.println(temp);

  return distance;
}
