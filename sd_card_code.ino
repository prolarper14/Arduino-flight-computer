#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
void setup() {
  Serial.begin(9600);

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed");
    return;
  }
  Serial.println("SD card Initialized!");

}

void loop() {
  // put your main code here, to run repeatedly:

}
