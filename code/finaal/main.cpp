#include <Arduino.h>
#include <WiFi.h>
#include <EEPROM.h>
#include "TelnetCommand.h"
#include "TelnetCommand.cpp"

#define SerialPort Serial
#define Baudrate 115200

//Wifi Login;
const char* ssid = "HGDevice";
const char* pswd = "KillAllHuman$";
const char* MyHostName = "LinefollowerOliver";
int port = 23;

WiFiServer telnetServer(port);
WiFiClient client;
TelnetCommand telnetCmd(SerialPort);

//Motor
#define MotorLeftForward 16
#define MotorLeftBackward 17
#define MotorRightForward 18
#define MotorRightBackward 19

//Void function
void onUnknownCommand(char *command);
void onSet();
void onDebug();
void onCalibrate();
void onRun();
void mainLoop();

//Sensoren
const int sensor[] = {36, 39, 34, 35, 32, 33};
//const int sensor[] = {33, 32, 35, 34, 39, 36};
struct param_t
{
  unsigned long cycleTime;
  uint black[6];
  uint white[6];
  uint power;
  float diff;
  float kp;
  float ki;
  float kd;

  /* andere parameters die in het eeprom geheugen moeten opgeslagen worden voeg je hier toe ... */
} params;
#define EEPROM_SIZE sizeof(param_t)


//Globalised Variables
int normalised[6];
float debugPosition;
bool debug;
bool run;
unsigned long previous, calculationTime;
float iTerm;
float lastErr;

void setup()
{
  SerialPort.begin(Baudrate);

  //Regelen 
  iTerm = 0;
  
  //EEPROM
  EEPROM.begin(EEPROM_SIZE);
  EEPROM.get(0, params);
  EEPROM.end();

  SerialPort.println("Welcome to ESP32 Serial:");
  run = false;
  //Wifi 
  
  WiFi.setHostname(MyHostName);
  WiFi.begin(ssid, pswd);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    SerialPort.println("Connecting to WiFi...");
  }

  SerialPort.println("Connected to WiFi");
  SerialPort.print("IP address: ");
  SerialPort.println(WiFi.localIP());

  telnetServer.begin();
  SerialPort.print("Port: ");
  SerialPort.println(port);

  telnetCmd.addCommand("set", onSet);
  telnetCmd.addCommand("debug", onDebug);
  telnetCmd.addCommand("calibrate", onCalibrate);
  telnetCmd.addCommand("run", onRun);
  telnetCmd.setDefaultHandler(onUnknownCommand);
}

void loop()
{
  //Wifi
  client = telnetServer.available();
  telnetCmd.readStream(client);
  if (client) 
  {
    Serial.println("New Telnet client connected");
    client.println("Welcome to ESP32-Robot Telnet Server");
    while (client.connected()) 
    {
      if (client.available()) {telnetCmd.readStream(client);}
      mainLoop();
    }
    Serial.println("Telnet client disconnected");
  }
}
void mainLoop()
{
  //Main Loop
  unsigned long current = micros();
  if (current - previous >= params.cycleTime)
  {
    previous = current;
    
    //sensoren
    for(int i=0;i<6;i++) normalised[i] = map(analogRead(sensor[i]), params.black[i], params.white[i], 0, 4096);
    
    float position = 0;

    //positie zwartste sensor 
    int index = 0;
    for (int i = 1; i < 6; i++) if (normalised[i] < normalised[index]) index = i;

    if (normalised[index] > 3000) run = false;
    
    //Is indix op de rand 
    if (index == 0) position = -50;
    else if (index == 7) position = 50;
    else
    {
    
    //waarde toekennen aan de 3 punten voor interpolatie
    long sNul = normalised[index];
    long sMinEen = normalised[index-1];
    long sPlusEen = normalised[index+1];
    //berekenen punten
    float b = ((float) (sPlusEen - sMinEen)) / 2;
    float a = sPlusEen - b - sNul;

    position = -b / (2 * a);  
    //Verschuiven y as
    position += index - 3.5;   
    position *= 15;
    }
    debugPosition = position;

    float error = -position;

    //Proportioneel
    float output = error * params.kp;
    
    //Integrerend
    iTerm += params.ki * error;
    iTerm = constrain(iTerm, -510, 510);
    output += iTerm;

    //Differentieel
    output += params.kd * (error - lastErr);
    lastErr = error;

    output = constrain(output, -510, 510);
    int powerLeft =0;
    int powerRight = 0;
    
    if (run) if (output >= 0)
    {
      powerLeft = constrain(params.power + params.diff * output, -255, 255);
      powerRight = constrain(powerLeft - output, -255, 255);
     powerLeft = powerRight + output;
    }
    else
    {
      powerRight = constrain(params.power - params.diff * output, -255, 255);
      powerLeft = constrain(powerRight + output, -255, 255);
      powerRight = powerLeft - output;
    }
    analogWrite(MotorLeftForward, powerLeft > 0 ? powerLeft : 0);
    analogWrite(MotorLeftBackward, powerLeft < 0 ? -powerLeft : 0);
    analogWrite(MotorRightForward, powerRight > 0 ? powerRight : 0);
    analogWrite(MotorRightBackward, powerRight < 0 ? -powerRight : 0);
  }
  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}

