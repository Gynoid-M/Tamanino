
#include <LiquidCrystal.h>
LiquidCrystal lcd (8, 9, 4, 5, 6, 7);
int lcd_key     = 0;
int adc_key_in  = 0;
int Totlife = 5;
unsigned long previousMillis = 0;
unsigned long timeToAction = 3000;
#define btnRIGHT  0 // 0
#define btnUP     1 //144
#define btnDOWN   2 //332
#define btnLEFT   3 // 505
#define btnSELECT 4 // 739
#define btnNONE   5 // 1023
int read_LCD_buttons();
void feed();
void mouthMovement();
void sick();
void hungry();
void life();
void passofTime();
void game();
void healthy();
void setup() {
  
  lcd.begin(16, 2);             
  lcd.setCursor(0,0);
  lcd.print("Tamagotchi");
  lcd.setCursor(0,1);
  lcd.print("Select to start");
  
}

void loop() {
  
  int instruction = read_LCD_buttons();
  if(instruction == btnSELECT)
    game();
 
}

int read_LCD_buttons()
{
  int key = analogRead(0);
  switch(key){
    case 0:
      return btnRIGHT;
    case 144:
      return btnUP;
    case 332:
      return btnDOWN;
    case 505:
      return btnLEFT;
    case 739:
      return btnSELECT;
    case 1023:
      return btnNONE;
  }


}

void feed () 
{
   for(int i = 0; i<6; i++)
   {
      
      lcd.setCursor(i,0);
      lcd.print("*");
      delay(1000);
      lcd.setCursor(i,0);
      lcd.print(" ");
      
      
   }
   Totlife = 5;
   mouthMovement();
   healthy();
   life();
   
}

void mouthMovement()
{
      lcd.setCursor(5,0);
      lcd.print(" ");
      lcd.setCursor(6,0);
      lcd.print("oAo");
      delay(1000);
      lcd.setCursor(6,0);
      lcd.print("ovo");
      delay(1000);
      lcd.setCursor(6,0);
      lcd.print("oAo");
      delay(1000);
      lcd.setCursor(6,0);
      lcd.print("ovo");
  
}

void sick()
{
  lcd.setCursor(6,0);
  lcd.print("=v=");
  lcd.setCursor(4,1);
  lcd.print("I'm sick");
}

void hungry()
{
  lcd.setCursor(6,0);
  lcd.print("TvT");
  lcd.setCursor(4,1);
  lcd.print("I'm hungry");
}

void life()
{
  lcd.setCursor(11,0);
  if(Totlife >= 0)
  {
    lcd.print(Totlife);
    lcd.print("H");
  }
  else
  {
    lcd.print(0);
    lcd.print("H");
    hungry();
  }
  
}

void passofTime() {
   unsigned long currentMillis = millis();
   if(currentMillis - previousMillis >= timeToAction)
   {
     Totlife --;
     previousMillis = currentMillis;
     life();
   }

  
}
void healthy(){
   lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("ovo");
    life();
}

void game(){

 //aux loop, for the main game. 
  healthy();
  while(true)
  {
    int instruction = read_LCD_buttons();
  
    passofTime();
    
   
   if(instruction == btnUP)
   {
      feed();
   }
  }
  
}




