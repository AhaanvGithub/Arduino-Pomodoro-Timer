#include <LiquidCrystal.h>
int S = 0; // count seconds 
int M = 25; // count minutes
int H = 0; // count hours
int buttonPin=8; // start button connected to pin 8
int buttonValue;
int yeet=2; // responsible for detecting whether it is break time or work time
int buttonPin2=7; // pause button connected to pin 7
int buttonValue2;
int piezoPin=9; // positive of piezo goes to pin 9

//initialize the library with the numbers of the interface pins
LiquidCrystal lcd(4,6,10,11,12,13); // pins connected to LCD
 
void setup()
{
 lcd.begin(16,2);// set up the LCD's number of columns and rows
 // initialize inputs and outputs
 pinMode(buttonPin, INPUT); 
 pinMode(buttonPin2, INPUT);
 pinMode(piezoPin, OUTPUT);
 digitalWrite(buttonPin, HIGH); // reads 1 
 digitalWrite(buttonPin2, HIGH); // reads 1
 Serial.begin(9600); // this is just for logging
}

void loop()
{
 buttonValue=digitalRead(buttonPin); // buttonValue will be 1 unless pressed
 buttonValue2=digitalRead(buttonPin2); // buttonValue2 will be 1 unlessed pressed
 if(buttonValue==1) // if the start button is not pressed
 {
   lcd.setCursor(1,0);
   lcd.print("Press to start");
 }
 else // if the person presses the start button
 {
   while(buttonValue2==1) // while the pause button is not pressed
   {
      buttonValue2=digitalRead(buttonPin2);
      Serial.print("Button: ");
      Serial.println(buttonValue2); // for logging purposes 
      if(buttonValue2 != 1) // if the pause button is pressed
      {
        break; // break the loop (stop)
      }
      else
      {
        // code for timer
        lcd.setCursor(1,0); 
        lcd.print ("Pomodoro Timer");
        lcd.setCursor(6,1);
        lcd.print(":");
        lcd.setCursor(9,1);
        lcd.print(":");

        S--; // decrease seconds by 1
        delay(1000); // wait for 1 second (1000 milliseconds)

        // self-explanatory
        if(S<0) 
        {
          M--;
          S=59;
        }
        if(M<0)
        {
          H--;
          M=59;
        }
        if(H<0) // if time runs out, i.e 0 hours, 0 minutes, 0 seconds
        {
          // code for saying work or break time has ended
          if (yeet%2 == 0) // if the variable yeet is divisible by 2, work time has ended
          {
            lcd.setCursor(1,0);
            lcd.print("Work  finished"); // add an extra space so it has the same characters as "Pomodoro Timer"
          }
          else // if the variable yeet is not divisible by 2, break time has ended
          {
            lcd.setCursor(1,0);
            lcd.print("Break finished");
            
          }         
          tone(piezoPin, 261); // make piezo buzz at 261 hertz
          delay(10000); // piezo buzzes for 10 seconds
          noTone(piezoPin); // stop piezo buzzing
          if (yeet%2 == 0) // if the variable yeet is divisible by 2, it must be break time
          {
            H=0; M=5; S=0;
            yeet++; // increase yeet by 1
          }
          else // if the variable yeet is not divisible by 2 that means it is work time
          {
            H=0; M=25; S=0;
            yeet++; // increase yeet by 1
          }
          
        }
        if(M>9) 
        {
          lcd.setCursor(7,1);
          lcd.print(M); // if m>9 there is no need to put a 0 before m so you just print m
        }
        else
        {
          // else you have to put a 0 before m
          lcd.setCursor(7,1);
          lcd.print("0"); 
          lcd.setCursor(8,1);
          lcd.print(M);
          lcd.setCursor(9,1);
          lcd.print(":");
        }

        if(S>9)
        {
          lcd.setCursor(10,1);
          lcd.print(S);
        }
        else
        {
          lcd.setCursor(10,1);
          lcd.print("0"); 
          lcd.setCursor(11,1);
          lcd.print(S);
          lcd.setCursor(12,1);
          lcd.print(" ");
        }

        if(H>9)
        {
          lcd.setCursor(4,1);
          lcd.print (H);
        }
        else
        {
          lcd.setCursor(4,1);
          lcd.print("0"); 
          lcd.setCursor(5,1);
          lcd.print(H);
          lcd.setCursor(6,1);
          lcd.print(":");
        }
      }
   }
 }
  
  
}
