#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

const int address = 0x38;
int sensorVal=0;
int res=0;
int time_is_finish=0;
int start=0;
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.setCursor(8, 1);
  lcd.print("Radmir");
pinMode(0, INPUT_PULLUP);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);

pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(A3,OUTPUT);
pinMode(A2,OUTPUT);
pinMode(A1,OUTPUT);
pinMode(A0,OUTPUT);
 
}
  
void loop()
{
      int tmp=!digitalRead(0);
      if (sensorVal!=tmp && tmp==1) {
        res+=1;
        res%=140;
        time_is_finish=0;
      }
      time_is_finish++;
      int sensorVal = !digitalRead(0);
      lcd.setCursor(8, 1);
      lcd.print("Radmir");      
      lcd.setCursor(0, 1); 
      lcd.print("Type");       
      lcd.print(res/35+1);  

      if (time_is_finish>600) {
        start=1;
      } 
     

      if   (start==1)
      {
         lcd.clear(); 
         lcd.print("start");          
         res=res/35+1;
         if (res==1)fifth();
         else if( res==2)second(); 
         else if( res==3)third();
         else if( res==4)fourth();
         delay(100); 
         start=0;
         time_is_finish=0;    
          lcd.setCursor(0, 1);   
          lcd.print("stop");
          first();
          delay(100);
          lcd.clear()    ;        
 
      }

         
} 
void first()
{
      int column [16]={13,12,11,10,9,8,7,6,5,4,3,2,A0,A1,A2,A3};
      Wire.beginTransmission(address);
      for (int i=0; i<4;i++)     Wire.write(~(0 << i));
      Wire.endTransmission();
    for (int i=0;i<16;i++) digitalWrite(column[i],0); 
    
     }

void second(){
    for (int i=0; i<4;i++){
      Wire.beginTransmission(address);
      Wire.write(~(1 << i));
      Wire.endTransmission();
      int column [16]={13,12,11,10,9,8,7,6,5,4,3,2,A0,A1,A2,A3};
      for (int i=0;i<16;i++) {
        digitalWrite(column[i],1);
        delay(200);
        digitalWrite(column[i],0);  
      delay(200);
          
      }
    }
    
    }

void third(){
    int column [16]={13,12,11,10,9,8,7,6,5,4,3,2,A0,A1,A2,A3};
    for (int i=0;i<16;i++) digitalWrite(column[i],1);
     for (int i=0; i<4;i++){
      Wire.beginTransmission(address);
      Wire.write(~(1 << i));
           
      Wire.endTransmission();
      delay(500);
    
    
}}

void  fourth(){
      
    int column [16]={13,12,11,10,9,8,7,6,5,4,3,2,A0,A1,A2,A3};
    Wire.beginTransmission(address);
    for (int i=0; i<4;i++)     Wire.write(~(1 << i));
    Wire.endTransmission();
for(int i=0;i<16;i+=4){
digitalWrite(column[i],1);
digitalWrite(column[i+1],1);
digitalWrite(column[i+2],1);
digitalWrite(column[i+3],1);
delay(1000); 
digitalWrite(column[i],0);
digitalWrite(column[i+1],0);
digitalWrite(column[i+2],0);
digitalWrite(column[i+3],0);

 }}

void fifth() {
  
  
    Wire.beginTransmission(address);
    Wire.write(~(1 << 2));
    Wire.endTransmission();
    
      digitalWrite(13,1); 
      delay(200);                    
      digitalWrite(13,0);

digitalWrite(12,1); 
      delay(200);                    
      digitalWrite(12,0); 

      digitalWrite(11,1); 
      delay(200);                    
      digitalWrite(11,0); 

      digitalWrite(10,1); 
      delay(200);                    
      digitalWrite(10,0);   
digitalWrite(11,1); 
      delay(200);                    
      digitalWrite(11,0);              
         digitalWrite(12,1); 
      delay(200);                    
      digitalWrite(12,0); 
digitalWrite(13,1); 
      delay(200);                    
      digitalWrite(13,0);


 }
