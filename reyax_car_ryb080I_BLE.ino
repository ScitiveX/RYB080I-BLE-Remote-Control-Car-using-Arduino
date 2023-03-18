// Code by : ScitiveX
// Arduino Wireless BLE car using REYAX RYB080I_Lite Module
//
//    ___              _      _        _                    __  __
//   / __|    __      (_)    | |_     (_)    __ __    ___   \ \/ /
//   \__ \   / _|     | |    |  _|    | |    \ V /   / -_)   >  <
//   |___/   \__|_   _|_|_   _\__|   _|_|_   _\_/_   \___|  /_/\_\  
// _|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|
// "`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'

// Video Link - https://youtu.be/uq7WTr2jQmE

// Libraries
#include <SoftwareSerial.h>

// Create a SoftwareSerial object for the RX (receive) and TX (transmit) pins
SoftwareSerial mySerial(2, 3);

const int horn = 13;

// motor pins
const int motor1Pin1 = 5;
const int motor1Pin2 = 6;
const int motor2Pin1 = 9;
const int motor2Pin2 = 10;

// LED pins
const int frontLed1Pin = 11;
const int frontLed2Pin = 12;
const int backLed1Pin = 7;
const int backLed2Pin = 8;

const int blinkInterval = 100;

void setup() {
  Serial.begin(9600);

  // Set the baud rate for the SoftwareSerial object
  mySerial.begin(9600);


  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);


  pinMode(frontLed1Pin, OUTPUT);
  pinMode(frontLed2Pin, OUTPUT);
  pinMode(backLed1Pin, OUTPUT);
  pinMode(backLed2Pin, OUTPUT);

  pinMode(horn, OUTPUT);

  alloff();
}

void loop() {

  if (mySerial.available()) {
    // Read the incoming byte
    char incomingByte = mySerial.read();
    Serial.println(incomingByte);
    // Serial.println(incomingByte);

    switch (incomingByte) {
      case '1':
        // Forward
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW);

        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);

        digitalWrite(frontLed1Pin, HIGH);
        digitalWrite(frontLed2Pin, HIGH);
        digitalWrite(backLed1Pin, LOW);
        digitalWrite(backLed2Pin, LOW);


        break;
      case '2':
        // Backward
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);

        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);

        digitalWrite(backLed1Pin, HIGH);
        digitalWrite(backLed2Pin, HIGH);
        digitalWrite(frontLed1Pin, LOW);
        digitalWrite(frontLed2Pin, LOW);

        break;
      case '3':
        // Left
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        //blinkDipperLeft();

        break;
      case '4':
        // Right
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        //blinkDipperRight();
        break;
      case '5':
        // Turn front lights on or off
        if (digitalRead(frontLed1Pin) == LOW) {
          digitalWrite(frontLed1Pin, HIGH);
          digitalWrite(frontLed2Pin, HIGH);
        } else {

          // Turn off the front lights
          digitalWrite(frontLed1Pin, LOW);
          digitalWrite(frontLed2Pin, LOW);
        }
        break;
      case '6':
        // Turn back lights on or off
        if (digitalRead(backLed1Pin) == LOW) {
          digitalWrite(backLed1Pin, HIGH);
          digitalWrite(backLed2Pin, HIGH);
        } else {
          // Turn off the back lights
          digitalWrite(backLed1Pin, LOW);
          digitalWrite(backLed2Pin, LOW);
        }
        break;

      case '7':
        // Turn back lights on or off
        alloff();
        break;

      case '8':
        digitalWrite(horn, HIGH);
        delay(10);
        break;
      case '9':
        digitalWrite(horn, LOW);
        delay(10);
        break;
      default :
        alloff();
        break;
    }
  }
}

void blinkDipperLeft() {
  // Blink the left dipper
  digitalWrite(backLed1Pin, HIGH);
  digitalWrite(backLed2Pin, LOW);
  delay(blinkInterval);
  digitalWrite(backLed1Pin, LOW);
  digitalWrite(backLed2Pin, LOW);
  delay(blinkInterval);
}

void blinkDipperRight() {
  // Blink the right dipper
  digitalWrite(backLed1Pin, LOW);
  digitalWrite(backLed2Pin, HIGH);
  delay(blinkInterval);
  digitalWrite(backLed1Pin, LOW);
  digitalWrite(backLed2Pin, LOW);
  delay(blinkInterval);
}

void alloff(void) {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(10);
}
