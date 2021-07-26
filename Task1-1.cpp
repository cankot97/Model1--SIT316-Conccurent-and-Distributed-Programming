// C++ code
//

float celsius;
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(celsius);
  if(celsius > 35){
    Serial.println("Too Hot");
    digitalWrite(13, HIGH);
  }
  else{
  	digitalWrite(13, LOW);
  }
  
  
}