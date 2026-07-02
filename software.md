## Software

The robot was programmed in C using the Arduino IDE.

Its control logic is based on Bluetooth communication. Commands received from a mobile device are interpreted by the Arduino, which controls two DC motors through the Adafruit Motor Shield.

The main implementation is shown below:

```cpp
#include <SoftwareSerial.h>
#include <AFMotor.h>

int speedFORWARD = 255;
int speedTURN = 255;

SoftwareSerial BT(14,15);

AF_DCMotor motorD(3);
AF_DCMotor motorE(4);

char dato;

void setup() {
    ...
}

void loop() {
    ...
}
```
