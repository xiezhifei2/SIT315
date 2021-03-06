void setup()
{
  pinMode(12, OUTPUT);//set pin 12 as output
  pinMode(8, OUTPUT);//set pin 8 as output
  pinMode(A2,INPUT);//set pin A2 as output
  Serial.begin(9600);
}

void loop()
{
  int Temperature=analogRead(2);
  if(Temperature<200)
  {
    //display current Temp
    Serial.print("current Temp is:");
    Serial.println(Temperature);
    
    digitalWrite(12, LOW);//turn off the red light 
    digitalWrite(8, HIGH);//Green light keep on
    
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if(Temperature>200)
  {
    //alarm temp>100
    Serial.print("High temperature alarm! current Temp is:");
    Serial.println(Temperature);
    
    digitalWrite(8, LOW);//turn off the green light 
    
    digitalWrite(12, HIGH);//turn on the red light 
    
    delay(1000); // Wait for 1000 millisecond(s)
  }
}