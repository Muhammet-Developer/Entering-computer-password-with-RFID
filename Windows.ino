#include <SPI.h> 
#include <RFID.h> 
#include <LiquidCrystal_I2C.h> 
#include <Keyboard.h> 
RFID rfid(10,9); 
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
  SPI.begin();
  rfid.init();
  lcd.begin();
  Keyboard.begin();
}
byte myCard[5] = {0xB4,0x66,0xE8,0x1D,0xE27}; 
void loop() {
  boolean validCard = true; 
  int i;
  lcd.setCursor(3,0);
  lcd.print("Read Your");
  lcd.setCursor(3,1);
  lcd.print("Card");
  if(rfid.isCard())
  {
    if(rfid.readCardSerial())
    {
      Serial.print("Card ID: ");
      Serial.print(rfid.serNum[0],HEX);
      Serial.print(rfid.serNum[1],HEX);
      Serial.print(rfid.serNum[2],HEX);
      Serial.print(rfid.serNum[3],HEX);
      Serial.println(rfid.serNum[4],HEX);
    }
    for(i=0; i<5; i++)
    {
      if(rfid.serNum[i] != myCard[i]) 
      {
        validCard = false; 
      }
    }
    if(validCard==true)
    {
       for(int i=0; i<17; i++) 
         lcd.setCursor(i,0); 
         Keyboard.press(KEY_RETURN); 
         delay(50);
         Keyboard.releaseAll();
         Keyboard.print("Computer Password enter"); 
         Keyboard.press(KEY_RETURN); 
         delay(50);
         Keyboard.releaseAll();
         lcd.print("MUHAMMET CETINKAYA "); 
         delay(200);
         lcd.setCursor(i,0);
         lcd.print(" ");
         lcd.setCursor(i,1); 
         lcd.print("Welcome");
         delay(200);
         lcd.setCursor(i,1);
         lcd.print(" ");
      }
    }
    else 
    {
         for(int i=0; i<17; i++){
         lcd.setCursor(i,0); 
          delay(50);
          lcd.print("Card Not Found "); 
          delay(200);
          lcd.setCursor(i,0);
          lcd.print(" ");
          lcd.setCursor(i,1); 
          lcd.print("XXXXXXXX");
          delay(200);
          lcd.setCursor(i,1);
          lcd.print(" ");
         }} rfid.halt();
}}
