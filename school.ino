int left_sensor=2;// pin no 2 in arduino to IR sensor Out pin
int right_sensor=3; // pin no 3 in arduino to IR sensor Out pin
int IN1=4;// pin no 4 in arduino to motor driver IN1 pin
int IN2=5;// pin no 5 in arduino to motor driver IN2 pin
int IN3=6;// pin no 6 in arduino to motor driver IN3 pin
int IN4=7;// pin no 7 in arduino to motor driver IN4 pin
void setup() {
  pinMode(left_sensor,INPUT);
  pinMode(right_sensor,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT); 
  Serial.begin(9600);
}
void loop() {
  int left_sensor_val=digitalRead(left_sensor);
  int right_sensor_val=digitalRead(right_sensor);
  
  if (left_sensor_val == LOW && right_sensor_val == LOW){
    forward();
    }else if (left_sensor_val == HIGH && right_sensor_val == LOW ){
      left();

    }else if (left_sensor_val == LOW && right_sensor_val == HIGH){
      right();

    } else if (left_sensor_val == HIGH && right_sensor_val == HIGH){
      stop();
    }

}




void forward(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("FORWARD");
}

void right(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  Serial.println("Right");
 }

 void left(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  Serial.println("Left");
 }
 void stop(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
   Serial.println("STOP");

  }