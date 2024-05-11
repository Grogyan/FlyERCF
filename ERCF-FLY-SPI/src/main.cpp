//#include "/pico/PicoSoftwareSerial.h"
//#include </pico-sdk/rp2040>
#include <Arduino.h>
#include "PicoSoftwareSerial.h"
#include <TMCStepper.h>

#include "Config.h"
#include "pins.h"


SoftwareSerial mySerial(Feeder_RX, MOT_SPI_MOSI_PIN);
//MySerial Serial2(Feeder_RX, MOT_SPI_MOSI_PIN);
int buttonState = 0;

void fastLED(void);
void slowLED(void);
  //Serial1.setRX(Feeder_RX);
  //Serial1.setTX(MOT_SPI_MOSI_PIN);

//HardwareSerial TMCSerial1(Feeder_RX, MOT_SPI_MOSI_PIN);
TMC2209Stepper driver(&mySerial, FEEDER_RSENSE, FEEDER_ADDRESS);
//TMC2209Stepper driver1(&Serial, FEEDER_RSENSE, FEEDER_ADDRESS_1);

void setup() {

  pinMode(LED_PIN, OUTPUT);
  pinMode(STOP_PIN, INPUT_PULLUP);
  pinMode(Feeder_EN_PIN, OUTPUT);

  mySerial.begin(115200);
  //mySerial.setPollingMode(true);
  digitalWrite(Feeder_EN_PIN, LOW);
  driver.begin();
  driver.toff(5);
  driver.rms_current(FEEDER_CURRENT);
  driver.microsteps(FEEDER_MICROSTEPS);
  driver.en_spreadCycle(FEEDER_SPREADCYCLE);
  driver.pwm_autoscale(true);
}

int32_t curr_speed = 0;
int32_t dest_speed = 1000 * FEEDER_MICROSTEPS;
int32_t acceleration = 10 * FEEDER_MICROSTEPS;

void ramp() {
  digitalWrite(LED_PIN, dest_speed > 0);
  while ((dest_speed > 0 && curr_speed < dest_speed) || (dest_speed < 0 && curr_speed > dest_speed)) {
    curr_speed += acceleration;
    driver.VACTUAL(curr_speed);
    delayMicroseconds(100);
  }
}

void loop() {
  while (true) {
    buttonState = digitalRead(STOP_PIN);
    if (digitalRead(STOP_PIN) == HIGH) {
      fastLED();
      delayMicroseconds(1000);
      driver.VACTUAL(dest_speed);
    } else {
      slowLED();
    }
  }
}

void fastLED(void) {
  digitalWrite(LED_PIN, HIGH);
  delay(250);
  digitalWrite(LED_PIN, LOW);
  delay(250);
}

void slowLED(void) {
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}