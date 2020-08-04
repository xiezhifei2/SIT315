void setup()
{
  pinMode(2, OUTPUT);//set pin 12 as output
  pinMode(A2,INPUT);//set pin A2 as output
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), test, RISING );
}

void test()
{
  Serial.print("High temperature alarm!");
  Serial.print("Temp is:");
  Serial.println(analogRead(2));
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
    
    digitalWrite(2, LOW);//turn off the red light 
    
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if(Temperature>200)
  { 
    digitalWrite(2, HIGH);//turn on the red light 
    
    delay(1000); // Wait for 1000 millisecond(s)
  }
}