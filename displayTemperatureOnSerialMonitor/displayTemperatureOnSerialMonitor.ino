// Include the OneWire.h and DallasTemperature.h libraries (make sure you already have these libraries installed in your Arduino IDE)
#include <OneWire.h>
#include <DallasTemperature.h>

// Change 2 to where the data wire of the temperature sensor is plugged into (any digital pin of the Arduino)
// In this case the data wire of the temperature sensor is plugged into the digital pin 2 of the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with the OneWire device (DS18B20 temperature Sensor)
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup(void) {
  // Start up the library and search for the temperature sensor
  sensors.begin(); 
  // Start up serial communication with the serial monitor
  Serial.begin(9600);
}

void loop(void) { 
  // Send the command to the temperature sensor to perform a temperature reading
  sensors.requestTemperatures(); 

  //  Print the temperature reading in degrees celsius on the serial monitor
  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("°C");

  //  Add a delay of 1000 milisecond between each temperature reading 
  //  You can change the delay to do temperature readings faster or slower
  delay(1000);
}
