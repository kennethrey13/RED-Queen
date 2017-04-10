/*
  Serial Event example

 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and
 clears it.

 A good test for this is to try it with a GPS receiver
 that sends out NMEA 0183 sentences.

 Created 9 May 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/SerialEvent

 */
#include  <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int red = 6;
int blue = 8;
int green = 7;
String command ="";

void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);

  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  
  pinMode(backLight, OUTPUT);          //set pin 13 as output
  analogWrite(backLight, 150);        //controls the backlight intensity 0-254
  lcd.begin(16,2);                    // columns, rows. size of display
  lcd.clear();                        // clear the screen
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    Serial.println(inputString);

 if (inputString.startsWith("turn")) {
     lcd.clear(); 
      inputString.replace(";", "");
      command = inputString;

if(command.equals("turn the red light on")){
   digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW); 
  digitalWrite(red, HIGH); 
  digitalWrite(green, LOW);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Red Light ON");
}


else if(command.equals("turn the blue light on")){
   digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Blue Light ON");
}


else if(command.equals("turn the green light on")){
   digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, HIGH);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Green Light ON");
}

else if(command.equals("turn the light off")){
  
  digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Light OFF");
}


else {

lcd.setCursor(0,0);
lcd.print("No Command Found");
  
  
}

  }


  if (inputString.startsWith("please")) {
     lcd.clear(); 
      inputString.replace(";", "");
      command = inputString.substring(7);

if(command.equals("turn the red light on")){
   digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW); 
  digitalWrite(red, HIGH); 
  digitalWrite(green, LOW);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Red Light ON");
}


else if(command.equals("turn the blue light on")){
   digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Blue Light ON");
}


else if(command.equals("turn the green light on")){
   digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, HIGH);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Green Light ON");
}

else if(command.equals("turn the light off")){
  
  digitalWrite(blue, LOW); 
  digitalWrite(red, LOW); 
  digitalWrite(green, LOW);

lcd.setCursor(0,0);
lcd.print("Command");
lcd.setCursor(0,1);
lcd.print("Light OFF");
}


else {

lcd.setCursor(0,0);
lcd.print("No Command Found");
  
  
}

  }
  

    
    // clear the string:
    inputString = "";
    stringComplete = false;
  }







  
}





/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == ';') {
      stringComplete = true;
    }
  }
}



