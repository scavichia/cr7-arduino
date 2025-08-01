#include <SoftwareSerial.h>
#include <AFMotor.h> 

int speedFORWARD = 255; // Maximum speed for forward movement
int speedTURN = 255; // Speed used for turning (can be customized separately)

SoftwareSerial BT(14,15); 


AF_DCMotor motorD(3); 
AF_DCMotor motorE(4); 

char dato; // Variable to store received data from Bluetooth

void setup() {
  motorD.run(RELEASE);
  motorE.run(RELEASE);

  motorD.setSpeed(speedFORWARD);
  motorE.setSpeed(speedFORWARD);

  BT.begin(9600);
  Serial.begin(9600);
}

void loop() {
  if(BT.available()) {
    dato = BT.read();
    Serial.print("Recebido: ");
    Serial.println(dato);

    switch (dato) {
      case 'F': // Move Forward
        motorD.setSpeed(speedFORWARD);
        motorE.setSpeed(speedFORWARD);
        motorD.run(FORWARD);
        motorE.run(FORWARD);
        break;

      case 'B': // Move Backward
        motorD.setSpeed(speedFORWARD);
        motorE.setSpeed(speedFORWARD);
        motorD.run(BACKWARD);
        motorE.run(BACKWARD);
        break;

      case 'L': // Turn Left
        motorD.setSpeed(speedFORWARD);
        motorE.setSpeed(speedFORWARD);
        motorD.run(FORWARD);
        motorE.run(BACKWARD);
        break;

      case 'R': // Turn Right
        motorD.setSpeed(speedFORWARD);
        motorE.setSpeed(speedFORWARD);
        motorD.run(BACKWARD);
        motorE.run(FORWARD);
        break;

      case 'S': // Stop all motors
        motorD.run(RELEASE);
        motorE.run(RELEASE);
        break;
    }
  }
}
