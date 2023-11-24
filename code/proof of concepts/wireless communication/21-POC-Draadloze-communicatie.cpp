#include <Arduino.h>
#include <WiFi.h>
#include <EEPROM.h>
#include "TelnetCommand.h"
#include "TelnetCommand.cpp"

#define SerialPort Serial
#define Baudrate 115200

const char* ssid = "ESP32OV";
const char* pswd = "Leerling1!";

int port = 23;

void onLed();
void onUnknownCommand(char *command);

WiFiServer telnetServer(port);
WiFiClient client;
TelnetCommand telnetCmd(SerialPort);


void setup() 
{
  SerialPort.begin(Baudrate);
  delay(100);

  pinMode(12, OUTPUT);


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
  SerialPort.print("Telnet server started on port ");
  SerialPort.println(port);

  telnetCmd.addCommand("led", onLed);
  telnetCmd.setDefaultHandler(onUnknownCommand);
}

void loop() 
{
  client = telnetServer.available();
  telnetCmd.readStream(client);
  if (client) 
  {
    Serial.println("New Telnet client connected");
    client.println("Welcome to ESP32-Robot Telnet Server");
    while (client.connected()) {if (client.available()) {telnetCmd.readStream(client);}}
    Serial.println("Telnet client disconnected");
  }
}

void onUnknownCommand(char *command)
{
  client.print("Unknown command: ");
  client.println(command);
}

void onLed()
{
  char* param = telnetCmd.next();
  
  if (param == nullptr) {
    client.print("Missing parameter. Usage: led [on/off]");
    return;
  }

  if (strcmp(param, "on") == 0)
  {
    digitalWrite(12, HIGH);
    client.println("ESP32 Feedback: LED ON");
  }
  else if (strcmp(param, "off") == 0)
  {
    digitalWrite(12, LOW);
    client.println("ESP32 Feedback: LED OFF");
  }
}