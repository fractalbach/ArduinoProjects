/*
 * Keyboard Instrument
 * (Project 7 from the Ardunio Projects Book)
 * 
 * Buttons and resistor are wired up in parallel
 * to create a "resistor ladder". Pressing a button can be thought of
 * as "adding another parallel resistor" to the circuit.  Due to Ohm's
 * Law V=IR,  The voltage will decrease across the circuit, and the
 * value in A0 will decrease.
 * 
 * Pins
 *  8: piezo speaker
 * A0: variable voltage used to determine pitch
 * 
 */

const int keyPin = A0;
const int speakerPin = 8;

int notes[] = {262, 294, 330, 392};

int keyVal = 0;

void setup() 
{
        Serial.begin(9600);
}

void loop() 
{
        keyVal = analogRead(keyPin);
        Serial.println(keyVal);
        handleSpeaker();
}

void handleSpeaker()
{
        if (keyVal == 1023) {
                tone(speakerPin, notes[0]);
        } 
        else if ((keyVal >= 990) && (keyVal <= 1010)) {
                tone(speakerPin, notes[1]);
        }
        else if ((keyVal >= 505) && (keyVal <= 515)) {
                tone(speakerPin, notes[2]);
        }
        else if ((keyVal >= 1) && (keyVal <= 30)) {
                tone(speakerPin, notes[3]);
        }
        else {
                noTone(speakerPin);
        }
}
