#include <Keyboard.h>

//PIN DECLARATION
const int pinButton1 = 13;
const int pinButton2 = 12;
const int pinButton3 = 11;
const int pinButton4 = 10;
const int pinButton5 = 9;
const int pinButton6 = 8;

const int pinSwitchPage1 = 7;
const int pinSwitchPage2 = 6;

const int pinSwitchProfil = 5;  

//BUTTONS STATES
int buttonState1;
int buttonState2;
int buttonState3;
int buttonState4;
int buttonState5;
int buttonState6;

int lastButtonState1 = HIGH;
int lastButtonState2 = HIGH;
int lastButtonState3 = HIGH;
int lastButtonState4 = HIGH;
int lastButtonState5 = HIGH;
int lastButtonState6 = HIGH;

//VARIABLES FOR DEBOUCE
unsigned long lastDebouceTime = 0;
unsigned long debouceDelay = 50;


void setup()
{
  pinMode(pinButton1, INPUT_PULLUP);
  pinMode(pinButton2, INPUT_PULLUP);
  pinMode(pinButton3, INPUT_PULLUP);
  pinMode(pinButton4, INPUT_PULLUP);
  pinMode(pinButton5, INPUT_PULLUP);
  pinMode(pinButton6, INPUT_PULLUP);
  
  pinMode(pinSwitchProfil, INPUT);

  pinMode(pinSwitchPage1, INPUT);
  pinMode(pinSwitchPage2, INPUT);
  
  Keyboard.begin();
  Serial.begin(9600);
}

void loop()
{
  //DECLARATION VARIABLES
  int readingButton1 = digitalRead(pinButton1);
  int readingButton2 = digitalRead(pinButton2);
  int readingButton3 = digitalRead(pinButton3);
  int readingButton4 = digitalRead(pinButton4);
  int readingButton5 = digitalRead(pinButton5);
  int readingButton6 = digitalRead(pinButton6);

  
  int switchPage1 = digitalRead(pinSwitchPage1);
  int switchPage2 = digitalRead(pinSwitchPage2);

  int switchProfil = digitalRead(pinSwitchProfil);
  
  int shortcutValueButton1;
  int shortcutValueButton2;
  int shortcutValueButton3;
  int shortcutValueButton4;
  int shortcutValueButton5;
  int shortcutValueButton6;

  int page;

  //BEGIN OF DEBOUCE METHOD
  if(readingButton1 != lastButtonState1){
    lastDebouceTime = millis();
  }
  if(readingButton2 != lastButtonState2){
    lastDebouceTime = millis();
  }
  if(readingButton3 != lastButtonState3){
    lastDebouceTime = millis();
  }
  if(readingButton4 != lastButtonState4){
    lastDebouceTime = millis();
  }
  if(readingButton5 != lastButtonState5){
    lastDebouceTime = millis();
  }
  if(readingButton6 != lastButtonState6){
    lastDebouceTime = millis();
  }

  if(switchPage1 == LOW && switchPage2 == LOW){
    //VALUE 0
    shortcutValueButton1 = 65;
    shortcutValueButton2 = 66;
    shortcutValueButton3 = 67;
    shortcutValueButton4 = 68;
    shortcutValueButton5 = 69;
    shortcutValueButton6 = 70;
    
    page = 0;
  }else if(switchPage1 == HIGH && switchPage2 == LOW){
    //VALUE 1
    shortcutValueButton1 = 71;
    shortcutValueButton2 = 72;
    shortcutValueButton3 = 73;
    shortcutValueButton4 = 74;
    shortcutValueButton5 = 75;
    shortcutValueButton6 = 76;

    page = 1;
  }else if(switchPage1 == LOW && switchPage2 == HIGH){
    //VALUE 2
    shortcutValueButton1 = 77;
    shortcutValueButton2 = 78;
    shortcutValueButton3 = 79;
    shortcutValueButton4 = 80;
    shortcutValueButton5 = 81;
    shortcutValueButton6 = 82;

    page = 2;
  }
  
  if((millis() - lastDebouceTime) > debouceDelay){
    if(readingButton1 != lastButtonState1){
      buttonState1 = readingButton1;

      if (readingButton1 == LOW) {
        Serial.println("Bouton 1 - ON");
        Serial.println("Ligne : ");
        Serial.println(line);
        Keyboard.write(shortcutValueButton1);
        delay(100);
        Keyboard.releaseAll();
      }
    }

    if(readingButton2 != lastButtonState2){
      buttonState2 = readingButton2;

      if (readingButton2 == LOW) {
        Serial.println("Bouton 2 - ON");
        Serial.println("Ligne : ");
        Serial.println(line);
        Keyboard.write(shortcutValueButton2);
        delay(100);
        Keyboard.releaseAll();
      }
    }

    if(readingButton3 != lastButtonState3){
      buttonState3 = readingButton3;

      if (readingButton3 == LOW) {
        Serial.println("Bouton 3 - ON");
        Serial.println("Ligne : ");
        Serial.println(line);
        Keyboard.write(shortcutValueButton3);
        delay(100);
        Keyboard.releaseAll();
      }
    }

    if(readingButton4 != lastButtonState4){
      buttonState4 = readingButton4;

      if (readingButton4 == LOW) {
        Serial.println("Bouton 4 - ON");
        Serial.println("Ligne : ");
        Serial.println(line);
        Keyboard.write(shortcutValueButton4);
        delay(100);
        Keyboard.releaseAll();
      }
    }

    if(readingButton5 != lastButtonState5){
      buttonState5 = readingButton5;

      if (readingButton5 == LOW) {
        Serial.println("Bouton 5 - ON");
        Serial.println("Ligne : ");
        Serial.println(line);
        Keyboard.write(shortcutValueButton5);
        delay(100);
        Keyboard.releaseAll();
      }
    }

    if(readingButton6 != lastButtonState6){
      buttonState6 = readingButton6;

      if (readingButton6 == LOW) {
        Serial.println("Bouton 6 - ON");
        Serial.println("Ligne : ");
        Serial.println(line);
        Keyboard.write(shortcutValueButton6);
        delay(100);
        Keyboard.releaseAll();
      }
    }
  }

  lastButtonState1 = readingButton1;
  lastButtonState2 = readingButton2;
  lastButtonState3 = readingButton3;
  lastButtonState4 = readingButton4;
  lastButtonState5 = readingButton5;
  lastButtonState6 = readingButton6;

}
