#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <vector>
#include <string>

using namespace std;

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0); 

vector <string> alpha = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
vector <string> number = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

 void setup(void) {
   u8g2.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
   for(int i = 0; i < 26; i++)
   {
     u8g2.clearBuffer();          // clear the internal memory
     u8g2.setFont(u8g2_font_logisoso28_tr);  // choose a suitable font at https://github.com/olikraus/u8g2/wiki/fntlistall
     u8g2.drawStr(58,29, alpha[i].c_str());  // write something to the internal memory
     u8g2.sendBuffer();         // transfer internal memory to the display
     delay(3000);
   }
}
