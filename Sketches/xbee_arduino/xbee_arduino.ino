#define SWITCHPIN 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode (SWITCHPIN, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead (SWITCHPIN) == LOW)
  {
     Serial.println (1);
     delay (500); 
  }
  else
  {
    Serial.println (0);
    delay(500);
  }
}
