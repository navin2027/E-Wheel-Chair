void Front();
void Back();
void Right();
void Left();
void Stop();

// LEFT MOTOR pin set up                                          
int motor1Pin1 = 2;
int motor1Pin2 = 3;

// RIGHT MOTOR pin set up
int motor2Pin1 = 4;
int motor2Pin2 = 5;

// Left side button setup                                        
int lf = 6;
int lb = 7;
// Right side button setup
int rb = 8;
int rf = 9;

// Bluetooth data input
int data;
int datai;

//Analog pin to Digital pin conversion for Sensor
#define trigPin1 A1   // Trigger pin setup for sensor1
#define echoPin1 A2   // Echo pin setup for sensor1
#define trigPin2 A3   // Trigger pin setup for sensor2
#define echoPin2 A4   // Echo pin setup for sensor2

const int trigPin3 = 10;  // Trigger pin setup for sensor3                          
const int echoPin3 = 11;  // Echo pin setup for sensor3                    

const int trigPin4 = 12;  // Trigger pin setup for sensor4
const int echoPin4 = 13;  // Echo pin setup for sensor4
       
int duration;                                           
int distance;                                            

void setup() {
  Serial.begin(9600);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  
  pinMode(lf, INPUT_PULLUP);
  pinMode(lb, INPUT_PULLUP);
  pinMode(rf, INPUT_PULLUP);
  pinMode(rb, INPUT_PULLUP);

  pinMode(data,INPUT_PULLUP);  // Deals with the bluetooth variable

                                // Start serial communication for sensor1
  pinMode(trigPin1, OUTPUT);    //Ultrasonic
  pinMode(echoPin1, INPUT);     //Ultrasonic

                                // Start serial communication for sensor2
  pinMode(trigPin2, OUTPUT);    //Ultrasonic
  pinMode(echoPin2, INPUT);     //Ultrasonic
  
                               // Start serial communication for sensor3
  pinMode(trigPin3, OUTPUT);   //Ultrasonic
  pinMode(echoPin3, INPUT);    //Ultrasonic

                               // Start serial communication for sensor4
  pinMode(trigPin4, OUTPUT);   //Ultrasonic
  pinMode(echoPin4, INPUT);    //Ultrasonic

}

