#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);  

#define analogPin 0                 // Pin za merjenje kapacitivnosti
#define pin_za_polnjenje 13         // Pin za polnjenje (do 63.2%)
#define pin_za_praznjenje 8         // Pin za praznjenje
#define Upor 10000.0F               // Uporabimo 10k ohmski upor za praznjenje

unsigned long startTime;            // Kdaj se začne in konča polnjenje
unsigned long elapsedTime;
float mikroFaradi;                  // Določimo mikro in nano farade 
float nanoFaradi;

void setup(){
  pinMode(pin_za_polnjenje, OUTPUT);     
  digitalWrite(pin_za_polnjenje, LOW); 
  lcd.init();
  lcd.backlight();
}

void loop(){
  digitalWrite(pin_za_polnjenje, HIGH);  
  startTime = micros();
  while(analogRead(analogPin) < 648){            // 63.2% pri polnjenju kondenzatorja je 648 (arduino ima 10 biten ADC = 2^10 = 1024)   
  }

  elapsedTime= micros() - startTime;
  mikroFaradi = ((float)elapsedTime / Upor) ;    // kapacitivnost dobimo tako, da podelimo čas v katerem se konndenzator napolni do 63.2% z upornostjo 10kE

     
  
  if (mikroFaradi > 1){                          // Če imamo kondenzator z večjo kapacitivnostjo od 1 uF uporabimo ta del za LCD, za manjše pa spodaj

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LESTVICA: 10nF-500uF");
    lcd.setCursor(1,1);  
    lcd.print(mikroFaradi);
    lcd.setCursor(14,1);        
    lcd.print("uF");   
    delay(500);    
  }

  else{
    nanoFaradi = mikroFaradi * 1000.0; 
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("LESTVICA: 10nF-500uF");
    lcd.setCursor(0,1);       
    lcd.print(nanoFaradi-11.00);  
    lcd.setCursor(14,1);       
    lcd.print("nF");          
    delay(500); 
  }

  
  digitalWrite(pin_za_polnjenje, LOW);            
  pinMode(pin_za_praznjenje, OUTPUT);            
  digitalWrite(pin_za_praznjenje, LOW);     // Praznjenje kondenzatorja     
  while(analogRead(analogPin) > 0){         // Počaka dokler kondenzator ni izpraznjen
  }

  pinMode(pin_za_praznjenje, INPUT);        // To nastavi pin na veliko impedanco
  
  lcd.setCursor(0,0);
  lcd.print("PRAZNJENJE......... ");
  lcd.setCursor(0,1);  
}