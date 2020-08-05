

void setup()
{
  pinMode(2, OUTPUT);//set pin 12 as output
  pinMode(A2,INPUT);//set pin A2 as output

  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), alarm, RISING );
}

void alarm()
{
  Serial.println("High temperature alarm!");
  Serial.print("Temp is:");
  Serial.print(analogRead(2));
  Serial.print("temperature >200");
}

void loop()
{
  int Temperature=analogRead(2);
    
  if(Temperature<200)
  {
    //display current Temp  
    Serial.print("current Temp is:");
    Serial.println(Temperature);
    digitalWrite(2, LOW);
    
    delay(1000); // Wait for 1000 millisecond(s)
  }
  
  if(Temperature>200)
  {
    digitalWrite(2, HIGH);
  }

}