// Important libraries that are needed. Keypad is typically not included
#include <LiquidCrystal.h> 
#include <Keypad.h>

const int trigPin = 7;
const int echoPin = 8;

const char* topLine[] = {"Katherine", "American", "whose", "orbital mechanics", "employee were", "success of the", "subsequent", "spaceflights.", "about physics &", "into space with", "Play around with", "and see how the", "changes."};
const char* bottomLine[] = {"Johnson was an", "mathematician", "calculations of", "as a NASA", "critical to the", "first and", "U.S. crewed", "You can learn", "shoot your ideas", "this launcher.", "the cannon angle", "ball trajectory", ""};

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
     lcd.print("Welcome to");

     lcd.setCursor(0, 1);
     lcd.print("Ball Launcher");

     //if ()
     delay(10000);
     lcd.clear();

     lcd.setCursor(0,0);
     lcd.print("Wave hand near");

     lcd.setCursor(0,1);
     lcd.print("motion sensor");
     delay(5000);
  } 

//Check if it is going
void loop()
 { 
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
       
       for (int i=0;i<13;i++)
       {
          lcd.setCursor(0,0);
          lcd.print(topLine[i]);
          lcd.setCursor(0,1);
          lcd.print(bottomLine[i]);
          delay(4000);
          lcd.clear();
       }

     }
     delay(5000);
     lcd.clear();
 }
 //Katherine Johnson was an American mathematician whose calculations of orbital mechanics as a NASA employee were critical to the success of the first and subsequent U.S. crewed spaceflights.
