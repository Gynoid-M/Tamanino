
#include <LiquidCrystal.h>
LiquidCrystal lcd (8, 9, 4, 5, 6, 7);
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0 // 0
#define btnUP     1 //144
#define btnDOWN   2 //332
#define btnLEFT   3 // 505
#define btnSELECT 4 // 739
#define btnNONE   5 // 1023
int read_LCD_buttons();
void feed();
void mouthMovement();

void setup() {
  //Serial.begin(9600);
 // lcd.createChar(0,bird);
  lcd.begin(16, 2);              // Inicializar el LCD
  lcd.setCursor(0,0);
  lcd.print("Tamagotchi");
  lcd.setCursor(0,1);
  lcd.print("Select to start");
  
  
  // put your setup code here, to run once:

}

void loop() {
  
  
  int instruction = read_LCD_buttons();
  
  if(instruction == btnSELECT)
   {  lcd.clear();
      lcd.setCursor(6,0);
      lcd.print("ovo");
   }

   if(instruction == btnUP)
   {
      feed();
   }
 

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
      lcd.print("3");
      delay(1000);
      lcd.setCursor(i,0);
      lcd.print(" ");
      
      
   }
   mouthMovement();
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

