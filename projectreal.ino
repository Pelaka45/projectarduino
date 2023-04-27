// Viral Science www.viralsciencecreativity.com www.youtube.com/c/viralscience
// Arduino Car Parking System

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address
#include <Servo.h> 

Servo myservo1;

int ir_2 = 2;
int ir_4 = 4;

int Slot = 6;           //Enter Total number of parking Slots

int flag1 = 0;
int flag2 = 0;
int ln=1,ln_1=1;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
pinMode(ir_2, INPUT);
pinMode(ir_4, INPUT);
  
myservo1.attach(3);
myservo1.write(0);

lcd.setCursor (0,0);
lcd.print("     ARDUINO    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (500);
lcd.clear();  
}
void loop(){ 
  lcd.clear(); 
  if(ln_1==1){
  if(digitalRead (ir_2) == LOW){
    ln=1;
  }
  else if(digitalRead (ir_4) == LOW ){
    ln=2;
  }
  ln_1=0;
  }
  if(digitalRead (ir_2) == LOW ){
    if(Slot<=0 && ln==1){
      myservo1.write(0);
      lcd.setCursor (0,0);
      lcd.print("    SORRY :(    ");  
      lcd.setCursor (0,1);
      lcd.print("  Parking Full  "); 
      delay (500);
      lcd.clear(); 
    }
    else if (Slot>0 && ln==1){
      myservo1.write(100);
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("Slot Left: ");
      lcd.print(Slot);
      delay (500);
    }
  }
  if(digitalRead (ir_4) == LOW && ln==1){
    if(ln==1){
      Slot=Slot-1;
      if(Slot<=0){
      Slot=0;
      }
      myservo1.write(0);
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("Slot Left: ");
      lcd.print(Slot);
      delay (500);
      ln_1=1;
    }
  }
  //////////////////////////
  if(digitalRead (ir_4) == LOW && ln==2){
   
      myservo1.write(100);
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("Slot Left: ");
      lcd.print(Slot);
      delay (500);
    
  }
  if(digitalRead (ir_2) == LOW && ln==2){
      Slot=Slot+1;
      if(Slot>=6){
      Slot=6;
      }
      myservo1.write(0);
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("Slot Left: ");
      lcd.print(Slot);
      delay (500);
      ln_1=1;
  }
  Serial.println(ln);
  lcd.setCursor (0,0);
  lcd.print("    WELCOME!    ");
  lcd.setCursor (0,1);
  lcd.print("Slot Left: ");
  lcd.print(Slot);
  delay (500);
}
