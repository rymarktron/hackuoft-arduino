// Header Files
#include <LiquidCrystal.h> 

int Contrast=75;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

//Produce a welcome message
 void setup()
 {
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
 }

//Get user input
void keyCheck(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
  }
}

