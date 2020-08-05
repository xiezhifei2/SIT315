

int movement = 0;
int No_of_movement = 0;

void setup()
{
  pinMode(2, OUTPUT);//set pin 12 as output
  pinMode(A2,INPUT);//set pin A2 as output
  pinMode(3,INPUT);//set pin 3 as output
  pinMode(13, OUTPUT);//set pin 13 as output

  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), alarm, RISING );
  attachInterrupt(digitalPinToInterrupt(3), cap_movement, RISING );
}

void alarm()
{
  Serial.println("High temperature alarm!");
  Serial.print("Temp is:");
  Serial.print(analogRead(2));
  Serial.println("temperature >200");
}

void cap_movement()
{
  No_of_movement = No_of_movement+1;
  Serial.print("Total amount of movement is ");
  Serial.println(No_of_movement);
  digitalWrite(13, HIGH);
  delay(1000);
}

void loop()
{
  int Temperature=analogRead(2);
  movement=digitalRead(3);
  digitalWrite(13, LOW);
    
  if(Temperature<200)
  {
    //display current Temp 
    Serial.println("****************");
    Serial.print("current Temp is:");
    Serial.println(Temperature);
    digitalWrite(2, LOW);
  }
  if(Temperature>200)
  {
    digitalWrite(2, HIGH);
  }
  
  delay(1000); // Wait for 1000 millisecond(s)
}