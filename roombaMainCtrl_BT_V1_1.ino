
#include "roombaDefines.h"
#include <SoftwareSerial.h>

// Roomba Create2 connection
int rxPin=10;
int txPin=11;
SoftwareSerial Roomba(rxPin,txPin);

// BT Module (HC-06)
SoftwareSerial BT1(8, 9); // El pin 8 es Rx y el pin 9 es Tx

//---------------------------------------------
void setup() 
{
  Roomba.begin(19200);
  BT1.begin(19200);
  Serial.begin(19200);
  
  pinMode(ddPin, OUTPUT);
  pinMode(ledPin, OUTPUT); //spare if needed for test purpose
  pinMode(buttonPin, INPUT_PULLUP); //used for "start" for test purposes

  delay(2000);
  Serial.print("Roomba Remote Control");
  BT1.print("Roomba Remote Control");
  BT1.println('\n');
  
  wakeUp ();   // Wake-up Roomba
  startSafe(); // Start Roomba in Safe Mode

  // turn-off all LEDs and Display
  setPowerLED(128,0);
  setDebrisLED(OFF);
  setDockLED(OFF);
  setSpotLED(OFF);
  setWarningLED(OFF);
  cleanDigitLED ();

  playSound (1); // start sound
  while (digitalRead(buttonPin))
  {  
    setDebrisLED(ON);
    writeLEDs ('-', '-', '-', '-');
  }
  setDebrisLED(OFF);
  writeLEDs ('s', 't', 'o', 'p');
  
   playSound (2);
   
  //Test Functions - Uncomment if needed 
  //motorSquareTest(); 
  //turnCW (40, 180);  
  //driveWheels(20, -20); 
  //driveLeft(20); 

}

void loop() 
{ 
   manualCmd ();
}
