void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  Serial.write("This is a test\n");
  i++;
  delay(2000);
}
