# Arduino Pomodoro Timer
A pomodoro timer for studying using arduino's LCD.

While working on something, I get distracted and maybe take a break randomly while working on the task at hand. On the other hand, I can get completely engrossed in what I’m working on and forget to take a break, which does not give my eyes and brain some rest. To prevent this bad habit, I can use the pomodoro technique. I will have 25 minutes of work time and 5 minutes of break time, and that counts as one interval. (Read more here https://en.wikipedia.org/wiki/Pomodoro_Technique) 

I could just use a timer on the internet, but then I wouldn’t be able to know how much time is left on the pomodoro (because I would be on a different tab.) Furthermore, if I’m doing something (like kumon) that’s not on the laptop or computer, it will be of no use. Therefore, I decided to build one using arduino and its LCD display.

## Requirements

The requirements for this project are: 

  - Needs to have a timer that counts down and notifies me with a buzz when it's at 0:00
  - A button switch to start the timer
  - A button switch to pause the timer in case I need to go to the bathroom or something
  - After work time is over, the break time should start.

## Materials

All of the materials are in the official arduino kit (except for the optional 9V battery.)
However, here is the full list:

  - Arduino Uno Board
  - LCD Display (16x2)
  - Potentiometer
  - Breadboard (half-sized will work)
  - Piezo
  - Two button switches
  - Jumper wires
  - Resistor (I used a 560 ohm one, but if you want the LCD to be brighter you can use a 220 ohm one.)

## Circuit Diagram

For the countdown timer, I used the tutorial from tutorial45.com -> https://tutorial45.com/building-an-arduino-countdown-timer/. I then had to change the circuit and code to have switch buttons and a piezo.

Tinkercad diagram: 
![Pomodoro Timer #2](https://user-images.githubusercontent.com/69446878/124607254-3dece100-dea0-11eb-8c9a-175f9fb85f6d.png) 

Real life picture with a 9v battery: 
![9v_battery](https://user-images.githubusercontent.com/69446878/124606908-f0707400-de9f-11eb-828a-3f25d4afba4e.JPG) 

## Video

