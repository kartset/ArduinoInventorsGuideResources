/********************************************************************************
   Arduino Inventor's Guide - Project 7 (Listing 7-3)
   Desktop Greenhouse  
   
   Example sketch - reads analog input from A0 and prints out
   the raw ADC value and the voltage
   
   Written by: Derek Runberg & Brian Huang, July 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

int rawSensorValue;
float rawVolts;

void setup() 
{  
  Serial.begin(9600);  //initializes the serial communication
  Serial.print("raw");
  Serial.print("\t");  //tab character
  Serial.print("volts");
  Serial.println();    //new line character
}
void loop()
{
  rawSensorValue = analogRead(A0);
  rawVolts = volts(rawSensorValue);  //convert sensor value
                                     //to volts
  Serial.print (rawSensorValue);  //print raw sensor value
  Serial.print("\t");
  Serial.print (rawVolts);  //print raw voltage reading 
  Serial.println();         //new line character
}

/**************************************************************************/
float volts(int rawCount)
{
   float AREF = 5.0;
   float calculatedVolts;
   calculatedVolts = rawCount * AREF / 1023;
   return calculatedVolts;
}

