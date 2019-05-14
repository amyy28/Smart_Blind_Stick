#include <Ultrasonic.h>

Ultrasonic ultrasonic(3,2); // (Trig PIN,Echo PIN)
char data=0;
void setup() 
{
    Serial.begin(9600); 
    pinMode(12,OUTPUT); //ultrasound controlled buzzer
    pinMode(13,OUTPUT); //bluetooth controlled buzzer
    pinMode(A1,INPUT); // for LDR  
}

void loop()
{
  int CM1=ultrasonic.Ranging(CM);
  int inte=analogRead(A1); 
  int a= map(CM1,0,51,50,200); //to set length of delay duration
  if(inte>980) // LDR on/off
  {
    tone(12,500);
    delay(250);
  }  
  else 
    noTone(12);
  if(CM1<45)   // Ultrasonic on/off
  { 
    tone(12,5000);
    delay(a);
    noTone(12);
    delay(a);
  }
    
  if(Serial.available() > 0)   // Send data only when you receive data: Reading pipe available or not
  {
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.println(data);      //Print Value inside data in Serial monitor
    if(data == '1')            //Checks whether value of data is equal to 1 
      digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
    else if(data == '0')       //Checks whether value of data is equal to 0
      digitalWrite(13, LOW);   //If value is 0 then LED turns OFF
  }                      
}
