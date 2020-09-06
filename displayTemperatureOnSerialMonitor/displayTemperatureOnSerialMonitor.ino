#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);  

DallasTemperature sensors(&oneWire);

void setup(void) {
  sensors.begin();  
  Serial.begin(9600);
}
void loop(void) { 
  sensors.requestTemperatures(); 

  Serial.print("Temperature: ");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("°C");
  
  delay(1000);
}
