#include <SoftwareSerial.h>
SoftwareSerial bluetooth(7, 8);
unsigned long previousMillis = 0;


void setup() {
    // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  
}

void loop() {

 

  unsigned long currentMillis = millis();
  
    int sensor1 = analogRead(A0);
    int sensor2 = analogRead(A1);
    int sensor3 = analogRead(A2);

    int Top = map(sensor1,0,1023,100,0);
    int Center = map(sensor2,0,1023,100,0);
    int Under = map(sensor3,0,1023,100,0);

  if(currentMillis - previousMillis >= 1000){
      previousMillis = currentMillis;
      bluetooth.print(Top);
      bluetooth.print(",");
      bluetooth.print(Center);
      bluetooth.print(",");
      bluetooth.print(Under);
      bluetooth.println("");
  }

   char val;
   
  if(bluetooth.available()){
    val = (char)bluetooth.read();

    }

  if(val=='0')
    {
      Serial.println("연동 완료");
    }
    

     if(val=='3')  //30%
    {
      power(100);
    }

     if(val=='4')  //40%
    {
      power(180);
 
    }

     if(val=='6')  //60%
      {
        power(255);
      }

 }

void power( int n){

  analogWrite(3,n);
}


  
