#include <Servo.h>

Servo servo;

void setup() {
  servo.attach(8); // Attach to the servo on pin 9  

}

void loop() {
  for (int i = 140; i >= 70; i--) {
    servo.write(i);
    
  }

  for (int i = 70; i <= 140; i++) {
    servo.write(i);
  }
}