void onUnknownCommand(char *command)
{
  client.print("unknown command: \"");
  client.print(command);
  client.println("\"");
}

void onSet()
{  
  char* param = telnetCmd.next();
  char* value = telnetCmd.next();

  /*
  if (strcmp(param, "debug") == 0)
  {
    if (strcmp(value, "on") == 0) debug = true;
    else if (strcmp(value, "off") == 0) debug = false;
  }
  */
 /*
 else  if (strcmp(param, "cycle") == 0) 
  {
    long newCycleTime = atol(value);
    float ratio = ((float) newCycleTime) / ((float) params.cycleTime);
    params.cycleTime = newCycleTime;
    SerialPort.print("New cycle time: ");
    SerialPort.println(params.cycleTime);
  }
  */
  if (strcmp(param, "cycle") == 0)
  {
    long newCycleTime = atol(value);
    float ratio = ((float) newCycleTime) / ((float) params.cycleTime);

    params.ki *= ratio;
    params.kd /= ratio;

    params.cycleTime = newCycleTime;
  } 
  else if (strcmp(param, "power") == 0) params.power = atol(value);
  else if (strcmp(param, "diff") == 0) params.diff = atof(value);
  else if (strcmp(param, "kp") == 0) params.kp = atof(value);
  else if (strcmp(param, "ki") == 0) params.ki = atof(value) * (((float) params.cycleTime) / 1000000);
  else if (strcmp(param, "kd") == 0) params.kd = atof(value) / (((float) params.cycleTime) / 1000000);

  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(0, params);
  EEPROM.commit();
  EEPROM.end();
}
void onDebug()
{
  client.print("cycle time: ");
  client.println(params.cycleTime);
  
  /* parameters weergeven met behulp van het debug commando doe je hier ... */
  client.print("black: ");
  for (int i =0; i <6; i++)
  {
    client.print(params.black[i]);
    client.print(" ");
  }
  client.println(" ");
 
 client.print("white: ");
  for (int i =0; i <6; i++)
  {
    client.print(params.white[i]);
    client.print(" ");
  }
  client.println(" ");
 
 client.print("normalised: ");
  for (int i =0; i <6; i++)
  {
    client.print(normalised[i]);
    client.print(" ");
  }
  client.println(" ");

  client.print("position: ");
  client.println(debugPosition);
  /*for (int i =0; i <6; i++)
  {
    SerialPort.print(debugPosition);
    SerialPort.print(" ");
  }
  */

  client.print("Power: ");
  client.println(params.power);
  client.print("Diff: ");
  client.println(params.diff);
  client.print("Kp: ");
  client.println(params.kp);
  client.print("Ki: ");
  client.println(params.ki /(((float) params.cycleTime )/ 1000000));
  client.print("Kd: ");
  client.println(params.kd *(((float) params.cycleTime) / 1000000));

  client.print("Run state: ");
  client.println(run);

  client.print("calculation time: ");
  client.println(calculationTime);
  calculationTime = 0;
}

void onCalibrate()
{
  char* param = telnetCmd.next();

  if (strcmp(param, "black") == 0)
  {
    client.print("start calibrating black... ");
    for (int i = 0; i < 6; i++) params.black[i]=analogRead(sensor[i]);
    client.println("done");
  }
  else if (strcmp(param, "white") == 0)
  {
    client.print("start calibrating white... ");    
    for (int i = 0; i < 6; i++) params.white[i]=analogRead(sensor[i]);  
    client.println("done");      
  }

  EEPROM.begin(EEPROM_SIZE);
  EEPROM.put(0, params);
  EEPROM.commit();
  EEPROM.end();
}

void onRun()
{
  if (run == false) 
  {
    iTerm = 0;
    run = true;
  }
  else run = false;
}