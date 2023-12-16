// подключаем библиотеку для работы с экраном
#include <LiquidCrystal.h>

// объявляем объект, для управления дисплеем указываем пины
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() {
   lcd.begin(16, 2);      // указываем количество строк и столбцов

   lcd.setCursor(1, 0);     // ставим курсор на 1 символ первой строки
   lcd.print("I LOVE");     // печатаем сообщение на первой строке
  
   lcd.setCursor(8, 1);        // ставим курсор на 1 символ второй строки
   lcd.print("ARDUINO");  // печатаем сообщение на второй строке
}
 
void loop() {
  lcd.clear(); 
  lcd.setCursor(0,0);// set the cursor on the first row and column 
  lcd.print("Humidity="); 
  lcd.print("25");//print the humidity 
  lcd.print("%"); 
  lcd.setCursor(0,1);//set the cursor on the second row and first column 
  lcd.print("Temp="); 
  lcd.print("26");//print the temperature 
  lcd.print("Celsius"); 
  delay(2000); 
  lcd.clear();

}