void loop() {
  Serial.println("Hai");
//Left side button
   int lfi = digitalRead(lf);
   int lbi = digitalRead(lb);
// Right side button
   int rfi = digitalRead(rf);
   int rbi = digitalRead(rb);

  data = Serial.read();
  if(data==102 || data==98 || data==114 || data==108 || data==115)
       datai=data;
   
   // Trigger the ultrasonic sensor1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Measure the echo time and calculate distance for ultrasonic sensor1
  long duration1 = pulseIn(echoPin1, HIGH);
  int sensor1_dt = duration1 * 0.034 / 2;

  // Print the distance to the Serial Monitor for ultrasonic sensor1
  Serial.print("Sensor1_dt : ");
  Serial.print(sensor1_dt);
  Serial.println(" cm");

   // Trigger the ultrasonic sensor2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Measure the echo time and calculate distance for ultrasonic sensor2
  long duration2 = pulseIn(echoPin2, HIGH);
  int sensor2_dt = duration2 * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Sensor2_dt : ");
  Serial.print(sensor2_dt);
  Serial.println(" cm");

   // Trigger the ultrasonic sensor3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  // Measure the echo time and calculate distance for ultrasonic sensor3
  long duration3 = pulseIn(echoPin3, HIGH);
  int sensor3_dt = duration3 * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Sensor3_dt : ");
  Serial.print(sensor3_dt);
  Serial.println(" cm");

   // Trigger the ultrasonic sensor4
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);

  // Measure the echo time and calculate distance for ultrasonic sensor2
  long duration4 = pulseIn(echoPin4, HIGH);
  int sensor4_dt = duration4 * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Sensor4_dt : ");
  Serial.print(sensor4_dt);
  Serial.println(" cm");

 Serial.print("\n Left Front: ");
 Serial.print(lfi);
 Serial.print("\n Left Back: ");
 Serial.print(lbi);
 Serial.print("\n Right Front: ");
 Serial.print(rfi);
 Serial.print("\n Right Back: ");
 Serial.print(rbi);
 Serial.print("\n \n");
  
  if(((lfi==LOW && lbi==HIGH) && (rfi==LOW && rbi==HIGH)) && (datai==102 || datai==98 || datai==114 || datai==108 || datai==115)){
    if((sensor1_dt <= 30 || sensor2_dt <= 30) || (sensor3_dt >= 15 || sensor4_dt >= 15)){
     Stop();
      if((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW) || ( datai==98)){
        Back();
      }
      else{
        Stop();
      }
    }
    else{
      Front();
    }
  }
  else if(((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW)) && (datai==102 || datai==98 || datai==114 || datai==108 || datai==115)){
      Back();
  }
  else if(((lfi==LOW && lbi==HIGH) && (rfi==HIGH && rbi==LOW)) && (datai==102 || datai==98 || datai==114 || datai==108 || datai==115)){
    if((sensor1_dt <= 30 || sensor2_dt <= 30 ) || (sensor3_dt >= 15 || sensor4_dt >= 15)){
     Stop();
      if((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW) || ( datai==98)){
        Back();
      }
      else{
        Stop();
      }
    }
    else{
      Right();
    }
  }
  else if(((lfi==HIGH && lbi==LOW) && (rfi==LOW && rbi==HIGH)) && (datai==102 || datai==98 || datai==114 || datai==108 || datai==115)){
    if((sensor1_dt <= 30 || sensor2_dt <= 30) && (sensor3_dt >= 15 || sensor4_dt >= 15)){
     Stop();
      if((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW) || ( datai==98)){
        Back();
      }
      else{
        Stop();
      }
    }
    else{
      Left();
    }
  }
  else if(((lfi==LOW && lbi==HIGH) && (rfi==LOW && rbi==HIGH)) || (datai==102)){
    if((sensor1_dt <= 30 || sensor2_dt <= 30) || (sensor3_dt >= 15 || sensor4_dt >= 15)){
     Stop();
      if((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW) || ( datai==98)){
        Back();
      }
      else{
        Stop();
      }
    }
    else{
      Front();
    }
  }
  else if(((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW)) || (datai==98)){
      Back();
  }
  else if(((lfi==LOW && lbi==HIGH) && (rfi==HIGH && rbi==LOW)) || (datai==114)){
    if((sensor1_dt <= 30 || sensor2_dt <= 30 ) || (sensor3_dt >= 15 || sensor4_dt >= 15)){
     Stop();
      if((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW) || ( datai==98)){
        Back();
      }
      else{
        Stop();
      }
    }
    else{
      Right();
    }
  }
  else if(((lfi==HIGH && lbi==LOW) && (rfi==LOW && rbi==HIGH)) || (datai==108)){
    if((sensor1_dt <= 30 || sensor2_dt <= 30 ) || (sensor3_dt >= 15 || sensor4_dt >= 15)){
     Stop();
      if((lfi==HIGH && lbi==LOW) && (rfi==HIGH && rbi==LOW) || ( datai==98)){
        Back();
      }
      else{
        Stop();
      }
    }
    else{
      Left();
    }
  }
  else if(((lfi==HIGH && lbi==HIGH) && (rfi==HIGH && rbi==HIGH)) || (datai==115)){
    Stop();
  }
  else if(((lfi==LOW && lbi==LOW) && (rfi==HIGH && rbi==HIGH)) || (datai==102 || datai==98 || datai==114 || datai==108 || datai==115))  {
    Stop();
  }
  else if(((lfi==HIGH && lbi==HIGH) && (rfi==LOW && rbi==LOW)) || (datai==102 || datai==98 || datai==114 || datai==108 || datai==115))  {
    Stop();
  }
  else if(((lfi==LOW && lbi==LOW) && (rfi==LOW && rbi==LOW)) || (datai==102 || datai==98 || datai==114 || datai==108 || datai==115))  {
    Stop();
  }
  else {     // If any of the conditions above is not satisfied , then just STOP
    Stop();
  }
}
void Front(){
 digitalWrite(motor1Pin1, HIGH);
 digitalWrite(motor1Pin2, LOW);
 digitalWrite(motor2Pin1, HIGH);
 digitalWrite(motor2Pin2, LOW);
}
void Back(){
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, HIGH);
 digitalWrite(motor2Pin1, LOW);
 digitalWrite(motor2Pin2, HIGH);
}
void Left(){
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, HIGH);
 digitalWrite(motor2Pin1, HIGH);
 digitalWrite(motor2Pin2, LOW);
}
void Right(){
 digitalWrite(motor1Pin1, HIGH);
 digitalWrite(motor1Pin2, LOW);
 digitalWrite(motor2Pin1, LOW);
 digitalWrite(motor2Pin2, HIGH);
}
void Stop(){
 digitalWrite(motor1Pin1, LOW);
 digitalWrite(motor1Pin2, LOW);
 digitalWrite(motor2Pin1, LOW);
 digitalWrite(motor2Pin2, LOW);
}