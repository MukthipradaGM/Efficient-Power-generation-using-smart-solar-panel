const int LDR = A1;
int input_val = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  input_val = analogRead(LDR);
  Serial.print((String)input_val+" ");
  delay(1000);
}
