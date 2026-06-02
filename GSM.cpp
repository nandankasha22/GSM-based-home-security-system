#include <LiquidCrystal.h>
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int pir=2;
int buzzer=A0;
int red=A1;
int green=A2;
String number="YOUR PHONE NUMBER";
void setup()
{
  Serial.begin(9600);
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);digitalWrite(buzzer,HIGH);
  pinMode(red,OUTPUT);pinMode(green,OUTPUT);
  digitalWrite(red,HIGH);digitalWrite(green,LOW);
  lcd.begin(16, 2);
  lcd.print("hello, world!");delay(1000);lcd.clear();Serial.begin(9600);delay(1000);
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print(number);Serial.print(":Registered successfully");delay(100);
Serial.write(0x1A);delay(10000); 
lcd.clear();lcd.print("sms sent.....");delay(1000);
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("Calling...");Serial.println("ATD /YOURPHONENUMBER/ ;");delay(10000);delay(10000);
Serial.println("ATH");delay(1000);
lcd.clear();lcd.print("READY TO USE.....");delay(1000);lcd.clear();

}

void loop()
{
int pirval=digitalRead(pir);delay(10);
if(pirval==HIGH)
{
 lcd.clear(); 
 lcd.setCursor(0,0);lcd.print("INTRUDER ALERT  ");delay(10);
 lcd.setCursor(0,1);lcd.print("                ");delay(100);
 digitalWrite(red,LOW);digitalWrite(green,HIGH);
 digitalWrite(buzzer,LOW);delay(500);digitalWrite(buzzer,HIGH);delay(100);
 digitalWrite(buzzer,LOW);delay(500);digitalWrite(buzzer,HIGH);delay(100);
 digitalWrite(buzzer,LOW);delay(500);digitalWrite(buzzer,HIGH);delay(100);
 lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("AT+CMGF=1");Serial.print("AT+CMGF=1\r\n");delay(1000);
lcd.clear();lcd.print("AT+CNMI=1,2,0,0");Serial.print("AT+CNMI=1,2,0,0\r\n");delay(1000);
lcd.clear();lcd.print(number);delay(100); 
lcd.setCursor(0,1);lcd.print("Sending sms...."); 
Serial.print("AT+CMGS=");
Serial.print('"');
Serial.print(number);
Serial.print('"');
Serial.print("\r\n");delay(1000);
Serial.print("INTRUDER ALERT");delay(100);
Serial.write(0x1A);delay(10000); 
lcd.clear();lcd.print("sms sent.....");delay(1000);
lcd.clear();lcd.print("AT");Serial.print("AT\r\n");delay(1000);
lcd.clear();lcd.print("ATE0");Serial.print("ATE0\r\n");delay(1000);
lcd.clear();lcd.print("Calling...");Serial.println("ATD /YOURPHONENUMBER/;");delay(10000);delay(10000);
Serial.println("ATH");delay(1000);
lcd.clear();lcd.print("READY TO USE.....");
 
}
 else
 {
  lcd.clear();
  lcd.setCursor(0,0);lcd.print("INTRUDER "); 
  lcd.setCursor(0,1);lcd.print("    NOT FOUND");delay(500);
  digitalWrite(red,HIGH);digitalWrite(green,LOW); 
 }
}
