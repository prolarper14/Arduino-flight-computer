float roll = 0;
float pitch = 0;
 //accellRoll = Accelerometers estimated roll angle
float accelRoll = 0;
float accelPitch = 0;

float gyroX = 0;
float gyroY = 0;

float dt = 0.01;

void setup() {
  Serial.begin(9600);
}

void loop() {

  // Simulated sensor readings
  accelRoll = 10;
  accelPitch = 5;

  gyroX = 0;
  gyroY = 0;

  // Complementary filter (Estimates new roll angle using prev angle + rotational speed)
  roll = 0.98 * (roll + gyroX * dt)
         + 0.02 * accelRoll;

  pitch = 0.98 * (pitch + gyroY * dt)
          + 0.02 * accelPitch;

  Serial.print("Roll: ");
  Serial.println(roll);

  Serial.print("Pitch: ");
  Serial.println(pitch);

  delay(1000);
}
