// Map altitude values to degrees for altimeter
// 145 = 0 ft
// 73 = 30,000 ft
#include <Arduino.h>
#include <Servo.h>


Servo myServo;
int signed angle;
int altitudeInt;
String altitudeString;
char readChar;

void setup() {
    // Set baud rate
    Serial.begin(9600);

    // Setup servo
    myServo.attach(9); // TODO: Need to figure out pin
    myServo.write(0); // 145 degrees represents 0 altitude as initial


}

int convertAltitudeToDegrees(int altitude) {
    // Converts altitude to degrees that should be written to servo
    int degrees = map(altitude, 0, 30000, 145, 73);

    return degrees;
}


void loop() {

    while (readChar = Serial.read() != '\n') {
        if (!isDigit(readChar)) {
            altitudeString = "";
        }

        altitudeString += readChar;
    }

    altitudeInt = altitudeString.toInt();
    angle = convertAltitudeToDegrees(altitudeInt);
    myServo.write(angle);
    altitudeString = "";
}
