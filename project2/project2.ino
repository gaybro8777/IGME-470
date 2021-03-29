/* LED connected to digital pins */
const int ledPinRed = 3;     
const int ledPinWhite = 4; 
const int ledPinGreen = 5; 

/* Analog Pins */
const int buttonPin = 16;    
const int mic = A3; 

const int threshold = 70;  // threshold value for detected vibration is a knock

//from knock sensor tutorial
unsigned long lastSensorRead = 0;  // the last time the sensor was read


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int sensorReading = 0;      // variable to store the value read from the sensor pin

int sensorReadOver = 0;      

void setup() {
  //LED Setup
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinWhite, OUTPUT);

  pinMode(buttonPin, INPUT);
  
  // use the serial port
  Serial.begin(9600);      
}

void loop() {
  //read analog and digital sensors
  sensorReading = analogRead(mic);
  buttonState = digitalRead(buttonPin);
          digitalWrite(ledPinGreen, HIGH);       
   sensorReadOver = analogRead(sensorReading);
    
  // read the mic and always send it to computer:
  Serial.print("Mic Level "); 

    Serial.println(analogRead(sensorReading));
     
    if (buttonState == HIGH) {
        //check for noise
        if (sensorReadOver > 20 && sensorReadOver < 400) {
          delay(10);
          Serial.print("Red Low Noise"); 
          Serial.println(analogRead(sensorReadOver));    
          // turn LED on:
 
          digitalWrite(ledPinGreen, HIGH);          
          digitalWrite(ledPinWhite, LOW);  
        }
        //check for louder noise
        else if (sensorReadOver > 430 && sensorReadOver < 500) {
          delay(10);
          Serial.print("White some Noise");  
          Serial.println(analogRead(sensorReadOver));    
          // turn LED on:

          digitalWrite(ledPinGreen, HIGH);          
          digitalWrite(ledPinRed, LOW);  
        }
         //check for super loud noise
         else if (sensorReadOver > 500) {
          // delay(10);      
          Serial.print("Green Loud!");  
          Serial.println(analogRead(sensorReadOver)); 
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



}
