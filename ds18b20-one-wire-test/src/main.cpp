#include <Arduino.h>
#include <SoftwareSerial.h>

#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntec to the Arduino digital pin 4
// #define ONE_WIRE_BUS 4
#define ONE_WIRE_BUS PC6


SoftwareSerial mySerial(PA3, PA2); // RX, TX
// SoftwareSerial mySerial(8, 9); // RX, TX

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // Start serial communication for debugging purposes
  mySerial.begin(9600);
  // Start up the library
  sensors.begin();
}

void loop(void){ 
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  mySerial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  mySerial.print(sensors.getTempCByIndex(0)); 
  mySerial.print(" - Fahrenheit temperature: ");
  mySerial.println(sensors.getTempFByIndex(0));
  delay(1000);
}