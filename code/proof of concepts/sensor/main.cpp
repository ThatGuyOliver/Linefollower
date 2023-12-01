#include <Arduino.h>
#include <EEPROM.h>
#include <SerialCommand.h>
#include <Serialcommand.cpp>



#define SerialPort Serial
#define Baudrate 115200

void onUnknownCommand(char *command);
void onSet();
void onDebug();
void onCalibrate();



//Sensoren

const int sensor[] = {33, 32, 35, 34, 39, 36};
struct param_t
{
  unsigned long cycleTime;
  int black[6];
  int white[6];
  /* andere parameters die in het eeprom geheugen moeten opgeslagen worden voeg je hier toe ... */
} params;
#define EEPROM_SIZE sizeof(param_t)

SerialCommand sCmd(SerialPort);
bool debug;
unsigned long previous, calculationTime;

void setup()
{
  SerialPort.begin(Baudrate);

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("calibrate", onCalibrate);
  sCmd.setDefaultHandler(onUnknownCommand);
  
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.get(0, params);
  EEPROM.end();

  SerialPort.println("ready");
}

void loop()
{
  sCmd.readSerial(); 
  unsigned long current = micros();
  if (current - previous >= params.cycleTime)
  {
    previous = current;
    
    
    //sensoren
    Serial.print("Values: ");
    for(int i=0;i<6;i++)
    {
      SerialPort.print(analogRead(sensor[i]));
      SerialPort.print(" ");
    }
    SerialPort.println();
    

  }
  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}

void onUnknownCommand(char *command)
{
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

void onSet()
{  
  char* param = sCmd.next();
  char* value = sCmd.next();

  if (strcmp(param, "debug") == 0)
  {
    if (strcmp(value, "on") == 0) debug = true;
    else if (strcmp(value, "off") == 0) debug = false;
  }
  else if (strcmp(param, "cycle") == 0) 
  {
    long newCycleTime = atol(value);
    float ratio = ((float) newCycleTime) / ((float) params.cycleTime);
    params.cycleTime = newCycleTime;
    SerialPort.print("New cycle time: ");
    SerialPort.println(params.cycleTime);
  }
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(0, params);
  EEPROM.commit();
  EEPROM.end();
}
void onDebug()
{
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);
  
  /* parameters weergeven met behulp van het debug commando doe je hier ... */
  SerialPort.print("black: ");
  for (int i =0; i <6; i++)
  {
    SerialPort.print(params.black[i]);
    SerialPort.print(" ");
  }
  SerialPort.print(" ");
 
 SerialPort.print("white: ");
  for (int i =0; i <6; i++)
  {
    SerialPort.print(params.white[i]);
    SerialPort.print(" ");
  }
  
  SerialPort.print(" ");
  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  calculationTime = 0;
}

void onCalibrate()
{
  char* param = sCmd.next();

  if (strcmp(param, "black") == 0)
  {
    SerialPort.print("start calibrating black... ");
    for (int i = 0; i < 6; i++) params.black[i]=analogRead(sensor[i]);
    SerialPort.println("done");
  }
  else if (strcmp(param, "white") == 0)
  {
    SerialPort.print("start calibrating white... ");    
    for (int i = 0; i < 6; i++) params.white[i]=analogRead(sensor[i]);  
    SerialPort.println("done");      
  }

  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(0, params);
  EEPROM.commit();
  EEPROM.end();
}