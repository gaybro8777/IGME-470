/*
 * Resources
 * WM Harris Serial demo Code
 * 
WM Harris 470.7-2 demo Serial with dfR Mic & Knock sensors 3.10.21
Read and send mic data ALWAYS
Checks knock sensor less, and sends KNOCK message if above threshold.

adapted from Knock Sensor and Debounce examples

  If doing an MEAS circuit:
  - positive connection of the piezo attached to analog in pin
  - negative connection of the piezo attached to ground
  - 1 megohm resistor attached from analog in 0 to ground
  http://www.arduino.cc/en/Tutorial/Knock
*/

/* Global variables */

/* LED connected to digital pins */
const int ledPinRed = 6;     
const int ledPinGreen = 5; 
const int ledPinWhite = 4; 

/* Analog Pins */
const int buttonPin = A2;    
const int mic = A4; 

const int threshold = 70;  // threshold value for detected vibration is a knock

unsigned long lastKnockTime = 0;  // the last time the knock sensor was read
unsigned long knockDelay = 10;    // time between knock sensor readings


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorReading = 0;      // variable to store the value read from the sensor pin

int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
  //LED Setup
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinWhite, OUTPUT);

  // use the serial port
  Serial.begin(9600);      
}

void loop() {
  // read the mic and always send it to computer:
  Serial.print("Mic Level "); 
  Serial.println(analogRead(mic));
  
  sensorReading = analogRead(mic);

  //read the button state 
  buttonState = digitalRead(buttonPin);


  // If it is time, read knock sensor and store it:
  if (millis() - lastKnockTime > knockDelay) {
    lastKnockTime = millis();
    sensorReading = analogRead(buttonPin);

    
    /* if (sensorReading > 20) { //half a knock? noise?
      Serial.println(sensorReading);
    }*/

      // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
        if (buttonState == HIGH) {
              if (sensorReading){
          // turn LED on:
          digitalWrite(ledPinRed, HIGH);
          digitalWrite(ledPinGreen, HIGH);          
          digitalWrite(ledPinWhite, HIGH);    
              }
          } 
        else {
          // turn LED off:
          digitalWrite(ledPinRed, LOW);
          digitalWrite(ledPinGreen, LOW);          
          digitalWrite(ledPinWhite, LOW);    
        }

    // if the sensor reading at the threshold:
    if (sensorReading >= threshold) {
      // toggle the status of the ledPin:
      ledState = !ledState;
      // update the LED pin itself:
      digitalWrite(ledPinRed, ledState);
      // send the string "Knock!" to the computer
      Serial.println("Button Pressed!");
      // delay even more to avoid knock bounciness
      lastKnockTime = lastKnockTime + 60;
    }
  }
}
