const int buttonPin = 2;     
const int ledPin =  13;      

// variables will change:
volatile int buttonState = 0;         
void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  //attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, CHANGE);
}

void loop() {
  digitalRead(buttonPin);
  if (digitalRead(buttonPin) == HIGH){
  	digitalWrite(ledPin, HIGH);
    Serial.println("LED ON");
  }
  else 
  {
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
  }
}

