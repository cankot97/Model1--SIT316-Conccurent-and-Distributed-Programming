const int buttonPin = 2;     
const int ledPin =  13;      
int celsius = 0;

// variables will change:
volatile int buttonState = 0;         
void setup() {
  
  pinMode(A0, INPUT);
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // Attach an interrupt to the ISR vector
  attachInterrupt(digitalPinToInterrupt(buttonPin), pin_ISR, CHANGE);
}

void loop() {
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print(celsius);
  Serial.println("C");
  if(celsius >= 40)
  {
    digitalWrite(ledPin,HIGH);
  	Serial.print("Too Hot");
  	Serial.println("Temperature: LED ON");
  }
  else
  {
      digitalWrite(ledPin,LOW);

  }
  delay(1000); 
}

void pin_ISR() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin, buttonState);
  Serial.println("INTERRUPTED");
}
