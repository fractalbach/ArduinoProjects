
/* 
 * Light Theremin
 * Based on the tutorial in the arduino starter's pack.
 * Modified such that more light = lower pitch.
 * 
 * Calibration
 * - Start/Reset arduino
 * - Have light hit the photoresistor. (sets the max).
 * - Cover the photoresistor in the desired way (sets the min).
 * - Wait for the 5 second delay to finish.
 *  
 * Pins
 * A0:  Photoresistor
 *  8:  Speaker
 *  
 */

const int ledPin = 13;

const int pitchMax = 3000;
const int pitchMin = 31;

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
    digitalWrite(ledPin, LOW);
  }
}

void loop() {
  sensorValue = analogRead(A0);
  int pitch = map(
    sensorValue,
    sensorLow,
    sensorHigh,
    pitchMin,
    pitchMax
  );
  tone(
    8,
    pitchMax - pitch,
    20
  );
  delay(10);
}
