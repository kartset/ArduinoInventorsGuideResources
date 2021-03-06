#include<Servo.h>
Servo myServo;

/********************************************************************************
   Arduino Inventor's Guide - Project 7 (Listing 7-5)
   Desktop Greenhouse  
 
   Adding servo control for the AutoVent to open / close the greenhouse window

   When the temperature rises above "setPoint," servo moves (open window)
   When the temperature drops below the "returnPoint," servo moves back (closes window)
  
   Written by: Derek Runberg & Brian Huang, July 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int rawSensorValue;
float rawVolts;
float tempC;
float tempF;
int setPoint = 85;
int returnPoint = 83;

void setup() 
{  
  myServo.attach(9, 1000, 2000);  //initializes myServo object
  Serial.begin(9600);  //initializes the serial communication
  Serial.print("raw");
  Serial.print("\t");  //tab character
  Serial.print("volts");
  Serial.print("\t");
  Serial.print("degC");
  Serial.print("\t");
  Serial.print("degF");
  
  Serial.println();    //new line character
}
void loop()
{
  rawSensorValue = analogRead(A0);
  rawVolts = volts(rawSensorValue);  //convert sensor value
                                     //to volts
  tempC = 100 * rawVolts - 50;   //convert volts to deg. C
  tempF = 1.8 * tempC + 32;      //convert deg. C to deg. F
  
  Serial.print (rawSensorValue);  //print raw sensor value
  Serial.print("\t");
  Serial.print (rawVolts);  //print raw voltage reading 

  Serial.print("\t");
  Serial.print(tempC);
  Serial.print("\t");
  Serial.print(tempF);

  Serial.println();         //new line character

  if(tempF > setPoint)
  {
    myServo.write(180);
  }
  else if(tempF < returnPoint)
  {
    myServo.write(0);    
  }
  delay(1000);
}

/**************************************************************************/
float volts(int rawCount)
{
   float AREF = 5.0;
   float calculatedVolts;
   calculatedVolts = rawCount * AREF / 1023;
   return calculatedVolts;
}

