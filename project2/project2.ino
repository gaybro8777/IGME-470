/* LED connected to digital pins */
const int ledPinRed = 3;     
const int ledPinWhite = 4; 
const int ledPinGreen = 5; 

/* Analog Pins */
const int buttonPin = 16;    
const int mic = A3; 

const int threshold = 70;  // threshold value for detected vibration is a knock

unsigned long lastKnockTime = 0;  // the last time the knock sensor was read
unsigned long knockDelay = 10;    // time between knock sensor readings


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorReading = 0;      // variable to store the value read from the sensor pin

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

  //read analog and digital sensors
  sensorReading = analogRead(mic);
  buttonState = digitalRead(buttonPin);

    //check for noise
    if (sensorReading > 20) {
        if (buttonState == HIGH) {
          delay(10);
          // turn LED on:
          digitalWrite(ledPinRed, HIGH);
          digitalWrite(ledPinGreen, LOW);          
          digitalWrite(ledPinWhite, LOW);  
        }
    } 
    //check for louder noise
    else if (sensorReading > 400) {
        if (buttonState == HIGH) {
           delay(10);         
          // turn LED on:
          digitalWrite(ledPinWhite, HIGH);
          digitalWrite(ledPinGreen, LOW);          
          digitalWrite(ledPinRed, LOW);  
        }
    }
    //check for super loud noise
    else if (sensorReading > 600) {
         if (buttonState == HIGH) {
           delay(10);         
          // turn LED on:
          digitalWrite(ledPinGreen, HIGH);
          digitalWrite(ledPinWhite, LOW);          
          digitalWrite(ledPinRed, LOW);  
        }
    }
    else {
      // turn LED off:
      digitalWrite(ledPinRed, LOW);
      digitalWrite(ledPinGreen, LOW);          
      digitalWrite(ledPinWhite, LOW);    
     }

 /* if (millis() - lastKnockTime > knockDelay) {
    lastKnockTime = millis();
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
  }*/
}
