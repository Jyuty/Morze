#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <vector>
#include <string>

using namespace std;

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

vector <string> symb = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
vector <string> Morze = {"01", "1000", "1010", "100", "0", "0010", "110", "0000", "00", "0111", "101", "0100", "11", "10", "111", "0110", "1101", "010", "000", "1", "001", "0001", "011", "1001", "1011", "1100",
"01111", "00111", "00011", "00001", "00000", "10000", "11000", "11100", "11110", "11111"};
vector <string> output;

int i = 0;
int x0 = 774; //зависит от начального значения джойстика(надо проверить)
int x;

#define PIN_VRX A0 //пин для джойстика(только одну ось)
#define PIN_BUTTON_J 3 //n-ный пин для кнопки джойстика

#define PIN_BUTTON  4 //пин для кнопки отправки

 void setup(void) {
   u8g2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
   /*u8g2.clearBuffer();          // clear the internal memory
     u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
     u8g2.drawStr(58,29, alpha[i].c_str());  // write something to the internal memory
     u8g2.sendBuffer();         // transfer internal memory to the display
     delay(3000);*/
     x = analogRead(PIN_VRX);
     if(abs(x-x0) > 100)
     {
        i = (i+1) % 36;
     }
     u8g2.clearBuffer();          // clear the internal memory
     u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
     u8g2.drawStr(58,29, alpha[i].c_str());  // write something to the internal memory
     u8g2.sendBuffer();
     if(digitalRead(PIN_BUTTON_J) == LOW)
     {
        output.push_back(Morze[i]);
     }
     if(digitalRead(PIN_BUTTON) == LOW)
     {
        
     }
}
