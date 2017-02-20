// Script to monitor water float position

const byte switchPin = 8;

void setup ()
  {
  Serial.begin (115200);
  pinMode (switchPin, INPUT_PULLUP);
  }  // end of setup

void loop ()
  {
  if (digitalRead (switchPin) == LOW)
     {
     Serial.println ("1");
     delay (1000); 
     } // end if switchState is LOW
     
   
  }  // end of loop
