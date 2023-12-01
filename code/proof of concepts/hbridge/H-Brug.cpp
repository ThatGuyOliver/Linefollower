#include <Arduino.h>

#define SerialPort Serial
#define Baudrate 115200

//Pins Instellen
const int motor1PWM1 = 16;  //PWM pin for motor 1 driver input 1
const int motor1PWM2 = 17;  //PWM pin for motor 1 driver input 2
const int motor2PWM1 = 18;  //PWM pin for motor 2 driver input 1
const int motor2PWM2 = 19;  //PWM pin for motor 2 driver input 2
const int delayTime = 25;   //Delay in milliseconds between each step


void motor1CW();
void motor1CCW();
void motor2CW();
void motor2CCW();
void samenC();

void setup() 
{
  //Seriële Poort
  SerialPort.begin(Baudrate);
  delay(100);

  pinMode(motor1PWM1, OUTPUT);
  pinMode(motor1PWM2, OUTPUT);
  pinMode(motor2PWM1, OUTPUT);
  pinMode(motor2PWM2, OUTPUT);
}

void loop() 
{   
  if (Serial.available()) { 
    String command = Serial.readStringUntil('\n');

    if (command == "M1") {
      Serial.println("Motor 1 Clockwise");
      motor1CW();
    } 
    else if (command == "O2") {

      Serial.println("Motor 2 Clockwise");
      motor2CW();
    } 
    else if (command == "A1") {

      Serial.println("Motor 1 Counterclockwise");
      motor1CCW();
    } 
    else if (command == "B2") {

      Serial.println("Motor 2 Counterclockwise");
      motor2CCW();
    }
    else if (command == "SA") {

      Serial.println("Motoren Werken Samen Clockwise");
      samenC();
    }
  }
}


void motor1CW()
{
  for (int speed = 40; speed <= 125; speed++)
  {
    analogWrite(motor1PWM1, 0);
    analogWrite(motor1PWM2, speed);
    delay(delayTime);
  }
  for (int speed = 125; speed >= 30; speed--) 
  {
    analogWrite(motor1PWM1, 0);
    analogWrite(motor1PWM2, speed);
    delay(delayTime);
  }
}

void motor2CW()
{
  for (int speed = 40; speed <= 125; speed++)
  {
    analogWrite(motor2PWM1, 0);
    analogWrite(motor2PWM2, speed);
    delay(delayTime);
  }
  for (int speed = 125; speed >= 30; speed--) 
  {
    analogWrite(motor2PWM1, 0);
    analogWrite(motor2PWM2, speed);
    delay(delayTime);
  }
}

void motor1CCW()
{
  for (int speed = 40; speed <= 125; speed++)
  {
    analogWrite(motor1PWM1, speed);
    analogWrite(motor1PWM2, 0);
    delay(delayTime);
  }
  for (int speed = 125; speed >= 30; speed--) 
  {
    analogWrite(motor1PWM1, speed);
    analogWrite(motor1PWM2, 0);
    delay(delayTime);
  }
}

void motor2CCW()
{
  for (int speed = 40; speed <= 125; speed++)
  {
    analogWrite(motor2PWM1, speed);
    analogWrite(motor2PWM2, 0);
    delay(delayTime);
  }
  for (int speed = 125; speed >= 30; speed--) 
  {
    analogWrite(motor2PWM1, speed);
    analogWrite(motor2PWM2, 0);
    delay(delayTime);
  }
}

void samenC()
{
  for (int speed = 40; speed <= 125; speed++)
  {
    analogWrite(motor1PWM1, 0);
    analogWrite(motor1PWM2, speed);
    analogWrite(motor2PWM1, 0);
    analogWrite(motor2PWM2, speed);
    delay(delayTime);
  }
  for (int speed = 125; speed >= 30; speed--) 
  {
    analogWrite(motor1PWM1, 0);
    analogWrite(motor1PWM2, speed);
    analogWrite(motor2PWM1, 0);
    analogWrite(motor2PWM2, speed);
    delay(delayTime);
  }
}
