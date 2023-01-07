#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ldr = A0; //Set A0(Analog Input) for LDR.
int value = 0; 
const int buzzer = 9; //buzzer to arduino pin 9
int ledpin = 6; //LED to pin 6

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT); // Set LED - pin 6 as an output
  lcd.begin(16, 2);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
}

void loop() {
  value = analogRead(ldr); //Reads the Value of LDR(light).
  //Serial.println("LDR value is :");//Prints the value of LDR to Serial Monitor.
  //Serial.println(value);
  if (value < 300)
  {
    digitalWrite(6, LOW);
    lcd.clear();
    noTone(buzzer);
  }
  else
  {
    digitalWrite(6, HIGH);
    tone(buzzer, 500);
    lcd.setCursor(0, 0);
    lcd.print("Caught You ! ");
    lcd.setCursor(0, 1);
    lcd.print("Run Fast -");
    //lcd.print(millis() / 1000);
    delay(100);
    noTone(buzzer);
    delay(100);
  }
}
