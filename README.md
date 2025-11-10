#  Arduino 2-Sensor Line Follower Robot

A simple, beginner-friendly line follower robot sketch using an Arduino,
two IR sensors, and a standard L293D/L298N motor driver.

---
### Hardware Required
* 1x Arduino (e.g., UNO, Nano)
* 1x Robot Chassis with 2 DC Motors
* 1x Motor Driver (e.g., L298N, L293D)
* 2x IR Proximity Sensors
* Jumper Wires
* Power Supply (e.g., 9V battery or 4xAA battery pack)

---
### 📌 Pin Connections

This sketch uses the following pin configuration:

| Component | Pin | Arduino Pin |
| :--- | :--- | :--- |
| **IR Sensors** | | |
| Left Sensor | `OUT` | Pin 2 |
| Right Sensor | `OUT` | Pin 3 |
| **Motor Driver** | | |
| Left Motor | `IN1` | Pin 4 |
| Left Motor | `IN2` | Pin 5 |
| Right Motor | `IN3` | Pin 6 |
| Right Motor | `IN4` | Pin 7 |

* **Motor Driver Power:** Connect `VCC`/`+5V` to Arduino 5V, `GND` to Arduino GND, and `VMS`/`V+` to your external battery pack.
* **Sensor Power:** Connect Sensor `VCC` to Arduino 5V and `GND` to Arduino GND.

---
### 🤖 How It Works (Logic)

The robot's behavior is controlled by the two IR sensors.

**IMPORTANT:** This code assumes your IR sensors output **`LOW`** when they see the **white surface** and **`HIGH`** when they detect the **black line**.

| Left Sensor | Right Sensor | State | Action |
| :--- | :--- | :--- | :--- |
| `LOW` (White) | `LOW` (White) | On the path | `forward()` |
| `HIGH` (Line) | `LOW` (White) | Left sensor hit line | `left()` |
| `LOW` (White) | `HIGH` (Line) | Right sensor hit line | `right()` |
| `HIGH` (Line) | `HIGH` (Line) | Both on line (e.g., intersection) | `stop()` |

> **Note:** If your robot does the opposite (e.g., turns right when it should turn left), your sensors may be `LOW` on black and `HIGH` on white. If so, you must reverse all the `HIGH`/`LOW` logic in the `loop()` function.

---
### 🚀 How to Use

1.  Assemble the hardware according to the **Pin Connections** table.
2.  Open the `.ino` file in the Arduino IDE.
3.  Connect your Arduino to your computer.
4.  Select the correct Board and Port from the `Tools` menu.
5.  Click **Upload**.
6.  Place the robot on its track and power it on.

---
### 📁 Source Code (`line_follower.ino`)

```

int left_sensor=2;    // pin no 2 in arduino to IR sensor Out pin
int right_sensor=3;   // pin no 3 in arduino to IR sensor Out pin
int IN1=4;            // pin no 4 in arduino to motor driver IN1 pin
int IN2=5;            // pin no 5 in arduino to motor driver IN2 pin
int IN3=6;            // pin no 6 in arduino to motor driver IN3 pin
int IN4=7;            // pin no 7 in arduino to motor driver IN4 pin

void setup() {
  pinMode(left_sensor,INPUT);
  pinMode(right_sensor,INPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT); 
  Serial.begin(9600); // For debugging
}

void loop() {
  int left_sensor_val=digitalRead(left_sensor);
  int right_sensor_val=digitalRead(right_sensor);
  
  // Logic: LOW = White Surface, HIGH = Black Line
  
  if (left_sensor_val == LOW && right_sensor_val == LOW){
    // Both sensors on white, move forward
    forward();
  } else if (left_sensor_val == HIGH && right_sensor_val == LOW ){
    // Left sensor on black line, turn left
    left();
  } else if (left_sensor_val == LOW && right_sensor_val == HIGH){
    // Right sensor on black line, turn right
    right();
  } else if (left_sensor_val == HIGH && right_sensor_val == HIGH){
    // Both sensors on black line, stop
    stop();
  }

}

void forward(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);  // Left motor forward
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);  // Right motor forward
  Serial.println("FORWARD");
}

void right(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);   // Left motor reverse
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);  // Right motor forward
  Serial.println("Right");
}

void left(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);  // Left motor forward
  digitalWrite(IN3,HIGH);
r  digitalWrite(IN4,LOW);   // Right motor reverse
  Serial.println("Left");
}

void stop(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);   // Left motor stop
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);   // Right motor stop
  Serial.println("STOP");
}
```
