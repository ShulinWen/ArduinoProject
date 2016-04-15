#include <SoftwareSerial.h>
#include <Car.h>
#include <RemoteControl.h>
#include <Info.h>

Car* car= new Car();
RemoteControl* rCrl = new RemoteControl(Serial3, false); // no use timer
Info* info = new Info();

void setup() {
  int pins[12] = { 30, 31, 2, // front-left wheel (digital, digital,analog output)
                  32, 33, 3, // front-right wheel
                  34, 35, 4, // rear-left wheel
                  36, 37, 5  // rear-right wheel
                };
 car->setPins(pins);
 car->ParameterSetup(2.975, -6.45, -6.41, -6.41, -6.49);

Serial.begin(19200);
}

void loop() {
    rCrl->receiveMsg();
    info = rCrl->getCurrentState();
    car->Move(info);

//Serial.println((int)info->dir);
//delay(300);
}

