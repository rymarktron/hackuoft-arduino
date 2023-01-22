// Important libraries that are needed. Keypad is typically not included
#include <LiquidCrystal.h> 
#include <Keypad.h>

const int trigPin = 7;
const int echoPin = 8;

long duration;
int distance;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //use different IDs for the LCD for input digital I/O pins

int Contrast=75;
//Produce a welcome message
 void setup()
 {
    //pinMode(A0, OUTPUT);
    //digitalWrite(A0, HIGH);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    analogWrite(6,Contrast);
     lcd.begin(16, 2);
     lcd.setCursor(0, 0);
     lcd.print("Welcome! Press 1 to begin");

     //if ()
     delay(4000);
     lcd.clear();
  } 

//Check if it is going
void loop()
 { 
     lcd.setCursor(0, 0);
     lcd.print("Hello world");
   
    lcd.setCursor(0, 1);
     lcd.print("UofT Hacks");

     //determine the distsance
     digitalWrite(trigPin, LOW);
     delay(2);

     digitalWrite(trigPin, HIGH); //change in state
     delay(4);
     
     digitalWrite(trigPin, LOW);

     duration = pulseIn(echoPin, HIGH);
     distance = duration * 0.034/2;
     lcd.clear();
     if (distance <= 10)
     {
      lcd.print("ON");
     }
    else{
      lcd.print("OFF");
    }

     delay(1000);

 }

