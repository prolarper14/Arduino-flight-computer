#include <Wire.h>
#include "MPU9250.h"


MPU9250 mpu;

void setup() {
  Serial.begin(9600);

  Wire.begin(9600);

  delay(2000);

  mpu.setup(0x68);

  Serial.println("MPU9250 initialized");
}

void loop() {
  if (mpu.update()) {

  Serial.println("--- ACCELEROMETER ---");

  Serial.print("X: ");
  Serial.println(mpu.getAccX());

  Serial.print("Y: ");
  Serial.println(mpu.getAccY());

  Serial.print("Z: ");
  Serial.println(mpu.getAccZ());

  Serial.println("--- GYROSCOPE ---");

  Serial.print("X: ");
  Serial.println(mpu.getGyroX());

  Serial.print("Y: ");
  Serial.println(mpu.getGyroY());

  Serial.print("Z: ");
  Serial.println(mpu.getGyroZ());

  Serial.println("--- MAGNETOMETER ---");

  Serial.print("X: ");
  Serial.println(mpu.getMagX());

  Serial.print("Y: ");
  Serial.println(mpu.getMagY());

  Serial.print("Z: ");
  Serial.println(mpu.getMagZ());

  Serial.println("----------------");
  }
  delay(100);
  
}
