// constants won't change. They're used here to set pin numbers:
const int ledPinWhiteLeft =  2;  
const int ledPinGreen = 3; 
const int ledPinWhiteRight = 4;
const int ledPinRed = 5;

const int ButtonPinYellow = 6;
const int ButtonPinTouch = 7;

// variables will change:
int buttonStateYellow = 0;
int buttonStateTouch = 0; 

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPinWhiteLeft, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinWhiteRight, OUTPUT);
  pinMode(ledPinRed, OUTPUT);

  pinMode(ButtonPinYellow, INPUT);
  pinMode(ButtonPinTouch, INPUT);

  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonStateYellow = digitalRead(ButtonPinYellow);
  buttonStateTouch = digitalRead(ButtonPinTouch);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:

  if (buttonStateYellow == HIGH) {
    // turn LED on:
    digitalWrite(ledPinWhiteLeft, HIGH);
    digitalWrite(ledPinGreen, HIGH);

    digitalWrite(ledPinWhiteRight, LOW);
    digitalWrite(ledPinRed, LOW);

    Serial.println(buttonStateYellow);
    buttonStateYellow = 0;
    
  } 
  else if (buttonStateTouch == HIGH){
    digitalWrite(ledPinWhiteRight, HIGH);
    digitalWrite(ledPinRed, HIGH);

    digitalWrite(ledPinWhiteLeft, LOW);
    digitalWrite(ledPinGreen, LOW);

    Serial.println(buttonStateTouch);
    buttonStateTouch = 0;
        
  } else {
    // turn LEDs off:
    digitalWrite(ledPinWhiteRight, LOW);
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinWhiteLeft, LOW);
    digitalWrite(ledPinGreen, LOW);
    delay(1000);
    buttonStateYellow = 1;
    buttonStateTouch = 1;
  }
}
