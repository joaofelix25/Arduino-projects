#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Definindo os pinos para a tela de LCD        
const int pinoSensor = 10; //PINO DIGITAL UTILIZADO PELO SENSOR
int buzzerPin = 9; // Definindo o pino digital para o buzzer
 
void setup(){
  lcd.begin(16, 2);
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  pinMode(buzzerPin, OUTPUT); // Definindo o pino do buzzer como saída
 
  Serial.begin(9600);
}
 
void loop(){

  if(digitalRead(pinoSensor) == LOW){ //SSem gás
      noTone(buzzerPin); //Buzzer desativado
      lcd.setCursor(1, 0); //Posiciona cursor
      lcd.print("SENSOR DE GAS");//Envia o texto entre aspas para o LCD
      lcd.setCursor(1, 1); //Posiciona cursor
      lcd.print("ZONA SEGURA");//Envia o texto entre aspas para o LCD
      Serial.println("sem alerta");//Escreve na serial
      lcd.clear();
  }else{ //com gás
    tone(buzzerPin,2000);
    lcd.setCursor(1, 0); //Posiciona cursor
    lcd.print("ALERTA");//Envia o texto entre aspas para o LCD
    lcd.setCursor(1, 1); //Posiciona cursor
    lcd.print("AR CONTAMINADO!");//Envia o texto entre aspas para o LCD
    Serial.println("ALERTA");
    delay(5000);
    lcd.clear();
  }
}
