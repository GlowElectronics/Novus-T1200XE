////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////                                                                                                            ////
////  Novus T1200XE Power Management                                                                            ////
////                                                                                                            ////
////  Select "Arduino Pro or Pro Mini" under "Arduino AVR Boards"                                               ////
////                                                                                                            ////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// For D7 boards

#include <Arduino.h>
#include <Wire.h>

String ver = "Novus T1200XE 1.0";
String build = "0.8 PA";
String builddate = "Mar 1, 2026";
String welcome = String(ver) + " | " + String(build) + " | " + String(builddate);
char val; // receiving data from the serial port

// Power & Reset
int pwrSwPin=2; // the power button
int pwrEnPin=3; // the signal to enable TPS22965 #1
int railPin=10; // the 5V rail load switch
boolean pwrSwLast=LOW;
boolean pwrSwCurrent=LOW;
boolean pwrEn=true;

// Switching
int neg22Sw=8; // negative 22 volt control (and negative 9 volt too)

// Signals
int batSense=6; // Main battery charge status
int batVoltage=5; // Main battery voltage status
int intdsp=9; // Use: Goes HIGH when the lid switch is pressed. We're using this signal to toggle CBLON (Backlight)
int cpcnf=11; // Use: Might tell the power board how to set regulation for CPU/FPU mode, or just be a status/config latch. (Testing)
int chg=14; // Use: Applying 5V to this pin makes the battery LED glow green.
int lb=15; // Use: Applying 5V to this pin makes the battery LED glow red.
int beep=16; // Use: Drive with square wave for tones, or pulse for click. Probably TTL-level input. (Testing)
int cblon=17; // Backlight enable signal. Works with INTDSP.
int led=13; // Onboard LED

// Direct Connectivity
// pclr - reset button [Use: Output from PSU to motherboard]

/* Signal Breakout
Signal	Likely meaning	        Direction
PSSD	  Power Supply Shut Down	Motherboard → Power board
     or Power Supply Send Data
PSRD	  Power Supply Ready	    Power board → Motherboard
     or Power Supply Read Data
*/

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(115200); // start serial communication
  Serial.println(welcome); // print the version, build type and build date

  pinMode(pwrSwPin, INPUT);
  pinMode(pwrEnPin, OUTPUT);
  pinMode(railPin, OUTPUT);
  pinMode(neg22Sw, OUTPUT);
  pinMode(batSense, INPUT);
  pinMode(batVoltage, INPUT);
  pinMode(intdsp, INPUT);
  pinMode(cpcnf, INPUT);
  pinMode(chg, OUTPUT);
  pinMode(lb, OUTPUT);
  pinMode(beep, OUTPUT);
  pinMode(cblon, OUTPUT);
 
  // start low
  digitalWrite(pwrEnPin, LOW);
  delay(5);
  digitalWrite(railPin, LOW); // Inverted
  delay(5);
  digitalWrite(cblon, LOW);
  delay(5);
  digitalWrite(chg, LOW);
  delay(5);
  digitalWrite(lb, LOW);
  delay(5);
  digitalWrite(beep, HIGH); // Beeps forever if LOW or floating
  delay(5);

  //Ready triple-blink
  for (int i=0; i<3; i++){
  digitalWrite(13, HIGH);
  delay(75);
  digitalWrite(13, LOW);
  delay(75);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

boolean pwrSwBounce(boolean last) // the physical power switch needs time to stop "bouncing" before continuing
{
  boolean current = digitalRead(pwrSwPin);
  if (last != current)
  {
    delay (25);
    current = digitalRead(pwrSwPin);
  }
  return current;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Power Switch

void pwrSw()
{
  pwrSwCurrent = pwrSwBounce(pwrSwLast);
  if (pwrSwLast == LOW && pwrSwCurrent == HIGH)
  {
    pwrEn = !pwrEn;
  }
    pwrSwLast = pwrSwCurrent;
    digitalWrite(pwrEnPin, pwrEn);
    delay(400);
    digitalWrite(railPin, pwrEn);
    delay(25);
    digitalWrite(neg22Sw, pwrEn);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Display Switch

void displaySw()
{
  if (digitalRead(intdsp) == LOW)
  {
  digitalWrite(cblon, HIGH);
  }
  else
  digitalWrite(cblon, LOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void loop()
{
  pwrSw();
  displaySw();

    //watchdog
    digitalWrite(13, HIGH);
    delay(1);
    digitalWrite(13, LOW);
}
