#include <SimpleDHT.h>
//Arduino Nano

const int pinDHT11 = 2;
SimpleDHT11 dht11;

const int r=5;//red LED pin
const int g=4;//green LED pin
const int b=3;//blue LED pin

const int tmin=19;//minimum temperature
const int tmax=21;//maximum temperature
const int reading_time=1000;//how often the measurements are made(1s=1000ms)

void setup() {                
  Serial.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);  
}
void loop() {
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, ");
  Serial.print((int)humidity); Serial.println(" %");
  if(temperature < tmin){
    digitalWrite(r,LOW);
    digitalWrite(g,LOW);
    digitalWrite(b,HIGH);
  }
  else if(temperature > tmax){
    digitalWrite(r,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
  }
  else{
    digitalWrite(r,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(b,LOW);
  }

  delay(reading_time);
}
