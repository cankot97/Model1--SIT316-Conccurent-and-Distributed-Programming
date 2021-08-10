int INTPIN1 = 2; 
int INTPIN2 = 3;
int ledPin = 13;
void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(INTPIN1, INPUT_PULLUP);
  pinMode(INTPIN2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(INTPIN1), ISR1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(INTPIN2), ISR2, CHANGE);
}

void ISR1(){
  Serial.print("Motion sensor 1 :");
  Serial.println(digitalRead(INTPIN1));
  digitalWrite(ledPin, HIGH);
}

void ISR2(){
  Serial.print("Motion sensor 2:");
  Serial.println(digitalRead(INTPIN2));
  digitalWrite(ledPin, HIGH);
	
}

void loop() {

}