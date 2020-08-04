int movement = 0;

void setup()
{
  pinMode(2, OUTPUT);//set pin 12 as output
  pinMode(A2,INPUT);//set pin A2 as output
  pinMode(4,INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), alarm, RISING);
  attachInterrupt(digitalPinToInterrupt(4), cap_movement, RISING);
}

void alarm()
{
  Serial.print("High temperature alarm!");
  Serial.print("Temp is:");
  Serial.println(analogRead(2));
  Serial.print("temperature >200");
}

void cap_movement()
{
 movement != movement;
}

void loop()
{
  int Temperature=analogRead(2);
  movement = digitalRead(4);
  
  if(movement == LOW)
  {
    Serial.println("There no movement");
  }
  if(movement == HIGH)
  {
    digitalWrite(13, HIGH);
    Serial.println("movement Captured"); 
  }
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