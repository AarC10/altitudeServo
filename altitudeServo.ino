// Map altitude values to degrees for altimeter
// 145 = 0 ft
// 73 = 30,000 ft
#include <Arduino.h>
#include <Servo.h>

const double ALTITUDE_TO_DEGREE_CONVERSION;
Servo myServo;
int angle;
int altitudeInt;
int degrees;
String altitudeString;
char readChar;


void setup() {
    // Set baud rate
    Serial.begin(9600);

    // Setup servo
    myServo.attach(8); // TODO: Need to figure out pin
    myServo.write(140); // 145 degrees represents 0 altitude as initial


}

int convertAltitudeToDegrees(int altitude) {
    // Converts altitude to degrees that should be written to servo
    int degrees = map(altitude, 0, 30000, 140, 70);

    return degrees;
}


void loop() {
    
    while (!Serial.available()) {};
    
    readChar = Serial.read();

    
    if (readChar == '\n') {

      
        altitudeInt = altitudeString.toInt();

        Serial.println(altitudeString);
        

        if ((0 <= altitudeInt) && (altitudeInt <= 30000)) {
          Serial.println(altitudeInt);
          angle = convertAltitudeToDegrees(altitudeInt);  
          myServo.write(angle);
        }
    
        altitudeString = "";
        
    } else {
       altitudeString += readChar;
      
    }
}
